#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>
#include "stats.h"
#include "utils.h"
#include "fightmanager.h"

namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = 0);
    ~TestForm();

    void initCharacters();
    void initSpells();
    QString fightStep();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TestForm *ui;

    Character cha, chb;
    bool isFirst;
    SpellFactory *sf;
    FightManager *fightManager;
};

#endif // TESTFORM_H
