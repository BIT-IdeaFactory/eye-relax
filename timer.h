#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QTime>
#include <QLCDNumber>
#include <mainwindow.h>
class Timer : public QObject
{
    Q_OBJECT
public:
    QLCDNumber *clock;
    explicit Timer(QObject *parent = nullptr);
    QTime remaining();
    void connect_signal(MainWindow *ui);
    static QTime elapsed(QTime first,QTime second);
private:
    QTime workingTime;
    void createWorkTimer();
    QTimer* WorkTimer;

public slots:
    void change_time();
    void startWorking();
    void setWorkingInterval(QTime time);
    void stopWorking();

signals:

};

#endif // TIMER_H
