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
    static QVector<Figura*> wszystkieFigury;

public:
    Figura(QWidget *parent, int x, int y, int player);
    ~Figura();
    int getX();
    int getY();
    int getPlayer();
    int getId();
    void setId(int id);
    QString getNazwa();
    virtual bool sprawdzRuch(int x, int y) = 0;
    bool zbijanie(Figura *f);

    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // FIGURA_H
