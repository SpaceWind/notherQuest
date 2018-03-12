#include "utils.h"
#include <QObject>
#include <QDateTime>


void StaticMethods::initRandom()
{
    QDateTime dt = QDateTime::currentDateTime();
    qsrand(dt.currentSecsSinceEpoch());
}

bool StaticMethods::procChance(float chance, int quality)
{
    int procInt = chance*quality;
    return qrand()%quality < procInt;
}

int StaticMethods::procItem(QVector<double> weights, int quality)
{
    int result = 0;
    double totalWeight = 0;
    double proc = double(qrand()%quality)/double(quality);
    foreach (const double &d, weights)
        totalWeight += d;
    double currentWeight = 0.0;
    for (int i = 0; i < weights.count(); i++)
    {
        double v = weights[i];
        weights[i] = v + currentWeight;
        currentWeight += v;
    }
    proc *= totalWeight;

    for (int i = 0; i < weights.count(); i++)
        if (proc <= weights[i])
            return i;

    return result;
}

double StaticMethods::minmax(double value, double min, double max)
{
    return std::min(std::max(value, min), max);
}
