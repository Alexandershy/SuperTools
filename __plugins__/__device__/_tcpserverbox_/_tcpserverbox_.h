#ifndef _TCPSERVERBOX__H
#define _TCPSERVERBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supernetwork__/_supernetwork_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "_tcpserverbox__global.h"

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

    SuperNetwork *SuperN                            = nullptr;
    ModuleA* Modulea                                = nullptr;
    ModuleB* Moduleb                                = nullptr;
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

    void Init();

    void Objectinit();

    void Widgetlistinit();

    void Tempdirinit();

    void Getlocalipaddress();

    void Enablestarttcpserver();

    void Starttcpserver();

    void Closetcpserver();

    void Forcedisconnect();

    void Writeapi(
            QTcpSocket *tcpsocket,
            QByteArray serverinfo);

    void Receivecommand();

    void Operatorcommand(
            QTcpSocket *tcpsocket,
            QByteArray bytes);

    void Exitmode(
            QTcpSocket *tcpsocket);

    void Stringtostring();

    void Stringtostringmode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void Stringtohex();

    void Stringtohexmode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void Hextostring();

    void Hextostringmode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void Receiverfiles();

    void Receiverfilesmode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void Transferfiles();

    void Transferfilesmode(
            QByteArray bytes,
            QTcpSocket *tcpsocket);

    void Getfilepath();

    void Disconnected();

    void Newtcpsocket();

    void Signalraslot(
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

    void Initrun();

signals:

    void Signalra(
            QFile *file,
            QTcpSocket *tcpsocket,
            QString string);
};

#endif // _TCPSERVERBOX__H
