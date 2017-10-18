#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QDialog>

namespace Ui {
class Ellipse;
}

class Ellipse : public QDialog
{
    Q_OBJECT

public:
    explicit Ellipse(QWidget *parent = 0);
    ~Ellipse();

private slots:
    void on_drawBtn_clicked();

private:
    Ui::Ellipse *ui;
};

#endif // ELLIPSE_H
