#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>
#include "stats.h"
#include "spells/spellfactory.h"


class Monster
{
public:

    enum Mod{SMALL, NORMAL, BIG, EPIC};

    Monster();
    Monster(Monster::Mod mod, int lvl, QString name, QString title, SpellFactory *sf, int id);
    virtual ~Monster() {if (c) delete c;}
    virtual Character * getChar() {return c;}

    QString name, title;
protected:
    virtual void initChar(const QVector<double> &stats, const QVector<QString> &prefixes, QString title, bool isMagicAA);

    Character *c;
    SpellFactory *sf;
    Mod mod;
    int lvl;
    int id;
};

class MonsterWolf : public Monster
{
public:
    MonsterWolf();
    MonsterWolf(Monster::Mod mod, int lvl, SpellFactory *sf, int id);
    virtual ~MonsterWolf() { }
};

#endif // MONSTER_H
