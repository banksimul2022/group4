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
    explicit KorttiMain(QString kortinnumero,QString pin, QWidget *parent = nullptr);
    ~KorttiMain();

private slots:

    void on_btn_20_clicked();

    void on_btn_40_clicked();

    void on_btn_50_clicked();

    void on_btn_100_clicked();

    void on_btn_custom_clicked();

    void on_btn_logout_clicked();

private:
    Ui::KorttiMain *ui;
};

#endif // KORTTIMAIN_H
