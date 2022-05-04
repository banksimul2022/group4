#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "DLLSerialPort_global.h"
#include <QObject>
#include <QString>
class DLLSERIALPORT_EXPORT DLLSerialPort : public QObject
{
Q_OBJECT
public:
    DLLSerialPort();
    QSerialPort *serial;
    void Luku();
private:
QString Read;

signals:
void RFID(QByteArray);
};

#endif // DLLSERIALPORT_H
