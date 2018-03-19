#ifndef CUTSTRIKE_H
#define CUTSTRIKE_H

#include <magic.h>

using namespace Magic;

struct CutStrike : public Nuke
{
    CutStrike () : Nuke() { }
    CutStrike(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);
    virtual void updateLvl(int lvl);
protected:
    double damage;
};
#endif // CUTSTRIKE_H
