#include "pionek.h"
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
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(this->player == wszystkieFigury[i]->getPlayer()) return false;
                            else {
                                //TUTAJ BEDZIE BICIE
                                if(zbijanie(wszystkieFigury[i])) {
                                    return true;
                                } else return false;
                            }
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
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(this->player == wszystkieFigury[i]->getPlayer()) return false;
                            else {
                                //TUTAJ BEDZIE BICIE
                                if(zbijanie(wszystkieFigury[i])) {
                                    return true;
                                } else return false;
                            }
                        }
                    } return false;
                } else return false;
            } else if((y-this->y == -2) && (x == this->x)) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getY() == y+1) && (wszystkieFigury[i]->getX() == x)
                            && (i != this->id)) return false;
                }
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
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(this->player == wszystkieFigury[i]->getPlayer()) return false;
                            else {
                                //TUTAJ BEDZIE BICIE
                                if(zbijanie(wszystkieFigury[i])) {
                                    return true;
                                } else return false;
                            }
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
                    return true;
                } else if((x-this->x == 1) || (x-this->x == -1)) {
                    for(int i=0; i<wszystkieFigury.size(); i++) {
                        if((wszystkieFigury[i]->getY() == y) && (wszystkieFigury[i]->getX() == x)
                                && (i != this->id)) {
                            if(this->player == wszystkieFigury[i]->getPlayer()) return false;
                            else {
                                //TUTAJ BEDZIE BICIE
                                if(zbijanie(wszystkieFigury[i])) {
                                    return true;
                                } else return false;
                            }
                        }
                    } return false;
                } else return false;
            } else if((y-this->y == 2) && (x == this->x)) {
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getY() == y-1) && (wszystkieFigury[i]->getX() == x)
                            && (i != this->id)) return false;
                }
                return true;
            } else return false;
        }
    }
}

bool operator ==(Pionek &p1, Pionek &p2)
{
    return (p1.getId() == p2.getId());
}
