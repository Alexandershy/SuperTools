#include "_demomoduleb_.h"
#include "ui__demomoduleb_.h"

DemoModuleB::DemoModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::DemoModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

DemoModuleB::~DemoModuleB()
{
    delete ui;
}

void DemoModuleB::init()
{
    parameterInit();
}

void DemoModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
