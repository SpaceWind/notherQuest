#ifndef MAP_H
#define MAP_H

#include <QVector>
struct Node
{
    Node();
    Node(int len);
    ~Node(){}
    int value;
    int length;
};

class Map
{
public:
    Map();

    void init(int size);
    void initFromImage(QString name);
    void updateNode(int left, int top, int value);

    inline index(int left, int top) { return left * count + top; }
    QString toString();

    Node * nodes;

    int count;
};

#endif // MAP_H
