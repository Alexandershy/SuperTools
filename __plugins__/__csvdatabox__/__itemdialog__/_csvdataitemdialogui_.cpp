#include "_csvdataitemdialogui_.h"

CsvDataItemDialogui::CsvDataItemDialogui(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CsvDataItemDialogui)
{
    ui->setupUi(this);
}

CsvDataItemDialogui::~CsvDataItemDialogui()
{
    delete ui;
}
