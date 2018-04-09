#include "goniec.h"
#include <QDebug>

Goniec::Goniec(QWidget *parent, int x, int y, int player) : Figura(parent, x, y, player)
{
    this->nazwa = "Goniec";

    if(player == 1) this->setPixmap(QPixmap(":/biale/PNG/goniec_b.png"));
    else this->setPixmap(QPixmap(":/czarne/PNG/goniec_c.png"));

    this->setGeometry(x*80, y*80, 80, 80);
}

bool Goniec::sprawdzRuch(int &x, int &y)
{
    for(int i=0; i<wszystkieFigury.size(); i++) {
        if(wszystkieFigury[i]->getX() == x && wszystkieFigury[i]->getY() == y
                && wszystkieFigury[i]->getPlayer() == this->player) return false;
    }

    if(this->x == x && this->y == y) return false;
    else if(x-this->x == y-this->y || x-this->x == (y-this->y)*(-1)) {
        if(x > this->x) {
            if(y > this->y) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getX() > this->x) && (wszystkieFigury[i]->getX() < x)
                            && (wszystkieFigury[i]->getY() > this->y) && (wszystkieFigury[i]->getY() < y)
                            && (wszystkieFigury[i]->getX()-this->x == wszystkieFigury[i]->getY()-this->y)
                            && (x > this->x) && (y > this->y) && (i != this->id)) {
                        return false;
                    }
                }
            } else {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getX() > this->x) && (wszystkieFigury[i]->getX() < x)
                            && (wszystkieFigury[i]->getY() > y) && (wszystkieFigury[i]->getY() < this->y)
                            && (wszystkieFigury[i]->getX()-this->x == this->y-wszystkieFigury[i]->getY())
                            && (x > this->x) && (y < this->y) && (i != this->id)) return false;
                }
            }
        } else {
            if(y > this->y) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getX() > x) && (wszystkieFigury[i]->getX() < this->x)
                            && (wszystkieFigury[i]->getY() > this->y) && (wszystkieFigury[i]->getY() < y)
                            && (this->x-wszystkieFigury[i]->getX() == wszystkieFigury[i]->getY()-this->y)
                            && (x < this->x) && (y > this->y) && (i != this->id)) return false;
                }
            } else {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getX() > x) && (wszystkieFigury[i]->getX() < this->x)
                            && (wszystkieFigury[i]->getY() > y) && (wszystkieFigury[i]->getY() < this->y)
                            && (this->x-wszystkieFigury[i]->getX() == this->y-wszystkieFigury[i]->getY())
                            && (x < this->x) && (y < this->y) && (i != this->id)) return false;
                }
            }
        }
        return true;
    } else return false;
}
