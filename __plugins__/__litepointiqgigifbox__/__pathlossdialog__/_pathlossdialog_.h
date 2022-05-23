#ifndef _PATHLOSSDIALOG__H
#define _PATHLOSSDIALOG__H

#include "__supercore__/_supercore_.h"
#include "__superwindow__/_superwindow_.h"
#include "_pathlossdialogui_.h"
#include <QAction>
#include <QMenu>

class PathLossConfigMenu;
class PathLossDataMenu;
class PathLossSettingMenu;

class PathLossDialog : public SuperWindow
{
    Q_OBJECT

public:

    PathLossDialogui *Plugin            = nullptr;
    PathLossConfigMenu *Configmenu      = nullptr;
    PathLossDataMenu *Datamenu          = nullptr;
    PathLossSettingMenu *Settingmenu    = nullptr;

public:

    PathLossDialog(
            QWidget *parent = nullptr);

    ~PathLossDialog();

private:

    QString Titleobjectname             = nullptr;

private slots:

    /*  main function;*/
    void init();

    void objectInit();

    void openPathLossConfigMenu();

    void openPathLossDataMenu();

    void openPathLossSettingMenu();

signals:

    void signalIn();

    void signalIs();

    void signalId();

};

class PathLossDataMenu : public QMenu
{
    Q_OBJECT

public:

    QAction *Newrow     = new QAction(this);
    QAction *Save       = new QAction(this);
    QAction *Deleterow  = new QAction(this);

public:

    /*  main function;*/
    PathLossDataMenu(
            QWidget *parent = nullptr);

public slots:

    void creatAction();

private:

    SuperCore *Core   = nullptr;

};

class PathLossConfigMenu : public QMenu
{
    Q_OBJECT

public:

    QAction *Newconfig      = new QAction(this);
    QAction *Save           = new QAction(this);
    QAction *Deleteconfig   = new QAction(this);
    QAction *Importcsv      = new QAction(this);
    QAction *Exportcsv      = new QAction(this);

public:

    /*  main function;*/
    PathLossConfigMenu(
            QWidget *parent = nullptr);

public slots:

    void creatAction();

private:

    SuperCore *Core = nullptr;

};

class PathLossSettingMenu : public QMenu
{
    Q_OBJECT

public:

    QAction *Apply = new QAction(this);

public:

    /*  main function;*/
    PathLossSettingMenu(
            QWidget *parent = nullptr);

public slots:

    void creatAction();

private:

    SuperCore *Core = nullptr;

};


#endif // _PATHLOSSDIALOG__H
