#include "figura.h"

Figura::Figura(QWidget *parent, int x, int y, int player) : Pole(parent, x, y)
{
    this->player = player;
    wszystkieFigury.push_back(this);

    this->id = wszystkieFigury.size()-1;
}

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

QVector<Figura*> Figura::wszystkieFigury;

void Figura::mousePressEvent(QMouseEvent *ev)
{
    offset = ev->pos();
}

void Figura::mouseMoveEvent(QMouseEvent *ev)
{
    this->move(mapToParent(ev->pos()) - offset);
}

void Figura::mouseReleaseEvent(QMouseEvent *ev)
{
    int x = (mapToParent(ev->pos()).x() - offset.x() + 40)/80;
    int y = (mapToParent(ev->pos()).y() - offset.y() + 40)/80;

    if(x>=0 && x<=7 && y>=0 && y<=7) {
        if(this->sprawdzRuch(x, y)) {
            this->x = x;
            this->y = y;
            this->move(x*80, y*80);
        } else {
            this->move(this->x*80, this->y*80);
        }
    } else {
        this->move(this->x*80, this->y*80);
    }

}