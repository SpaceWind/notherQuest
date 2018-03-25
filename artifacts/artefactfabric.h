#ifndef ARTEFACTFABRIC_H
#define ARTEFACTFABRIC_H

#include "all.h"
#include <QHash>


class ArtefactFabric
{
public:
    ArtefactFabric(SpellFactory *sf);

    void init();

    struct ArtifactLvl
    {
        ArtifactLvl() { min = max = 0; }
        ArtifactLvl(int minLvl, int maxLvl = 9999) { min = minLvl, max = maxLvl; }
        ~ArtifactLvl(){}
        bool check(int lvl) { return lvl >= min && lvl <= max; }
        int min, max;
    };

    QString findBase(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity = QList<Artefact::Rarity>());
    QString findPrefix(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity = QList<Artefact::Rarity>());
    QString findPostfix(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity = QList<Artefact::Rarity>());
    QString findItem(Artefact::ArtefactSlot slot, int lvl, Artefact::Type type, QList<Artefact::Rarity> rarity = QList<Artefact::Rarity>());

    Artefact* getArtifact(QString name, int lvl, Character *c = 0);

    Artefact* generateBase(int minLvl, int maxLvl,
                           QList<Artefact::ArtefactSlot> slot = QList<Artefact::ArtefactSlot>(),
                           QList<Artefact::Rarity> rarity = QList<Artefact::Rarity>(),
                           Character *c = 0);
    Artefact* generatePrefix(Artefact::ArtefactSlot slot, int lvl, Character *c);
    Artefact* generatePostfix(Artefact::ArtefactSlot slot, int lvl, Character *c);

    Artefact* generate(bool isSpecial, int minLvl, int maxLvl, Character *c = 0);


protected:
    QHash<QString, ArtifactLvl> levels;
    QHash<QString, Artefact::ArtefactSlot> artSlots;
    QHash<QString, Artefact::Rarity> artRarity;
    QHash<Artefact::ArtefactSlot, QHash<Artefact::Type, QList<QString> > > items;

    SpellFactory *sf;
    int currentId;
};


#endif // ARTEFACTFABRIC_H
