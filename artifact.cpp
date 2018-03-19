#include "artifact.h"

Artifact::Artifact()
{
    owner = 0;
    lvl = 0;
    price = 0;
    isValid = false;
    id = 0;
    prefix = postfix = 0;
}

Artifact::Artifact(Character *c, int lvl, int id)
{
    owner = c;
    this->lvl = lvl;
    price = 0;
    isValid = true;
    this->id = id;
    prefix = postfix = 0;
}
