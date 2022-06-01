#include "_ledanalyserbox_.h"
#include "ui__ledanalysermodulea_.h"
#include "ui__ledanalysermoduleb_.h"

SuperTab* Interface::Loadplugin()
{
    return new LedAnalyserBox();
}

/*  return class ledanalyserbox new instance pointer;*/

LedAnalyserBox::LedAnalyserBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("LedAnalyserBox");
    setGroupBox(2,1);
    setStretch({1,99},{100});
    init();
}

LedAnalyserBox::~LedAnalyserBox()
{
    Serial->closeSerial(Serialport);
    Core->closeThread(Threadaa);
    Core->closeThread(Threadsa);
    Core->closeThread(Threadta);;
}

void LedAnalyserBox::init()
{
    objectInit();
    timerInit();
    widgetListInit();
}

void LedAnalyserBox::objectInit()
{
    Serial = new SuperSerial(this);
    Serialport  = new QSerialPort(this);
    Modulea = new LedAnalyserModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new LedAnalyserModuleB(this,Rightgroupboxlist.at(0)->Insidelayout);
    Logger = new SuperLogger(this,Leftgroupboxlist.at(1)->Insidelayout);
    connect(Modulea->ui->comboBox_26,    &QComboBox::textActivated,  this,   &LedAnalyserBox::enableConnectButton);
    connect(Modulea->ui->comboBox_30,    &QComboBox::textActivated,  this,   &LedAnalyserBox::systemCommand);
    connect(Modulea->ui->pushButton_89,  &QPushButton::clicked,      this,   &LedAnalyserBox::connectSerialPort);
    connect(Modulea->ui->pushButton_90,  &QPushButton::clicked,      this,   &LedAnalyserBox::getSerialPort);
    connect(Modulea->ui->pushButton_91,  &QPushButton::clicked,      this,   &LedAnalyserBox::scanLedPort);
    connect(Modulea->ui->pushButton_92,  &QPushButton::clicked,      this,   &LedAnalyserBox::disconnectSerialPort);
    connect(Modulea->ui->pushButton_94,  &QPushButton::clicked,      this,   &LedAnalyserBox::startDisplayValue);
    connect(Modulea->ui->radioButton_3,  &QRadioButton::toggled,     this,   &LedAnalyserBox::enablePwm);
    connect(Modulea->ui->radioButton_4,  &QRadioButton::toggled,     this,   &LedAnalyserBox::enablePwm);
    connect(Moduleb->ui->comboBox_28,    &QComboBox::textActivated,  this,   &LedAnalyserBox::selectLedAnalyserInfo);
}

void LedAnalyserBox::timerInit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&LedAnalyserBox::timerCaSlot);
}

void LedAnalyserBox::widgetListInit()
{
    Titlelable  = {Moduleb->ui->label_231,Moduleb->ui->label_168,Moduleb->ui->label_169,Moduleb->ui->label_170};
    Valuelabel  = {Moduleb->ui->label_171,Moduleb->ui->label_172,Moduleb->ui->label_173,Moduleb->ui->label_174,Moduleb->ui->label_175,Moduleb->ui->label_176,Moduleb->ui->label_177,Moduleb->ui->label_178,Moduleb->ui->label_179,Moduleb->ui->label_180,
                   Moduleb->ui->label_181,Moduleb->ui->label_182,Moduleb->ui->label_183,Moduleb->ui->label_184,Moduleb->ui->label_185,Moduleb->ui->label_186,Moduleb->ui->label_187,Moduleb->ui->label_188,Moduleb->ui->label_189,Moduleb->ui->label_190,
                   Moduleb->ui->label_191,Moduleb->ui->label_192,Moduleb->ui->label_193,Moduleb->ui->label_194,Moduleb->ui->label_195,Moduleb->ui->label_196,Moduleb->ui->label_197,Moduleb->ui->label_198,Moduleb->ui->label_199,Moduleb->ui->label_200,
                   Moduleb->ui->label_201,Moduleb->ui->label_202,Moduleb->ui->label_203,Moduleb->ui->label_204,Moduleb->ui->label_205,Moduleb->ui->label_206,Moduleb->ui->label_207,Moduleb->ui->label_208,Moduleb->ui->label_209,Moduleb->ui->label_210,
                   Moduleb->ui->label_211,Moduleb->ui->label_212,Moduleb->ui->label_213,Moduleb->ui->label_214,Moduleb->ui->label_215,Moduleb->ui->label_216,Moduleb->ui->label_217,Moduleb->ui->label_218,Moduleb->ui->label_219,Moduleb->ui->label_220,
                   Moduleb->ui->label_221,Moduleb->ui->label_222,Moduleb->ui->label_223,Moduleb->ui->label_224,Moduleb->ui->label_225,Moduleb->ui->label_226,Moduleb->ui->label_227,Moduleb->ui->label_228,Moduleb->ui->label_229,Moduleb->ui->label_230};
    Checkbox    = {Moduleb->ui->checkBox_47,Moduleb->ui->checkBox_48,Moduleb->ui->checkBox_49,Moduleb->ui->checkBox_50,Moduleb->ui->checkBox_51,Moduleb->ui->checkBox_52,Moduleb->ui->checkBox_53,Moduleb->ui->checkBox_54,Moduleb->ui->checkBox_55,Moduleb->ui->checkBox_56,
                   Moduleb->ui->checkBox_57,Moduleb->ui->checkBox_58,Moduleb->ui->checkBox_59,Moduleb->ui->checkBox_60,Moduleb->ui->checkBox_61,Moduleb->ui->checkBox_62,Moduleb->ui->checkBox_63,Moduleb->ui->checkBox_64,Moduleb->ui->checkBox_65,Moduleb->ui->checkBox_66};
}

/*  widget list init;*/

void LedAnalyserBox::selectLedAnalyserInfo()
{
    if(Moduleb->ui->comboBox_28->currentText() == "select led analyser model")
    {
        resetFunction();
    }
    else
    {
        resetFunction();
        ledAnalyserInfo();
    }
    enableConnectButton();
    enableScanPortButton();
}

/*  select led analyser info;*/

void LedAnalyserBox::resetFunction()
{
    for(int i = 0;i < Titlelable.count();i++)
    {
        Titlelable.at(i)->setEnabled(false);
    }
    for(int i = 0;i < Valuelabel.count();i++)
    {
        Valuelabel.at(i)->setEnabled(false);
        Valuelabel.at(i)->setText("");
    }
    for(int i = 0;i < Checkbox.count();i++) // 5
    {
        Checkbox.at(i)->setChecked(false);
        Checkbox.at(i)->setEnabled(false);
    }
}

/*  reset function widget;*/

void LedAnalyserBox::ledAnalyserInfo()
{
    QStringList ledanalyserinfo = Moduleb->ui->comboBox_28->currentText().split(" - ");
    Model = ledanalyserinfo.at(0);
    Function = ledanalyserinfo.at(0);
    Rgbbool = false;
    Command = "getwi";
    Index[0] = 0;
    Index[1] = 1;
    if(Function.contains("rgb"))
    {
        Rgbbool = true;
        Command = "getrgbi";
        Index[0] = 2;
        Index[1] = 1;
    }
    Channels = ledanalyserinfo.at(0).toInt();
    Baudrate = ledanalyserinfo.at(0).toInt();
    Modulea->ui->comboBox_36->setCurrentText(ledanalyserinfo.at(3));
    Logger->displayLog("N","set ledanalyser info is " + Moduleb->ui->comboBox_28->currentText(),"Ledanalyserinfo function run completed");
}

/*  pass in the correct parameters;*/

void LedAnalyserBox::enableLedAnalyserFunction()
{
    Titlelable.at(0)->setEnabled(true);
    Titlelable.at(1)->setEnabled(!Rgbbool);
    Titlelable.at(2)->setEnabled(true);
    Titlelable.at(3)->setEnabled(Rgbbool);
    for(int i = 0;i<Channels;i++)
    {
        Checkbox.at(1 * i + 0)->setEnabled(true);
        Checkbox.at(1 * i + 0)->setChecked(true);
        Valuelabel.at(3 * i + 0)->setEnabled(!Rgbbool);
        Valuelabel.at(3 * i + 1)->setEnabled(true);
        Valuelabel.at(3 * i + 2)->setEnabled(Rgbbool);
    }
}

/*  enable widget by ledanalyser info;*/

void LedAnalyserBox::getSerialPort()
{
    Serial->getSerialPort(&Serialnamelist,Modulea->ui->comboBox_26);
    Serial->enableSerialComboBox(&Serialnamelist,Modulea->ui->comboBox_26,Modulea->ui->comboBox_26);
    enableConnectButton();
    if(Modulea->ui->comboBox_26->currentText().isEmpty())
    {
        Logger->displayLog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_26->count();i++)
        {
            Logger->displayLog("N",Modulea->ui->comboBox_26->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

void LedAnalyserBox::connectSerialPort()
{
    QWidgetList connectwidgetet = {Modulea->ui->comboBox_27,Modulea->ui->comboBox_30,Modulea->ui->pushButton_92,Modulea->ui->pushButton_94,Modulea->ui->radioButton_3,Modulea->ui->radioButton_4};
    QWidgetList connectwidgetef = {Moduleb->ui->comboBox_28,Modulea->ui->pushButton_89,Modulea->ui->pushButton_90,Modulea->ui->pushButton_91,Modulea->ui->comboBox_26};
    Serial->connectSerialPort(Serialport,Serialnamelist[Modulea->ui->comboBox_26->currentIndex()],Modulea->ui->comboBox_36->currentText().toInt());
    if(Serialport->isOpen())
    {
        enableLedAnalyserFunction();
        for(int i = 0;i < connectwidgetet.count();i++)
        {
            connectwidgetet.at(i)->setEnabled(true);
        }
        for(int i = 0;i < connectwidgetef.count();i++)
        {
            connectwidgetef.at(i)->setEnabled(false);
        }
        Timerca->start();
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_26->currentText() + " and set baudrate as " + Modulea->ui->comboBox_36->currentText() + " success",
                   "Connectserialport function run completed");
    }
    else
    {
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_26->currentText() + " and set baudrate as " + Modulea->ui->comboBox_36->currentText() + " failed",
                   "Connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for read data and check connected device;*/

void LedAnalyserBox::disconnectSerialPort()
{
    Serialport->close();
    QWidgetList disconnectwidgetet = {Moduleb->ui->comboBox_28,Modulea->ui->pushButton_89,Modulea->ui->pushButton_90,Modulea->ui->pushButton_91,Modulea->ui->comboBox_26};
    QWidgetList disconnectwidgetef = {Modulea->ui->comboBox_27,Modulea->ui->comboBox_30,Modulea->ui->pushButton_92,Modulea->ui->pushButton_94,Modulea->ui->radioButton_3,Modulea->ui->radioButton_4};
    if(!Serialport->isOpen())
    {
        for(int i = 0;i < disconnectwidgetef.count();i++)
        {
            disconnectwidgetef.at(i)->setEnabled(false);
        }
        for(int i = 0;i < disconnectwidgetet.count();i++)
        {
            disconnectwidgetet.at(i)->setEnabled(true);
        }
        Modulea->ui->radioButton_4->setChecked(true);
        resetFunction();
        Timerca->stop();
        Logger->displayLog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui*/;

bool LedAnalyserBox::enableConnectButton()
{
    if(Moduleb->ui->comboBox_28->currentText().contains("select led analyser model"))
    {
        Modulea->ui->pushButton_89->setEnabled(false);
        Logger->displayLog("N","disable connect button ,select led analyser model","Enableconnectbutton function run completed");
        return false;
    }
    if(Serial->enableConnectButton(Modulea->ui->comboBox_26,Modulea->ui->comboBox_36,Modulea->ui->pushButton_89))
    {
        Logger->displayLog("N","enable connect button success","Enableconnectbutton function run completed");
        return true;
    }
    return false;
}

/*  check is enable connect button;*/;

void LedAnalyserBox::enableScanPortButton()
{
    if(!Moduleb->ui->comboBox_28->currentText().contains("select led analyser model") && !Modulea->ui->pushButton_92->isEnabled())
    {
        Modulea->ui->pushButton_91->setEnabled(true);
        Logger->displayLog("N","enable scan serial button success","Enablescanportbutton function run completed");
    }
    else
    {
        Modulea->ui->pushButton_91->setEnabled(false);
        Logger->displayLog("N","disable scan serial button","Enablescanportbutton function run completed");
    }
}

/*  check is enable scan serial port button*/;

void LedAnalyserBox::enablePwm()
{
    if(Modulea->ui->radioButton_3->isChecked())
    {
        Modulea->ui->comboBox_29->setEnabled(true);
        Logger->displayLog("N","pwm mode is enabled","enablepwm function run completed");
    }
    else
    {
        Modulea->ui->comboBox_29->setEnabled(false);
        Logger->displayLog("N","pwm mode is disabled","enablepwm function run completed");
    }
}

/*  is enable pwm level combobox;*/

void LedAnalyserBox::startDisplayValue()
{
    QString strcommand = setCommandLineEdit();
    if(!strcommand.isEmpty())
    {
        Modulea->ui->pushButton_94->setText("Value Displaying...");
        Modulea->ui->pushButton_94->setEnabled(false);
        Modulea->ui->comboBox_30->setEnabled(false);
        for(int i = 0;i<Channels;i++)
        {
            Checkbox.at(i)->setEnabled(false);
        }
        double timeout = (6 - Modulea->ui->comboBox_27->currentIndex() + Modulea->ui->comboBox_29->currentIndex()) * 1000;
        Serial->writeSerial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serialport,Modulea->ui->lineEdit_52);
        Logger->displayLog("W",strcommand,"ledAnalyserCommandApi function run completed");
        Threadtb = new SuperSerialThread(Serialport,timeout);
        connect(Threadtb,&SuperSerialThread::signalTt,this,     &LedAnalyserBox::signalTtbSlot);
        connect(Threadtb,&SuperSerialThread::signalTf,this,     &LedAnalyserBox::signalTfbSlot);
        connect(Threadtb,&SuperSerialThread::finished,Threadtb, &QObject::deleteLater);
        Threadtb->start();
    }
}

/*  start capture led info and analysis info;*/

QString LedAnalyserBox::setCommandLineEdit()
{
    QString strcommand = "";
    if(Modulea->ui->comboBox_27->currentIndex() != 0 && Modulea->ui->radioButton_3->isChecked() && Modulea->ui->comboBox_29->currentIndex() != 0)
    {
        strcommand = "capture" + QString::number(Modulea->ui->comboBox_27->currentIndex()) + "pwm" + Modulea->ui->comboBox_29->currentText().split(" - ").at(1);
    }
    else if(Modulea->ui->comboBox_27->currentIndex() != 0 && Modulea->ui->radioButton_3->isChecked() && Modulea->ui->comboBox_29->currentIndex() == 0)
    {
        Logger->displayLog("N","select correct pwm level","Setcommandlineedit function run completed");
    }
    else if(Modulea->ui->comboBox_27->currentIndex() != 0 && !Modulea->ui->radioButton_3->isChecked())
    {
        strcommand = "capture" + QString::number(Modulea->ui->comboBox_27->currentIndex());
    }
    else if(Modulea->ui->comboBox_27->currentIndex() == 0)
    {
        Logger->displayLog("N","select correct range level","Setcommandlineedit function run completed");
    }
    Modulea->ui->lineEdit_52->setText(strcommand);
    return strcommand;
}

/*  set command lineedit string command and return command;*/

void LedAnalyserBox::stopDisplayValue()
{
    Threadaa = nullptr;
    Modulea->ui->pushButton_94->setText("Start Display Value");
    Modulea->ui->pushButton_94->setEnabled(true);
    Modulea->ui->comboBox_30->setEnabled(true);
    for(int i = 0;i<Channels;i++)
    {
        Checkbox.at(i)->setEnabled(true);
    }
}

/*  receive readblock signal and enable widget;*/

void LedAnalyserBox::systemCommand()
{
    if(Modulea->ui->comboBox_30->currentText() == "select led command")
    {
        Logger->displayLog("N","selcet led analyser system command","Systemcommand function run completed");
    }
    else
    {
        QString command = Systemcommandlist[Modulea->ui->comboBox_30->currentIndex()];
        ledAnalyserCommandApi(command);
    }
}

/*  select combobox and run system command;*/

void LedAnalyserBox::ledAnalyserCommandApi(QString strcommand)
{
    double timeout = (6 - Modulea->ui->comboBox_27->currentIndex() + Modulea->ui->comboBox_29->currentIndex()) * 1000;
    Modulea->ui->lineEdit_52->setText(strcommand);
    Modulea->ui->comboBox_30->setEnabled(false);
    Modulea->ui->pushButton_94->setEnabled(false);
    Serial->writeSerial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serialport,Modulea->ui->lineEdit_52);
    Logger->displayLog("W",strcommand,"ledAnalyserCommandApi function run completed");
    Threadta = new SuperSerialThread(Serialport,timeout);
    connect(Threadta,&SuperSerialThread::signalTt,this,     &LedAnalyserBox::signalTtaSlot);
    connect(Threadta,&SuperSerialThread::signalTf,this,     &LedAnalyserBox::signalTfaSlot);
    connect(Threadta,&SuperSerialThread::finished,Threadta, &QObject::deleteLater);
    Threadta->start();
}

/*  system command api;*/

void LedAnalyserBox::timerCaSlot()
{
    if(Serial->checkSerialDevice(Serialport,Modulea->ui->comboBox_26->currentText()) == false)
    {
        disconnectSerialPort();
        getSerialPort();
        Logger->displayLog("N","serial port has been removed","checkconnect function run completed");
        enableConnectButton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void LedAnalyserBox::signalTtaSlot()
{
    Threadta = nullptr;
    Modulea->ui->comboBox_30->setEnabled(true);
    Modulea->ui->pushButton_94->setEnabled(true);
    Modulea->ui->pushButton_94->setText("Start Display Value");
    Logger->displayLog("R",Serial->readDataStream(Serialport,Modulea->ui->checkBox_33),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void LedAnalyserBox::signalTfaSlot()
{
    Threadta = nullptr;
    Modulea->ui->comboBox_30->setEnabled(true);
    Modulea->ui->pushButton_94->setEnabled(true);
    Modulea->ui->pushButton_94->setText("Start Display Value");
    Logger->displayLog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false result from signal;*/

void LedAnalyserBox::signalTtbSlot()
{
    Threadtb = nullptr;
    QString Backvaluetempb = Serial->readDataStream(Serialport,Modulea->ui->checkBox_33);
    Logger->displayLog("R",Backvaluetempb,"Signalraslot function run completed");
    resetLabelValue();
    double timeout = 1000;
    Channellist = checkBoxEnabled();
    Threadaa = new Analysisled(Serialport,timeout,Modulea->ui->checkBox_33,&Channellist);
    connect(Threadaa,&Analysisled::signalAa,this,&LedAnalyserBox::signalAaSlot);
    connect(Threadaa,&Analysisled::signalAb,this,&LedAnalyserBox::signalAbSlot);
    connect(Threadaa,&Analysisled::signalAc,this,&LedAnalyserBox::stopDisplayValue);
    connect(Threadaa,&Analysisled::finished,Threadaa,&QObject::deleteLater);
    Threadaa->start();
}

/*  receive capture result and start channel value threads;*/

void LedAnalyserBox::signalTfbSlot()
{
    Threadtb = nullptr;
    stopDisplayValue();
    Logger->displayLog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false result from signal;*/

QStringList LedAnalyserBox::checkBoxEnabled()
{
    QStringList temp = {};
    for(int i = 0;i<Channels;i++)
    {
        if(Checkbox.at(i)->isChecked())
        {
            temp.append(QString::number(i));
        }
    }
    return temp;
}

/*  return checked checkbox index;*/

void LedAnalyserBox::resetLabelValue()
{
    for(int i = 0;i<Channels;i++)
    {
        Valuelabel.at(i * 3 + 0)->setText("");
        Valuelabel.at(i * 3 + 1)->setText("");
        Valuelabel.at(i * 3 + 2)->setText("");
    }
}

/*  reset all label value;*/

void LedAnalyserBox::signalAaSlot(int counts)
{
    QString strcommand = Command + Channelrule[counts];
    Modulea->ui->lineEdit_52->setText(strcommand);
    Serial->writeSerial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serialport,Modulea->ui->lineEdit_52);
    Logger->displayLog("W",strcommand,"Signalaaslot function run completed");
}

/*  receive readblock signal and enable pushbutton;*/

void LedAnalyserBox::signalAbSlot(int counts)
{
    QString Result;
    QStringList Valuelist;
    Result = Serial->readDataStream(Serialport,Modulea->ui->checkBox_33);
    if(!Result.contains("serial port receive time out") && Result.contains("\r\n"))
    {
        Valuelist = processResult(Result);
        Valuelabel.at(counts * 3 + Index[0])->setText(Valuelist.at(0));
        Valuelabel.at(counts * 3 + Index[1])->setText(Valuelist.at(1));
    }
    Logger->displayLog("R",Result,"Signalraslot function run completed");
}

/*  receive readblock signal and enable pushbutton;*/

QStringList LedAnalyserBox::processResult(QString strresult)
{
    QStringList tempa;
    QStringList tempb = {"",""};
    if(Rgbbool)
    {
        tempa = strresult.split("\r\n")[0].split(" ");
        if(tempa.count() == 4)
        {
            tempb[0] = "red:" + tempa[0] + "  green:" + tempa.at(1) + "  blue:" + tempa.at(2);
            tempb[1] = tempa.at(3);
        }
    }
    else
    {
        tempa = strresult.split("\r\n")[0].split(" ");
        if(tempa.count() == 2)
        {
            tempb[0] = tempa.at(0);
            tempb[1] = tempa.at(1);
        }
    }
    return tempb;
}

/*  return result list;*/

void LedAnalyserBox::scanLedPort()
{
    QString Backvaluea = Core->firstWordUpper(Model);
    Modulea->ui->pushButton_91->setEnabled(false);
    Threadsa = new SuperScanSerial(this,Serialport,Baudrate,"getHW","capture5pwm01",Modulea->ui->checkBox_33,Modulea->ui->lineEdit_52,Backvaluea,"OK");
    connect(Threadsa,&SuperScanSerial::signalSa,Logger,  &SuperLogger::displayLog);
    connect(Threadsa,&SuperScanSerial::signalSb,this,    &LedAnalyserBox::signalSbSlot);
    connect(Threadsa,&SuperScanSerial::signalSc,this,    &LedAnalyserBox::signalScSlot);
    connect(Threadsa,&SuperScanSerial::finished,Threadsa,&QObject::deleteLater);
    Threadsa->start();
}

/*  start scan relay port;*/

void LedAnalyserBox::signalSbSlot(QString strcommand)
{
    Modulea->ui->lineEdit_52->setText(strcommand);
    Serial->writeSerial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serialport,Modulea->ui->lineEdit_52);
}

/*  set command lineedit strcommand and write to serial port;*/

void LedAnalyserBox::signalScSlot()
{
    Threadsa = nullptr;
    Modulea->ui->pushButton_91->setEnabled(true);
}

/*  enable pushbutton;*/

Analysisled::Analysisled(QSerialPort* serial,double timeout,QCheckBox* checkboxstring,QStringList *channellist)
{
    Serialport = serial;
    Timeout = timeout;
    Checkboxstring = checkboxstring;
    Channellist = channellist;
}

void Analysisled::run()
{
    for(int i = 0;i < Channellist->count();i++)
    {
        BytesAvailable = 0;
        emit signalAa(Channellist->at(i).toInt());
        while(Inittime < Timeout)
        {
            QThread::msleep(50);
            Serialport->waitForReadyRead(1);
            Inittime = Inittime + 50;
            int bytesAvailable = Serialport->bytesAvailable();
            if(BytesAvailable != bytesAvailable && bytesAvailable != 0)
            {
                BytesAvailable = bytesAvailable;
            }
            else if(BytesAvailable == bytesAvailable && BytesAvailable != 0)
            {
                emit signalAb(Channellist->at(i).toInt());
                Inittime = 0;
                break;
            }
            else if(Inittime >= Timeout)
            {
                emit signalAd();
                Inittime = 0;
                break;
            }
        }
    }
    emit signalAc();
}

