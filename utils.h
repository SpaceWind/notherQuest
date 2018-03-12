#ifndef UTILS_H
#define UTILS_H

#include <QVector>

class StaticMethods
{
public:
    static void initRandom();
    static bool procChance(float chance, int quality = 1000);
    static int procItem(QVector<double> weights, int quality = 1000);
    static double minmax(double value, double min = 0.0, double max = 1.0);
};


#endif // UTILS_H
