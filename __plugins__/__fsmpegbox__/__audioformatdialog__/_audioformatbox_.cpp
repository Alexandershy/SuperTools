#include "_audioformatbox_.h"

AudioFormatBox::AudioFormatBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AudioFormatBox)
{
    ui->setupUi(this);
}

AudioFormatBox::~AudioFormatBox()
{
    delete ui;
}
