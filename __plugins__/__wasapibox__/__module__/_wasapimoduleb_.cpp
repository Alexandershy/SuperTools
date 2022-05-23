#include "_wasapimoduleb_.h"

WasapiModuleB::WasapiModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::WasapiModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

WasapiModuleB::~WasapiModuleB()
{
    delete ui;
}

void WasapiModuleB::init()
{
    parameterInit();
}

void WasapiModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
