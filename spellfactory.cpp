#include "spellfactory.h"
#include <QDebug>

SpellFactory::SpellFactory()
{
    types["CutStrike"] = SPELL_TYPE_NUKE;
    types["HybridStrike"] = SPELL_TYPE_NUKE;
    types["Atomization"] = SPELL_TYPE_NUKE;
    types["WitsEnd"] = SPELL_TYPE_COMPLEX;
    types["WitsEndNuke"] = SPELL_TYPE_NUKE;
    types["WitsEndDebuff"] = SPELL_TYPE_BUFF;
    currentID = 10;
}

int SpellFactory::createSpell(QString name, Character *c, int lvl)
{
    if (name == "CutStrike")
        return bindSpell(new CutStrike(c, lvl));
    if (name == "HybridStrike")
        return bindSpell(new HybridStrike(c, lvl));
    if (name == "Atomization")
        return bindSpell(new Atomization(c, lvl));
    if (name == "WitsEnd")
    {
        auto s = new WitsEnd(c, lvl);
        int id = bindSpell(s);

        foreach (const QString &sp, s->prepare())
            s->addSpell(createSpell(sp, c, lvl));
        return id;
    }
    if (name == "WitsEndNuke")
        return bindSpell(new WitsEndNuke(c, lvl));
    if (name == "WitsEndDebuff")
        return bindSpell(new WitsEndDebuff(c, lvl));

    return 0;
}

int SpellFactory::generic(int spellId)
{
    if (spells.contains(spellId))
    {
        auto s = spells[spellId];
        return createSpell(s->name, s->owner, s->lvl);
    }
    return 0;
}

QString SpellFactory::getTypeByName(QString name)
{
    if (types.contains(name))
        return types[name];
    return QString();
}

QString SpellFactory::getTypeById(int id)
{
    QString name = getName(id);
    if (!name.isEmpty())
        return getTypeByName(name);
    return QString();
}

QString SpellFactory::getName(int id)
{
    if (names.contains(id))
        return names[id];
    return QString();
}

int SpellFactory::findSpell(QString name, int owner)
{
    foreach (const int &id, spells.keys())
        if (spells[id]->owner->id == owner && spells[id]->name == name)
            return id;
    return 0;
}

Magic::Nuke* SpellFactory::getNuke(int id)
{
    Magic::Nuke * result = 0;

    if (names.contains(id) && types.contains(names[id]) &&
        spells.contains(id) && types[names[id]] == SPELL_TYPE_NUKE)
    {
        result = dynamic_cast<Magic::Nuke*>(spells[id]);
    }
    return result;
}

Magic::Buff *SpellFactory::getBuff(int id)
{
    Magic::Buff * result = 0;

    if (names.contains(id) && types.contains(names[id]) &&
        spells.contains(id) && types[names[id]] == SPELL_TYPE_BUFF)
    {
        result = dynamic_cast<Magic::Buff*>(spells[id]);
    }
    return result;
}

Magic::Launcher *SpellFactory::getLauncher(int id)
{
    Magic::Launcher * result = 0;

    if (names.contains(id) && types.contains(names[id]) &&
        spells.contains(id) && types[names[id]] == SPELL_TYPE_LAUNCHER)
    {
        result = dynamic_cast<Magic::Launcher*>(spells[id]);
    }
    return result;
}

Magic::Augmentation *SpellFactory::getAugmentation(int id)
{
    Magic::Augmentation * result = 0;

    if (names.contains(id) && types.contains(names[id]) &&
        spells.contains(id) && types[names[id]] == SPELL_TYPE_AUGMENTATION)
    {
        result = dynamic_cast<Magic::Augmentation*>(spells[id]);
    }
    return result;
}

Magic::Complex *SpellFactory::getComplex(int id)
{
    Magic::Complex * result = 0;

    if (names.contains(id) && types.contains(names[id]) &&
        spells.contains(id) && types[names[id]] == SPELL_TYPE_COMPLEX)
    {
        result = dynamic_cast<Magic::Complex*>(spells[id]);
    }
    return result;
}

void SpellFactory::removeSpell(int id)
{
    if (names.contains(id))
        names.remove(id);
    if (spells.contains(id))
    {
        Magic::Spell *s = spells[id];
        spells.remove(id);
        delete s;
    }
}

double SpellFactory::update(int id, double time)
{
    if (spells.contains(id))
        return spells[id]->step(time);
    return 0;
}

void SpellFactory::resetCD(int id)
{
    spells[id]->currentCD = spells[id]->cd;
}

void SpellFactory::makeReady(int id)
{
    spells[id]->currentCD = 0;
}

bool SpellFactory::isReady(int id)
{
    if (spells.contains(id))
        return spells[id]->isReady();
    return false;
}

bool SpellFactory::isActive(int id)
{
    if  (spells.contains(id) && types.contains(spells[id]->name))
    {
        QString type = types[spells[id]->name];
        if (type == SPELL_TYPE_BUFF)
        {
            Buff * b = dynamic_cast<Buff*>(spells[id]);
            return b->isActive();
        }
        else if (type == SPELL_TYPE_LAUNCHER)
        {
            Launcher *l = dynamic_cast<Launcher*>(spells[id]);
            return l->isActive();
        }
    }
    return false;
}

int SpellFactory::bindSpell(Spell *s)
{
    int id = currentID++;
    s->id = id;
    names[id] = s->name;
    spells[id] = s;
    return id;
}
