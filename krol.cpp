#include "krol.h"
#include <QDebug>

Krol::Krol(QWidget *parent, int x, int y, int player) : Figura(parent, x, y, player)
{
    this->nazwa = "Krol";

    if(player == 1) this->setPixmap(QPixmap(":/biale/PNG/krol_b.png"));
    else this->setPixmap(QPixmap(":/czarne/PNG/krol_c.png"));

    this->setGeometry(x*80, y*80, 80, 80);
}

bool Krol::sprawdzRuch(int &x, int &y)
{
    if(this->x == x && this->y == y) return false;
    else if(x-this->x < 2 && x-this->x > -2 && y-this->y < 2 && y-this->y > -2) return true;
    else if(this->czyRuszany == false ) {
        //ROSZADA

        if(y-this->y == 0) {
            if(x-this->x == 2) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if(wszystkieFigury[i]->getX() == 7 && wszystkieFigury[i]->getY() == this->y
                            && wszystkieFigury[i]->getCzyRuszany() == false && wszystkieFigury[i]->getNazwa() == "Wieza") {
                        for(int i=0; i<wszystkieFigury.size(); i++) {
                            if(wszystkieFigury[i]->getX() > this->x && wszystkieFigury[i]->getX() < 7
                                    && wszystkieFigury[i]->getY() == this->y && i != this->id) return false;
                        }
                        wszystkieFigury[i]->setX(x-1);
                        wszystkieFigury[i]->move(wszystkieFigury[i]->getX()*80, wszystkieFigury[i]->getY()*80);
                        return true;
                    }
                }
                return false;
            } else if(x-this->x == -2) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if(wszystkieFigury[i]->getX() == 0 && wszystkieFigury[i]->getY() == this->y
                            && wszystkieFigury[i]->getCzyRuszany() == false && wszystkieFigury[i]->getNazwa() == "Wieza") {
                        for(int i=0; i<wszystkieFigury.size(); i++) {
                            if(wszystkieFigury[i]->getX() > 0 && wszystkieFigury[i]->getX() < this->x
                                    && wszystkieFigury[i]->getY() == this->y && i != this->id) return false;
                        }
                        wszystkieFigury[i]->setX(x+1);
                        wszystkieFigury[i]->move(wszystkieFigury[i]->getX()*80, wszystkieFigury[i]->getY()*80);
                        return true;
                    }
                }
                return false;
            } else return false;
        } else return false;
    } else return false;
}

bool operator ==(Krol &k1, Krol &k2)
{
    return (k1.getId() == k2.getId());
}
