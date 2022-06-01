#include "_wavdatamodulea_.h"
#include "ui__wavdatamodulea_.h"

WavdataModuleA::WavdataModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::WavdataModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

WavdataModuleA::~WavdataModuleA()
{
    delete ui;
}

void WavdataModuleA::init()
{
    objectInit();
    parameterInit();
    iconInit();
}

/*  object init;*/

void WavdataModuleA::objectInit()
{
    Multimedia = new SuperMultiMedia(this);
}

/*  object init;*/

void WavdataModuleA::checkDeviceChanged()
{
    Mediadevices = new QMediaDevices(this);
    connect(Mediadevices,&QMediaDevices::audioOutputsChanged,this,&WavdataModuleA::signalWb);
}

/*  check device changed;*/

void WavdataModuleA::checkDefaultDevice()
{
    QList<bool> boollist;
    Multimedia->checkDeviceExist(&boollist);
    if(!boollist.at(0))
    {
        checkDeviceChanged();
    }
    else
    {
        emit signalWa();
    }
}

/*  check default device is exist;*/

void WavdataModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  parameter init;*/

void WavdataModuleA::iconInit()
{
    ui->pushButton_2->setIcon(QIcon(":/__supericon__/_stopplay_.svg"));
    ui->pushButton_3->setIcon(QIcon(":/__supericon__/_last_.svg"));
    ui->pushButton_5->setIcon(QIcon(":/__supericon__/_random_.svg"));
    ui->pushButton_6->setIcon(QIcon(":/__supericon__/_next_.svg"));
    ui->pushButton_7->setIcon(QIcon(":/__supericon__/_play_.svg"));
}

/*  init icon;*/

