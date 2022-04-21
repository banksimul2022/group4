#include "korttimain.h"
#include "ui_korttimain.h"

KorttiMain::KorttiMain(QString kortinnumero, QString pin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KorttiMain)
{
    ui->setupUi(this);
    ui->labelKortinnumero->setText(kortinnumero);
    ui->labelPin->setText(pin);
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

}

