#include "_superprogressbardialogui_.h"
#include "ui__superprogressbardialogui_.h"

SuperProgressBarDialogui::SuperProgressBarDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperProgressBarDialogui)
{
    ui->setupUi(this);
}

SuperProgressBarDialogui::~SuperProgressBarDialogui()
{
    delete ui;
}

/*  for ui;*/

