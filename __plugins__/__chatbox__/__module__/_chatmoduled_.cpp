#include "_chatmoduled_.h"
#include "ui__chatmoduled_.h"

ChatModuleD::ChatModuleD(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ChatModuleD)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

ChatModuleD::~ChatModuleD()
{
    delete ui;
}

void ChatModuleD::init()
{
    parameterInit();
    iconInit();
}

void ChatModuleD::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void ChatModuleD::iconInit()
{
    ui->pushButton_5->setIcon(QIcon(":/__supericon__/_download_.svg"));
}

/*  icon init;*/
