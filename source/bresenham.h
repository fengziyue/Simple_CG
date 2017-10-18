#ifndef BRESENHAM_H
#define BRESENHAM_H

#include <QDialog>

namespace Ui {
class Bresenham;
}

class Bresenham : public QDialog
{
    Q_OBJECT

public:
    explicit Bresenham(QWidget *parent = 0);
    ~Bresenham();

private slots:
    void on_drawbtn_clicked();

private:
    Ui::Bresenham *ui;
};

#endif // BRESENHAM_H
