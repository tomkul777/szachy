#ifndef HETMAN_H
#define HETMAN_H

#include "figura.h"

class Hetman : public Figura
{
public:
    Hetman(QWidget *parent, int x, int y, int player);
    bool sprawdzRuch(int &x, int &y);
};

#endif // HETMAN_H
