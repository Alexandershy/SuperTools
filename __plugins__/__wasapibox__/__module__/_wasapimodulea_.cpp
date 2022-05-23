#include "_wasapimodulea_.h"

WasapiModuleA::WasapiModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::WasapiModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

WasapiModuleA::~WasapiModuleA()
{
    delete ui;
}

void WasapiModuleA::init()
{
    parameterInit();
}

void WasapiModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
