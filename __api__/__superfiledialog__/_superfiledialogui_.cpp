#include "_superfiledialogui_.h"
#include "ui__superfiledialogui_.h"

SuperFileDialogui::SuperFileDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperFileDialogui)
{
    ui->setupUi(this);
}

SuperFileDialogui::~SuperFileDialogui()
{
    delete ui;
}

/*  for ui;*/
