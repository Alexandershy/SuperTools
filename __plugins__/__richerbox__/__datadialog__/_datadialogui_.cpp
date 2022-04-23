#include "_datadialogui_.h"

DataDialogui::DataDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DataDialogui)
{
    ui->setupUi(this);
}

DataDialogui::~DataDialogui()
{
    delete ui;
}
