#include "_scannermodulea_.h"
#include "ui__scannermodulea_.h"

ScannerModuleA::ScannerModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ScannerModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

ScannerModuleA::~ScannerModuleA()
{
    delete ui;
}

void ScannerModuleA::init()
{
    parameterInit();
}

void ScannerModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
