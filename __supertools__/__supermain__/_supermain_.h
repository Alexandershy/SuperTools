#ifndef _SUPERMAIN__H
#define _SUPERMAIN__H

#include "__superfiledialog__/_superfiledialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__supertabwidget__/_supertabwidget_.h"
#include "__supercore__/_supercore_.h"
#include <QDesktopServices>
#include <QGroupBox>
#include <QKeyEvent>
#include <QLibrary>
#include <QProcess>

class SuperMain : public SuperTabWidget
{
    Q_OBJECT

public:

    QMenu *Load                     = nullptr;
    QMenu *Help                     = nullptr;
    QMenu *Config                   = nullptr;
    QAction *Actionsave             = nullptr;
    QAction *Actionsaveas           = nullptr;
    QAction *Actionquit             = nullptr;

public:

    SuperMain(
            QWidget *window = nullptr,
            QString setting = nullptr);

    ~SuperMain();

public slots:

    void setFocus();

protected:

    void keyPressEvent(
        QKeyEvent *event);

    void enterEvent(
        QEnterEvent *);

private:

    SuperCore *Core                 = nullptr;
    QString Setting                 = "";
    QStringList Tabnamelist         = {};
    QAction *Actionplugin           = nullptr;
    QAction *Actionsetting          = nullptr;
    QAction *Actionchangelanguage   = nullptr;
    QAction *Actionopencachepath    = nullptr;
    QAction *Actionversion          = nullptr;
    QAction *Actionreadme           = nullptr;
    QAction *Actionsuperapi         = nullptr;

    //function;
    typedef QGroupBox*(*Groupboxfun)();

    //loaddll;
    Groupboxfun Tab;

private slots:

    void init();

    void objectInit();

    void actionInit();

    void loadSetting();

    void loadPlugin();

    void importPlugins(
            QStringList listsuper);

    void importSetting(
            QString strini);

    void addTabApi(
            QString strdllname,
            QString strtabname,
            QString strobjname);

    void addTab(
            QString strtabname,
            QWidget* widget,
            QString strobjname);

    void showTab(
            QStringList *listobjname,
            QString strobjname);

    void save();

    void saveSetting(
            QString strtitle);

    void saveAs();

    void openCachePath();

    void checkVersion();

    void readme();

    void superApi();

    void openCloseTabBox(
            int intindex);

    void closeTab();

    void close();

signals:

    void signalMa(
            QString filepath);

    void signalMb();

    void signalMc(
        Qt::CursorShape shape);

};

#endif // _SUPERMAIN__H
