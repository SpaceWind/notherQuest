#include "stats.h"
#include "utils.h"

Stats::Stats()
{
    strength = 0.;
    agility = 0.;
    intellect = 0.;
    speed = 0.;
    endurance = 0.;
    charisma = 0.;

    strPerLevel = 0.;
    agiPerLevel = 0.;
    intPerLevel = 0.;
    spdPerLevel = 0.;
    endPerLevel = 0.;
    chaPerLevel = 0.;
    level = 0;
    isBuilt = false;
}

Stats Stats::build()
{
    Stats stats = *this;;
    if (this->isBuilt)
        return stats;

    Stats result = (*this);
    result.strength = strength + strPerLevel*double(level);
    result.agility = agility + agiPerLevel*double(level);
    result.intellect = intellect + intPerLevel*double(level);
    result.speed = speed + spdPerLevel*double(level);
    result.endurance = endurance + endPerLevel*double(level);
    result.charisma = charisma + chaPerLevel*double(level);
    result.isBuilt = true;
    return result;
}

StatsInfo StatsInfo::buildInfo(Stats stats)
{

    StatsInfo info;
    info.damage = stats.strength * 5.0 + stats.agility *1.0;
    info.crc = stats.agility * 1.5;
    info.crd = stats.agility * 3.0 + stats.strength *1.0;
    info.arm = stats.agility * 1.0 + stats.endurance * 3.5;
    info.mr = stats.endurance * 2.0 + stats.charisma *0.5 + stats.intellect *0.5;
    info.mana = stats.intellect * 10.0 + 50;
    info.sd = stats.intellect * 8.0;
    info.mpr = stats.intellect * 0.005 + 0.05;
    info.hp = stats.strength * 6.0 + stats.endurance * 18.0 + 100.;
    info.hpr = stats.endurance * 0.1 + 0.5;
    info.rc = stats.charisma * 7.0;
    info.sc = stats.charisma * 4.0;
    info.siq = stats.charisma * 4.0;
    info.ms = stats.speed * 8.0;
    info.eq = stats.speed * 1.5;
    info.init = stats.speed * 0.15 + 10.0;
    info.as = stats.agility * 4.0 + stats.speed * 2.5;
    info.cs = stats.intellect * 4.0 + stats.speed * 2.5;

    return info;
}

double StatsInfo::speciality()
{
    double pS, mS, nS;
    pS = damage * 182. + crc*666. + crd*200.;
    mS = sd * 125. + (mana-50.) * 100. + (mpr - 0.05)*200000.;
    nS = (arm * 222. + mr * 333. + (hp - 100.)*42. + (hpr - 0.5) * 10000. + eq*666. + init * 6666.)*0.66;

    double normalV = (pS + nS)/(pS + nS + mS + nS);
    return StaticMethods::minmax(2*normalV - 0.5, 0.1, 0.9);
}

double StatsInfo::offensiveness()
{
    double ofP, defP;
    ofP = damage * 182. + crc*400. + crd*200. + sd * 125. + init * 6666.;
    defP = arm * 222. + mr * 333. + (hp - 100.)*42. + (hpr - 0.5) * 10000. + eq*666.;

    double normalV = ofP / (ofP + defP);
    return normalV;
}

void Character::update()
{
    info = StatsInfo::buildInfo(stats.build());
}

void Character::reset()
{
    currentHP = info.hp;
    currentMana = info.mana;
    currentInit = info.init;
}

void Character::resetPrepared()
{
    preparedInfo = info;
    preparedStats = stats;
}

AutoAttack AutoAttack::makeAutoAttack(Character &a, Character &d)
{
    AutoAttack result;
    result.damage = a.preparedInfo.damage;

    if (StaticMethods::procChance(a.preparedInfo.crtChance()))
    {
        result.damage *= a.preparedInfo.crtDamage();
        result.isCrit = true;
    }
    else
        result.isCrit = false;
    double resist = a.isMagicAutoAttack ?
                    d.preparedInfo.armor() : d.preparedInfo.mres();
    result.damage *= 1.0 - resist;

    if (StaticMethods::procChance(d.preparedInfo.evasion() * (1.0 - a.preparedInfo.evasion()/2.0)))
    {
        result.missed = true;
        result.isDefenderDead = false;
        return result;
    }
    else
        result.missed = false;

    if (d.currentHP - result.damage <= 0.0)
        result.isDefenderDead = true;
    else
        result.isDefenderDead = false;

    return result;
}
