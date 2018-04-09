#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "pole.h"
#include "figura.h"
#include "wieza.h"
#include "kon.h"
#include "goniec.h"
#include "krol.h"
#include "hetman.h"
#include "pionek.h"
#include "logi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void nowaGra();
    void poddajSie();

private:
    Ui::MainWindow *ui;
    QVector<Figura*> figury;
    QPushButton *b_nowaGra;
    QPushButton *b_poddajSie;

};

#endif // MAINWINDOW_H
