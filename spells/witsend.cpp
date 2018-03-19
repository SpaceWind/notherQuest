#include "witsend.h"

WitsEndNuke::WitsEndNuke(Character *owner, int lvl)
    : Nuke(owner, lvl)
{
    name = "WitsEndNuke";
    currentCD = 0;
    updateLvl(lvl);
}

Nuke::Result WitsEndNuke::launch(const Character *receiver)
{
    Nuke::Result result;
    if (!isReady())
        return result;
    result.isActive = true;
    result.magicDamage = damage + 100*owner->preparedInfo.spellDamage();
    return result;
}

void WitsEndNuke::updateLvl(int lvl)
{
    this->lvl = lvl;
    this->title = "Распыление (удар) " + QString::number(lvl) +"го уровня";
    cd = 0;
    manacost = 0;

    switch (lvl)
    {
    case 1:
        damage = 0;
        break;
    case 2:
        damage = 50;
        break;
    case 3:
        damage = 100;
        break;
    case 4:
        damage = 150;
        break;
    case 5:
        damage = 200;
        break;
    default:
        break;
    }
}

WitsEndDebuff::WitsEndDebuff(Character *owner, int lvl)
    : Buff(owner, lvl)
{
    name = "WitsEndDebuff";
    updateLvl(lvl);
}

void WitsEndDebuff::apply(Character *receiver)
{
    receiver->preparedInfo.mr -= value;
}

void WitsEndDebuff::updateLvl(int lvl)
{
    this->lvl = lvl;
    title = "Смерть разума " + QString::number(lvl);
    health = -1;
    manacost = 0;
    value = 15 + 10*(lvl-1);
}

WitsEnd::WitsEnd(Character *owner, int lvl)
    : Complex(owner, lvl)
{

}

QList<QString> WitsEnd::prepare()
{
    QList<QString> result;
    result.append("WitsEndNuke");
    result.append("WitsEndDebuff");
    return result;
}
