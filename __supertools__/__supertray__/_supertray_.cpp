#include "_supertray_.h"

SuperTray::SuperTray(QWidget *parent)
    : QSystemTrayIcon(parent)
{
    connect(Regedit,        &QAction::triggered,        this,&SuperTray::Openregedit);
    connect(Taskmanager,    &QAction::triggered,        this,&SuperTray::Opentaskmanager);
    connect(Computermanager,&QAction::triggered,        this,&SuperTray::Opencomputermanager);
    connect(Network,        &QAction::triggered,        this,&SuperTray::Opennetwork);
    connect(Quit,           &QAction::triggered,        this,&SuperTray::Closeevent);
    connect(this,           &QSystemTrayIcon::activated,this,&SuperTray::Trayclick);
    Init();
}

SuperTray::~SuperTray()
{
    delete Menu;
}

void SuperTray::Init()
{
    Objectinit();
    Parameterinit();
    Actioninit();
}

/*  system tray init,new action to menu and add function;*/

void SuperTray::Objectinit()
{
    SuperC = new SuperCore(this);
}

/*  object init;*/

void SuperTray::Parameterinit()
{
    setContextMenu(Menu);
    setToolTip("SuperTools");
    setIcon(QIcon(":/__supericon__/_supertools_.ico"));
    show();
}

/*  object init;*/

void SuperTray::Actioninit()
{
    Addactioninfo(Regedit,"regedit",":/__supericon__/_regedit_.png");
    Addactioninfo(Taskmanager,"taskmanager",":/__supericon__/_taskmanager_.png");
    Addactioninfo(Computermanager,"computermanager",":/__supericon__/_computermanager_.png");
    Addactioninfo(Network,"network",":/__supericon__/_network_.svg");
    Menu->addSeparator();
    Addactioninfo(Quit,"quit",":/__supericon__/_quit_.svg");
}

/*  action init;*/

void SuperTray::Addactioninfo(QAction *actiona,QString actionname,QString icopath)
{
    Menu->addAction(actiona);
    actiona->setText(actionname);
    actiona->setIcon(QIcon(icopath));
}

/*  creat new action ,set name and add to menu;*/

void SuperTray::Opentaskmanager()
{
    SuperC->Runcommand("./__depycache__/__cache__/__bat__/_taskmgr_.bat","taskmgr.exe");
}

/*  open windows taskmanager;*/

void SuperTray::Opencomputermanager()
{
    SuperC->Runcommand("./__depycache__/__cache__/__bat__/_compmgmt_.bat","devmgmt.msc");
}

/*  open windows computer manager;*/

void SuperTray::Openregedit()
{
    SuperC->Runcommand("./__depycache__/__cache__/__bat__/_regedit_.bat","regedit.exe");
}

/*  open windows regedit;*/

void SuperTray::Opennetwork()
{
    SuperC->Runcommand("./__depycache__/__cache__/__bat__/_network_.bat","ncpa.cpl");
}

/*  Open windows network;*/

void SuperTray::Trayclick(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick)
    {
        emit Signaltb();
    }
}

/*  click or double click show main window;*/

void SuperTray::Closeevent()
{
    emit Signaltb();
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"you sure to quit?");
    connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperTray::Signalta);
    notedialog->Messageinit();
}

/*  when close app ,show window first and choose if close;*/
