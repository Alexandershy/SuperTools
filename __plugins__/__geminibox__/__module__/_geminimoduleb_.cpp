#include "_geminimoduleb_.h"
#include "ui__geminimoduleb_.h"

GeminiModuleB::GeminiModuleB(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::GeminiModuleB)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

GeminiModuleB::~GeminiModuleB()
{
    delete ui;
}

void GeminiModuleB::init()
{
    parameterInit();
}

void GeminiModuleB::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
