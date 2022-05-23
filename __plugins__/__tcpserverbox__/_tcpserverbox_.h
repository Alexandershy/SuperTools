#ifndef _TCPSERVERBOX__H
#define _TCPSERVERBOX__H
#define _TCPSERVERBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supernetwork__/_supernetwork_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_tcpservermodulea_.h"
#include "__module__/_tcpservermoduleb_.h"

class _TCPSERVERBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class tcpserverbox new instance pointer;*/
};

class TcpServerBox : public SuperTab
{
    Q_OBJECT

public:

    TcpServerBox(
            QWidget *parent = nullptr);

    ~TcpServerBox();

private:

    SuperNetwork *Network                           = nullptr;
    TcpServerModuleA* Modulea                       = nullptr;
    TcpServerModuleB* Moduleb                       = nullptr;
    QTcpServer *Tcpserver                           = nullptr;
    QList<QTcpSocket*> Tcpsocketlist                = {};
    QList<QWidget*> Connectwidgetet                 = {};
    QList<QWidget*> Connectwidgetef                 = {};
    QList<QWidget*> Disconnectwidgetef              = {};
    QList<QWidget*> Disconnectwidgetet              = {};
    QList<QNetworkInterface> Networkinterface       = {};
    QList<QNetworkAddressEntry> Networkaddressentry = {};
    int Commandindex                                = 0;
    QDir *Dir                                       = nullptr;
    QString Tempfilepath                            = "./__depycache__/__tcpserver__/";
    QStringList Fileslist                           = {};
    QStringList Commandlist                         = {"",
                                                       "\r\n<1><String to String>",
                                                       "\r\n<2><String to hex>",
                                                       "\r\n<3><Hex to String>",
                                                       "\r\n<4><Transfer files>",
                                                       "\r\n<5><Receiver files>"
                                                      };
    SuperLogger *Logger                             = nullptr;

private slots:

    /* main function;*/
    void init();

    void objectInit();

    void widgetListInit();

    void tempDirInit();

    void getLocalIpAddress();

    void enableStartTcpserver();

    void startTcpserver();

    void closeTcpserver();

    void forceDisconnect();

    void writeApi(
            QTcpSocket *tcpsocket,
            QByteArray serverinfo);

    void receiveCommand();

    void operatorCommand(
            QTcpSocket *tcpsocket,
            QByteArray bytes);

    void exitMode(
            QTcpSocket *tcpsocket);

    void stringToString();

    void stringTostringMode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void stringToHex();

    void stringToHexMode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void hexTostring();

    void hexTostringMode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void receiverFiles();

    void receiverFilesMode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void transferFiles();

    void transferFilesMode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void getFilePath();

    void disconnected();

    void newTcpsocket();

    void signalRaSlot(
            QFile *file,
            QTcpSocket *tcpsocket,
            QString string);
};

class ReceiverData : public QThread
{
    Q_OBJECT

public:

    ReceiverData(
            QFile *file,
            QTcpSocket *tcpsocket,
            int size);

    ~ReceiverData();

public slots:

    void run();

private:

    QFile *File             = nullptr;
    QTcpSocket *Tcpsocket   = nullptr;
    int Size = 0;
    double Sizewrite = 0;
    double Timeout = 1000;
    double Inittime = 0;

private slots:

    void initRun();

signals:

    void signalRa(
            QFile *file,
            QTcpSocket *tcpsocket,
            QString string);
};

#endif // _TCPSERVERBOX__H
