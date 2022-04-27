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
    void StartTransaction(QString tilinum, QString wtoken, int maara);
    void getTilitapahtumat(QString kortinnumero, QString wtoken);
    QString knumero, webtoken, tnumero, Balance;
    int Amount;

private:
    QNetworkAccessManager * getManager;
    QNetworkAccessManager * tiliManager;
    QNetworkAccessManager * saldoManager;
    QNetworkAccessManager * putManager;
    QNetworkReply *reply;
    QByteArray response_data;

private slots:
    void getTilinumeroSlot (QNetworkReply *reply);
    void getSaldoSlot (QNetworkReply *reply);
    void getSaldoSlotInternal (QNetworkReply *reply);
    void getTilitapahtumatSlot(QNetworkReply *reply);
    void AllocateSaldo(QString);

    void Transaction();
    void TransactSlot(QNetworkReply *reply);

signals:
    void balanceSignal(QString);
    void balanceSignalInternal(QString);
    void startTransact();
    void withdrawSignal();
    void tilinumeroSignal(QString);
    void tilitapahtumatSignal(QString);




};
#endif // DLLRESTAPI_H
