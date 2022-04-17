#include "_superframe_.h"

SuperFrame::SuperFrame(QWidget *parent)
    : SuperWindow(parent)
{
    Superinitwindow();
    Disablemaxisize();
    Settitle(qApp->applicationVersion());
    Addthemefunction();
    Supertimer();
}

SuperFrame::~SuperFrame()
{

}

void SuperFrame::Superinitwindow()
{
    Initbox = new SuperInit(this);
    connect(Initbox,&SuperInit::Signalia,   this,&SuperFrame::Supermainwindow);
    connect(this,   &SuperFrame::Signalwb,  this,&SuperFrame::Superselectcolor);
    Pluginlayout->addWidget(Initbox);
}

/*  add initbox;*/

void SuperFrame::Supertimer()
{
    Timer = new QTimer(this);
    Timer->setInterval(1000);
    connect(Timer,&QTimer::timeout,this,&SuperFrame::Checkstatus);
    Timer->start();
}

/*  add check supertools repeat opened;*/

void SuperFrame::Checkstatus()
{
    if(!Core->Readonlyfile(Openstatuspath).isEmpty())
    {
        Show();
        Core->Writeonlyfile(Openstatuspath,"");
    }
}

/*  check opened status;*/

void SuperFrame::Supermainwindow(QString setting)
{
    delete Initbox;
    Initbox = nullptr;
    Mainbox = new SuperMain(this,setting);
    Pluginlayout->addWidget(Mainbox);
    Mainbox->Setfocus();
    connect(Mainbox,&SuperMain::Signalma,   Core,&SuperCore::Openpath);
    connect(Mainbox,&SuperMain::Signalmb,   this,&SuperFrame::Quit);
    connect(Mainbox,&SuperMain::Signalmc,   this,&SuperFrame::setCursor);
    connect(this,   &SuperFrame::Signalwa,  Mainbox,&SuperMain::Setfocus);
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

void SuperFrame::Supersystemtray()
{
    Tray = new SuperTray(this);
    connect(Tray,&SuperTray::Signalta,this,&SuperFrame::Quit);
    connect(Tray,&SuperTray::Signaltb,this,&SuperFrame::Show);
}

/*  add system tray;*/

void SuperFrame::Superselectcolor()
{
    SuperColorDialog *colordialog = new SuperColorDialog(nullptr,Backgroundcolor);
    connect(colordialog,&SuperColorDialog::Signalsa,this,       &SuperFrame::Setcolor);
    connect(colordialog,&SuperColorDialog::Signalsa,colordialog,&QObject::deleteLater);
    colordialog->Show();
}

/*  select color;*/

void SuperFrame::Quit()
{
    Tray->setVisible(false);
    close();
    qApp->quit();
}

/*  quit;*/

SuperRepeat::SuperRepeat(QObject *parent)
    : QObject(parent)
{
    Init();
}

SuperRepeat::~SuperRepeat()
{
    qApp->quit();
}

void SuperRepeat::Init()
{
    Objectinit();
    Writeinit();
    Timerinit();
}

void SuperRepeat::Objectinit()
{
    Core = new SuperCore(this);
}

void SuperRepeat::Writeinit()
{
    Core->Writeonlyfile(Openstatuspath,"opened");
}

/*  change opened status;*/

void SuperRepeat::Timerinit()
{
    Timer = new QTimer(this);
    Timer->setInterval(1000);
    connect(Timer,&QTimer::timeout,this,&SuperRepeat::deleteLater);
    Timer->start();
}

/*  close this delay 1000ms;*/

