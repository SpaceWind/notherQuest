#ifndef NUKES_H
#define NUKES_H
#include "magic.h"

using namespace Magic;

class Atomization : public Nuke
{
public:
    Atomization() : Nuke() { }
    Atomization(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);
    virtual void updateLvl(int lvl);
protected:
    double damage;
};

struct CutStrike : public Nuke
{
    CutStrike () : Nuke() { }
    CutStrike(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);
    virtual void updateLvl(int lvl);
protected:
    double damage;
};

class HybridStrike : public Nuke
{
public:
    HybridStrike() : Nuke() { }
    HybridStrike(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);
    virtual void updateLvl(int lvl);
protected:
    double damage;
};

class WitsEndNuke : public Nuke
{
public:
    WitsEndNuke() : Nuke() { }
    WitsEndNuke(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);
    virtual void updateLvl(int lvl);
protected:
    double damage;
};

class WitsEndDebuff : public Buff
{
public:
    WitsEndDebuff() : Buff() {}
    WitsEndDebuff(Character *owner, int lvl);

    virtual void apply(Character *receiver);
    virtual void updateLvl(int lvl);
protected:
    double value;
};

class WitsEnd : public Complex
{
public:
    WitsEnd() : Complex() {}
    WitsEnd(Character *owner, int lvl);

    virtual QList<QString> prepare();
};

class Desintegration : public Nuke
{
public:
    Desintegration() : Nuke() { }
    Desintegration(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);
    virtual void updateLvl(int lvl);
protected:
    double damage;
};

#endif // NUKES_H
