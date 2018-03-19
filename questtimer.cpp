#include "questtimer.h"
#include <QDebug>


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

void QuestTimer::start(double time)
{
    this->time = time;
    elapsed.restart();
    timer->setInterval(30);
    timer->start();
}

void QuestTimer::update()
{
    double v = double(elapsed.elapsed())/1000. / time;
    emit progress(StaticMethods::minmax(v));
    if (v >= 1.0)
        timer->stop();
}
