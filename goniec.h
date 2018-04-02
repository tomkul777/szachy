#ifndef GONIEC_H
#define GONIEC_H

#include "figura.h"

class Goniec : public Figura
{
public:
    Goniec(QWidget *parent, int x, int y, int player);
    bool sprawdzRuch(int x, int y);
};

#endif // GONIEC_H
