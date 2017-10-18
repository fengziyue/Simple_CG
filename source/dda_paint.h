#ifndef DDA_PAINT_H
#define DDA_PAINT_H

#include <QDialog>

namespace Ui {
class dda_paint;
}

class dda_paint : public QDialog
{
    Q_OBJECT

public:
    explicit dda_paint(QWidget *parent = 0);
    ~dda_paint();
    int x1,x2,y1,y2;
    int dx,dy,steps;
    int k=-1;
    float xIncrement,yIncrement,x,y;
private:
    Ui::dda_paint *ui;
    int id1, id2, id3;
    QPixmap pix;


protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

};

#endif // DDA_PAINT_H
