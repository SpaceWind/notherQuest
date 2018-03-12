#ifndef ATOMIZATION_H
#define ATOMIZATION_H
#include <magic.h>

using namespace Magic;

class Atomization : public Nuke
{
public:
    Atomization() : Nuke() { }
    Atomization(Character *owner, int lvl);

    virtual Nuke::Result launch(const Character *receiver);

protected:
    double damage;
};

#endif // ATOMIZATION_H
