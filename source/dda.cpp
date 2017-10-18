#include "dda.h"
#include "ui_dda.h"
#include "dda_paint.h"

DDA::DDA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DDA)
{
    ui->setupUi(this);
    setWindowTitle("DDA");
}

DDA::~DDA()
{
    delete ui;
}

void DDA::on_DrawBtn_clicked()
{
    dda_paint ddaimg(this);
    ddaimg.x1=ui->x1->text().toInt();
    ddaimg.x2=ui->x2->text().toInt();
    ddaimg.y1=ui->y1->text().toInt();
    ddaimg.y2=ui->y2->text().toInt();
    ddaimg.exec();
}
