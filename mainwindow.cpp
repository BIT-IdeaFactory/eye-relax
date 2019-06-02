#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timer.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer *long_timer = new Timer(this);

    ui->clock->display("45:00");

    long_timer->clock = ui->clock;
    QTime working_interval(0,45,0);
    long_timer->setWorkingInterval(working_interval);
    long_timer->startWorking();

    QTimer *short_timer = new QTimer(this);
    connect(short_timer, &QTimer::timeout, long_timer, &Timer::change_time);
    short_timer->start(1000);
    long_timer->change_time();
}



MainWindow::~MainWindow()
{
    delete ui;
}

//MainWindow Buttons:
void MainWindow::set_to_normal() {
    ui->pbData->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbSettings->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbAbout->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbManu->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
}

void MainWindow::on_pbManu_clicked()
{
    set_to_normal();
    ui->pbManu->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px;}");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pbData_clicked()
{
    set_to_normal();
    ui->pbData->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pbSettings_clicked()
{
    set_to_normal();
    ui->pbSettings->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pbAbout_clicked()
{
    set_to_normal();
    ui->pbAbout->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");

    ui->stackedWidget->setCurrentIndex(3);
}
//End of MainWindow Buttons.






