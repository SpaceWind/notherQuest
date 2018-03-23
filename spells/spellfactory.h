#ifndef SPELLFABRIC_H
#define SPELLFABRIC_H

#include "allspells.h"
#include <QHash>

class SpellFactory
{
public:
    SpellFactory();
    ~SpellFactory() {}
    int createSpell(QString name, Character *c, int lvl);
    int generic(int spellId);
    QString getTypeByName(QString name);
    QString getTypeById(int id);
    QString getName(int id);
    int findSpell(QString name, int owner);

    Magic::Nuke *getNuke(int id);
    Magic::Buff* getBuff(int id);
    Magic::Launcher* getLauncher(int id);
    Magic::Augmentation* getAugmentation(int id);
    Magic::Complex* getComplex(int id);

    void removeSpell(int id);

    double update(int id, double time);
    void resetCD(int id);
    void makeReady(int id);
    bool isReady(int id);
    bool isActive(int id);

private:

    int bindSpell(Magic::Spell* s);
    QHash<int, QString> names;
    QHash<QString, QString> types;

    QHash<int, Magic::Spell*> spells;
    int currentID;
};


#endif // SPELLFABRIC_H
