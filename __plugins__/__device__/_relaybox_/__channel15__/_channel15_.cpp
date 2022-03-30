#include "_channel15_.h"

Channel15::Channel15(QWidget *parent,QSerialPort *serial,QCheckBox *checkbox,QLineEdit *lineedit)
    : QFrame(parent)
    , ui(new Ui::Channel15)
{
    ui->setupUi(this);
    Widget = parent;
    Serial = serial;
    Checkbox = checkbox;
    Lineedit = lineedit;
    connect(ui->pushButton_1,  &QPushButton::clicked,      this,   &Channel15::Closechannel1);
    connect(ui->pushButton_2,  &QPushButton::clicked,      this,   &Channel15::Closechannel2);
    connect(ui->pushButton_3,  &QPushButton::clicked,      this,   &Channel15::Closechannel3);
    connect(ui->pushButton_4,  &QPushButton::clicked,      this,   &Channel15::Closechannel4);
    connect(ui->pushButton_5,  &QPushButton::clicked,      this,   &Channel15::Closechannel5);
    connect(ui->pushButton_6,  &QPushButton::clicked,      this,   &Channel15::Closechannel6);
    connect(ui->pushButton_7,  &QPushButton::clicked,      this,   &Channel15::Closechannel7);
    connect(ui->pushButton_8,  &QPushButton::clicked,      this,   &Channel15::Closechannel8);
    connect(ui->pushButton_9,  &QPushButton::clicked,      this,   &Channel15::Closechannel9);
    connect(ui->pushButton_10, &QPushButton::clicked,      this,   &Channel15::Closechannela);
    connect(ui->pushButton_11, &QPushButton::clicked,      this,   &Channel15::Closechannelb);
    connect(ui->pushButton_12, &QPushButton::clicked,      this,   &Channel15::Closechannelc);
    connect(ui->pushButton_13, &QPushButton::clicked,      this,   &Channel15::Closechanneld);
    connect(ui->pushButton_14, &QPushButton::clicked,      this,   &Channel15::Closechannele);
    connect(ui->pushButton_15, &QPushButton::clicked,      this,   &Channel15::Closechannelf);
    connect(ui->pushButton_16, &QPushButton::clicked,      this,   &Channel15::Openchannel1);
    connect(ui->pushButton_17, &QPushButton::clicked,      this,   &Channel15::Openchannel2);
    connect(ui->pushButton_18, &QPushButton::clicked,      this,   &Channel15::Openchannel3);
    connect(ui->pushButton_19, &QPushButton::clicked,      this,   &Channel15::Openchannel4);
    connect(ui->pushButton_20, &QPushButton::clicked,      this,   &Channel15::Openchannel5);
    connect(ui->pushButton_21, &QPushButton::clicked,      this,   &Channel15::Openchannel6);
    connect(ui->pushButton_22, &QPushButton::clicked,      this,   &Channel15::Openchannel7);
    connect(ui->pushButton_23, &QPushButton::clicked,      this,   &Channel15::Openchannel8);
    connect(ui->pushButton_24, &QPushButton::clicked,      this,   &Channel15::Openchannel9);
    connect(ui->pushButton_25, &QPushButton::clicked,      this,   &Channel15::Openchannela);
    connect(ui->pushButton_26, &QPushButton::clicked,      this,   &Channel15::Openchannelb);
    connect(ui->pushButton_27, &QPushButton::clicked,      this,   &Channel15::Openchannelc);
    connect(ui->pushButton_28, &QPushButton::clicked,      this,   &Channel15::Openchanneld);
    connect(ui->pushButton_29, &QPushButton::clicked,      this,   &Channel15::Openchannele);
    connect(ui->pushButton_30, &QPushButton::clicked,      this,   &Channel15::Openchannelf);
    connect(ui->checkBox_9,    &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_10,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_11,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_12,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_13,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_14,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_15,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_16,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_17,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_18,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_19,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_20,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_21,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_22,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->checkBox_23,   &QCheckBox::stateChanged,   this,   &Channel15::Emitenablerelaybutton);
    connect(ui->lineEdit,      &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit,      &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_2,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_2,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_3,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_3,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_4,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_4,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_5,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_5,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_6,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_6,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_7,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_7,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_8,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_8,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_9,    &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_9,    &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_10,   &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_10,   &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_11,   &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_11,   &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_12,   &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_12,   &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_13,   &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_13,   &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_14,   &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_14,   &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    connect(ui->lineEdit_15,   &QLineEdit::textChanged,    this,   &Channel15::Checklineedittext);
    connect(ui->lineEdit_15,   &QLineEdit::editingFinished,this,   &Channel15::Savecurrenttext);
    Init();
}

Channel15::~Channel15()
{
    SuperC->Closethread(Threadsa);
    delete ui;
}

void Channel15::Init()
{
    Objectinit();
    Widgetlistinit();
}

void Channel15::Objectinit()
{
    SuperC = new SuperCore(this);
    Threadsa = new ScanSerialPort(Widget,Serial,9600,"aaf1","aaf0",Checkbox,Lineedit,"66f1","66f0");
    connect(Threadsa,&ScanSerialPort::Signalsa,this,&Channel15::Emitdisplaylog);
    connect(Threadsa,&ScanSerialPort::Signalsb,this,&Channel15::Emitsignalsbslot);
    connect(Threadsa,&ScanSerialPort::Signalsc,this,&Channel15::Emitsignalscslot);
}

void Channel15::Widgetlistinit()
{
    Connectwidgetet     = {ui->pushButton_1,ui->pushButton_2,ui->pushButton_3,ui->pushButton_4,ui->pushButton_5,ui->pushButton_6,
                           ui->pushButton_7,ui->pushButton_8,ui->pushButton_9,ui->pushButton_10,ui->pushButton_11,ui->pushButton_12,
                           ui->pushButton_13,ui->pushButton_14,ui->pushButton_15,ui->pushButton_16,ui->pushButton_17,ui->pushButton_18,
                           ui->pushButton_19,ui->pushButton_20,ui->pushButton_21,ui->pushButton_22,ui->pushButton_23,ui->pushButton_24,
                           ui->pushButton_25,ui->pushButton_26,ui->pushButton_27,ui->pushButton_28,ui->pushButton_29,ui->pushButton_30,
                           ui->checkBox_9,ui->checkBox_10,ui->checkBox_11,ui->checkBox_12,ui->checkBox_13,ui->checkBox_14,
                           ui->checkBox_15,ui->checkBox_16,ui->checkBox_17,ui->checkBox_18,ui->checkBox_19,ui->checkBox_20,
                           ui->checkBox_21,ui->checkBox_22,ui->checkBox_23};
    Disconnectwidgetef  = {ui->pushButton_1,ui->pushButton_2,ui->pushButton_3,ui->pushButton_4,ui->pushButton_5,ui->pushButton_6,
                           ui->pushButton_7,ui->pushButton_8,ui->pushButton_9,ui->pushButton_10,ui->pushButton_11,ui->pushButton_12,
                           ui->pushButton_13,ui->pushButton_14,ui->pushButton_15,ui->pushButton_16,ui->pushButton_17,ui->pushButton_18,
                           ui->pushButton_19,ui->pushButton_20,ui->pushButton_21,ui->pushButton_22,ui->pushButton_23,ui->pushButton_24,
                           ui->pushButton_25,ui->pushButton_26,ui->pushButton_27,ui->pushButton_28,ui->pushButton_29,ui->pushButton_30,
                           ui->checkBox_9,ui->checkBox_10,ui->checkBox_11,ui->checkBox_12,ui->checkBox_13,ui->checkBox_14,
                           ui->checkBox_15,ui->checkBox_16,ui->checkBox_17,ui->checkBox_18,ui->checkBox_19,ui->checkBox_20,
                           ui->checkBox_21,ui->checkBox_22,ui->checkBox_23};
    Progressbarlist     = {ui->progressBar_1,ui->progressBar_2,ui->progressBar_3,ui->progressBar_4,ui->progressBar_5,ui->progressBar_6,
                           ui->progressBar_7,ui->progressBar_8,ui->progressBar_9,ui->progressBar_10,ui->progressBar_11,ui->progressBar_12,
                           ui->progressBar_13,ui->progressBar_14,ui->progressBar_15};
    Checkboxlist        = {ui->checkBox_9,ui->checkBox_10,ui->checkBox_11,ui->checkBox_12,ui->checkBox_13,ui->checkBox_14,ui->checkBox_15,
                           ui->checkBox_16,ui->checkBox_17,ui->checkBox_18,ui->checkBox_19,ui->checkBox_20,ui->checkBox_21,ui->checkBox_22,
                           ui->checkBox_23};
    Lineeditlist        = {ui->lineEdit,ui->lineEdit_2,ui->lineEdit_3,ui->lineEdit_4,ui->lineEdit_5,ui->lineEdit_6,ui->lineEdit_7,ui->lineEdit_8,
                           ui->lineEdit_9,ui->lineEdit_10,ui->lineEdit_11,ui->lineEdit_12,ui->lineEdit_13,ui->lineEdit_14,ui->lineEdit_15};
}

void Channel15::Setsetting(QString path)
{
    Settingpath = path;
    Loadsetting();
    Enablelineedit(Serial->isOpen());
}

/*  set setting path;*/

void Channel15::Closechannel1()
{
    emit Signalcd("aa11");
}

/*  close gtk relay channel 1;*/

void Channel15::Closechannel2()
{
    emit Signalcd("aa21");
}

/*  close gtk relay channel 2;*/

void Channel15::Closechannel3()
{
    emit Signalcd("aa31");
}

/*  close gtk relay channel 3;*/

void Channel15::Closechannel4()
{
    emit Signalcd("aa41");
}

/*  close gtk relay channel 4;*/

void Channel15::Closechannel5()
{
    emit Signalcd("aa51");
}

/*  close gtk relay channel 5;*/

void Channel15::Closechannel6()
{
    emit Signalcd("aa61");
}

/*  close gtk relay channel 6;*/

void Channel15::Closechannel7()
{
    emit Signalcd("aa71");
}

/*  close gtk relay channel 7;*/

void Channel15::Closechannel8()
{
    emit Signalcd("aa81");
}

/*  close gtk relay channel 8;*/

void Channel15::Closechannel9()
{
    emit Signalcd("aa91");
}

/*  close gtk relay channel 9;*/

void Channel15::Closechannela()
{
    emit Signalcd("aaa1");
}

/*  close gtk relay channel 10;*/

void Channel15::Closechannelb()
{
    emit Signalcd("aab1");
}

/*  close gtk relay channel 11;*/

void Channel15::Closechannelc()
{
    emit Signalcd("aac1");
}

/*  close gtk relay channel 12;*/

void Channel15::Closechanneld()
{
    emit Signalcd("aad1");
}

/*  close gtk relay channel 13;*/

void Channel15::Closechannele()
{
    emit Signalcd("aae1");
}

/*  close gtk relay channel 14;*/

void Channel15::Closechannelf()
{
    emit Signalcd("aaf1");
}

/*  close gtk relay channel 15;*/

void Channel15::Openchannel1()
{
    emit Signalcd("aa10");
}

/*  open gtk relay channel 1;*/

void Channel15::Openchannel2()
{
    emit Signalcd("aa20");
}

/*  open gtk relay channel 2;*/

void Channel15::Openchannel3()
{
    emit Signalcd("aa30");
}

/*  open gtk relay channel 3;*/

void Channel15::Openchannel4()
{
    emit Signalcd("aa40");
}

/*  open gtk relay channel 4;*/

void Channel15::Openchannel5()
{
    emit Signalcd("aa50");
}

/*  open gtk relay channel 5;*/

void Channel15::Openchannel6()
{
    emit Signalcd("aa60");
}

/*  open gtk relay channel 6;*/

void Channel15::Openchannel7()
{
    emit Signalcd("aa70");
}

/*  open gtk relay channel 7;*/

void Channel15::Openchannel8()
{
    emit Signalcd("aa80");
}

/*  open gtk relay channel 8;*/

void Channel15::Openchannel9()
{
    emit Signalcd("aa90");
}

/*  open gtk relay channel 9;*/

void Channel15::Openchannela()
{
    emit Signalcd("aaa0");
}

/*  open gtk relay channel 10;*/

void Channel15::Openchannelb()
{
    emit Signalcd("aab0");
}

/*  open gtk relay channel 11;*/

void Channel15::Openchannelc()
{
    emit Signalcd("aac0");
}

/*  open gtk relay channel 12;*/

void Channel15::Openchanneld()
{
    emit Signalcd("aad0");
}

/*  open gtk relay channel 13;*/

void Channel15::Openchannele()
{
    emit Signalcd("aae0");
}

/*  open gtk relay channel 14;*/

void Channel15::Openchannelf()
{
    emit Signalcd("aaf0");
}

/*  open gtk relay channel 15;*/

void Channel15::Emitdisplaylog(QString direction,QString strtlog,QString strllog)
{
    emit Signalca(direction,strtlog,strllog);
}

/*  emit signal for dislpaylog function;*/

void Channel15::Emitsignalsbslot(QString strcommand)
{
    emit Signalcb(strcommand);
}

/*  emit signal for thread write serial function;*/

void Channel15::Emitsignalscslot()
{
    emit Signalcc();
}

/*  emit signal for thread finished;*/

void Channel15::Emitenablerelaybutton()
{
    emit Signalce();
}

/*  emit signal for enable button;*/

void Channel15::Savecurrenttext()
{
    SuperC->Writeonlyfile(Settingpath,"15" + Spliter);
    QString currenttext = "";
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        currenttext.append(Lineeditlist.at(i)->text() + Spliter);
    }
    SuperC->Appendfile(Settingpath,currenttext);
}

/*  emit signal for thread finished;*/

void Channel15::Checklineedittext(QString text)
{
    QLineEdit *lineedit = (QLineEdit*)sender();
    if(text.contains(Spliter) && lineedit->isEnabled())
    {
        lineedit->clear();
        SuperNoteDialog *messagbox = new SuperNoteDialog(nullptr,"can not input " + Spliter + ";");
        messagbox->Hideleftbutton();
        messagbox->Messageinit();
    }
}

/*  emit signal for thread finished;*/

void Channel15::Loadsetting()
{
    QStringList textlist = SuperC->Readonlyfile(Settingpath).split(Spliter);
    if(textlist.count() >= 16)
    {
        for(int i = 0;i < Lineeditlist.count();i++)
        {
            Lineeditlist.at(i)->setText(textlist.at(i + 1));
        }
    }
    else if(!Settingpath.isEmpty())
    {
        SuperNoteDialog *messagbox = new SuperNoteDialog(nullptr,"unknown parameter,set as new setting;");
        messagbox->Messageinit();
        for(int i = 0;i < Lineeditlist.count();i++)
        {
            Lineeditlist.at(i)->clear();
        }
    }
}

/*  load setting;*/

void Channel15::Enablelineedit(bool boola)
{
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        Lineeditlist.at(i)->setEnabled(boola);
    }
}

/*  enable lineedit;*/
