#include "_superprogressbarbox_.h"

SuperProgressBarBox::SuperProgressBarBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperProgressBarBox)
{
    ui->setupUi(this);
}

SuperProgressBarBox::~SuperProgressBarBox()
{
    delete ui;
}

