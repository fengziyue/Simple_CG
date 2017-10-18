#ifndef BRE_PAINT_H
#define BRE_PAINT_H

#include <QDialog>

namespace Ui {
class bre_paint;
}

class bre_paint : public QDialog
{
    Q_OBJECT

public:
    explicit bre_paint(QWidget *parent = 0);
    ~bre_paint();
    int x1,y1,x2,y2;
    int dx,dy;
    int p;
    int twoDy,twoDyMinusDx;
    int x,y;
    int k=-1;

private:
    Ui::bre_paint *ui;
    int id1, id2, id3;
    QPixmap pix;

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

};

#endif // BRE_PAINT_H
