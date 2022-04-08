#include "_superfontbox_.h"

SuperFontBox::SuperFontBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperFontBox)
{
    ui->setupUi(this);
}

SuperFontBox::~SuperFontBox()
{
    delete ui;
}
