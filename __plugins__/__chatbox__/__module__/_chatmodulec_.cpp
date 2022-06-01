#include "_chatmodulec_.h"
#include "ui__chatmodulec_.h"

ChatModuleC::ChatModuleC(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ChatModuleC)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

ChatModuleC::~ChatModuleC()
{
    delete ui;
}

void ChatModuleC::init()
{
    parameterInit();
    uiInit();
}

void ChatModuleC::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void ChatModuleC::uiInit()
{
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
    ui->scrollArea->viewport()->setStyleSheet("background-color:transparent;margin:0px;");
    ui->comboBox->lineEdit()->setAlignment(Qt::AlignRight);
    ui->comboBox->lineEdit()->setReadOnly(true);
}

/*  ui init;*/
