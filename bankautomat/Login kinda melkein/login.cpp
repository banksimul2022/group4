#include "login.h"
#include "QDebug"

Login::Login(QWidget *parent) :
    QDialog(parent)
{
    objectMyUrl=new MyUrl;
    base_url=objectMyUrl->getBase_url();
    objectDLLRestAPI = new DLLRestAPI;
    connect(objectDLLRestAPI,SIGNAL(CardStateSignal(QString)),
            this,SLOT(CardStateSLOT(QString)));


}

Login::~Login()
{

}

void Login::MainLogin(QString ParPin, QString ParKortinnumero){
    qDebug()<<"base_url="+base_url;
    kortinnumero=ParKortinnumero;
    pin=ParPin;
    objectDLLRestAPI->getCardState(kortinnumero, "WebToken");
}


void Login::CardStateSLOT(QString state)
{
    if(state == "1")
    {
        qDebug()<<"Card Is Locked";
    } else {
        StartLogin();
    }
}

void Login::StartLogin()
{
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
    //qDebug()<<response_data;

    if (response_data==check) {
        qDebug()<<"Wrong pin";
        if(kortinnumero==PrevCard){
            LoginAttempts += 1;
        } else {
            LoginAttempts = 1;
            PrevCard=kortinnumero;
        }
        if(LoginAttempts >= 3){
            qDebug()<<"Your card has been locked";
            objectDLLRestAPI->LockCard(kortinnumero);
        }
        qDebug()<<LoginAttempts;
    } else {
        LoginAttempts = 0;
        emit tokenSignal(response_data);
    }
}
