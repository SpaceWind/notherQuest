#include "badstick.h"

BadStick::BadStick()
    : Artifact()
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    name = "BadStick";
    title = "Дряхлая палка";
}

BadStick::BadStick(SpellFactory *sf, Character *c, int lvl, int id)
    : Artifact(sf, c, lvl, id)
{
    slot = WEAPON;
    type = BASE;
    rarity = COMMON;
    price = 10 + 1*lvl;
    name = "BadStick";
    title = "Дряхлая палка";
}

void BadStick::init()
{
    if (prefix)     prefix->init();
    if (postfix)    postfix->init();
}

void BadStick::apply()
{
    owner->preparedInfo.damage += 1 + 0.25*lvl;
    if (prefix)     prefix->apply();
    if (postfix)    postfix->apply();
}
