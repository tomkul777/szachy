#include "hetman.h"
#include <QDebug>

Hetman::Hetman(QWidget *parent, int x, int y, int player) : Figura(parent, x, y, player)
{
    this->nazwa = "Hetman";

    if(player == 1) this->setPixmap(QPixmap(":/biale/PNG/hetman_b.png"));
    else this->setPixmap(QPixmap(":/czarne/PNG/hetman_c.png"));

    this->setGeometry(x*80, y*80, 80, 80);
}

bool Hetman::sprawdzRuch(int &x, int &y)
{
    for(int i=0; i<wszystkieFigury.size(); i++) {
        if(wszystkieFigury[i]->getX() == x && wszystkieFigury[i]->getY() == y
                && wszystkieFigury[i]->getPlayer() == this->player) return false;
    }

    if(this->x == x && this->y == y) return false;
    else if((x-this->x == y-this->y) || (x-this->x == (y-this->y)*(-1)) ||
            (x-this->x == 0) || (y-this->y == 0)) {
        if(x-this->x == 0) {
            int minY = y<this->y ? y : this->y;
            int maxY = y>this->y ? y : this->y;

            for(int i=0; i<wszystkieFigury.size(); i++) {
                if((wszystkieFigury[i]->getY() > minY) && (wszystkieFigury[i]->getY() < maxY)
                        && (wszystkieFigury[i]->getX()-x == 0)) return false;
            }
        } else if(y-this->y == 0) {
            int minX = x<this->x ? x : this->x;
            int maxX = x>this->x ? x : this->x;

            for(int i=0; i<wszystkieFigury.size(); i++) {
                if((wszystkieFigury[i]->getX() > minX) && (wszystkieFigury[i]->getX() < maxX)
                        && (wszystkieFigury[i]->getY()-y == 0)) return false;
            }
        } else if(x > this->x) {
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

bool operator ==(Hetman &h1, Hetman &h2)
{
    return (h1.getId() == h2.getId());
}
