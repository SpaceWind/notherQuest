#ifndef ARTIFACTFABRIC_H
#define ARTIFACTFABRIC_H

#include "artifacts/all.h"
#include <QHash>


class ArtifactFabric
{
public:
    ArtifactFabric(SpellFactory *sf);

    void init();

    struct ArtifactLvl
    {
        ArtifactLvl() { min = max = 0; }
        ArtifactLvl(int minLvl, int maxLvl) { min = minLvl, max = maxLvl; }
        ~ArtifactLvl(){}
        bool check(int lvl) { return lvl >= min && lvl <= max; }
        int min, max;
    };

    QString findBase(Artifact::ArtifactSlot slot, int lvl, QList<Artifact::Rarity> rarity = QList<Artifact::Rarity>());
    QString findPrefix(Artifact::ArtifactSlot slot, int lvl, QList<Artifact::Rarity> rarity = QList<Artifact::Rarity>());
    QString findPostfix(Artifact::ArtifactSlot slot, int lvl, QList<Artifact::Rarity> rarity = QList<Artifact::Rarity>());
    QString findItem(Artifact::ArtifactSlot slot, int lvl, Artifact::Type type, QList<Artifact::Rarity> rarity = QList<Artifact::Rarity>());

    Artifact* getArtifact(QString name, int lvl, Character *c = 0);

    Artifact* generateBase(int minLvl, int maxLvl,
                           QList<Artifact::ArtifactSlot> slot = QList<Artifact::ArtifactSlot>(),
                           QList<Artifact::Rarity> rarity = QList<Artifact::Rarity>(),
                           Character *c = 0);
    Artifact* generatePrefix(Artifact::ArtifactSlot slot, int lvl, Character *c);
    Artifact* generatePostfix(Artifact::ArtifactSlot slot, int lvl, Character *c);

    Artifact* generate(bool isSpecial, int minLvl, int maxLvl, Character *c = 0);


protected:
    QHash<QString, ArtifactLvl> levels;
    QHash<QString, Artifact::ArtifactSlot> artSlots;
    QHash<QString, Artifact::Rarity> artRarity;
    QHash<Artifact::ArtifactSlot, QHash<Artifact::Type, QList<QString> > > items;

    SpellFactory *sf;
    int currentId;
};

#endif // ARTIFACTFABRIC_H
