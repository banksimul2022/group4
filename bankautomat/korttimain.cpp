#include "korttimain.h"
#include "ui_korttimain.h"

KorttiMain::KorttiMain(QString kNum, QString kPin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KorttiMain)
{
    ui->setupUi(this);
    ui->labelKortinnumero->setText(kNum);
    ui->labelPin->setText(kPin);
}

KorttiMain::~KorttiMain()
{
    delete ui;
}

void KorttiMain::on_btnSaldo_clicked()
{

}

