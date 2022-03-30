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
    Uiinit();
}

void ModuleB::Parameterinit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void ModuleB::Uiinit()
{
    ui->groupBox_5->setHidden(true);
    ui->groupBox_6->setHidden(true);
    ui->groupBox_8->setHidden(true);
}
