#ifndef KON_H
#define KON_H

#include "figura.h"

class Kon : public Figura
{
public:
    Kon(QWidget *parent, int x, int y, int player);
    bool sprawdzRuch(int x, int y);
};

bool operator ==(Kon &k1, Kon &k2);

#endif // KON_H
