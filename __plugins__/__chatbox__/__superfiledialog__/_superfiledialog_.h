#ifndef _SUPERFILEDIALOG__H
#define _SUPERFILEDIALOG__H

#include "_superfilebox_.h"
#include "_superfilesystemmodel_.h"
#include "__superwindow__/_superwindow_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include <QFileIconProvider>
#include <QStandardPaths>

class SuperFileDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperFileDialog(
            QWidget *parent = nullptr,
            QString folderpath = "",
            QStringList filterlist = {});

    ~SuperFileDialog();

    void Setsinglefile();

    void Setsavefile();

    void Setsavefolder();

private:

    SuperFileBox *Plugin                        = nullptr;
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

    void Init();

    void Objectinit();

    void Dirinit();

    void Systemmodelinit();

    void Menuinit();

    void Iconinit();

    void Quickaccessinit();

    void Locationpathinit();

    void Treewidgetadditemapi(
            QStandardPaths::StandardLocation path);

    void Transfermodelindex(
            QModelIndex index);

    void Checkfolder();

    void Refreshquickaccessfolder();

    void Refreshfolder(
            QString folderpath);

    void Fileinfomode();

    void Filepicturemode();

    void Getfilesavemode();

    void Getfile();

    void Savefile();

    void Getfoldersavemode();

    void Savefolder();

    bool Checkrepeatfile(
            QString filename,
            QString filesuffix);

    void Getfilelist();

    void Enableselectfilebutton();

    void Enablesavefilebutton();

    void Cdupfolder();

    void Execfilemenu();

    void Exectreemenu();

    void Openfiles();

    void Openpaths();

    void Replacefile();

    void Creatnewfolder();

    void Delete();

    void Searchfile(
            QString text);

    void Addtoquickaccess();

    void Changefileiconmode();

    void Deletequickaccess();

    void Expandmodelfolder(
        QDir *dir);

signals:

    void Signalfa();

    void Signalfb(
            QString file);

    void Signalfc(
            QStringList filelist);

};

#endif // _SUPERFILEDIALOG__H
