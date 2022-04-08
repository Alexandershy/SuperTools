#include "_superprogressbardialog_.h"

SuperProgressBarDialog::SuperProgressBarDialog(QWidget *parent)
    : SuperWindow(parent)
{
    Settitle("Progressbar running...");
    setWindowModality(Qt::ApplicationModal);
    Disableclose();
    Disablemaxisize();
    Thememenuinit();
    Addiconfunction();
    Init();
}

SuperProgressBarDialog::~SuperProgressBarDialog()
{

}

void SuperProgressBarDialog::Init()
{
    Objectinit();
}

void SuperProgressBarDialog::Objectinit()
{
    Plugin = new SuperProgressBarDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(this,&SuperProgressBarDialog::Signalpb,this,&SuperProgressBarDialog::hide);
    Stop = new QAction("Stop",this);
    connect(Stop,&QAction::triggered,this,&SuperProgressBarDialog::Stopfunction);
    Addthemesaction(Stop);
}

/*  creat object and connect its slot;*/

void SuperProgressBarDialog::Stopfunction()
{
    emit Signalpa();
}

/*  emit signal for stop current progress;*/

void SuperProgressBarDialog::Setvaluemessage(int value,QString message)
{
    Plugin->ui->progressBar->setValue(value);
    Plugin->ui->label->setText(message);
    if(value == 100)
    {
        Plugin->ui->progressBar->setValue(0);
        Plugin->ui->label->setText("waitting for message...");
        emit Signalpb();
    }
}

/*  receive value and message from Getvalue thread;*/

