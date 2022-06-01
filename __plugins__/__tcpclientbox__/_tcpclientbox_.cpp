#include "_tcpclientbox_.h"
#include "ui__tcpclientmodulea_.h"
#include "ui__tcpclientmoduleb_.h"

SuperTab* Interface::Loadplugin()
{
    return new TcpClientBox();
}

/*  return class TcpClientBox new instance pointer;*/

TcpClientBox::TcpClientBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("TcpClientBox");
    setGroupBox(2,1);
    setStretch({1,99},{100});
    init();
}

TcpClientBox::~TcpClientBox()
{
    Network->closeTcpClient(Tcpsocket);
}

void TcpClientBox::init()
{
    objectInit();
    parameterInit();
    widgetListInit();
    tcpsocketInit();
}

void TcpClientBox::objectInit()
{
    Network = new SuperNetwork(this);
    Modulea = new TcpClientModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new TcpClientModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Modulea->ui->pushButton,    &QPushButton::clicked,          this,   &TcpClientBox::getLocalIpAddress);
    connect(Modulea->ui->pushButton_37, &QPushButton::clicked,          this,   &TcpClientBox::connectTcpServer);
    connect(Modulea->ui->pushButton_38, &QPushButton::clicked,          this,   &TcpClientBox::disconnectTcpServer);
    connect(Moduleb->ui->spinBox,       &QSpinBox::editingFinished,     this,   &TcpClientBox::adjustSenderBox);
    connect(Modulea->ui->comboBox,      &QComboBox::currentTextChanged, this,   &TcpClientBox::enableConnectTcpServer);
    connect(Modulea->ui->comboBox_2,    &QComboBox::currentTextChanged, this,   &TcpClientBox::enableConnectTcpServer);
    connect(Modulea->ui->checkBox_2,    &QCheckBox::stateChanged,       this,   &TcpClientBox::enableAddn);
    connect(Modulea->ui->checkBox_1,    &QCheckBox::stateChanged,       this,   &TcpClientBox::enableAddr);
    connect(Modulea->ui->checkBox_3,    &QCheckBox::stateChanged,       this,   &TcpClientBox::changeTypea);
    connect(Modulea->ui->checkBox_4,    &QCheckBox::stateChanged,       this,   &TcpClientBox::changeTypeb);
}

void TcpClientBox::parameterInit()
{
    Logger->addTransferCodec();
    Stringlist = Core->readOnlyFile(Cachefile).split(Spliter);
    if(Stringlist.count() < Moduleb->ui->spinBox->maximum())
    {
        Stringlist.clear();
        for(int i = 0;i < Moduleb->ui->spinBox->maximum();i++)
        {
            Stringlist.append("");
        }
    }
    adjustSenderBox();
}

/*  read cache file to stringlist;*/

void TcpClientBox::widgetListInit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
    Connectwidgetef     = {Modulea->ui->pushButton_37,Modulea->ui->pushButton,Modulea->ui->comboBox,Modulea->ui->comboBox_2,Moduleb->ui->spinBox};
    Disconnectwidgetet  = {Modulea->ui->pushButton_37,Modulea->ui->pushButton,Modulea->ui->comboBox,Modulea->ui->comboBox_2,Moduleb->ui->spinBox};
    Disconnectwidgetef  = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
}

void TcpClientBox::tcpsocketInit()
{
    Tcpsocket = new QTcpSocket(this);
    connect(Tcpsocket,&QTcpSocket::readyRead,   this,   &TcpClientBox::readData);
    connect(Tcpsocket,&QTcpSocket::disconnected,this,   &TcpClientBox::abnormalDisconnect);
}

/*  creat socket and connect its slot;*/

void TcpClientBox::getLocalIpAddress()
{
    Modulea->ui->comboBox->clear();
    Networkinterface = QNetworkInterface::allInterfaces();
    for(int i = 0;i < Networkinterface.count();i++)
    {
        Networkaddressentry = Networkinterface.at(i).addressEntries();
        Network->getLocalIpAddress(&Networkaddressentry,Modulea->ui->comboBox);
    }
    enableListenPort();
}

/*  add system ipddress;*/

void TcpClientBox::enableListenPort()
{
    if(Modulea->ui->comboBox->count() > 0)
    {
        Modulea->ui->comboBox_2->setEnabled(true);
        for(int i = 0;i < Modulea->ui->comboBox->count();i++)
        {
            Logger->displayLog("N",Modulea->ui->comboBox->itemText(i),"Enablelistenport function run completed");
        }
    }
    else
    {
        Logger->displayLog("N","no found ip address;","Enablelistenport function run completed");
    }
}

/*  enable listen port combobox;*/

void TcpClientBox::enableConnectTcpServer()
{
    bool boolb = false;
    bool boola = Core->checkIpRules(Modulea->ui->comboBox->currentText());
    Modulea->ui->comboBox_2->currentText().toInt(&boolb);
    if(boola == true && boolb == true)
    {
        Modulea->ui->pushButton_37->setEnabled(true);
    }
}

/*  Enable connect tcpserver button or not*/

void TcpClientBox::connectTcpServer()
{
    bool boola = Network->connectTcpServer(Tcpsocket,Modulea->ui->comboBox->currentText(),Modulea->ui->comboBox_2->currentText().toInt(),1000);
    if(boola)
    {
        Core->enableWidgetList(&Connectwidgetet,true);
        Core->enableWidgetList(&Connectwidgetef,false);
        enableSenderBox(true);
        Logger->displayLog("N","tcpclient has been connected","Connecttcpserver function run completed");
    }
    else
    {
        Logger->displayLog("N","connect " + Modulea->ui->comboBox->currentText() + " failed","Connecttcpserver function run completed;");
    }
}

/*  use current setting connect to server;*/

void TcpClientBox::disconnectTcpServer()
{
    Network->disConnectTcpServer(Tcpsocket,1000);
}

/*  disconnect server;*/

void TcpClientBox::enableSenderBox(bool boola)
{
    if(boola)
    {
        for(int i = 0;i < Senderboxlist.count();i++)
        {
            Senderboxlist.at(i)->enable();
        }
    }
    else
    {
        for(int i = 0;i < Senderboxlist.count();i++)
        {
            Senderboxlist.at(i)->disable();
        }
    }
}

/*  enable senderbox or not;*/

void TcpClientBox::writeApi(QLineEdit* lineeditdata)
{
    Logger->Result.clear();
    Network->writeSocket(Modulea->ui->checkBox_3,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Tcpsocket,lineeditdata);
    Logger->displayLog("W",lineeditdata->text(),"Writedata function run completed");
}

/*  write text to socket;*/

void TcpClientBox::recordText()
{
    for(int i = 0;i < Senderboxlist.count();i++)
    {
        Stringlist[i] = Senderboxlist.at(i)->Lineedit->text();
    }
    Core->writeOnlyFileList(Cachefile,&Stringlist,Spliter,false);
}

/*  record last text;*/

void TcpClientBox::readData()
{
    QByteArray byteresult = Network->readDataStream(Tcpsocket,Modulea->ui->checkBox_3);
    Logger->displayLog("R",byteresult,"Readdata function run completed;");
    Logger->Result.append(byteresult);
}

/*  read tcpsocket data;*/

void TcpClientBox::enableAddn()
{
    if(Modulea->ui->checkBox_2->isChecked())
    {
        Logger->displayLog("N","input line has been add \\n","enableaddn function run completed");
    }
    else
    {
        Logger->displayLog("N","input line has been cancel \\n","enableaddn function run completed");
    }
}

/*  write data add \\n;*/

void TcpClientBox::enableAddr()
{
    if(Modulea->ui->checkBox_1->isChecked())
    {
        Logger->displayLog("N","input line has been add \\r","enableaddr function run completed");
    }
    else
    {
        Logger->displayLog("N","input line has been cancel \\r","enableaddr function run completed");
    }
}

/*  write data add \\r;*/

void TcpClientBox::changeTypea()
{
    if(Modulea->ui->checkBox_3->isChecked())
    {
        changeTypeapi(Modulea->ui->checkBox_4,"input line has been changed to string","changetypea function run completed",false,true,true);
    }
    else
    {
        changeTypeapi(Modulea->ui->checkBox_4,"input line has been changed to hex","changetypea function run completed",true,false,false);
    }
}

/*  change write data type string or hex;*/

void TcpClientBox::changeTypeb()
{
    if(Modulea->ui->checkBox_4->isChecked())
    {
        changeTypeapi(Modulea->ui->checkBox_3,"input line has been changed to hex","Changetypeb function run completed",false,false,false);
    }
    else
    {
        changeTypeapi(Modulea->ui->checkBox_3,"input line has been changed to string","Changetypeb function run completed",true,true,true);
    }
}

/*  change write data type string or hex;*/

void TcpClientBox::changeTypeapi(QCheckBox* checkboxtype,QString strtlog,QString strllog,bool boola,bool boolb,bool boolc)
{
    checkboxtype->setChecked(boola);
    Modulea->ui->checkBox_1->setEnabled(boolb);
    Modulea->ui->checkBox_2->setEnabled(boolc);
    Logger->displayLog("N",strtlog,strllog);
}

/*  change write data type api;*/

void TcpClientBox::abnormalDisconnect()
{
    Core->enableWidgetList(&Disconnectwidgetet,true);
    Core->enableWidgetList(&Disconnectwidgetef,false);
    enableConnectTcpServer();
    enableSenderBox(false);
    Logger->displayLog("N","tcpclient has been disconnect","checkconnect function run completed");
}

/*  receive result from signalc,check serial port is connect or not;*/

void TcpClientBox::adjustSenderBox()
{
    Senderboxlist.clear();
    Core->deleteAllItemsOfLayout(Moduleb->ui->verticalLayout_8);
    Logger->displayLog("N","senderbox adjust counts as: " + QString::number(Moduleb->ui->spinBox->value()),"Adjustsenderbox function run completed;");
    for(int i = 0;i < Moduleb->ui->spinBox->value();i++)
    {
        SuperSender *senderbox = new SuperSender(this,Moduleb->ui->verticalLayout_8);
        connect(senderbox,&SuperSender::signalSa,this,&TcpClientBox::writeApi);
        connect(senderbox,&SuperSender::signalSb,this,&TcpClientBox::recordText);
        senderbox->Lineedit->setText(Stringlist.at(Senderboxlist.count()));
        Senderboxlist.append(senderbox);
        senderbox->disable();
    }
}

/*  adjust sender box;*/
