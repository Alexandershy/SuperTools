#include "_modulec_.h"

ModuleC::ModuleC(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ModuleC)
{
    Layout = layout;
    ui->setupUi(this);
    Init();
}

ModuleC::~ModuleC()
{
    delete ui;
}

void ModuleC::Init()
{
    Parameterinit();
}

void ModuleC::Parameterinit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
