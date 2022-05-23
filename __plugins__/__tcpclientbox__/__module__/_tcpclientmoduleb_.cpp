#include "_tcpclientmoduleb_.h"

TcpClientModuleB::TcpClientModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::TcpClientModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

TcpClientModuleB::~TcpClientModuleB()
{
    delete ui;
}

void TcpClientModuleB::init()
{
    parameterInit();
    uiInit();
}

void TcpClientModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void TcpClientModuleB::uiInit()
{
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
    ui->scrollArea->viewport()->setStyleSheet("QWidget#scrollAreaWidgetContents{background:transparent;}");
}

/*  ui init;*/
