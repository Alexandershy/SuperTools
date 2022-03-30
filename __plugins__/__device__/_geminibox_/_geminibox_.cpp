#include "_geminibox_.h"

SuperTab* Interface::Loadplugin()
{
    return new GeminiBox();
}

/*  return class geminibox new instance pointer;*/

GeminiBox::GeminiBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("GeminiBox");
    Setgroupbox(2,1);
    Setstretch({1,99},{100});
    Init();
}

GeminiBox::~GeminiBox()
{
    SuperS->Closeserial(Serial);
    SuperC->Closethread(Threadsa);
    SuperC->Closethread(Threadta);
    SuperC->Closethread(Threadtb);
    SuperC->Closethread(Threadtc);
    SuperC->Closethread(Threadtd);
    SuperC->Closethread(Threadte);
}

void GeminiBox::Init()
{
    Objectinit();
    Timerinit();
    Widgetlistinit();
}

void GeminiBox::Objectinit()
{
    SuperS = new SuperSerial(this);
    Serial = new QSerialPort(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Threadsa = new ScanSerialPort(this,Serial,1000000,"help","version",Moduleb->ui->checkBox_30,Moduleb->ui->lineEdit_33,"Available commands:","+");
    connect(Threadsa,   &ScanSerialPort::Signalsa,  Logger, &SuperLogger::Displaylog);
    connect(Threadsa,   &ScanSerialPort::Signalsb,  this,   &GeminiBox::Signalsbslot);
    connect(Threadsa,   &ScanSerialPort::Signalsc,  this,   &GeminiBox::Signalscslot);
    connect(Modulea->ui->pushButton_51,  &QPushButton::clicked,          this,   &GeminiBox::Getserialport);
    connect(Modulea->ui->pushButton_54,  &QPushButton::clicked,          this,   &GeminiBox::Connectserialport);
    connect(Modulea->ui->pushButton_56,  &QPushButton::clicked,          this,   &GeminiBox::Scangeminiport);
    connect(Modulea->ui->comboBox_4,     &QComboBox::textActivated,      this,   &GeminiBox::Enableconnectbutton);
    connect(Modulea->ui->pushButton_55,  &QPushButton::clicked,          this,   &GeminiBox::Disconnectserialport);
    connect(Moduleb->ui->comboBox_5,     &QComboBox::currentTextChanged, this,   &GeminiBox::Enableruntxtest);
    connect(Moduleb->ui->comboBox_6,     &QComboBox::currentTextChanged, this,   &GeminiBox::Enableruntxtest);
    connect(Moduleb->ui->comboBox_7,     &QComboBox::currentTextChanged, this,   &GeminiBox::Enableruntxtest);
    connect(Moduleb->ui->comboBox_8,     &QComboBox::currentTextChanged, this,   &GeminiBox::Enableruntxtest);
    connect(Moduleb->ui->comboBox_9,     &QComboBox::currentTextChanged, this,   &GeminiBox::Enablestartrxtest);
    connect(Moduleb->ui->pushButton_46,  &QPushButton::clicked,          this,   &GeminiBox::Help);
    connect(Moduleb->ui->pushButton_47,  &QPushButton::clicked,          this,   &GeminiBox::Checkversion);
    connect(Moduleb->ui->pushButton_48,  &QPushButton::clicked,          this,   &GeminiBox::Runtxtest);
    connect(Moduleb->ui->pushButton_49,  &QPushButton::clicked,          this,   &GeminiBox::Startrxtest);
    connect(Moduleb->ui->pushButton_50,  &QPushButton::clicked,          this,   &GeminiBox::Endrxtest);
}

/*  object init;*/

void GeminiBox::Timerinit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&GeminiBox::Timercaslot);
}

/*  timer init;*/

void GeminiBox::Widgetlistinit()
{
    Connectwidgetet     = {Moduleb->ui->comboBox_5,Moduleb->ui->comboBox_6,Moduleb->ui->comboBox_7,Moduleb->ui->comboBox_8,Moduleb->ui->comboBox_9,Modulea->ui->pushButton_55,Moduleb->ui->pushButton_46,Moduleb->ui->pushButton_47,Moduleb->ui->lineEdit_17,Moduleb->ui->lineEdit_18,Moduleb->ui->lineEdit_19,Moduleb->ui->lineEdit_20,Moduleb->ui->lineEdit_21};
    Connectwidgetef     = {Modulea->ui->comboBox_4,Modulea->ui->pushButton_54,Modulea->ui->pushButton_56,Modulea->ui->pushButton_51};
    Disconnectwidgetet  = {Modulea->ui->comboBox_4,Modulea->ui->pushButton_54,Modulea->ui->pushButton_51,Modulea->ui->pushButton_56};
    Disconnectwidgetef  = {Moduleb->ui->comboBox_5,Moduleb->ui->comboBox_6,Moduleb->ui->comboBox_7,Moduleb->ui->comboBox_8,Moduleb->ui->comboBox_9,Modulea->ui->pushButton_55,Moduleb->ui->pushButton_46,Moduleb->ui->pushButton_47,Moduleb->ui->pushButton_48,Moduleb->ui->pushButton_49,Moduleb->ui->pushButton_50,Moduleb->ui->lineEdit_17,Moduleb->ui->lineEdit_18,Moduleb->ui->lineEdit_19,Moduleb->ui->lineEdit_20,Moduleb->ui->lineEdit_21};
}

/*  widget list init;*/

void GeminiBox::Getserialport()
{
    SuperS->Getserialport(&Serialnamelist,Modulea->ui->comboBox_4);
    SuperS->Enableserialcombobox(&Serialnamelist,Modulea->ui->comboBox_4,Modulea->ui->comboBox_4);
    SuperS->Enableconnectbutton(Modulea->ui->comboBox_4,Modulea->ui->comboBox_31,Modulea->ui->pushButton_54);
    if(Modulea->ui->comboBox_4->currentText().isEmpty())
    {
        Logger->Displaylog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_4->count();i++)
        {
            Logger->Displaylog("N",Modulea->ui->comboBox_4->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

void GeminiBox::Connectserialport()
{
    SuperS->Connectserialport(Serial,Serialnamelist[Modulea->ui->comboBox_4->currentIndex()],Modulea->ui->comboBox_31->currentText().toInt());
    if(Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Connectwidgetet,true);
        SuperC->Enablewidgetlist(&Connectwidgetef,false);
        Enableruntxtest();
        Enablestartrxtest();
        Timerca->start();
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_4->currentText() + " and set baudrate as " + Modulea->ui->comboBox_31->currentText() + " success","Connectserialport function run completed");
    }
    else
    {
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_4->currentText() + " and set baudrate as " + Modulea->ui->comboBox_31->currentText() + " failed","Connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for read data and check connected device;*/

void GeminiBox::Disconnectserialport()
{
    Serial->close();
    if(!Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Disconnectwidgetef,false);
        SuperC->Enablewidgetlist(&Disconnectwidgetet,true);
        Timerca->stop();
        Logger->Displaylog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui*/;

bool GeminiBox::Enableconnectbutton()
{
    return SuperS->Enableconnectbutton(Modulea->ui->comboBox_4,Modulea->ui->comboBox_31,Modulea->ui->pushButton_54);
}

/*  check is enable connect button;*/;

void GeminiBox::Geminicommand(QString strcommand)
{
    Moduleb->ui->lineEdit_33->setText(strcommand);
    SuperS->Writeserial(Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Serial,Moduleb->ui->lineEdit_33);
    Logger->Displaylog("W",strcommand,"Geminicommand function run completed");
}

/*  send and read command quick api;*/

void GeminiBox::Help()
{
    Moduleb->ui->pushButton_46->setEnabled(false);
    Geminicommand("help");
    Threadta = new SerialThread(Serial,1000);
    connect(Threadta,&SerialThread::Signaltt,this,     &GeminiBox::Signalttaslot);
    connect(Threadta,&SerialThread::Signaltf,this,     &GeminiBox::Signaltfaslot);
    connect(Threadta,&SerialThread::finished,Threadta, &QObject::deleteLater);
    Threadta->start();
}

/*  send and read help command;*/

void GeminiBox::Checkversion()
{
    Moduleb->ui->pushButton_47->setEnabled(false);
    Geminicommand("version");
    Threadtb = new SerialThread(Serial,1000);
    connect(Threadtb,&SerialThread::Signaltt,this,     &GeminiBox::Signalttbslot);
    connect(Threadtb,&SerialThread::Signaltf,this,     &GeminiBox::Signaltfbslot);
    connect(Threadtb,&SerialThread::finished,Threadtb, &QObject::deleteLater);
    Threadtb->start();
}

/*  send and read version command;*/

void GeminiBox::Runtxtest()
{
    QString Strcommand = "run_tx_test " + Moduleb->ui->comboBox_5->currentText() + " " + Moduleb->ui->comboBox_6->currentText() + " " + Moduleb->ui->comboBox_7->currentText() + " " + Moduleb->ui->comboBox_8->currentText();
    Moduleb->ui->pushButton_48->setEnabled(false);
    Moduleb->ui->pushButton_48->setText("Transmiting...");
    Moduleb->ui->lineEdit_33->setText(Strcommand);
    SuperS->Writeserial(Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Serial,Moduleb->ui->lineEdit_33);
    Logger->Displaylog("W",Strcommand,"Runtxtest function running...");
    Threadtc = new SerialThread(Serial,Moduleb->ui->comboBox_8->currentText().toInt() * 2);
    connect(Threadtc,&SerialThread::Signaltt,this,      &GeminiBox::Signalttcslot);
    connect(Threadtc,&SerialThread::Signaltf,this,      &GeminiBox::Signaltfcslot);
    connect(Threadtc,&SerialThread::finished,Threadtc,  &QObject::deleteLater);
    Threadtc->start();
}

/*  send and read run tx test command;*/

void GeminiBox::Startrxtest()
{
    Geminicommand("start_rx_test " + Moduleb->ui->comboBox_9->currentText());
    Threadtd = new SerialThread(Serial,1000);
    connect(Threadtd,&SerialThread::Signaltt,this,     &GeminiBox::Signalttdslot);
    connect(Threadtd,&SerialThread::Signaltf,this,     &GeminiBox::Signaltfdslot);
    connect(Threadtd,&SerialThread::finished,Threadtd, &QObject::deleteLater);
    Threadtd->start();
}

/*  send and read start rx test command;*/

void GeminiBox::Endrxtest()
{
    Geminicommand("end_rx_test");
    Threadte = new SerialThread(Serial,1000);
    connect(Threadte,&SerialThread::Signaltt,this,     &GeminiBox::Signaltteslot);
    connect(Threadte,&SerialThread::Signaltf,this,     &GeminiBox::Signaltfeslot);
    connect(Threadte,&SerialThread::finished,Threadte, &QObject::deleteLater);
    Threadte->start();
}

/*  send and read end rx test command and refresh ui;*/

void GeminiBox::Enableruntxtest()
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
        Logger->Displaylog("N","set frequency as " + Moduleb->ui->comboBox_5->currentText() + "(hz),power as " + Moduleb->ui->comboBox_6->currentText()  + "(dbm),length as " + Moduleb->ui->comboBox_7->currentText() + "(bits),number as " + Moduleb->ui->comboBox_8->currentText() + "(pkts)",
                   "Enableruntxtest function run completed");
    }
    else
    {
        Moduleb->ui->pushButton_48->setEnabled(false);
        Logger->Displaylog("N","please set parameter correctly!,set frequency as " + Moduleb->ui->comboBox_5->currentText() + "(hz),power as " + Moduleb->ui->comboBox_6->currentText()  + "(dbm),length as " + Moduleb->ui->comboBox_7->currentText() + "(bits),number as " + Moduleb->ui->comboBox_8->currentText() + "(pkts)",
                   "Enableruntxtest function run completed");
    }
}

/*  enable run tx test button or not;*/

void GeminiBox::Enablestartrxtest()
{
    bool boola = false;
    Moduleb->ui->comboBox_9->currentText().toInt(&boola);
    if(boola && !Moduleb->ui->pushButton_50->isEnabled())
    {
        Moduleb->ui->pushButton_49->setEnabled(true);
        Logger->Displaylog("N","set frequency as " + Moduleb->ui->comboBox_9->currentText() + "(hz)","Enablestartrxtest function run completed");
    }
    else
    {
        Moduleb->ui->pushButton_49->setEnabled(false);
        Logger->Displaylog("N","please set frequency correctly,set frequency as " + Moduleb->ui->comboBox_9->currentText() + "(hz)","Enablestartrxtest function run completed");
    }
}

/*  enable start rx test button or not;*/

void GeminiBox::Scangeminiport()
{
    Modulea->ui->pushButton_56->setEnabled(false);
    Threadsa->start();
}

/*  new thread for scan gemini port;*/

void GeminiBox::Signalsbslot(QString strcommand)
{
    Moduleb->ui->lineEdit_33->setText(strcommand);
    SuperS->Writeserial(Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Moduleb->ui->checkBox_30,Serial,Moduleb->ui->lineEdit_33);
}

/*  receive command and set to lineedit;*/

void GeminiBox::Signalscslot()
{
    Modulea->ui->pushButton_56->setEnabled(true);
}

/*  receive scan completed signal and enable pushbutton;*/

void GeminiBox::Timercaslot()
{
    if(SuperS->Checkserialdevice(Serial,Modulea->ui->comboBox_4->currentText()) == false)
    {
        Disconnectserialport();
        Getserialport();
        Logger->Displaylog("N","serial port has been removed","checkconnect function run completed");
        Enableconnectbutton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void GeminiBox::Signalttaslot()
{
    Threadta = nullptr;
    Moduleb->ui->pushButton_46->setEnabled(true);
    Logger->Displaylog("R",SuperS->Readdatastream(Serial,Moduleb->ui->checkBox_30),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::Signaltfaslot()
{
    Threadta = nullptr;
    Moduleb->ui->pushButton_46->setEnabled(true);
    Logger->Displaylog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::Signalttbslot()
{
    Threadtb = nullptr;
    Moduleb->ui->pushButton_47->setEnabled(true);
    Logger->Displaylog("R",SuperS->Readdatastream(Serial,Moduleb->ui->checkBox_30),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::Signaltfbslot()
{
    Threadtb = nullptr;
    Moduleb->ui->pushButton_47->setEnabled(true);
    Logger->Displaylog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::Signalttcslot()
{
    Threadtc = nullptr;
    Moduleb->ui->pushButton_48->setEnabled(true);
    Moduleb->ui->pushButton_48->setText("Run Tx Test");
    Logger->Displaylog("R",SuperS->Readdatastream(Serial,Moduleb->ui->checkBox_30),"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::Signaltfcslot()
{
    Threadtc = nullptr;
    Moduleb->ui->pushButton_48->setEnabled(true);
    Moduleb->ui->pushButton_48->setText("Run Tx Test");
    Logger->Displaylog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::Signalttdslot()
{
    Threadtd = nullptr;
    QString Result = SuperS->Readdatastream(Serial,Moduleb->ui->checkBox_30);
    Moduleb->ui->pushButton_48->setEnabled(false);
    Moduleb->ui->pushButton_49->setEnabled(false);
    Moduleb->ui->pushButton_49->setText("Receiving...");
    Moduleb->ui->pushButton_50->setEnabled(true);
    Logger->Displaylog("R",Result,"Signalraslot function run completed");
}

/*  receive true readblock signal;*/

void GeminiBox::Signaltfdslot()
{
    Threadtd = nullptr;
    Logger->Displaylog("R","serial port receive time out","Signalraslot function run completed");
}

/*  receive false readblock signal;*/

void GeminiBox::Signaltteslot()
{
    Threadte = nullptr;
    QString result = SuperS->Readdatastream(Serial,Moduleb->ui->checkBox_30);
    QStringList listtemp = result.split(",");
    Moduleb->ui->pushButton_50->setEnabled(false);
    Moduleb->ui->pushButton_49->setText("Start Rx Test");
    Enableruntxtest();
    Enablestartrxtest();
    Logger->Displaylog("R",result,"Signalraslot function run completed");
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

void GeminiBox::Signaltfeslot()
{
    Threadte = nullptr;
    Logger->Displaylog("R","serial port receive time out","Signaltfeslot function run completed");
}

/*  receive false readblock signal;*/
