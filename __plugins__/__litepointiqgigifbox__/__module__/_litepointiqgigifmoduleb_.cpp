#include "_litepointiqgigifmoduleb_.h"

LitePointIQGigIfModuleB::LitePointIQGigIfModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::LitePointIQGigIfModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

LitePointIQGigIfModuleB::~LitePointIQGigIfModuleB()
{
    delete ui;
}

void LitePointIQGigIfModuleB::init()
{
    parameterInit();
    uiInit();
}

void LitePointIQGigIfModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void LitePointIQGigIfModuleB::uiInit()
{
    ui->groupBox_5->setHidden(true);
    ui->groupBox_6->setHidden(true);
    ui->groupBox_8->setHidden(true);
}
