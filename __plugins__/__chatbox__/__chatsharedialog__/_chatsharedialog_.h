#ifndef _CHATSHAREDIALOG__H
#define _CHATSHAREDIALOG__H

#include "_chatsharebox_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include <QDesktopServices>
#include <QHostInfo>

class GetFileInfoThread;

class ChatShareDialog : public SuperWindow
{
    Q_OBJECT

public:

    ChatShareDialog(
            QWidget *parent = nullptr,
            QLineEdit *lineedit = nullptr);

    ~ChatShareDialog();

    void Refreshsharedfiles();

private:

    ChatShareBox *Plugin            = nullptr;
    QLineEdit *Lineedit             = nullptr;
    GetFileInfoThread *Threadga     = nullptr;
    QString Localuser               = "";
    QString Sharedfolder            = "";
    QString Targetpath              = "";
    QString Sharedfilepath          = "";
    QStringList Fileslist           = {};
    QStringList Fileinfotemp        = {};
    QFileIconProvider Iconprovider  = {};

private slots:

    void Init();

    void Objectinit();

    void Checkuserinit();

    void Openitemoptions();

    void Selectsharedfiles();

    void Addsharedfiles(
            QStringList filelist);

    void Appendtolocal(
            QStringList *fileinfo);

    void Refreshsharedfilesslot(
            QStringList fileinfotemp);

    void Cancelsharedfiles();

    void Writetolocal();

    void Downloadfiles();

    void Selectdownloadpath();

    void Downloadfilesas(
            QString folder);

    void Opencontactfolder();

signals:

    void Signalca(
            int fileindex,
            QString filepath);

};

class GetFileInfoThread : public QThread
{
    Q_OBJECT

public:

    GetFileInfoThread(
            QString sharedfilepath,
            int columncount,
            QString shared,
            QString user,
            QStringList *fileslist,
            QString sharedfolder);

    ~GetFileInfoThread();

public slots:

    void run();

    void Init();

    void Objectinit();

private:

    SuperCore *SuperC       = nullptr;
    QString Sharedfilepath  = "";
    int Columncount         = 0;
    QString Shared          = "";
    QString User            = "";
    QStringList *Fileslist  = nullptr;
    QString Sharedfolder    = "";

signals:

    void Signalga(
            QStringList fileinfotemp);

};

#endif // _CHATSHAREDIALOG__H
