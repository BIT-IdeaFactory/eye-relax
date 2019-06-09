#include "exercise.h"
#include "ui_exercise.h"

Exercise::Exercise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exercise)
{
    setGeometry(56,100,900,900);
    k.show();
}

Exercise::~Exercise()
{
    delete ui;
}
