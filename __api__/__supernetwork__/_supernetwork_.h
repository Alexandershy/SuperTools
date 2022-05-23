#ifndef _SUPERNETWORK__H
#define _SUPERNETWORK__H
#define _SUPERNETWORK__EXPORT Q_DECL_EXPORT
#define _SUPERTCPSOCKETTHREAD__EXPORT Q_DECL_EXPORT

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

class _SUPERNETWORK__EXPORT SuperNetwork : public QObject
{
    Q_OBJECT

public:

    SuperNetwork(
        QObject* parent = nullptr);

    ~SuperNetwork();

public slots:

    /*  system;*/
    void getLocalIpAddress(
            QList<QNetworkAddressEntry> *entry,
            QComboBox *combobox);

    void getLocalNetmask(
            QList<QNetworkAddressEntry> *entry,
            QComboBox *combobox);

    /*  QTcpsocket;*/
    bool connectTcpServer(
            QTcpSocket* tcpsocket,
            QString ipaddress,
            int portnumber,
            int timeout);

    bool disConnectTcpServer(
            QTcpSocket* tcpsocket,
            int timeout);

    void writeSocket(
            QCheckBox* checkboxstring,
            QCheckBox* checkboxaddr,
            QCheckBox* checkboxaddn,
            QTcpSocket* tcpsocket,
            QLineEdit* lineeditdata);

    QByteArray readDataStream(
            QTcpSocket* tcpsocket,
            QCheckBox* checkboxstring);

    void closeTcpClient(
            QTcpSocket* tcpsocket);
};

class _SUPERTCPSOCKETTHREAD__EXPORT SuperTcpSocketThread : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    SuperTcpSocketThread(
            QTcpSocket* tcpsocket,
            double timeout);

    ~SuperTcpSocketThread();

public slots:

    void run();

private:

    QTcpSocket* Tcpsocket   = nullptr;
    double Timeout          = 1000;
    double Inittime         = 0;
    int Bytesavailable      = 0;

signals:

    void signalTt();

    void signalTf();
};

#endif // _SUPERNETWORK__H
