#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include <QObject>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <dialog.h>

class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI();
    ~DLLRestAPI();
    void getTilinumero(QString kortinnumero, QString wtoken);
    void getCardState(QString kortinnumero, QString wtoken);
    void LockCard(QString kortinnumero);
    void getBalance(QString kortinnumero, QString wtoken);
    void StartTransaction(QString kortinnumero, QString tilinum, QString wtoken, int maara);
    void getTilitapahtumat(QString kortinnumero, QString wtoken);
    QString knumero, webtoken, tnumero, Balance;
    int Amount;

private:
    void addTilitapahtuma(QString tapahtuma);
    QNetworkAccessManager * getManager;
    QNetworkAccessManager * tiliManager;
    QNetworkAccessManager * saldoManager;
    QNetworkAccessManager * putManager;
    QNetworkAccessManager *tilitapahtumaManager;
    QNetworkReply *reply;
    QByteArray response_data;
    void showPrompt();
    Dialog * objectDialog;

private slots:
    void getTilinumeroSlot (QNetworkReply *reply);
    void getCardStateSlot (QNetworkReply *reply);
    void updateCardStateSlot(QNetworkReply *reply);
    void getSaldoSlot (QNetworkReply *reply);
    void getSaldoSlotInternal (QNetworkReply *reply);
    void getTilitapahtumatSlot(QNetworkReply *reply);
    void AllocateSaldo(QString);

    void Transaction();
    void TransactSlot(QNetworkReply *reply);

    void addTilitapahtumaSlot(QNetworkReply *reply);

signals:
    void balanceSignal(QString);
    void balanceSignalInternal(QString);
    void startTransact();
    void withdrawSignal();
    void tilinumeroSignal(QString);
    void CardStateSignal(QString);
    void tilitapahtumatSignal(QString);




};
#endif // DLLRESTAPI_H
