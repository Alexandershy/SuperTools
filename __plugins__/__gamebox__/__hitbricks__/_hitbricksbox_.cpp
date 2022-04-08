#include "_hitbricksbox_.h"

HitBricksBox::HitBricksBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::HitBricksBox)
{
    ui->setupUi(this);
}

HitBricksBox::~HitBricksBox()
{
    delete ui;
}







