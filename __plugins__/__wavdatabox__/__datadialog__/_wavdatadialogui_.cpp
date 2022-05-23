#include "_wavdatadialogui_.h"

WavDataDialogui::WavDataDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::WavDataDialogui)
{
    ui->setupUi(this);
}

WavDataDialogui::~WavDataDialogui()
{
    delete ui;
}




