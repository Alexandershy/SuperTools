#include "_itembox_.h"

ItemBox::ItemBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ItemBox)
{
    ui->setupUi(this);
}

ItemBox::~ItemBox()
{
    delete ui;
}
