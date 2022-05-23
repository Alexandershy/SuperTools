#include "_ledanalysermodulea_.h"

LedAnalyserModuleA::LedAnalyserModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::LedAnalyserModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

LedAnalyserModuleA::~LedAnalyserModuleA()
{
    delete ui;
}

void LedAnalyserModuleA::init()
{
    parameterInit();
}

void LedAnalyserModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
