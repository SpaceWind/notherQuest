#ifndef WITSEND_H
#define WITSEND_H

#include <magic.h>

using namespace Magic;

class WitsEndNuke : public Nuke
{
public:
    WitsEndNuke() : Nuke() { }
    WitsEndNuke(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);
protected:
    double damage;
};

class WitsEndDebuff : public Buff
{
public:
    WitsEndDebuff() : Buff() {}
    WitsEndDebuff(Character *owner, int lvl);

    virtual void apply(Character *receiver);
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

#endif // WITSEND_H
