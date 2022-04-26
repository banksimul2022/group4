#include "korttimain.h"
#include "ui_korttimain.h"


#include <QStandardItemModel>

KorttiMain::KorttiMain(QByteArray webtoken, QString kortinnumero, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KorttiMain)
{
    ui->setupUi(this);
    WebToken = webtoken;
    Kortinnumero = kortinnumero;
    objectDLLRestAPI = new DLLRestAPI;


    connect(objectDLLRestAPI,SIGNAL(tilinumeroSignal(QString)),
            this,SLOT(tiliSLOT(QString)));
    connect(objectDLLRestAPI,SIGNAL(balanceSignal(QString)),
            this,SLOT(saldoSLOT(QString)));
    connect(objectDLLRestAPI,SIGNAL(tilitapahtumatSignal(QString)),
            this,SLOT(tilitapahtumaSLOT(QString)));



    objectDLLRestAPI->getTilinumero(Kortinnumero, WebToken);

    lista.append(&t1);
    lista.append(&t2);
    lista.append(&t3);
    lista.append(&t4);
    lista.append(&t5);
    lista.append(&t6);
    lista.append(&t7);
    lista.append(&t8);
    lista.append(&t9);
    lista.append(&t10);

}

KorttiMain::~KorttiMain()
{
    delete ui;
    delete objectDLLRestAPI;
    objectDLLRestAPI=nullptr;
}

void KorttiMain::on_btn_20_clicked()
{
    objectDLLRestAPI->getWithdraw(Tilinumero, WebToken, 20, Saldo.toInt());
    close();
}


void KorttiMain::on_btn_40_clicked()
{
    objectDLLRestAPI->getWithdraw(Tilinumero, WebToken, 40, Saldo.toInt());
}


void KorttiMain::on_btn_50_clicked()
{
    objectDLLRestAPI->getWithdraw(Tilinumero, WebToken, 50, Saldo.toInt());
}


void KorttiMain::on_btn_100_clicked()
{
    objectDLLRestAPI->getWithdraw(Tilinumero, WebToken, 100, Saldo.toInt());
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
}

void KorttiMain::saldoSLOT(QString balance)
{
    Saldo = balance;
    ui->labelSaldo->setText("Saldo: "+Saldo+"€");
}

void KorttiMain::tilitapahtumaSLOT(QString tap)
{
    QString tapahtuma = tap;
    QStringList templist1;
    templist1 = tapahtuma.split(",");
    int track = (templist1.size()-1)/3;
    int listtracker = 0;
    for (int i = 0; i <track; i++){
        lista[i]->setAika(templist1[listtracker]);
        lista[i]->setTapahtuma(templist1[listtracker+1]);
        lista[i]->setSumma(templist1[listtracker+2]);
        listtracker += 3;
    }
    TapahtumatLista();

}

void KorttiMain::TapahtumatLista()
{

    QStandardItemModel *table_model = new QStandardItemModel(lista.size(),3);
    table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("Aika"));
    table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tapahtuma"));
    table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Summa"));

    for (int row = 0; row <lista.size(); ++row) {
            QStandardItem *Aika = new QStandardItem((lista[row]->getAika()));
            table_model->setItem(row, 0, Aika);
            QStandardItem *Tapahtuma = new QStandardItem((lista[row]->getTapahtuma()));
            table_model->setItem(row, 1, Tapahtuma);
            QStandardItem *Summa = new QStandardItem((lista[row]->getSumma()));
            table_model->setItem(row, 2, Summa);
    }

    ui->tableView->setModel(table_model);
    for (int col=0; col<3; col++)
    {
       ui->tableView->setColumnWidth(col,135);
    }

}



void KorttiMain::on_tiltap_btn_clicked()
{
    objectDLLRestAPI->getTilitapahtumat(Tilinumero, WebToken);
}


void KorttiMain::on_btn_saldo_clicked()
{
    objectDLLRestAPI->getBalance(Tilinumero, WebToken);
}

