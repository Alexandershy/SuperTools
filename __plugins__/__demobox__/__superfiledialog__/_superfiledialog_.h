#ifndef _SUPERFILEDIALOG__H
#define _SUPERFILEDIALOG__H
#define _SUPERFILEDIALOG__EXPORT Q_DECL_EXPORT

#include "__superwindow__/_superwindow_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "_superfiledialogui_.h"
#include "_superfilesystemmodel_.h"
#include <QFileIconProvider>
#include <QStandardPaths>

class _SUPERFILEDIALOG__EXPORT SuperFileDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperFileDialog(
            QWidget *parent = nullptr,
            QString folderpath = "",
            QStringList filterlist = {});

    ~SuperFileDialog();

public slots:

    void setSingleFile();

    void setSaveFile();

    void setSaveFolder();

private:

    SuperFileDialogui *Plugin                   = nullptr;
    SuperFileSystemModel *Filesystemmodel       = nullptr;
    QDir *Dir                                   = nullptr;
    QMenu *Filemenu                             = nullptr;
    QAction *Selectfile                         = nullptr;
    QAction *Openfile                           = nullptr;
    QAction *Openpath                           = nullptr;
    QAction *Deletefile                         = nullptr;
    QMenu *Treemenu                             = nullptr;
    QAction *Openfolder                         = nullptr;
    QAction *Unpin                              = nullptr;
    int Rowcounts                               = 0;
    int Columncounts                            = 4;
    QStringList Filterlist                      = {};
    QString Foldersourcepath                    = "";
    QString Folderabsolutepath                  = "";
    QFileInfoList Fileinfolist                  = {};
    QFileInfoList Folderinfolist                = {};
    QFileInfoList Allfileinfolist               = {};
    int Dialogmode                              = 0;
    int Currentfileindex                        = 0;
    QVector<QVector<QString>> Filemenutext      = {{"Select file","Open file","Open path","Delete file"},{"Select file","Open file","Open path","Delete file"},{"Replace file","Open file","Open path","Delete file"},{"Select path","Open file","Open path","Delete file"}};
    QVector<QVector<QString>> Foldermenutext    = {{"Open folder","No function","Open path","Delete folder"},{"Open folder","No function","Open path","Delete folder"},{"Open folder","No function","Open path","Delete folder"},{"Open folder","No function","Open path","Delete folder"}};
    QVector<int> Path                           = {0,1};
    QFileIconProvider Iconprovider              = {};
    QString Locationpath                        = "./__depycache__/__cache__/__ini__/_quickaccess_.ini";
    int Quickaccesscounts                       = 0;
    int Fileiconmode                            = 32;
    QList<QLabel*> Lablelist                    = {};
    QStringList Fileinfoheader                  = {"Name","Size","Creat date","Type"};
    QStringList Filepictureheader               = {"Picture","Name","Size","Type"};

private slots:

    void init();

    void objectInit();

    void dirInit();

    void systemModelInit();

    void menuInit();

    void iconInit();

    void quickAccessInit();

    void locationPathInit();

    void treeWidgetAddItemApi(
            QStandardPaths::StandardLocation path);

    void transferModelIndex(
            QModelIndex index);

    void checkFolder();

    void refreshQuickAccessFolder();

    void refreshFolder(
            QString folderpath);

    void fileInfoMode();

    void filePictureMode();

    void getFileSaveMode();

    void getFile();

    void saveFile();

    void getFolderSaveMode();

    void saveFolder();

    bool checkRepeatFile(
            QString filename,
            QString filesuffix);

    void getFileList();

    void enableSelectFileButton();

    void enableSaveFileButton();

    void cdUpFolder();

    void execFileMenu();

    void execTreeMenu();

    void openFiles();

    void openPaths();

    void replaceFile();

    void creatNewFolder();

    void deleteitem();

    void searchFile(
            QString text);

    void addToQuickAccess();

    void changeFileIconMode();

    void deleteQuickAccess();

    void expandModelFolder(
        QDir *dir);

signals:

    void signalFa();

    void signalFb(
            QString file);

    void signalFc(
            QStringList filelist);

};

#endif // _SUPERFILEDIALOG__H
