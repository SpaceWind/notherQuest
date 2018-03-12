#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testform.h"
#include "enemystatusitem.h"
#include <QListWidgetItem>
#include <QListWidget>
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TestForm *tf = new TestForm();
    tf->show();


    createEnemyInfo(80, 765, 50, 500, "БОБЕР", QList<QString>());
    createEnemyInfo(900, 900, 500, 500, "ХРЮХА", QList<QString>() << "Бешенство" << "СПИД");



}

MainWindow::~MainWindow()
{
    delete ui;
}

EnemyStatusItem* MainWindow::createEnemyInfo(double hp, double maxhp, double mana, double maxmana, QString name, QList<QString> effects)
{
    auto item = new EnemyStatusItem();
    item->render(hp, mana, maxhp, maxmana, name, effects);
    QListWidgetItem * listItem = new QListWidgetItem();
    listItem->setSizeHint(QSize(0, item->height()));
    ui->enemies->addItem(listItem);
    ui->enemies->setItemWidget(listItem, item);
    return item;
}
