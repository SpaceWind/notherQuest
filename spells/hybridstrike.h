#ifndef HYBRIDSTRIKE_H
#define HYBRIDSTRIKE_H

#include <magic.h>
using namespace Magic;

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

#endif // HYBRIDSTRIKE_H
