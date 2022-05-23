#include "_pathlossdialogui_.h"

PathLossDialogui::PathLossDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::PathLossDialogui)
{
    ui->setupUi(this);
}

PathLossDialogui::~PathLossDialogui()
{
    delete ui;
}

