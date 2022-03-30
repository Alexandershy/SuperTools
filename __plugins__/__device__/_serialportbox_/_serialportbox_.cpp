#include "_serialportbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new SerialPortBox();
}

/*  return class SerialPortBox new instance pointer;*/

SerialPortBox::SerialPortBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("SerialPortBox");
    Setgroupbox(2,1);
    Setstretch({1,99},{100});
    Init();
}

SerialPortBox::~SerialPortBox()
{
    SuperS->Closeserial(Serial);
}

void SerialPortBox::Init()
{
    Objectinit();
    Parameterinit();
    Timerinit();
    Widgetlistinit();
}

void SerialPortBox::Objectinit()
{
    SuperS = new SuperSerial(this);
    Serial = new QSerialPort(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Serial,                     &QSerialPort::readyRead,        this,   &SerialPortBox::Readyreadslot);
    connect(Modulea->ui->pushButton_36, &QPushButton::clicked,          this,   &SerialPortBox::Getserialport);
    connect(Modulea->ui->pushButton_37, &QPushButton::clicked,          this,   &SerialPortBox::Connectserialport);
    connect(Modulea->ui->pushButton_38, &QPushButton::clicked,          this,   &SerialPortBox::Disconnectserialport);
    connect(Moduleb->ui->spinBox,       &QSpinBox::editingFinished,     this,   &SerialPortBox::Adjustsenderbox);
    connect(Modulea->ui->comboBox_2,    &QComboBox::textActivated,      this,   &SerialPortBox::Enableconnectbutton);
    connect(Modulea->ui->comboBox_2,    &QComboBox::currentTextChanged, this,   &SerialPortBox::Enableconnectbutton);
    connect(Modulea->ui->comboBox_3,    &QComboBox::editTextChanged,    this,   &SerialPortBox::Enableconnectbutton);
    connect(Modulea->ui->checkBox_2,    &QCheckBox::stateChanged,       this,   &SerialPortBox::Enableaddn);
    connect(Modulea->ui->checkBox_1,    &QCheckBox::stateChanged,       this,   &SerialPortBox::Enableaddr);
    connect(Modulea->ui->checkBox_3,    &QCheckBox::stateChanged,       this,   &SerialPortBox::Changetypea);
    connect(Modulea->ui->checkBox_4,    &QCheckBox::stateChanged,       this,   &SerialPortBox::Changetypeb);
}

/*  init menu and action;*/

void SerialPortBox::Parameterinit()
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

void SerialPortBox::Timerinit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&SerialPortBox::Timercaslot);
}

/*  check connect and cycle write timer init;*/

void SerialPortBox::Widgetlistinit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
    Connectwidgetef     = {Modulea->ui->pushButton_36,Modulea->ui->pushButton_37,Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Moduleb->ui->spinBox};
    Disconnectwidgetef  = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
    Disconnectwidgetet  = {Modulea->ui->pushButton_36,Modulea->ui->pushButton_37,Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Moduleb->ui->spinBox};
}

/*  add ui pointer to list;*/

void SerialPortBox::Getserialport()
{
    SuperS->Getserialport(&Serialnamelist,Modulea->ui->comboBox_2);
    SuperS->Enableserialcombobox(&Serialnamelist,Modulea->ui->comboBox_2,Modulea->ui->comboBox_3);
    SuperS->Enableconnectbutton(Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Modulea->ui->pushButton_37);
    if(Modulea->ui->comboBox_2->currentText().isEmpty())
    {
        Logger->Displaylog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_2->count();i++)
        {
            Logger->Displaylog("N",Modulea->ui->comboBox_2->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

bool SerialPortBox::Enableconnectbutton()
{
    return SuperS->Enableconnectbutton(Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Modulea->ui->pushButton_37);
}

/*  is enable serial port connect button;*/

void SerialPortBox::Enablesenderbox(bool boola)
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

void SerialPortBox::Connectserialport()
{
    SuperS->Connectserialport(Serial,Serialnamelist[Modulea->ui->comboBox_2->currentIndex()],Modulea->ui->comboBox_3->currentText().toInt());
    if(Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Connectwidgetet,true);
        SuperC->Enablewidgetlist(&Connectwidgetef,false);
        Enablesenderbox(true);
        Changetypea();
        Changetypeb();
        Timerca->start();
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_2->currentText() + " and set baudrate as " + Modulea->ui->comboBox_3->currentText() + " success","connectserialport function run completed");
    }
    else
    {
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_2->currentText() + " and set baudrate as " + Modulea->ui->comboBox_3->currentText() + " failed","connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for read data and check connected device;*/

void SerialPortBox::Disconnectserialport()
{
    Serial->close();
    if(!Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Disconnectwidgetef,false);
        SuperC->Enablewidgetlist(&Disconnectwidgetet,true);
        Enablesenderbox(false);
        Timerca->stop();
        Logger->Displaylog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui*/

void SerialPortBox::Enableaddn()
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

void SerialPortBox::Enableaddr()
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

void SerialPortBox::Changetypea()
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

void SerialPortBox::Changetypeb()
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

void SerialPortBox::Changetypeapi(QCheckBox* checkboxtype,QString strtlog,QString strllog,bool boola,bool boolb,bool boolc)
{
    checkboxtype->setChecked(boola);
    Modulea->ui->checkBox_1->setEnabled(boolb);
    Modulea->ui->checkBox_2->setEnabled(boolc);
    Logger->Displaylog("N",strtlog,strllog);
}

/*  change write data type api;*/

void SerialPortBox::Timercaslot()
{
    if(SuperS->Checkserialdevice(Serial,Modulea->ui->comboBox_2->currentText()) == false)
    {
        Disconnectserialport();
        Getserialport();
        Logger->Displaylog("N","serial port has been removed","checkconnect function run completed");
        Enableconnectbutton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void SerialPortBox::Readyreadslot()
{
    QByteArray result = SuperS->Readdatastream(Serial,Modulea->ui->checkBox_3);
    Logger->Displaylog("R",result,"Readyreadslot function run completed");
    Logger->Result.append(result);
}

/*  receive singalr result, and display on textbrowser;*/

void SerialPortBox::Writeapi(QLineEdit *lineedit)
{
    Logger->Result.clear();
    SuperS->Writeserial(Modulea->ui->checkBox_3,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Serial,lineedit);
    Logger->Displaylog("W",lineedit->text(),"Timerwaslot function run completed");
}

/*  run lineinput1 cycle write;*/

void SerialPortBox::Recordtext()
{
    for(int i = 0;i < Senderboxlist.count();i++)
    {
        Stringlist[i] = Senderboxlist.at(i)->Lineedit->text();
    }
    SuperC->Writeonlyfilelist(Cachefile,&Stringlist,Spliter,false);
}

/*  record last text;*/

void SerialPortBox::Adjustsenderbox()
{
    Senderboxlist.clear();
    SuperC->Deleteallitemsoflayout(Moduleb->ui->verticalLayout_8);
    Logger->Displaylog("N","senderbox adjust counts as: " + QString::number(Moduleb->ui->spinBox->value()),"Adjustsenderbox function run completed;");
    for(int i = 0;i < Moduleb->ui->spinBox->value();i++)
    {
        SuperSender *senderbox = new SuperSender(this,Moduleb->ui->verticalLayout_8);
        connect(senderbox,&SuperSender::Signalsa,this,&SerialPortBox::Writeapi);
        connect(senderbox,&SuperSender::Signalsb,this,&SerialPortBox::Recordtext);
        senderbox->Lineedit->setText(Stringlist.at(Senderboxlist.count()));
        Senderboxlist.append(senderbox);
        senderbox->Disable();
    }
}

/*  adjust sender box;*/
