#ifndef STASHITEM_H
#define STASHITEM_H
#include "stats.h"

struct StashItem
{
    StashItem();
    StashItem(int id, QString name, QString title, double price, bool isQuest, bool isActive);
    virtual ~StashItem() { }

    QString name, title;
    int id;
    double price;
    bool isQuest;
    bool isActive;
    bool destroed;
    Character * owner;

    virtual void activate(Character *receiver = 0) { destroed = true; }
};

#endif // STASHITEM_H
