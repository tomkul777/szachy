#ifndef WIEZA_H
#define WIEZA_H

#include "figura.h"

class Wieza : public Figura
{
public:
    Wieza(QWidget *parent, int x, int y, int player);
    bool sprawdzRuch(int x, int y);
};

bool operator==(Wieza w1, Wieza w2);

#endif // WIEZA_H
