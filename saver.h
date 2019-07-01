#ifndef SAVER_H
#define SAVER_H

#include <QObject>
#include <QFileInfo>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QTime>
class Saver : public QObject
{
    Q_OBJECT
public:
    explicit Saver(QObject *parent = nullptr);
    bool exists();
    void load();

    bool getChecked() const;

    QTime getTTime();

private:
    QString filename="./Time.txt";
    QFile* file;
    QString STime;
    QTime tTime;
    bool checked=false;

signals:

public slots:
    void save(QString);
};

#endif // SAVER_H
