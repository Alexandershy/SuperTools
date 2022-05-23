#include "_routdialogui_.h"

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
