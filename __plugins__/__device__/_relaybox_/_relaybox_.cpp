#include "_relaybox_.h"

SuperTab* Interface::Loadplugin()
{
    return new RelayBox();
}

/*  return class relaybox new instance pointer;*/

RelayBox::RelayBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("RelayBox");
    Setgroupbox(2,2);
    Setstretch({1,99},{1,99});
    Init();
}

RelayBox::~RelayBox()
{
    SuperS->Closeserial(Serial);
    SuperC->Closethread(Threadta);
    delete Channel15relay;
    delete Channel34relay;
}

void RelayBox::Init()
{
    Timerinit();
    Objectinit();
    Widgetlistinit();
}

void RelayBox::Timerinit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&RelayBox::Timercaslot);
}

void RelayBox::Objectinit()
{
    SuperS = new SuperSerial(this);
    Serial = new QSerialPort(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Logger = new SuperLogger(this,Leftgroupboxlist.at(1)->Insidelayout);
    Moduleb = new ModuleB(this,Rightgroupboxlist.at(0)->Insidelayout);
    Modulec = new ModuleC(this,Rightgroupboxlist.at(1)->Insidelayout);
    connect(Modulea->ui->pushButton_35,  &QPushButton::clicked,      this,   &RelayBox::Getserialport);
    connect(Modulea->ui->comboBox_1,     &QComboBox::textActivated,  this,   &RelayBox::Enableconnectbutton);
    connect(Modulea->ui->pushButton_31,  &QPushButton::clicked,      this,   &RelayBox::Connectserialport);
    connect(Modulea->ui->pushButton_32,  &QPushButton::clicked,      this,   &RelayBox::Disconnectserialport);
    connect(Modulea->ui->pushButton_33,  &QPushButton::clicked,      this,   &RelayBox::Resetallchannel);
    connect(Modulea->ui->pushButton_34,  &QPushButton::clicked,      this,   &RelayBox::Closeallchannel);
    connect(Modulea->ui->pushButton_45,  &QPushButton::clicked,      this,   &RelayBox::Openselectchannel);
    connect(Modulea->ui->pushButton_44,  &QPushButton::clicked,      this,   &RelayBox::Closeselectchannel);
    connect(Modulea->ui->pushButton_57,  &QPushButton::clicked,      this,   &RelayBox::Scanrelayport);
    connect(Moduleb->ui->comboBox_2,     &QComboBox::textActivated,  this,   &RelayBox::Selectrelaymodel);
    connect(Moduleb->ui->pushButton,     &QPushButton::clicked,      this,   &RelayBox::Selectsetting);
    connect(Moduleb->ui->lineEdit_16,    &QLineEdit::textChanged,    this,   &RelayBox::Setsetting);
    Channel15relay = new Channel15(this,Serial,Modulea->ui->checkBox_29,Modulea->ui->lineEdit);
    connect(Channel15relay,&Channel15::Signalca,Logger,&SuperLogger::Displaylog);
    connect(Channel15relay,&Channel15::Signalcb,this,&RelayBox::Signalsbslot);
    connect(Channel15relay,&Channel15::Signalcc,this,&RelayBox::Signalscslot);
    connect(Channel15relay,&Channel15::Signalcd,this,&RelayBox::Writecommand);
    connect(Channel15relay,&Channel15::Signalce,this,&RelayBox::Enablerelaybutton);
    Channel34relay = new Channel34(this,Serial,Modulea->ui->checkBox_29,Modulea->ui->lineEdit);
    connect(Channel34relay,&Channel34::Signalca,Logger,&SuperLogger::Displaylog);
    connect(Channel34relay,&Channel34::Signalcb,this,&RelayBox::Signalsbslot);
    connect(Channel34relay,&Channel34::Signalcc,this,&RelayBox::Signalscslot);
    connect(Channel34relay,&Channel34::Signalcd,this,&RelayBox::Writecommand);
    connect(Channel34relay,&Channel34::Signalce,this,&RelayBox::Enablerelaybutton);
    Threadta = new SerialThread(Serial,1000);
    connect(Threadta,&SerialThread::Signaltt,this,  &RelayBox::Readyreadslot);
    connect(Threadta,&SerialThread::Signaltf,this,  &RelayBox::Readtimeoutslot);
    Modulec->ui->verticalLayout_8->addWidget(Channel15relay);
    Modulec->ui->verticalLayout_8->addWidget(Channel34relay);
    Fileinfo = QFileInfo(Defaultsettingpath);
    Channel34relay->hide();
}

void RelayBox::Widgetlistinit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_32,Modulea->ui->pushButton_33,Modulea->ui->pushButton_34,Moduleb->ui->lineEdit_16,Moduleb->ui->pushButton};
    Disconnectwidgetef  = {Modulea->ui->pushButton_33,Modulea->ui->pushButton_34,Modulea->ui->pushButton_32,Modulea->ui->pushButton_44,Modulea->ui->pushButton_45,Moduleb->ui->lineEdit_16,Moduleb->ui->pushButton};
    Connectwidgetef     = {Modulea->ui->pushButton_31,Modulea->ui->pushButton_35,Modulea->ui->pushButton_57,Modulea->ui->comboBox_1,Moduleb->ui->comboBox_2};
    Disconnectwidgetet  = {Modulea->ui->pushButton_31,Modulea->ui->pushButton_35,Modulea->ui->pushButton_57,Modulea->ui->comboBox_1,Moduleb->ui->comboBox_2};
}

/*  widget list init;*/

void RelayBox::Getserialport()
{
    SuperS->Getserialport(&Serialnamelist,Modulea->ui->comboBox_1);
    SuperS->Enableserialcombobox(&Serialnamelist,Modulea->ui->comboBox_1,Modulea->ui->comboBox_1);
    Enableconnectbutton();
    if(Modulea->ui->comboBox_1->currentText().isEmpty())
    {
        Logger->Displaylog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_1->count();i++)
        {
            Logger->Displaylog("N",Modulea->ui->comboBox_1->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

bool RelayBox::Enableconnectbutton()
{
    if(!Moduleb->ui->comboBox_2->currentIndex())
    {
        Modulea->ui->pushButton_31->setEnabled(false);
        Logger->Displaylog("N","disable connect button ,select relay model","Enableconnectbutton function run completed");
        return false;
    }
    if(SuperS->Enableconnectbutton(Modulea->ui->comboBox_1,Modulea->ui->comboBox,Modulea->ui->pushButton_31))
    {
        Logger->Displaylog("N","enable connect button success","Enableconnectbutton function run completed");
        return true;
    }
    return false;
}

/*  check is enable connect button;*/;

void RelayBox::Enablescanportbutton()
{
    if(Moduleb->ui->comboBox_2->currentIndex() && !Modulea->ui->pushButton_32->isEnabled())
    {
        Modulea->ui->pushButton_57->setEnabled(true);
        Logger->Displaylog("N","enable scan serial button success","Enablescanportbutton function run completed");
    }
    else
    {
        Modulea->ui->pushButton_57->setEnabled(false);
        Logger->Displaylog("N","disable scan serial button","Enablescanportbutton function run completed");
    }
}

/*  check is enable scan serial port button*/;

void RelayBox::Connectserialport()
{
    SuperS->Connectserialport(Serial,Serialnamelist[Modulea->ui->comboBox_1->currentIndex()],Modulea->ui->comboBox->currentText().toInt());
    if(Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Connectwidgetet,true);
        SuperC->Enablewidgetlist(&Connectwidgetef,false);
        SuperC->Enablewidgetlist(Relayconnectwidgetet,true);
        Enablelineeditlist(Lineeditlist,true);
        Enablerelaybutton();
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_1->currentText() + " and set baudrate as " + Modulea->ui->comboBox->currentText() + " success","connectserialport function run completed");
        Timerca->start();
    }
    else
    {
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_1->currentText() + " and set baudrate as " + Modulea->ui->comboBox->currentText() + " failed","connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for check connected device;*/

void RelayBox::Disconnectserialport()
{
    Serial->close();
    if(!Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Disconnectwidgetet,true);
        SuperC->Enablewidgetlist(&Disconnectwidgetef,false);
        SuperC->Enablewidgetlist(Relaydisconnectwidgetef,false);
        Enablelineeditlist(Lineeditlist,false);
        Timerca->stop();
        Logger->Displaylog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui;*/

void RelayBox::Enablelineeditlist(QList<QLineEdit*>* lineeditlist,bool boola)
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

void RelayBox::Timercaslot()
{
    if(SuperS->Checkserialdevice(Serial,Modulea->ui->comboBox_1->currentText()) == false)
    {
        Disconnectserialport();
        Getserialport();
        Logger->Displaylog("N","serial port has been removed","Timercaslot function run completed");
        Enableconnectbutton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void RelayBox::Writecommand(QString strcommand)
{
    Modulea->ui->lineEdit->setText(strcommand);
    SuperS->Writeserial(Modulea->ui->checkBox_29,Modulea->ui->checkBox_27,Modulea->ui->checkBox_27,Serial,Modulea->ui->lineEdit);
    if(Threadta->isRunning())
    {
        Logger->Displaylog("N","waitting for return value or timeout;","Writecommand function run completed");
    }
    else
    {
        Logger->Displaylog("W",Modulea->ui->lineEdit->text(),"Writecommand function run completed");
        Threadta->start();
    }
}

/*  click single button api;*/

void RelayBox::Opreateallchannel(QStringList *listcommand)
{
    QString Command = "";
    for(int i = 0;i < listcommand->count();i++)
    {
        Command = Command + listcommand->at(i);
    }
    Writecommand(Command);
}

/*  opreate all channel api;*/

void RelayBox::Opreateselectchannel(QStringList *listcommand)
{
    QString comand = "";
    for(int i = 0;i < Checkboxlist->count();i++)
    {
        if (Checkboxlist->at(i)->isChecked())
        {
            comand = comand + listcommand->at(i);
        }
    }
    Writecommand(comand);
}

/*  opreate selected channel api;*/

void RelayBox::Resetallchannel()
{
    Opreateallchannel(Gtkrelayopencommand);
}

/*  open all channel;*/

void RelayBox::Closeallchannel()
{
    Opreateallchannel(Gtkrelayclosecommand);
}

/*  close all channel;*/

void RelayBox::Closeselectchannel()
{
    Opreateselectchannel(Gtkrelayclosecommand);
}

/*  close select channel;*/

void RelayBox::Openselectchannel()
{
    Opreateselectchannel(Gtkrelayopencommand);
}

/*  open select channel;*/

QString RelayBox::Checkselectchannel()
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

void RelayBox::Enablerelaybutton()
{
    QString strchannels = Checkselectchannel();
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
    Logger->Displaylog("N","current selected channels: " + strchannels,"enablerelaybutton function run completed");
}

/*  enable button or not;*/

void RelayBox::Scanrelayport()
{
    Modulea->ui->pushButton_57->setEnabled(false);
    Threadsa->start();
}

/*  start scan relay port;*/

void RelayBox::Selectrelaymodel()
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
            Logger->Displaylog("N","communication type: hex;","Displayrelaymodel function run completed;");
            Logger->Displaylog("N","setting save path:  " + Channel15relay->Settingpath,"Displayrelaymodel function run completed;");
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
            Logger->Displaylog("N","communication type: string;","Displayrelaymodel function run completed;");
            Logger->Displaylog("N","setting save path:  " + Channel34relay->Settingpath,"Displayrelaymodel function run completed;");
            break;
        }
    }
    Enableconnectbutton();
    Enablescanportbutton();
}

/*  select gtk relay model;*/

void RelayBox::Signalsbslot(QString strcommand)
{
    Modulea->ui->lineEdit->setText(strcommand);
    SuperS->Writeserial(Modulea->ui->checkBox_29,Modulea->ui->checkBox_27,Modulea->ui->checkBox_27,Serial,Modulea->ui->lineEdit);
}

/*  receive signal and write strcommand;*/

void RelayBox::Signalscslot()
{
    Modulea->ui->pushButton_57->setEnabled(true);
}

/*  reset scan pushbutton;*/

void RelayBox::Readyreadslot()
{
    QByteArray result = SuperS->Readdatastream(Serial,Modulea->ui->checkBox_29);
    Logger->Displaylog("R",result,"Signaltaslot function run completed");
    Operatorprogressbar(result,Gtkrelayclosebackvalue,99);
    Operatorprogressbar(result,Gtkrelayopenbackvalue,0);
}

/*  receive signal and read data from serial port;*/

void RelayBox::Readtimeoutslot()
{
    Logger->Displaylog("R","serial port receive time out","Signaltaslot function run completed");
}

void RelayBox::Operatorprogressbar(QString backvalue,QStringList *backvaluelist,int intlight)
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

void RelayBox::Selectsetting()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,Fileinfo.absolutePath(),{"*.ini"});
    connect(filedialog,&SuperFileDialog::Signalfb,Moduleb->ui->lineEdit_16,  &QLineEdit::setText);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,       &QObject::deleteLater);
    filedialog->Setsinglefile();
    filedialog->Show();
}

/*  select setting;*/

void RelayBox::Setsetting(QString file)
{
    switch (Moduleb->ui->comboBox_2->currentIndex())
    {
        case 1:
        {
            Channel15relay->Enablelineedit(false);
            Channel15relay->Setsetting(file);
            break;
        }
        case 2:
        {
            Channel34relay->Enablelineedit(false);
            Channel34relay->Setsetting(file);
            break;
        }
    }
}

/*  set setting;*/
