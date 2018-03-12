#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "enemystatusitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    EnemyStatusItem *createEnemyInfo(double hp, double maxhp, double mana, double maxmana, QString name, QList<QString> effects);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
