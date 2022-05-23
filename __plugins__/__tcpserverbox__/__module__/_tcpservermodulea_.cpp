#include "_tcpservermodulea_.h"

TcpServerModuleA::TcpServerModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::TcpServerModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

TcpServerModuleA::~TcpServerModuleA()
{
    delete ui;
}

void TcpServerModuleA::init()
{
    parameterInit();
}

void TcpServerModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
