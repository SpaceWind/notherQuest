#include "nukes.h"

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
    cd = LVLI(4, 4, 3, 3, 2);
    damage = 25 * lvl;
}
//--------------------------------------------------------------------------
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

    cd = LVLI(6, 5, 4, 3, 2);
    manacost = LVLI(5, 10, 15, 25, 40);
    damage = LVLI(30, 60, 90, 120, 150);
}
//--------------------------------------------------------------------------

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

    cd = LVLI(4, 3, 2, 2, 1);
    manacost = LVLI(15, 25, 35, 45, 60);
    damage = LVLI(20, 40, 60, 80, 100);
}
//------------------------------------------------------------------------------------
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

    damage = LVLI(0, 50, 100, 150, 200);
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

Desintegration::Desintegration(Character *owner, int lvl)
    : Nuke(owner, lvl)
{
    name = "Desintegration";
    updateLvl(lvl);
}

Nuke::Result Desintegration::launch(const Character *receiver)
{
    Nuke::Result result;
    if (!isReady())
        return result;
    result.magicDamage = damage + 0.1*(receiver->preparedInfo.hp - receiver->currentHP) + 50.0*owner->preparedInfo.spellDamage();
    result.isActive = true;
    return result;
}

void Desintegration::updateLvl(int lvl)
{
    title = "Дезинтеграция " + QString::number(lvl) + "го уровня";
    manacost = 40;
    cd = LVLI(8, 6, 5, 4, 3);
    damage = 10 + 30*lvl;
}
