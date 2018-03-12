#include "cutstrike.h"

// SPELLS
CutStrike::CutStrike(Character *owner, int lvl)
    : Nuke(owner, lvl)
{
    this->name = "CutStrike";
    this->title = "Рассечение " + QString::number(lvl) +"го уровня";
    switch (lvl)
    {
    case 1:
        cd = 6;
        manacost = 5;
        damage = 30;
        break;
    case 2:
        cd = 5;
        manacost = 10;
        damage = 60;
        break;
    case 3:
        cd = 4;
        manacost = 15;
        damage = 90;
        break;
    case 4:
        cd = 3;
        manacost = 25;
        damage = 120;
        break;
    case 5:
        cd = 2;
        manacost = 40;
        damage = 150;
        break;
    default:
        break;
    }
}

Nuke::Result CutStrike::launch(const Character *receiver)
{
    Nuke::Result result;
    if (!isReady())
        return result;
    result.isActive = true;
    result.physDamage = damage + 80*owner->preparedInfo.spellDamage() + 0.5*owner->preparedInfo.damage;
    return result;
}
