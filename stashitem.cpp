#include "stashitem.h"

StashItem::StashItem()
{
    id = 0;
    price = 0;
    isQuest = false;
    isActive = false;
    destroed = false;
}

StashItem::StashItem(int id, QString name, QString title, double price, bool isQuest, bool isActive)
{
    this->id = id;
    this->name = name;
    this->title = title;
    this->price = price;
    this->isQuest = isQuest;
    this->isActive = isActive;
    this->destroed = false;
}
