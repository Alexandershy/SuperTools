#include "_chatinfodialogui_.h"

ChatInfoDialogui::ChatInfoDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ChatInfoDialogui)
{
    ui->setupUi(this);
}

ChatInfoDialogui::~ChatInfoDialogui()
{
    delete ui;
}

/*  public boxs' ui pointer;*/
