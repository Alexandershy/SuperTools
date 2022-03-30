#include "_ledanalyserbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new LedAnalyserBox();
}

/*  return class ledanalyserbox new instance pointer;*/

LedAnalyserBox::LedAnalyserBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("LedAnalyserBox");
    Setgroupbox(2,1);
    Setstretch({1,99},{100});
    Init();
}

LedAnalyserBox::~LedAnalyserBox()
{
    SuperS->Closeserial(Serial);
    SuperC->Closethread(Threadaa);
    SuperC->Closethread(Threadsa);
    SuperC->Closethread(Threadta);;
}

void LedAnalyserBox::Init()
{
    Objectinit();
    Timerinit();
    Widgetlistinit();
}

void LedAnalyserBox::Objectinit()
{
    SuperS = new SuperSerial(this);
    Serial  = new QSerialPort(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ModuleB(this,Rightgroupboxlist.at(0)->Insidelayout);
    Logger = new SuperLogger(this,Leftgroupboxlist.at(1)->Insidelayout);
    connect(Modulea->ui->comboBox_26,    &QComboBox::textActivated,  this,   &LedAnalyserBox::Enableconnectbutton);
    connect(Modulea->ui->comboBox_30,    &QComboBox::textActivated,  this,   &LedAnalyserBox::Systemcommand);
    connect(Modulea->ui->pushButton_89,  &QPushButton::clicked,      this,   &LedAnalyserBox::Connectserialport);
    connect(Modulea->ui->pushButton_90,  &QPushButton::clicked,      this,   &LedAnalyserBox::Getserialport);
    connect(Modulea->ui->pushButton_91,  &QPushButton::clicked,      this,   &LedAnalyserBox::Scanledport);
    connect(Modulea->ui->pushButton_92,  &QPushButton::clicked,      this,   &LedAnalyserBox::Disconnectserialport);
    connect(Modulea->ui->pushButton_94,  &QPushButton::clicked,      this,   &LedAnalyserBox::Startdisplayvalue);
    connect(Modulea->ui->radioButton_3,  &QRadioButton::toggled,     this,   &LedAnalyserBox::Enablepwm);
    connect(Modulea->ui->radioButton_4,  &QRadioButton::toggled,     this,   &LedAnalyserBox::Enablepwm);
    connect(Moduleb->ui->comboBox_28,    &QComboBox::textActivated,  this,   &LedAnalyserBox::Selectledanalyserinfo);
}

void LedAnalyserBox::Timerinit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&LedAnalyserBox::Timercaslot);
}

void LedAnalyserBox::Widgetlistinit()
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

void LedAnalyserBox::Selectledanalyserinfo()
{
    if(Moduleb->ui->comboBox_28->currentText() == "select led analyser model")
    {
        Resetfunction();
    }
    else
    {
        Resetfunction();
        Ledanalyserinfo();
    }
    Enableconnectbutton();
    Enablescanportbutton();
}

/*  select led analyser info;*/

void LedAnalyserBox::Resetfunction()
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

void LedAnalyserBox::Ledanalyserinfo()
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
    Logger->Displaylog("N","set ledanalyser info is " + Moduleb->ui->comboBox_28->currentText(),"Ledanalyserinfo function run completed");
}

/*  pass in the correct parameters;*/

void LedAnalyserBox::Enableledanalyserfunction()
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

void LedAnalyserBox::Getserialport()
{
    SuperS->Getserialport(&Serialnamelist,Modulea->ui->comboBox_26);
    SuperS->Enableserialcombobox(&Serialnamelist,Modulea->ui->comboBox_26,Modulea->ui->comboBox_26);
    Enableconnectbutton();
    if(Modulea->ui->comboBox_26->currentText().isEmpty())
    {
        Logger->Displaylog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_26->count();i++)
        {
            Logger->Displaylog("N",Modulea->ui->comboBox_26->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

void LedAnalyserBox::Connectserialport()
{
    QWidgetList connectwidgetet = {Modulea->ui->comboBox_27,Modulea->ui->comboBox_30,Modulea->ui->pushButton_92,Modulea->ui->pushButton_94,Modulea->ui->radioButton_3,Modulea->ui->radioButton_4};
    QWidgetList connectwidgetef = {Moduleb->ui->comboBox_28,Modulea->ui->pushButton_89,Modulea->ui->pushButton_90,Modulea->ui->pushButton_91,Modulea->ui->comboBox_26};
    SuperS->Connectserialport(Serial,Serialnamelist[Modulea->ui->comboBox_26->currentIndex()],Modulea->ui->comboBox_36->currentText().toInt());
    if(Serial->isOpen())
    {
        Enableledanalyserfunction();
        for(int i = 0;i < connectwidgetet.count();i++)
        {
            connectwidgetet.at(i)->setEnabled(true);
        }
        for(int i = 0;i < connectwidgetef.count();i++)
        {
            connectwidgetef.at(i)->setEnabled(false);
        }
        Timerca->start();
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_26->currentText() + " and set baudrate as " + Modulea->ui->comboBox_36->currentText() + " success",
                   "Connectserialport function run completed");
    }
    else
    {
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_26->currentText() + " and set baudrate as " + Modulea->ui->comboBox_36->currentText() + " failed",
                   "Connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for read data and check connected device;*/

void LedAnalyserBox::Disconnectserialport()
{
    Serial->close();
    QWidgetList disconnectwidgetet = {Moduleb->ui->comboBox_28,Modulea->ui->pushButton_89,Modulea->ui->pushButton_90,Modulea->ui->pushButton_91,Modulea->ui->comboBox_26};
    QWidgetList disconnectwidgetef = {Modulea->ui->comboBox_27,Modulea->ui->comboBox_30,Modulea->ui->pushButton_92,Modulea->ui->pushButton_94,Modulea->ui->radioButton_3,Modulea->ui->radioButton_4};
    if(!Serial->isOpen())
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
        Resetfunction();
        Timerca->stop();
        Logger->Displaylog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui*/;

bool LedAnalyserBox::Enableconnectbutton()
{
    if(Moduleb->ui->comboBox_28->currentText().contains("select led analyser model"))
    {
        Modulea->ui->pushButton_89->setEnabled(false);
        Logger->Displaylog("N","disable connect button ,select led analyser model","Enableconnectbutton function run completed");
        return false;
    }
    if(SuperS->Enableconnectbutton(Modulea->ui->comboBox_26,Modulea->ui->comboBox_36,Modulea->ui->pushButton_89))
    {
        Logger->Displaylog("N","enable connect button success","Enableconnectbutton function run completed");
        return true;
    }
    return false;
}

/*  check is enable connect button;*/;

void LedAnalyserBox::Enablescanportbutton()
{
    if(!Moduleb->ui->comboBox_28->currentText().contains("select led analyser model") && !Modulea->ui->pushButton_92->isEnabled())
    {
        Modulea->ui->pushButton_91->setEnabled(true);
        Logger->Displaylog("N","enable scan serial button success","Enablescanportbutton function run completed");
    }
    else
    {
        Modulea->ui->pushButton_91->setEnabled(false);
        Logger->Displaylog("N","disable scan serial button","Enablescanportbutton function run completed");
    }
}

/*  check is enable scan serial port button*/;

void LedAnalyserBox::Enablepwm()
{
    if(Modulea->ui->radioButton_3->isChecked())
    {
        Modulea->ui->comboBox_29->setEnabled(true);
        Logger->Displaylog("N","pwm mode is enabled","enablepwm function run completed");
    }
    else
    {
        Modulea->ui->comboBox_29->setEnabled(false);
        Logger->Displaylog("N","pwm mode is disabled","enablepwm function run completed");
    }
}

/*  is enable pwm level combobox;*/

void LedAnalyserBox::Startdisplayvalue()
{
    QString strcommand = Setcommandlineedit();
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
        SuperS->Writeserial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serial,Modulea->ui->lineEdit_52);
        Logger->Displaylog("W",strcommand,"ledanalysercommandapi function run completed");
        Threadtb = new SerialThread(Serial,timeout);
        connect(Threadtb,&SerialThread::Signaltt,this,     &LedAnalyserBox::Signalttbslot);
        connect(Threadtb,&SerialThread::Signaltf,this,     &LedAnalyserBox::Signaltfbslot);
        connect(Threadtb,&SerialThread::finished,Threadtb, &QObject::deleteLater);
        Threadtb->start();
    }
}

/*  start capture led info and analysis info;*/

QString LedAnalyserBox::Setcommandlineedit()
{
    QString strcommand = "";
    if(Modulea->ui->comboBox_27->currentIndex() != 0 && Modulea->ui->radioButton_3->isChecked() && Modulea->ui->comboBox_29->currentIndex() != 0)
    {
        strcommand = "capture" + QString::number(Modulea->ui->comboBox_27->currentIndex()) + "pwm" + Modulea->ui->comboBox_29->currentText().split(" - ").at(1);
    }
    else if(Modulea->ui->comboBox_27->currentIndex() != 0 && Modulea->ui->radioButton_3->isChecked() && Modulea->ui->comboBox_29->currentIndex() == 0)
    {
        Logger->Displaylog("N","select correct pwm level","Setcommandlineedit function run completed");
    }
    else if(Modulea->ui->comboBox_27->currentIndex() != 0 && !Modulea->ui->radioButton_3->isChecked())
    {
        strcommand = "capture" + QString::number(Modulea->ui->comboBox_27->currentIndex());
    }
    else if(Modulea->ui->comboBox_27->currentIndex() == 0)
    {
        Logger->Displaylog("N","select correct range level","Setcommandlineedit function run completed");
    }
    Modulea->ui->lineEdit_52->setText(strcommand);
    return strcommand;
}

/*  set command lineedit string command and return command;*/

void LedAnalyserBox::Stopdisplayvalue()
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

void LedAnalyserBox::Systemcommand()
{
    if(Modulea->ui->comboBox_30->currentText() == "select led command")
    {
        Logger->Displaylog("N","selcet led analyser system command","Systemcommand function run completed");
    }
    else
    {
        QString command = Systemcommandlist[Modulea->ui->comboBox_30->currentIndex()];
        ledanalysercommandapi(command);
    }
}

/*  select combobox and run system command;*/

void LedAnalyserBox::ledanalysercommandapi(QString strcommand)
{
    double timeout = (6 - Modulea->ui->comboBox_27->currentIndex() + Modulea->ui->comboBox_29->currentIndex()) * 1000;
    Modulea->ui->lineEdit_52->setText(strcommand);
    Modulea->ui->comboBox_30->setEnabled(false);
    Modulea->ui->pushButton_94->setEnabled(false);
    SuperS->Writeserial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serial,Modulea->ui->lineEdit_52);
    Logger->Displaylog("W",strcommand,"ledanalysercommandapi function run completed");
    Threadta = new SerialThread(Serial,timeout);
    connect(Threadta,&SerialThread::Signaltt,this,     &LedAnalyserBox::Signalttaslot);
    connect(Threadta,&SerialThread::Signaltf,this,     &LedAnalyserBox::Signaltfaslot);
    connect(Threadta,&SerialThread::finished,Threadta, &QObject::deleteLater);
    Threadta->start();
}

/*  system command api;*/

void LedAnalyserBox::Timercaslot()
{
    if(SuperS->Checkserialdevice(Serial,Modulea->ui->comboBox_26->currentText()) == false)
    {
        Disconnectserialport();
        Getserialport();
        Logger->Displaylog("N","serial port has been removed","checkconnect function run completed");
        Enableconnectbutton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void LedAnalyserBox::Signalttaslot()
{
    Threadta = nullptr;
    Modulea->ui->comboBox_30->setEnabled(true);
    Modulea->ui->pushButton_94->setEnabled(true);
    Modulea->ui->pushButton_94->setText("Start Display Value");
    Logger->Displaylog("R",SuperS->Readdatastream(Serial,Modulea->ui->checkBox_33),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void LedAnalyserBox::Signaltfaslot()
{
    Threadta = nullptr;
    Modulea->ui->comboBox_30->setEnabled(true);
    Modulea->ui->pushButton_94->setEnabled(true);
    Modulea->ui->pushButton_94->setText("Start Display Value");
    Logger->Displaylog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false result from signal;*/

void LedAnalyserBox::Signalttbslot()
{
    Threadtb = nullptr;
    QString Backvaluetempb = SuperS->Readdatastream(Serial,Modulea->ui->checkBox_33);
    Logger->Displaylog("R",Backvaluetempb,"Signalraslot function run completed");
    Resetlabelvalue();
    double timeout = 1000;
    Channellist = Checkboxenabled();
    Threadaa = new Analysisled(Serial,timeout,Modulea->ui->checkBox_33,&Channellist);
    connect(Threadaa,&Analysisled::Signalaa,this,&LedAnalyserBox::Signalaaslot);
    connect(Threadaa,&Analysisled::Signalab,this,&LedAnalyserBox::Signalabslot);
    connect(Threadaa,&Analysisled::Signalac,this,&LedAnalyserBox::Stopdisplayvalue);
    connect(Threadaa,&Analysisled::finished,Threadaa,&QObject::deleteLater);
    Threadaa->start();
}

/*  receive capture result and start channel value threads;*/

void LedAnalyserBox::Signaltfbslot()
{
    Threadtb = nullptr;
    Stopdisplayvalue();
    Logger->Displaylog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false result from signal;*/

QStringList LedAnalyserBox::Checkboxenabled()
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

void LedAnalyserBox::Resetlabelvalue()
{
    for(int i = 0;i<Channels;i++)
    {
        Valuelabel.at(i * 3 + 0)->setText("");
        Valuelabel.at(i * 3 + 1)->setText("");
        Valuelabel.at(i * 3 + 2)->setText("");
    }
}

/*  reset all label value;*/

void LedAnalyserBox::Signalaaslot(int counts)
{
    QString strcommand = Command + Channelrule[counts];
    Modulea->ui->lineEdit_52->setText(strcommand);
    SuperS->Writeserial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serial,Modulea->ui->lineEdit_52);
    Logger->Displaylog("W",strcommand,"Signalaaslot function run completed");
}

/*  receive readblock signal and enable pushbutton;*/

void LedAnalyserBox::Signalabslot(int counts)
{
    QString Result;
    QStringList Valuelist;
    Result = SuperS->Readdatastream(Serial,Modulea->ui->checkBox_33);
    if(!Result.contains("serial port receive time out") && Result.contains("\r\n"))
    {
        Valuelist = Processresult(Result);
        Valuelabel.at(counts * 3 + Index[0])->setText(Valuelist.at(0));
        Valuelabel.at(counts * 3 + Index[1])->setText(Valuelist.at(1));
    }
    Logger->Displaylog("R",Result,"Signalraslot function run completed");
}

/*  receive readblock signal and enable pushbutton;*/

QStringList LedAnalyserBox::Processresult(QString strresult)
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

void LedAnalyserBox::Scanledport()
{
    QString Backvaluea = SuperC->Firstwordupper(Model);
    Modulea->ui->pushButton_91->setEnabled(false);
    Threadsa = new ScanSerialPort(this,Serial,Baudrate,"getHW","capture5pwm01",Modulea->ui->checkBox_33,Modulea->ui->lineEdit_52,Backvaluea,"OK");
    connect(Threadsa,&ScanSerialPort::Signalsa,Logger,  &SuperLogger::Displaylog);
    connect(Threadsa,&ScanSerialPort::Signalsb,this,    &LedAnalyserBox::Signalsbslot);
    connect(Threadsa,&ScanSerialPort::Signalsc,this,    &LedAnalyserBox::Signalscslot);
    connect(Threadsa,&ScanSerialPort::finished,Threadsa,&QObject::deleteLater);
    Threadsa->start();
}

/*  start scan relay port;*/

void LedAnalyserBox::Signalsbslot(QString strcommand)
{
    Modulea->ui->lineEdit_52->setText(strcommand);
    SuperS->Writeserial(Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Modulea->ui->checkBox_33,Serial,Modulea->ui->lineEdit_52);
}

/*  set command lineedit strcommand and write to serial port;*/

void LedAnalyserBox::Signalscslot()
{
    Threadsa = nullptr;
    Modulea->ui->pushButton_91->setEnabled(true);
}

/*  enable pushbutton;*/

Analysisled::Analysisled(QSerialPort* serial,double timeout,QCheckBox* checkboxstring,QStringList *channellist)
{
    Serial = serial;
    Timeout = timeout;
    Checkboxstring = checkboxstring;
    Channellist = channellist;
}

void Analysisled::run()
{
    for(int i = 0;i < Channellist->count();i++)
    {
        BytesAvailable = 0;
        emit Signalaa(Channellist->at(i).toInt());
        while(Inittime < Timeout)
        {
            QThread::msleep(50);
            Serial->waitForReadyRead(1);
            Inittime = Inittime + 50;
            int bytesAvailable = Serial->bytesAvailable();
            if(BytesAvailable != bytesAvailable && bytesAvailable != 0)
            {
                BytesAvailable = bytesAvailable;
            }
            else if(BytesAvailable == bytesAvailable && BytesAvailable != 0)
            {
                emit Signalab(Channellist->at(i).toInt());
                Inittime = 0;
                break;
            }
            else if(Inittime >= Timeout)
            {
                emit Signalad();
                Inittime = 0;
                break;
            }
        }
    }
    emit Signalac();
}

