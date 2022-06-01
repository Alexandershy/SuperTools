#include "_serialportmoduleb_.h"
#include "ui__serialportmoduleb_.h"

SerialPortModuleB::SerialPortModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::SerialPortModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

SerialPortModuleB::~SerialPortModuleB()
{
    delete ui;
}

void SerialPortModuleB::init()
{
    parameterInit();
    uiInit();
}

void SerialPortModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void SerialPortModuleB::uiInit()
{
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
    ui->scrollArea->viewport()->setStyleSheet("QWidget#scrollAreaWidgetContents{background:transparent;}");
}

/*  ui init;*/
