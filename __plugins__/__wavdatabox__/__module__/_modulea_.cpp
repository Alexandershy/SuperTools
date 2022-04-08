#include "_modulea_.h"

ModuleA::ModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    Init();
}

ModuleA::~ModuleA()
{
    delete ui;
}

void ModuleA::Init()
{
    Objectinit();
    Parameterinit();
    Iconinit();
}

/*  object init;*/

void ModuleA::Objectinit()
{
    SuperM = new SuperMultiMedia(this);
}

/*  object init;*/

void ModuleA::Checkdevicechanged()
{
    Mediadevices = new QMediaDevices(this);
    connect(Mediadevices,&QMediaDevices::audioOutputsChanged,this,&ModuleA::Signalwb);
}

/*  check device changed;*/

void ModuleA::Checkdefaultdevice()
{
    QList<bool> boollist;
    SuperM->Checkdeviceexist(&boollist);
    if(!boollist.at(0))
    {
        Checkdevicechanged();
    }
    else
    {
        emit Signalwa();
    }
}

/*  check default device is exist;*/

void ModuleA::Parameterinit()
{
    Layout->addWidget(this);
}

/*  parameter init;*/

void ModuleA::Iconinit()
{
    ui->pushButton_2->setIcon(QIcon(":/__supericon__/_stopplay_.svg"));
    ui->pushButton_3->setIcon(QIcon(":/__supericon__/_last_.svg"));
    ui->pushButton_5->setIcon(QIcon(":/__supericon__/_random_.svg"));
    ui->pushButton_6->setIcon(QIcon(":/__supericon__/_next_.svg"));
    ui->pushButton_7->setIcon(QIcon(":/__supericon__/_play_.svg"));
}

/*  init icon;*/

