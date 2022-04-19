#ifndef LOGIN_H
#define LOGIN_H

#include "korttimain.h"
#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void MainLogin(QString ParPin, QString ParKortinnumero);


private slots:
    void loginSlot(QNetworkReply *reply);

private:
    QString kortinnumero;
    QString pin;
    QString lukittu;
    KorttiMain *objectKorttiMain;
    MyUrl *objectMyUrl;
    QString base_url;

    QNetworkAccessManager *LoginManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // LOGIN_H
