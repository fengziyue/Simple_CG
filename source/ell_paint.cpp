#include "ell_paint.h"
#include "ui_ell_paint.h"

#include <qpainter.h>

ell_paint::ell_paint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ell_paint)
{
    ui->setupUi(this);
    setFixedSize(402,402);
    setWindowTitle("Ellipse");

    pix = QPixmap(400, 400);
    pix.fill(Qt::white);
    id1 = startTimer(100);
}

ell_paint::~ell_paint()
{
    delete ui;
}

void ell_paint::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);

    if(k==-1)
    {
        p1=ry*ry-rx*rx*ry+(rx*rx/4);
        x=0;
        y=ry;

        pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
        pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
        pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
        pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);

        pp.drawLine(QPointF(0, 200), QPointF(400, 200));
        pp.drawLine(QPointF(200, 0), QPointF(200, 400));
        k=1;
    }
    else
    {
        if(ry*ry*x<rx*rx*y)
        {
            if(p1<0)
            {
                p1+=2*ry*ry*x+3*ry*ry;
                x++;
                pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);
            }
            else
            {
                p1+=2*ry*ry*x+3*ry*ry-2*rx*rx*y+2*rx*rx;
                x++;
                y--;
                pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
                pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
                pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);
            }
            p2=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
        }
        else
        {
            if(y>0)
            {
                if(p2>0)
                {
                    p2+=-2*rx*rx*(y-1)+rx*rx;
                    y--;
                    pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
                    pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
                    pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
                    pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);
                }
                else
                {
                    x++;
                    y--;
                    p2+=2*ry*ry*x-2*rx*rx*y+rx*rx;
                    pp.drawRect((100+round( x+x0))*2,(99-round( y+y0))*2,2,2);
                    pp.drawRect((100+round(-x+x0))*2,(99-round( y+y0))*2,2,2);
                    pp.drawRect((100+round( x+x0))*2,(99-round(-y+y0))*2,2,2);
                    pp.drawRect((100+round(-x+x0))*2,(99-round(-y+y0))*2,2,2);
                }
            }
        }
    }

    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
void ell_paint::timerEvent(QTimerEvent *event)
{
   if (event->timerId() == id1) {
       update();
   }
}
