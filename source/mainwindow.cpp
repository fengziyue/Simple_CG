#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dda.h"
#include "bresenham.h"
#include "circle.h"
#include "ellipse.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Fzyue's CG Program");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QDialog *dlg = new QDialog(this);
    //dlg->show();
    DDA dda(this);
    dda.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Bresenham bre(this);
    bre.exec();
}

void MainWindow::on_circle_clicked()
{
    Circle cir(this);
    cir.exec();
}

void MainWindow::on_ellipse_clicked()
{
    Ellipse ell(this);
    ell.exec();
}
