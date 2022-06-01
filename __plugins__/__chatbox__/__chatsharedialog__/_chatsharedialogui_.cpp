#include "_chatsharedialogui_.h"
#include "ui__chatsharedialogui_.h"

ChatShareDialogui::ChatShareDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ChatShareDialogui)
{
    ui->setupUi(this);
    init();
}

ChatShareDialogui::~ChatShareDialogui()
{
    delete ui;
}

void ChatShareDialogui::init()
{
    pointerInit();
}

void ChatShareDialogui::pointerInit()
{
    Itemoptions         = new QMenu(this);
    Cancelshared        = new QAction(Itemoptions);
    Downloadfile        = new QAction(Itemoptions);
    Downloadfileas      = new QAction(Itemoptions);
    Openpath            = new QAction(Itemoptions);
}

/*  public boxs' ui pointer;*/
