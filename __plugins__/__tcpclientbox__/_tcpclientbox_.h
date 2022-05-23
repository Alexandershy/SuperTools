#ifndef _TCPCLIENTBOX__H
#define _TCPCLIENTBOX__H
#define _TCPCLIENTBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__supernetwork__/_supernetwork_.h"
#include "__supersender__/_supersender_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_tcpclientmodulea_.h"
#include "__module__/_tcpclientmoduleb_.h"
#include <QThread>
#include <QTimer>
#include <QDir>

class _TCPCLIENTBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class tcpclientbox new instance pointer;*/
};

class TcpClientBox : public SuperTab
{
    Q_OBJECT

public:

    TcpClientBox(
            QWidget *parent = nullptr);

    ~TcpClientBox();

private:

    SuperNetwork *Network                           = nullptr;
    TcpClientModuleA *Modulea                       = nullptr;
    TcpClientModuleB *Moduleb                       = nullptr;
    QTcpSocket *Tcpsocket                           = nullptr;
    QString Username                                = "";
    QList<QWidget*> Connectwidgetet                 = {};
    QList<QWidget*> Connectwidgetef                 = {};
    QList<QWidget*> Disconnectwidgetef              = {};
    QList<QWidget*> Disconnectwidgetet              = {};
    QList<QNetworkInterface> Networkinterface       = {};
    QList<QNetworkAddressEntry> Networkaddressentry = {};
    SuperLogger *Logger                             = nullptr;
    QList<SuperSender*> Senderboxlist               = {};
    QStringList Stringlist                          = {};
    QString Cachefile                               = "./__depycache__/__tcpclient__/_defaultsetting_.ini";
    QString Spliter                                 = "<split>";

private slots:

    /* main function;*/
    void init();

    void parameterInit();

    void objectInit();

    void widgetListInit();

    void tcpsocketInit();

    void getLocalIpAddress();

    void enableListenPort();

    void enableConnectTcpServer();

    void connectTcpServer();

    void enableSenderBox(
            bool boola);

    void disconnectTcpServer();

    void writeApi(
            QLineEdit* lineeditdata);

    void recordText();

    void readData();

    void enableAddn();

    void enableAddr();

    void changeTypea();

    void changeTypeb();

    void changeTypeapi(
            QCheckBox* checkboxtype,
            QString strtlog,
            QString strllog,
            bool boola,
            bool boolb,
            bool boolc);

    void abnormalDisconnect();

    void adjustSenderBox();

};

#endif // _TCPCLIENTBOX__H
