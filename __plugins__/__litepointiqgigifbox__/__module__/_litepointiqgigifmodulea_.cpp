#include "_litepointiqgigifmodulea_.h"

LitePointIQGigIfModuleA::LitePointIQGigIfModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::LitePointIQGigIfModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

LitePointIQGigIfModuleA::~LitePointIQGigIfModuleA()
{
    delete ui;
}

void LitePointIQGigIfModuleA::init()
{
    parameterInit();
}

void LitePointIQGigIfModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
