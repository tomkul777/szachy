#include "kon.h"
#include <QDebug>

Kon::Kon(QWidget *parent, int x, int y, int player) : Figura(parent, x, y, player)
{
    this->nazwa = "Kon";

    if(player == 1) this->setPixmap(QPixmap(":/biale/PNG/kon_b.png"));
    else this->setPixmap(QPixmap(":/czarne/PNG/kon_c.png"));

    this->setGeometry(x*80, y*80, 80, 80);
}

bool Kon::sprawdzRuch(int x, int y)
{
    if(((x-this->x == 2 || x-this->x == -2) && (y-this->y == 1 || y-this->y == -1)) ||
            ((y-this->y == 2 || y-this->y == -2) && (x-this->x == 1 || x-this->x == -1))) {
        for(int i=0; i<wszystkieFigury.size(); i++) {
            if((wszystkieFigury[i]->getX() == x) && (wszystkieFigury[i]->getY() == y)
                    && (i != this->id)) {
                if(this->player == wszystkieFigury[i]->getPlayer()) return false;
                else {
                    //TUTAJ BEDZIE BICIE
                    return zbijanie(wszystkieFigury[i]);
                }
            }
        }
        return true;
    } else return false;
}

bool operator ==(Kon &k1, Kon &k2)
{
    return (k1.getId() == k2.getId());
}
