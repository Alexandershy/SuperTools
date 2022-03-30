#ifndef _PATHLOSSDIALOG__H
#define _PATHLOSSDIALOG__H

#include "__supercore__/_supercore_.h"
#include "__superwindow__/_superwindow_.h"
#include "_pathlossbox_.h"
#include <QAction>
#include <QMenu>

class PathLossConfigMenu;
class PathLossDataMenu;
class PathLossSettingMenu;

class PathLossDialog : public SuperWindow
{
    Q_OBJECT

public:

    PathLossBox *Plugin                 = nullptr;
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

    void Init();

    void Objectinit();

    void Openpathlossconfigmenu();

    void Openpathlossdatamenu();

    void Openpathlosssettingmenu();

signals:

    void Signalin();

    void Signalis();

    void Signalid();

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

    void Creataction();

private:

    SuperCore *SuperC   = nullptr;

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

    void Creataction();

private:

    SuperCore *SuperC = nullptr;

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

    void Creataction();

private:

    SuperCore *SuperC = nullptr;

};


#endif // _PATHLOSSDIALOG__H
