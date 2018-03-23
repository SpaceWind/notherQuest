#ifndef BADSTICK_H
#define BADSTICK_H

#include <QObject>
#include "artefact.h"

class BadStick : public Artefact
{
public:
    BadStick();
    BadStick(SpellFactory *sf, Character *c, int lvl, int id);
    ~BadStick() { }

    virtual void apply();
};

#endif // BADSTICK_H
