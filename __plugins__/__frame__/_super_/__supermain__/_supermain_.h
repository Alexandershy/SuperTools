#ifndef _SUPERMAIN__H
#define _SUPERMAIN__H

#include "__superfiledialog__/_superfiledialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__supertabwidget__/_supertabwidget_.h"
#include "__supercore__/_supercore_.h"
#include <QDesktopServices>
#include <QLibrary>
#include <QProcess>
#include <QKeyEvent>

class SuperMain : public SuperTabWidget
{
    Q_OBJECT

public:

    SuperMain(
            QWidget *window = nullptr,
            QString setting = nullptr);

    ~SuperMain();

    void Setfocus();

    QMenu *Load                     = nullptr;
    QMenu *Help                     = nullptr;
    QMenu *Config                   = nullptr;
    QAction *Actionsave             = nullptr;
    QAction *Actionsaveas           = nullptr;
    QAction *Actionquit             = nullptr;

protected:

    void keyPressEvent(
        QKeyEvent *event);

    void enterEvent(
        QEnterEvent *);

private:

    SuperCore *SuperC               = nullptr;
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

    void Init();

    void Parameterinit();

    void Objectinit();

    void Actioninit();

    void Loadsetting();

    void Loadmodule();

    void Importplugins(
            QStringList listsuper);

    void Importsetting(
            QString strini);

    void Addtabapi(
            QString strdllname,
            QString strtabname,
            QString strobjname);

    void Addtab(
            QString strtabname,
            QWidget* widget,
            QString strobjname);

    void Showtab(
            QStringList *listobjname,
            QString strobjname);

    void Save();

    void Savesetting(
            QString strtitle);

    void Saveas();

    void Opencachepath();

    void Checkversion();

    void Readme();

    void Superapi();

    void Openclosetabbox(
            int intindex);

    void Closetab();

    void Closeevent();

signals:

    void Signalma(
            QString filepath);

    void Signalmb();

    void Signalmc(
        Qt::CursorShape shape);

};

#endif // _SUPERMAIN__H
