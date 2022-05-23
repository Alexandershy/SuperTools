#include "_supercolordialogui_.h"

SuperColorDialogui::SuperColorDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperColorDialogui)
{
    ui->setupUi(this);
    init();
}

SuperColorDialogui::~SuperColorDialogui()
{
    delete ui;
}

void SuperColorDialogui::init()
{
    objectInit();
}

void SuperColorDialogui::objectInit()
{
    Painter = new SuperPainter(this,ui->verticalLayout_3);
}
