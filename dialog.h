#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWidget>
#include <kolo.h>
#include <QVBoxLayout>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QWidget* w;
    Kolo* k;
    QVBoxLayout* l;
};

#endif // DIALOG_H
