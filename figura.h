#ifndef FIGURA_H
#define FIGURA_H

#include <QMouseEvent>

#include "pole.h"
#include "logi.h"

class Figura : public Pole
{
private:
    QPoint offset; 
    static QLabel *im_aktualnyRuch;
    static QLabel *t_aktualnyRuch;

protected:
    static QVector<Figura *> wszystkieFigury;
    static bool czyKoniec;
    QWidget *w;
    int player;
    int id;
    QString nazwa;
    bool czyRuszany;

public:
    Figura(QWidget *parent, int x, int y, int player);
    ~Figura();

    static Logi *logi;
    static int aktualnyRuch;

    virtual bool sprawdzRuch(int &x, int &y) = 0;
    void zbijanie(Figura *f);
    bool szach(int x, int y);
    bool mat();
    static void koniec(QWidget *w);

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

Logi& operator <<(Logi &l, Figura *f);
Logi& operator <<(Logi &l, QString s);

#endif // FIGURA_H
