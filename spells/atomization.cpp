#include "atomization.h"
#include <QVector>

Atomization::Atomization(Character *owner, int lvl)
    : Nuke(owner, lvl)
{
    name = "Atomization";
    updateLvl(lvl);
}

Nuke::Result Atomization::launch(const Character *receiver)
{
    Nuke::Result result;
    if (!isReady())
        return result;
    result.physDamage = damage + 0.1*receiver->currentHP + 50*owner->preparedInfo.spellDamage() + owner->preparedInfo.damage;
    result.isActive = true;
    return result;
}

void Atomization::updateLvl(int lvl)
{
    this->lvl = lvl;
    title = "Распыление " + QString::number(lvl) + "го уровня";
    manacost = 30;
    switch (lvl)
    {
    case 1:
    case 2:
        cd = 4; break;
    case 3:
    case 4:
        cd = 3; break;
    case 5:
        cd = 2; break;
    }
    damage = 25 * lvl;
}
