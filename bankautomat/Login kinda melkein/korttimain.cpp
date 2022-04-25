#include "korttimain.h"
#include "ui_korttimain.h"
#include "tapahtumat.h"

#include <QStandardItemModel>

KorttiMain::KorttiMain(QByteArray webtoken, QString kortinnumero, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KorttiMain)
{
    ui->setupUi(this);

    objectDLLRestAPI = new DLLRestAPI;
    objectDLLRestAPI->getTilinumero(kortinnumero, webtoken);
    connect(objectDLLRestAPI,SIGNAL(tilinumeroSignal(QString)),
            this,SLOT(tiliSLOT(QString)));
    TapahtumatLista();

    ui->labelKortinnumero->setText(kortinnumero);
    ui->labelPin->setText(webtoken);
}

KorttiMain::~KorttiMain()
{
    delete ui;
}

void KorttiMain::on_btn_20_clicked()
{

}


void KorttiMain::on_btn_40_clicked()
{

}


void KorttiMain::on_btn_50_clicked()
{

}


void KorttiMain::on_btn_100_clicked()
{

}


void KorttiMain::on_btn_custom_clicked()
{

}


void KorttiMain::on_btn_logout_clicked()
{
    close();
}

void KorttiMain::tiliSLOT(QString tilin)
{
    Tilinumero = tilin;
    ui->labelTilinumero->setText(Tilinumero);
}

void KorttiMain::TapahtumatLista()
{
    QList<Tapahtumat*> tapahtumalista;
    Tapahtumat tap1, tap2, tap3, tap4, tap5, tap6, tap7, tap8, tap9, tap10;
    tapahtumalista.append(&tap1);
    tapahtumalista.append(&tap2);
    tapahtumalista.append(&tap3);
    tapahtumalista.append(&tap4);
    tapahtumalista.append(&tap5);
    tapahtumalista.append(&tap6);
    tapahtumalista.append(&tap7);
    tapahtumalista.append(&tap8);
    tapahtumalista.append(&tap9);
    tapahtumalista.append(&tap10);

    tap1.setAika("21-04-2022 10:00");
    tap1.setTapahtuma("Nosto");
    tap1.setSumma("30");
    tap2.setAika("21-04-2022 10:00");
    tap2.setTapahtuma("Nosto");
    tap2.setSumma("15");
    tap3.setAika("21-04-2022 10:00");
    tap3.setTapahtuma("Nosto");
    tap3.setSumma("20");

    QStandardItemModel *table_model = new QStandardItemModel(tapahtumalista.size(),3);
    table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("Aika"));
    table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tapahtuma"));
    table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Summa"));

    for (int row = 0; row < tapahtumalista.size(); ++row) {
            QStandardItem *Aika = new QStandardItem((tapahtumalista[row]->getAika()));
            table_model->setItem(row, 0, Aika);
            QStandardItem *Tapahtuma = new QStandardItem((tapahtumalista[row]->getTapahtuma()));
            table_model->setItem(row, 1, Tapahtuma);
            QStandardItem *Summa = new QStandardItem((tapahtumalista[row]->getSumma()));
            table_model->setItem(row, 2, Summa);
    }

    ui->tableView->setModel(table_model);
    for (int col=0; col<3; col++)
    {
       ui->tableView->setColumnWidth(col,135);
    }

}

