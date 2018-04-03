#ifndef PIONEK_H
#define PIONEK_H

#include "figura.h"

class Pionek : public Figura
{
private:
    bool czyRuszany;

public:
    Pionek(QWidget *parent, int x, int y, int player);
    bool sprawdzRuch(int x, int y);
};

bool operator ==(Pionek &p1, Pionek &p2);

#endif // PIONEK_H
