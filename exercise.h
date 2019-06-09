#ifndef EXERCISE_H
#define EXERCISE_H

#include <QWidget>
#include "kolo.h"

namespace Ui {
class Exercise;
}

class Exercise : public QWidget
{
    Q_OBJECT

public:
    explicit Exercise(QWidget *parent = nullptr);
    ~Exercise();

private:
    Ui::Exercise *ui;
    Kolo k;
};

#endif // EXERCISE_H
