#include "map.h"
#include <QImage>
#include <QFile>

#include <QDebug>
Map::Map()
{
    count = 0;
    nodes = 0;
}

void Map::init(int size)
{
    if (nodes) delete nodes;
    count = size;
    nodes = new Node[size*size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <size; j++)
        {
            int value;
            if (qrand()%100 >= 50 || (i < 16 && j < 16))
                value = qrand()%16 + 1;
            else
                value = 0;
            nodes[i*size +j] = Node(value);
        }
    }
}

void Map::initFromImage(QString name)
{
    QFile f(name);
    f.open(QFile::ReadOnly);
    QImage img = QImage::fromData(f.readAll(),"PNG");

    count = img.width();


    if (nodes) delete[] nodes;
    nodes = new Node[count*count];

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j <count; j++)
        {
            int value = img.pixel(i,j) == qRgb(0,0,0) ? qrand()%16 + 1 : 0;
            nodes[i*count +j] = Node(value);
        }
    }
    f.close();
}

void Map::updateNode(int left, int top, int value)
{
    if (left >= 0 && count > left && top >= 0 && count > top && nodes[index(left, top)].length > 0 &&
        (nodes[index(left, top)].value == 0 || nodes[index(left, top)].value > value + nodes[index(left, top)].length))
    {
        nodes[index(left,top)].value = nodes[index(left,top)].length + value;
        int newV = nodes[index(left,top)].value;
        updateNode(left, top - 1, newV);
        updateNode(left, top + 1, newV);
        updateNode(left - 1, top, newV);
        updateNode(left + 1, top, newV);
    }
}

QString Map::toString()
{
    QString result;
    for (int i = 0; i < count; i++)
    {
        QString currentS;
        for (int j = 0; j < count; j++)
        {
            currentS += QString::number(nodes[index(i,j)].value) + "/" + QString::number(nodes[index(i,j)].length) + "\t";
        }
        currentS += "\n";
        result += currentS;
    }
    return result;
}

Node::Node()
{
    value = 0;
    length = 0;
}

Node::Node(int len)
{
    value = 0;
    length = len;
}
