#include "_supersender_.h"
#include "ui__supersenderui_.h"

SuperSender::SuperSender(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::SuperSenderui)
{
    Widget = parent;
    Layout = layout;
    ui->setupUi(this);
    connect(ui->lineEdit,   &QLineEdit::textChanged,    this,&SuperSender::enableSendButton);
    connect(ui->pushButton, &QPushButton::clicked,      this,&SuperSender::send);
    connect(ui->checkBox,   &QCheckBox::stateChanged,   this,&SuperSender::enableSpinBox);
    init();
}

SuperSender::~SuperSender()
{
    delete ui;
}

void SuperSender::init()
{
    parameterInit();
    objectInit();
}

void SuperSender::parameterInit()
{
    Index = Layout->count();
    Layout->addWidget(this);
    ui->label->setText("Input line " + QString("%1").arg(Index,2, 10, QChar('0')));
    Lineedit = ui->lineEdit;
}

void SuperSender::objectInit()
{
    Timer = new QTimer(this);
    connect(Timer,&QTimer::timeout,this,&SuperSender::sendText);
}

void SuperSender::enableSendButton(QString text)
{
    ui->pushButton->setEnabled(!text.isEmpty());
    if(text.contains(Spliter))
    {
        ui->lineEdit->clear();
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"can not input " + Spliter + ";");
        notedialog->hideLeftButton();
        notedialog->messageInit();
    }
    else
    {
        emit signalSb();
    }
}

/*  enable send button or not;*/

void SuperSender::sendText()
{
    emit signalSa(ui->lineEdit);
}

/*  send text;*/

void SuperSender::send()
{
    sendText();
    if(ui->checkBox->isChecked())
    {
        ui->pushButton->setEnabled(false);
        ui->spinBox->setEnabled(false);
        Timer->setInterval(ui->spinBox->value());
        Timer->start();
    }
}

/*  send text;*/

void SuperSender::enableSpinBox()
{
    if(ui->checkBox->isChecked())
    {
        ui->spinBox->setEnabled(true);
    }
    else
    {
        ui->spinBox->setEnabled(false);
        if(Timer->isActive())
        {
           Timer->stop();
           ui->pushButton->setEnabled(true);
        }
    }
}

/*  enable spin box or not;*/

void SuperSender::enable()
{
    ui->lineEdit->setEnabled(true);
    ui->checkBox->setEnabled(true);
    enableSendButton(ui->lineEdit->text());
    enableSpinBox();
}

/*  enable super senderbox;*/

void SuperSender::disable()
{
    ui->lineEdit->setEnabled(false);
    ui->checkBox->setEnabled(false);
    ui->checkBox->setChecked(false);
    enableSendButton("");
    enableSpinBox();
}

/*  enable super senderbox;*/
