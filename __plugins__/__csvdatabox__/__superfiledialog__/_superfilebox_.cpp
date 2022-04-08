#include "_superfilebox_.h"

SuperFileBox::SuperFileBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperFileBox)
{
    ui->setupUi(this);
}

SuperFileBox::~SuperFileBox()
{
    delete ui;
}
