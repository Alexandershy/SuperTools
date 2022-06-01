#include "_audioformatdialog_.h"
#include "ui__audioformatdialogui_.h"

AudioFormatDialog::AudioFormatDialog(QWidget *parent)
    : SuperWindow(parent)
{
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose);
    setTitle("convert dialog");
    disableMaxisize();
    init();
}

AudioFormatDialog::~AudioFormatDialog()
{

}

void AudioFormatDialog::init()
{
    objectInit();
}

void AudioFormatDialog::objectInit()
{
    Plugin = new AudioFormatDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,      this,&AudioFormatDialog::convert);
    connect(Plugin->ui->comboBox,       &QComboBox::textActivated,  this,&AudioFormatDialog::convertMode);
}

void AudioFormatDialog::convert()
{
    if(Plugin->ui->checkBox->isChecked())
    {
        emit signalAb(0);
    }
    else
    {
        emit signalAb(1);
    }
    deleteLater();
}

/*  emit signal convert mpeg file;*/

void AudioFormatDialog::convertMode()
{
    emit signalAa(Plugin->ui->comboBox->currentIndex());
}

/*  emit convert mode id;*/


