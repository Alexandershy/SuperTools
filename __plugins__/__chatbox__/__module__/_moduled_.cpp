#include "_moduled_.h"

ModuleD::ModuleD(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ModuleD)
{
    Layout = layout;
    ui->setupUi(this);
    Init();
}

ModuleD::~ModuleD()
{
    delete ui;
}

void ModuleD::Init()
{
    Parameterinit();
    Iconinit();
}

void ModuleD::Parameterinit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void ModuleD::Iconinit()
{
    ui->pushButton_5->setIcon(QIcon(":/__supericon__/_download_.svg"));
}

/*  icon init;*/
