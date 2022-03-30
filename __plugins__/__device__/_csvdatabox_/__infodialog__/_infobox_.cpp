#include "_infobox_.h"

InfoBox::InfoBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::InfoBox)
{
    ui->setupUi(this);
}

InfoBox::~InfoBox()
{
    delete ui;
}
