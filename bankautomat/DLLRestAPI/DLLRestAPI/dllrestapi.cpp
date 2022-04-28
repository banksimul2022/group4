#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI()
{
    connect(this, SIGNAL(balanceSignalInternal(QString)),
            this, SLOT(AllocateSaldo(QString)));
    connect(this, SIGNAL(startTransact()),
            this, SLOT(Transaction()));
}
DLLRestAPI::~DLLRestAPI()
{

}

void DLLRestAPI::getTilinumero(QString kortinnumero, QString wtoken)
{
    QString site_url="http://localhost:3000/kortti/"+kortinnumero;
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+wtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU
    tiliManager = new QNetworkAccessManager(this);

    connect(tiliManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTilinumeroSlot(QNetworkReply*)));

    reply = tiliManager->get(request);
}
void DLLRestAPI::getTilinumeroSlot (QNetworkReply *reply)
{
     response_data=reply->readAll();
     qDebug()<<response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();
     QString tilinumero;
     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        tilinumero=QString::number(json_obj["tilinumero"].toInt());
        qDebug()<<"tilinum: "+tilinumero;
        emit tilinumeroSignal(tilinumero);
}
     reply->deleteLater();
     tiliManager->deleteLater();
}


void DLLRestAPI::getCardState(QString kortinnumero, QString wtoken)
{
    QString site_url="http://localhost:3000/kortti/"+kortinnumero;
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+wtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU
    tiliManager = new QNetworkAccessManager(this);

    connect(tiliManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCardStateSlot(QNetworkReply*)));

    reply = tiliManager->get(request);
}
void DLLRestAPI::getCardStateSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString CardState;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       CardState=QString::number(json_obj["lukittu"].toInt());
       qDebug()<<"Card State: "+CardState;
       emit CardStateSignal(CardState);
}
    reply->deleteLater();
    tiliManager->deleteLater();
}


void DLLRestAPI::LockCard(QString kortinnumero)
{
    QJsonObject jsonObj;
    jsonObj.insert("lukittu","1");

    QString site_url="http://localhost:3000/kortti/"+kortinnumero;
    QNetworkRequest request((site_url));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateCardStateSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
}
void DLLRestAPI::updateCardStateSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}

void DLLRestAPI::getBalance(QString tilinum, QString wtoken)
{
    QString site_url="http://localhost:3000/tili/"+tilinum;
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+wtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU
    saldoManager = new QNetworkAccessManager(this);

    connect(saldoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

    reply = saldoManager->get(request);
}


void DLLRestAPI::StartTransaction(QString kortnum, QString tilinum, QString wtoken, int maara)
{
    knumero = kortnum;
    tnumero = tilinum;
    webtoken = wtoken;
    Amount = maara;
    QString site_url="http://localhost:3000/tili/"+tilinum;
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+wtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU
    saldoManager = new QNetworkAccessManager(this);

    connect(saldoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSaldoSlotInternal(QNetworkReply*)));

    reply = saldoManager->get(request);
}


void DLLRestAPI::getTilitapahtumat(QString tilinum, QString wtoken)
{
    QString site_url="http://localhost:3000/tilitapahtumat/"+tilinum;
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+wtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTilitapahtumatSlot(QNetworkReply*)));

    reply = getManager->get(request);
}


void DLLRestAPI::addTilitapahtuma(QString tapahtuma)
{
    QDateTime date = QDateTime::currentDateTime();
    QString DateTime = date.toString("yyyy.MM.dd hh:mm:ss");

    QJsonObject jsonObj;

    jsonObj.insert("id_tilinumero",tnumero);
    jsonObj.insert("kortinnumero",knumero);
    jsonObj.insert("pvmaika",DateTime);
    jsonObj.insert("tapahtuma",tapahtuma);
    jsonObj.insert("summa",Amount);

    QString site_url="http://localhost:3000/tilitapahtumat";
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+webtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    tilitapahtumaManager = new QNetworkAccessManager(this);
    connect( tilitapahtumaManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addTilitapahtumaSlot(QNetworkReply*)));

    reply = tilitapahtumaManager->post(request, QJsonDocument(jsonObj).toJson());
}

void DLLRestAPI::showPrompt()
{
    objectDialog=new Dialog;
    objectDialog->exec();
}


void DLLRestAPI::Transaction()
{
    qDebug()<<"Withdraw balance: "+Balance;

    int amount = Balance.toInt() - Amount;
    qDebug()<<"Amount after: "+QString::number(amount);

    QJsonObject jsonObj;
    jsonObj.insert("saldo",amount);
    qDebug()<<jsonObj;

    QString site_url="http://localhost:3000/tili/"+tnumero;
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+webtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    putManager = new QNetworkAccessManager(this);

    DLLRestAPI::addTilitapahtuma("Nosto"); //Tilitapahtuma tehdaan

    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(TransactSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
}





void DLLRestAPI::getSaldoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString saldo;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       saldo=(json_obj["saldo"].toString());
       emit balanceSignal(saldo);
}
    reply->deleteLater();
    saldoManager->deleteLater();
}


void DLLRestAPI::getSaldoSlotInternal(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString saldo;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       saldo=(json_obj["saldo"].toString());
       if (Amount > saldo.toInt()){ //Tarkistetaan onko tililla tarpeeksi raahaa
           qDebug()<<"No monie";
           showPrompt();
       } else if(Amount == 0) { //Tarkistetaan yrittääkö käyttäjä nostaa yli nollaa euroa
           qDebug()<<"Transaction Failed";
           showPrompt();
       } else {
           emit balanceSignalInternal(saldo);
       }

}
    reply->deleteLater();
    saldoManager->deleteLater();
}


void DLLRestAPI::getTilitapahtumatSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString tilitapahtuma;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       tilitapahtuma+=json_obj["pvmaika"].toString()+", "+json_obj["tapahtuma"].toString()+", "+json_obj["summa"].toString()+",";

}
    emit tilitapahtumatSignal(tilitapahtuma);
    reply->deleteLater();
    getManager->deleteLater();
}


void DLLRestAPI::TransactSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}


void DLLRestAPI::addTilitapahtumaSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    tilitapahtumaManager->deleteLater();
}


void DLLRestAPI::AllocateSaldo(QString s)
{
    Balance = s;
    emit startTransact();

}
