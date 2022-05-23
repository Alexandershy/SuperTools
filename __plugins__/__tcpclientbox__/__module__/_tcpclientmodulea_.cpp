#include "_tcpclientmodulea_.h"

TcpClientModuleA::TcpClientModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::TcpClientModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

TcpClientModuleA::~TcpClientModuleA()
{
    delete ui;
}

void TcpClientModuleA::init()
{
    parameterInit();
}

void TcpClientModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
