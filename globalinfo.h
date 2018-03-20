#ifndef GLOBALINFO_H
#define GLOBALINFO_H
#include <QList>
#include <QObject>
#include <QHash>
#include "stashitem.h"

class GlobalInfo : public QObject
{
    Q_OBJECT
public:
    GlobalInfo(QObject *parent);

    QList<StashItem> stashItems;
    int gold;
    int currentQuest;
    int currentCharacter;
    double exp;
    double expToLvlUp;
    QHash<int, double> spellsExp;
};

#endif // GLOBALINFO_H
