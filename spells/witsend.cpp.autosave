#include "witsend.h"

//Damage: 0/50/100/150/200 + 100SQF
WitsEndNuke::WitsEndNuke(Character *owner, int lvl)
    : Nuke(owner, lvl)
{
    name = "WitsEndNuke";
    currentCD = 0;
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

Nuke::Result WitsEndNuke::launch(const Character *receiver)
{
    Nuke::Result result;
    if (!isReady())
        return result;
    result.isActive = true;
    result.magicDamage = damage + 100*owner->preparedInfo.spellDamage();
    return result;
}

WitsEndDebuff::WitsEndDebuff(Character *owner, int lvl)
    : Buff(owner, lvl)
{
    name = "WitsEndDebuff";
    title = "Смерть разума " + QString::number(lvl);
    health = -1;
    manacost = 0;
    value = 15 + 10*(lvl-1);
}

void WitsEndDebuff::apply(Character *receiver)
{
    receiver->preparedInfo.mr -= value;
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
