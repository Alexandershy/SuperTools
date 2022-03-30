#include "_resuper_.h"

QWidget* Interface::Loadplugin()
{
    return new Resuper();
}

/*  return class resuper new instance pointer;*/

Resuper::Resuper(QWidget *parent)
    : QWidget(parent)
{
    Init();
}

Resuper::~Resuper()
{

}

void Resuper::Init()
{
    Objectinit();
    Writeinit();
    Timerinit();
}

void Resuper::Objectinit()
{
    SuperC = new SuperCore(this);
}

void Resuper::Writeinit()
{
    SuperC->Writeonlyfile(Openstatuspath,"opened");
}

/*  change opened status;*/

void Resuper::Timerinit()
{
    Timer = new QTimer(this);
    Timer->setInterval(1000);
    connect(Timer,&QTimer::timeout,this,&Resuper::Closeapp);
    Timer->start();
}

/*  close this delay 1000ms;*/

void Resuper::Closeapp()
{
    qApp->quit();
}

/*  run close function;*/
