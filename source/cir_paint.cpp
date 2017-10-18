#include "cir_paint.h"
#include "ui_cir_paint.h"
#include <qpainter.h>

cir_paint::cir_paint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cir_paint)
{
    ui->setupUi(this);
    setFixedSize(402,402);
    setWindowTitle("Circle");

    pix = QPixmap(400, 400);
    pix.fill(Qt::white);
    id1 = startTimer(100);
}

cir_paint::~cir_paint()
{
    delete ui;
}

void cir_paint::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);

    if(k==-1)
    {
        p=(5/4)-r;
        x=0;
        y=r;

        pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
        pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
        pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
        pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);

        pp.drawRect((100+round( y+x0))*2,(99-round( x+y0))*2,2,2);
        pp.drawRect((100+round( y+x0))*2,(99-round(-x+y0))*2,2,2);
        pp.drawRect((100+round(-y+x0))*2,(99-round( x+y0))*2,2,2);
        pp.drawRect((100+round(-y+x0))*2,(99-round(-x+y0))*2,2,2);

        pp.drawLine(QPointF(0, 200), QPointF(400, 200));
        pp.drawLine(QPointF(200, 0), QPointF(200, 400));
        k=1;
    }
    else
    {
        if(x<y)
        {
            if(p<0)
            {
                p+=2*x+3;
                x++;
                pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);

                pp.drawRect((100+round( y+x0))*2,(99-round( x+y0))*2,2,2);
                pp.drawRect((100+round( y+x0))*2,(99-round(-x+y0))*2,2,2);
                pp.drawRect((100+round(-y+x0))*2,(99-round( x+y0))*2,2,2);
                pp.drawRect((100+round(-y+x0))*2,(99-round(-x+y0))*2,2,2);
            }
            else
            {
                p+=2*x+5-2*y;
                x++;
                y--;
                pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);

                pp.drawRect((100+round( y+x0))*2,(99-round( x+y0))*2,2,2);
                pp.drawRect((100+round( y+x0))*2,(99-round(-x+y0))*2,2,2);
                pp.drawRect((100+round(-y+x0))*2,(99-round( x+y0))*2,2,2);
                pp.drawRect((100+round(-y+x0))*2,(99-round(-x+y0))*2,2,2);
            }
        }
    }

    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}

void cir_paint::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id1) {
        update();
    }
}
