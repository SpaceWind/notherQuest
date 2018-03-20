#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    size = 16;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qsrand(QDateTime::currentDateTime().currentSecsSinceEpoch()%32000);
    m.init(16);
    ui->plainTextEdit->appendPlainText(m.toString());
}

void MainWindow::on_pushButton_2_clicked()
{
    m.updateNode(0,0,0);
    ui->plainTextEdit->appendPlainText(m.toString());
}

void MainWindow::on_pushButton_3_clicked()
{
    QElapsedTimer t;
    t.restart();
    m.init(size);
    m.updateNode(0,0,0);
    ui->plainTextEdit->appendPlainText( "SIZE: " + QString::number(size)  +  " TIME: " + QString::number(t.elapsed()));
    size *= 1.5;
}
