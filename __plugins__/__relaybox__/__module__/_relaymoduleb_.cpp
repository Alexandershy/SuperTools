#include "_relaymoduleb_.h"

RelayModuleB::RelayModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::RelayModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

RelayModuleB::~RelayModuleB()
{
    delete ui;
}

void RelayModuleB::init()
{
    parameterInit();
}

void RelayModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
