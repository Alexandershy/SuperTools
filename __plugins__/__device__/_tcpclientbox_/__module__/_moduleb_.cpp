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
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
    ui->scrollArea->viewport()->setStyleSheet("QWidget#scrollAreaWidgetContents{background:transparent;}");
}

/*  ui init;*/
