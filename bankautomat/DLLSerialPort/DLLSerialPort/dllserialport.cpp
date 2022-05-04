#include "dllserialport.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
DLLSerialPort::DLLSerialPort():serial(new QSerialPort)
{
    serial->setPortName("COM3");
    serial->setBaudRate(9600);
    serial->setDataBits(QSerialPort::DataBits(8));
    serial->setParity(QSerialPort::Parity(0));
    serial->setStopBits(QSerialPort::StopBits(1));
    serial->setFlowControl(QSerialPort::FlowControl(0));
    serial->open(QIODevice::ReadOnly);
    if (serial->open(QIODevice::ReadWrite)) {
        qDebug()<<"Serial Open";
    } else {
        qDebug()<< serial->errorString();
    }
}

void DLLSerialPort::Luku()
{
    QByteArray Read = serial->readLine();
    qDebug()<<Read;
    emit RFID(Read);
}



