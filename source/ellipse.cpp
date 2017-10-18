#include "ellipse.h"
#include "ui_ellipse.h"
#include "ell_paint.h"

Ellipse::Ellipse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ellipse)
{
    ui->setupUi(this);
    setWindowTitle("Ellipse");
}

Ellipse::~Ellipse()
{
    delete ui;
}

void Ellipse::on_drawBtn_clicked()
{
    ell_paint ellimg(this);
    ellimg.x0=ui->x0->text().toInt();
    ellimg.y0=ui->y0->text().toInt();
    ellimg.rx=ui->rx->text().toInt();
    ellimg.ry=ui->ry->text().toInt();
    ellimg.exec();
}
