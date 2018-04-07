#include "pionek.h"
#include "hetman.h"
#include <QDebug>

Pionek::Pionek(QWidget *parent, int x, int y, int player) : Figura(parent, x, y, player)
{
    this->nazwa = "Pionek";

    if(player == 1) this->setPixmap(QPixmap(":/biale/PNG/pionek_b.png"));
    else this->setPixmap(QPixmap(":/czarne/PNG/pionek_c.png"));

    this->setGeometry(x*80, y*80, 80, 80);
}

bool Pionek::sprawdzRuch(int x, int y)
{
    if(this->x == x && this->y == y) return false;
    else if(player == 1) {
        if(this->czyRuszany) {
            if(y-this->y == -1) {
                if(x == this->x) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) return false;
                    }
                    promocja(x, y);
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(wszystkieFigury[i]->getPlayer() != this->player
                                    && wszystkieFigury[i]->getNazwa() != "Krol") promocja(x, y);
                            return true;
                        }
                    }
                    return false;
                } else return false;
            } else return false;
        } else {
            if(y-this->y == -1) {
                if(x == this->x) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) return false;
                    }
                    promocja(x, y);
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(wszystkieFigury[i]->getPlayer() != this->player
                                    && wszystkieFigury[i]->getNazwa() != "Krol") promocja(x, y);
                            return true;
                        }
                    } return false;
                } else return false;
            } else if((y-this->y == -2) && (x == this->x)) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getY() == y+1) && (wszystkieFigury[i]->getX() == x)
                            && (i != this->id)) return false;
                }
                promocja(x, y);
                return true;
            } else return false;
        }
    } else {
        if(this->czyRuszany) {
            if(y-this->y == 1) {
                if(x == this->x) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) return false;
                    }
                    promocja(x, y);
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(wszystkieFigury[i]->getPlayer() != this->player
                                    && wszystkieFigury[i]->getNazwa() != "Krol") promocja(x, y);
                            return true;
                        }
                    } return false;
                } else return false;
            } else return false;
        } else {
            if(y-this->y == 1) {
                if(x == this->x) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) return false;
                    }
                    promocja(x, y);
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(wszystkieFigury[i]->getPlayer() != this->player
                                    && wszystkieFigury[i]->getNazwa() != "Krol") promocja(x, y);
                            return true;
                        }
                    } return false;
                } else return false;
            } else if((y-this->y == 2) && (x == this->x)) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getY() == y-1) && (wszystkieFigury[i]->getX() == x)
                            && (i != this->id)) return false;
                }
                promocja(x, y);
                return true;
            } else return false;
        }
    }
}

void Pionek::promocja(int x, int y)
{
    if(this->player == 1 && y == 0) {
        wszystkieFigury.push_back(new Hetman(parentWidget(), x, y, 1));
        this->~Figura();
    } else if(this->player == 2 && y == 7) {
        wszystkieFigury.push_back(new Hetman(parentWidget(), x, y, 2));
        this->~Figura();
    }
}

bool operator ==(Pionek &p1, Pionek &p2)
{
    return (p1.getId() == p2.getId());
}
