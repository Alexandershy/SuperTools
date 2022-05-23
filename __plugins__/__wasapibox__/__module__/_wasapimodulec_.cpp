#include "_wasapimodulec_.h"

WasapiModuleC::WasapiModuleC(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::WasapiModuleC)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

WasapiModuleC::~WasapiModuleC()
{
    delete ui;
}

void WasapiModuleC::init()
{
    parameterInit();
}

void WasapiModuleC::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
