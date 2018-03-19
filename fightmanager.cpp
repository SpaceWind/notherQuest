#include "fightmanager.h"
#include "utils.h"
#include <QThread>
#include <QDebug>
#include <QApplication>

FightManager::FightManager(SpellFactory *sf, QuestTimer *q, QObject *o)
    : QObject(o)
{
    this->sf = sf;
    this->qt = q;
    connect(this, SIGNAL(invokeStartQt(double,bool)), qt, SLOT(start(double,bool)));
}

void FightManager::startFight()
{
    for (int i = 0; i < playerTeam.count(); i++)
        applyFightStart(playerTeam[i]);
    for (int i = 0; i < enemyTeam.count(); i++)
        applyFightStart(enemyTeam[i]);
    runMessage("БИТВА НАЧАЛАСЬ", 3.0, false);
    turnNumber = 1;
}

void FightManager::startTurn()
{
    runMessage("Ход " + QString::number(turnNumber++), 2.0, false);
    updateInit();
    for (int i = 0; i < playerTeam.count(); i++)
        applyTurn(playerTeam[i]);
    for (int i = 0; i < enemyTeam.count(); i++)
        applyTurn(enemyTeam[i]);

    FightCycleResult result;
    while (!result.done())
        result = runFightCycle();

    if (result.ended())
        emit fightEnded(result.playerWon);
    else
        emit nextTurn();
}

FightManager::FightCycleResult FightManager::runFightCycle()
{
    FightCycleResult result;
    Character *c = pickNext();
    if (c == 0)
    {
        result.turnEnded = true;
        return result;
    }

    bool isPlayerTurn = playerTeam.contains(c);

    Character *e = findEnemy(OFFENSIVE, isPlayerTurn);
    if (e == 0)
    {
        runMessage("Бой закончился. Победил " + c->name, false);
        result.playerWon = isPlayerTurn;
        result.enemyWon = !isPlayerTurn;
        return result;
    }

    bool wantsToCastSpell = StaticMethods::procChance(1.0 - c->preparedInfo.speciality());
    bool wasCasted = false;
    if (wantsToCastSpell)
    {
        foreach (const int &sId, c->actives.activeSpells)
            if (sf->isReady(sId))
            {
                QString type = sf->getTypeById(sId);
                if (type == SPELL_TYPE_NUKE)
                {
                    Nuke *s = sf->getNuke(sId);
                    if (s->manacost <= c->currentMana)
                    {
                        runMessage(c->name + " кастует " + s->title, 10.0 * c->preparedInfo.castSpeed());
                        c->currentMana-= s->manacost;
                        if (s->selfCast)
                            applyNuke(c, s->id, s->launch(c), c);
                        else
                            applyNuke(c, s->id, s->launch(e), e);
                        wasCasted = true;
                        break;
                    }
                }
                else if (type == SPELL_TYPE_BUFF)
                {
                    Buff *s = sf->getBuff(sId);
                    if (s->manacost <= c->currentMana)
                    {
                        runMessage(c->name + " кастует " + s->name, 10.0 * c->preparedInfo.castSpeed());
                        c->currentMana-= s->manacost;
                        if (s->selfCast)
                            c->passives.buffs.append(sf->generic(sId));
                        else
                            e->passives.buffs.append(sf->generic(sId));
                        wasCasted = true;
                        break;
                    }
                }
                else if (type == SPELL_TYPE_LAUNCHER)
                {
                    Launcher *s = sf->getLauncher(sId);
                    if (s->manacost <= c->currentMana)
                    {
                        runMessage (c->name + " кастует" + s->name, 10.0 * c->preparedInfo.castSpeed());
                        c->currentMana -= s->manacost;
                        if (s->selfCast)
                            c->passives.launchers.append(sf->generic(sId));
                        else
                            e->passives.launchers.append(sf->generic(sId));
                        wasCasted = true;
                        break;
                    }
                }
            }
    }
    if (!wasCasted)
    {
        AutoAttack aa = AutoAttack::makeAutoAttack(*c, *e);

        QString msg;
        if (!aa.missed)
        {
            if (!aa.isCrit)
                msg = c->name + " наносит " + QString::number(aa.damage, 'f', 3) + " урона  по " + e->name + "!\n";
            else
                msg = c->name + " УЕБАЛ " + QString::number(aa.damage, 'f', 3) + " урона  по " + e->name + "!\n";

            if (aa.isDefenderDead)
                msg += e->name + "умирает. " + c->name + " победил";
        }
        else
            msg = c->name + " промахнулся!";
        runMessage(msg, StaticMethods::minmax(10.0 * c->preparedInfo.attackSpeed(),1.0, aa.missed ? 2.0 : 10.0));


        foreach (const int &id, c->passives.launchers)
            applyLauncher(sf->getLauncher(id)->beforeAttack(aa, e));
        foreach (const int &id, e->passives.launchers)
            applyLauncher(sf->getLauncher(id)->beforeReceiveAutoAttack(aa, c));

        if (!aa.missed)
        {
            e->currentHP -= aa.damage;
            if (e->currentHP < 0)
                e->currentHP = 0;
        }
        foreach (const int &id, c->passives.launchers)
            applyLauncher(sf->getLauncher(id)->afterAttack(aa, e));
        foreach (const int &id, e->passives.launchers)
            applyLauncher(sf->getLauncher(id)->afterReceiveAutoAttack(aa, c));
    }
    return result;
}

Character *FightManager::pickNext()
{
    double maxInit = 10.0;
    Character * r = 0;

    for (int i = 0; i < playerTeam.count(); i++)
    {
        auto c = playerTeam[i];
        if (c->currentInit >= maxInit && c->alive())
        {
            if ((r != 0 && c->currentInit == r->currentInit && c->info.init < r->info.init) ||
                 c->currentInit > maxInit)
            {
                maxInit = c->currentInit;
                r = c;
            }
        }
    }
    for (int i = 0; i < enemyTeam.count(); i++)
    {
        auto c = enemyTeam[i];
        if (c->currentInit >= maxInit && c->alive())
        {
            if ((r != 0 && c->currentInit == r->currentInit && c->info.init < r->info.init) ||
                 c->currentInit > maxInit)
            {
                maxInit = c->currentInit;
                r = c;
            }
        }
    }

    if (r != 0)
        r->currentInit-= 10.;
    return r;
}

void FightManager::updateInit()
{
    for (int i = 0; i < playerTeam.count(); i++)
        if (playerTeam[i]->currentInit < 10.0)
            playerTeam[i]->currentInit += playerTeam[i]->info.init;
    for (int i = 0; i < enemyTeam.count(); i++)
        if (enemyTeam[i]->currentInit < 10.0)
            enemyTeam[i]->currentInit += enemyTeam[i]->info.init;

}

Character *FightManager::findEnemy(FightManager::CharSearchRule rule, bool isFindEnemy)
{
    QList<Character*> list = isFindEnemy ? enemyTeam : playerTeam;

    if (rule == FIRST)
    {
        for (int i = 0; i < list.count(); i++)
            if (list[i]->alive())
                return list[i];
    }
    if (rule == LAST)
    {
        for (int i = list.count()-1; i >= 0; i--)
            if (list[i]->alive())
                return list[i];
    }
    if (rule == RANDOM)
    {
        for (int i = 0; i < list.count()*2; i++)
        {
            int index  = qrand()%list.count();
            if (list[index]->alive())
                return list[index];
        }
        return findEnemy(FIRST, isFindEnemy);
    }
    if (rule == OFFENSIVE)
    {
        QVector<double> weights;
        for (int i = 0; i < list.count(); i++)
            weights.append(list[i]->info.offensiveness());
        auto c = list[StaticMethods::procItem(weights)];
        if (!c->alive())
            return findEnemy(RANDOM, isFindEnemy);
        return c;
    }
    if (rule == WEAK)
    {
        double hp = 999999999;
        int index = -1;

        for (int i = 0; i < list.count(); i++)
        {
            if (list[i]->currentHP < hp)
            {
                hp = list[i]->currentHP;
                index  = i;
            }
        }
        if (index != -1 && list[index]->alive())
            return list[index];
        else
            return findEnemy(FIRST, isFindEnemy);
    }
    else
        return 0;
}

Character *FightManager::findById(int id)
{
    for (int i = 0; i < playerTeam.count(); i++)
        if (playerTeam[i]->id == id)
            return playerTeam[i];
    for (int i = 0; i < enemyTeam.count(); i++)
        if (enemyTeam[i]->id == id)
            return enemyTeam[i];
    return 0;
}

void FightManager::awaitTimer()
{
    while (!qt->isReady())
    {
        this->thread()->msleep(250);
    }
}

void FightManager::runMessage(QString s, double time, bool animation)
{
    message(s);
    invokeStartQt(time, animation);
    this->thread()->sleep(1);
    awaitTimer();
}

void FightManager::applyFightStart(Character *c)
{
    c->resetPrepared();

    foreach (const int passiveId, c->actives.passives)
    {
        QString type = sf->getTypeById(passiveId);
        if (type == SPELL_TYPE_BUFF)
            c->passives.buffs.append(sf->generic(passiveId));
        else if (type == SPELL_TYPE_LAUNCHER)
            c->passives.launchers.append(sf->generic(passiveId));
    }
    foreach (const int buffId, c->passives.buffs)
    {
        Buff *b = sf->getBuff(buffId);
        b->apply(c);
    }
    foreach (const int launcherId, c->passives.launchers)
    {
        Launcher *l = sf->getLauncher(launcherId);
        Launcher::Result r = l->onFightStart();
        applyLauncher(r);
    }
}

void FightManager::applyTurn(Character *c)
{
    c->resetPrepared();
    QList<int> bRemoveList;
    foreach (const int buffId, c->passives.buffs)
    {
        Buff *b = sf->getBuff(buffId);
        if (!b->isActive())
        {
            sf->removeSpell(buffId);
            bRemoveList.append(buffId);
            continue;
        }
        b->apply(c);
    }

    QList<int> lremoveIds;
    foreach (const int launcherId, c->passives.launchers)
    {
        Launcher *l = sf->getLauncher(launcherId);
        if (!l->isActive())
        {
            sf->removeSpell(l->id);
            lremoveIds.append(launcherId);
            continue;
        }
        Launcher::Result r = l->onTurn();
        applyLauncher(r);
    }
    foreach (const int &i, lremoveIds)
        c->passives.launchers.removeOne(i);
    foreach (const int &i, bRemoveList)
        c->passives.buffs.removeOne(i);

    foreach (const int buffId, c->passives.buffs)
        sf->update(buffId, 5.0);
    foreach (const int launcherId, c->passives.launchers)
        sf->update(launcherId, 5.0);
    foreach (const int spId, c->actives.activeSpells)
        sf->update(spId, 5.0);
    if (c->currentHP > 0.0)
        c->currentHP = StaticMethods::minmax(c->currentHP + c->preparedInfo.hpr * 5.0, 0.0, c->preparedInfo.hp);
    c->currentMana = StaticMethods::minmax(c->currentMana + c->preparedInfo.mpr * 5.0, 0.0, c->preparedInfo.mana);
}

void FightManager::applyNuke(Character *sender, int spellId, Nuke::Result r, Character *c)
{
    foreach (const int &sid, c->passives.launchers)
    {
        Launcher *l = sf->getLauncher(sid);
        Launcher::Result r = l->beforeSpell(sender, spellId);
        applyLauncher(r);
    }

    if (r.isActive)
    {
        double mres = 1.0 - c->preparedInfo.mres(),
               armor= 1.0 - c->preparedInfo.armor();

        double value =  r.physDamage*armor + r.magicDamage*mres + r.trueDamage;

        c->currentMana -= r.manaDamage;
        c->currentHP-= value;
        if (r.manaDamage > 0)
            runMessage("сжигает " + QString::number(r.manaDamage, 'f',2) + " маны", 3.0, false);

        runMessage("наносит " + QString::number(value, 'f', 2) + " урона", 3.0, false);

        if (c->currentMana < 0.) c->currentMana = 0.;
        if (c->currentHP < 0.) c->currentHP = 0.;
    }
    sf->resetCD(spellId);

    foreach (const int &sid, c->passives.launchers)
    {
        Launcher *l = sf->getLauncher(sid);
        Launcher::Result r = l->afterSpell(sender, spellId);
        applyLauncher(r);
    }
}

void FightManager::applyLauncher(Launcher::Result r)
{
    if (r.isActive)
    {
        int sId = sf->createSpell(r.spellName,findById(r.ownerID), r.lvl);
        QString type = sf->getTypeById(sId);
        if (type == SPELL_TYPE_BUFF)
            findById(r.receiverID)->passives.buffs.append(sf->generic(sId));
        else if (type == SPELL_TYPE_NUKE)
        {
            Nuke *n = sf->getNuke(sId);
            applyNuke(findById(r.ownerID), n->id, n->launch(findById(r.receiverID)), findById(r.receiverID));
        }
        else if (type == SPELL_TYPE_LAUNCHER)
            findById(r.receiverID)->passives.launchers.append(sf->generic(sId));
    }
}




























