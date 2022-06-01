#include "_wasapiformatdialog_.h"
#include "ui__wasapiformatdialogui_.h"

WasapiFormatDialog::WasapiFormatDialog(QWidget *parent,QAudioFormat *outformat,QAudioFormat *inputformat)
    : SuperWindow(parent)
{
    Outputformat = outformat;
    Inputformat = inputformat;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    disableMaxisize();
    setTitle("audio format");
    init();
}

WasapiFormatDialog::~WasapiFormatDialog()
{

}

void WasapiFormatDialog::init()
{
    objectInit();
    parameterInit();
}

void WasapiFormatDialog::objectInit()
{
    Multimedia = new SuperMultiMedia(this);
    Plugin = new WasapiFormatDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->doubleSpinBox,  &QDoubleSpinBox::textChanged,   this,&WasapiFormatDialog::changeOutputFormat);
    connect(Plugin->ui->doubleSpinBox_2,&QDoubleSpinBox::textChanged,   this,&WasapiFormatDialog::changeOutputFormat);
    connect(Plugin->ui->doubleSpinBox_3,&QDoubleSpinBox::textChanged,   this,&WasapiFormatDialog::changeOutputFormat);
    connect(Plugin->ui->doubleSpinBox_4,&QDoubleSpinBox::textChanged,   this,&WasapiFormatDialog::changeInputFormat);
    connect(Plugin->ui->doubleSpinBox_5,&QDoubleSpinBox::textChanged,   this,&WasapiFormatDialog::changeInputFormat);
    connect(Plugin->ui->doubleSpinBox_6,&QDoubleSpinBox::textChanged,   this,&WasapiFormatDialog::changeInputFormat);
}

void WasapiFormatDialog::parameterInit()
{
    Plugin->ui->doubleSpinBox->setValue(Outputformat->channelCount());
    Plugin->ui->doubleSpinBox_2->setValue(Outputformat->sampleRate());
    Plugin->ui->doubleSpinBox_3->setValue(Multimedia->enumBitsToInt(Outputformat->sampleFormat()));
    Plugin->ui->doubleSpinBox_4->setValue(Inputformat->channelCount());
    Plugin->ui->doubleSpinBox_5->setValue(Inputformat->sampleRate());
    Plugin->ui->doubleSpinBox_6->setValue(Multimedia->enumBitsToInt(Inputformat->sampleFormat()));
}

void WasapiFormatDialog::changeOutputFormat()
{
    emit signalFa(Outputformat,Plugin->ui->doubleSpinBox_2->value(),Plugin->ui->doubleSpinBox_3->value(),Plugin->ui->doubleSpinBox->value(),"output");
    emit signalFb(Plugin->ui->doubleSpinBox_2->value(),Plugin->ui->doubleSpinBox_3->value(),Plugin->ui->doubleSpinBox->value());
}

/*  set output audio format parameter;*/

void WasapiFormatDialog::changeInputFormat()
{
    emit signalFa(Inputformat,Plugin->ui->doubleSpinBox_5->value(),Plugin->ui->doubleSpinBox_6->value(),Plugin->ui->doubleSpinBox_4->value(),"input");
    emit signalFc(Plugin->ui->doubleSpinBox_5->value(),Plugin->ui->doubleSpinBox_6->value(),Plugin->ui->doubleSpinBox_4->value());
}

/*  set input audio format parameter;*/


