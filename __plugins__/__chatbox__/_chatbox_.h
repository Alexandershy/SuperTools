#ifndef _CHATBOX__H
#define _CHATBOX__H
#define _CHATBOX__EXPORT Q_DECL_EXPORT

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
#include "__module__/_chatmodulea_.h"
#include "__module__/_chatmoduleb_.h"
#include "__module__/_chatmodulec_.h"
#include "__module__/_chatmoduled_.h"
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

    SuperNetwork *Network                       = nullptr;
    ChatModuleA *Modulea                        = nullptr;
    ChatModuleB *Moduleb                        = nullptr;
    ChatModuleC *Modulec                        = nullptr;
    ChatModuleD *Moduled                        = nullptr;
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

    void init();

    void moduleInit();

    void clientInit();

    void serverInit();

    void userInit();

    void openProfile();

    void openSharedFiles();

    void getContacts();

    void getContactstSlot();

    void getContactsfSlot();

    void openContacts();

    void addContactsMessageRecord();

    void getFileInfo(
            QByteArray fileindex);

    void getFileByteStop();

    void getFileByteEnd();

    void copyToTargetPath();

    void getFileInfoSlot();

    bool replaceFile(
            QString filename,
            QString filesize,
            QString filehash);

    void getFileByte();

    void getFileByteSlot();

    void openContactsShared();

    void downloadSharedFiles(
            int fileindex,
            QString path);

    void enableSendButton();

    void getChatAnwser();

    void moveToBottom();

    void getChatAnwsertSlot();

    void getChatAnwserfSlot();

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

    void newFileInfoTcpsocket();

    void newFileByteTcpsocket();

    void returnContacts();

    void returnFileInfo();

    void returnFileByte();

    void returnChatAnwser();

signals:

    void signalCa();

    void signalCb();
};


#endif // _CHATBOX__H
