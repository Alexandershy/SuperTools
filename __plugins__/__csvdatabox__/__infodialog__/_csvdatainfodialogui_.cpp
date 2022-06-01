#include "_csvdatainfodialogui_.h"
#include "ui__csvdatainfodialogui_.h"

CsvDataInfoDialogui::CsvDataInfoDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CsvDataInfoDialogui)
{
    ui->setupUi(this);
}

CsvDataInfoDialogui::~CsvDataInfoDialogui()
{
    delete ui;
}
