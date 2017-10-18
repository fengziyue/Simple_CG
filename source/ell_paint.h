#ifndef ELL_PAINT_H
#define ELL_PAINT_H

#include <QDialog>

namespace Ui {
class ell_paint;
}

class ell_paint : public QDialog
{
    Q_OBJECT

public:
    explicit ell_paint(QWidget *parent = 0);
    ~ell_paint();
    float x0,y0,rx,ry;
    int x,y;
    int k=-1;
    float p1,p2;

private:
    Ui::ell_paint *ui;
    int id1, id2, id3;
    QPixmap pix;

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

};

#endif // ELL_PAINT_H
