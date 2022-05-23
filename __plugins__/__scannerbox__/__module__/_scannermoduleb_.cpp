#include "_scannermoduleb_.h"

ScannerModuleB::ScannerModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ScannerModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

ScannerModuleB::~ScannerModuleB()
{
    delete ui;
}

void ScannerModuleB::init()
{
    parameterInit();
}

void ScannerModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
