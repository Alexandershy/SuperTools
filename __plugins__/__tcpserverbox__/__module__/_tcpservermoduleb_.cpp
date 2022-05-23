#include "_tcpservermoduleb_.h"

TcpServerModuleB::TcpServerModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::TcpServerModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

TcpServerModuleB::~TcpServerModuleB()
{
    delete ui;
}

void TcpServerModuleB::init()
{
    parameterInit();
}

void TcpServerModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
