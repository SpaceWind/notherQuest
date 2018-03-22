#include "cutstrike.h"
#include <QVector>

// SPELLS
CutStrike::CutStrike(Character *owner, int lvl)
    : Nuke(owner, lvl)
{
    this->name = "CutStrike";
    updateLvl(lvl);
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

void CutStrike::updateLvl(int lvl)
{
    this->lvl = lvl;
    this->title = "Рассечение " + QString::number(lvl) +"го уровня";

    cd = (QVector<int>() << 6 << 5 << 4 << 3 << 2) [lvl-1];
    manacost = (QVector<int>() << 5 << 10 << 15 << 25 << 40) [lvl-1];
    damage = (QVector<int>() << 30 << 60 << 90 << 120 << 150) [lvl-1];
}
