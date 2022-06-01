#ifndef _SUPERFILEMANAGER__H
#define _SUPERFILEMANAGER__H
#define _SUPERFILEMANAGER__EXPORT Q_DECL_EXPORT

#include "__superfiledialog__/_superfiledialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__supercore__/_supercore_.h"
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

    void disableOpen();

    QString getCurrentItemText();

    void enableWidgetList();

    void personalization(
        QString sourcepath,
        QString text);

    void setCurrentFile(
        QString filetemp);

    void checkFileVaildInit();

    QTableWidgetItem *firstItem(
        int rowindex);

    QTableWidgetItem* currentItem();

    void setCurrentItem(
        QTableWidgetItem* item);

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

    void init();

    void parameterInit();

    void objectInit();

    void addActionInit();

    void headerViewInit();

    void loadFilesInit();

    void importFilesSlot();

    void clearFileInit();

    void clearTreeWidget();

    void setFiles(
        QStringList filelistinput);

    void searchFiles(
        QString text);

    void itemOptions();

    void tableOptions();

    void clickOpen();

    void actionOpen();

    void openFilePath();

    bool openInit();

    void deleteFilesInit();

    void deleteFiles();

    void resetIndex();

    void disableOpenTips();

    void locationFile();

    void checkFileVaild();

    void deleteInvaildFiles();

signals:

    void signalFa(
        QString direction,
        QString tlogs,
        QString llogs);

    void signalFb();

    void signalFc();

    void signalFd();

    void signalFe(
        QString file);

};

#endif // _SUPERFILEMANAGER__H

