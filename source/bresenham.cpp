#include "bresenham.h"
#include "ui_bresenham.h"
#include "bre_paint.h"

Bresenham::Bresenham(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bresenham)
{
    ui->setupUi(this);
    setWindowTitle("Bresenham");
}

Bresenham::~Bresenham()
{
    delete ui;
}

void Bresenham::on_drawbtn_clicked()
{
    bre_paint breimg(this);
    breimg.x1=ui->x1->text().toInt();
    breimg.x2=ui->x2->text().toInt();
    breimg.y1=ui->y1->text().toInt();
    breimg.y2=ui->y2->text().toInt();
    breimg.exec();
}
