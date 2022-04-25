#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include "engine.h"
#include "myurl.h"
#include <QObject>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI();
    ~DLLRestAPI();
void getTilinumero(QString kortinnumero, QString wtoken);
void getBalance(QString kortinnumero, QString wtoken);
void getWithdraw(QString kortinnumero, QString wtoken);
void getTilitapahtumat(QString kortinnumero, QString wtoken);
QString knumero, webtoken, tnumero;

private:
QNetworkAccessManager * getManager;
QNetworkReply *reply;
QByteArray response_data;

private slots:
void getTilinumeroSlot (QNetworkReply *reply);

signals:
void balanceSignal();
void withdrawSignal();
void tilinumeroSignal();
void tilitapahtumatSignal();




};
#endif // DLLRESTAPI_H
