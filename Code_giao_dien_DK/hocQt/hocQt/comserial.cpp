#include "comserial.h"

comserial::comserial(QSerialPort *myDev)
{
   devSerial = myDev;

}
QStringList comserial::ConnectedDevices()
{
    QStringList devs;
    foreach (const QSerialPortInfo info, QSerialPortInfo::availablePorts()){
        devSerial->setPort(info);
        if (devSerial->open(QIODevice::ReadWrite)){
            devSerial->close();
            devs << info.portName();
        }
    }
return devs;
}
bool comserial::Connect(QString Port, uint32_t bd)
{
    devSerial->setPortName(Port);
    qDebug() <<"Serial port device:"<< Port;
    switch (bd) {
  case 2400:
        qDebug() <<"Baudrate: 2400";

        devSerial->setBaudRate(QSerialPort::Baud2400);

        break;
  case 4800:
          qDebug() <<"Baudrate: 4800";
          devSerial->setBaudRate(QSerialPort::Baud4800);
          break;
  case 9600:
          qDebug() <<"Baudrate: 9600";
          devSerial->setBaudRate(QSerialPort::Baud9600);
          break;
  case 19200:
          qDebug() <<"Baudrate: 19200";
          devSerial->setBaudRate(QSerialPort::Baud19200);
          break;
  case 115200:
          qDebug() <<"Baurate: 115200";
          devSerial->setBaudRate(QSerialPort::Baud115200);
          break;
    }
   devSerial->setFlowControl(QSerialPort::NoFlowControl);
   devSerial->setDataBits(QSerialPort::Data8);
   devSerial->setParity(QSerialPort::NoParity);
   devSerial->setStopBits(QSerialPort::OneStop);

   if (devSerial->open(QIODevice::ReadWrite)){
       qDebug()<<"Successfully opened serial port!";
       return true;
       }
   else {
       qDebug()<<"Failed ti opend serial port!";
       qDebug()<<"Erro:"<<devSerial->error();
       return false;

   }
}
bool comserial::Disconnect()
{
    devSerial->clear();
    devSerial->close();
    if(devSerial->error()==0||!devSerial->isOpen()){
        qDebug()<<"Succesfully closed serial port!";
        return true;

    }
    else{
        qDebug()<<"Failed to close serial port! Erro:"<<devSerial->error();
        return false;
           }
}
qint64 comserial::Write(const char *cmd)
{
    qint64 sizeWritten;
    sizeWritten = devSerial->write(cmd,qstrlen(cmd));

    return sizeWritten;
}

QByteArray comserial:: ReadPort()
{
    QByteArray readData;

    while (devSerial->waitForReadyRead(25)) {
        readData.append(devSerial->readAll());
    }
    return readData;
}
//QByteArray comserial::Read()
//{
//    Q bufRxSerial;
//    while (devSerial->waitForReadyRead(20)) {
//        bufRxSerial += devSerial->readAll();
//    }
//    return bufRxSerial;
//}
//QString comserial::Read(int bufferSize){
//    char *buf = new char[bufferSize];
//    if (devSerial->canReadLine()){
//        devSerial->read(buf, sizeof(buf));
//    }
//    QString str = QString::fromUtf8(buf,bufferSize);
//    delete [] buf;
//    return str;
//}
