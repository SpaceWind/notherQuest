#ifndef UTILS_H
#define UTILS_H

#include <QVector>
#include <QProgressBar>


class SM
{
public:
    static void initRandom();
    static bool procChance(float chance, int quality = 1000);
    static int procItem(QVector<double> weights, int quality = 1000);
    static double minmax(double value, double min = 0.0, double max = 1.0);
    static void animatePBProperty(QProgressBar* pb, int endValue, int time);
    static double pickItem(const QVector<int> &options, const QVector<double> &values, int item);
    static QString pickItem(const QVector<int> &options, const QVector<QString> &values, int item);
};


#endif // UTILS_H
