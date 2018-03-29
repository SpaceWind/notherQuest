#include "map.h"
#include <QImage>
#include <QFile>

void Region::loadFromImage(QString filename)
{
    QFile f(filename);
    QImage img;
    if (f.open(QFile::ReadOnly))
        img = QImage::fromData(f.readAll(),"PNG");
    else
        return;
    if (img.isNull())
        return;

    width = img.width();
    height = img.height();
    entries = new mapEntry[width * height];

    for (int j = 0; j < width; j++)
        for (int i = 0; i < height; i++)
        {
            int index = j*width + i;
            QRgb color = img.pixel(i,j);

            int red = qRed(color);
            entries[index].roadCoef = 1.0;
            if (red == 0 || red == 40 || red == 180 || red == 200 || red == 220 || red == 240)
                entries[index].roadType = mapEntry::ROAD;
            else if (red == 160)
                entries[index].roadType = mapEntry::CITY;
            else if (red == 170)
                entries[index].roadType = mapEntry::DUNGEON;
            else
                entries[index].roadType = mapEntry::NONROAD;
            switch (red)
            {
            case 180:   entries[index].roadCoef *= 2.0; break;
            case 200:   entries[index].roadCoef *= 4.0; break;
            case 220:   entries[index].roadCoef *= 8.0; break;
            case 240:   entries[index].roadCoef *= 16.0; break;
            default: break;
            }

            int green = qGreen(color);
            switch (green)
            {
            case 0: case 255: default: entries[index].buildingType = mapEntry::NONBUILDING; break;
            case 100: entries[index].buildingType = mapEntry::ARTEFACT_TRADER; break;
            case 200: entries[index].buildingType = mapEntry::ITEM_TRADER; break;
            case 180: entries[index].buildingType = mapEntry::BORDEL; break;
            case 160: entries[index].buildingType = mapEntry::CHURCH; break;
            case 140: entries[index].buildingType = mapEntry::TAVERN; break;
            case 120: entries[index].buildingType = mapEntry::GUILD; break;
            case 66: entries[index].buildingType = mapEntry::SPAWN; break;
            case 33: entries[index].buildingType = mapEntry::CEMETERY; break;
            case 10: entries[index].buildingType = mapEntry::TPT_NORTH; break;
            case 20: entries[index].buildingType = mapEntry::TPT_EAST; break;
            case 30: entries[index].buildingType = mapEntry::TPT_SOUTH; break;
            case 40: entries[index].buildingType = mapEntry::TPT_WEST; break;
            case 11: entries[index].buildingType = mapEntry::TPF_SOUTH; break;
            case 21: entries[index].buildingType = mapEntry::TPF_WEST; break;
            case 31: entries[index].buildingType = mapEntry::TPF_NORTH; break;
            case 41: entries[index].buildingType = mapEntry::TPF_EAST; break;
            }

            switch (green)
            {
            case 250: entries[index].roadCoef /= 8.0; break;
            case 190: entries[index].roadCoef /= 4.0; break;
            case 130: entries[index].roadCoef /= 2.0; break;
            default: break;
            }

            int blue = qBlue(color);
            entries[index].length = blue;
            entries[index].value = 0;
            entries[index].left = i;
            entries[index].top = j;

        }

}

void Region::loadFromData(QString filename)
{
    QFile f(filename);
    if (f.open(QFile::ReadOnly))
    {
        QDataStream ds(&f);
        int magic;
        ds >> magic;
        if (magic == S_MAGIC)
        {
            int count;
            ds >> name >> title >> west >> north >> east >> south >> width >> height >> count;
            entries = new mapEntry[count];
            for (int i = 0; i < count; i++)
                entries[i].loadFromDS(ds);
        }
        f.close();
    }
}

void Region::saveToData(QString filename)
{
    QFile f(filename);
    if (f.open(QFile::WriteOnly))
    {
        QDataStream ds(&f);
        ds << S_MAGIC << name << title << west << north << east << south << width << height << width*height;
        for (int i = 0; i < width*height; i++)
            entries[i].saveToDS(ds);
        f.flush();
        f.close();
    }
}

void Region::calculateValues(int left, int top, int value)
{
    if (left >= 0 && width > left && top >= 0 && height > top && entries[indexV(left, top, width)].length > 0 &&
        (entries[indexV(left, top, width)].value == 0 || entries[indexV(left, top, width)].value > value + entries[indexV(left, top, width)].length))
    {
        entries[indexV(left, top, width)].value = entries[indexV(left, top, width)].length + value;
        int newV = entries[indexV(left, top, width)].value;
        calculateValues(left, top - 1, newV);
        calculateValues(left, top + 1, newV);
        calculateValues(left - 1, top, newV);
        calculateValues(left + 1, top, newV);
    }
}

QVector<QPoint> Region::findWay(int startLeft, int startTop, int endLeft, int endTop)
{
    int currentLeft = endLeft, currentTop = endTop;
    QVector<QPoint> result;
    result.append(QPoint(currentLeft, currentTop));
    bool fail = false;
    while (currentLeft != startLeft && currentTop != startTop)
    {
        int needValue = entries[indexV(currentLeft, currentTop, width)].value - entries[indexV(currentLeft, currentTop, width)].length;

        if (currentLeft > 0 && entries[indexV(currentLeft - 1, currentTop, width)].value == needValue)
        {
            currentLeft--;
            result.append(QPoint(currentLeft, currentTop));
            continue;
        }
        else if (width - 1 > currentLeft && entries[indexV(currentLeft + 1, currentTop, width)].value == needValue)
        {
            currentLeft++;
            result.append(QPoint(currentLeft, currentTop));
            continue;
        }
        else if (currentTop > 0 && entries[indexV(currentLeft, currentTop - 1, width)].value == needValue)
        {
            currentTop--;
            result.append(QPoint(currentLeft, currentTop));
            continue;
        }
        else if (height - 1 > currentTop && entries[indexV(currentLeft, currentTop + 1, width)].value == needValue)
        {
            currentTop++;
            result.append(QPoint(currentLeft, currentTop));
            continue;
        }
        else {
            fail = true;
            break;
        }
    }
    if (fail)
        return QVector<QPoint>();
    std::reverse(result.begin(), result.end());
    return result;
}

QVector<QPoint> Region::findRoad(Region::mapEntry::RoadType type)
{
    QVector<QPoint> result;
    for (int left = 0; left < width; left++)
        for (int top = 0; top < height; top++)
        {
            if (entries[indexV(left, top, width)].roadType == type)
                result.append(QPoint(left, top));
        }
    return result;
}

QVector<QPoint> Region::findRoad(Region::mapEntry::RoadType type, int sLeft, int sTop, int range)
{
    auto allItems = findRoad(type);
    return filterByRange(allItems, sLeft, sTop, range);
}

QVector<QPoint> Region::findBuilding(Region::mapEntry::BuildingType type)
{
    QVector<QPoint> result;
    for (int left = 0; left < width; left++)
        for (int top = 0; top < height; top++)
        {
            if (entries[indexV(left, top, width)].buildingType == type)
                result.append(QPoint(left, top));
        }
    return result;
}

QVector<QPoint> Region::findBuilding(Region::mapEntry::BuildingType type, int sLeft, int sTop, int range)
{
    auto allItems = findBuilding(type);
    return filterByRange(allItems, sLeft, sTop, range);
}

QVector<QPoint> Region::filterByRange(QVector<QPoint> &items, int sLeft, int sTop, int range)
{
    if (items.isEmpty())
        return items;
    calculateValues(sLeft, sTop);
    QVector<QPoint> result;
    foreach (const QPoint &p, items)
    {
        if (entries[indexV(p.x(), p.y(), width)].value <= range)
            result.append(p);
    }
    return result;
}

int Region::indexV(int left, int top, int width)
{
    return top*width + left;
}

Region::mapEntry Region::mapEntry::loadFromDS(QDataStream &ds)
{
    mapEntry result;
    int rc, bt;
    ds >> result.roadCoef >> result.value >> result.left >> result.top >> result.length >> rc >> bt;
    result.roadCoef = rc;
    result.buildingType = (mapEntry::BuildingType)bt;
    return result;
}

void Region::mapEntry::saveToDS(QDataStream &ds)
{
    ds << roadCoef << value << left << top << length << roadCoef << buildingType;
}
