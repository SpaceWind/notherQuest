#include "hybridstrike.h"

HybridStrike::HybridStrike(Character *owner, int lvl)
    : Nuke (owner, lvl)
{
    this->name = "HybridStrike";
    updateLvl(lvl);
}

Nuke::Result HybridStrike::launch(const Character *receiver)
{
    Nuke::Result result;
    if (!isReady())
        return result;
    result.isActive = true;
    result.magicDamage = damage + 40*owner->preparedInfo.spellDamage() + 1.0*owner->preparedInfo.damage;
    return result;
}

void HybridStrike::updateLvl(int lvl)
{
    this->lvl = lvl;
    this->title = "Гибридный удар " + QString::number(lvl) +"го уровня";
    switch (lvl)
    {
    case 1:
        cd = 4;
        manacost = 15;
        damage = 20;
        break;
    case 2:
        cd = 3;
        manacost = 25;
        damage = 40;
        break;
    case 3:
        cd = 2;
        manacost = 35;
        damage = 60;
        break;
    case 4:
        cd = 2;
        manacost = 45;
        damage = 80;
        break;
    case 5:
        cd = 1;
        manacost = 60;
        damage = 100;
        break;
    default:
        break;
    }
}
