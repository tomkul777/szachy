#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("Chess by Tomasz Kula & Agata Szczypińska");
    this->setFixedSize(900, 640);

    b_nowaGra = new QPushButton(this);
    b_nowaGra->setText("Nowa Gra");
    b_nowaGra->setGeometry(700, 100, 140, 30);

    b_poddajSie = new QPushButton(this);
    b_poddajSie->setText("Poddaj Się");
    b_poddajSie->setGeometry(700, 180, 140, 30);

    connect(b_nowaGra, SIGNAL (released()), this, SLOT (nowaGra()));
    connect(b_poddajSie, SIGNAL (released()), this, SLOT (poddajSie()));

    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nowaGra()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::poddajSie()
{
    Figura::koniec(this);
}
