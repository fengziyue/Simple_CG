#ifndef DDA_H
#define DDA_H

#include <QDialog>

namespace Ui {
class DDA;
}

class DDA : public QDialog
{
    Q_OBJECT

public:
    explicit DDA(QWidget *parent = 0);
    ~DDA();

private slots:
    void on_DrawBtn_clicked();

private:
    Ui::DDA *ui;
};

#endif // DDA_H
