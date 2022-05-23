#include "_csvdatamodulea_.h"

CsvDataModuleA::CsvDataModuleA(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::CsvDataModuleA)
{
    Layout = layout;
    ui->setupUi(this);
    init();
}

CsvDataModuleA::~CsvDataModuleA()
{
    delete ui;
}

void CsvDataModuleA::init()
{
    parameterInit();
}

void CsvDataModuleA::parameterInit()
{
    Layout->addWidget(this);
}

/*  add widget;*/
