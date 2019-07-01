#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include "saver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void start_exercise();

    void on_pbManu_clicked();

    void on_pbData_clicked();

    void on_pbSettings_clicked();

    void on_pbAbout_clicked();

    void on_pbNightDay_clicked();

    void time_changed();

private:
    bool night = true;
    Saver* saver;
    void change_about_text_color_night();
    void change_settings_text_color_night();
    void change_about_text_color_day();
    void change_settings_text_color_day();
    void set_to_normal_night();
    void set_to_normal_day();

    Ui::MainWindow *ui;
signals:
    void exercise_started();

};

#endif // MAINWINDOW_H
