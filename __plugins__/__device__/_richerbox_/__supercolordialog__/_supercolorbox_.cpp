#include "_supercolorbox_.h"

SuperColorBox::SuperColorBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperColorBox)
{
    ui->setupUi(this);
    Init();
}

SuperColorBox::~SuperColorBox()
{
    delete ui;
}

void SuperColorBox::Init()
{
    Objectinit();
}

void SuperColorBox::Objectinit()
{
    Painter = new SuperPainter(this,ui->verticalLayout_3);
}
