#include "weapondeathpostfix.h"

WeaponPostfixDeathSpell::WeaponPostfixDeathSpell()
    : Launcher()
{
    name = "WeaponDeathPostfixSpell";
}

WeaponPostfixDeathSpell::WeaponPostfixDeathSpell(Character *owner, int lvl)
    : Launcher(owner, lvl)
{
    name = "WeaponDeathPostfixSpell";
    title = "Смертоносность";
    health = -1;
    manacost = 0;
}

Launcher::Result WeaponPostfixDeathSpell::beforeAttack(AutoAttack &aa, Character *receiver)
{
    aa.damage += receiver->currentHP * 0.03;
    return Launcher::Result();
}
