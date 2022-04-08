#include "_routbox_.h"

RoutBox::RoutBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::RoutBox)
{
    ui->setupUi(this);
}

RoutBox::~RoutBox()
{
    delete ui;
}
