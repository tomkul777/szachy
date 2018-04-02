#include "pole.h"

Pole::Pole(QWidget *parent, int x, int y) : QLabel(parent)
{
    this->x = x;
    this->y = y;
    this->setGeometry(y*80, x*80, 80, 80);

    if((x+y)% 2 == 0) this->setPixmap(QPixmap(":/pola/PNG/pole2.png"));
    else this->setPixmap(QPixmap(":/pola/PNG/pole1.png"));

    this->show();
}


