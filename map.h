#ifndef MAP_H
#define MAP_H
#include <QString>
#include <QVector>
#include <QHash>
#include <QPoint>
#include <QDataStream>

class Region
{
public:
    struct mapEntry {
        enum RoadType {ROAD, CITY, DUNGEON, FIELD, NONROAD};
        enum BuildingType {NONBUILDING, ITEM_TRADER, ARTEFACT_TRADER, BORDEL, CHURCH, GUILD, CEMETERY, TAVERN,
                          TPT_WEST, TPT_NORTH, TPT_EAST, TPT_SOUTH,
                          TPF_WEST, TPF_NORTH, TPF_EAST, TPF_SOUTH, SPAWN};
        static mapEntry loadFromDS(QDataStream &ds);
        void saveToDS(QDataStream &ds);
        double roadCoef, value;
        int left, top, length;
        RoadType roadType;
        BuildingType buildingType;
    };

    void loadFromImage(QString filename);
    void loadFromData(QString filename);
    void saveToData(QString filename);
    void calculateValues(int left, int top, int value = 0);
    QVector<QPoint> findWay(int startLeft, int startTop, int endLeft, int endTop);
    QVector<QPoint> findRoad(Region::mapEntry::RoadType type);
    QVector<QPoint> findRoad(Region::mapEntry::RoadType type, int sLeft, int sTop, int range);
    QVector<QPoint> findBuilding(Region::mapEntry::BuildingType type);
    QVector<QPoint> findBuilding(Region::mapEntry::BuildingType type, int sLeft, int sTop, int range);

    QVector<QPoint> filterByRange(QVector<QPoint> &items, int sLeft, int sTop, int range);

    static int indexV(int left, int top, int width);

    mapEntry * entries;
    QString name, west, north, east, south;
    QString title;
    int width, height;

    static const int S_MAGIC = 0xAEAEAE16;
};

struct RegionLocation
{
    QString name, regionName;
    QString title;
    int left, top;

    enum LVL {GREAT, MIDDLE, LOW};
    LVL lvl;

};

struct QuestPerson
{
    QString name;
    QVector<QString> questAccepters;
    QHash<QString, QVector<QString> > questItemsReceive;
    QHash<QString, QVector<QString> > questItemsSend;
    QString location;
    QString title;
};

struct CurrentQuest
{
    QString name, title;
    QString giver, receiver;
    QString item;
    bool returnToGiver;
};

struct PlayerPosition
{
    int currentLeft, currentTop;
    double progress, currentLength;
    enum Direction {WEST, NORTH, EAST, SOUTH};
    QVector<QPoint> way;
    int aimLeft, aimTop;
};

struct PlayerStatus
{
    QString currentRegion;
    PlayerPosition position;
    CurrentQuest quest;
};

struct MetaProgress
{
    int lvl;
    double currentExp, lvlExp;
    int stashSize;
    QVector<int> artefacts;
    QVector<int> items;
};

class Map
{
public:
    Map();

    QVector < QVector<Region> > regions;
    QHash<QString, RegionLocation> locations;
    QHash<QString, QuestPerson> persons;

    PlayerStatus status;
    MetaProgress progress;
};

#endif // MAP_H
