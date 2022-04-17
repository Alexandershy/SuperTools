#ifndef _SUPERFILEMANAGER__H
#define _SUPERFILEMANAGER__H
#define _SUPERFILEMANAGER__EXPORT Q_DECL_EXPORT

#include "__superfiledialog__/_superfiledialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__supercore__/_supercore_.h"
#include "ui__superfilemanagerui_.h"
#include <QScrollBar>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperFileManagerui; }
QT_END_NAMESPACE

class _SUPERFILEMANAGER__EXPORT SuperFileManager : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperFileManagerui *ui      = nullptr;
    QStringList Filelist            = {};
    QList<QWidget*> Widgetlist      = {};
    QList<QCheckBox*> Checkboxlist  = {};

public:

    SuperFileManager(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr,
        QStringList filesplit = {});

    ~SuperFileManager();

public slots:

    void Disableopen();

    QString Getcurrentitemtext();

    void Enablewidgetlist();

    void Personalization(
        QString sourcepath,
        QString text);

    void Setcurrentfile(
        QString filetemp);

    void Checkfilevaildinit();

private:

    SuperCore *Core                 = nullptr;
    QMenu *Filemenu                 = nullptr;
    QAction *Openfile               = nullptr;
    QAction *Openpath               = nullptr;
    QAction *Deletefile             = nullptr;
    QMenu *Tablemenu                = nullptr;
    QAction *Importfiles            = nullptr;
    QAction *Deleteallfiles         = nullptr;
    QLayout *Layout                 = nullptr;
    QWidget *Widget                 = nullptr;
    QString Cachesetting            = "";
    QString Split                   = "<split>";
    QStringList Filesplit           = {};
    QFileIconProvider Iconprovider  = {};
    QStringList Fileinfoheader      = {"ID","Name","Path","Size"};
    QString Sourcepath              = "./";
    QString Filetemp                = "";
    QString Filesuffix              = "Super";
    QList<int> Invaildfilelist      = {};

private slots:

    void Init();

    void Parameterinit();

    void Objectinit();

    void Addactioninit();

    void Headerviewinit();

    void Loadfilesinit();

    void Importfilesslot();

    void Clearfileinit();

    void Cleartreewidget();

    void Setfiles(
        QStringList filelistinput);

    void Searchfiles(
        QString text);

    void Itemoptions();

    void Tableoptions();

    void Clickopen();

    void Actionopen();

    void Openfilepath();

    bool Openinit();

    void Deletefilesinit();

    void Deletefiles();

    void Resetindex();

    void Disableopentips();

    void Locationfile();

    void Checkfilevaild();

    void Deleteinvaildfiles();

signals:

    void Signalfa(
        QString direction,
        QString tlogs,
        QString llogs);

    void Signalfb();

    void Signalfc();

    void Signalfd();

    void Signalfe(
        QString file);

};

#endif // _SUPERFILEMANAGER__H

