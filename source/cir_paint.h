#ifndef CIR_PAINT_H
#define CIR_PAINT_H

#include <QDialog>

namespace Ui {
class cir_paint;
}

class cir_paint : public QDialog
{
    Q_OBJECT

public:
    explicit cir_paint(QWidget *parent = 0);
    ~cir_paint();
    int x0,y0,r;
    int x,y;
    int k=-1;
    float p;

private:
    Ui::cir_paint *ui;
    int id1, id2, id3;
    QPixmap pix;

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

};

#endif // CIR_PAINT_H
