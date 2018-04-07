#include "figura.h"
#include <QDebug>

Figura::Figura(QWidget *parent, int x, int y, int player) : Pole(parent, x, y)
{
    czyRuszany = false;

    this->player = player;
    wszystkieFigury.push_back(this);

    this->id = wszystkieFigury.size()-1;
}

Figura::~Figura()
{
    wszystkieFigury.remove(this->id);
    for(int i=this->id; i<wszystkieFigury.size(); i++) {
        wszystkieFigury[i]->setId(i);
    }

    //qDebug() << "USUWAMY XD, ilosc = " << wszystkieFigury.size();
}

QVector<Figura*> Figura::wszystkieFigury;
int Figura::aktualnyRuch = 1;

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
        f->~Figura();

        if(this->czyRuszany == false) this->czyRuszany = true;

        this->x = f->getX();
        this->y = f->getY();
        this->move(f->getX()*80, f->getY()*80);
        //qDebug() << "ZBIJAM";
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

    //if(aktualnyRuch == 2) qDebug() << "Czarny krol(" << wszystkieFigury[idKrol]->getX() << ", " << wszystkieFigury[idKrol]->getY() << ")";

    for(int i=0; i<wszystkieFigury.size(); i++) {
        if(wszystkieFigury[i]->getPlayer() != aktualnyRuch && wszystkieFigury[i]->getX() != x && wszystkieFigury[i]->getY() != y) {
            int xx = wszystkieFigury[idKrol]->getX();
            int yy = wszystkieFigury[idKrol]->getY();

            if(wszystkieFigury[i]->sprawdzRuch(xx, yy)) {
                return true;
            }
        }
    }
    return false;
}

void Figura::mousePressEvent(QMouseEvent *ev)
{
    if(this->player == aktualnyRuch) offset = ev->pos();
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
                                    if(this->czyRuszany == false) this->czyRuszany = true;
                                    zbijanie(wszystkieFigury[i]);
                                    this->move(x*80, y*80);

                                    if(aktualnyRuch == 1) aktualnyRuch = 2;
                                    else aktualnyRuch = 1;
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
