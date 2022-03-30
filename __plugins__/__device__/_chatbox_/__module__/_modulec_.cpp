#include "_modulec_.h"

ModuleC::ModuleC(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::ModuleC)
{
    Layout = layout;
    ui->setupUi(this);
    Init();
}

ModuleC::~ModuleC()
{
    delete ui;
}

void ModuleC::Init()
{
    Parameterinit();
    Uiinit();
}

void ModuleC::Parameterinit()
{
    Layout->addWidget(this);
}

/*  add widget;*/

void ModuleC::Uiinit()
{
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
    ui->scrollArea->viewport()->setStyleSheet("background-color:transparent;margin:0px;");
    ui->comboBox->lineEdit()->setAlignment(Qt::AlignRight);
    ui->comboBox->lineEdit()->setReadOnly(true);
}

/*  ui init;*/
