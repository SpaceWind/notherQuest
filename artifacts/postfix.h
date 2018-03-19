#ifndef WEAPONPOSTFIXDEATH_H
#define WEAPONPOSTFIXDEATH_H
#include <artifact.h>

class WeaponPostfixDeath :public Artefact
{
public:
    WeaponPostfixDeath();
    WeaponPostfixDeath(SpellFactory *sf, Character *c, int lvl, int id);
    ~WeaponPostfixDeath() { }

    virtual void init();
    virtual void apply();
};

#endif // WEAPONPOSTFIXDEATH_H
