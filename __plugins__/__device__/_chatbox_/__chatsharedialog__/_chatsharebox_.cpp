#include "_chatsharebox_.h"

ChatShareBox::ChatShareBox(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ChatShareBox)
{
    ui->setupUi(this);
    Init();
}

ChatShareBox::~ChatShareBox()
{
    delete ui;
}

void ChatShareBox::Init()
{
    Pointerinit();
}

void ChatShareBox::Pointerinit()
{
    Itemoptions         = new QMenu(this);
    Cancelshared        = new QAction(Itemoptions);
    Downloadfile        = new QAction(Itemoptions);
    Downloadfileas      = new QAction(Itemoptions);
    Openpath            = new QAction(Itemoptions);
}

/*  public boxs' ui pointer;*/
