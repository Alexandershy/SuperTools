#include "_csvdatadialogui_.h"

CsvDataDialogui::CsvDataDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CsvDataDialogui)
{
    ui->setupUi(this);
}

CsvDataDialogui::~CsvDataDialogui()
{
    delete ui;
}
