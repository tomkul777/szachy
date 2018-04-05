#ifndef FIGURA_H
#define FIGURA_H

#include <QMouseEvent>

#include "pole.h"

class Figura : public Pole
{
private:
    QPoint offset;

protected:
    int player;
    int id;
    QString nazwa;
    bool czyRuszany;
    static QVector<Figura*> wszystkieFigury;

public:
    Figura(QWidget *parent, int x, int y, int player);
    ~Figura();
    virtual bool sprawdzRuch(int x, int y) = 0;
    bool zbijanie(Figura *f);
    void promocja(Figura *f);

    int getX();
    int getY();
    int getPlayer();
    int getId();
    QString getNazwa();
    bool getCzyRuszany();

    void setX(int x);
    void setY(int y);
    void setId(int id);

    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // FIGURA_H
