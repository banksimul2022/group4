#include "pincode.h"
#include "ui_pincode.h"


pincode::pincode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pincode)
{
    ui->setupUi(this);
}

pincode::~pincode()
{
    delete ui;
}

void pincode::on_btnLogin_clicked()
{
    QString a=ui->pinLineEdit->text();
    this->setDialogValue(a);
    this->close();
}

