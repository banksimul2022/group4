#ifndef LOGIN_H
#define LOGIN_H

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
    QString kortinnumero;
    QString pin;


private slots:
    void loginSlot(QNetworkReply *reply);

private:
    MyUrl *objectMyUrl;
    QString base_url;
    QString check = "false";

    QNetworkAccessManager *LoginManager;
    QNetworkReply *reply;
    QByteArray response_data;
signals:
    void tokenSignal(QByteArray);

};

#endif // LOGIN_H
