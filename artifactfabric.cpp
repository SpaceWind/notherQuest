#include "artifactfabric.h"
#include "utils.h"

ArtifactFabric::ArtifactFabric(SpellFactory *sf)
{
    this->sf = sf;
    currentId = 1;
}

void ArtifactFabric::init()
{
    //QHash<QString, ArtifactLvl> levels;
    levels["BadStick"] = ArtifactLvl(0, 10);
    levels["WeaponPostfixDeath"] = ArtifactLvl();

    //QHash<QString, Artifact::ArtifactSlot> artSlots;
    artSlots["BadStick"] = Artefact::WEAPON;
    artSlots["WeaponPostfixDeath"] = Artefact::WEAPON;

    //QHash<QString, Artifact::Rarity> artRarity;
    artRarity["BadStick"] = Artefact::COMMON;
    artRarity["WeaponPostfixDeath"] = Artefact::RARE;

    //QHash<Artifact::ArtifactSlot, QHash<Artifact::Type, QList<QString> > > items;
    QList<QString> weaponBase;
    weaponBase << "BadStick";
    QList<QString> weaponPostfix;
    weaponPostfix << "WeaponPostfixDeath";

    items[Artefact::WEAPON][Artefact::BASE] = weaponBase;
    items[Artefact::WEAPON][Artefact::POSTFIX] = weaponPostfix;

}

QString ArtifactFabric::findBase(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity)
{
    return findItem(slot, lvl, Artefact::BASE, rarity);
}

QString ArtifactFabric::findPrefix(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity)
{
    return findItem(slot, lvl, Artefact::PREFIX, rarity);
}

QString ArtifactFabric::findPostfix(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity)
{
    return findItem(slot, lvl, Artefact::POSTFIX, rarity);
}

QString ArtifactFabric::findItem(Artefact::ArtefactSlot slot, int lvl, Artefact::Type type, QList<Artefact::Rarity> rarity)
{
    QList<QString> result;
    foreach (const QString &s, items[slot][type])
        if (levels[s].check(lvl) && (rarity.contains(artRarity[s]) || rarity.isEmpty()))
            result.append(s);
    if (result.isEmpty())
        return "";
    return result[qrand()%result.count()];
}

Artefact *ArtifactFabric::getArtifact(QString name, int lvl, Character*c)
{
    if (name == "BadStick")
        return new BadStick(sf, c, lvl, currentId++);
    if (name == "WeaponPostfixDeath")
        return new WeaponPostfixDeath(sf, c, lvl, currentId++);
    return 0;
}

Artefact *ArtifactFabric::generateBase(int minLvl, int maxLvl, QList<Artefact::ArtefactSlot> slot, QList<Artefact::Rarity> rarity, Character *c)
{
    int lvl = qrand()%(maxLvl-minLvl) + minLvl;
    if (slot.isEmpty())
        slot << Artefact::WEAPON;
    int slotIndex = qrand()%slot.count();

    QString name = findBase(slot[slotIndex], lvl, rarity);
    return getArtifact(name, lvl, c);
}

Artefact *ArtifactFabric::generatePrefix(Artefact::ArtefactSlot slot, int lvl, Character *c)
{
    QString name = findPrefix(slot, lvl);
    return getArtifact(name, lvl, c);
}

Artefact *ArtifactFabric::generatePostfix(Artefact::ArtefactSlot slot, int lvl, Character *c)
{
    QString name = findPostfix(slot, lvl);
    return getArtifact(name, lvl,c);
}

Artefact *ArtifactFabric::generate(bool isSpecial, int minLvl, int maxLvl, Character *c)
{
    Artefact * base = generateBase(minLvl, maxLvl,
                                   QList<Artefact::ArtefactSlot>(),
                                   QList<Artefact::Rarity>() << Artefact::COMMON,c);
    if (!isSpecial)
        return base;

    bool needPrefix = false, needPostfix = false, uniqueInstead = false;
    if (StaticMethods::procChance(0.7))
        needPrefix = true;
    else
        needPostfix = true;

    if (needPrefix && StaticMethods::procChance(0.07))
        needPostfix = true;
    else if (needPostfix && StaticMethods::procChance(0.3))
        needPostfix = true;

    if (needPrefix && needPostfix && StaticMethods::procChance(0.1))
        uniqueInstead = true;

    if (uniqueInstead)
    {
        delete base;
        return generateBase(minLvl, maxLvl, QList<Artefact::ArtefactSlot>(), QList<Artefact::Rarity>() << Artefact::LEGENDARY, c);
    }

    if (needPrefix)
    {
        Artefact *prefix = generatePrefix(base->getSlot(), base->getLvl(), c);
        base->setPrefix(prefix);
        base->setRarity(Artefact::UNCOMMON);
    }
    if (needPostfix)
    {
        Artefact *postfix = generatePostfix(base->getSlot(), base->getLvl(), c);
        base->setPostfix(postfix);
        base->setRarity(Artefact::RARE);
    }
    if (needPrefix && needPostfix)
        base->setRarity(Artefact::MYTHICAL);
    return base;
}
