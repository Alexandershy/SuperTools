#include "_supersender_.h"

SuperSender::SuperSender(QWidget *parent,QLayout *layout)
    : QFrame(parent)
    , ui(new Ui::SuperSenderui)
{
    Widget = parent;
    Layout = layout;
    ui->setupUi(this);
    connect(ui->lineEdit,   &QLineEdit::textChanged,    this,&SuperSender::Enablesendbutton);
    connect(ui->pushButton, &QPushButton::clicked,      this,&SuperSender::Send);
    connect(ui->checkBox,   &QCheckBox::stateChanged,   this,&SuperSender::Enablespinbox);
    Init();
}

SuperSender::~SuperSender()
{
    delete ui;
}

void SuperSender::Init()
{
    Parameterinit();
    Objectinit();
}

void SuperSender::Parameterinit()
{
    Index = Layout->count();
    Layout->addWidget(this);
    ui->label->setText("Input line " + QString("%1").arg(Index,2, 10, QChar('0')));
    Lineedit = ui->lineEdit;
}

void SuperSender::Objectinit()
{
    Timer = new QTimer(this);
    connect(Timer,&QTimer::timeout,this,&SuperSender::Sendtext);
}

void SuperSender::Enablesendbutton(QString text)
{
    ui->pushButton->setEnabled(!text.isEmpty());
    if(text.contains(Spliter))
    {
        ui->lineEdit->clear();
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"can not input " + Spliter + ";");
        notedialog->Hideleftbutton();
        notedialog->Messageinit();
    }
    else
    {
        emit Signalsb();
    }
}

/*  enable send button or not;*/

void SuperSender::Sendtext()
{
    emit Signalsa(ui->lineEdit);
}

/*  send text;*/

void SuperSender::Send()
{
    Sendtext();
    if(ui->checkBox->isChecked())
    {
        ui->pushButton->setEnabled(false);
        ui->spinBox->setEnabled(false);
        Timer->setInterval(ui->spinBox->value());
        Timer->start();
    }
}

/*  send text;*/

void SuperSender::Enablespinbox()
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

void SuperSender::Enable()
{
    ui->lineEdit->setEnabled(true);
    ui->checkBox->setEnabled(true);
    Enablesendbutton(ui->lineEdit->text());
    Enablespinbox();
}

/*  enable super senderbox;*/

void SuperSender::Disable()
{
    ui->lineEdit->setEnabled(false);
    ui->checkBox->setEnabled(false);
    ui->checkBox->setChecked(false);
    Enablesendbutton("");
    Enablespinbox();
}

/*  enable super senderbox;*/
