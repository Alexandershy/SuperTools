#include "_moduleb_.h"

ModuleB::ModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    Init();
}

ModuleB::~ModuleB()
{
    delete ui;
}

void ModuleB::Init()
{
    Parameterinit();
}

void ModuleB::Parameterinit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
