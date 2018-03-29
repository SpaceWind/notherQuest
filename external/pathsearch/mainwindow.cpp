#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QElapsedTimer>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    size = 16;
    qsrand(QDateTime::currentDateTime().currentSecsSinceEpoch()%32000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QElapsedTimer t;
    m.initFromImage(QFileDialog::getOpenFileName());
    t.restart();
    m.updateNode(153,415,0);
    ui->plainTextEdit->appendPlainText( "SIZE: " + QString::number(m.count)  +  " TIME: " + QString::number(t.elapsed()));
}

void MainWindow::on_pushButton_2_clicked()
{
    m.updateNode(0,0,0);
    ui->plainTextEdit->appendPlainText(m.toString());
}

void MainWindow::on_pushButton_3_clicked()
{
    for (int i = 0; i < 10; i++)
    {
        QElapsedTimer t;
        t.restart();
        m.init(size);
        m.updateNode(0,0,0);
        ui->plainTextEdit->appendPlainText( "SIZE: " + QString::number(size)  +  " TIME: " + QString::number(t.elapsed()));
        qApp->processEvents();
    }
    size *= 1.5;
}
