#include "bre_paint.h"
#include "ui_bre_paint.h"
#include <qpainter.h>
#include"bresenham.h"

bre_paint::bre_paint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bre_paint)
{
    ui->setupUi(this);
    setFixedSize(402,402);
    setWindowTitle("Bresenham");

    pix = QPixmap(400, 400);
    pix.fill(Qt::white);
    id1 = startTimer(100);
}

bre_paint::~bre_paint()
{
    delete ui;
}
void bre_paint::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);

    if(k==-1)
    {
        dx=fabs(x2-x1);
        dy=fabs(y2-y1);
        p=2*dy-dx;
        twoDy=2*dy;
        twoDyMinusDx=2*(dy-dx);

        if(x1>x2)
        {
            x=x2;
            y=y2;
            x2=x1;
        }
        else
        {
            x=x1;
            y=y1;
        }

        pp.drawRect((100+round(x))*2,(99-round(y))*2,2,2);
        pp.drawLine(QPointF(0, 200), QPointF(400, 200));
        pp.drawLine(QPointF(200, 0), QPointF(200, 400));
        k=1;
    }
    else
    {
        if(x<x2)
        {
            x++;
            if(p<0)
                p+=twoDy;
            else
            {
                y++;
                p+=twoDyMinusDx;
            }
            pp.drawRect((100+round(x))*2,(99-round(y))*2,2,2);
        }
    }

    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
void bre_paint::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id1) {
        update();
    }
}
