#include "_databox_.h"

DataBox::DataBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DataBox)
{
    ui->setupUi(this);
}

DataBox::~DataBox()
{
    delete ui;
}
