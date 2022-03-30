#include "_infodialog_.h"

InfoDialog::InfoDialog(QWidget *parent) : SuperWindow(parent)
{
    Init();
    Disablemaxisize();
    Settitle("Info Dialog");
    setWindowModality(Qt::ApplicationModal);
}

InfoDialog::~InfoDialog()
{

}

void InfoDialog::Init()
{
    Objectinit();
}

void InfoDialog::Objectinit()
{
    Plugin = new InfoBox(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->spinBox,   &QSpinBox::textChanged, this,   &InfoDialog::Checkitemnumber);
    connect(Plugin->ui->spinBox_2, &QSpinBox::textChanged, this,   &InfoDialog::Checkupperlimitnumber);
    connect(Plugin->ui->spinBox_3, &QSpinBox::textChanged, this,   &InfoDialog::Checklowerlimitnumber);
    connect(Plugin->ui->spinBox_4, &QSpinBox::textChanged, this,   &InfoDialog::Checkdatanumber);
    connect(Plugin->ui->spinBox_5, &QSpinBox::textChanged, this,   &InfoDialog::Checkdutnumber);
    connect(Plugin->ui->spinBox_6, &QSpinBox::textChanged, this,   &InfoDialog::Checktesternumber);
    connect(Plugin->ui->spinBox_7, &QSpinBox::textChanged, this,   &InfoDialog::Checkappraisernumber);
}

/*  item object init;*/

void InfoDialog::Checkitemnumber()
{
    emit Signalia(Plugin->ui->spinBox->value());
}

/*  check and set item index;*/

void InfoDialog::Checkupperlimitnumber()
{
    emit Signalib(Plugin->ui->spinBox_2->value());
}

/*  check and set upper limit index;*/

void InfoDialog::Checklowerlimitnumber()
{
    emit Signalic(Plugin->ui->spinBox_3->value());
}

/*  check and set lower limit index;*/

void InfoDialog::Checkdatanumber()
{
    emit Signalid(Plugin->ui->spinBox_4->value());
}

/*  check and set data index;*/

void InfoDialog::Checkdutnumber()
{
    emit Signalie(Plugin->ui->spinBox_5->value());
}

/*  check and set data index;*/

void InfoDialog::Checktesternumber()
{
    emit Signalif(Plugin->ui->spinBox_6->value());
}

/*  check and set data index;*/

void InfoDialog::Checkappraisernumber()
{
    emit Signalig(Plugin->ui->spinBox_7->value());
}

/*  check and set data index;*/
