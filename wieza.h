#ifndef WIEZA_H
#define WIEZA_H

#include "figura.h"

class Wieza : public Figura
{
public:
    Wieza(QWidget *parent, int x, int y, int player);
    bool sprawdzRuch(int x, int y);
};

#endif // WIEZA_H
