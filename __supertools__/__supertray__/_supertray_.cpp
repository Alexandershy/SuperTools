#include "_supertray_.h"

SuperTray::SuperTray(QWidget *parent)
    : QSystemTrayIcon(parent)
{
    connect(Regedit,        &QAction::triggered,        this,&SuperTray::openRegedit);
    connect(Taskmanager,    &QAction::triggered,        this,&SuperTray::openTaskManager);
    connect(Computermanager,&QAction::triggered,        this,&SuperTray::openComputerManager);
    connect(Network,        &QAction::triggered,        this,&SuperTray::openNetwork);
    connect(Quit,           &QAction::triggered,        this,&SuperTray::close);
    connect(this,           &QSystemTrayIcon::activated,this,&SuperTray::trayClick);
    init();
}

SuperTray::~SuperTray()
{
    delete Menu;
}

void SuperTray::init()
{
    objectInit();
    parameterInit();
    actionInit();
}

/*  system tray init,new action to menu and add function;*/

void SuperTray::objectInit()
{
    Core = new SuperCore(this);
}

/*  object init;*/

void SuperTray::parameterInit()
{
    setContextMenu(Menu);
    setToolTip("SuperTools");
    setIcon(QIcon(":/__supericon__/_supertools_.ico"));
    show();
}

/*  object init;*/

void SuperTray::actionInit()
{
    addActionInfo(Regedit,"regedit",":/__supericon__/_regedit_.png");
    addActionInfo(Taskmanager,"taskmanager",":/__supericon__/_taskmanager_.png");
    addActionInfo(Computermanager,"computermanager",":/__supericon__/_computermanager_.png");
    addActionInfo(Network,"network",":/__supericon__/_network_.svg");
    Menu->addSeparator();
    addActionInfo(Quit,"quit",":/__supericon__/_quit_.svg");
}

/*  action init;*/

void SuperTray::addActionInfo(QAction *actiona,QString actionname,QString icopath)
{
    Menu->addAction(actiona);
    actiona->setText(actionname);
    actiona->setIcon(QIcon(icopath));
}

/*  creat new action ,set name and add to menu;*/

void SuperTray::openTaskManager()
{
    Core->runCommand("./__depycache__/__cache__/__bat__/_taskmgr_.bat","taskmgr.exe");
}

/*  open windows taskmanager;*/

void SuperTray::openComputerManager()
{
    Core->runCommand("./__depycache__/__cache__/__bat__/_compmgmt_.bat","devmgmt.msc");
}

/*  open windows computer manager;*/

void SuperTray::openRegedit()
{
    Core->runCommand("./__depycache__/__cache__/__bat__/_regedit_.bat","regedit.exe");
}

/*  open windows regedit;*/

void SuperTray::openNetwork()
{
    Core->runCommand("./__depycache__/__cache__/__bat__/_network_.bat","ncpa.cpl");
}

/*  Open windows network;*/

void SuperTray::trayClick(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick)
    {
        emit Signaltb();
    }
}

/*  click or double click show main window;*/

void SuperTray::close()
{
    emit Signaltb();
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"you sure to quit?");
    connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperTray::Signalta);
    notedialog->messageInit();
}

/*  when close app ,show window first and choose if close;*/
