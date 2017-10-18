#include "circle.h"
#include "ui_circle.h"
#include "cir_paint.h"

Circle::Circle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Circle)
{
    ui->setupUi(this);
    setWindowTitle("Circle");
}

Circle::~Circle()
{
    delete ui;
}

void Circle::on_drawBtn_clicked()
{
    cir_paint cirimg(this);
    cirimg.x0=ui->x->text().toInt();
    cirimg.y0=ui->y->text().toInt();
    cirimg.r=ui->r->text().toInt();
    cirimg.exec();
}
