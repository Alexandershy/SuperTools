#include "_relaymodulec_.h"
#include "ui__relaymodulec_.h"

RelayModuleC::RelayModuleC(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::RelayModuleC)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

RelayModuleC::~RelayModuleC()
{
    delete ui;
}

void RelayModuleC::init()
{
    parameterInit();
    uiInit();
}

void RelayModuleC::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void RelayModuleC::uiInit()
{
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
    ui->scrollArea->viewport()->setStyleSheet("QWidget#scrollAreaWidgetContents{background:transparent;}");
}

/*  ui init;*/
