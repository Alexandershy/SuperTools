#include "_geminibox_.h"

SuperTab* Interface::Loadplugin()
{
    return new GeminiBox();
}

/*  return class geminibox new instance pointer;*/

GeminiBox::GeminiBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("GeminiBox");
    setGroupBox(2,1);
    setStretch({1,99},{100});
    init();
}

GeminiBox::~GeminiBox()
{
    Serial->closeSerial(Serialport);
    Core->closeThread(Threadsa);
    Core->closeThread(Threadta);
    Core->closeThread(Threadtb);
    Core->closeThread(Threadtc);
    Core->closeThread(Threadtd);
    Core->closeThread(Threadte);
}

void GeminiBox::init()
{
    objectInit();
    timerInit();
    widgetListInit();
}

void GeminiBox::objectInit()
{
    Serial = new SuperSerial(this);
    Serialport = new QSerialPort(this);
    Modulea = new GeminiModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new GeminiModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Threadsa = new SuperScanSerial(this,Serialport,1000000,"help","version",Moduleb->ui->checkBox_30,Moduleb->ui->lineEdit_33,"Available commands:","+");
    connect(Threadsa,   &SuperScanSerial::signalSa,  Logger, &SuperLogger::displayLog);
    connect(Threadsa,   &SuperScanSerial::signalSb,  this,   &GeminiBox::signalSbSlot);
    connect(Threadsa,   &SuperScanSerial::signalSc,  this,   &GeminiBox::signalScSlot);
    connect(Modulea->ui->pushButton_51,  &QPushButton::clicked,          this,   &GeminiBox::getSerialPort);
    connect(Modulea->ui->pushButton_54,  &QPushButton::clicked,          this,   &GeminiBox::connectSerialPort);
    connect(Modulea->ui->pushButton_56,  &QPushButton::clicked,          this,   &GeminiBox::scanGeminiPort);
    connect(Modulea->ui->comboBox_4,     &QComboBox::textActivated,      this,   &GeminiBox::enableConnectButton);
    connect(Modulea->ui->pushButton_55,  &QPushButton::clicked,          this,   &GeminiBox::disconnectSerialPort);
    connect(Moduleb->ui->comboBox_5,     &QComboBox::currentTextChanged, this,   &GeminiBox::enableRunTxTest);
    connect(Moduleb->ui->comboBox_6,     &QComboBox::currentTextChanged, this,   &GeminiBox::enableRunTxTest);
    connect(Moduleb->ui->comboBox_7,     &QComboBox::currentTextChanged, this,   &GeminiBox::enableRunTxTest);
    connect(Moduleb->ui->comboBox_8,     &QComboBox::currentTextChanged, this,   &GeminiBox::enableRunTxTest);
    connect(Moduleb->ui->comboBox_9,     &QComboBox::currentTextChanged, this,   &GeminiBox::enableStartRxTest);
    connect(Moduleb->ui->pushButton_46,  &QPushButton::clicked,          this,   &GeminiBox::help);
    connect(Moduleb->ui->pushButton_47,  &QPushButton::clicked,          this,   &GeminiBox::checkVersion);
    connect(Moduleb->ui->pushButton_48,  &QPushButton::clicked,          this,   &GeminiBox::runTxTest);
    connect(Moduleb->ui->pushButton_49,  &QPushButton::clicked,          this,   &GeminiBox::startRxTest);
    connect(Moduleb->ui->pushButton_50,  &QPushButton::clicked,          this,   &GeminiBox::endRxTest);
}

/*  object init;*/

void GeminiBox::timerInit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&GeminiBox::timerCaSlot);
}

/*  timer init;*/

void GeminiBox::widgetListInit()
{
    Connectwidgetet     = {Moduleb->ui->comboBox_5,Moduleb->ui->comboBox_6,Moduleb->ui->comboBox_7,Moduleb->ui->comboBox_8,Moduleb->ui->comboBox_9,Modulea->ui->pushButton_55,Moduleb->ui->pushButton_46,Moduleb->ui->pushButton_47,Moduleb->ui->lineEdit_17,Moduleb->ui->lineEdit_18,Moduleb->ui->lineEdit_19,Moduleb->ui->lineEdit_20,Moduleb->ui->lineEdit_21};
    Connectwidgetef     = {Modulea->ui->comboBox_4,Modulea->ui->pushButton_54,Modulea->ui->pushButton_56,Modulea->ui->pushButton_51};
    Disconnectwidgetet  = {Modulea->ui->comboBox_4,Modulea->ui->pushButton_54,Modulea->ui->pushButton_51,Modulea->ui->pushButton_56};
    Disconnectwidgetef  = {Moduleb->ui->comboBox_5,Moduleb->ui->comboBox_6,Moduleb->ui->comboBox_7,Moduleb->ui->comboBox_8,Moduleb->ui->comboBox_9,Modulea->ui->pushButton_55,Moduleb->ui->pushButton_46,Moduleb->ui->pushButton_47,Moduleb->ui->pushButton_48,Moduleb->ui->pushButton_49,Moduleb->ui->pushButton_50,Moduleb->ui->lineEdit_17,Moduleb->ui->lineEdit_18,Moduleb->ui->lineEdit_19,Moduleb->ui->lineEdit_20,Moduleb->ui->lineEdit_21};
}

/*  widget list init;*/

void GeminiBox::getSerialPort()
{
    Serial->getSerialPort(&Serialnamelist,Modulea->ui->comboBox_4);
    Serial->enableSerialComboBox(&Serialnamelist,Modulea->ui->comboBox_4,Modulea->ui->comboBox_4);
    Serial->enableConnectButton(Modulea->ui->comboBox_4,Modulea->ui->comboBox_31,Modulea->ui->pushButton_54);
    if(Modulea->ui->comboBox_4->currentText().isEmpty())
    {
        Logger->displayLog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_4->count();i++)
        {
            Logger->displayLog("N",Modulea->ui->comboBox_4->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

void GeminiBox::connectSerialPort()
{
    Serial->connectSerialPort(Serialport,Serialnamelist[Modulea->ui->comboBox_4->currentIndex()],Modulea->ui->comboBox_31->currentText().toInt());
    if(Serialport->isOpen())
    {
        Core->enableWidgetList(&Connectwidgetet,true);
        Core->enableWidgetList(&Connectwidgetef,false);
        enableRunTxTest();
        enableStartRxTest();
        Timerca->start();
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_4->currentText() + " and set baudrate as " + Modulea->ui->comboBox_31->currentText() + " success","Connectserialport function run completed");
    }
    else
    {
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_4->currentText() + " and set baudrate as " + Modulea->ui->comboBox_31->currentText() + " failed","Connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for read data and check connected device;*/

void GeminiBox::disconnectSerialPort()
{
    Serialport->close();
    if(!Serialport->isOpen())
    {
        Core->enableWidgetList(&Disconnectwidgetef,false);
        Core->enableWidgetList(&Disconnectwidgetet,true);
        Timerca->stop();
        Logger->displayLog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui*/;

bool GeminiBox::enableConnectButton()
{
    return Serial->enableConnectButton(Modulea->ui->comboBox_4,Modulea->ui->comboBox_31,Modulea->ui->pushButton_54);
}

/*  check is enable connect button;*/;

void GeminiBox::geminiCommand(QString strcommand)
{
    Moduleb->ui->lineEdit_33->setText(strcommand);
    Serial->writeSerial(Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Serialport,Moduleb->ui->lineEdit_33);
    Logger->displayLog("W",strcommand,"geminiCommand function run completed");
}

/*  send and read command quick api;*/

void GeminiBox::help()
{
    Moduleb->ui->pushButton_46->setEnabled(false);
    geminiCommand("help");
    Threadta = new SuperSerialThread(Serialport,1000);
    connect(Threadta,&SuperSerialThread::signalTt,this,     &GeminiBox::signalTtaSlot);
    connect(Threadta,&SuperSerialThread::signalTf,this,     &GeminiBox::signalTfaSlot);
    connect(Threadta,&SuperSerialThread::finished,Threadta, &QObject::deleteLater);
    Threadta->start();
}

/*  send and read help command;*/

void GeminiBox::checkVersion()
{
    Moduleb->ui->pushButton_47->setEnabled(false);
    geminiCommand("version");
    Threadtb = new SuperSerialThread(Serialport,1000);
    connect(Threadtb,&SuperSerialThread::signalTt,this,     &GeminiBox::signalTtbSlot);
    connect(Threadtb,&SuperSerialThread::signalTf,this,     &GeminiBox::signalTfbSlot);
    connect(Threadtb,&SuperSerialThread::finished,Threadtb, &QObject::deleteLater);
    Threadtb->start();
}

/*  send and read version command;*/

void GeminiBox::runTxTest()
{
    QString Strcommand = "run_tx_test " + Moduleb->ui->comboBox_5->currentText() + " " + Moduleb->ui->comboBox_6->currentText() + " " + Moduleb->ui->comboBox_7->currentText() + " " + Moduleb->ui->comboBox_8->currentText();
    Moduleb->ui->pushButton_48->setEnabled(false);
    Moduleb->ui->pushButton_48->setText("Transmiting...");
    Moduleb->ui->lineEdit_33->setText(Strcommand);
    Serial->writeSerial(Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Serialport,Moduleb->ui->lineEdit_33);
    Logger->displayLog("W",Strcommand,"Runtxtest function running...");
    Threadtc = new SuperSerialThread(Serialport,Moduleb->ui->comboBox_8->currentText().toInt() * 2);
    connect(Threadtc,&SuperSerialThread::signalTt,this,      &GeminiBox::signalTtcSlot);
    connect(Threadtc,&SuperSerialThread::signalTf,this,      &GeminiBox::signalTfcSlot);
    connect(Threadtc,&SuperSerialThread::finished,Threadtc,  &QObject::deleteLater);
    Threadtc->start();
}

/*  send and read run tx test command;*/

void GeminiBox::startRxTest()
{
    geminiCommand("start_rx_test " + Moduleb->ui->comboBox_9->currentText());
    Threadtd = new SuperSerialThread(Serialport,1000);
    connect(Threadtd,&SuperSerialThread::signalTt,this,     &GeminiBox::signalTtdSlot);
    connect(Threadtd,&SuperSerialThread::signalTf,this,     &GeminiBox::signalTfdSlot);
    connect(Threadtd,&SuperSerialThread::finished,Threadtd, &QObject::deleteLater);
    Threadtd->start();
}

/*  send and read start rx test command;*/

void GeminiBox::endRxTest()
{
    geminiCommand("end_rx_test");
    Threadte = new SuperSerialThread(Serialport,1000);
    connect(Threadte,&SuperSerialThread::signalTt,this,     &GeminiBox::signalTteSlot);
    connect(Threadte,&SuperSerialThread::signalTf,this,     &GeminiBox::signalTfeSlot);
    connect(Threadte,&SuperSerialThread::finished,Threadte, &QObject::deleteLater);
    Threadte->start();
}

/*  send and read end rx test command and refresh ui;*/

void GeminiBox::enableRunTxTest()
{
    bool boola = false;
    bool boolb = false;
    bool boolc = false;
    bool boold = false;
    Moduleb->ui->comboBox_5->currentText().toInt(&boola);
    Moduleb->ui->comboBox_6->currentText().toInt(&boolb);
    Moduleb->ui->comboBox_7->currentText().toInt(&boolc);
    Moduleb->ui->comboBox_8->currentText().toInt(&boold);
    if(boola && boolb && boolc && boold && !Moduleb->ui->pushButton_50->isEnabled())
    {
        Moduleb->ui->pushButton_48->setEnabled(true);
        Logger->displayLog("N","set frequency as " + Moduleb->ui->comboBox_5->currentText() + "(hz),power as " + Moduleb->ui->comboBox_6->currentText()  + "(dbm),length as " + Moduleb->ui->comboBox_7->currentText() + "(bits),number as " + Moduleb->ui->comboBox_8->currentText() + "(pkts)",
                   "Enableruntxtest function run completed");
    }
    else
    {
        Moduleb->ui->pushButton_48->setEnabled(false);
        Logger->displayLog("N","please set parameter correctly!,set frequency as " + Moduleb->ui->comboBox_5->currentText() + "(hz),power as " + Moduleb->ui->comboBox_6->currentText()  + "(dbm),length as " + Moduleb->ui->comboBox_7->currentText() + "(bits),number as " + Moduleb->ui->comboBox_8->currentText() + "(pkts)",
                   "Enableruntxtest function run completed");
    }
}

/*  enable run tx test button or not;*/

void GeminiBox::enableStartRxTest()
{
    bool boola = false;
    Moduleb->ui->comboBox_9->currentText().toInt(&boola);
    if(boola && !Moduleb->ui->pushButton_50->isEnabled())
    {
        Moduleb->ui->pushButton_49->setEnabled(true);
        Logger->displayLog("N","set frequency as " + Moduleb->ui->comboBox_9->currentText() + "(hz)","Enablestartrxtest function run completed");
    }
    else
    {
        Moduleb->ui->pushButton_49->setEnabled(false);
        Logger->displayLog("N","please set frequency correctly,set frequency as " + Moduleb->ui->comboBox_9->currentText() + "(hz)","Enablestartrxtest function run completed");
    }
}

/*  enable start rx test button or not;*/

void GeminiBox::scanGeminiPort()
{
    Modulea->ui->pushButton_56->setEnabled(false);
    Threadsa->start();
}

/*  new thread for scan gemini port;*/

void GeminiBox::signalSbSlot(QString strcommand)
{
    Moduleb->ui->lineEdit_33->setText(strcommand);
    Serial->writeSerial(Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Serialport,Moduleb->ui->lineEdit_33);
}

/*  receive command and set to lineedit;*/

void GeminiBox::signalScSlot()
{
    Modulea->ui->pushButton_56->setEnabled(true);
}

/*  receive scan completed signal and enable pushbutton;*/

void GeminiBox::timerCaSlot()
{
    if(Serial->checkSerialDevice(Serialport,Modulea->ui->comboBox_4->currentText()) == false)
    {
        disconnectSerialPort();
        getSerialPort();
        Logger->displayLog("N","serial port has been removed","checkconnect function run completed");
        enableConnectButton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void GeminiBox::signalTtaSlot()
{
    Threadta = nullptr;
    Moduleb->ui->pushButton_46->setEnabled(true);
    Logger->displayLog("R",Serial->readDataStream(Serialport,Moduleb->ui->checkBox_30),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::signalTfaSlot()
{
    Threadta = nullptr;
    Moduleb->ui->pushButton_46->setEnabled(true);
    Logger->displayLog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::signalTtbSlot()
{
    Threadtb = nullptr;
    Moduleb->ui->pushButton_47->setEnabled(true);
    Logger->displayLog("R",Serial->readDataStream(Serialport,Moduleb->ui->checkBox_30),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::signalTfbSlot()
{
    Threadtb = nullptr;
    Moduleb->ui->pushButton_47->setEnabled(true);
    Logger->displayLog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::signalTtcSlot()
{
    Threadtc = nullptr;
    Moduleb->ui->pushButton_48->setEnabled(true);
    Moduleb->ui->pushButton_48->setText("Run Tx Test");
    Logger->displayLog("R",Serial->readDataStream(Serialport,Moduleb->ui->checkBox_30),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::signalTfcSlot()
{
    Threadtc = nullptr;
    Moduleb->ui->pushButton_48->setEnabled(true);
    Moduleb->ui->pushButton_48->setText("Run Tx Test");
    Logger->displayLog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::signalTtdSlot()
{
    Threadtd = nullptr;
    QString Result = Serial->readDataStream(Serialport,Moduleb->ui->checkBox_30);
    Moduleb->ui->pushButton_48->setEnabled(false);
    Moduleb->ui->pushButton_49->setEnabled(false);
    Moduleb->ui->pushButton_49->setText("Receiving...");
    Moduleb->ui->pushButton_50->setEnabled(true);
    Logger->displayLog("R",Result,"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::signalTfdSlot()
{
    Threadtd = nullptr;
    Logger->displayLog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::signalTteSlot()
{
    Threadte = nullptr;
    QString result = Serial->readDataStream(Serialport,Moduleb->ui->checkBox_30);
    QStringList listtemp = result.split(",");
    Moduleb->ui->pushButton_50->setEnabled(false);
    Moduleb->ui->pushButton_49->setText("Start Rx Test");
    enableRunTxTest();
    enableStartRxTest();
    Logger->displayLog("R",result,"Signalraslot function run completed");
    if(listtemp.count() >= 5)
    {
        Moduleb->ui->lineEdit_17->setText(listtemp[0].split(":")[1]);
        Moduleb->ui->lineEdit_18->setText(listtemp[1].split(":")[1]);
        Moduleb->ui->lineEdit_19->setText(listtemp[2].split(":")[1]);
        Moduleb->ui->lineEdit_20->setText(listtemp[3].split(":")[1]);
        Moduleb->ui->lineEdit_21->setText(listtemp[4].split(":")[1].split("}")[0]);
    }
}

/*  receive true readblock signal;*/

void GeminiBox::signalTfeSlot()
{
    Threadte = nullptr;
    Logger->displayLog("R","serial port receive time out","Signaltfeslot function run completed");
}

/*  receive false readblock signal;*/
