#include "magic.h"

Magic::Spell::Spell()
{
    Spell("", "", -1, 0, -1);
}

Magic::Spell::Spell(const QString &name, const QString &title, int id, Character *owner, int lvl)
{
    this->name = name;
    this->title = title;
    this->id = id;
    this->owner = owner;
    this->lvl = lvl;
    this->currentCD = 0;
    this->cd = 0;
    this->selfCast = false;
    this->health = 0;
}

double Magic::Spell::step(int time)
{
    currentCD -= double(time)/5.0;
    if (currentCD < 0.0)
        currentCD = 0.0;
    if (health > 0)
        health -= double(time)/5.0;
    if (health < 0)
        health = 0;
    return currentCD;
}

Magic::Nuke::Nuke(Character *owner, int lvl)
    : Spell("", "", 0, owner, lvl)
{

}

Magic::Buff::Buff(Character *owner, int lvl)
    : Spell("", "", 0, owner, lvl)
{

}

Magic::Launcher::Result Magic::Launcher::Result::emptyResult()
{
    Result result;
    result.isActive = false;
    return result;
}

Magic::Augmentation::Augmentation(Character *owner, int lvl)
    : Spell("", "", 0, owner, lvl)
{

}

Magic::Complex::Complex(Character *owner, int lvl)
    : Spell("", "", 0, owner, lvl)
{

}

void Magic::Complex::addSpell(int spellId)
{
    spells.append(spellId);
}
