#ifndef _CHATBOX__H
#define _CHATBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superwindow__/_superwindow_.h"
#include "__supernetwork__/_supernetwork_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__chatinfodialog__/_chatinfodialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__chatsharedialog__/_chatsharedialog_.h"
#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "__chatter__/_chatter_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "__module__/_modulec_.h"
#include "__module__/_moduled_.h"
#include "_chatbox__global.h"
#include <QTimer>
#include <QDir>

/**************interface****************/
class _CHATBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class chatbox new instance pointer;*/
};

class ChatBox : public SuperTab
{
    Q_OBJECT

public:

    ChatBox(
            QWidget *parent = nullptr);

    ~ChatBox();

protected:

    void resizeEvent(QResizeEvent *event);

private:

    SuperNetwork *SuperN                        = nullptr;
    ModuleA *Modulea                            = nullptr;
    ModuleB *Moduleb                            = nullptr;
    ModuleC *Modulec                            = nullptr;
    ModuleD *Moduled                            = nullptr;
    QUdpSocket *Udppackclient                   = nullptr;
    QTcpSocket *Tcpfileinfoclient               = nullptr;
    QTcpSocket *Tcpfilebyteclient               = nullptr;
    QUdpSocket *Udpchatclient                   = nullptr;
    ChatInfoDialog *Infodialog                  = nullptr;
    SuperProgressBarDialog *Progressbardialog   = nullptr;
    QTimer *Timerca                             = nullptr;
    QTimer *Timercb                             = nullptr;
    QHostAddress Hostaddress                    = {};
    QString Contactsname                        = "";
    QString Contactsfolder                      = "";
    QString Targetfolder                        = "";
    int Fileindexreceiving                      = -1;
    QString Messagerecorded                     = "";
    qint64 Tranfilesize                         = 0;
    QString Tranfilepath                        = "";
    QString Tranfilehash                        = "";
    qint64 Trandatasize                         = 1024000;
    qint64 Tranwritecompletedsize               = 0;
    QByteArray Trandata                         = "";
    QString Tranendmessage                      = "";

private slots:

    void Init();

    void Moduleinit();

    void Clientinit();

    void Serverinit();

    void Userinit();

    void Openprofile();

    void Opensharedfiles();

    void Getcontacts();

    void Getcontactstslot();

    void Getcontactsfslot();

    void Opencontacts();

    void Addcontactsmessagerecord();

    void Getfileinfo(
            QByteArray fileindex);

    void Getfilebytestop();

    void Getfilebyteend();

    void Copytotargetpath();

    void Getfileinfoslot();

    bool Replacefile(
            QString filename,
            QString filesize,
            QString filehash);

    void Getfilebyte();

    void Getfilebyteslot();

    void Opencontactsshared();

    void Downloadsharedfiles(
            int fileindex,
            QString path);

    void Enablesendbutton();

    void Getchatanwser();

    void Movetobottom();

    void Getchatanwsertslot();

    void Getchatanwserfslot();

//***************************************************Server*********************************************************//

private:

    QUdpSocket *Udppackserver       = nullptr;
    QTcpServer *Tcpfileinfoserver   = nullptr;
    QTcpServer *Tcpfilebyteserver   = nullptr;
    QUdpSocket *Udpchatserver       = nullptr;
    QString Username                = "";
    QString Userfolder              = "";
    QString Userprofile             = "";
    QString Usersharedfile          = "";
    QStringList Userfile            = {};
    QStringList Fileinfolist        = {};

private slots:

    void Newfileinfotcpsocket();

    void Newfilebytetcpsocket();

    void Returncontacts();

    void Returnfileinfo();

    void Returnfilebyte();

    void Returnchatanwser();

signals:

    void Signalca();

    void Signalcb();
};


#endif // _CHATBOX__H
