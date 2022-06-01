#include "_chatmodulea_.h"
#include "ui__chatmodulea_.h"

ChatModuleA::ChatModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ChatModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

ChatModuleA::~ChatModuleA()
{
    delete ui;
}

void ChatModuleA::init()
{
    parameterInit();
}

void ChatModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
