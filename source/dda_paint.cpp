#include "dda_paint.h"
#include "ui_dda_paint.h"
#include <qpainter.h>
#include "dda.h"

dda_paint::dda_paint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dda_paint)
{
    ui->setupUi(this);
    setFixedSize(402,402);
    setWindowTitle("DDA");

    pix = QPixmap(400, 400);
    pix.fill(Qt::white);
    id1 = startTimer(100);
}

dda_paint::~dda_paint()
{
    delete ui;
}
void dda_paint::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);
    if(k==-1)
    {
        x=x1;
        y=y1;
        dx=x2-x1;
        dy=y2-y1;
        if(fabs(dx)>fabs(dy))
            steps=fabs(dx);
        else
            steps=fabs(dy);
        xIncrement=float(dx)/float(steps);
        yIncrement=float(dy)/float(steps);
        pp.drawRect((100+round(x))*2,(99-round(y))*2,2,2);
        pp.drawLine(QPointF(0, 200), QPointF(400, 200));
        pp.drawLine(QPointF(200, 0), QPointF(200, 400));
        k=0;
    }
    else
    {
        if(k<steps)
        {
            x+=xIncrement;
            y+=yIncrement;
            pp.drawRect((100+round(x))*2,(99-round(y))*2,2,2);
            k++;
        }
    }

    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
void dda_paint::timerEvent(QTimerEvent *event)
{
   if (event->timerId() == id1) {
       update();
   }
}
