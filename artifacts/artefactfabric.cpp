#include "artefactfabric.h"
#include "utils.h"

ArtefactFabric::ArtefactFabric(SpellFactory *sf)
{
    this->sf = sf;
    currentId = 1;
}

void ArtefactFabric::init()
{
    //QHash<QString, ArtifactLvl> levels;
    levels["BadStick"] = ArtifactLvl(0, 10);
    levels["Stick"] = ArtifactLvl(2, 10);
    levels["WoodenRog"] = ArtifactLvl(0, 14);
    levels["Bow"] = ArtifactLvl(4, 12);
    levels["Baton"] = ArtifactLvl(5, 14);
    levels["Dagger"] = ArtifactLvl(7, 18);
    levels["HuntersBow"] = ArtifactLvl(7, 15);
    levels["StoneSword"] = ArtifactLvl(8, 22);
    levels["Spear"] = ArtifactLvl(8, 25);
    levels["IronDagger"] = ArtifactLvl(10, 20);
    levels["IronSword"] = ArtifactLvl(14, 30);
    levels["EnforcedSpear"] = ArtifactLvl(16, 36);
    levels["StoneBaton"] = ArtifactLvl(15, 40);
    levels["Mace"] = ArtifactLvl(18, 42);
    levels["Lance"] = ArtifactLvl(14, 40);
    levels["LongBow"] = ArtifactLvl(16, 47);
    levels["LightRazor"] = ArtifactLvl(20, 45);
    levels["Scimitar"] = ArtifactLvl(22, 52);
    levels["HeavyMace"] = ArtifactLvl(26, 50);
    levels["Palica"] = ArtifactLvl(27, 57);
    levels["MetalHammer"] = ArtifactLvl(28, 55);
    levels["WarHammer"] = ArtifactLvl(30, 62);
    levels["SteelDirk"] = ArtifactLvl(35, 64);
    levels["SuperRazor"] = ArtifactLvl(33, 70);
    levels["Rapier"] = ArtifactLvl(35, 68);
    levels["Trident"] = ArtifactLvl(38, 72);
    levels["Ax"] = ArtifactLvl(40, 77);
    levels["Scythe"] = ArtifactLvl(45, 84);
    levels["Kris"] = ArtifactLvl(47, 90);
    levels["GreatSword"] = ArtifactLvl(52);
    levels["Falchion"] = ArtifactLvl(50);
    levels["Flamberg"] = ArtifactLvl(58);
    levels["Katana"] = ArtifactLvl(60);
    levels["Halberd"] = ArtifactLvl(65);
    levels["Crossbow"] = ArtifactLvl(75);
    levels["Cradle"] = ArtifactLvl(88);
    levels["Musket"] = ArtifactLvl(108);
    levels["Arquebus"] = ArtifactLvl(110);
    levels["Riffle"] = ArtifactLvl(140);
    levels["GrenadeGun"] = ArtifactLvl(180);
    levels["Flamethrower"] = ArtifactLvl(220);
    levels["Plasmgun"] = ArtifactLvl(270);
    levels["NuclearRiffle"] = ArtifactLvl(290);
    levels["Desintegrator"] = ArtifactLvl(340);
    levels["FSP"] = ArtifactLvl(360);
    levels["Warbow"] = ArtifactLvl(390);
    levels["HellTridal"] = ArtifactLvl(440);
    levels["HandOfGod"] = ArtifactLvl(500);
    levels["WeaponPostfixDeath"] = ArtifactLvl();

    //QHash<QString, Artifact::ArtifactSlot> artSlots;
    /*
     *     artSlots["BadStick"] = );
    artSlots["Stick"] = );
    artSlots["WoodenRog"] = );
    artSlots["Bow"] = );
    artSlots["Baton"] = );
    artSlots["Dagger"] = );
    artSlots["HuntersBow"] = );
    artSlots["StoneSword"] = );
    artSlots["Spear"] = );
    artSlots["IronDagger"] = );
    artSlots["IronSword"] = );
    artSlots["EnforcedSpear"] = );
    artSlots["StoneBaton"] = );
    artSlots["Mace"] = );
    artSlots["Lance"] = );
    artSlots["LongBow"] = );
    artSlots["LightRazor"] = );
    artSlots["Scimitar"] = );
    artSlots["HeavyMace"] = );
    artSlots["Palica"] = );
    artSlots["MetalHammer"] = );
    artSlots["WarHammer"] = );
    artSlots["SteelDirk"] = );
    artSlots["SuperRazor"] = );
    artSlots["Rapier"] = );
    artSlots["Trident"] = );
    artSlots["Ax"] = );
    artSlots["Scythe"] = );
    artSlots["Kris"] = );
    artSlots["GreatSword"] = );
    artSlots["Falchion"] = );
    artSlots["Flamberg"] = );
    artSlots["Katana"] = );
    artSlots["Halberd"] = );
    artSlots["Crossbow"] = );
    artSlots["Cradle"] = );
    artSlots["Musket"] = );
    artSlots["Arquebus"] = );
    artSlots["Riffle"] = );
    artSlots["GrenadeGun"] = );
    artSlots["Flamethrower"] = );
    artSlots["Plasmgun"] = );
    artSlots["NuclearRiffle"] = );
    artSlots["Desintegrator"] = );
    artSlots["FSP"] = );
    artSlots["Warbow"] = );
    artSlots["HellTridal"] = );
    artSlots["HandOfGod"] = );
     * */
    artSlots["BadStick"] = Artefact::WEAPON;
    artSlots["Stick"] = Artefact::WEAPON;
    artSlots["WoodenRog"] = Artefact::WEAPON;
    artSlots["Bow"] = Artefact::WEAPON;
    artSlots["Baton"] = Artefact::WEAPON;
    artSlots["Dagger"] = Artefact::WEAPON;
    artSlots["HuntersBow"] = Artefact::WEAPON;
    artSlots["StoneSword"] = Artefact::WEAPON;
    artSlots["Spear"] = Artefact::WEAPON;
    artSlots["IronDagger"] = Artefact::WEAPON;
    artSlots["IronSword"] = Artefact::WEAPON;
    artSlots["EnforcedSpear"] = Artefact::WEAPON;
    artSlots["StoneBaton"] = Artefact::WEAPON;
    artSlots["Mace"] = Artefact::WEAPON;
    artSlots["Lance"] = Artefact::WEAPON;
    artSlots["LongBow"] = Artefact::WEAPON;
    artSlots["LightRazor"] = Artefact::WEAPON;
    artSlots["Scimitar"] = Artefact::WEAPON;
    artSlots["HeavyMace"] = Artefact::WEAPON;
    artSlots["Palica"] = Artefact::WEAPON;
    artSlots["MetalHammer"] = Artefact::WEAPON;
    artSlots["WarHammer"] = Artefact::WEAPON;
    artSlots["SteelDirk"] = Artefact::WEAPON;
    artSlots["SuperRazor"] = Artefact::WEAPON;
    artSlots["Rapier"] = Artefact::WEAPON;
    artSlots["Trident"] = Artefact::WEAPON;
    artSlots["Ax"] = Artefact::WEAPON;
    artSlots["Scythe"] = Artefact::WEAPON;
    artSlots["Kris"] = Artefact::WEAPON;
    artSlots["GreatSword"] = Artefact::WEAPON;
    artSlots["Falchion"] = Artefact::WEAPON;
    artSlots["Flamberg"] = Artefact::WEAPON;
    artSlots["Katana"] = Artefact::WEAPON;
    artSlots["Halberd"] = Artefact::WEAPON;
    artSlots["Crossbow"] = Artefact::WEAPON;
    artSlots["Cradle"] = Artefact::WEAPON;
    artSlots["Musket"] = Artefact::WEAPON;
    artSlots["Arquebus"] = Artefact::WEAPON;
    artSlots["Riffle"] = Artefact::WEAPON;
    artSlots["GrenadeGun"] = Artefact::WEAPON;
    artSlots["Flamethrower"] = Artefact::WEAPON;
    artSlots["Plasmgun"] = Artefact::WEAPON;
    artSlots["NuclearRiffle"] = Artefact::WEAPON;
    artSlots["Desintegrator"] = Artefact::WEAPON;
    artSlots["FSP"] = Artefact::WEAPON;
    artSlots["Warbow"] = Artefact::WEAPON;
    artSlots["HellTridal"] = Artefact::WEAPON;
    artSlots["HandOfGod"] = Artefact::WEAPON;
    artSlots["WeaponPostfixDeath"] = Artefact::WEAPON;

    //QHash<QString, Artifact::Rarity> artRarity;
    artRarity["BadStick"] = Artefact::COMMON;
    artRarity["BadStick"] = Artefact::COMMON;
    artRarity["Stick"] = Artefact::COMMON;
    artRarity["WoodenRog"] = Artefact::COMMON;
    artRarity["Bow"] = Artefact::COMMON;
    artRarity["Baton"] = Artefact::COMMON;
    artRarity["Dagger"] = Artefact::COMMON;
    artRarity["HuntersBow"] = Artefact::COMMON;
    artRarity["StoneSword"] = Artefact::COMMON;
    artRarity["Spear"] = Artefact::COMMON;
    artRarity["IronDagger"] = Artefact::COMMON;
    artRarity["IronSword"] = Artefact::COMMON;
    artRarity["EnforcedSpear"] = Artefact::COMMON;
    artRarity["StoneBaton"] = Artefact::COMMON;
    artRarity["Mace"] = Artefact::COMMON;
    artRarity["Lance"] = Artefact::COMMON;
    artRarity["LongBow"] = Artefact::COMMON;
    artRarity["LightRazor"] = Artefact::COMMON;
    artRarity["Scimitar"] = Artefact::COMMON;
    artRarity["HeavyMace"] = Artefact::COMMON;
    artRarity["Palica"] = Artefact::COMMON;
    artRarity["MetalHammer"] = Artefact::COMMON;
    artRarity["WarHammer"] = Artefact::COMMON;
    artRarity["SteelDirk"] = Artefact::COMMON;
    artRarity["SuperRazor"] = Artefact::COMMON;
    artRarity["Rapier"] = Artefact::COMMON;
    artRarity["Trident"] = Artefact::COMMON;
    artRarity["Ax"] = Artefact::COMMON;
    artRarity["Scythe"] = Artefact::COMMON;
    artRarity["Kris"] = Artefact::COMMON;
    artRarity["GreatSword"] = Artefact::COMMON;
    artRarity["Falchion"] = Artefact::COMMON;
    artRarity["Flamberg"] = Artefact::COMMON;
    artRarity["Katana"] = Artefact::COMMON;
    artRarity["Halberd"] = Artefact::COMMON;
    artRarity["Crossbow"] = Artefact::COMMON;
    artRarity["Cradle"] = Artefact::COMMON;
    artRarity["Musket"] = Artefact::COMMON;
    artRarity["Arquebus"] = Artefact::COMMON;
    artRarity["Riffle"] = Artefact::COMMON;
    artRarity["GrenadeGun"] = Artefact::COMMON;
    artRarity["Flamethrower"] = Artefact::COMMON;
    artRarity["Plasmgun"] = Artefact::COMMON;
    artRarity["NuclearRiffle"] = Artefact::COMMON;
    artRarity["Desintegrator"] = Artefact::COMMON;
    artRarity["FSP"] = Artefact::COMMON;
    artRarity["Warbow"] = Artefact::COMMON;
    artRarity["HellTridal"] = Artefact::COMMON;
    artRarity["HandOfGod"] = Artefact::COMMON;
    artRarity["WeaponPostfixDeath"] = Artefact::RARE;

    //QHash<Artifact::ArtifactSlot, QHash<Artifact::Type, QList<QString> > > items;
    QList<QString> weaponBase;
    weaponBase << "BadStick" << "Stick" << "WoodenRog" << "Bow" << "Baton" << "Dagger" << "HunterBow" << "StoneSword" << "Spear" <<
                  "IronDagger" << "IronSword" << "EnforcedSpear" << "StoneBaton" << "Mace" << "Lance" << "LongBow" << "LightRazor" <<
                  "Scimitar" << "HeavyMace" << "Palica" << "MetalHammer" << "WarHammer" << "SteelDirk" << "SuperRazor" << "Rapier" <<
                  "Trident" << "Ax" << "Scythe" << "Kris" << "GreatSword" << "Falchion" << "Flamberg" << "Katana" << "Halberd" <<
                  "Crossbow" << "Cradle" << "Musket" << "Arquebus" << "Riffle" << "GrenadeGun" << "Flamethrower" << "Plasmgun" <<
                  "NuclearRiffle" << "Desintegrator" << "FSP" << "Warbow" << "HellTridal" << "HandOfGod";
    QList<QString> weaponPostfix;
    weaponPostfix << "WeaponPostfixDeath";

    items[Artefact::WEAPON][Artefact::BASE] = weaponBase;
    items[Artefact::WEAPON][Artefact::POSTFIX] = weaponPostfix;
}

QString ArtefactFabric::findBase(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity)
{
    return findItem(slot, lvl, Artefact::BASE, rarity);
}

QString ArtefactFabric::findPrefix(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity)
{
    return findItem(slot, lvl, Artefact::PREFIX, rarity);
}

QString ArtefactFabric::findPostfix(Artefact::ArtefactSlot slot, int lvl, QList<Artefact::Rarity> rarity)
{
    return findItem(slot, lvl, Artefact::POSTFIX, rarity);
}

QString ArtefactFabric::findItem(Artefact::ArtefactSlot slot, int lvl, Artefact::Type type, QList<Artefact::Rarity> rarity)
{
    QList<QString> result;
    foreach (const QString &s, items[slot][type])
        if (levels[s].check(lvl) && (rarity.contains(artRarity[s]) || rarity.isEmpty()))
            result.append(s);
    if (result.isEmpty())
        return "";
    return result[qrand()%result.count()];
}

Artefact *ArtefactFabric::getArtifact(QString name, int lvl, Character*c)
{
    if (name == "BadStick")
        return new BadStick(sf, c, lvl, currentId++);
    if (name == "WeaponPostfixDeath")
        return new WeaponPostfixDeath(sf, c, lvl, currentId++);
    return 0;
}

Artefact *ArtefactFabric::generateBase(int minLvl, int maxLvl, QList<Artefact::ArtefactSlot> slot, QList<Artefact::Rarity> rarity, Character *c)
{
    int lvl = qrand()%(maxLvl-minLvl) + minLvl;
    if (slot.isEmpty())
        slot << Artefact::WEAPON;
    int slotIndex = qrand()%slot.count();

    QString name = findBase(slot[slotIndex], lvl, rarity);
    return getArtifact(name, lvl, c);
}

Artefact *ArtefactFabric::generatePrefix(Artefact::ArtefactSlot slot, int lvl, Character *c)
{
    QString name = findPrefix(slot, lvl);
    return getArtifact(name, lvl, c);
}

Artefact *ArtefactFabric::generatePostfix(Artefact::ArtefactSlot slot, int lvl, Character *c)
{
    QString name = findPostfix(slot, lvl);
    return getArtifact(name, lvl,c);
}

Artefact *ArtefactFabric::generate(bool isSpecial, int minLvl, int maxLvl, Character *c)
{
    Artefact * base = generateBase(minLvl, maxLvl,
                                   QList<Artefact::ArtefactSlot>(),
                                   QList<Artefact::Rarity>() << Artefact::COMMON,c);
    if (!isSpecial)
        return base;

    bool needPrefix = false, needPostfix = false, uniqueInstead = false;
    if (SM::procChance(0.7))
        needPrefix = true;
    else
        needPostfix = true;

    if (needPrefix && SM::procChance(0.07))
        needPostfix = true;
    else if (needPostfix && SM::procChance(0.3))
        needPostfix = true;

    if (needPrefix && needPostfix && SM::procChance(0.1))
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

