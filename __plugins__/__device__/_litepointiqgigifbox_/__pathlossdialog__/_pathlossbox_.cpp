#include "_pathlossbox_.h"

PathLossBox::PathLossBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::PathLossBox)
{
    ui->setupUi(this);
}

PathLossBox::~PathLossBox()
{
    delete ui;
}

