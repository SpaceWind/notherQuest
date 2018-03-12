#ifndef MAGIC_H
#define MAGIC_H

#include <QObject>
#include "stats.h"

#define SPELL_TYPE_NUKE QString("N")
#define SPELL_TYPE_BUFF QString("B")
#define SPELL_TYPE_LAUNCHER QString("L")
#define SPELL_TYPE_AUGMENTATION QString("A")
#define SPELL_TYPE_COMPLEX QString("C")

namespace Magic {

enum Aspect { SINGLE, AOE, ENEMY_AOE, ALLY_AOE, RANDOM, RANDOM_ENEMY, RANDOM_ALLY };

struct Spell
{
    Spell ();
    Spell (const QString &name, const QString &title, int id, Character *owner, int lvl);
    virtual ~Spell() {}

    bool isReady() {return currentCD <= 0.0;}
    double step(int time);

    QString name;
    QString title;
    int id;
    Character *owner;
    int lvl;
    int manacost, cd;
    double currentCD;
    bool selfCast;
    double health;
};

struct Nuke : public Spell
{
    Nuke() : Spell() {}
    Nuke(Character *owner, int lvl);
    virtual ~Nuke () {}

    struct Result
    {
        Result() { isActive = false; physDamage = magicDamage = trueDamage = manaDamage = 0.0; }
        ~Result() {}
        bool isActive;
        double physDamage;
        double magicDamage;
        double trueDamage;
        double manaDamage;
    };
    virtual Result launch(const Character *receiver) = 0;
};

struct Buff : public Spell
{
    Buff() : Spell() {}
    Buff (Character *owner, int lvl);
    virtual ~Buff () { }

    virtual void apply(Character *receiver) = 0;
    virtual bool isActive() { bool alive = health != 0; health--; return alive; }
protected:
};

struct Launcher : public Spell
{
    Launcher() : Spell() {}
    Launcher (const Character *owner, int lvl);
    virtual ~Launcher () { }

    struct Result
    {
        static Result emptyResult();
        bool isActive;
        bool skipTurn;
        bool secondTurn;
        int ownerID, receiverID, lvl;
        Aspect aspect;
        QString spellName;
    };

    virtual bool isActive() { bool alive = health != 0; health--; return alive; }
    virtual Result beforeTurn(){ return Result::emptyResult(); }
    virtual Result onTurn() { return Result::emptyResult(); }
    virtual Result beforeAttack(AutoAttack &aa, Character *receiver) { return Result::emptyResult(); }
    virtual Result afterAttack(const AutoAttack &aa, Character *receiver) { return Result::emptyResult(); }
    virtual Result onKill (Character *receiver) { return Result::emptyResult(); }
    virtual Result beforeSpell (Character *sender, int spellID) { return Result::emptyResult(); }
    virtual Result afterSpell (Character *sender, int spellID) { return Result::emptyResult(); }
    virtual Result beforeReceiveAutoAttack(AutoAttack &aa, Character *sender) { return Result::emptyResult(); }
    virtual Result afterReceiveAutoAttack(const AutoAttack &aa, Character *sender) { return Result::emptyResult(); }
    virtual Result onFightStart() { return Result::emptyResult(); }
    virtual Result onFightEnd(bool win) { return Result::emptyResult(); }
};

struct Augmentation : public Spell
{
    Augmentation() : Spell() {}
    Augmentation (Character *owner, int lvl);
    virtual ~Augmentation () { }

    virtual void apply(Character *receiver) = 0;
};

struct Complex : public Spell
{
    Complex() : Spell() {}
    Complex (Character *owner, int lvl);
    virtual ~Complex () { }

    void addSpell(int spellId);
    virtual QList<int> launch() { return spells; }
    virtual QList<QString> prepare() { return QList<QString>(); }
protected:
    QList<int> spells;

};

}
#endif // MAGIC_H
