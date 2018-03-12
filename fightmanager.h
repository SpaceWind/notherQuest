#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include "spellfactory.h"
#include "stats.h"
#include <QList>
#include <QObject>
#include <QHash>

class FightManager : public QObject
{
    Q_OBJECT
public:
    FightManager(SpellFactory *sf, QObject *o);

    void addPlayer(Character *c);
    void addEnemy(Character *c);

    void startFight();
    void startTurn();
    
    enum CharSearchRule {FIRST, LAST, RANDOM, OFFENSIVE, WEAK};

signals:
    void message(QString s);
private:
    Character* pickNext();
    void updateInit();
    Character* findEnemy(CharSearchRule rule, bool isFindEnemy);
    Character* findById(int id);
    
    void applyFightStart(Character *c);
    void applyTurn(Character *c);
    void applyNuke(Character *sender, int spellId, Nuke::Result r, int receiverId) { applyNuke(sender, spellId, r, findById(receiverId)); }
    void applyNuke(Character *sender, int spellId, Nuke::Result r, Character* c);
    void applyLauncher(Launcher::Result r);

    QList<Character*> playerTeam;
    QList<Character*> enemyTeam;



    SpellFactory * sf;
};

#endif // FIGHTMANAGER_H
