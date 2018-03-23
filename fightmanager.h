#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include "spells/spellfactory.h"
#include "stats.h"
#include <QList>
#include <QObject>
#include <QHash>
#include "utils.h"

class FightManager : public QObject
{
    Q_OBJECT
public:
    FightManager(SpellFactory *sf, QuestTimer *q, QObject *o);

    enum CharSearchRule {FIRST, LAST, RANDOM, OFFENSIVE, WEAK};
    struct FightCycleResult
    {
        FightCycleResult() {turnEnded = playerWon = enemyWon = false;}
        ~FightCycleResult() {}
        bool done() {return turnEnded || playerWon || enemyWon;}
        bool ended() {return playerWon || enemyWon; }
        bool turnEnded;
        bool playerWon;
        bool enemyWon;
    };

public slots:
    void addPlayer(Character *c) { playerTeam.append(c); }
    void addEnemy(Character *c)  { enemyTeam.append(c); }

    void startFight();
    void startTurn();
    void clear() {playerTeam.clear(); enemyTeam.clear();}
    FightCycleResult runFightCycle();

signals:
    void message(QString s);
    void invokeStartQt(double time, bool animation);
    void nextTurn();
    void fightEnded(bool playerWon);
private:
    Character* pickNext();
    void updateInit();
    Character* findEnemy(CharSearchRule rule, bool isFindEnemy);
    Character* findById(int id);

    void awaitTimer();
    void runMessage(QString s, double time = 5.0, bool animation = true);
    
    void applyFightStart(Character *c);
    void applyTurn(Character *c);
    void applyNuke(Character *sender, int spellId, Nuke::Result r, int receiverId) { applyNuke(sender, spellId, r, findById(receiverId)); }
    void applyNuke(Character *sender, int spellId, Nuke::Result r, Character* c);
    void applyLauncher(Launcher::Result r);

    QList<Character*> playerTeam;
    QList<Character*> enemyTeam;



    SpellFactory * sf;
    QuestTimer *qt;
    int turnNumber;
};

#endif // FIGHTMANAGER_H
