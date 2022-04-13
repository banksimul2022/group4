#ifndef KORTTIMAIN_H
#define KORTTIMAIN_H

#include <QDialog>

namespace Ui {
class KorttiMain;
}

class KorttiMain : public QDialog
{
    Q_OBJECT

public:
    explicit KorttiMain(QString kNum,QString kPin, QWidget *parent = nullptr);
    ~KorttiMain();

private slots:
    void on_btnSaldo_clicked();

private:
    Ui::KorttiMain *ui;
};

#endif // KORTTIMAIN_H
