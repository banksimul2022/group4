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
    objectSerialPort=new DLLSerialPort;
    connect(objectSerialPort,SIGNAL(RFID(QByteArray)),
            this,SLOT(serialSLOT(QByteArray)));
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

void MainWindow::on_btn_acc1_clicked()
{
    knumero = "1234";
    objectDLLPinCode->openDllDialog();
    QString value=objectDLLPinCode->returnFromDll();
    objectLogin->MainLogin(value, knumero);

}
void MainWindow::on_btn_acc2_clicked()
{
    knumero = "22";
    objectDLLPinCode->openDllDialog();
    QString value=objectDLLPinCode->returnFromDll();
    objectLogin->MainLogin(value, knumero);
}
void MainWindow::on_btn_acc3_clicked()
{
    knumero = "51265";
    objectDLLPinCode->openDllDialog();
    QString value=objectDLLPinCode->returnFromDll();
    objectLogin->MainLogin(value, knumero);
}

void MainWindow::serialSLOT(QByteArray rfid)
{
    recieved = rfid;
}


void MainWindow::tokenSLOT(QByteArray tok)
{
    token = tok;
    objectKorttiMain=new KorttiMain(token, knumero);
    objectKorttiMain->show();
}

void MainWindow::on_btn_Serial_clicked()
{
    objectSerialPort->Luku();
    recieved = recieved.trimmed();
    knumero = QString(recieved);
    objectDLLPinCode->openDllDialog();
    QString value=objectDLLPinCode->returnFromDll();
    objectLogin->MainLogin(value, knumero);

}

