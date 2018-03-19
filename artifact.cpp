#include "artifact.h"

Artifact::Artifact()
{
    owner = 0;
    lvl = 0;
    price = 0;
    isValid = false;
    id = 0;
    prefix = postfix = 0;
    sf = 0;
}

Artifact::Artifact(SpellFactory *sf, Character *c, int lvl, int id)
{
    owner = c;
    this->lvl = lvl;
    price = 0;
    isValid = true;
    this->id = id;
    prefix = postfix = 0;
    this->sf = sf;
}

double Artifact::getPrice()
{
    double result = price;
    if (prefix)
        result += prefix->price;
    if (postfix)
        result += postfix->price;
    switch (rarity)
    {
    case UNCOMMON:
        result *=1.25; break;
    case RARE:
        result *=2.0; break;
    case MYTHICAL:
        result *= 3.5; break;
    case LEGENDARY:
        result *= 4.5; break;
    default: break;
    }
    return result;
}
