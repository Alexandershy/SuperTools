#include "_supergroupbox_.h"

SuperGroupBox::SuperGroupBox(QWidget *parent,QLayout *layout)
    : QGroupBox(parent)
{
    Outsidelayout = layout;
    init();
}

SuperGroupBox::~SuperGroupBox()
{

}

void SuperGroupBox::init()
{
    objectTnit();
    parameterInit();
}

/*  groupbox init;*/

void SuperGroupBox::objectTnit()
{
    Insidelayout = new QVBoxLayout(this);
}

/*  creat object for groupbox;*/

void SuperGroupBox::parameterInit()
{
    setTitle("");
    Outsidelayout->addWidget(this);
    Insidelayout->setContentsMargins(1, 1, 1, 1);
}

/*  groupbox init;*/

void SuperGroupBox::addWidget(QWidget *widget)
{
    Insidelayout->addWidget(widget);
}

/*  add widget;*/
