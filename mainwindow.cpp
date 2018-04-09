#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("Chess by Tomasz Kula & Agata Szczypińska");
    this->setFixedSize(900, 640);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
