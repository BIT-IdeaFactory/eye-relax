#include "dialog.h"
#include "ui_dialog.h"
#include <kolo.h>
#include <QVBoxLayout>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->setFixedSize(900,900);
    ui->setupUi(this);

    w=new QWidget();
    k=new Kolo(this);
    w=k;
    l=new QVBoxLayout();
    l->addWidget(w);
    ui->frame->setLayout(l);

}

Dialog::~Dialog()
{
    delete w;
    delete k;
    delete l;
    delete ui;
}
