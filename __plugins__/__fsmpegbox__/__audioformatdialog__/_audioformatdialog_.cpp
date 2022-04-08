#include "_audioformatdialog_.h"

AudioFormatDialog::AudioFormatDialog(QWidget *parent)
    : SuperWindow(parent)
{
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose);
    Settitle("convert dialog");
    Disablemaxisize();
    Init();
}

AudioFormatDialog::~AudioFormatDialog()
{

}

void AudioFormatDialog::Init()
{
    Objectinit();
}

void AudioFormatDialog::Objectinit()
{
    Plugin = new AudioFormatBox(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,      this,&AudioFormatDialog::Convert);
    connect(Plugin->ui->comboBox,       &QComboBox::textActivated,  this,&AudioFormatDialog::Convertmode);
}

void AudioFormatDialog::Convert()
{
    if(Plugin->ui->checkBox->isChecked())
    {
        emit Signalab(0);
    }
    else
    {
        emit Signalab(1);
    }
    deleteLater();
}

/*  emit signal convert mpeg file;*/

void AudioFormatDialog::Convertmode()
{
    emit Signalaa(Plugin->ui->comboBox->currentIndex());
}

/*  emit convert mode id;*/


