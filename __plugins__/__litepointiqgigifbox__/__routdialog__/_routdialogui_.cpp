#include "_routdialogui_.h"
#include "ui__routdialogui_.h"

RoutDialogui::RoutDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::RoutDialogui)
{
    ui->setupUi(this);
}

RoutDialogui::~RoutDialogui()
{
    delete ui;
}
