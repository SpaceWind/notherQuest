#include "testform.h"
#include "ui_testform.h"
#include "playerstats.h"

TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    ui->setupUi(this);
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

    cha.name = ui->name_1->text();
    chb.name = ui->name_2->text();
    cha.isMagicAutoAttack = ui->md_1->isChecked();
    chb.isMagicAutoAttack = ui->md_2->isChecked();
    isFirst = cha.stats.speed > chb.stats.speed;
}

QString TestForm::fightStep()
{
    AutoAttack aa;
    QString aname, bname;
    QString message;
    if (isFirst)
    {
        aa = AutoAttack::makeAutoAttack(cha, chb);
        aname = cha.name.toUpper();
        bname = chb.name.toUpper();
    }
    else
    {
        aa = AutoAttack::makeAutoAttack(chb, cha);
        aname = chb.name.toUpper();
        bname = cha.name.toUpper();
    }


    if (!aa.missed)
    {
        if (!aa.isCrit)
            message = aname + " наносит " + QString::number(aa.damage, 'f', 3) + " урона  по " + bname + "!\n";
        else
            message = aname + " УЕБАЛ " + QString::number(aa.damage, 'f', 3) + " урона  по " + bname + "!\n";

        if (aa.isDefenderDead)
            message += bname + "умирает. " + aname + " победил";
    }
    else
        message = aname + " промахнулся!";

    if (isFirst)
        chb.currentHP -= aa.damage - aa.enemyHealed;
    else
        cha.currentHP -= aa.damage - aa.enemyHealed;

    ui->hpbar_1->setValue(cha.currentHP);
    ui->hpbar_->setValue(chb.currentHP);

    isFirst = !isFirst;
    return message;
}

void TestForm::on_pushButton_clicked()
{
    initCharacters();
    ui->hpbar_1->setMaximum(cha.info.hp);
    ui->hpbar_->setMaximum(chb.info.hp);
    ui->hpbar_1->setValue(cha.currentHP);
    ui->hpbar_->setValue(chb.currentHP);
    ui->textEdit->clear();
}

void TestForm::on_pushButton_2_clicked()
{
    ui->textEdit->append(fightStep());
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
