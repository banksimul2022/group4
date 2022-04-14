#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectLogin=new Login;
    objectDLLPinCode=new DLLPinCode;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectLogin;
    ui=nullptr;
    objectLogin=nullptr;
    delete objectDLLPinCode;
    objectDLLPinCode=nullptr;
}


void MainWindow::on_btnLogin_clicked()
{
    objectDLLPinCode->openDllDialog();
    QString value=objectDLLPinCode->returnFromDll();
    qDebug()<<value;
}




