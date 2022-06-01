#include "_superfinddialogui_.h"
#include "ui__superfinddialogui_.h"

SuperFindDialogui::SuperFindDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperFindDialogui)
{
    ui->setupUi(this);
}

SuperFindDialogui::~SuperFindDialogui()
{
    delete ui;
}

/*  for ui;*/
