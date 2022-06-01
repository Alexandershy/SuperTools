#include "_richerdatadialogui_.h"
#include "ui__richerdatadialogui_.h"

RicherDataDialogui::RicherDataDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::RicherDataDialogui)
{
    ui->setupUi(this);
}

RicherDataDialogui::~RicherDataDialogui()
{
    delete ui;
}
