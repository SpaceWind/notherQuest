#include "fightmanager.h"
#include "utils.h"

FightManager::FightManager(SpellFactory *sf, QObject *o)
    : QObject(o)
{
    this->sf = sf;
}

void FightManager::startFight()
{
    for (int i = 0; i < playerTeam.count(); i++)
        applyFightStart(playerTeam[i]);
    for (int i = 0; i < enemyTeam.count(); i++)
        applyFightStart(enemyTeam[i]);
    emit message("БИТВА НАЧАЛАСЬ");
}

void FightManager::startTurn()
{
    updateInit();
    for (int i = 0; i < playerTeam.count(); i++)
        applyTurn(playerTeam[i]);
    for (int i = 0; i < enemyTeam.count(); i++)
        applyTurn(enemyTeam[i]);

    Character *c = pickNext();
    if (c == 0)
    {
        emit message("Ход закончен");
        return;
    }

    bool isPlayerTurn = playerTeam.contains(c);

    Character *e = findEnemy(OFFENSIVE, !isPlayerTurn);
    if (e == 0)
    {
        emit message("Бой закончился. Победил " + c->name);
        return;
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
                        emit message(c->name + " кастует " + s->name);
                        c->currentMana-= s->manacost;
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
                        emit message(c->name + " кастует " + s->name);
                        c->currentMana-= s->manacost;
                        c->passives.buffs.append(s->id);
                    }
                }
            }
    }
    if (!wasCasted)
    {
        AutoAttack aa = AutoAttack::makeAutoAttack(*c, *e);
        foreach (const int &id, c->passives.launchers)
            applyLauncher(sf->getLauncher(id)->beforeAttack(aa, e));
        foreach (const int &id, e->passives.launchers)
            applyLauncher(sf->getLauncher(id)->beforeAttack(aa, e));

        if (!aa.missed)
        {
            e->currentHP -= aa.damage;
            if (e->currentHP < 0)
                e->currentHP = 0;
        }
        else
        {
            emit message(c->name + " промахнулся");
        }
    }

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
            if ((c != 0 && c->info.init < r->info.init) || c == 0)
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
            if ((c != 0 && c->info.init < r->info.init) || c == 0)
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
        playerTeam[i]->currentInit += playerTeam[i]->info.init;
    for (int i = 0; i < enemyTeam.count(); i++)
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

void FightManager::applyFightStart(Character *c)
{
    c->resetPrepared();

    foreach (const int passiveId, c->actives.passives)
    {
        QString type = sf->getTypeById(passiveId);
        if (type == SPELL_TYPE_BUFF)
            c->passives.buffs.append(passiveId);
        else if (type == SPELL_TYPE_LAUNCHER)
            c->passives.launchers.append(passiveId);
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
            //sf->removeSpell(buffId);
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
            //sf->removeSpell(l->id);
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

        c->currentMana -= r.manaDamage;
        c->currentHP-= r.physDamage*armor + r.magicDamage*mres + r.trueDamage;

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
            findById(r.receiverID)->passives.buffs.append(sId);
        else if (type == SPELL_TYPE_NUKE)
        {
            Nuke *n = sf->getNuke(sId);
            applyNuke(findById(r.ownerID), n->id, n->launch(findById(r.receiverID)), findById(r.receiverID));
        }
        else if (type == SPELL_TYPE_LAUNCHER)
            findById(r.receiverID)->passives.launchers.append(sId);
    }
}




























