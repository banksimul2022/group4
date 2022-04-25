#ifndef KORTTIMAIN_H
#define KORTTIMAIN_H

#include <QDialog>
#include <QDebug>
#include "dllrestapi.h"

namespace Ui {
class KorttiMain;
}

class KorttiMain : public QDialog
{
    Q_OBJECT

public:
    explicit KorttiMain(QByteArray webtoken,QString kortinnumero, QWidget *parent = nullptr);
    ~KorttiMain();
    void TapahtumatLista();

private slots:

    void on_btn_20_clicked();

    void on_btn_40_clicked();

    void on_btn_50_clicked();

    void on_btn_100_clicked();

    void on_btn_custom_clicked();

    void on_btn_logout_clicked();

    void tiliSLOT(QString);

private:
    Ui::KorttiMain *ui;
    DLLRestAPI *objectDLLRestAPI;
    QString Tilinumero;
};

#endif // KORTTIMAIN_H
