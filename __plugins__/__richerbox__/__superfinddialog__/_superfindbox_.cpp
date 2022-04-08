#include "_superfindbox_.h"

SuperFindBox::SuperFindBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperFindBox)
{
    ui->setupUi(this);
}

SuperFindBox::~SuperFindBox()
{
    delete ui;
}
