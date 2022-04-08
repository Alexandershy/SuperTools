
#ifndef _SUPERNETWORK__H
#define _SUPERNETWORK__H

#include <QNetworkInterface>
#include <QNetworkDatagram>
#include <QTcpSocket>
#include <QTcpServer>
#include <QUdpSocket>
#include <QHostInfo>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QThread>

class SuperNetwork : public QObject
{
    Q_OBJECT

public:

    SuperNetwork(
        QObject* parent = nullptr);

    ~SuperNetwork();

public slots:

    /*  system;*/

    void Getlocalipaddress(
            QList<QNetworkAddressEntry> *entry,
            QComboBox *combobox);

    void Getlocalnetmask(
            QList<QNetworkAddressEntry> *entry,
            QComboBox *combobox);

    /*  QTcpsocket;*/
    bool Connecttcpserver(
            QTcpSocket* tcpsocket,
            QString ipaddress,
            int portnumber,
            int timeout);

    bool Disconnecttcpserver(
            QTcpSocket* tcpsocket,
            int timeout);

    void Writesocket(
            QCheckBox* checkboxstring,
            QCheckBox* checkboxaddr,
            QCheckBox* checkboxaddn,
            QTcpSocket* tcpsocket,
            QLineEdit* lineeditdata);

    QByteArray Readdatastream(
            QTcpSocket* tcpsocket,
            QCheckBox* checkboxstring);

    void Closetcpclient(
            QTcpSocket* tcpsocket);
};

class Tcpsocketthread : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    Tcpsocketthread(
            QTcpSocket* tcpsocket,
            double timeout);

public slots:

    void run();

private:

    QTcpSocket* Tcpsocket   = nullptr;
    double Timeout          = 1000;
    double Inittime         = 0;
    int Bytesavailable      = 0;

signals:

    void Signaltt();

    void Signaltf();
};

#endif // _SUPERNETWORK__H
