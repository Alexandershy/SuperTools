#include "_relaymodulea_.h"

RelayModuleA::RelayModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::RelayModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

RelayModuleA::~RelayModuleA()
{
    delete ui;
}

void RelayModuleA::init()
{
    parameterInit();
}

void RelayModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
