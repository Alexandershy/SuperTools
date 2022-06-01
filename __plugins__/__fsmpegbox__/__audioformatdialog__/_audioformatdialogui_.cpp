#include "_audioformatdialogui_.h"
#include "ui__audioformatdialogui_.h"

AudioFormatDialogui::AudioFormatDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::AudioFormatDialogui)
{
    ui->setupUi(this);
}

AudioFormatDialogui::~AudioFormatDialogui()
{
    delete ui;
}
