#include "_supercolordialogui_.h"

SuperColorDialogui::SuperColorDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperColorDialogui)
{
    ui->setupUi(this);
    Init();
}

SuperColorDialogui::~SuperColorDialogui()
{
    delete ui;
}

void SuperColorDialogui::Init()
{
    Objectinit();
}

void SuperColorDialogui::Objectinit()
{
    Painter = new SuperPainter(this,ui->verticalLayout_3);
}
