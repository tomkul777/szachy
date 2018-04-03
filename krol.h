#ifndef KROL_H
#define KROL_H

#include "figura.h"

class Krol : public Figura
{
private:
    bool czyRuszany;

public:
    Krol(QWidget *parent, int x, int y, int player);
    bool sprawdzRuch(int x, int y);
};

bool operator ==(Krol &k1, Krol &k2);

#endif // KROL_H
