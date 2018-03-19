#ifndef BADSTICK_H
#define BADSTICK_H

#include <QObject>
#include <artifact.h>

class BadStick : public Artifact
{
public:
    BadStick();
    BadStick(SpellFactory *sf, Character *c, int lvl, int id);
    ~BadStick() { }

    virtual void init();
    virtual void apply();
};

#endif // BADSTICK_H
