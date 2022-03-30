#include "_chatinfobox_.h"

ChatInfoBox::ChatInfoBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ChatInfoBox)
{
    ui->setupUi(this);
}

ChatInfoBox::~ChatInfoBox()
{
    delete ui;
}

/*  public boxs' ui pointer;*/
