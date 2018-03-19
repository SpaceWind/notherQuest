#ifndef QUESTTIMER_H
#define QUESTTIMER_H

#include <QObject>
#include <QElapsedTimer>
#include <QTimer>
#include <utils.h>

class QuestTimer : public QObject
{
    Q_OBJECT
public:
    explicit QuestTimer(QTimer * t, QObject *parent = 0);
    ~QuestTimer(){}

signals:
    void progress(double percent);

public slots:
    bool isReady();
    void start(double time = 5.0, bool animation = true);

    void update();

private:
    QElapsedTimer elapsed;
    QTimer *timer;
    double time;
    bool noAnimation;
};

#endif // QUESTTIMER_H
