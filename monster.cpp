#include "monster.h"
#include "utils.h"

#define QVD QVector<double>()

Monster::Monster()
{
    c = 0;
    sf = 0;
    id = 0;
}

Monster::Monster(Monster::Mod mod, int lvl, QString name, QString title, SpellFactory *sf, int id) :
    Monster()
{
    this->mod = mod;
    this->lvl = lvl;
    this->name = name;
    this->title = title;
    this->sf = sf;
    this->id = id;
}

void Monster::initChar(const QVector<double> &stats, const QVector<QString> &prefixes, QString title, bool isMagicAA)
{
    QVector<int> types = QVector<int>() << SMALL << NORMAL << BIG << EPIC;
    Stats a;
    a.strength = SM::pickItem(types,    QVD << stats[0] << stats[1] << stats[2] << stats[3], mod);
    a.strPerLevel = SM::pickItem(types, QVD << stats[4] << stats[5] << stats[6] << stats[7], mod);
    a.agility = SM::pickItem(types,     QVD << stats[8] << stats[9] << stats[10] << stats[11], mod );
    a.agiPerLevel = SM::pickItem(types, QVD << stats[12] << stats[13] << stats[14] << stats[15], mod);
    a.intellect = SM::pickItem(types,   QVD << stats[16] << stats[17] << stats[18] << stats[19], mod);
    a.intPerLevel = SM::pickItem(types, QVD << stats[20] << stats[21] << stats[22] << stats[23], mod);
    a.speed = SM::pickItem(types,       QVD << stats[24] << stats[25] << stats[26] << stats[27], mod);
    a.spdPerLevel = SM::pickItem(types, QVD << stats[28] << stats[29] << stats[30] << stats[31], mod);
    a.endurance = SM::pickItem(types,   QVD << stats[32] << stats[33] << stats[34] << stats[35], mod);
    a.endPerLevel = SM::pickItem(types, QVD << stats[36] << stats[37] << stats[38] << stats[39], mod);
    a.charisma = SM::pickItem(types,    QVD << stats[40] << stats[41] << stats[42] << stats[43], mod);
    a.chaPerLevel = SM::pickItem(types, QVD << stats[44] << stats[45] << stats[46] << stats[47], mod);
    a.level = lvl;
    a.isBuilt = false;

    c = new Character();
    c->stats = a;
    c->info = StatsInfo::buildInfo(c->stats.build());
    c->id = id;

    this->title = SM::pickItem(types, prefixes, mod) + title;
    c->name = this->title;
    c->isMagicAutoAttack = isMagicAA;
    c->reset();
    c->resetPrepared();
}

MonsterWolf::MonsterWolf() :
    Monster()
{

}

MonsterWolf::MonsterWolf(Monster::Mod mod, int lvl, SpellFactory *sf, int id)
    : Monster(mod, lvl, "MonsterWolf", "",  sf, id)
{

    auto stats = QVD << 1.2 << 1.8 << 2.6 << 4.0 <<
                        0.1 << 0.12 <<0.14<< 0.15 <<
                        2.0 << 3.0 << 4.0 << 5.0 <<
                        0.2 << 0.25 << 0.3 << 0.4 <<
                        1.0 << 1.5 << 1.75 << 2.0 <<
                        0.1 << 0.12 << 0.14 << 0.15 <<
                        3.0 << 4.5 << 6.0 << 8.0 <<
                        0.3 << 0.4 << 0.6 << 0.8 <<
                        2.0 << 3.0 << 4.0 << 6.0 <<
                        0.3 << 0.4 << 0.5 << 0.6 <<
                        1.0 << 1.5 << 2.0 << 2.5 <<
                        0.1 << 0.1 << 0.2 << 0.2;
    initChar(stats, QVector<QString>() << "Молодой " << "" << "Большой " << "Альфа ", "Волк", false);
}
