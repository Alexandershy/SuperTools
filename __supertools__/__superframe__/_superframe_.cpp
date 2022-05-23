#include "_superframe_.h"

SuperFrame::SuperFrame(QWidget *parent)
    : SuperWindow(parent)
{
    superInitWindow();
    disableMaxisize();
    setTitle(qApp->applicationVersion());
    addThemeFunction();
    superTimer();
}

SuperFrame::~SuperFrame()
{

}

void SuperFrame::superInitWindow()
{
    Initbox = new SuperInit(this);
    connect(Initbox,&SuperInit::signalIa,   this,&SuperFrame::superMainWindow);
    connect(this,   &SuperFrame::signalWb,  this,&SuperFrame::superSelectColor);
    Pluginlayout->addWidget(Initbox);
}

/*  add initbox;*/

void SuperFrame::superTimer()
{
    Timer = new QTimer(this);
    Timer->setInterval(1000);
    connect(Timer,&QTimer::timeout,this,&SuperFrame::checkStatus);
    Timer->start();
}

/*  add check supertools repeat opened;*/

void SuperFrame::checkStatus()
{
    if(!Core->readOnlyFile(Openstatuspath).isEmpty())
    {
        show();
        Core->writeOnlyFile(Openstatuspath,"");
    }
}

/*  check opened status;*/

void SuperFrame::superMainWindow(QString setting)
{
    delete Initbox;
    Initbox = nullptr;
    Mainbox = new SuperMain(this,setting);
    Pluginlayout->addWidget(Mainbox);
    Mainbox->setFocus();
    connect(Mainbox,&SuperMain::signalMa,   Core,&SuperCore::openPath);
    connect(Mainbox,&SuperMain::signalMb,   this,&SuperFrame::quit);
    connect(Mainbox,&SuperMain::signalMc,   this,&SuperFrame::setCursor);
    connect(this,   &SuperFrame::signalWa,  Mainbox,&SuperMain::setFocus);
    addFrameFunction();
    addResizeFunction();
    addMenu(Mainbox->Load,"Load",false);
    addMenu(Mainbox->Config,"Config",false);
    addMenu(Mainbox->Help,"Help",true);
    addAction(Mainbox->Actionsave);
    addAction(Mainbox->Actionsaveas);
    addAction(Mainbox->Actionquit);
    superSystemTray();
    moveCenter(Mainbox);
}

/*  add mainbox;*/

void SuperFrame::superSystemTray()
{
    Tray = new SuperTray(this);
    connect(Tray,&SuperTray::Signalta,this,&SuperFrame::quit);
    connect(Tray,&SuperTray::Signaltb,this,&SuperFrame::show);
}

/*  add system tray;*/

void SuperFrame::superSelectColor()
{
    SuperColorDialog *colordialog = new SuperColorDialog(nullptr,Backgroundcolor);
    connect(colordialog,&SuperColorDialog::signalSa,this,       &SuperFrame::setColor);
    connect(colordialog,&SuperColorDialog::signalSa,colordialog,&QObject::deleteLater);
    colordialog->show();
}

/*  select color;*/

void SuperFrame::quit()
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
    objectInit();
    writeInit();
    timerInit();
}

void SuperRepeat::objectInit()
{
    Core = new SuperCore(this);
}

void SuperRepeat::writeInit()
{
    Core->writeOnlyFile(Openstatuspath,"opened");
}

/*  change opened status;*/

void SuperRepeat::timerInit()
{
    Timer = new QTimer(this);
    Timer->setInterval(1000);
    connect(Timer,&QTimer::timeout,this,&SuperRepeat::deleteLater);
    Timer->start();
}

/*  close this delay 1000ms;*/

