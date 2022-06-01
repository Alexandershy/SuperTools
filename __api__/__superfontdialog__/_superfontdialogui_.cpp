#include "_superfontdialogui_.h"
#include "ui__superfontdialogui_.h"

SuperFontDialogui::SuperFontDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperFontDialogui)
{
    ui->setupUi(this);
}

SuperFontDialogui::~SuperFontDialogui()
{
    delete ui;
}

/*  for ui;*/
