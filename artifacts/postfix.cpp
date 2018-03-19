#include "postfix.h"
#include <spells/allspells.h>

WeaponPostfixDeath::WeaponPostfixDeath()
    : Artefact ()
{
    slot = WEAPON;
    type = POSTFIX;
    rarity = RARE;
    name = "WeaponPostfixDeath";
    title = "Смерти";
}

WeaponPostfixDeath::WeaponPostfixDeath(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = POSTFIX;
    rarity = RARE;
    price = 20 + 3*lvl;
    name = "WeaponPostfixDeath";
    title = "Смерти";
}

void WeaponPostfixDeath::init()
{
    this->spells.append(sf->createSpell("WeaponDeathPostfix", owner, lvl));
    owner->passives.launchers.append(this->spells.last());
}

void WeaponPostfixDeath::apply()
{
    owner->preparedInfo.damage += 25.0 + 0.1*lvl;
}
