#include "_channel34_.h"

Channel34::Channel34(QWidget *parent,QSerialPort *serial,QCheckBox *checkbox,QLineEdit *lineedit)
    : QFrame(parent)
    , ui(new Ui::Channel34)
{
    ui->setupUi(this);
    Widget = parent;
    Serial = serial;
    Checkbox = checkbox;
    Lineedit = lineedit;
    connect(ui->pushButton_1,  &QPushButton::clicked,      this,   &Channel34::Closechannel01);
    connect(ui->pushButton_2,  &QPushButton::clicked,      this,   &Channel34::Closechannel02);
    connect(ui->pushButton_3,  &QPushButton::clicked,      this,   &Channel34::Closechannel03);
    connect(ui->pushButton_4,  &QPushButton::clicked,      this,   &Channel34::Closechannel04);
    connect(ui->pushButton_5,  &QPushButton::clicked,      this,   &Channel34::Closechannel05);
    connect(ui->pushButton_6,  &QPushButton::clicked,      this,   &Channel34::Closechannel06);
    connect(ui->pushButton_7,  &QPushButton::clicked,      this,   &Channel34::Closechannel07);
    connect(ui->pushButton_8,  &QPushButton::clicked,      this,   &Channel34::Closechannel08);
    connect(ui->pushButton_9,  &QPushButton::clicked,      this,   &Channel34::Closechannel09);
    connect(ui->pushButton_10, &QPushButton::clicked,      this,   &Channel34::Closechannel10);
    connect(ui->pushButton_11, &QPushButton::clicked,      this,   &Channel34::Closechannel11);
    connect(ui->pushButton_12, &QPushButton::clicked,      this,   &Channel34::Closechannel12);
    connect(ui->pushButton_13, &QPushButton::clicked,      this,   &Channel34::Closechannel13);
    connect(ui->pushButton_14, &QPushButton::clicked,      this,   &Channel34::Closechannel14);
    connect(ui->pushButton_15, &QPushButton::clicked,      this,   &Channel34::Closechannel15);
    connect(ui->pushButton_31, &QPushButton::clicked,      this,   &Channel34::Closechannel16);
    connect(ui->pushButton_33, &QPushButton::clicked,      this,   &Channel34::Closechannel17);
    connect(ui->pushButton_35, &QPushButton::clicked,      this,   &Channel34::Closechannel18);
    connect(ui->pushButton_37, &QPushButton::clicked,      this,   &Channel34::Closechannel19);
    connect(ui->pushButton_39, &QPushButton::clicked,      this,   &Channel34::Closechannel20);
    connect(ui->pushButton_41, &QPushButton::clicked,      this,   &Channel34::Closechannel21);
    connect(ui->pushButton_43, &QPushButton::clicked,      this,   &Channel34::Closechannel22);
    connect(ui->pushButton_45, &QPushButton::clicked,      this,   &Channel34::Closechannel23);
    connect(ui->pushButton_47, &QPushButton::clicked,      this,   &Channel34::Closechannel24);
    connect(ui->pushButton_49, &QPushButton::clicked,      this,   &Channel34::Closechannel25);
    connect(ui->pushButton_51, &QPushButton::clicked,      this,   &Channel34::Closechannel26);
    connect(ui->pushButton_53, &QPushButton::clicked,      this,   &Channel34::Closechannel27);
    connect(ui->pushButton_55, &QPushButton::clicked,      this,   &Channel34::Closechannel28);
    connect(ui->pushButton_57, &QPushButton::clicked,      this,   &Channel34::Closechannel29);
    connect(ui->pushButton_59, &QPushButton::clicked,      this,   &Channel34::Closechannel30);
    connect(ui->pushButton_61, &QPushButton::clicked,      this,   &Channel34::Closechannel31);
    connect(ui->pushButton_63, &QPushButton::clicked,      this,   &Channel34::Closechannel32);
    connect(ui->pushButton_65, &QPushButton::clicked,      this,   &Channel34::Closechannel33);
    connect(ui->pushButton_67, &QPushButton::clicked,      this,   &Channel34::Closechannel34);
    connect(ui->pushButton_16, &QPushButton::clicked,      this,   &Channel34::Openchannel01);
    connect(ui->pushButton_17, &QPushButton::clicked,      this,   &Channel34::Openchannel02);
    connect(ui->pushButton_18, &QPushButton::clicked,      this,   &Channel34::Openchannel03);
    connect(ui->pushButton_19, &QPushButton::clicked,      this,   &Channel34::Openchannel04);
    connect(ui->pushButton_20, &QPushButton::clicked,      this,   &Channel34::Openchannel05);
    connect(ui->pushButton_21, &QPushButton::clicked,      this,   &Channel34::Openchannel06);
    connect(ui->pushButton_22, &QPushButton::clicked,      this,   &Channel34::Openchannel07);
    connect(ui->pushButton_23, &QPushButton::clicked,      this,   &Channel34::Openchannel08);
    connect(ui->pushButton_24, &QPushButton::clicked,      this,   &Channel34::Openchannel09);
    connect(ui->pushButton_25, &QPushButton::clicked,      this,   &Channel34::Openchannel10);
    connect(ui->pushButton_26, &QPushButton::clicked,      this,   &Channel34::Openchannel11);
    connect(ui->pushButton_27, &QPushButton::clicked,      this,   &Channel34::Openchannel12);
    connect(ui->pushButton_28, &QPushButton::clicked,      this,   &Channel34::Openchannel13);
    connect(ui->pushButton_29, &QPushButton::clicked,      this,   &Channel34::Openchannel14);
    connect(ui->pushButton_30, &QPushButton::clicked,      this,   &Channel34::Openchannel15);
    connect(ui->pushButton_32, &QPushButton::clicked,      this,   &Channel34::Openchannel16);
    connect(ui->pushButton_34, &QPushButton::clicked,      this,   &Channel34::Openchannel17);
    connect(ui->pushButton_36, &QPushButton::clicked,      this,   &Channel34::Openchannel18);
    connect(ui->pushButton_38, &QPushButton::clicked,      this,   &Channel34::Openchannel19);
    connect(ui->pushButton_40, &QPushButton::clicked,      this,   &Channel34::Openchannel20);
    connect(ui->pushButton_42, &QPushButton::clicked,      this,   &Channel34::Openchannel21);
    connect(ui->pushButton_44, &QPushButton::clicked,      this,   &Channel34::Openchannel22);
    connect(ui->pushButton_46, &QPushButton::clicked,      this,   &Channel34::Openchannel23);
    connect(ui->pushButton_48, &QPushButton::clicked,      this,   &Channel34::Openchannel24);
    connect(ui->pushButton_50, &QPushButton::clicked,      this,   &Channel34::Openchannel25);
    connect(ui->pushButton_52, &QPushButton::clicked,      this,   &Channel34::Openchannel26);
    connect(ui->pushButton_54, &QPushButton::clicked,      this,   &Channel34::Openchannel27);
    connect(ui->pushButton_56, &QPushButton::clicked,      this,   &Channel34::Openchannel28);
    connect(ui->pushButton_58, &QPushButton::clicked,      this,   &Channel34::Openchannel29);
    connect(ui->pushButton_60, &QPushButton::clicked,      this,   &Channel34::Openchannel30);
    connect(ui->pushButton_62, &QPushButton::clicked,      this,   &Channel34::Openchannel31);
    connect(ui->pushButton_64, &QPushButton::clicked,      this,   &Channel34::Openchannel32);
    connect(ui->pushButton_66, &QPushButton::clicked,      this,   &Channel34::Openchannel33);
    connect(ui->pushButton_68, &QPushButton::clicked,      this,   &Channel34::Openchannel34);
    connect(ui->checkBox_9,    &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_10,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_11,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_12,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_13,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_14,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_15,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_16,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_17,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_18,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_19,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_20,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_21,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_22,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_23,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_24,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_25,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_26,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_27,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_28,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_29,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_30,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_31,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_32,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_33,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_34,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_35,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_36,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_37,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_38,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_39,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_40,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_41,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->checkBox_42,   &QCheckBox::stateChanged,   this,   &Channel34::Emitenablerelaybutton);
    connect(ui->lineEdit,      &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit,      &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_2,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_2,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_3,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_3,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_4,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_4,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_5,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_5,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_6,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_6,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_7,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_7,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_8,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_8,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_9,    &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_9,    &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_10,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_10,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_11,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_11,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_12,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_12,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_13,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_13,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_14,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_14,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_15,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_15,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_16,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_16,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_17,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_17,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_18,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_18,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_19,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_19,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_20,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_20,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_21,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_21,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_22,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_22,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_23,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_23,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_24,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_24,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_25,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_25,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_26,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_26,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_27,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_27,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_28,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_28,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_29,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_29,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_30,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_30,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_31,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_31,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_32,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_32,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_33,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_33,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    connect(ui->lineEdit_34,   &QLineEdit::textChanged,    this,   &Channel34::Checklineedittext);
    connect(ui->lineEdit_34,   &QLineEdit::editingFinished,this,   &Channel34::Savecurrenttext);
    Init();

}

Channel34::~Channel34()
{
    SuperC->Closethread(Threadsa);
    delete ui;
}

void Channel34::Init()
{
    Objectinit();
    Widgetlistinit();
}

void Channel34::Objectinit()
{
    SuperC = new SuperCore(this);
    Threadsa = new ScanSerialPort(Widget,Serial,9600,"close001","open001",Checkbox,Lineedit,"close1 OK","open1 OK");
    connect(Threadsa,&ScanSerialPort::Signalsa,this,&Channel34::Emitdisplaylog);
    connect(Threadsa,&ScanSerialPort::Signalsb,this,&Channel34::Emitsignalsbslot);
    connect(Threadsa,&ScanSerialPort::Signalsc,this,&Channel34::Emitsignalscslot);
}

void Channel34::Widgetlistinit()
{
    Connectwidgetet     = {ui->pushButton_1,ui->pushButton_2,ui->pushButton_3,ui->pushButton_4,ui->pushButton_5,ui->pushButton_6,
                           ui->pushButton_7,ui->pushButton_8,ui->pushButton_9,ui->pushButton_10,ui->pushButton_11,ui->pushButton_12,
                           ui->pushButton_13,ui->pushButton_14,ui->pushButton_15,ui->pushButton_16,ui->pushButton_17,ui->pushButton_18,
                           ui->pushButton_19,ui->pushButton_20,ui->pushButton_21,ui->pushButton_22,ui->pushButton_23,ui->pushButton_24,
                           ui->pushButton_25,ui->pushButton_26,ui->pushButton_27,ui->pushButton_28,ui->pushButton_29,ui->pushButton_30,
                           ui->pushButton_31,ui->pushButton_32,ui->pushButton_33,ui->pushButton_34,ui->pushButton_35,ui->pushButton_36,
                           ui->pushButton_37,ui->pushButton_38,ui->pushButton_39,ui->pushButton_40,ui->pushButton_41,ui->pushButton_42,
                           ui->pushButton_43,ui->pushButton_44,ui->pushButton_45,ui->pushButton_46,ui->pushButton_47,ui->pushButton_48,
                           ui->pushButton_49,ui->pushButton_50,ui->pushButton_51,ui->pushButton_52,ui->pushButton_53,ui->pushButton_54,
                           ui->pushButton_55,ui->pushButton_56,ui->pushButton_57,ui->pushButton_58,ui->pushButton_59,ui->pushButton_60,
                           ui->pushButton_61,ui->pushButton_62,ui->pushButton_63,ui->pushButton_64,ui->pushButton_65,ui->pushButton_66,
                           ui->pushButton_67,ui->pushButton_68,
                           ui->checkBox_9,ui->checkBox_10,ui->checkBox_11,ui->checkBox_12,ui->checkBox_13,ui->checkBox_14,
                           ui->checkBox_15,ui->checkBox_16,ui->checkBox_17,ui->checkBox_18,ui->checkBox_19,ui->checkBox_20,
                           ui->checkBox_21,ui->checkBox_22,ui->checkBox_23,ui->checkBox_24,ui->checkBox_25,ui->checkBox_26,
                           ui->checkBox_27,ui->checkBox_28,ui->checkBox_29,ui->checkBox_30,ui->checkBox_31,ui->checkBox_32,
                           ui->checkBox_33,ui->checkBox_34,ui->checkBox_35,ui->checkBox_36,ui->checkBox_37,ui->checkBox_38,
                           ui->checkBox_39,ui->checkBox_40,ui->checkBox_41,ui->checkBox_42};
    Disconnectwidgetef  = {ui->pushButton_1,ui->pushButton_2,ui->pushButton_3,ui->pushButton_4,ui->pushButton_5,ui->pushButton_6,
                           ui->pushButton_7,ui->pushButton_8,ui->pushButton_9,ui->pushButton_10,ui->pushButton_11,ui->pushButton_12,
                           ui->pushButton_13,ui->pushButton_14,ui->pushButton_15,ui->pushButton_16,ui->pushButton_17,ui->pushButton_18,
                           ui->pushButton_19,ui->pushButton_20,ui->pushButton_21,ui->pushButton_22,ui->pushButton_23,ui->pushButton_24,
                           ui->pushButton_25,ui->pushButton_26,ui->pushButton_27,ui->pushButton_28,ui->pushButton_29,ui->pushButton_30,
                           ui->pushButton_31,ui->pushButton_32,ui->pushButton_33,ui->pushButton_34,ui->pushButton_35,ui->pushButton_36,
                           ui->pushButton_37,ui->pushButton_38,ui->pushButton_39,ui->pushButton_40,ui->pushButton_41,ui->pushButton_42,
                           ui->pushButton_43,ui->pushButton_44,ui->pushButton_45,ui->pushButton_46,ui->pushButton_47,ui->pushButton_48,
                           ui->pushButton_49,ui->pushButton_50,ui->pushButton_51,ui->pushButton_52,ui->pushButton_53,ui->pushButton_54,
                           ui->pushButton_55,ui->pushButton_56,ui->pushButton_57,ui->pushButton_58,ui->pushButton_59,ui->pushButton_60,
                           ui->pushButton_61,ui->pushButton_62,ui->pushButton_63,ui->pushButton_64,ui->pushButton_65,ui->pushButton_66,
                           ui->pushButton_67,ui->pushButton_68,
                           ui->checkBox_9,ui->checkBox_10,ui->checkBox_11,ui->checkBox_12,ui->checkBox_13,ui->checkBox_14,
                           ui->checkBox_15,ui->checkBox_16,ui->checkBox_17,ui->checkBox_18,ui->checkBox_19,ui->checkBox_20,
                           ui->checkBox_21,ui->checkBox_22,ui->checkBox_23,ui->checkBox_24,ui->checkBox_25,ui->checkBox_26,
                           ui->checkBox_27,ui->checkBox_28,ui->checkBox_29,ui->checkBox_30,ui->checkBox_31,ui->checkBox_32,
                           ui->checkBox_33,ui->checkBox_34,ui->checkBox_35,ui->checkBox_36,ui->checkBox_37,ui->checkBox_38,
                           ui->checkBox_39,ui->checkBox_40,ui->checkBox_41,ui->checkBox_42};
    Progressbarlist     = {ui->progressBar_1,ui->progressBar_2,ui->progressBar_3,ui->progressBar_4,ui->progressBar_5,ui->progressBar_6,
                           ui->progressBar_7,ui->progressBar_8,ui->progressBar_9,ui->progressBar_10,ui->progressBar_11,ui->progressBar_12,
                           ui->progressBar_13,ui->progressBar_14,ui->progressBar_15,ui->progressBar_16,ui->progressBar_17,ui->progressBar_18,
                           ui->progressBar_19,ui->progressBar_20,ui->progressBar_21,ui->progressBar_22,ui->progressBar_23,ui->progressBar_24,
                           ui->progressBar_25,ui->progressBar_26,ui->progressBar_27,ui->progressBar_28,ui->progressBar_29,ui->progressBar_30,
                           ui->progressBar_31,ui->progressBar_32,ui->progressBar_33,ui->progressBar_34};
    Checkboxlist        = {ui->checkBox_9,ui->checkBox_10,ui->checkBox_11,ui->checkBox_12,ui->checkBox_13,ui->checkBox_14,
                           ui->checkBox_15,ui->checkBox_16,ui->checkBox_17,ui->checkBox_18,ui->checkBox_19,ui->checkBox_20,
                           ui->checkBox_21,ui->checkBox_22,ui->checkBox_23,ui->checkBox_24,ui->checkBox_25,ui->checkBox_26,
                           ui->checkBox_27,ui->checkBox_28,ui->checkBox_29,ui->checkBox_30,ui->checkBox_31,ui->checkBox_32,
                           ui->checkBox_33,ui->checkBox_34,ui->checkBox_35,ui->checkBox_36,ui->checkBox_37,ui->checkBox_38,
                           ui->checkBox_39,ui->checkBox_40,ui->checkBox_41,ui->checkBox_42};
    Lineeditlist        = {ui->lineEdit,ui->lineEdit_2,ui->lineEdit_3,ui->lineEdit_4,ui->lineEdit_5,ui->lineEdit_6,ui->lineEdit_7,ui->lineEdit_8,
                           ui->lineEdit_9,ui->lineEdit_10,ui->lineEdit_11,ui->lineEdit_12,ui->lineEdit_13,ui->lineEdit_14,ui->lineEdit_15,ui->lineEdit_16,
                           ui->lineEdit_17,ui->lineEdit_18,ui->lineEdit_19,ui->lineEdit_20,ui->lineEdit_21,ui->lineEdit_22,ui->lineEdit_23,ui->lineEdit_24,
                           ui->lineEdit_25,ui->lineEdit_26,ui->lineEdit_27,ui->lineEdit_28,ui->lineEdit_29,ui->lineEdit_30,ui->lineEdit_31,ui->lineEdit_32,
                           ui->lineEdit_33,ui->lineEdit_34};
}

void Channel34::Setsetting(QString path)
{
    Settingpath = path;
    Loadsetting();
    Enablelineedit(Serial->isOpen());
}

/*  set setting path;*/

void Channel34::Closechannel01()
{
    emit Signalcd("close001");
}

/*  close gtk relay channel 1;*/

void Channel34::Closechannel02()
{
    emit Signalcd("close002");
}

/*  close gtk relay channel 2;*/

void Channel34::Closechannel03()
{
    emit Signalcd("close003");
}

/*  close gtk relay channel 3;*/

void Channel34::Closechannel04()
{
    emit Signalcd("close004");
}

/*  close gtk relay channel 4;*/

void Channel34::Closechannel05()
{
    emit Signalcd("close005");
}

/*  close gtk relay channel 5;*/

void Channel34::Closechannel06()
{
    emit Signalcd("close006");
}

/*  close gtk relay channel 6;*/

void Channel34::Closechannel07()
{
    emit Signalcd("close007");
}

/*  close gtk relay channel 7;*/

void Channel34::Closechannel08()
{
    emit Signalcd("close008");
}

/*  close gtk relay channel 8;*/

void Channel34::Closechannel09()
{
    emit Signalcd("close009");
}

/*  close gtk relay channel 9;*/

void Channel34::Closechannel10()
{
    emit Signalcd("close010");
}

/*  close gtk relay channel 10;*/

void Channel34::Closechannel11()
{
    emit Signalcd("close011");
}

/*  close gtk relay channel 11;*/

void Channel34::Closechannel12()
{
    emit Signalcd("close012");
}

/*  close gtk relay channel 12;*/

void Channel34::Closechannel13()
{
    emit Signalcd("close013");
}

/*  close gtk relay channel 13;*/

void Channel34::Closechannel14()
{
    emit Signalcd("close014");
}

/*  close gtk relay channel 14;*/

void Channel34::Closechannel15()
{
    emit Signalcd("close015");
}

/*  close gtk relay channel 15;*/

void Channel34::Closechannel16()
{
    emit Signalcd("close016");
}

/*  close gtk relay channel 16;*/

void Channel34::Closechannel17()
{
    emit Signalcd("close017");
}

/*  close gtk relay channel 17;*/

void Channel34::Closechannel18()
{
    emit Signalcd("close018");
}

/*  close gtk relay channel 18;*/

void Channel34::Closechannel19()
{
    emit Signalcd("close019");
}

/*  close gtk relay channel 19;*/

void Channel34::Closechannel20()
{
    emit Signalcd("close020");
}

/*  close gtk relay channel 20;*/

void Channel34::Closechannel21()
{
    emit Signalcd("close021");
}

/*  close gtk relay channel 21;*/

void Channel34::Closechannel22()
{
    emit Signalcd("close022");
}

/*  close gtk relay channel 22;*/

void Channel34::Closechannel23()
{
    emit Signalcd("close023");
}

/*  close gtk relay channel 23;*/

void Channel34::Closechannel24()
{
    emit Signalcd("close024");
}

/*  close gtk relay channel 24;*/

void Channel34::Closechannel25()
{
    emit Signalcd("close025");
}

/*  close gtk relay channel 25;*/

void Channel34::Closechannel26()
{
    emit Signalcd("close026");
}

/*  close gtk relay channel 26;*/

void Channel34::Closechannel27()
{
    emit Signalcd("close027");
}

/*  close gtk relay channel 27;*/

void Channel34::Closechannel28()
{
    emit Signalcd("close028");
}

/*  close gtk relay channel 28;*/

void Channel34::Closechannel29()
{
    emit Signalcd("close029");
}

/*  close gtk relay channel 29;*/

void Channel34::Closechannel30()
{
    emit Signalcd("close030");
}

/*  close gtk relay channel 30;*/

void Channel34::Closechannel31()
{
    emit Signalcd("close031");
}

/*  close gtk relay channel 31;*/

void Channel34::Closechannel32()
{
    emit Signalcd("close032");
}

/*  close gtk relay channel 32;*/

void Channel34::Closechannel33()
{
    emit Signalcd("close033");
}

/*  close gtk relay channel 33;*/

void Channel34::Closechannel34()
{
    emit Signalcd("close034");
}

/*  close gtk relay channel 34;*/

void Channel34::Openchannel01()
{
    emit Signalcd("open001");
}

/*  open gtk relay channel 1;*/

void Channel34::Openchannel02()
{
    emit Signalcd("open002");
}

/*  open gtk relay channel 2;*/

void Channel34::Openchannel03()
{
    emit Signalcd("open003");
}

/*  open gtk relay channel 3;*/

void Channel34::Openchannel04()
{
    emit Signalcd("open004");
}

/*  open gtk relay channel 4;*/

void Channel34::Openchannel05()
{
    emit Signalcd("open005");
}

/*  open gtk relay channel 5;*/

void Channel34::Openchannel06()
{
    emit Signalcd("open006");
}

/*  open gtk relay channel 6;*/

void Channel34::Openchannel07()
{
    emit Signalcd("open007");
}

/*  open gtk relay channel 7;*/

void Channel34::Openchannel08()
{
    emit Signalcd("open008");
}

/*  open gtk relay channel 8;*/

void Channel34::Openchannel09()
{
    emit Signalcd("open009");
}

/*  open gtk relay channel 9;*/

void Channel34::Openchannel10()
{
    emit Signalcd("open010");
}

/*  open gtk relay channel 10;*/

void Channel34::Openchannel11()
{
    emit Signalcd("open011");
}

/*  open gtk relay channel 11;*/

void Channel34::Openchannel12()
{
    emit Signalcd("open012");
}

/*  open gtk relay channel 12;*/

void Channel34::Openchannel13()
{
    emit Signalcd("open013");
}

/*  open gtk relay channel 13;*/

void Channel34::Openchannel14()
{
    emit Signalcd("open014");
}

/*  open gtk relay channel 14;*/

void Channel34::Openchannel15()
{
    emit Signalcd("open015");
}

/*  open gtk relay channel 15;*/

void Channel34::Openchannel16()
{
    emit Signalcd("open016");
}

/*  open gtk relay channel 16;*/

void Channel34::Openchannel17()
{
    emit Signalcd("open017");
}

/*  open gtk relay channel 17;*/

void Channel34::Openchannel18()
{
    emit Signalcd("open018");
}

/*  open gtk relay channel 18;*/

void Channel34::Openchannel19()
{
    emit Signalcd("open019");
}

/*  open gtk relay channel 19;*/

void Channel34::Openchannel20()
{
    emit Signalcd("open020");
}

/*  open gtk relay channel 20;*/

void Channel34::Openchannel21()
{
    emit Signalcd("open021");
}

/*  open gtk relay channel 21;*/

void Channel34::Openchannel22()
{
    emit Signalcd("open022");
}

/*  open gtk relay channel 22;*/

void Channel34::Openchannel23()
{
    emit Signalcd("open023");
}

/*  open gtk relay channel 23;*/

void Channel34::Openchannel24()
{
    emit Signalcd("open024");
}

/*  open gtk relay channel 24;*/

void Channel34::Openchannel25()
{
    emit Signalcd("open025");
}

/*  open gtk relay channel 25;*/

void Channel34::Openchannel26()
{
    emit Signalcd("open026");
}

/*  open gtk relay channel 26;*/

void Channel34::Openchannel27()
{
    emit Signalcd("open027");
}

/*  open gtk relay channel 27;*/

void Channel34::Openchannel28()
{
    emit Signalcd("open028");
}

/*  open gtk relay channel 28;*/

void Channel34::Openchannel29()
{
    emit Signalcd("open029");
}

/*  open gtk relay channel 29;*/

void Channel34::Openchannel30()
{
    emit Signalcd("open030");
}

/*  open gtk relay channel 30;*/

void Channel34::Openchannel31()
{
    emit Signalcd("open031");
}

/*  open gtk relay channel 31;*/

void Channel34::Openchannel32()
{
    emit Signalcd("open032");
}

/*  open gtk relay channel 32;*/

void Channel34::Openchannel33()
{
    emit Signalcd("open033");
}

/*  open gtk relay channel 33;*/


void Channel34::Openchannel34()
{
    emit Signalcd("open034");
}

/*  open gtk relay channel 34;*/

void Channel34::Emitdisplaylog(QString direction,QString strtlog,QString strllog)
{
    emit Signalca(direction,strtlog,strllog);
}

/*  emit signal for dislpaylog function;*/

void Channel34::Emitsignalsbslot(QString strcommand)
{
    emit Signalcb(strcommand);
}

/*  emit signal for thread write serial function;*/

void Channel34::Emitsignalscslot()
{
    emit Signalcc();
}

/*  emit signal for thread finished;*/

void Channel34::Emitenablerelaybutton()
{
    emit Signalce();
}

/*  emit signal for enable button;*/

void Channel34::Savecurrenttext()
{
    SuperC->Writeonlyfile(Settingpath,"34" + Spliter);
    QString currenttext = "";
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        currenttext.append(Lineeditlist.at(i)->text() + Spliter);
    }
    SuperC->Appendfile(Settingpath,currenttext);
}

/*  emit signal for thread finished;*/

void Channel34::Checklineedittext(QString text)
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

void Channel34::Loadsetting()
{
    QStringList textlist = SuperC->Readonlyfile(Settingpath).split(Spliter);
    if(textlist.count() >= 35)
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

void Channel34::Enablelineedit(bool boola)
{
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        Lineeditlist.at(i)->setEnabled(boola);
    }
}

/*  enable lineedit;*/
