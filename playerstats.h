#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <QWidget>
#include "stats.h"

namespace Ui {
class PlayerStats;
}

class PlayerStats : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerStats(QWidget *parent = 0);
    explicit PlayerStats(StatsInfo &info, QWidget *parent = 0);
    ~PlayerStats();

public slots:
    void render();

private:
    Ui::PlayerStats *ui;


    StatsInfo info;

};

#endif // PLAYERSTATS_H
