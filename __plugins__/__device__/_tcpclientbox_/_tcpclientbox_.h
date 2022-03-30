#ifndef _TCPCLIENTBOX__H
#define _TCPCLIENTBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__supernetwork__/_supernetwork_.h"
#include "__supersender__/_supersender_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "_tcpclientbox__global.h"
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

    SuperNetwork *SuperN                            = nullptr;
    ModuleA *Modulea                                = nullptr;
    ModuleB *Moduleb                                = nullptr;
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

    void Init();

    void Parameterinit();

    void Objectinit();

    void Widgetlistinit();

    void Tcpsocketinit();

    void Getlocalipaddress();

    void Enablelistenport();

    void Enableconnecttcpserver();

    void Connecttcpserver();

    void Enablesenderbox(
            bool boola);

    void Disconnecttcpserver();

    void Writeapi(
            QLineEdit* lineeditdata);

    void Recordtext();

    void Readdata();

    void Enableaddn();

    void Enableaddr();

    void Changetypea();

    void Changetypeb();

    void Changetypeapi(
            QCheckBox* checkboxtype,
            QString strtlog,
            QString strllog,
            bool boola,
            bool boolb,
            bool boolc);

    void Abnormaldisconnect();

    void Adjustsenderbox();

};

#endif // _TCPCLIENTBOX__H
