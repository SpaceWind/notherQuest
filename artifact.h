#ifndef ARTIFACT_H
#define ARTIFACT_H
#include "stats.h"
#include "spellfactory.h"
#include <QList>

class Artifact
{
public:
    Artifact();
    Artifact(SpellFactory *sf, Character *c, int lvl, int id);
    virtual ~Artifact() { }
    enum ArtifactSlot{HEAD, SHOWLDERS, BODY, ARMS, LEGS, FEET, AMULET, LEFT_RING, RIGHT_RING, WEAPON};
    enum Rarity {COMMON, UNCOMMON, RARE, MYTHICAL, LEGENDARY};
    enum Type {BASE, PREFIX, POSTFIX};

    void setPrefix(Artifact *a) {prefix = a;}
    void setPostfix(Artifact *a) {postfix = a;}
    void setRarity(Artifact::Rarity r) {rarity = r;}

    Artifact::ArtifactSlot getSlot() { return slot; }
    int getLvl() { return lvl; }

    virtual void init() = 0;
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

    Artifact *prefix;
    Artifact *postfix;
    QList<int> spells;

    ArtifactSlot slot;
    Rarity rarity;
    Type type;
};

#endif // ARTIFACT_H
