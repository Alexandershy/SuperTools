#include "_tcpclientbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new TcpClientBox();
}

/*  return class TcpClientBox new instance pointer;*/

TcpClientBox::TcpClientBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("TcpClientBox");
    Setgroupbox(2,1);
    Setstretch({1,99},{100});
    Init();
}

TcpClientBox::~TcpClientBox()
{
    SuperN->Closetcpclient(Tcpsocket);
}

void TcpClientBox::Init()
{
    Objectinit();
    Parameterinit();
    Widgetlistinit();
    Tcpsocketinit();
}

void TcpClientBox::Objectinit()
{
    SuperN = new SuperNetwork(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Modulea->ui->pushButton,    &QPushButton::clicked,          this,   &TcpClientBox::Getlocalipaddress);
    connect(Modulea->ui->pushButton_37, &QPushButton::clicked,          this,   &TcpClientBox::Connecttcpserver);
    connect(Modulea->ui->pushButton_38, &QPushButton::clicked,          this,   &TcpClientBox::Disconnecttcpserver);
    connect(Moduleb->ui->spinBox,       &QSpinBox::editingFinished,     this,   &TcpClientBox::Adjustsenderbox);
    connect(Modulea->ui->comboBox,      &QComboBox::currentTextChanged, this,   &TcpClientBox::Enableconnecttcpserver);
    connect(Modulea->ui->comboBox_2,    &QComboBox::currentTextChanged, this,   &TcpClientBox::Enableconnecttcpserver);
    connect(Modulea->ui->checkBox_2,    &QCheckBox::stateChanged,       this,   &TcpClientBox::Enableaddn);
    connect(Modulea->ui->checkBox_1,    &QCheckBox::stateChanged,       this,   &TcpClientBox::Enableaddr);
    connect(Modulea->ui->checkBox_3,    &QCheckBox::stateChanged,       this,   &TcpClientBox::Changetypea);
    connect(Modulea->ui->checkBox_4,    &QCheckBox::stateChanged,       this,   &TcpClientBox::Changetypeb);
}

void TcpClientBox::Parameterinit()
{
    Logger->Addtransfercodec();
    Stringlist = SuperC->Readonlyfile(Cachefile).split(Spliter);
    if(Stringlist.count() < Moduleb->ui->spinBox->maximum())
    {
        Stringlist.clear();
        for(int i = 0;i < Moduleb->ui->spinBox->maximum();i++)
        {
            Stringlist.append("");
        }
    }
    Adjustsenderbox();
}

/*  read cache file to stringlist;*/

void TcpClientBox::Widgetlistinit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
    Connectwidgetef     = {Modulea->ui->pushButton_37,Modulea->ui->pushButton,Modulea->ui->comboBox,Modulea->ui->comboBox_2,Moduleb->ui->spinBox};
    Disconnectwidgetet  = {Modulea->ui->pushButton_37,Modulea->ui->pushButton,Modulea->ui->comboBox,Modulea->ui->comboBox_2,Moduleb->ui->spinBox};
    Disconnectwidgetef  = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
}

void TcpClientBox::Tcpsocketinit()
{
    Tcpsocket = new QTcpSocket(this);
    connect(Tcpsocket,&QTcpSocket::readyRead,   this,   &TcpClientBox::Readdata);
    connect(Tcpsocket,&QTcpSocket::disconnected,this,   &TcpClientBox::Abnormaldisconnect);
}

/*  creat socket and connect its slot;*/

void TcpClientBox::Getlocalipaddress()
{
    Modulea->ui->comboBox->clear();
    Networkinterface = QNetworkInterface::allInterfaces();
    for(int i = 0;i < Networkinterface.count();i++)
    {
        Networkaddressentry = Networkinterface.at(i).addressEntries();
        SuperN->Getlocalipaddress(&Networkaddressentry,Modulea->ui->comboBox);
    }
    Enablelistenport();
}

/*  add system ipddress;*/

void TcpClientBox::Enablelistenport()
{
    if(Modulea->ui->comboBox->count() > 0)
    {
        Modulea->ui->comboBox_2->setEnabled(true);
        for(int i = 0;i < Modulea->ui->comboBox->count();i++)
        {
            Logger->Displaylog("N",Modulea->ui->comboBox->itemText(i),"Enablelistenport function run completed");
        }
    }
    else
    {
        Logger->Displaylog("N","no found ip address;","Enablelistenport function run completed");
    }
}

/*  enable listen port combobox;*/

void TcpClientBox::Enableconnecttcpserver()
{
    bool boolb = false;
    bool boola = SuperC->Checkiprules(Modulea->ui->comboBox->currentText());
    Modulea->ui->comboBox_2->currentText().toInt(&boolb);
    if(boola == true && boolb == true)
    {
        Modulea->ui->pushButton_37->setEnabled(true);
    }
}

/*  Enable connect tcpserver button or not*/

void TcpClientBox::Connecttcpserver()
{
    bool boola = SuperN->Connecttcpserver(Tcpsocket,Modulea->ui->comboBox->currentText(),Modulea->ui->comboBox_2->currentText().toInt(),1000);
    if(boola)
    {
        SuperC->Enablewidgetlist(&Connectwidgetet,true);
        SuperC->Enablewidgetlist(&Connectwidgetef,false);
        Enablesenderbox(true);
        Logger->Displaylog("N","tcpclient has been connected","Connecttcpserver function run completed");
    }
    else
    {
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox->currentText() + " failed","Connecttcpserver function run completed;");
    }
}

/*  use current setting connect to server;*/

void TcpClientBox::Disconnecttcpserver()
{
    SuperN->Disconnecttcpserver(Tcpsocket,1000);
}

/*  disconnect server;*/

void TcpClientBox::Enablesenderbox(bool boola)
{
    if(boola)
    {
        for(int i = 0;i < Senderboxlist.count();i++)
        {
            Senderboxlist.at(i)->Enable();
        }
    }
    else
    {
        for(int i = 0;i < Senderboxlist.count();i++)
        {
            Senderboxlist.at(i)->Disable();
        }
    }
}

/*  enable senderbox or not;*/

void TcpClientBox::Writeapi(QLineEdit* lineeditdata)
{
    Logger->Result.clear();
    SuperN->Writesocket(Modulea->ui->checkBox_3,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Tcpsocket,lineeditdata);
    Logger->Displaylog("W",lineeditdata->text(),"Writedata function run completed");
}

/*  write text to socket;*/

void TcpClientBox::Recordtext()
{
    for(int i = 0;i < Senderboxlist.count();i++)
    {
        Stringlist[i] = Senderboxlist.at(i)->Lineedit->text();
    }
    SuperC->Writeonlyfilelist(Cachefile,&Stringlist,Spliter,false);
}

/*  record last text;*/

void TcpClientBox::Readdata()
{
    QByteArray byteresult = SuperN->Readdatastream(Tcpsocket,Modulea->ui->checkBox_3);
    Logger->Displaylog("R",byteresult,"Readdata function run completed;");
    Logger->Result.append(byteresult);
}

/*  read tcpsocket data;*/

void TcpClientBox::Enableaddn()
{
    if(Modulea->ui->checkBox_2->isChecked())
    {
        Logger->Displaylog("N","input line has been add \\n","enableaddn function run completed");
    }
    else
    {
        Logger->Displaylog("N","input line has been cancel \\n","enableaddn function run completed");
    }
}

/*  write data add \\n;*/

void TcpClientBox::Enableaddr()
{
    if(Modulea->ui->checkBox_1->isChecked())
    {
        Logger->Displaylog("N","input line has been add \\r","enableaddr function run completed");
    }
    else
    {
        Logger->Displaylog("N","input line has been cancel \\r","enableaddr function run completed");
    }
}

/*  write data add \\r;*/

void TcpClientBox::Changetypea()
{
    if(Modulea->ui->checkBox_3->isChecked())
    {
        Changetypeapi(Modulea->ui->checkBox_4,"input line has been changed to string","changetypea function run completed",false,true,true);
    }
    else
    {
        Changetypeapi(Modulea->ui->checkBox_4,"input line has been changed to hex","changetypea function run completed",true,false,false);
    }
}

/*  change write data type string or hex;*/

void TcpClientBox::Changetypeb()
{
    if(Modulea->ui->checkBox_4->isChecked())
    {
        Changetypeapi(Modulea->ui->checkBox_3,"input line has been changed to hex","Changetypeb function run completed",false,false,false);
    }
    else
    {
        Changetypeapi(Modulea->ui->checkBox_3,"input line has been changed to string","Changetypeb function run completed",true,true,true);
    }
}

/*  change write data type string or hex;*/

void TcpClientBox::Changetypeapi(QCheckBox* checkboxtype,QString strtlog,QString strllog,bool boola,bool boolb,bool boolc)
{
    checkboxtype->setChecked(boola);
    Modulea->ui->checkBox_1->setEnabled(boolb);
    Modulea->ui->checkBox_2->setEnabled(boolc);
    Logger->Displaylog("N",strtlog,strllog);
}

/*  change write data type api;*/

void TcpClientBox::Abnormaldisconnect()
{
    SuperC->Enablewidgetlist(&Disconnectwidgetet,true);
    SuperC->Enablewidgetlist(&Disconnectwidgetef,false);
    Enableconnecttcpserver();
    Enablesenderbox(false);
    Logger->Displaylog("N","tcpclient has been disconnect","checkconnect function run completed");
}

/*  receive result from signalc,check serial port is connect or not;*/

void TcpClientBox::Adjustsenderbox()
{
    Senderboxlist.clear();
    SuperC->Deleteallitemsoflayout(Moduleb->ui->verticalLayout_8);
    Logger->Displaylog("N","senderbox adjust counts as: " + QString::number(Moduleb->ui->spinBox->value()),"Adjustsenderbox function run completed;");
    for(int i = 0;i < Moduleb->ui->spinBox->value();i++)
    {
        SuperSender *senderbox = new SuperSender(this,Moduleb->ui->verticalLayout_8);
        connect(senderbox,&SuperSender::Signalsa,this,&TcpClientBox::Writeapi);
        connect(senderbox,&SuperSender::Signalsb,this,&TcpClientBox::Recordtext);
        senderbox->Lineedit->setText(Stringlist.at(Senderboxlist.count()));
        Senderboxlist.append(senderbox);
        senderbox->Disable();
    }
}

/*  adjust sender box;*/
