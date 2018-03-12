#include "playerstats.h"
#include "ui_playerstats.h"

PlayerStats::PlayerStats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerStats)
{
    ui->setupUi(this);
}

PlayerStats::PlayerStats(StatsInfo &info, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerStats)
{
    ui->setupUi(this);
    this->info = info;
    render();
}

PlayerStats::~PlayerStats()
{
    delete ui;
}

void PlayerStats::render()
{
    ui->dmg->setText(QString::number(info.damage, 'f', 2));
    ui->arm->setText(QString::number(info.armor()*100., 'f', 2) + "%");
    ui->mr->setText(QString::number(info.mres()*100., 'f', 2) + "%");
    ui->crc->setText(QString::number(info.crtChance()*100., 'f', 2) + "%");
    ui->crd->setText(QString::number(info.crtDamage(), 'f', 2) + "x");
    ui->sd->setText(QString::number(info.spellDamage(), 'f', 2) + "x");
    ui->ms->setText(QString::number(info.ms + 300., 'f', 2));
    ui->eq->setText(QString::number(info.evasion(), 'f', 2) + "%");
    ui->rq->setText(QString::number(info.rewardCoef(), 'f', 2) + "x");
    ui->tq->setText(QString::number(info.tradePriceBuyCoef(), 'f', 2) +" / " +
                    QString::number(info.tradePriceSellCoef(), 'f', 2));
    ui->siq->setText(QString::number(info.specialItemChance(), 'f', 2) + "%");
    ui->maxhp->setText(QString::number(info.hp, 'f', 2));
    ui->maxmana->setText(QString::number(info.mana, 'f', 2));
    ui->hpr->setText(QString::number(info.hpr, 'f', 2));
    ui->mpr->setText(QString::number(info.mpr, 'f', 2));
    ui->spec->setText(QString::number(info.speciality(), 'f', 2));
}
