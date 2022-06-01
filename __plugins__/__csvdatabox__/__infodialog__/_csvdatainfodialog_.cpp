#include "_csvdatainfodialog_.h"
#include "ui__csvdatainfodialogui_.h"

CsvDataInfoDialog::CsvDataInfoDialog(QWidget *parent)
    : SuperWindow(parent)
{
    init();
    disableMaxisize();
    setTitle("Info Dialog");
    setWindowModality(Qt::ApplicationModal);
}

CsvDataInfoDialog::~CsvDataInfoDialog()
{

}

void CsvDataInfoDialog::init()
{
    objectInit();
}

void CsvDataInfoDialog::objectInit()
{
    Plugin = new CsvDataInfoDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->spinBox,   &QSpinBox::textChanged, this,   &CsvDataInfoDialog::checkItemNumber);
    connect(Plugin->ui->spinBox_2, &QSpinBox::textChanged, this,   &CsvDataInfoDialog::checkUpperLimitNumber);
    connect(Plugin->ui->spinBox_3, &QSpinBox::textChanged, this,   &CsvDataInfoDialog::checkLowerLimitNumber);
    connect(Plugin->ui->spinBox_4, &QSpinBox::textChanged, this,   &CsvDataInfoDialog::checkDataNumber);
    connect(Plugin->ui->spinBox_5, &QSpinBox::textChanged, this,   &CsvDataInfoDialog::checkDutNumber);
    connect(Plugin->ui->spinBox_6, &QSpinBox::textChanged, this,   &CsvDataInfoDialog::checkTesterNumber);
    connect(Plugin->ui->spinBox_7, &QSpinBox::textChanged, this,   &CsvDataInfoDialog::checkAppraiserNumber);
}

/*  item object init;*/

void CsvDataInfoDialog::checkItemNumber()
{
    emit signalIa(Plugin->ui->spinBox->value());
}

/*  check and set item index;*/

void CsvDataInfoDialog::checkUpperLimitNumber()
{
    emit signalIb(Plugin->ui->spinBox_2->value());
}

/*  check and set upper limit index;*/

void CsvDataInfoDialog::checkLowerLimitNumber()
{
    emit signalIc(Plugin->ui->spinBox_3->value());
}

/*  check and set lower limit index;*/

void CsvDataInfoDialog::checkDataNumber()
{
    emit signalId(Plugin->ui->spinBox_4->value());
}

/*  check and set data index;*/

void CsvDataInfoDialog::checkDutNumber()
{
    emit signalIe(Plugin->ui->spinBox_5->value());
}

/*  check and set data index;*/

void CsvDataInfoDialog::checkTesterNumber()
{
    emit signalIf(Plugin->ui->spinBox_6->value());
}

/*  check and set data index;*/

void CsvDataInfoDialog::checkAppraiserNumber()
{
    emit signalIg(Plugin->ui->spinBox_7->value());
}

/*  check and set data index;*/
