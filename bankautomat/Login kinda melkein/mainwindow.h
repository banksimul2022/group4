#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include "dllpincode.h"
#include "korttimain.h"
#include "dllserialport.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void tokenSLOT(QByteArray);

    void on_btn_acc1_clicked();

    void on_btn_acc2_clicked();

    void on_btn_acc3_clicked();

    void serialSLOT(QByteArray);

    void on_btn_Serial_clicked();

private:
    Ui::MainWindow *ui;
    Login *objectLogin;
    DLLPinCode *objectDLLPinCode;
    QByteArray token;
    KorttiMain *objectKorttiMain;
    DLLSerialPort *objectSerialPort;
    QString knumero;
    QByteArray recieved;
};
#endif // MAINWINDOW_H
