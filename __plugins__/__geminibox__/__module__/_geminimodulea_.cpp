#include "_geminimodulea_.h"

GeminiModuleA::GeminiModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::GeminiModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

GeminiModuleA::~GeminiModuleA()
{
    delete ui;
}

void GeminiModuleA::init()
{
    parameterInit();
}

void GeminiModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
