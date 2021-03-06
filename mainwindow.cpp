#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timer.h"
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->clock->display("45:00");
    Timer *long_timer = new Timer(this);
      long_timer->clock = ui->clock;
      QTime working_interval(0,45,0);
      long_timer->setWorkingInterval(working_interval);
      long_timer->startWorking();

      QTimer *short_timer = new QTimer(this);
      connect(short_timer, &QTimer::timeout, long_timer, &Timer::change_time);
      short_timer->start(1000);
      long_timer->change_time();

    if(night==true){
        ui->pbManu->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px;}");
    }
    else{
        ui->pbManu->setStyleSheet("QPushButton{ color: white;background-color: rgb(49, 235, 167);border-style: outset;border-width: 2px;border-color: white;font: bold 15px;min-width: 10em;padding: 6px;}");
    }
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::set_to_normal_night()
{
   // ui->buttonGroup->setStyleSheet( "QButtonGroup{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );

    ui->pbData->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbSettings->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbAbout->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbManu->setStyleSheet( "QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }" );
}

void MainWindow::set_to_normal_day()
{
    ui->pbData->setStyleSheet( "QPushButton{ color: rgb(49, 235, 167);background-color: rgb(239, 242, 247); border-style: outset;border-width: 2px;border-color: white; font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbSettings->setStyleSheet( "QPushButton{ color: rgb(49, 235, 167);background-color: rgb(239, 242, 247); border-style: outset;border-width: 2px;border-color: white; font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbAbout->setStyleSheet( "QPushButton{ color: rgb(49, 235, 167);background-color: rgb(239, 242, 247); border-style: outset;border-width: 2px;border-color: white; font: bold 15px;min-width: 10em; padding: 6px; }" );
    ui->pbManu->setStyleSheet( "QPushButton{ color: rgb(49, 235, 167);background-color: rgb(239, 242, 247); border-style: outset;border-width: 2px;border-color: white; font: bold 15px;min-width: 10em; padding: 6px; }" );
}

void MainWindow:: change_about_text_color_day()
{
    ui->label_authors->setStyleSheet("QLabel{color: rgb(50, 42, 83); border-width: 0px; font: bold 30px; padding: 6px;}");
    ui->label_text_patryk->setStyleSheet("QLabel{ color: rgb(50, 42, 83); border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_oros->setStyleSheet("QLabel{ color: rgb(50, 42, 83); border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_stanislav->setStyleSheet("QLabel{ color: rgb(50, 42, 83); border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_michal->setStyleSheet("QLabel{color: rgb(50, 42, 83); border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_konrad->setStyleSheet("QLabel{color:rgb(50, 42, 83); border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_info->setStyleSheet("QLabel{ color: rgb(50, 42, 83); border-width: 0px; font: bold 11px; padding: 6px;}");
}

void MainWindow::change_settings_text_color_day()
{
    ui->label_text_NightDay->setStyleSheet("QLabel{color: rgb(50, 42, 83);; border-width: 0px; font: bold 20px; padding: 6px;}");
    ui->label_text_SetTime->setStyleSheet("QLabel{color: rgb(50, 42, 83);; border-width: 0px; font: bold 20px; padding: 6px;}");
    ui->lineEdit_time->setStyleSheet("QLineEdit{color:rgb(50, 42, 83); background-color:white; border-radius: 15px; border-style: outset;border-width: 3px;border-color: rgb(49, 235, 167);font: bold 15px;}");
    ui->label_text_NightDay->setText(" day version");
}

void MainWindow::change_settings_text_color_night()
{
    ui->label_text_NightDay->setStyleSheet("QLabel{color: rgb(18, 18, 18); border-width: 0px; font: bold 20px; padding: 6px;}");
    ui->label_text_SetTime->setStyleSheet("QLabel{color: rgb(18, 18, 18); border-width: 0px; font: bold 20px; padding: 6px;}");
    ui->lineEdit_time->setStyleSheet("QLineEdit{color: rgb(76, 121, 206); background-color: rgb(25, 28, 35); border-radius: 15px; border-style: outset;border-width: 3px;border-color: rgb(76, 121, 206);font: bold 15px;}");
    ui->label_text_NightDay->setText("night version");
}

void MainWindow:: change_about_text_color_night()
{
    ui->label_authors->setStyleSheet("QLabel{color: white; border-width: 0px; font: bold 30px; padding: 6px;}");
    ui->label_text_patryk->setStyleSheet("QLabel{ color: white; border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_oros->setStyleSheet("QLabel{color: white; border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_stanislav->setStyleSheet("QLabel{ color: white; border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_michal->setStyleSheet("QLabel{ color: white; border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_konrad->setStyleSheet("QLabel{ color: white; border-width: 0px; font: bold 11px; padding: 6px;}");
    ui->label_text_info->setStyleSheet("QLabel{ color: white; border-width: 0px; font: bold 11px; padding: 6px;}");
}

void MainWindow::on_pbManu_clicked()
{
    if(night==true)
    {
        set_to_normal_night();
        ui->pbManu->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px;}");

    }
    else
    {
        set_to_normal_day();
        ui->pbManu->setStyleSheet("QPushButton{ color: white;background-color: rgb(49, 235, 167);border-style: outset;border-width: 2px;border-color: white;font: bold 15px;min-width: 10em;padding: 6px;}");

    }
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pbData_clicked()
{
    if(night==true){
        set_to_normal_night();
        ui->pbData->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");
    }

    else {
        set_to_normal_day();
        ui->pbData->setStyleSheet("QPushButton{ color: white;background-color: rgb(49, 235, 167);border-style: outset;border-width: 2px;border-color: white;font: bold 15px;min-width: 10em;padding: 6px;}");
    }

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pbSettings_clicked()
{
    if(night==true){
        set_to_normal_night();
        ui->pbSettings->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");
    }

    else{
        set_to_normal_day();
        ui->pbSettings->setStyleSheet("QPushButton{ color: white;background-color: rgb(49, 235, 167);border-style: outset;border-width: 2px;border-color: white;font: bold 15px;min-width: 10em;padding: 6px;}");
    }

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pbAbout_clicked()
{
    if(night==true){
        set_to_normal_night();
        ui->pbAbout->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");
    }
    else{
        set_to_normal_day();
        ui->pbAbout->setStyleSheet("QPushButton{ color: white;background-color: rgb(49, 235, 167);border-style: outset;border-width: 2px;border-color: white;font: bold 15px;min-width: 10em;padding: 6px;}");
    }
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_pbNightDay_clicked()
{
    night=!night;
    QIcon icon;
      if(night==true){
        icon.addFile(QString::fromUtf8("C:/Users/Eugen/Documents/QT/Photos/night-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui->pbNightDay->setIcon(icon);
        ui->pbNightDay->setIconSize(QSize(80, 80));

        set_to_normal_night();
        ui->pbSettings->setStyleSheet("QPushButton{ color: white;background-color: rgb(76, 121, 206);border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em;padding: 6px; }");

        change_settings_text_color_night();
        change_about_text_color_night();
        setStyleSheet("QMainWindow{background-color: rgb(40, 44, 53);}");
        ui->frameChoose->setStyleSheet("QFrame{ border-color: rgb(0, 0, 0);border-width : 1px;border-style:inset;background-color: rgb(33, 36, 45); }");
        ui->frameTop->setStyleSheet("QFrame{ border-color: rgb(0, 0, 0);border-width : 1.2px;border-style:inset;background-color: rgb(33, 36, 45); }");
        ui->label_text_top->setStyleSheet("QLabel{color: rgb(76, 121, 206); font: bold 15px; padding: 6px;  font: italic 15px;border-width: 0px;}");
        ui->clock->setStyleSheet("QLCDNumber{ color: white; background-color: rgb(25, 28, 35); border-radius: 40px; border-style: outset;border-width: 7px;border-color: rgb(76, 121, 206);}");
    }
    else {
//            qApp->setStyleSheet(QString("QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); background-color: white;border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }"));
//            qApp->setStyleSheet(QString("QLabel{color: rgb(49, 235, 167); font: bold 15px; padding: 6px;  font: italic 15px;border-width: 0px;}"));
//            qApp->setStyleSheet(QString("QFrame{ border-color: white;border-width : 1px;border-style:inset;  background-color:white;  }"));
//          setStyleSheet(QString("QLabel{color: rgb(49, 235, 167); font: bold 15px; padding: 6px;  font: italic 15px;border-width: 0px;}"));
//         setStyleSheet(QString("QPushButton{ color: rgb(76, 121, 206);background-color: rgb(33, 36, 45); background-color: white;border-style: outset;border-width: 2px;border-color: rgb(18, 18, 18);font: bold 15px;min-width: 10em; padding: 6px; }"));

         icon.addFile(QString::fromUtf8("C:/Users/Eugen/Documents/QT/Photos/day-button.png"), QSize(), QIcon::Normal, QIcon::Off);
         ui->pbNightDay->setIcon(icon);
         ui->pbNightDay->setIconSize(QSize(80, 80));

         set_to_normal_day();
         ui->pbSettings->setStyleSheet("QPushButton{ color: white;background-color: rgb(49, 235, 167);border-style: outset;border-width: 2px;border-color: white;font: bold 15px;min-width: 10em;padding: 6px;}");

         change_settings_text_color_day();
         change_about_text_color_day();
         setStyleSheet("QMainWindow{background-color:rgb(239, 242, 247);}");
         ui->frameChoose->setStyleSheet("QFrame{ border-color: white;border-width : 1px;border-style:inset;  background-color:white; }");
         ui->frameTop->setStyleSheet("QFrame{ border-color: rgb(49, 235, 167);border-bottom-width : 3px;border-style:inset; background-color:rgb(239, 242, 247);background-color:rgb(91, 81, 119);background-color:rgb(50, 42, 83);}");
         ui->label_text_top->setStyleSheet("QLabel{color: rgb(49, 235, 167); font: bold 15px; padding: 6px;  font: italic 15px;border-width: 0px;}");
         ui->clock->setStyleSheet("QLCDNumber{ color:rgb(91, 81, 119); color:rgb(50, 42, 83); background-color: white; border-radius: 40px; border-style: outset;border-width: 7px;border-color: rgb(49, 235, 167);}");

    }

    ui->AboutWidget->setStyleSheet("QLabel{text-color:black;}");


}
