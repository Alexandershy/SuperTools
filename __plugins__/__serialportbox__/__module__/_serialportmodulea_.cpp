#include "_serialportmodulea_.h"
#include "ui__serialportmodulea_.h"

SerialPortModuleA::SerialPortModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::SerialPortModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

SerialPortModuleA::~SerialPortModuleA()
{
    delete ui;
}

void SerialPortModuleA::init()
{
    parameterInit();
}

void SerialPortModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
