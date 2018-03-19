#ifndef GLOBALINFO_H
#define GLOBALINFO_H
#include <QList>
#include <QObject>
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
    int nodeId;
    double nodePosition;
};

#endif // GLOBALINFO_H
