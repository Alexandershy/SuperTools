#include "_super_.h"

SuperWindow* Interface::Loadplugin()
{
    return new SuperTools();
}

/*  return class supertools new instance pointer;*/

SuperTools::SuperTools()
{
    Superinitwindow();
    Disablemaxisize();
    Settitle(qApp->applicationVersion());
    Addthemefunction();
    Supertimer();
}

void SuperTools::Superinitwindow()
{
    Initbox = new SuperInit(this);
    connect(Initbox,&SuperInit::Signalia,   this,&SuperTools::Supermainwindow);
    connect(this,   &SuperTools::Signalwb,  this,&SuperTools::Superselectcolor);
    Pluginlayout->addWidget(Initbox);
    Show();
    Movecenter(this);
}

/*  add initbox;*/

void SuperTools::Supertimer()
{
    Timer = new QTimer(this);
    Timer->setInterval(1000);
    connect(Timer,&QTimer::timeout,this,&SuperTools::Checkstatus);
    Timer->start();
}

/*  add check supertools repeat opened;*/

void SuperTools::Checkstatus()
{
    if(!SuperC->Readonlyfile(Openstatuspath).isEmpty())
    {
        Show();
        SuperC->Writeonlyfile(Openstatuspath,"");
    }
}

/*  check opened status;*/

void SuperTools::Supermainwindow(QString setting)
{
    delete Initbox;
    Initbox = nullptr;
    Mainbox = new SuperMain(this,setting);
    Pluginlayout->addWidget(Mainbox);
    Mainbox->Setfocus();
    connect(Mainbox,&SuperMain::Signalma,   this,&SuperTools::Superreadme);
    connect(Mainbox,&SuperMain::Signalmb,   this,&SuperTools::Quit);
    connect(Mainbox,&SuperMain::Signalmc,   this,&SuperTools::setCursor);
    connect(this,   &SuperTools::Signalwa,  Mainbox,&SuperMain::Setfocus);
    Addframefunction();
    Addresizefunction();
    Addmenu(Mainbox->Load,"Load",false);
    Addmenu(Mainbox->Config,"Config",false);
    Addmenu(Mainbox->Help,"Help",true);
    Addaction(Mainbox->Actionsave);
    Addaction(Mainbox->Actionsaveas);
    Addaction(Mainbox->Actionquit);
    Supersystemtray();
    Movecenter(Mainbox);
}

/*  add mainbox;*/

void SuperTools::Superreadme(QString filepath)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));
}

/*  open current module's readme;*/

void SuperTools::Supersystemtray()
{
    Tray = new SuperTray(this);
    connect(Tray,&SuperTray::Signalta,this,&SuperTools::Quit);
    connect(Tray,&SuperTray::Signaltb,this,&SuperTools::Show);
}

/*  add system tray;*/

void SuperTools::Superselectcolor()
{
    SuperColorDialog *colordialog = new SuperColorDialog(nullptr,Backgroundcolor);
    connect(colordialog,&SuperColorDialog::Signalsa,this,       &SuperTools::Setcolor);
    connect(colordialog,&SuperColorDialog::Signalsa,colordialog,&QObject::deleteLater);
    colordialog->Show();
}

/*  select color;*/

void SuperTools::Quit()
{
    Tray->setVisible(false);
    close();
    qApp->quit();
}

/*  quit;*/
