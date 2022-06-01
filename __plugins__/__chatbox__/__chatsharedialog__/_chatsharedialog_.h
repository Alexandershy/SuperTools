#ifndef _CHATSHAREDIALOG__H
#define _CHATSHAREDIALOG__H

#include "_chatsharedialogui_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include <QDesktopServices>
#include <QHostInfo>
#include <QLineEdit>

class GetFileInfoThread;

class ChatShareDialog : public SuperWindow
{
    Q_OBJECT

public:

    ChatShareDialog(
            QWidget *parent = nullptr,
            QLineEdit *lineedit = nullptr);

    ~ChatShareDialog();

public slots:

    void refreshSharedFiles();

private:

    ChatShareDialogui *Plugin       = nullptr;
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

    void init();

    void objectInit();

    void checkUserInit();

    void openItemOptions();

    void selectSharedFiles();

    void addSharedFiles(
            QStringList filelist);

    void appendToLocal(
            QStringList *fileinfo);

    void refreshSharedFilesSlot(
            QStringList fileinfotemp);

    void cancelSharedFiles();

    void writeToLocal();

    void downloadFiles();

    void selectDownloadPath();

    void downloadFilesAs(
            QString folder);

    void openContactFolder();

signals:

    void signalCa(
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

    void init();

    void objectInit();

private:

    SuperCore *Core         = nullptr;
    QString Sharedfilepath  = "";
    int Columncount         = 0;
    QString Shared          = "";
    QString User            = "";
    QStringList *Fileslist  = nullptr;
    QString Sharedfolder    = "";

signals:

    void signalGa(
            QStringList fileinfotemp);

};

#endif // _CHATSHAREDIALOG__H
