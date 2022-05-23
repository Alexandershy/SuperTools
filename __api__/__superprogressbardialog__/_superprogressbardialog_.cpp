#include "_superprogressbardialog_.h"

SuperProgressBarDialog::SuperProgressBarDialog(QWidget *parent)
    : SuperWindow(parent)
{
    setTitle("SuperProgressBarDialog");
    setWindowModality(Qt::ApplicationModal);
    disableClose();
    disableMaxisize();
    themeMenuInit();
    addIconFunction();
    init();
}

SuperProgressBarDialog::~SuperProgressBarDialog()
{

}

void SuperProgressBarDialog::init()
{
    objectInit();
}

void SuperProgressBarDialog::objectInit()
{
    Plugin = new SuperProgressBarDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(this,&SuperProgressBarDialog::signalPb,this,&SuperProgressBarDialog::hide);
    Stop = new QAction("Stop",this);
    connect(Stop,&QAction::triggered,this,&SuperProgressBarDialog::stopFunction);
    addThemesAction(Stop);
}

/*  creat object and connect its slot;*/

void SuperProgressBarDialog::stopFunction()
{
    emit signalPa();
}

/*  emit signal for stop current progress;*/

void SuperProgressBarDialog::setValueMessage(int value,QString message)
{
    Plugin->ui->progressBar->setValue(value);
    Plugin->ui->label->setText(message);
    if(value == 100)
    {
        Plugin->ui->progressBar->setValue(0);
        Plugin->ui->label->setText("waitting for message...");
        emit signalPb();
    }
}

/*  receive value and message from Getvalue thread;*/

