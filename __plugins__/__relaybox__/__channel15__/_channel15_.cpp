#include "_channel15_.h"
#include "ui__channel15_.h"

Channel15::Channel15(QWidget *parent,QSerialPort *serial,QCheckBox *checkbox,QLineEdit *lineedit)
    : QFrame(parent)
    , ui(new Ui::Channel15)
{
    ui->setupUi(this);
    Widget = parent;
    Serial = serial;
    Checkbox = checkbox;
    Lineedit = lineedit;
    connect(ui->pushButton_1,  &QPushButton::clicked,      this,   &Channel15::closeChannel1);
    connect(ui->pushButton_2,  &QPushButton::clicked,      this,   &Channel15::closeChannel2);
    connect(ui->pushButton_3,  &QPushButton::clicked,      this,   &Channel15::closeChannel3);
    connect(ui->pushButton_4,  &QPushButton::clicked,      this,   &Channel15::closeChannel4);
    connect(ui->pushButton_5,  &QPushButton::clicked,      this,   &Channel15::closeChannel5);
    connect(ui->pushButton_6,  &QPushButton::clicked,      this,   &Channel15::closeChannel6);
    connect(ui->pushButton_7,  &QPushButton::clicked,      this,   &Channel15::closeChannel7);
    connect(ui->pushButton_8,  &QPushButton::clicked,      this,   &Channel15::closeChannel8);
    connect(ui->pushButton_9,  &QPushButton::clicked,      this,   &Channel15::closeChannel9);
    connect(ui->pushButton_10, &QPushButton::clicked,      this,   &Channel15::closeChannela);
    connect(ui->pushButton_11, &QPushButton::clicked,      this,   &Channel15::closeChannelb);
    connect(ui->pushButton_12, &QPushButton::clicked,      this,   &Channel15::closeChannelc);
    connect(ui->pushButton_13, &QPushButton::clicked,      this,   &Channel15::closeChanneld);
    connect(ui->pushButton_14, &QPushButton::clicked,      this,   &Channel15::closeChannele);
    connect(ui->pushButton_15, &QPushButton::clicked,      this,   &Channel15::closeChannelf);
    connect(ui->pushButton_16, &QPushButton::clicked,      this,   &Channel15::openChannel1);
    connect(ui->pushButton_17, &QPushButton::clicked,      this,   &Channel15::openChannel2);
    connect(ui->pushButton_18, &QPushButton::clicked,      this,   &Channel15::openChannel3);
    connect(ui->pushButton_19, &QPushButton::clicked,      this,   &Channel15::openChannel4);
    connect(ui->pushButton_20, &QPushButton::clicked,      this,   &Channel15::openChannel5);
    connect(ui->pushButton_21, &QPushButton::clicked,      this,   &Channel15::openChannel6);
    connect(ui->pushButton_22, &QPushButton::clicked,      this,   &Channel15::openChannel7);
    connect(ui->pushButton_23, &QPushButton::clicked,      this,   &Channel15::openChannel8);
    connect(ui->pushButton_24, &QPushButton::clicked,      this,   &Channel15::openChannel9);
    connect(ui->pushButton_25, &QPushButton::clicked,      this,   &Channel15::openChannela);
    connect(ui->pushButton_26, &QPushButton::clicked,      this,   &Channel15::openChannelb);
    connect(ui->pushButton_27, &QPushButton::clicked,      this,   &Channel15::openChannelc);
    connect(ui->pushButton_28, &QPushButton::clicked,      this,   &Channel15::openChanneld);
    connect(ui->pushButton_29, &QPushButton::clicked,      this,   &Channel15::openChannele);
    connect(ui->pushButton_30, &QPushButton::clicked,      this,   &Channel15::openChannelf);
    connect(ui->checkBox_9,    &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_10,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_11,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_12,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_13,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_14,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_15,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_16,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_17,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_18,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_19,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_20,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_21,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_22,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->checkBox_23,   &QCheckBox::stateChanged,   this,   &Channel15::emitEnableRelayButton);
    connect(ui->lineEdit,      &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit,      &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_2,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_2,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_3,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_3,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_4,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_4,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_5,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_5,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_6,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_6,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_7,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_7,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_8,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_8,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_9,    &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_9,    &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_10,   &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_10,   &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_11,   &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_11,   &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_12,   &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_12,   &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_13,   &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_13,   &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_14,   &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_14,   &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    connect(ui->lineEdit_15,   &QLineEdit::textChanged,    this,   &Channel15::checkLineEditText);
    connect(ui->lineEdit_15,   &QLineEdit::editingFinished,this,   &Channel15::saveCurrentText);
    init();
}

Channel15::~Channel15()
{
    Core->closeThread(Threadsa);
    delete ui;
}

void Channel15::init()
{
    objectInit();
    widgetListInit();
}

void Channel15::objectInit()
{
    Core = new SuperCore(this);
    Threadsa = new SuperScanSerial(Widget,Serial,9600,"aaf1","aaf0",Checkbox,Lineedit,"66f1","66f0");
    connect(Threadsa,&SuperScanSerial::signalSa,this,&Channel15::emitDisplayLog);
    connect(Threadsa,&SuperScanSerial::signalSb,this,&Channel15::emitSignalSbSlot);
    connect(Threadsa,&SuperScanSerial::signalSc,this,&Channel15::emitSignalScSlot);
}

void Channel15::widgetListInit()
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

void Channel15::setSetting(QString path)
{
    Settingpath = path;
    loadSetting();
    enableLineEdit(Serial->isOpen());
}

/*  set setting path;*/

void Channel15::closeChannel1()
{
    emit signalCd("aa11");
}

/*  close gtk relay channel 1;*/

void Channel15::closeChannel2()
{
    emit signalCd("aa21");
}

/*  close gtk relay channel 2;*/

void Channel15::closeChannel3()
{
    emit signalCd("aa31");
}

/*  close gtk relay channel 3;*/

void Channel15::closeChannel4()
{
    emit signalCd("aa41");
}

/*  close gtk relay channel 4;*/

void Channel15::closeChannel5()
{
    emit signalCd("aa51");
}

/*  close gtk relay channel 5;*/

void Channel15::closeChannel6()
{
    emit signalCd("aa61");
}

/*  close gtk relay channel 6;*/

void Channel15::closeChannel7()
{
    emit signalCd("aa71");
}

/*  close gtk relay channel 7;*/

void Channel15::closeChannel8()
{
    emit signalCd("aa81");
}

/*  close gtk relay channel 8;*/

void Channel15::closeChannel9()
{
    emit signalCd("aa91");
}

/*  close gtk relay channel 9;*/

void Channel15::closeChannela()
{
    emit signalCd("aaa1");
}

/*  close gtk relay channel 10;*/

void Channel15::closeChannelb()
{
    emit signalCd("aab1");
}

/*  close gtk relay channel 11;*/

void Channel15::closeChannelc()
{
    emit signalCd("aac1");
}

/*  close gtk relay channel 12;*/

void Channel15::closeChanneld()
{
    emit signalCd("aad1");
}

/*  close gtk relay channel 13;*/

void Channel15::closeChannele()
{
    emit signalCd("aae1");
}

/*  close gtk relay channel 14;*/

void Channel15::closeChannelf()
{
    emit signalCd("aaf1");
}

/*  close gtk relay channel 15;*/

void Channel15::openChannel1()
{
    emit signalCd("aa10");
}

/*  open gtk relay channel 1;*/

void Channel15::openChannel2()
{
    emit signalCd("aa20");
}

/*  open gtk relay channel 2;*/

void Channel15::openChannel3()
{
    emit signalCd("aa30");
}

/*  open gtk relay channel 3;*/

void Channel15::openChannel4()
{
    emit signalCd("aa40");
}

/*  open gtk relay channel 4;*/

void Channel15::openChannel5()
{
    emit signalCd("aa50");
}

/*  open gtk relay channel 5;*/

void Channel15::openChannel6()
{
    emit signalCd("aa60");
}

/*  open gtk relay channel 6;*/

void Channel15::openChannel7()
{
    emit signalCd("aa70");
}

/*  open gtk relay channel 7;*/

void Channel15::openChannel8()
{
    emit signalCd("aa80");
}

/*  open gtk relay channel 8;*/

void Channel15::openChannel9()
{
    emit signalCd("aa90");
}

/*  open gtk relay channel 9;*/

void Channel15::openChannela()
{
    emit signalCd("aaa0");
}

/*  open gtk relay channel 10;*/

void Channel15::openChannelb()
{
    emit signalCd("aab0");
}

/*  open gtk relay channel 11;*/

void Channel15::openChannelc()
{
    emit signalCd("aac0");
}

/*  open gtk relay channel 12;*/

void Channel15::openChanneld()
{
    emit signalCd("aad0");
}

/*  open gtk relay channel 13;*/

void Channel15::openChannele()
{
    emit signalCd("aae0");
}

/*  open gtk relay channel 14;*/

void Channel15::openChannelf()
{
    emit signalCd("aaf0");
}

/*  open gtk relay channel 15;*/

void Channel15::emitDisplayLog(QString direction,QString strtlog,QString strllog)
{
    emit signalCa(direction,strtlog,strllog);
}

/*  emit signal for dislpaylog function;*/

void Channel15::emitSignalSbSlot(QString strcommand)
{
    emit signalCb(strcommand);
}

/*  emit signal for thread write serial function;*/

void Channel15::emitSignalScSlot()
{
    emit signalCc();
}

/*  emit signal for thread finished;*/

void Channel15::emitEnableRelayButton()
{
    emit signalCe();
}

/*  emit signal for enable button;*/

void Channel15::saveCurrentText()
{
    Core->writeOnlyFile(Settingpath,"15" + Spliter);
    QString currenttext = "";
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        currenttext.append(Lineeditlist.at(i)->text() + Spliter);
    }
    Core->appendFile(Settingpath,currenttext);
}

/*  emit signal for thread finished;*/

void Channel15::checkLineEditText(QString text)
{
    QLineEdit *lineedit = (QLineEdit*)sender();
    if(text.contains(Spliter) && lineedit->isEnabled())
    {
        lineedit->clear();
        SuperNoteDialog *messagbox = new SuperNoteDialog(nullptr,"can not input " + Spliter + ";");
        messagbox->hideLeftButton();
        messagbox->messageInit();
    }
}

/*  emit signal for thread finished;*/

void Channel15::loadSetting()
{
    QStringList textlist = Core->readOnlyFile(Settingpath).split(Spliter);
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
        messagbox->messageInit();
        for(int i = 0;i < Lineeditlist.count();i++)
        {
            Lineeditlist.at(i)->clear();
        }
    }
}

/*  load setting;*/

void Channel15::enableLineEdit(bool boola)
{
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        Lineeditlist.at(i)->setEnabled(boola);
    }
}

/*  enable lineedit;*/
