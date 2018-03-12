#ifndef ENEMYSTATUSITEM_H
#define ENEMYSTATUSITEM_H

#include <QWidget>
#include <QList>

namespace Ui {
class EnemyStatusItem;
}

class EnemyStatusItem : public QWidget
{
    Q_OBJECT

public:
    explicit EnemyStatusItem(QWidget *parent = 0);
    void render(double hp, double mana, double maxhp, double maxmana, QString name,
                QList<QString> statusEffects);
    ~EnemyStatusItem();

private:
    Ui::EnemyStatusItem *ui;
};

#endif // ENEMYSTATUSITEM_H
