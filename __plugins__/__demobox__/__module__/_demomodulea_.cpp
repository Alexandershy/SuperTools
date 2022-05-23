#include "_demomodulea_.h"

DemoModuleA::DemoModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::DemoModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

DemoModuleA::~DemoModuleA()
{
    delete ui;
}

void DemoModuleA::init()
{
    parameterInit();
}

void DemoModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
