#include "testform.h"
#include "ui_testform.h"
#include "playerstats.h"
#include <QThread>
#include <QDebug>
#include "map.h"
#include <QFileDialog>

TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    ui->setupUi(this);
    sf = new SpellFactory();

    QThread *t = new QThread();
    QThread *fmt = new QThread();
    QTimer * timer = new QTimer();
    timer->moveToThread(t);

    questTimer = new QuestTimer(timer);
    questTimer->moveToThread(t);
    t->start();

    fightManager = new FightManager(sf, questTimer, 0);
    fightManager->moveToThread(fmt);
    fmt->start();

    QObject::connect(fightManager, SIGNAL(message(QString)), this, SLOT(updateText(QString)));
    QObject::connect(fightManager, SIGNAL(nextTurn()), this, SLOT(nextTurn()));
    QObject::connect(fightManager, SIGNAL(fightEnded(bool)), this, SLOT(fightEnded(bool)));

    QObject::connect(questTimer, SIGNAL(progress(double)), this, SLOT(progress(double)));

    connect(this, SIGNAL(invokeAddEnemy(Character*)), fightManager, SLOT(addEnemy(Character*)));
    connect(this, SIGNAL(invokeAddPlayer(Character*)), fightManager, SLOT(addPlayer(Character*)));
    connect(this, SIGNAL(invokeClear()), fightManager, SLOT(clear()));
    connect(this, SIGNAL(invokeStartFight()), fightManager, SLOT(startFight()));
    connect(this, SIGNAL(invokeStartTurn()), fightManager, SLOT(startTurn()));
}

TestForm::~TestForm()
{
    delete ui;
}

void TestForm::initCharacters()
{
    Stats a, b;
    a.strength = ui->str_1->value();
    a.strPerLevel = ui->str_pl_1->value();
    a.agility = ui->agi_1->value();
    a.agiPerLevel = ui->agi_pl_1->value();
    a.intellect = ui->int_1->value();
    a.intPerLevel = ui->int_pl_1->value();
    a.speed = ui->spd_1->value();
    a.spdPerLevel = ui->spd_pl_1->value();
    a.endurance = ui->end_1->value();
    a.endPerLevel = ui->end_pl_1->value();
    a.charisma = ui->cha_1->value();
    a.chaPerLevel = ui->cha_pl_1->value();
    a.level = ui->lvl_1->value();
    a.isBuilt = false;

    b.strength = ui->str_2->value();
    b.strPerLevel = ui->str_pl_2->value();
    b.agility = ui->agi_2->value();
    b.agiPerLevel = ui->agi_pl_2->value();
    b.intellect = ui->int_2->value();
    b.intPerLevel = ui->int_pl_2->value();
    b.speed = ui->spd_2->value();
    b.spdPerLevel = ui->spd_pl_2->value();
    b.endurance = ui->end_2->value();
    b.endPerLevel = ui->end_pl_2->value();
    b.charisma = ui->cha_2->value();
    b.chaPerLevel = ui->cha_pl_2->value();
    b.level = ui->lvl_2->value();
    b.isBuilt = false;

    cha.stats = a;
    chb.stats = b;
    cha.info = StatsInfo::buildInfo(cha.stats.build());
    chb.info = StatsInfo::buildInfo(chb.stats.build());
    cha.reset();
    chb.reset();

    cha.id = 1;
    chb.id = 2;

    cha.name = ui->name_1->text();
    chb.name = ui->name_2->text();
    cha.isMagicAutoAttack = ui->md_1->isChecked();
    chb.isMagicAutoAttack = ui->md_2->isChecked();
    isFirst = cha.stats.speed > chb.stats.speed;

    cha.resetPrepared();
    chb.resetPrepared();

    initSpells();
}

void TestForm::initSpells()
{
    static bool d = false;
    if (!d) d = true;
    else   return;
    cha.actives.activeSpells.append(sf->createSpell("CutStrike", &cha, 1));
    chb.actives.activeSpells.append(sf->createSpell("HybridStrike", &chb, 1));
}

void TestForm::progress(double v)
{
    ui->quest_timer->setMaximum(1000);
    ui->quest_timer->setValue(v*1000);
}

void TestForm::updateText(QString s)
{
    ui->textEdit->append(s);
    ui->status_label->setText(s);

    SM::animatePBProperty(ui->hpbar_1,cha.currentHP,1000);
    SM::animatePBProperty(ui->hpbar_,chb.currentHP, 1000);
}

void TestForm::nextTurn()
{
    invokeStartTurn();
}

void TestForm::fightEnded(bool playerWon)
{
    if (playerWon)
        ui->textEdit->append("победил " + cha.name);
    else
        ui->textEdit->append("победил " + chb.name);
    invokeClear();
    sf->makeReady(sf->findSpell("CutStrike", cha.id));
    sf->makeReady(sf->findSpell("HybridStrike", chb.id));
}

void TestForm::on_pushButton_clicked()
{
    initCharacters();
    ui->hpbar_1->setMaximum(cha.info.hp);
    ui->hpbar_->setMaximum(chb.info.hp);
    ui->hpbar_1->setValue(cha.currentHP);
    ui->hpbar_->setValue(chb.currentHP);
    ui->textEdit->clear();

    invokeAddPlayer(&cha);
    invokeAddEnemy(&chb);
    invokeStartFight();
    invokeStartTurn();
}

void TestForm::on_pushButton_3_clicked()
{
    PlayerStats *p = new PlayerStats(cha.info);
    p->show();
}

void TestForm::on_pushButton_4_clicked()
{
    PlayerStats *p = new PlayerStats(chb.info);
    p->show();
}

void TestForm::on_pushButton_2_clicked()
{
    QString name = QFileDialog::getOpenFileName();
    Region r;
    r.loadFromImage(name);
    r.saveToData("E:/map.dat");
    auto v =  r.findBuilding(Region::mapEntry::CHURCH, 30, 69, 2000);
    qDebug() << v << r.entries[r.indexV(v[0].x(), v[0].y(), r.width)].value << " " <<
                     r.entries[r.indexV(v[1].x(), v[1].y(), r.width)].value;

    qDebug() << r.findWay(30, 69, 32, 72);
    //qDebug() << r.findBuilding(Region::mapEntry::TAVERN);
}
