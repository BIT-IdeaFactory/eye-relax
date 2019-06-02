#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>

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

    void on_pbManu_clicked();

    void on_pbData_clicked();

    void on_pbSettings_clicked();

    void on_pbAbout_clicked();

    void on_pbNightDay_clicked();


private:
    bool night = true;
    void change_about_text_color_night();
    void change_settings_text_color_night();
    void change_about_text_color_day();
    void change_settings_text_color_day();
    void set_to_normal_night();
    void set_to_normal_day();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
