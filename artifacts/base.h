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

class Stick : public Artefact
{
public:
    Stick();
    Stick(SpellFactory *sf, Character *c, int lvl, int id);
    ~Stick() { }

    virtual void apply();
};

class WoodenRog : public Artefact
{
public:
    WoodenRog();
    WoodenRog(SpellFactory *sf, Character *c, int lvl, int id);
    ~WoodenRog() { }

    virtual void apply();
};

class Bow : public Artefact
{
public:
    Bow();
    Bow(SpellFactory *sf, Character *c, int lvl, int id);
    ~Bow() { }

    virtual void apply();
};


class Baton : public Artefact
{
public:
    Baton();
    Baton(SpellFactory *sf, Character *c, int lvl, int id);
    ~Baton() { }

    virtual void apply();
};

class Dagger : public Artefact
{
public:
    Dagger();
    Dagger(SpellFactory *sf, Character *c, int lvl, int id);
    ~Dagger() { }

    virtual void apply();
};

class HuntersBow : public Artefact
{
public:
    HuntersBow();
    HuntersBow(SpellFactory *sf, Character *c, int lvl, int id);
    ~HuntersBow() { }

    virtual void apply();
};

class StoneSword : public Artefact
{
public:
    StoneSword();
    StoneSword(SpellFactory *sf, Character *c, int lvl, int id);
    ~StoneSword() { }

    virtual void apply();
};

class Spear : public Artefact
{
public:
    Spear();
    Spear(SpellFactory *sf, Character *c, int lvl, int id);
    ~Spear() { }

    virtual void apply();
};

class IronDagger : public Artefact
{
public:
    IronDagger();
    IronDagger(SpellFactory *sf, Character *c, int lvl, int id);
    ~IronDagger() { }

    virtual void apply();
};

class IronSword : public Artefact
{
public:
    IronSword();
    IronSword(SpellFactory *sf, Character *c, int lvl, int id);
    ~IronSword() { }

    virtual void apply();
};

class EnforcedRazor : public Artefact
{
public:
    EnforcedRazor();
    EnforcedRazor(SpellFactory *sf, Character *c, int lvl, int id);
    ~EnforcedRazor() { }

    virtual void apply();
};

class StoneBaton : public Artefact
{
public:
    StoneBaton();
    StoneBaton(SpellFactory *sf, Character *c, int lvl, int id);
    ~StoneBaton() { }

    virtual void apply();
};

class Mace : public Artefact
{
public:
    Mace();
    Mace(SpellFactory *sf, Character *c, int lvl, int id);
    ~Mace() { }

    virtual void apply();
};

class Lance : public Artefact
{
public:
    Lance();
    Lance(SpellFactory *sf, Character *c, int lvl, int id);
    ~Lance() { }

    virtual void apply();
};

class LongBow : public Artefact
{
public:
    LongBow();
    LongBow(SpellFactory *sf, Character *c, int lvl, int id);
    ~LongBow() { }

    virtual void apply();
};

class LightRazor : public Artefact
{
public:
    LightRazor();
    LightRazor(SpellFactory *sf, Character *c, int lvl, int id);
    ~LightRazor() { }

    virtual void apply();
};

class Scimitar : public Artefact
{
public:
    Scimitar();
    Scimitar(SpellFactory *sf, Character *c, int lvl, int id);
    ~Scimitar() { }

    virtual void apply();
};

class HeavyMace : public Artefact
{
public:
    HeavyMace();
    HeavyMace(SpellFactory *sf, Character *c, int lvl, int id);
    ~HeavyMace() { }

    virtual void apply();
};

class Palica : public Artefact
{
public:
    Palica();
    Palica(SpellFactory *sf, Character *c, int lvl, int id);
    ~Palica() { }

    virtual void apply();
};

class MetalHammer : public Artefact
{
public:
    MetalHammer();
    MetalHammer(SpellFactory *sf, Character *c, int lvl, int id);
    ~MetalHammer() { }

    virtual void apply();
};

class WarHammer : public Artefact
{
public:
    WarHammer();
    WarHammer(SpellFactory *sf, Character *c, int lvl, int id);
    ~WarHammer() { }

    virtual void apply();
};

class SteelDirk : public Artefact
{
public:
    SteelDirk();
    SteelDirk(SpellFactory *sf, Character *c, int lvl, int id);
    ~SteelDirk() { }

    virtual void apply();
};

class SuperRazor : public Artefact
{
public:
    SuperRazor();
    SuperRazor(SpellFactory *sf, Character *c, int lvl, int id);
    ~SuperRazor() { }

    virtual void apply();
};

class Rapier : public Artefact
{
public:
    Rapier();
    Rapier(SpellFactory *sf, Character *c, int lvl, int id);
    ~Rapier() { }

    virtual void apply();
};

class Trident : public Artefact
{
public:
    Trident();
    Trident(SpellFactory *sf, Character *c, int lvl, int id);
    ~Trident() { }

    virtual void apply();
};

class Ax : public Artefact
{
public:
    Ax();
    Ax(SpellFactory *sf, Character *c, int lvl, int id);
    ~Ax() { }

    virtual void apply();
};

class Scythe : public Artefact
{
public:
    Scythe();
    Scythe(SpellFactory *sf, Character *c, int lvl, int id);
    ~Scythe() { }

    virtual void apply();
};

class Kris : public Artefact
{
public:
    Kris();
    Kris(SpellFactory *sf, Character *c, int lvl, int id);
    ~Kris() { }

    virtual void apply();
};

class GreatSword : public Artefact
{
public:
    GreatSword();
    GreatSword(SpellFactory *sf, Character *c, int lvl, int id);
    ~GreatSword() { }

    virtual void apply();
};

class Falchion : public Artefact
{
public:
    Falchion();
    Falchion(SpellFactory *sf, Character *c, int lvl, int id);
    ~Falchion() { }

    virtual void apply();
};

class Flamberg : public Artefact
{
public:
    Flamberg();
    Flamberg(SpellFactory *sf, Character *c, int lvl, int id);
    ~Flamberg() { }

    virtual void apply();
};

class Katana : public Artefact
{
public:
    Katana();
    Katana(SpellFactory *sf, Character *c, int lvl, int id);
    ~Katana() { }

    virtual void apply();
};

class Halberd : public Artefact
{
public:
    Halberd();
    Halberd(SpellFactory *sf, Character *c, int lvl, int id);
    ~Halberd() { }

    virtual void apply();
};

class Crossbow : public Artefact
{
public:
    Crossbow();
    Crossbow(SpellFactory *sf, Character *c, int lvl, int id);
    ~Crossbow() { }

    virtual void apply();
};

class Cradle : public Artefact
{
public:
    Cradle();
    Cradle(SpellFactory *sf, Character *c, int lvl, int id);
    ~Cradle() { }

    virtual void apply();
};

class Musket : public Artefact
{
public:
    Musket();
    Musket(SpellFactory *sf, Character *c, int lvl, int id);
    ~Musket() { }

    virtual void apply();
};

class Arquebus : public Artefact
{
public:
    Arquebus();
    Arquebus(SpellFactory *sf, Character *c, int lvl, int id);
    ~Arquebus() { }

    virtual void apply();
};

class Riffle : public Artefact
{
public:
    Riffle();
    Riffle(SpellFactory *sf, Character *c, int lvl, int id);
    ~Riffle() { }

    virtual void apply();
};

class GrenadeGun : public Artefact
{
public:
    GrenadeGun();
    GrenadeGun(SpellFactory *sf, Character *c, int lvl, int id);
    ~GrenadeGun() { }

    virtual void apply();
};

class Flamethrower : public Artefact
{
public:
    Flamethrower();
    Flamethrower(SpellFactory *sf, Character *c, int lvl, int id);
    ~Flamethrower() { }

    virtual void apply();
};

class Plasmgun : public Artefact
{
public:
    Plasmgun();
    Plasmgun(SpellFactory *sf, Character *c, int lvl, int id);
    ~Plasmgun() { }

    virtual void apply();
};

class NuclearRiffle : public Artefact
{
public:
    NuclearRiffle();
    NuclearRiffle(SpellFactory *sf, Character *c, int lvl, int id);
    ~NuclearRiffle() { }

    virtual void apply();
};

class Desintegrator : public Artefact
{
public:
    Desintegrator();
    Desintegrator(SpellFactory *sf, Character *c, int lvl, int id);
    ~Desintegrator() { }

    virtual void apply();
};

class FSP : public Artefact
{
public:
    FSP();
    FSP(SpellFactory *sf, Character *c, int lvl, int id);
    ~FSP() { }

    virtual void apply();
};

class Warbow : public Artefact
{
public:
    Warbow();
    Warbow(SpellFactory *sf, Character *c, int lvl, int id);
    ~Warbow() { }

    virtual void apply();
};

class HellTridal : public Artefact
{
public:
    HellTridal();
    HellTridal(SpellFactory *sf, Character *c, int lvl, int id);
    ~HellTridal() { }

    virtual void apply();
};

class HandOfGod : public Artefact
{
public:
    HandOfGod();
    HandOfGod(SpellFactory *sf, Character *c, int lvl, int id);
    ~HandOfGod() { }

    virtual void apply();
};


#endif // BADSTICK_H
