#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

const QString &Dialog::getDialogValue() const
{
    return dialogValue;
}

void Dialog::setDialogValue(const QString &newDialogValue)
{
    dialogValue = newDialogValue;
}

void Dialog::on_btnSet_clicked()
{
    QString a=ui->textValue->text();
    this->setDialogValue(a);
    this->close();
}

