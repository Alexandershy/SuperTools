#include "_ledanalysermoduleb_.h"

LedAnalyserModuleB::LedAnalyserModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::LedAnalyserModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

LedAnalyserModuleB::~LedAnalyserModuleB()
{
    delete ui;
}

void LedAnalyserModuleB::init()
{
    parameterInit();
}

void LedAnalyserModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
