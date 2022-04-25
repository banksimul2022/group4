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
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTilinumeroSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void DLLRestAPI::getBalance(QString kortinnumero, QString wtoken)
{

}

void DLLRestAPI::getWithdraw(QString kortinnumero, QString wtoken)
{

}

void DLLRestAPI::getTilitapahtumat(QString kortinnumero, QString wtoken)
{

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
     getManager->deleteLater();
}
