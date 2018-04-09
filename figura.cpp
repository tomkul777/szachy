#include "figura.h"
#include <QDebug>

Figura::Figura(QWidget *parent, int x, int y, int player) : Pole(parent, x, y)
{
    czyRuszany = false;

    this->player = player;
    wszystkieFigury.push_back(this);

    this->id = wszystkieFigury.size()-1;

    if(this->logi == NULL) this->logi = new Logi(parent);
}

Figura::~Figura()
{
    wszystkieFigury.remove(this->id);
    for(int i=this->id; i<wszystkieFigury.size(); i++) {
        wszystkieFigury[i]->setId(i);
    }
}

QVector<Figura*> Figura::wszystkieFigury;
int Figura::aktualnyRuch = 1;
Logi* Figura::logi;

int Figura::getX()
{
    return this->x;
}

int Figura::getY()
{
    return this->y;
}

int Figura::getPlayer()
{
    return this->player;
}

int Figura::getId()
{
    return this->id;
}

void Figura::setId(int id)
{
    this->id = id;
}

QString Figura::getNazwa()
{
    return this->nazwa;
}

bool Figura::getCzyRuszany()
{
    return this->czyRuszany;
}

void Figura::setX(int x)
{
    this->x = x;
}

void Figura::setY(int y)
{
    this->y = y;
}

void Figura::zbijanie(Figura *f)
{
        *logi << this << " zbija " << f << "\n";

        f->~Figura();

        if(this->czyRuszany == false) this->czyRuszany = true;

        this->x = f->getX();
        this->y = f->getY();
        this->move(f->getX()*80, f->getY()*80);
}

bool Figura::szach(int x, int y)
{
    int idKrol;

    for(int i=0; i<wszystkieFigury.size(); i++) {
        if(wszystkieFigury[i]->getNazwa() == "Krol" && wszystkieFigury[i]->getPlayer() == aktualnyRuch) {
            idKrol = i;
            break;
        }
    }

    int xx = wszystkieFigury[idKrol]->getX();
    int yy = wszystkieFigury[idKrol]->getY();

    for(int i=0; i<wszystkieFigury.size(); i++) {
        if(wszystkieFigury[i]->getPlayer() != aktualnyRuch && wszystkieFigury[i]->getX() != x && wszystkieFigury[i]->getY() != y) {
            if(wszystkieFigury[i]->sprawdzRuch(xx, yy)) {
                return true;
            }
        }
    }
    return false;
}

bool Figura::mat()
{
    if(szach(-1, -1)) {
        *logi << "SZACH\n";

        for(int i=0; i<wszystkieFigury.size(); i++) {
            if(wszystkieFigury[i]->getPlayer() == aktualnyRuch) {
                int stareX = wszystkieFigury[i]->getX();
                int stareY = wszystkieFigury[i]->getY();

                qDebug() << wszystkieFigury[i]->getNazwa() << " " << wszystkieFigury[i]->getId();
                for(int a=0; a<8; a++) {
                    for(int b=0; b<8; b++) {
                        if(wszystkieFigury[i]->sprawdzRuch(b, a)) {
                            wszystkieFigury[i]->setX(b);
                            wszystkieFigury[i]->setY(a);

                            bool czysto1 = true;

                            for(int j=0; j<wszystkieFigury.size(); j++) {
                                int testX = wszystkieFigury[j]->getX();
                                int testY = wszystkieFigury[j]->getY();

                                if(wszystkieFigury[j]->getX() == b && wszystkieFigury[j]->getY() == a
                                        && i != j && wszystkieFigury[j]->getPlayer() != aktualnyRuch) {
                                    czysto1 = false;

                                    wszystkieFigury[j]->setX(-5);
                                    wszystkieFigury[j]->setY(-5);

                                    if(!szach(-1, -1)) {
                                        wszystkieFigury[j]->setX(testX);
                                        wszystkieFigury[j]->setY(testY);
                                        wszystkieFigury[i]->setX(stareX);
                                        wszystkieFigury[i]->setY(stareY);
                                        return false;
                                    }

                                    wszystkieFigury[j]->setX(testX);
                                    wszystkieFigury[j]->setY(testY);
                                    break;
                                }
                            }

                            if(czysto1 == true) {
                                if(!szach(-1, -1)) {
                                    wszystkieFigury[i]->setX(stareX);
                                    wszystkieFigury[i]->setY(stareY);
                                    return false;
                                }
                            }

                            wszystkieFigury[i]->setX(stareX);
                            wszystkieFigury[i]->setY(stareY);
                        }
                    }
                }
                wszystkieFigury[i]->setX(stareX);
                wszystkieFigury[i]->setY(stareY);
                qDebug() << "===============";
            }
        }
        if(aktualnyRuch == 2) *logi << "KONIEC GRY!!! WYGRYWAJĄ BIAŁE, GRATULACJE\n";
        else *logi << "KONIEC GRY!!! WYGRYWAJĄ CZARNE, GRATULACJE\n";

        return true;
    } else return false;
}

void Figura::mousePressEvent(QMouseEvent *ev)
{
    if(this->player == aktualnyRuch) offset = ev->pos();
    //qDebug() << "ID=" << this->getId() << "  x=" << this->x << ", y=" << this->y;
}

void Figura::mouseMoveEvent(QMouseEvent *ev)
{
    if(this->player == aktualnyRuch) this->move(mapToParent(ev->pos()) - offset);
}

void Figura::mouseReleaseEvent(QMouseEvent *ev)
{        
    if(this->player == aktualnyRuch) {
        int x = (mapToParent(ev->pos()).x() - offset.x() + 40)/80;
        int y = (mapToParent(ev->pos()).y() - offset.y() + 40)/80;

        if(x>=0 && x<=7 && y>=0 && y<=7) {
            if(this->sprawdzRuch(x, y)) {
                bool czysto = true;

                //SPRAWDZANIE ZBIJANIA
                for(int i=0; i<wszystkieFigury.size(); i++) {
                    if((wszystkieFigury[i]->getX() == x) && (wszystkieFigury[i]->getY() == y)
                            && (i != this->id)) {
                        czysto = false;

                        if(this->player == wszystkieFigury[i]->getPlayer()) {
                            this->move(this->x*80, this->y*80);
                        } else {
                            if(wszystkieFigury[i]->getNazwa() != "Krol") {
                                int staryX = this->x;
                                int staryY = this->y;
                                this->x = x;
                                this->y = y;

                                if(szach(x, y)) {
                                    this->x = staryX;
                                    this->y = staryY;
                                    this->move(this->x*80, this->y*80);
                                    qDebug() << "Nie mozesz tu isc bo będzie szach ;(";
                                } else {
                                    qDebug() << "Ok, tu mozesz";
                                    int testX = wszystkieFigury[i]->getX();
                                    int testY = wszystkieFigury[i]->getY();

                                    //zbijanie(wszystkieFigury[i]);
                                    //this->move(x*80, y*80);

                                    wszystkieFigury[i]->setX(-5);
                                    wszystkieFigury[i]->setY(-5);

                                    if(szach(-1, -1)) {
                                        qDebug() << "a jednak drugi szach :(";
                                        this->x = staryX;
                                        this->y = staryY;
                                        this->move(staryX*80, staryY*80);
                                        wszystkieFigury[i]->setX(testX);
                                        wszystkieFigury[i]->setY(testY);
                                        break;
                                    }

                                    wszystkieFigury[i]->setX(testX);
                                    wszystkieFigury[i]->setY(testY);

                                    if(!szach(x, y)){
                                        qDebug() << "brak szacha przy zbijaniu";
                                        zbijanie(wszystkieFigury[i]);
                                        this->move(x*80, y*80);

                                        if(this->czyRuszany == false) this->czyRuszany = true;
                                        if(aktualnyRuch == 1) aktualnyRuch = 2;
                                        else aktualnyRuch = 1;

                                        if(mat()) qDebug() << "TUTAJ POWINIEN BYC KONIEC GRY";
                                    }
                                }
                            } else {
                                this->move(this->x*80, this->y*80);
                            }
                        }
                        break;
                    }
                }
                //--------------------

                if(czysto) {
                    int staryX = this->x;
                    int staryY = this->y;

                    //MOZLIWOSC ROSZADY
                    if(this->nazwa == "Krol" && y-this->y == 0 && this->czyRuszany == false
                            && (x-this->x == 2 || x-this->x == -2)) {
                        bool czyRoszada = true;

                        if(x-this->x == 2) {
                            for(int i=0; i<wszystkieFigury.size(); i++) {
                                if(wszystkieFigury[i]->getX() == 7 && wszystkieFigury[i]->getY() == this->y
                                        && wszystkieFigury[i]->getCzyRuszany() == false && wszystkieFigury[i]->getNazwa() == "Wieza") {
                                    for(int j=0; j<wszystkieFigury.size(); j++) {
                                        if(wszystkieFigury[j]->getX() > this->x && wszystkieFigury[j]->getX() < 7
                                                && wszystkieFigury[j]->getY() == this->y && i != this->id) {
                                            czyRoszada = false;
                                            break;
                                        }
                                    }

                                    if(czyRoszada && !szach(-1, -1)) {
                                        int testX = wszystkieFigury[i]->getX();

                                        this->x = x;
                                        this->y = y;
                                        wszystkieFigury[i]->setX(x-1);

                                        if(!szach(-1, -1)) {
                                            qDebug() << "Lecimy z roszadka";
                                            wszystkieFigury[i]->move(wszystkieFigury[i]->getX()*80, wszystkieFigury[i]->getY()*80);

                                            if(this->czyRuszany == false) this->czyRuszany = true;
                                            this->move(x*80, y*80);

                                            if(aktualnyRuch == 1) {
                                                *logi << "Białe robią roszadę\n";
                                                aktualnyRuch = 2;
                                            } else {
                                                *logi << "Czarne robią roszadę\n";
                                                aktualnyRuch = 1;
                                            }
                                        } else {
                                            this->x = staryX;
                                            this->y = staryY;
                                            wszystkieFigury[i]->setX(testX);
                                        }
                                    } else {
                                        this->move(staryX*80, staryY*80);
                                    }
                                    break;
                                } else {
                                    this->move(staryX*80, staryY*80);
                                }
                            }
                        } else if(x-this->x == -2) {
                            for(int i=0; i<wszystkieFigury.size(); i++) {
                                if(wszystkieFigury[i]->getX() == 0 && wszystkieFigury[i]->getY() == this->y
                                        && wszystkieFigury[i]->getCzyRuszany() == false && wszystkieFigury[i]->getNazwa() == "Wieza") {
                                    for(int i=0; i<wszystkieFigury.size(); i++) {
                                        if(wszystkieFigury[i]->getX() > 0 && wszystkieFigury[i]->getX() < this->x
                                                && wszystkieFigury[i]->getY() == this->y && i != this->id) {
                                            czyRoszada = false;
                                            break;
                                        }
                                    }

                                    if(czyRoszada && !szach(-1, -1)) {
                                        int testX = wszystkieFigury[i]->getX();

                                        this->x = x;
                                        this->y = y;
                                        wszystkieFigury[i]->setX(x+1);

                                        if(!szach(-1, -1)) {
                                            //qDebug() << "Lecimy z roszadka";
                                            wszystkieFigury[i]->move(wszystkieFigury[i]->getX()*80, wszystkieFigury[i]->getY()*80);

                                            if(this->czyRuszany == false) this->czyRuszany = true;
                                            this->move(x*80, y*80);

                                            if(aktualnyRuch == 1) {
                                                *logi << "Białe robią roszadę\n";
                                                aktualnyRuch = 2;
                                            } else {
                                                *logi << "Czarne robią roszadę\n";
                                                aktualnyRuch = 1;
                                            }
                                        } else {
                                            this->x = staryX;
                                            this->y = staryY;
                                            wszystkieFigury[i]->setX(testX);
                                        }
                                    } else {
                                        this->move(staryX*80, staryY*80);
                                    }
                                    break;
                                } else {
                                    this->move(staryX*80, staryY*80);
                                }
                            }
                        } //-----------------------------------------
                    } else {
                        int staryX = this->x;
                        int staryY = this->y;
                        this->x = x;
                        this->y = y;

                        if(szach(-1, -1)) {
                            this->x = staryX;
                            this->y = staryY;
                            this->move(this->x*80, this->y*80);
                            qDebug() << "Nie mozesz tu isc bo będzie szach ;(";
                        } else {
                            qDebug() << "Ok, tu mozesz";

                            if(this->czyRuszany == false) this->czyRuszany = true;
                            this->move(x*80, y*80);

                            if(aktualnyRuch == 1) aktualnyRuch = 2;
                            else aktualnyRuch = 1;

                            if(mat()) qDebug() << "TUTAJ POWINIEN BYC KONIEC GRY";
                        }
                    }
                }
            } else {
                this->move(this->x*80, this->y*80);
            }
        } else {
            this->move(this->x*80, this->y*80);
        }
    }
}

Logi& operator <<(Logi &l, Figura *f)
{
    l.insertPlainText(f->getNazwa());
    return l;
}

Logi& operator <<(Logi &l, QString s)
{
    l.insertPlainText(s);
    return l;
}
