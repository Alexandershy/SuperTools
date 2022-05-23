#include "_serialportbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new SerialPortBox();
}

/*  return class SerialPortBox new instance pointer;*/

SerialPortBox::SerialPortBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("SerialPortBox");
    setGroupBox(2,1);
    setStretch({1,99},{100});
    init();
}

SerialPortBox::~SerialPortBox()
{
    Serial->closeSerial(Serialport);
}

void SerialPortBox::init()
{
    objectInit();
    parameterInit();
    timerInit();
    widgetListInit();
}

void SerialPortBox::objectInit()
{
    Serial = new SuperSerial(this);
    Serialport = new QSerialPort(this);
    Modulea = new SerialPortModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new SerialPortModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Serialport,                 &QSerialPort::readyRead,        this,   &SerialPortBox::readyReadSlot);
    connect(Modulea->ui->pushButton_36, &QPushButton::clicked,          this,   &SerialPortBox::getSerialPort);
    connect(Modulea->ui->pushButton_37, &QPushButton::clicked,          this,   &SerialPortBox::connectSerialPort);
    connect(Modulea->ui->pushButton_38, &QPushButton::clicked,          this,   &SerialPortBox::disconnectSerialPort);
    connect(Moduleb->ui->spinBox,       &QSpinBox::editingFinished,     this,   &SerialPortBox::adjustSenderBox);
    connect(Modulea->ui->comboBox_2,    &QComboBox::textActivated,      this,   &SerialPortBox::enableConnectButton);
    connect(Modulea->ui->comboBox_2,    &QComboBox::currentTextChanged, this,   &SerialPortBox::enableConnectButton);
    connect(Modulea->ui->comboBox_3,    &QComboBox::editTextChanged,    this,   &SerialPortBox::enableConnectButton);
    connect(Modulea->ui->checkBox_2,    &QCheckBox::stateChanged,       this,   &SerialPortBox::enableAddn);
    connect(Modulea->ui->checkBox_1,    &QCheckBox::stateChanged,       this,   &SerialPortBox::enableAddr);
    connect(Modulea->ui->checkBox_3,    &QCheckBox::stateChanged,       this,   &SerialPortBox::changeTypea);
    connect(Modulea->ui->checkBox_4,    &QCheckBox::stateChanged,       this,   &SerialPortBox::changeTypeb);
}

/*  init menu and action;*/

void SerialPortBox::parameterInit()
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

void SerialPortBox::timerInit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&SerialPortBox::timerCaSlot);
}

/*  check connect and cycle write timer init;*/

void SerialPortBox::widgetListInit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
    Connectwidgetef     = {Modulea->ui->pushButton_36,Modulea->ui->pushButton_37,Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Moduleb->ui->spinBox};
    Disconnectwidgetef  = {Modulea->ui->pushButton_38,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Modulea->ui->checkBox_4};
    Disconnectwidgetet  = {Modulea->ui->pushButton_36,Modulea->ui->pushButton_37,Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Moduleb->ui->spinBox};
}

/*  add ui pointer to list;*/

void SerialPortBox::getSerialPort()
{
    Serial->getSerialPort(&Serialnamelist,Modulea->ui->comboBox_2);
    Serial->enableSerialComboBox(&Serialnamelist,Modulea->ui->comboBox_2,Modulea->ui->comboBox_3);
    Serial->enableConnectButton(Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Modulea->ui->pushButton_37);
    if(Modulea->ui->comboBox_2->currentText().isEmpty())
    {
        Logger->displayLog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_2->count();i++)
        {
            Logger->displayLog("N",Modulea->ui->comboBox_2->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

bool SerialPortBox::enableConnectButton()
{
    return Serial->enableConnectButton(Modulea->ui->comboBox_2,Modulea->ui->comboBox_3,Modulea->ui->pushButton_37);
}

/*  is enable serial port connect button;*/

void SerialPortBox::enableSenderBox(bool boola)
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

void SerialPortBox::connectSerialPort()
{
    Serial->connectSerialPort(Serialport,Serialnamelist[Modulea->ui->comboBox_2->currentIndex()],Modulea->ui->comboBox_3->currentText().toInt());
    if(Serialport->isOpen())
    {
        Core->enableWidgetList(&Connectwidgetet,true);
        Core->enableWidgetList(&Connectwidgetef,false);
        enableSenderBox(true);
        changeTypea();
        changeTypeb();
        Timerca->start();
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_2->currentText() + " and set baudrate as " + Modulea->ui->comboBox_3->currentText() + " success","connectSerialPort function run completed");
    }
    else
    {
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_2->currentText() + " and set baudrate as " + Modulea->ui->comboBox_3->currentText() + " failed","connectSerialPort function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for read data and check connected device;*/

void SerialPortBox::disconnectSerialPort()
{
    Serialport->close();
    if(!Serialport->isOpen())
    {
        Core->enableWidgetList(&Disconnectwidgetef,false);
        Core->enableWidgetList(&Disconnectwidgetet,true);
        enableSenderBox(false);
        Timerca->stop();
        Logger->displayLog("N",this->objectName() + " has been disconnected","disconnectSerialPort function run completed");
    }
}

/*  disconnect serial port and operate ui*/

void SerialPortBox::enableAddn()
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

void SerialPortBox::enableAddr()
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

void SerialPortBox::changeTypea()
{
    if(Modulea->ui->checkBox_3->isChecked())
    {
        changeTypeApi(Modulea->ui->checkBox_4,"input line has been changed to string","changetypea function run completed",false,true,true);
    }
    else
    {
        changeTypeApi(Modulea->ui->checkBox_4,"input line has been changed to hex","changetypea function run completed",true,false,false);
    }
}

/*  change write data type string or hex;*/

void SerialPortBox::changeTypeb()
{
    if(Modulea->ui->checkBox_4->isChecked())
    {
        changeTypeApi(Modulea->ui->checkBox_3,"input line has been changed to hex","Changetypeb function run completed",false,false,false);
    }
    else
    {
        changeTypeApi(Modulea->ui->checkBox_3,"input line has been changed to string","Changetypeb function run completed",true,true,true);
    }
}

/*  change write data type string or hex;*/

void SerialPortBox::changeTypeApi(QCheckBox* checkboxtype,QString strtlog,QString strllog,bool boola,bool boolb,bool boolc)
{
    checkboxtype->setChecked(boola);
    Modulea->ui->checkBox_1->setEnabled(boolb);
    Modulea->ui->checkBox_2->setEnabled(boolc);
    Logger->displayLog("N",strtlog,strllog);
}

/*  change write data type api;*/

void SerialPortBox::timerCaSlot()
{
    if(Serial->checkSerialDevice(Serialport,Modulea->ui->comboBox_2->currentText()) == false)
    {
        disconnectSerialPort();
        getSerialPort();
        Logger->displayLog("N","serial port has been removed","checkconnect function run completed");
        enableConnectButton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void SerialPortBox::readyReadSlot()
{
    QByteArray result = Serial->readDataStream(Serialport,Modulea->ui->checkBox_3);
    Logger->displayLog("R",result,"Readyreadslot function run completed");
    Logger->Result.append(result);
}

/*  receive singalr result, and display on textbrowser;*/

void SerialPortBox::writeApi(QLineEdit *lineedit)
{
    Logger->Result.clear();
    Serial->writeSerial(Modulea->ui->checkBox_3,Modulea->ui->checkBox_1,Modulea->ui->checkBox_2,Serialport,lineedit);
    Logger->displayLog("W",lineedit->text(),"Timerwaslot function run completed");
}

/*  run lineinput1 cycle write;*/

void SerialPortBox::recordText()
{
    for(int i = 0;i < Senderboxlist.count();i++)
    {
        Stringlist[i] = Senderboxlist.at(i)->Lineedit->text();
    }
    Core->writeOnlyFileList(Cachefile,&Stringlist,Spliter,false);
}

/*  record last text;*/

void SerialPortBox::adjustSenderBox()
{
    Senderboxlist.clear();
    Core->deleteAllItemsOfLayout(Moduleb->ui->verticalLayout_8);
    Logger->displayLog("N","senderbox adjust counts as: " + QString::number(Moduleb->ui->spinBox->value()),"Adjustsenderbox function run completed;");
    for(int i = 0;i < Moduleb->ui->spinBox->value();i++)
    {
        SuperSender *senderbox = new SuperSender(this,Moduleb->ui->verticalLayout_8);
        connect(senderbox,&SuperSender::signalSa,this,&SerialPortBox::writeApi);
        connect(senderbox,&SuperSender::signalSb,this,&SerialPortBox::recordText);
        senderbox->Lineedit->setText(Stringlist.at(Senderboxlist.count()));
        Senderboxlist.append(senderbox);
        senderbox->disable();
    }
}

/*  adjust sender box;*/
