#include "_modulea_.h"

ModuleA::ModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    Init();
}

ModuleA::~ModuleA()
{
    delete ui;
}

void ModuleA::Init()
{
    Parameterinit();
}

void ModuleA::Parameterinit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
