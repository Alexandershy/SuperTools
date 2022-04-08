#include "_supergroupbox_.h"

SuperGroupBox::SuperGroupBox(QWidget *parent,QLayout *layout)
    : QGroupBox(parent)
{
    Outsidelayout = layout;
    Init();
}

SuperGroupBox::~SuperGroupBox()
{

}

void SuperGroupBox::Init()
{
    Objectinit();
    Parameterinit();
}

/*  groupbox init;*/

void SuperGroupBox::Objectinit()
{
    Insidelayout = new QVBoxLayout(this);
}

/*  creat object for groupbox;*/

void SuperGroupBox::Parameterinit()
{
    setTitle("");
    Outsidelayout->addWidget(this);
    Insidelayout->setContentsMargins(1, 1, 1, 1);
}

/*  groupbox init;*/

void SuperGroupBox::Addwidget(QWidget *widget)
{
    Insidelayout->addWidget(widget);
}

/*  add widget;*/
