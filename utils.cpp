#include "utils.h"
#include <QObject>
#include <QDateTime>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QDebug>


void SM::initRandom()
{
    QDateTime dt = QDateTime::currentDateTime();
    qsrand(dt.currentSecsSinceEpoch());
}

bool SM::procChance(float chance, int quality)
{
    int procInt = chance*quality;
    return qrand()%quality < procInt;
}

int SM::procItem(QVector<double> weights, int quality)
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

double SM::minmax(double value, double min, double max)
{
    return std::min(std::max(value, min), max);
}

void SM::animatePBProperty(QProgressBar *pb, int endValue, int time)
{
    QPropertyAnimation *a = new QPropertyAnimation(pb, "value");
    a->setStartValue(pb->value());
    a->setEndValue(endValue);
    a->setDuration(time);
    a->setEasingCurve(QEasingCurve::OutElastic);
    a->start(QAbstractAnimation::DeleteWhenStopped);
}

double SM::pickItem(const QVector<int> &options, const QVector<double> &values, int item)
{
    int index = options.indexOf(item);
    if (index >= 0 && index < values.count())
        return values[index];
    if (values.count())
        return values.first();
    else
        return 0.0;
}

QString SM::pickItem(const QVector<int> &options, const QVector<QString> &values, int item)
{
    int index = options.indexOf(item);
    if (index >= 0 && index < values.count())
        return values[index];
    if (values.count())
        return values.first();
    else
        return "";
}

QuestTimer::QuestTimer(QTimer *t, QObject *parent) : QObject(parent)
{
    timer = t;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

bool QuestTimer::isReady()
{
    bool ready = double(elapsed.elapsed())/1000. > time;
    return ready;
}

void QuestTimer::start(double time, bool animation)
{
    this->time = time;
    elapsed.restart();
    timer->setInterval(25);
    timer->start();
    noAnimation = !animation;
}

void QuestTimer::update()
{
    double v = double(elapsed.elapsed())/1000. / time;
    emit progress(noAnimation ? 1.0 : SM::minmax(v));
    if (v >= 1.0)
        timer->stop();
}

