#ifndef WEAPONDEATHPOSTFIX_H
#define WEAPONDEATHPOSTFIX_H
#include <magic.h>
using namespace Magic;

class WeaponPostfixDeathSpell :public Launcher
{
public:
    WeaponPostfixDeathSpell();
    WeaponPostfixDeathSpell(Character * owner, int lvl);

    virtual Result beforeAttack(AutoAttack &aa, Character *receiver);
};

#endif // WEAPONDEATHPOSTFIX_H
