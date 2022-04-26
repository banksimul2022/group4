#ifndef KORTTIMAIN_H
#define KORTTIMAIN_H

#include <QDialog>
#include <QDebug>
#include "dllrestapi.h"
#include "tapahtumat.h"

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
    QString Kortinnumero, Tilinumero, Saldo;
    QByteArray WebToken;
    QList<Tapahtumat*> lista;
    Tapahtumat t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;



private slots:

    void on_btn_20_clicked();

    void on_btn_40_clicked();

    void on_btn_50_clicked();

    void on_btn_100_clicked();

    void on_btn_custom_clicked();

    void on_btn_logout_clicked();

    void tiliSLOT(QString);

    void saldoSLOT(QString);

    void tilitapahtumaSLOT(QString);

    void on_tiltap_btn_clicked();

private:
    Ui::KorttiMain *ui;
    DLLRestAPI *objectDLLRestAPI;


};

#endif // KORTTIMAIN_H
