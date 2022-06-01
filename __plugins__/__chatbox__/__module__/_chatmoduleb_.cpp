#include "_chatmoduleb_.h"
#include "ui__chatmoduleb_.h"

ChatModuleB::ChatModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ChatModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

ChatModuleB::~ChatModuleB()
{
    delete ui;
}

void ChatModuleB::init()
{
    parameterInit();
}

void ChatModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
