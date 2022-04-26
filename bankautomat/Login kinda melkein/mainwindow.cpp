#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectLogin=new Login;
    objectDLLPinCode=new DLLPinCode;
    connect(objectLogin,SIGNAL(tokenSignal(QByteArray)),
            this, SLOT(tokenSLOT(QByteArray)));
    knumero = "22";

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectLogin;
    ui=nullptr;
    objectLogin=nullptr;
    delete objectKorttiMain;
    objectKorttiMain=nullptr;

}


void MainWindow::on_btnLogin_clicked()
{

    objectDLLPinCode->openDllDialog();
    QString value=objectDLLPinCode->returnFromDll();
    objectLogin->MainLogin(value, knumero);
}

void MainWindow::tokenSLOT(QByteArray tok)
{
    token = tok;
    objectKorttiMain=new KorttiMain(token, knumero);
    objectKorttiMain->show();
}




