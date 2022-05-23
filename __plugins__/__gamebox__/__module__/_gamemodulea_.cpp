#include "_gamemodulea_.h"

GameModuleA::GameModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::GameModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

GameModuleA::~GameModuleA()
{
    delete ui;
}

void GameModuleA::init()
{
    parameterInit();
}

void GameModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
