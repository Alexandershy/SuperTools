#include "_chatter_.h"

Chatter::Chatter(QWidget *parent,QString role,QString username,QString message)
    : QWidget(parent)
    , ui(new Ui::Chatter)
{
    Parent = parent;
    Role = role;
    Username = username;
    Message = message;
    ui->setupUi(this);
    Init();
}

Chatter::~Chatter()
{
    delete ui;
}

void Chatter::Init()
{
    Objectinit();
    Setplaceinit();
    Timerinit();
}

void Chatter::Objectinit()
{
    User = new ChatUser(this,Role,Username);
    Bubble = new ChatBubble(Parent,Message);
}

/*  chatters' user and bubble init;*/

void Chatter::Setplaceinit()
{
    if(Role == "self")
    {
        ui->verticalLayout_3->addWidget(Bubble);
        ui->verticalLayout_4->addWidget(User);
        ui->horizontalLayout_3->setStretch(0, 99);
        ui->horizontalLayout_3->setStretch(1, 1);
        ui->horizontalLayout_3->setStretch(2, 1);
        ui->horizontalLayout_3->setStretch(3, 1);
    }
    else
    {
        ui->verticalLayout_3->addWidget(User);
        ui->verticalLayout_4->addWidget(Bubble);
        ui->horizontalLayout_3->setStretch(0, 1);
        ui->horizontalLayout_3->setStretch(1, 1);
        ui->horizontalLayout_3->setStretch(2, 1);
        ui->horizontalLayout_3->setStretch(3, 99);
    }
}

/*  set align left or right by user kind;*/

void Chatter::Timerinit()
{
    Timer = new QTimer(this);
    Timer->setInterval(100);
    connect(Timer,&QTimer::timeout,Bubble,&ChatBubble::Adjustheight);
    connect(Timer,&QTimer::timeout,Timer,&QObject::deleteLater);
    Timer->start();
}

/*  delay 100ms adjust height;*/

void Chatter::Adjustsize()
{
    Bubble->Adjustwidth();
    Bubble->Adjustheight();
}

/*  adjust width and height;*/
