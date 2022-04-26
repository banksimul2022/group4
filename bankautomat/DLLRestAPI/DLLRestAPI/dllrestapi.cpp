#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI()
{

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

void DLLRestAPI::getWithdraw(QString tilinum, QString wtoken, int maara)
{

    QJsonObject jsonObj;
    jsonObj.insert("saldo",maara);
    qDebug()<<jsonObj;

    QString site_url="http://localhost:3000/tili/"+tilinum;
    QNetworkRequest request((site_url));
    //BASIC AUTENTIKOINTI ALKU
    request.setRawHeader(QByteArray("Authorization"),QByteArray("Token "+wtoken.toLocal8Bit()));
    //BASIC AUTENTIKOINTI LOPPU

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
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
        emit tilinumeroSignal(tilinumero);
}
     reply->deleteLater();
     tiliManager->deleteLater();
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

void DLLRestAPI::withdrawSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}
