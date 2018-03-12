#include "enemystatusitem.h"
#include "ui_enemystatusitem.h"

EnemyStatusItem::EnemyStatusItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnemyStatusItem)
{
    ui->setupUi(this);
}

void EnemyStatusItem::render(double hp, double mana, double maxhp, double maxmana, QString name, QList<QString> statusEffects)
{
    ui->hp->setMaximum(maxhp);
    ui->mana->setMaximum(maxmana);
    ui->hp->setValue(hp);
    ui->mana->setValue(mana);
    ui->groupBox->setTitle(name);

    ui->effectlist->clear();
    foreach (const QString &s, statusEffects)
        ui->effectlist->addItem(s);
}

EnemyStatusItem::~EnemyStatusItem()
{
    delete ui;
}
