#include "login.h"
#include "QDebug"

Login::Login(QWidget *parent) :
    QDialog(parent)
{
    objectMyUrl=new MyUrl;
    base_url=objectMyUrl->getBase_url();
}

Login::~Login()
{
    delete objectKorttiMain;
    objectKorttiMain=nullptr;
}

void Login::MainLogin(QString ParPin, QString ParKortinnumero){
    qDebug()<<"base_url="+base_url;
    kortinnumero=ParKortinnumero;
    pin=ParPin;

    QJsonObject jsonObj;
    jsonObj.insert("kortinnumero",kortinnumero);
    jsonObj.insert("pin",pin);

    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    LoginManager = new QNetworkAccessManager(this);
    connect(LoginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = LoginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    if (response_data==check) {
        qDebug()<<"Eat shit and die";
    } else {
        objectKorttiMain=new KorttiMain(kortinnumero,pin);
        objectKorttiMain->show();
    }
}
