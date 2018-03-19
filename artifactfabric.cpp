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
    artSlots["BadStick"] = Artifact::WEAPON;
    artSlots["WeaponPostfixDeath"] = Artifact::WEAPON;

    //QHash<QString, Artifact::Rarity> artRarity;
    artRarity["BadStick"] = Artifact::COMMON;
    artRarity["WeaponPostfixDeath"] = Artifact::RARE;

    //QHash<Artifact::ArtifactSlot, QHash<Artifact::Type, QList<QString> > > items;
    QList<QString> weaponBase;
    weaponBase << "BadStick";
    QList<QString> weaponPostfix;
    weaponPostfix << "WeaponPostfixDeath";

    items[Artifact::WEAPON][Artifact::BASE] = weaponBase;
    items[Artifact::WEAPON][Artifact::POSTFIX] = weaponPostfix;

}

QString ArtifactFabric::findBase(Artifact::ArtifactSlot slot, int lvl, QList<Artifact::Rarity> rarity)
{
    return findItem(slot, lvl, Artifact::BASE, rarity);
}

QString ArtifactFabric::findPrefix(Artifact::ArtifactSlot slot, int lvl, QList<Artifact::Rarity> rarity)
{
    return findItem(slot, lvl, Artifact::PREFIX, rarity);
}

QString ArtifactFabric::findPostfix(Artifact::ArtifactSlot slot, int lvl, QList<Artifact::Rarity> rarity)
{
    return findItem(slot, lvl, Artifact::POSTFIX, rarity);
}

QString ArtifactFabric::findItem(Artifact::ArtifactSlot slot, int lvl, Artifact::Type type, QList<Artifact::Rarity> rarity)
{
    QList<QString> result;
    foreach (const QString &s, items[slot][type])
        if (levels[s].check(lvl) && (rarity.contains(artRarity[s]) || rarity.isEmpty()))
            result.append(s);
    if (result.isEmpty())
        return "";
    return result[qrand()%result.count()];
}

Artifact *ArtifactFabric::getArtifact(QString name, int lvl, Character*c)
{
    if (name == "BadStick")
        return new BadStick(sf, c, lvl, currentId++);
    if (name == "WeaponPostfixDeath")
        return new WeaponPostfixDeath(sf, c, lvl, currentId++);
    return 0;
}

Artifact *ArtifactFabric::generateBase(int minLvl, int maxLvl, QList<Artifact::ArtifactSlot> slot, QList<Artifact::Rarity> rarity, Character *c)
{
    int lvl = qrand()%(maxLvl-minLvl) + minLvl;
    if (slot.isEmpty())
        slot << Artifact::WEAPON;
    int slotIndex = qrand()%slot.count();

    QString name = findBase(slot[slotIndex], lvl, rarity);
    return getArtifact(name, lvl, c);
}

Artifact *ArtifactFabric::generatePrefix(Artifact::ArtifactSlot slot, int lvl, Character *c)
{
    QString name = findPrefix(slot, lvl);
    return getArtifact(name, lvl, c);
}

Artifact *ArtifactFabric::generatePostfix(Artifact::ArtifactSlot slot, int lvl, Character *c)
{
    QString name = findPostfix(slot, lvl);
    return getArtifact(name, lvl,c);
}

Artifact *ArtifactFabric::generate(bool isSpecial, int minLvl, int maxLvl, Character *c)
{
    Artifact * base = generateBase(minLvl, maxLvl,
                                   QList<Artifact::ArtifactSlot>(),
                                   QList<Artifact::Rarity>() << Artifact::COMMON,c);
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
        return generateBase(minLvl, maxLvl, QList<Artifact::ArtifactSlot>(), QList<Artifact::Rarity>() << Artifact::LEGENDARY, c);
    }

    if (needPrefix)
    {
        Artifact *prefix = generatePrefix(base->getSlot(), base->getLvl(), c);
        base->setPrefix(prefix);
        base->setRarity(Artifact::UNCOMMON);
    }
    if (needPostfix)
    {
        Artifact *postfix = generatePostfix(base->getSlot(), base->getLvl(), c);
        base->setPostfix(postfix);
        base->setRarity(Artifact::RARE);
    }
    if (needPrefix && needPostfix)
        base->setRarity(Artifact::MYTHICAL);
    return base;
}
