#include "base.h"

BadStick::BadStick()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "BadStick";
    title = "Дряхлая палка";
}

BadStick::BadStick(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 10 + 1*lvl;
    name = "BadStick";
    title = "Дряхлая палка";
}

void BadStick::apply()
{
    owner->preparedInfo.damage += 1 + 0.25*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------

Stick::Stick()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Stick";
    title = "Палка";
}

Stick::Stick(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 15 + 1*lvl;
    name = "Stick";
    title = "Палка";
}

void Stick::apply()
{
    owner->preparedInfo.damage += 2 + 0.25*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//----------------------------------------------------------------------------
WoodenRog::WoodenRog()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "WoodenRog";
    title = "Рогатка из прутьев";
}

WoodenRog::WoodenRog(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 18 + 0.8*lvl;
    name = "WoodenRog";
    title = "Рогатка из прутьев";
}

void WoodenRog::apply()
{
    owner->preparedInfo.damage += 2.5 + 0.15*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//-----------------------------------------------------------------------------

Bow::Bow()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Bow";
    title = "Лук";
}

Bow::Bow(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 30 + 1.5*lvl;
    name = "Bow";
    title = "Лук";
}

void Bow::apply()
{
    owner->preparedInfo.damage += 4.0 + 0.1*lvl;
    owner->preparedInfo.crc += 2.0 + 0.4*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//-----------------------------------------------------------------------------
Baton::Baton()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Baton";
    title = "Дубинка";
}

Baton::Baton(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 36 + 2*lvl;
    name = "Baton";
    title = "Дубинка";
}

void Baton::apply()
{
    owner->preparedInfo.damage += 3 + 0.3*lvl;
    owner->preparedInfo.crd += 5 + 0.8*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//-----------------------------------------------------------------------------
Dagger::Dagger()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Dagger";
    title = "Кинжал";
}

Dagger::Dagger(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 30 + 2.5*lvl;
    name = "Dagger";
    title = "Кинжал";
}

void Dagger::apply()
{
    owner->preparedInfo.damage += 1 + 0.25*lvl;
    owner->preparedInfo.crc += 9 + 0.3*lvl;
    owner->preparedInfo.crd += 4 + 0.2*lvl;
    owner->preparedInfo.as += 20;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
HuntersBow::HuntersBow()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "HuntersBow";
    title = "Охотничий лук";
}

HuntersBow::HuntersBow(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 35 + 2.5*lvl;
    name = "HuntersBow";
    title = "Охотничий лук";
}

void HuntersBow::apply()
{
    owner->preparedInfo.damage += 4 + 0.2*lvl;
    owner->preparedInfo.crc += 4 + 0.4*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
StoneSword::StoneSword()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "StoneSword";
    title = "Каменный меч";
}

StoneSword::StoneSword(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 30 + 3*lvl;
    name = "StoneSword";
    title = "Каменный меч";
}

void StoneSword::apply()
{
    owner->preparedInfo.damage += 6 + 0.2*lvl;
    owner->preparedInfo.crc += 2 + 0.2*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Spear::Spear()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Spear";
    title = "Копьё";
}

Spear::Spear(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 45 + 3.0*lvl;
    name = "Spear";
    title = "Копьё";
}

void Spear::apply()
{
    owner->preparedInfo.damage += 8 + 0.3*lvl;
    owner->preparedInfo.crd += 5 + 0.5*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
IronDagger::IronDagger()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "IronDagger";
    title = "Железный кинжал";
}

IronDagger::IronDagger(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 60 + 3*lvl;
    name = "IronDagger";
    title = "Железный кинжал";
}

void IronDagger::apply()
{
    owner->preparedInfo.damage += 3 + 0.5*lvl;
    owner->preparedInfo.crc += 9 + 0.3*lvl;
    owner->preparedInfo.crd += 4 + 0.2*lvl;
    owner->preparedInfo.as += 30;

    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
IronSword::IronSword()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "IronSword";
    title = "Железный меч";
}

IronSword::IronSword(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 40 + 3.5*lvl;
    name = "IronSword";
    title = "Железный меч";
}

void IronSword::apply()
{
    owner->preparedInfo.damage += 5 + 0.3*lvl;
    owner->preparedInfo.crc += 2 + 0.2*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
EnforcedRazor::EnforcedRazor()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "EnforcedSpear";
    title = "Усиленное копьё";
}

EnforcedRazor::EnforcedRazor(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 80 + 3.5*lvl;
    name = "EnforcedSpear";
    title = "Усиленное копьё";
}

void EnforcedRazor::apply()
{
    owner->preparedInfo.damage += 16 + 0.7*lvl;
    owner->preparedInfo.crd += 10 + 0.5*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
StoneBaton::StoneBaton()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "StoneBaton";
    title = "Каменный батон";
}

StoneBaton::StoneBaton(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 95 + 4.0*lvl;
    name = "StoneBaton";
    title = "Каменный батон";
}

void StoneBaton::apply()
{
    owner->preparedInfo.damage += 25 + 0.6*lvl;
    owner->preparedInfo.crd += 10 + 0.4*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Mace::Mace()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Mace";
    title = "Булава";
}

Mace::Mace(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 100 + 4.5*lvl;
    name = "Mace";
    title = "Булава";
}

void Mace::apply()
{
    owner->preparedInfo.damage += 15 + 0.5*lvl;
    owner->preparedInfo.crc += 25 + 0.1*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Lance::Lance()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Lance";
    title = "Пика";
}

Lance::Lance(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 90 + 5.0*lvl;
    name = "Lance";
    title = "ПИка";
}

void Lance::apply()
{
    owner->preparedInfo.damage += 35 + 0.6*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
LongBow::LongBow()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "LongBow";
    title = "Длинный лук";
}

LongBow::LongBow(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 120 + 6.0*lvl;
    name = "LongBow";
    title = "Длинный лук";
}

void LongBow::apply()
{
    owner->preparedInfo.damage += 18 + 0.7*lvl;
    owner->preparedInfo.crc += 8 + 0.4*lvl;
    owner->preparedInfo.crd += 12 + 0.1*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
LightRazor::LightRazor()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "LightRazor";
    title = "Лёгкое лезвие";
}

LightRazor::LightRazor(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 120 + 6.0*lvl;
    name = "LightRazor";
    title = "Лёгкое лезвие";
}

void LightRazor::apply()
{
    owner->preparedInfo.damage += 8 + 0.6*lvl;
    owner->preparedInfo.crc += 16 + 0.4*lvl;
    owner->preparedInfo.crd += 8 + 0.4*lvl;
    owner->preparedInfo.as += 40;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Scimitar::Scimitar()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Scimitar";
    title = "Ятаган";
}

Scimitar::Scimitar(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 105 + 6.5*lvl;
    name = "Scimitar";
    title = "Ятаган";
}

void Scimitar::apply()
{
    owner->preparedInfo.damage += 12 + 0.9*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
HeavyMace::HeavyMace()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "HeavyMace";
    title = "Тяжелая булава";
}

HeavyMace::HeavyMace(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 135 + 6.0*lvl;
    name = "HeavyMace";
    title = "Тяжелая булава";
}

void HeavyMace::apply()
{
    owner->preparedInfo.damage += 28 + 0.8*lvl;
    owner->preparedInfo.crc += 4 + 0.2*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Palica::Palica()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Palica";
    title = "Палица";
}

Palica::Palica(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 160 + 6.5*lvl;
    name = "Palica";
    title = "Палица";
}

void Palica::apply()
{
    owner->preparedInfo.damage += 16 + 0.8*lvl;
    owner->preparedInfo.crd += 10 + 0.6*lvl;
    owner->preparedInfo.as -= 10;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
MetalHammer::MetalHammer()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "MetalHammer";
    title = "Железный молот";
}

MetalHammer::MetalHammer(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 150 + 7.5*lvl;
    name = "MetalHammer";
    title = "Железный молот";
}

void MetalHammer::apply()
{
    owner->preparedInfo.damage += 5 + 0.9*lvl;
    owner->preparedInfo.crd += 40 + 0.1*lvl;
    owner->preparedInfo.as -= 30;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
WarHammer::WarHammer()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "WarHammer";
    title = "Боевой молот";
}

WarHammer::WarHammer(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 170 + 7.0*lvl;
    name = "WarHammer";
    title = "Боевой молот";
}

void WarHammer::apply()
{
    owner->preparedInfo.damage += 20 + 0.95*lvl;
    owner->preparedInfo.crd += 20 + 0.2*lvl;
    owner->preparedInfo.as -= 20;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
SteelDirk::SteelDirk()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "SteelDirk";
    title = "Стальной кортик";
}

SteelDirk::SteelDirk(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 190 + 7.5*lvl;
    name = "SteelDirk";
    title = "Стальной кортик";
}

void SteelDirk::apply()
{
    owner->preparedInfo.damage += 10 + 0.65*lvl;
    owner->preparedInfo.crc += 16 + 0.6*lvl;
    owner->preparedInfo.as += 40;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
SuperRazor::SuperRazor()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "EnforcedSpear";
    title = "Супер бритва";
}

SuperRazor::SuperRazor(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 210 + 8.0*lvl;
    name = "EnforcedSpear";
    title = "Супер бритва";
}

void SuperRazor::apply()
{
    owner->preparedInfo.damage += 8 + 0.75*lvl;
    owner->preparedInfo.crc += 10 + 0.4*lvl;
    owner->preparedInfo.crd += 10 + 0.4*lvl;
    owner->preparedInfo.as += 20;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Rapier::Rapier()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Rapier";
    title = "Рапира";
}

Rapier::Rapier(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 275 + 7.5*lvl;
    name = "Rapier";
    title = "Рапира";
}

void Rapier::apply()
{
    owner->preparedInfo.damage += 16 + 0.8*lvl;
    owner->preparedInfo.crd += 30 + 0.4*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Trident::Trident()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Trident";
    title = "Трезубец";
}

Trident::Trident(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 180 + 8.0*lvl;
    name = "Trident";
    title = "Трезубец";
}

void Trident::apply()
{
    owner->preparedInfo.damage += 35 + 1.0*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Ax::Ax()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Ax";
    title = "Секира";
}

Ax::Ax(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 260 + 8.0*lvl;
    name = "Ax";
    title = "Секира";
}

void Ax::apply()
{
    owner->preparedInfo.damage += 20 + 1.0*lvl;
    owner->preparedInfo.crd += 20 + 0.5*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Scythe::Scythe()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Scythe";
    title = "Коса";
}

Scythe::Scythe(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 280 + 8.5*lvl;
    name = "Scythe";
    title = "Коса";
}

void Scythe::apply()
{
    owner->preparedInfo.damage += 10 + 0.75*lvl;
    owner->preparedInfo.crc += 8 + 0.6*lvl;
    owner->preparedInfo.crd += 10 + 0.8*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Kris::Kris()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Kris";
    title = "Крис";
}

Kris::Kris(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 330 + 9.0*lvl;
    name = "Kris";
    title = "Крис";
}

void Kris::apply()
{
    owner->preparedInfo.damage += 32 + 0.65*lvl;
    owner->preparedInfo.crc += 32 + 0.4*lvl;
    owner->preparedInfo.as += 60;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
GreatSword::GreatSword()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "GreatSword";
    title = "Двуручный меч";
}

GreatSword::GreatSword(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 290 + 10*lvl;
    name = "GreatSword";
    title = "Двуручный меч";
}

void GreatSword::apply()
{
    owner->preparedInfo.damage += 35 + 1.2*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Falchion::Falchion()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Falchion";
    title = "Фальшион";
}

Falchion::Falchion(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 330 + 9.5*lvl;
    name = "Falchion";
    title = "Фальшион";
}

void Falchion::apply()
{
    owner->preparedInfo.damage += 10 + 1.0*lvl;
    owner->preparedInfo.crc += 10 + 0.4*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Flamberg::Flamberg()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Flamberg";
    title = "Фламберг";
}

Flamberg::Flamberg(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 430 + 11*lvl;
    name = "Flamberg";
    title = "Фламберг";
}

void Flamberg::apply()
{
    owner->preparedInfo.damage += 10 + 1.3*lvl;
    owner->preparedInfo.crc += 10 + 0.6*lvl;
    owner->preparedInfo.crd += 40 + 0.5*lvl;
    owner->preparedInfo.as -= 40;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Katana::Katana()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Katana";
    title = "Катана";
}

Katana::Katana(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 420 + 12*lvl;
    name = "Katana";
    title = "Катана";
}

void Katana::apply()
{
    owner->preparedInfo.damage += 40 + 1.4*lvl;
    owner->preparedInfo.crc += 20 + 0.6*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Halberd::Halberd()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Halberd";
    title = "Алебарда";
}

Halberd::Halberd(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 360 + 11*lvl;
    name = "Halberd";
    title = "Алебарда";
}

void Halberd::apply()
{
    owner->preparedInfo.damage += 20 + 1.5*lvl;
    owner->preparedInfo.as -= 40;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Crossbow::Crossbow()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Crossbow";
    title = "Арбалет";
}

Crossbow::Crossbow(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 480 + 12.5*lvl;
    name = "Crossbow";
    title = "Арбалет";
}

void Crossbow::apply()
{
    owner->preparedInfo.damage += 20 + 1.6*lvl;
    owner->preparedInfo.crd += 20 + 0.4*lvl;
    owner->preparedInfo.as -= 60;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Cradle::Cradle()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Cradle";
    title = "Ручница";
}

Cradle::Cradle(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 450 + 13*lvl;
    name = "Cradle";
    title = "Ручница";
}

void Cradle::apply()
{
    owner->preparedInfo.damage += 45 + 1.7*lvl;
    owner->preparedInfo.crc += 10 + 0.5*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Musket::Musket()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Musket";
    title = "Мушкет";
}

Musket::Musket(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 600 + 12*lvl;
    name = "Musket";
    title = "Мушкет";
}

void Musket::apply()
{
    owner->preparedInfo.damage += 40 + 1.8*lvl;
    owner->preparedInfo.crc += 10 + 0.5*lvl;
    owner->preparedInfo.crd += 10 + 0.6*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Arquebus::Arquebus()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Arquebus";
    title = "Аркебуза";
}

Arquebus::Arquebus(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 550 + 14*lvl;
    name = "Arquebus";
    title = "Аркебуза";
}

void Arquebus::apply()
{
    owner->preparedInfo.damage += 30 + 1.9*lvl;
    owner->preparedInfo.crd += 50 + 0.7 * lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Riffle::Riffle()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Riffle";
    title = "Калаш";
}

Riffle::Riffle(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 620 + 14.5*lvl;
    name = "Riffle";
    title = "Калаш";
}

void Riffle::apply()
{
    owner->preparedInfo.damage += 20 + 2.0*lvl;
    owner->preparedInfo.crc += 10 + 0.2*lvl;
    owner->preparedInfo.crd += 40 + 0.8*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
GrenadeGun::GrenadeGun()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "GrenadeGun";
    title = "Гранатомёт";
}

GrenadeGun::GrenadeGun(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 750 + 14*lvl;
    name = "GrenadeGun";
    title = "Гранатомёт";
}

void GrenadeGun::apply()
{
    owner->preparedInfo.damage += 60 + 2.1*lvl;
    owner->preparedInfo.crd += 50 + 0.7*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Flamethrower::Flamethrower()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Flamethrower";
    title = "Огнемет";
}

Flamethrower::Flamethrower(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 670 + 15*lvl;
    name = "Flamethrower";
    title = "Огнемет";
}

void Flamethrower::apply()
{
    owner->preparedInfo.damage += 10 + 2.1*lvl;
    owner->preparedInfo.crc += 30 + 0.5*lvl;
    owner->preparedInfo.as += 100;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Plasmgun::Plasmgun()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Plasmgun";
    title = "Плазмоган";
}

Plasmgun::Plasmgun(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 550 + 16*lvl;
    name = "Plasmgun";
    title = "Плазмоган";
}

void Plasmgun::apply()
{
    owner->preparedInfo.damage += 60 + 2.8*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
NuclearRiffle::NuclearRiffle()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "NuclearRiffle";
    title = "Ядерное ружьё";
}

NuclearRiffle::NuclearRiffle(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 850 + 15*lvl;
    name = "NuclearRiffle";
    title = "Ядерное ружьё";
}

void NuclearRiffle::apply()
{
    owner->preparedInfo.damage += 40 + 3.0*lvl;
    owner->preparedInfo.crc += 20 + 0.4*lvl;
    owner->preparedInfo.crd += 30 + 0.7*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Desintegrator::Desintegrator()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Desintegrator";
    title = "Дезинтегратор";
}

Desintegrator::Desintegrator(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 700 + 20*lvl;
    name = "Desintegrator";
    title = "Дезинтегратор";
}

void Desintegrator::apply()
{
    owner->preparedInfo.damage += 30 + 2.8*lvl;
    owner->preparedInfo.crd += 70 + 1.2*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
FSP::FSP()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "FSP";
    title = "FSP";
}

FSP::FSP(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 800 + 21*lvl;
    name = "FSP";
    title = "FSP";
}

void FSP::apply()
{
    owner->preparedInfo.damage += 80 + 2.8*lvl;
    owner->preparedInfo.crc += 40 + 0.4*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
Warbow::Warbow()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "Warbow";
    title = "Лук войны";
}

Warbow::Warbow(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 900 + 24*lvl;
    name = "Warbow";
    title = "Лук войны";
}

void Warbow::apply()
{
    owner->preparedInfo.damage += 10 + 2.0*lvl;
    owner->preparedInfo.crc += 100 + 1.0*lvl;
    owner->preparedInfo.crd += 10 + 0.2*lvl;
    owner->preparedInfo.as += 100;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
HellTridal::HellTridal()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "HellTridal";
    title = "Адовый трезубец";
}

HellTridal::HellTridal(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 270 + 33*lvl;
    name = "HellTridal";
    title = "Адовый трезубец";
}

void HellTridal::apply()
{
    owner->preparedInfo.damage += 6 + 3.6*lvl;
    owner->preparedInfo.crc += 50 + 0.4*lvl;
    owner->preparedInfo.crd += 66 + 0.66*lvl;
    owner->preparedInfo.as += 66;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
HandOfGod::HandOfGod()
    : Artefact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "HandOfGod";
    title = "Рука бога";
}

HandOfGod::HandOfGod(SpellFactory *sf, Character *c, int lvl, int id)
    : Artefact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 770 + 44*lvl;
    name = "HandOfGod";
    title = "Рука Бога";
}

void HandOfGod::apply()
{
    owner->preparedInfo.damage += 7 + 4.4*lvl;
    owner->preparedInfo.crd += 77 + 0.77*lvl;
    owner->preparedInfo.as += 177;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
//---------------------------------------------------------------------------
