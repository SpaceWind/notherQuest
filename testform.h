#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>
#include "stats.h"
#include "utils.h"
#include "fightmanager.h"
#include "questtimer.h"

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

signals:
    void invokeAddPlayer(Character *c);
    void invokeAddEnemy(Character *c);
    void invokeStartFight();
    void invokeStartTurn();
    void invokeClear();
public slots:
    void progress(double v);
    void updateText(QString s);
    void nextTurn();
    void fightEnded(bool playerWon);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TestForm *ui;

    Character cha, chb;
    bool isFirst;
    SpellFactory *sf;
    FightManager *fightManager;
    QuestTimer * questTimer;
};

#endif // TESTFORM_H
