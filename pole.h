#ifndef POLE_H
#define POLE_H

#include <QLabel>

class Pole : public QLabel
{
protected:
    int x, y;

public:
    Pole(QWidget *parent, int x, int y);
};

#endif // POLE_H
