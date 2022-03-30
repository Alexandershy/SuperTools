#include "_formatbox_.h"

FormatBox::FormatBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FormatBox)
{
    ui->setupUi(this);
}

FormatBox::~FormatBox()
{
    delete ui;
}




