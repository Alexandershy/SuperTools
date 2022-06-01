#include "_relaybox_.h"
#include "ui__relaymodulea_.h"
#include "ui__relaymoduleb_.h"
#include "ui__relaymodulec_.h"

SuperTab* Interface::Loadplugin()
{
    return new RelayBox();
}

/*  return class relaybox new instance pointer;*/

RelayBox::RelayBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("RelayBox");
    setGroupBox(2,2);
    setStretch({1,99},{1,99});
    init();
}

RelayBox::~RelayBox()
{
    Serial->closeSerial(Serialport);
    Core->closeThread(Threadta);
    delete Channel15relay;
    delete Channel34relay;
}

void RelayBox::init()
{
    timerInit();
    objectInit();
    widgetListInit();
}

void RelayBox::timerInit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&RelayBox::timerCaSlot);
}

void RelayBox::objectInit()
{
    Serial = new SuperSerial(this);
    Serialport = new QSerialPort(this);
    Modulea = new RelayModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Logger = new SuperLogger(this,Leftgroupboxlist.at(1)->Insidelayout);
    Moduleb = new RelayModuleB(this,Rightgroupboxlist.at(0)->Insidelayout);
    Modulec = new RelayModuleC(this,Rightgroupboxlist.at(1)->Insidelayout);
    connect(Modulea->ui->pushButton_35,  &QPushButton::clicked,      this,   &RelayBox::getSerialPort);
    connect(Modulea->ui->comboBox_1,     &QComboBox::textActivated,  this,   &RelayBox::enableConnectButton);
    connect(Modulea->ui->pushButton_31,  &QPushButton::clicked,      this,   &RelayBox::connectSerialPort);
    connect(Modulea->ui->pushButton_32,  &QPushButton::clicked,      this,   &RelayBox::disconnectSerialPort);
    connect(Modulea->ui->pushButton_33,  &QPushButton::clicked,      this,   &RelayBox::resetAllChannel);
    connect(Modulea->ui->pushButton_34,  &QPushButton::clicked,      this,   &RelayBox::closeAllChannel);
    connect(Modulea->ui->pushButton_45,  &QPushButton::clicked,      this,   &RelayBox::openSelectChannel);
    connect(Modulea->ui->pushButton_44,  &QPushButton::clicked,      this,   &RelayBox::closeSelectChannel);
    connect(Modulea->ui->pushButton_57,  &QPushButton::clicked,      this,   &RelayBox::scanRelayPort);
    connect(Moduleb->ui->comboBox_2,     &QComboBox::textActivated,  this,   &RelayBox::selectRelayModel);
    connect(Moduleb->ui->pushButton,     &QPushButton::clicked,      this,   &RelayBox::selectSetting);
    connect(Moduleb->ui->lineEdit_16,    &QLineEdit::textChanged,    this,   &RelayBox::setSetting);
    Channel15relay = new Channel15(this,Serialport,Modulea->ui->checkBox_29,Modulea->ui->lineEdit);
    connect(Channel15relay,&Channel15::signalCa,Logger,&SuperLogger::displayLog);
    connect(Channel15relay,&Channel15::signalCb,this,&RelayBox::signalSbSlot);
    connect(Channel15relay,&Channel15::signalCc,this,&RelayBox::signalScSlot);
    connect(Channel15relay,&Channel15::signalCd,this,&RelayBox::writeCommand);
    connect(Channel15relay,&Channel15::signalCe,this,&RelayBox::enableRelayButton);
    Channel34relay = new Channel34(this,Serialport,Modulea->ui->checkBox_29,Modulea->ui->lineEdit);
    connect(Channel34relay,&Channel34::signalCa,Logger,&SuperLogger::displayLog);
    connect(Channel34relay,&Channel34::signalCb,this,&RelayBox::signalSbSlot);
    connect(Channel34relay,&Channel34::signalCc,this,&RelayBox::signalScSlot);
    connect(Channel34relay,&Channel34::signalCd,this,&RelayBox::writeCommand);
    connect(Channel34relay,&Channel34::signalCe,this,&RelayBox::enableRelayButton);
    Threadta = new SuperSerialThread(Serialport,1000);
    connect(Threadta,&SuperSerialThread::signalTt,this,  &RelayBox::readyReadSlot);
    connect(Threadta,&SuperSerialThread::signalTf,this,  &RelayBox::readTimeoutSlot);
    Modulec->ui->verticalLayout_8->addWidget(Channel15relay);
    Modulec->ui->verticalLayout_8->addWidget(Channel34relay);
    Fileinfo = QFileInfo(Defaultsettingpath);
    Channel34relay->hide();
}

void RelayBox::widgetListInit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_32,Modulea->ui->pushButton_33,Modulea->ui->pushButton_34,Moduleb->ui->lineEdit_16,Moduleb->ui->pushButton};
    Disconnectwidgetef  = {Modulea->ui->pushButton_33,Modulea->ui->pushButton_34,Modulea->ui->pushButton_32,Modulea->ui->pushButton_44,Modulea->ui->pushButton_45,Moduleb->ui->lineEdit_16,Moduleb->ui->pushButton};
    Connectwidgetef     = {Modulea->ui->pushButton_31,Modulea->ui->pushButton_35,Modulea->ui->pushButton_57,Modulea->ui->comboBox_1,Moduleb->ui->comboBox_2};
    Disconnectwidgetet  = {Modulea->ui->pushButton_31,Modulea->ui->pushButton_35,Modulea->ui->pushButton_57,Modulea->ui->comboBox_1,Moduleb->ui->comboBox_2};
}

/*  widget list init;*/

void RelayBox::getSerialPort()
{
    Serial->getSerialPort(&Serialnamelist,Modulea->ui->comboBox_1);
    Serial->enableSerialComboBox(&Serialnamelist,Modulea->ui->comboBox_1,Modulea->ui->comboBox_1);
    enableConnectButton();
    if(Modulea->ui->comboBox_1->currentText().isEmpty())
    {
        Logger->displayLog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_1->count();i++)
        {
            Logger->displayLog("N",Modulea->ui->comboBox_1->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

bool RelayBox::enableConnectButton()
{
    if(!Moduleb->ui->comboBox_2->currentIndex())
    {
        Modulea->ui->pushButton_31->setEnabled(false);
        Logger->displayLog("N","disable connect button ,select relay model","Enableconnectbutton function run completed");
        return false;
    }
    if(Serial->enableConnectButton(Modulea->ui->comboBox_1,Modulea->ui->comboBox,Modulea->ui->pushButton_31))
    {
        Logger->displayLog("N","enable connect button success","Enableconnectbutton function run completed");
        return true;
    }
    return false;
}

/*  check is enable connect button;*/;

void RelayBox::enableScanPortButton()
{
    if(Moduleb->ui->comboBox_2->currentIndex() && !Modulea->ui->pushButton_32->isEnabled())
    {
        Modulea->ui->pushButton_57->setEnabled(true);
        Logger->displayLog("N","enable scan serial button success","Enablescanportbutton function run completed");
    }
    else
    {
        Modulea->ui->pushButton_57->setEnabled(false);
        Logger->displayLog("N","disable scan serial button","Enablescanportbutton function run completed");
    }
}

/*  check is enable scan serial port button*/;

void RelayBox::connectSerialPort()
{
    Serial->connectSerialPort(Serialport,Serialnamelist[Modulea->ui->comboBox_1->currentIndex()],Modulea->ui->comboBox->currentText().toInt());
    if(Serialport->isOpen())
    {
        Core->enableWidgetList(&Connectwidgetet,true);
        Core->enableWidgetList(&Connectwidgetef,false);
        Core->enableWidgetList(Relayconnectwidgetet,true);
        enableLineEditList(Lineeditlist,true);
        enableRelayButton();
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_1->currentText() + " and set baudrate as " + Modulea->ui->comboBox->currentText() + " success","connectserialport function run completed");
        Timerca->start();
    }
    else
    {
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_1->currentText() + " and set baudrate as " + Modulea->ui->comboBox->currentText() + " failed","connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for check connected device;*/

void RelayBox::disconnectSerialPort()
{
    Serialport->close();
    if(!Serialport->isOpen())
    {
        Core->enableWidgetList(&Disconnectwidgetet,true);
        Core->enableWidgetList(&Disconnectwidgetef,false);
        Core->enableWidgetList(Relaydisconnectwidgetef,false);
        enableLineEditList(Lineeditlist,false);
        Timerca->stop();
        Logger->displayLog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui;*/

void RelayBox::enableLineEditList(QList<QLineEdit*>* lineeditlist,bool boola)
{
    if(!Moduleb->ui->lineEdit_16->text().isEmpty())
    {
        for(int i = 0;i < lineeditlist->count();i++)
        {
            lineeditlist->at(i)->setEnabled(boola);
        }
    }
}

/*  enable lineedit in a list or not;*/

void RelayBox::timerCaSlot()
{
    if(Serial->checkSerialDevice(Serialport,Modulea->ui->comboBox_1->currentText()) == false)
    {
        disconnectSerialPort();
        getSerialPort();
        Logger->displayLog("N","serial port has been removed","Timercaslot function run completed");
        enableConnectButton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void RelayBox::writeCommand(QString strcommand)
{
    Modulea->ui->lineEdit->setText(strcommand);
    Serial->writeSerial(Modulea->ui->checkBox_29,Modulea->ui->checkBox_27,Modulea->ui->checkBox_27,Serialport,Modulea->ui->lineEdit);
    if(Threadta->isRunning())
    {
        Logger->displayLog("N","waitting for return value or timeout;","Writecommand function run completed");
    }
    else
    {
        Logger->displayLog("W",Modulea->ui->lineEdit->text(),"Writecommand function run completed");
        Threadta->start();
    }
}

/*  click single button api;*/

void RelayBox::opreateAllChannel(QStringList *listcommand)
{
    QString Command = "";
    for(int i = 0;i < listcommand->count();i++)
    {
        Command = Command + listcommand->at(i);
    }
    writeCommand(Command);
}

/*  opreate all channel api;*/

void RelayBox::opreateSelectChannel(QStringList *listcommand)
{
    QString comand = "";
    for(int i = 0;i < Checkboxlist->count();i++)
    {
        if (Checkboxlist->at(i)->isChecked())
        {
            comand = comand + listcommand->at(i);
        }
    }
    writeCommand(comand);
}

/*  opreate selected channel api;*/

void RelayBox::resetAllChannel()
{
    opreateAllChannel(Gtkrelayopencommand);
}

/*  open all channel;*/

void RelayBox::closeAllChannel()
{
    opreateAllChannel(Gtkrelayclosecommand);
}

/*  close all channel;*/

void RelayBox::closeSelectChannel()
{
    opreateSelectChannel(Gtkrelayclosecommand);
}

/*  close select channel;*/

void RelayBox::openSelectChannel()
{
    opreateSelectChannel(Gtkrelayopencommand);
}

/*  open select channel;*/

QString RelayBox::checkSelectChannel()
{
    QString temp = "";
    for(int i = 0;i < Checkboxlist->count();i++)
    {
        if(Checkboxlist->at(i)->isChecked())
        {
            temp = temp + "Channel" + QString::number(i + 1) + " ";
        }
    }
    return temp;
}

/*  return checked checkbox;*/

void RelayBox::enableRelayButton()
{
    QString strchannels = checkSelectChannel();
    if(strchannels.isEmpty())
    {
        Modulea->ui->pushButton_44->setEnabled(false);
        Modulea->ui->pushButton_45->setEnabled(false);
    }
    else
    {
        Modulea->ui->pushButton_44->setEnabled(true);
        Modulea->ui->pushButton_45->setEnabled(true);
    }
    Logger->displayLog("N","current selected channels: " + strchannels,"enablerelaybutton function run completed");
}

/*  enable button or not;*/

void RelayBox::scanRelayPort()
{
    Modulea->ui->pushButton_57->setEnabled(false);
    Threadsa->start();
}

/*  start scan relay port;*/

void RelayBox::selectRelayModel()
{
    switch (Moduleb->ui->comboBox_2->currentIndex())
    {
        case 1:
        {
            Channel15relay->setHidden(false);
            Channel34relay->setHidden(true);
            Modulea->ui->checkBox_29->setChecked(false);
            Relayconnectwidgetet    = &Channel15relay->Connectwidgetet;
            Relaydisconnectwidgetef = &Channel15relay->Disconnectwidgetef;
            Progressbarlist         = &Channel15relay->Progressbarlist;
            Checkboxlist            = &Channel15relay->Checkboxlist;
            Gtkrelayclosebackvalue  = &Channel15relay->Closebackvalue;
            Gtkrelayopenbackvalue   = &Channel15relay->Openbackvalue;
            Gtkrelayclosecommand    = &Channel15relay->Closecommand;
            Gtkrelayopencommand     = &Channel15relay->Opencommand;
            Lineeditlist            = &Channel15relay->Lineeditlist;
            Threadsa                = Channel15relay->Threadsa;
            Moduleb->ui->lineEdit_16->setText(Channel15relay->Settingpath);
            Logger->displayLog("N","communication type: hex;","Displayrelaymodel function run completed;");
            Logger->displayLog("N","setting save path:  " + Channel15relay->Settingpath,"Displayrelaymodel function run completed;");
            break;
        }
        case 2:
        {
            Channel15relay->setHidden(true);
            Channel34relay->setHidden(false);
            Modulea->ui->checkBox_29->setChecked(true);
            Relayconnectwidgetet    = &Channel34relay->Connectwidgetet;
            Relaydisconnectwidgetef = &Channel34relay->Disconnectwidgetef;
            Progressbarlist         = &Channel34relay->Progressbarlist;
            Checkboxlist            = &Channel34relay->Checkboxlist;
            Gtkrelayclosebackvalue  = &Channel34relay->Closebackvalue;
            Gtkrelayopenbackvalue   = &Channel34relay->Openbackvalue;
            Gtkrelayclosecommand    = &Channel34relay->Closecommand;
            Gtkrelayopencommand     = &Channel34relay->Opencommand;
            Lineeditlist            = &Channel34relay->Lineeditlist;
            Threadsa                = Channel34relay->Threadsa;
            Moduleb->ui->lineEdit_16->setText(Channel34relay->Settingpath);
            Logger->displayLog("N","communication type: string;","Displayrelaymodel function run completed;");
            Logger->displayLog("N","setting save path:  " + Channel34relay->Settingpath,"Displayrelaymodel function run completed;");
            break;
        }
    }
    enableConnectButton();
    enableScanPortButton();
}

/*  select gtk relay model;*/

void RelayBox::signalSbSlot(QString strcommand)
{
    Modulea->ui->lineEdit->setText(strcommand);
    Serial->writeSerial(Modulea->ui->checkBox_29,Modulea->ui->checkBox_27,Modulea->ui->checkBox_27,Serialport,Modulea->ui->lineEdit);
}

/*  receive signal and write strcommand;*/

void RelayBox::signalScSlot()
{
    Modulea->ui->pushButton_57->setEnabled(true);
}

/*  reset scan pushbutton;*/

void RelayBox::readyReadSlot()
{
    QByteArray result = Serial->readDataStream(Serialport,Modulea->ui->checkBox_29);
    Logger->displayLog("R",result,"Signaltaslot function run completed");
    operatorProgressBar(result,Gtkrelayclosebackvalue,99);
    operatorProgressBar(result,Gtkrelayopenbackvalue,0);
}

/*  receive signal and read data from serial port;*/

void RelayBox::readTimeoutSlot()
{
    Logger->displayLog("R","serial port receive time out","Signaltaslot function run completed");
}

void RelayBox::operatorProgressBar(QString backvalue,QStringList *backvaluelist,int intlight)
{
    for(int i = 0;i < backvaluelist->count();i++)
    {
        if(backvalue.contains(backvaluelist->at(i)))
        {
            Progressbarlist->at(i)->setValue(intlight);
        }
    }
}

/*  check result and opearte progressbar;*/

void RelayBox::selectSetting()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,Fileinfo.absolutePath(),{"*.ini"});
    connect(filedialog,&SuperFileDialog::signalFb,Moduleb->ui->lineEdit_16,  &QLineEdit::setText);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,       &QObject::deleteLater);
    filedialog->setSingleFile();
    filedialog->show();
}

/*  select setting;*/

void RelayBox::setSetting(QString file)
{
    switch (Moduleb->ui->comboBox_2->currentIndex())
    {
        case 1:
        {
            Channel15relay->enableLineEdit(false);
            Channel15relay->setSetting(file);
            break;
        }
        case 2:
        {
            Channel34relay->enableLineEdit(false);
            Channel34relay->setSetting(file);
            break;
        }
    }
}

/*  set setting;*/
