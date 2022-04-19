#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include "dllpincode.h"

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
    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;
    Login *objectLogin;
    DLLPinCode *objectDLLPinCode;
};
#endif // MAINWINDOW_H