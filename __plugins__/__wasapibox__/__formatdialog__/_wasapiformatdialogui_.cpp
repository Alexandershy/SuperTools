#include "_wasapiformatdialogui_.h"
#include "ui__wasapiformatdialogui_.h"

WasapiFormatDialogui::WasapiFormatDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::WasapiFormatDialogui)
{
    ui->setupUi(this);
}

WasapiFormatDialogui::~WasapiFormatDialogui()
{
    delete ui;
}




