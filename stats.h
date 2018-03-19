#ifndef STATS_H
#define STATS_H

#include <QObject>
#include <QString>

/*
 * STR: урон, хп
AGI: критшанс, армор.
INT: запас маны, урон от спелов
SPD: скорость передвижения по карте, уворот.
END: хп, армор, мрез.
CHA: +золото с мобов, мрез, цена продажи, шанс найти ценную вещь.



STR: +5MD, +8HP
AGI: +4CRT, +4CRD, + 4ARM
INT: +10MP, +10SD, +0.25MPR
SPD: +10MS, + 5EQ
END: +15HP, +5ARM, +3MR, +0.25HPR
CHA: +8RC, +2MR, + 4SC, +4SR


CRTchance = (CRT / CRT+100)
CRTDamage = 1.25 + CRD/100
SDamageQF = 1.0 + SD/100
EvasionQF = (EQ / EQ+100)
Reward = 1.0 + RC/100
TradePriceBuy = 1.0 - (SC / (SC + 500))
TradePriceSell = 1.0 - TradePriceBuy
SpecialItemChance = 0.05 + (SR/ (SR + 200))

 * */

struct Stats
{
    Stats();
    double strength, agility, intellect, speed, endurance, charisma;
    double strPerLevel, agiPerLevel, intPerLevel, spdPerLevel, endPerLevel, chaPerLevel;
    int level;
    bool isBuilt;

    Stats build();

    double aspect() {return (0.4 *strength + 0.6*agility) / (0.4 *strength + 0.6*agility + 0.9*intellect +0.1*charisma);}
};

struct StatsInfo
{
    static StatsInfo buildInfo(Stats stats);
    double damage;
    double crc, crd;
    double arm, mr;
    double mana, sd, mpr;
    double hp, hpr;
    double rc, sc, siq;
    double ms, eq;
    double init;
    double as, cs;

    double crtChance()          { return crc / (crc+100.); }
    double crtDamage()          { return 1.25 + crd/100.; }
    double spellDamage()        { return 1.0 + sd/100.; }
    double evasion()            { return eq / (eq+100.); }
    double rewardCoef()         { return 1.0 + rc/100.; }
    double tradePriceBuyCoef()  { return 1.0 - (sc / (sc + 500)); }
    double tradePriceSellCoef() { return 2.0 - tradePriceBuyCoef(); }
    double specialItemChance()  { return 0.05 + siq/(siq + 200); }
    double armor()              { return arm / (arm + 100.); }
    double mres()               { return mr / (mr + 100.); }

    double attackSpeed()        { return 1.0 - as / (as + 100.); }
    double castSpeed()          { return 1.0 - cs / (cs + 100.); }

    double speciality();
    double offensiveness();
};

struct PassiveList
{
    QList<int> launchers;
    QList<int> buffs;
    QList<int> globals;
};

struct ActiveSpells
{
    QList<int> activeSpells;
    QList<int> passives;
    QList<int> globals;
};

struct Character
{
    QString name;
    Stats stats, preparedStats;
    StatsInfo info, preparedInfo;
    int id;

    double currentInit;
    double currentMana, currentHP;
    bool isMagicAutoAttack;

    void update();
    void reset();
    void resetPrepared();
    bool alive() {return currentHP > 0.0; }

    PassiveList passives;
    ActiveSpells actives;
};


struct AutoAttack
{
    static AutoAttack makeAutoAttack(Character &a, Character &d);

    double damage;
    double enemyHealed;
    bool isCrit;
    bool isDefenderDead;
    bool missed;
};

#endif // STATS_H
