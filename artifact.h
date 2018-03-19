#ifndef ARTIFACT_H
#define ARTIFACT_H
#include "stats.h"
#include <QList>


class Artifact
{
public:
    Artifact();
    Artifact(Character *c, int lvl, int id);
    virtual ~Artifact() { }
    enum ArtifactSlot{HEAD, SHOWLDERS, BODY, ARMS, LEGS, FEET, AMULET, LEFT_RING, RIGHT_RING};
    enum Rarity {COMMON, UNCOMMON, RARE, MYTHICAL, LEGENDARY};
    enum Type {BASE, PREFIX, POSTFIX};

    void setPrefix(Artifact *a) {prefix = a;}
    void setPostfix(Artifact *a) {postfix = a;}

    virtual apply() = 0;

private:
    int id;
    double price;
    int lvl;
    bool isValid;
    Character * owner;

    Artifact *prefix;
    Artifact *postfix;
    QList<int> spells;

    ArtifactSlot slot;
    Rarity rarity;
    Type type;
};

#endif // ARTIFACT_H
