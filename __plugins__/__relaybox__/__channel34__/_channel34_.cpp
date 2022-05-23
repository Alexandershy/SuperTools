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
    connect(ui->pushButton_1,  &QPushButton::clicked,      this,   &Channel34::closeChannel01);
    connect(ui->pushButton_2,  &QPushButton::clicked,      this,   &Channel34::closeChannel02);
    connect(ui->pushButton_3,  &QPushButton::clicked,      this,   &Channel34::closeChannel03);
    connect(ui->pushButton_4,  &QPushButton::clicked,      this,   &Channel34::closeChannel04);
    connect(ui->pushButton_5,  &QPushButton::clicked,      this,   &Channel34::closeChannel05);
    connect(ui->pushButton_6,  &QPushButton::clicked,      this,   &Channel34::closeChannel06);
    connect(ui->pushButton_7,  &QPushButton::clicked,      this,   &Channel34::closeChannel07);
    connect(ui->pushButton_8,  &QPushButton::clicked,      this,   &Channel34::closeChannel08);
    connect(ui->pushButton_9,  &QPushButton::clicked,      this,   &Channel34::closeChannel09);
    connect(ui->pushButton_10, &QPushButton::clicked,      this,   &Channel34::closeChannel10);
    connect(ui->pushButton_11, &QPushButton::clicked,      this,   &Channel34::closeChannel11);
    connect(ui->pushButton_12, &QPushButton::clicked,      this,   &Channel34::closeChannel12);
    connect(ui->pushButton_13, &QPushButton::clicked,      this,   &Channel34::closeChannel13);
    connect(ui->pushButton_14, &QPushButton::clicked,      this,   &Channel34::closeChannel14);
    connect(ui->pushButton_15, &QPushButton::clicked,      this,   &Channel34::closeChannel15);
    connect(ui->pushButton_31, &QPushButton::clicked,      this,   &Channel34::closeChannel16);
    connect(ui->pushButton_33, &QPushButton::clicked,      this,   &Channel34::closeChannel17);
    connect(ui->pushButton_35, &QPushButton::clicked,      this,   &Channel34::closeChannel18);
    connect(ui->pushButton_37, &QPushButton::clicked,      this,   &Channel34::closeChannel19);
    connect(ui->pushButton_39, &QPushButton::clicked,      this,   &Channel34::closeChannel20);
    connect(ui->pushButton_41, &QPushButton::clicked,      this,   &Channel34::closeChannel21);
    connect(ui->pushButton_43, &QPushButton::clicked,      this,   &Channel34::closeChannel22);
    connect(ui->pushButton_45, &QPushButton::clicked,      this,   &Channel34::closeChannel23);
    connect(ui->pushButton_47, &QPushButton::clicked,      this,   &Channel34::closeChannel24);
    connect(ui->pushButton_49, &QPushButton::clicked,      this,   &Channel34::closeChannel25);
    connect(ui->pushButton_51, &QPushButton::clicked,      this,   &Channel34::closeChannel26);
    connect(ui->pushButton_53, &QPushButton::clicked,      this,   &Channel34::closeChannel27);
    connect(ui->pushButton_55, &QPushButton::clicked,      this,   &Channel34::closeChannel28);
    connect(ui->pushButton_57, &QPushButton::clicked,      this,   &Channel34::closeChannel29);
    connect(ui->pushButton_59, &QPushButton::clicked,      this,   &Channel34::closeChannel30);
    connect(ui->pushButton_61, &QPushButton::clicked,      this,   &Channel34::closeChannel31);
    connect(ui->pushButton_63, &QPushButton::clicked,      this,   &Channel34::closeChannel32);
    connect(ui->pushButton_65, &QPushButton::clicked,      this,   &Channel34::closeChannel33);
    connect(ui->pushButton_67, &QPushButton::clicked,      this,   &Channel34::closeChannel34);
    connect(ui->pushButton_16, &QPushButton::clicked,      this,   &Channel34::openChannel01);
    connect(ui->pushButton_17, &QPushButton::clicked,      this,   &Channel34::openChannel02);
    connect(ui->pushButton_18, &QPushButton::clicked,      this,   &Channel34::openChannel03);
    connect(ui->pushButton_19, &QPushButton::clicked,      this,   &Channel34::openChannel04);
    connect(ui->pushButton_20, &QPushButton::clicked,      this,   &Channel34::openChannel05);
    connect(ui->pushButton_21, &QPushButton::clicked,      this,   &Channel34::openChannel06);
    connect(ui->pushButton_22, &QPushButton::clicked,      this,   &Channel34::openChannel07);
    connect(ui->pushButton_23, &QPushButton::clicked,      this,   &Channel34::openChannel08);
    connect(ui->pushButton_24, &QPushButton::clicked,      this,   &Channel34::openChannel09);
    connect(ui->pushButton_25, &QPushButton::clicked,      this,   &Channel34::openChannel10);
    connect(ui->pushButton_26, &QPushButton::clicked,      this,   &Channel34::openChannel11);
    connect(ui->pushButton_27, &QPushButton::clicked,      this,   &Channel34::openChannel12);
    connect(ui->pushButton_28, &QPushButton::clicked,      this,   &Channel34::openChannel13);
    connect(ui->pushButton_29, &QPushButton::clicked,      this,   &Channel34::openChannel14);
    connect(ui->pushButton_30, &QPushButton::clicked,      this,   &Channel34::openChannel15);
    connect(ui->pushButton_32, &QPushButton::clicked,      this,   &Channel34::openChannel16);
    connect(ui->pushButton_34, &QPushButton::clicked,      this,   &Channel34::openChannel17);
    connect(ui->pushButton_36, &QPushButton::clicked,      this,   &Channel34::openChannel18);
    connect(ui->pushButton_38, &QPushButton::clicked,      this,   &Channel34::openChannel19);
    connect(ui->pushButton_40, &QPushButton::clicked,      this,   &Channel34::openChannel20);
    connect(ui->pushButton_42, &QPushButton::clicked,      this,   &Channel34::openChannel21);
    connect(ui->pushButton_44, &QPushButton::clicked,      this,   &Channel34::openChannel22);
    connect(ui->pushButton_46, &QPushButton::clicked,      this,   &Channel34::openChannel23);
    connect(ui->pushButton_48, &QPushButton::clicked,      this,   &Channel34::openChannel24);
    connect(ui->pushButton_50, &QPushButton::clicked,      this,   &Channel34::openChannel25);
    connect(ui->pushButton_52, &QPushButton::clicked,      this,   &Channel34::openChannel26);
    connect(ui->pushButton_54, &QPushButton::clicked,      this,   &Channel34::openChannel27);
    connect(ui->pushButton_56, &QPushButton::clicked,      this,   &Channel34::openChannel28);
    connect(ui->pushButton_58, &QPushButton::clicked,      this,   &Channel34::openChannel29);
    connect(ui->pushButton_60, &QPushButton::clicked,      this,   &Channel34::openChannel30);
    connect(ui->pushButton_62, &QPushButton::clicked,      this,   &Channel34::openChannel31);
    connect(ui->pushButton_64, &QPushButton::clicked,      this,   &Channel34::openChannel32);
    connect(ui->pushButton_66, &QPushButton::clicked,      this,   &Channel34::openChannel33);
    connect(ui->pushButton_68, &QPushButton::clicked,      this,   &Channel34::openChannel34);
    connect(ui->checkBox_9,    &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_10,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_11,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_12,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_13,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_14,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_15,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_16,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_17,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_18,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_19,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_20,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_21,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_22,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_23,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_24,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_25,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_26,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_27,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_28,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_29,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_30,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_31,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_32,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_33,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_34,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_35,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_36,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_37,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_38,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_39,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_40,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_41,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->checkBox_42,   &QCheckBox::stateChanged,   this,   &Channel34::emitEnableRelayButton);
    connect(ui->lineEdit,      &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit,      &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_2,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_2,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_3,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_3,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_4,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_4,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_5,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_5,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_6,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_6,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_7,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_7,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_8,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_8,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_9,    &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_9,    &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_10,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_10,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_11,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_11,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_12,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_12,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_13,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_13,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_14,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_14,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_15,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_15,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_16,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_16,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_17,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_17,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_18,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_18,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_19,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_19,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_20,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_20,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_21,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_21,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_22,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_22,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_23,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_23,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_24,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_24,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_25,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_25,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_26,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_26,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_27,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_27,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_28,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_28,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_29,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_29,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_30,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_30,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_31,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_31,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_32,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_32,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_33,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_33,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    connect(ui->lineEdit_34,   &QLineEdit::textChanged,    this,   &Channel34::checkLineEditText);
    connect(ui->lineEdit_34,   &QLineEdit::editingFinished,this,   &Channel34::saveCurrentText);
    init();

}

Channel34::~Channel34()
{
    Core->closeThread(Threadsa);
    delete ui;
}

void Channel34::init()
{
    objectInit();
    widgetListInit();
}

void Channel34::objectInit()
{
    Core = new SuperCore(this);
    Threadsa = new SuperScanSerial(Widget,Serial,9600,"close001","open001",Checkbox,Lineedit,"close1 OK","open1 OK");
    connect(Threadsa,&SuperScanSerial::signalSa,this,&Channel34::emitDisplayLog);
    connect(Threadsa,&SuperScanSerial::signalSb,this,&Channel34::emitSignalSbSlot);
    connect(Threadsa,&SuperScanSerial::signalSc,this,&Channel34::emitSignalScSlot);
}

void Channel34::widgetListInit()
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

void Channel34::setSetting(QString path)
{
    Settingpath = path;
    loadSetting();
    enableLineEdit(Serial->isOpen());
}

/*  set setting path;*/

void Channel34::closeChannel01()
{
    emit signalCd("close001");
}

/*  close gtk relay channel 1;*/

void Channel34::closeChannel02()
{
    emit signalCd("close002");
}

/*  close gtk relay channel 2;*/

void Channel34::closeChannel03()
{
    emit signalCd("close003");
}

/*  close gtk relay channel 3;*/

void Channel34::closeChannel04()
{
    emit signalCd("close004");
}

/*  close gtk relay channel 4;*/

void Channel34::closeChannel05()
{
    emit signalCd("close005");
}

/*  close gtk relay channel 5;*/

void Channel34::closeChannel06()
{
    emit signalCd("close006");
}

/*  close gtk relay channel 6;*/

void Channel34::closeChannel07()
{
    emit signalCd("close007");
}

/*  close gtk relay channel 7;*/

void Channel34::closeChannel08()
{
    emit signalCd("close008");
}

/*  close gtk relay channel 8;*/

void Channel34::closeChannel09()
{
    emit signalCd("close009");
}

/*  close gtk relay channel 9;*/

void Channel34::closeChannel10()
{
    emit signalCd("close010");
}

/*  close gtk relay channel 10;*/

void Channel34::closeChannel11()
{
    emit signalCd("close011");
}

/*  close gtk relay channel 11;*/

void Channel34::closeChannel12()
{
    emit signalCd("close012");
}

/*  close gtk relay channel 12;*/

void Channel34::closeChannel13()
{
    emit signalCd("close013");
}

/*  close gtk relay channel 13;*/

void Channel34::closeChannel14()
{
    emit signalCd("close014");
}

/*  close gtk relay channel 14;*/

void Channel34::closeChannel15()
{
    emit signalCd("close015");
}

/*  close gtk relay channel 15;*/

void Channel34::closeChannel16()
{
    emit signalCd("close016");
}

/*  close gtk relay channel 16;*/

void Channel34::closeChannel17()
{
    emit signalCd("close017");
}

/*  close gtk relay channel 17;*/

void Channel34::closeChannel18()
{
    emit signalCd("close018");
}

/*  close gtk relay channel 18;*/

void Channel34::closeChannel19()
{
    emit signalCd("close019");
}

/*  close gtk relay channel 19;*/

void Channel34::closeChannel20()
{
    emit signalCd("close020");
}

/*  close gtk relay channel 20;*/

void Channel34::closeChannel21()
{
    emit signalCd("close021");
}

/*  close gtk relay channel 21;*/

void Channel34::closeChannel22()
{
    emit signalCd("close022");
}

/*  close gtk relay channel 22;*/

void Channel34::closeChannel23()
{
    emit signalCd("close023");
}

/*  close gtk relay channel 23;*/

void Channel34::closeChannel24()
{
    emit signalCd("close024");
}

/*  close gtk relay channel 24;*/

void Channel34::closeChannel25()
{
    emit signalCd("close025");
}

/*  close gtk relay channel 25;*/

void Channel34::closeChannel26()
{
    emit signalCd("close026");
}

/*  close gtk relay channel 26;*/

void Channel34::closeChannel27()
{
    emit signalCd("close027");
}

/*  close gtk relay channel 27;*/

void Channel34::closeChannel28()
{
    emit signalCd("close028");
}

/*  close gtk relay channel 28;*/

void Channel34::closeChannel29()
{
    emit signalCd("close029");
}

/*  close gtk relay channel 29;*/

void Channel34::closeChannel30()
{
    emit signalCd("close030");
}

/*  close gtk relay channel 30;*/

void Channel34::closeChannel31()
{
    emit signalCd("close031");
}

/*  close gtk relay channel 31;*/

void Channel34::closeChannel32()
{
    emit signalCd("close032");
}

/*  close gtk relay channel 32;*/

void Channel34::closeChannel33()
{
    emit signalCd("close033");
}

/*  close gtk relay channel 33;*/

void Channel34::closeChannel34()
{
    emit signalCd("close034");
}

/*  close gtk relay channel 34;*/

void Channel34::openChannel01()
{
    emit signalCd("open001");
}

/*  open gtk relay channel 1;*/

void Channel34::openChannel02()
{
    emit signalCd("open002");
}

/*  open gtk relay channel 2;*/

void Channel34::openChannel03()
{
    emit signalCd("open003");
}

/*  open gtk relay channel 3;*/

void Channel34::openChannel04()
{
    emit signalCd("open004");
}

/*  open gtk relay channel 4;*/

void Channel34::openChannel05()
{
    emit signalCd("open005");
}

/*  open gtk relay channel 5;*/

void Channel34::openChannel06()
{
    emit signalCd("open006");
}

/*  open gtk relay channel 6;*/

void Channel34::openChannel07()
{
    emit signalCd("open007");
}

/*  open gtk relay channel 7;*/

void Channel34::openChannel08()
{
    emit signalCd("open008");
}

/*  open gtk relay channel 8;*/

void Channel34::openChannel09()
{
    emit signalCd("open009");
}

/*  open gtk relay channel 9;*/

void Channel34::openChannel10()
{
    emit signalCd("open010");
}

/*  open gtk relay channel 10;*/

void Channel34::openChannel11()
{
    emit signalCd("open011");
}

/*  open gtk relay channel 11;*/

void Channel34::openChannel12()
{
    emit signalCd("open012");
}

/*  open gtk relay channel 12;*/

void Channel34::openChannel13()
{
    emit signalCd("open013");
}

/*  open gtk relay channel 13;*/

void Channel34::openChannel14()
{
    emit signalCd("open014");
}

/*  open gtk relay channel 14;*/

void Channel34::openChannel15()
{
    emit signalCd("open015");
}

/*  open gtk relay channel 15;*/

void Channel34::openChannel16()
{
    emit signalCd("open016");
}

/*  open gtk relay channel 16;*/

void Channel34::openChannel17()
{
    emit signalCd("open017");
}

/*  open gtk relay channel 17;*/

void Channel34::openChannel18()
{
    emit signalCd("open018");
}

/*  open gtk relay channel 18;*/

void Channel34::openChannel19()
{
    emit signalCd("open019");
}

/*  open gtk relay channel 19;*/

void Channel34::openChannel20()
{
    emit signalCd("open020");
}

/*  open gtk relay channel 20;*/

void Channel34::openChannel21()
{
    emit signalCd("open021");
}

/*  open gtk relay channel 21;*/

void Channel34::openChannel22()
{
    emit signalCd("open022");
}

/*  open gtk relay channel 22;*/

void Channel34::openChannel23()
{
    emit signalCd("open023");
}

/*  open gtk relay channel 23;*/

void Channel34::openChannel24()
{
    emit signalCd("open024");
}

/*  open gtk relay channel 24;*/

void Channel34::openChannel25()
{
    emit signalCd("open025");
}

/*  open gtk relay channel 25;*/

void Channel34::openChannel26()
{
    emit signalCd("open026");
}

/*  open gtk relay channel 26;*/

void Channel34::openChannel27()
{
    emit signalCd("open027");
}

/*  open gtk relay channel 27;*/

void Channel34::openChannel28()
{
    emit signalCd("open028");
}

/*  open gtk relay channel 28;*/

void Channel34::openChannel29()
{
    emit signalCd("open029");
}

/*  open gtk relay channel 29;*/

void Channel34::openChannel30()
{
    emit signalCd("open030");
}

/*  open gtk relay channel 30;*/

void Channel34::openChannel31()
{
    emit signalCd("open031");
}

/*  open gtk relay channel 31;*/

void Channel34::openChannel32()
{
    emit signalCd("open032");
}

/*  open gtk relay channel 32;*/

void Channel34::openChannel33()
{
    emit signalCd("open033");
}

/*  open gtk relay channel 33;*/


void Channel34::openChannel34()
{
    emit signalCd("open034");
}

/*  open gtk relay channel 34;*/

void Channel34::emitDisplayLog(QString direction,QString strtlog,QString strllog)
{
    emit signalCa(direction,strtlog,strllog);
}

/*  emit signal for dislpaylog function;*/

void Channel34::emitSignalSbSlot(QString strcommand)
{
    emit signalCb(strcommand);
}

/*  emit signal for thread write serial function;*/

void Channel34::emitSignalScSlot()
{
    emit signalCc();
}

/*  emit signal for thread finished;*/

void Channel34::emitEnableRelayButton()
{
    emit signalCe();
}

/*  emit signal for enable button;*/

void Channel34::saveCurrentText()
{
    Core->writeOnlyFile(Settingpath,"34" + Spliter);
    QString currenttext = "";
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        currenttext.append(Lineeditlist.at(i)->text() + Spliter);
    }
    Core->appendFile(Settingpath,currenttext);
}

/*  emit signal for thread finished;*/

void Channel34::checkLineEditText(QString text)
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

void Channel34::loadSetting()
{
    QStringList textlist = Core->readOnlyFile(Settingpath).split(Spliter);
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
        messagbox->messageInit();
        for(int i = 0;i < Lineeditlist.count();i++)
        {
            Lineeditlist.at(i)->clear();
        }
    }
}

/*  load setting;*/

void Channel34::enableLineEdit(bool boola)
{
    for(int i = 0;i < Lineeditlist.count();i++)
    {
        Lineeditlist.at(i)->setEnabled(boola);
    }
}

/*  enable lineedit;*/
