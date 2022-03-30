#include "_formatdialog_.h"

FormatDialog::FormatDialog(QWidget *parent,QAudioFormat *outformat,QAudioFormat *inputformat)
    : SuperWindow(parent)
{
    Outputformat = outformat;
    Inputformat = inputformat;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Disablemaxisize();
    Settitle("audio format");
    Init();
}

FormatDialog::~FormatDialog()
{

}

void FormatDialog::Init()
{
    Objectinit();
    Parameterinit();
}

void FormatDialog::Objectinit()
{
    SuperM = new SuperMultiMedia(this);
    Plugin = new FormatBox(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->doubleSpinBox,  &QDoubleSpinBox::textChanged,   this,&FormatDialog::Changeoutputformat);
    connect(Plugin->ui->doubleSpinBox_2,&QDoubleSpinBox::textChanged,   this,&FormatDialog::Changeoutputformat);
    connect(Plugin->ui->doubleSpinBox_3,&QDoubleSpinBox::textChanged,   this,&FormatDialog::Changeoutputformat);
    connect(Plugin->ui->doubleSpinBox_4,&QDoubleSpinBox::textChanged,   this,&FormatDialog::Changeinputformat);
    connect(Plugin->ui->doubleSpinBox_5,&QDoubleSpinBox::textChanged,   this,&FormatDialog::Changeinputformat);
    connect(Plugin->ui->doubleSpinBox_6,&QDoubleSpinBox::textChanged,   this,&FormatDialog::Changeinputformat);
}

void FormatDialog::Parameterinit()
{
    Plugin->ui->doubleSpinBox->setValue(Outputformat->channelCount());
    Plugin->ui->doubleSpinBox_2->setValue(Outputformat->sampleRate());
    Plugin->ui->doubleSpinBox_3->setValue(SuperM->Enumbitstoint(Outputformat->sampleFormat()));
    Plugin->ui->doubleSpinBox_4->setValue(Inputformat->channelCount());
    Plugin->ui->doubleSpinBox_5->setValue(Inputformat->sampleRate());
    Plugin->ui->doubleSpinBox_6->setValue(SuperM->Enumbitstoint(Inputformat->sampleFormat()));
}

void FormatDialog::Changeoutputformat()
{
    emit Signalfa(Outputformat,Plugin->ui->doubleSpinBox_2->value(),Plugin->ui->doubleSpinBox_3->value(),Plugin->ui->doubleSpinBox->value(),"output");
    emit Signalfb(Plugin->ui->doubleSpinBox_2->value(),Plugin->ui->doubleSpinBox_3->value(),Plugin->ui->doubleSpinBox->value());
}

/*  set output audio format parameter;*/

void FormatDialog::Changeinputformat()
{
    emit Signalfa(Inputformat,Plugin->ui->doubleSpinBox_5->value(),Plugin->ui->doubleSpinBox_6->value(),Plugin->ui->doubleSpinBox_4->value(),"input");
    emit Signalfc(Plugin->ui->doubleSpinBox_5->value(),Plugin->ui->doubleSpinBox_6->value(),Plugin->ui->doubleSpinBox_4->value());
}

/*  set input audio format parameter;*/


