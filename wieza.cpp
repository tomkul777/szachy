#include "wieza.h"
#include <QDebug>

Wieza::Wieza(QWidget *parent, int x, int y, int player) : Figura(parent, x, y, player)
{
    this->nazwa = "Wieza";

    if(player == 1) this->setPixmap(QPixmap(":/biale/PNG/wieza_b.png"));
    else this->setPixmap(QPixmap(":/czarne/PNG/wieza_c.png"));

    this->setGeometry(x*80, y*80, 80, 80);
}

bool Wieza::sprawdzRuch(int x, int y)
{
    if(this->x == x && this->y == y) return false;
    else if(x-this->x == 0 || y-this->y == 0) {
        if(x-this->x == 0) {
            int minY = y<this->y ? y : this->y;
            int maxY = y>this->y ? y : this->y;

            for(int i=0; i<wszystkieFigury.size(); i++) {
                if((wszystkieFigury[i]->getY() > minY) && (wszystkieFigury[i]->getY() < maxY)
                        && (wszystkieFigury[i]->getX()-x == 0)) return false;
            }
        } else {
            int minX = x<this->x ? x : this->x;
            int maxX = x>this->x ? x : this->x;

            for(int i=0; i<wszystkieFigury.size(); i++) {
                if((wszystkieFigury[i]->getX() > minX) && (wszystkieFigury[i]->getX() < maxX)
                        && (wszystkieFigury[i]->getY()-y == 0)) return false;
            }
        }
        return true;
    } else return false;
}

bool operator==(Wieza &w1, Wieza &w2)
{
    return (w1.getId() == w2.getId());
}
