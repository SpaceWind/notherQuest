#ifndef ARTEFACT_H
#define ARTEFACT_H
#include "stats.h"
#include "spells/spellfactory.h"
#include <QList>

class Artefact
{
public:
    Artefact();
    Artefact(SpellFactory *sf, Character *c, int lvl, int id);
    virtual ~Artefact() { }
    enum ArtefactSlot{HEAD, SHOWLDERS, BODY, ARMS, LEGS, FEET, AMULET, LEFT_RING, RIGHT_RING, WEAPON};
    enum Rarity {COMMON, UNCOMMON, RARE, MYTHICAL, LEGENDARY};
    enum Type {BASE, PREFIX, POSTFIX};

    void setPrefix(Artefact *a) {prefix = a;}
    void setPostfix(Artefact *a) {postfix = a;}
    void setRarity(Artefact::Rarity r) {rarity = r;}

    Artefact::ArtefactSlot getSlot() { return slot; }
    int getLvl() { return lvl; }

    virtual void init();
    virtual void apply() = 0;

    virtual double getPrice();

protected:
    int id;
    double price;
    int lvl;
    bool isValid;
    QString name, title;
    Character * owner;
    SpellFactory *sf;

    Artefact *prefix;
    Artefact *postfix;
    QList<int> spells;

    ArtefactSlot slot;
    Rarity rarity;
    Type type;
};

#endif // ARTEFACT_H
