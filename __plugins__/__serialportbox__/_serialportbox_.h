#ifndef _SERIALPORTBOX__H
#define _SERIALPORTBOX__H
#define _SERIALPORTBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superserial__/_superserial_.h"
#include "__supersender__/_supersender_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_serialportmodulea_.h"
#include "__module__/_serialportmoduleb_.h"

/**************interface****************/
class _SERIALPORTBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class serialportbox new instance pointer;*/
};

class SerialPortBox : public SuperTab
{
    Q_OBJECT

public:

    SerialPortBox(
            QWidget *parent = nullptr);

    ~SerialPortBox();

private:

    SuperSerial *Serial                     = nullptr;
    SerialPortModuleA *Modulea              = nullptr;
    SerialPortModuleB *Moduleb              = nullptr;
    QStringList Serialnamelist              = {};
    QList<QWidget*> Connectwidgetet         = {};
    QList<QWidget*> Connectwidgetef         = {};
    QList<QWidget*> Disconnectwidgetef      = {};
    QList<QWidget*> Disconnectwidgetet      = {};
    QSerialPort *Serialport                 = nullptr;
    QTimer *Timerca                         = nullptr;
    SuperLogger *Logger                     = nullptr;
    QList<SuperSender*> Senderboxlist       = {};
    QStringList Stringlist                  = {};
    QString Cachefile                       = "./__depycache__/__serialport__/_defaultsetting_.ini";
    QString Spliter                         = "<split>";

private slots:

    /*  main function*/
    void init();

    void parameterInit();

    void objectInit();

    void timerInit();

    void widgetListInit();

    void getSerialPort();

    void enableSenderBox(
            bool boola);

    void connectSerialPort();

    void disconnectSerialPort();

    void enableAddn();

    void enableAddr();

    void changeTypea();

    void changeTypeb();

    bool enableConnectButton();

    void readyReadSlot();

    void writeApi(
            QLineEdit* lineedit);

    void recordText();

    void timerCaSlot();

    void changeTypeApi(
            QCheckBox* checkboxtype,
            QString strtlog,
            QString strllog,
            bool boola,
            bool boolb,
            bool boolc);

    void adjustSenderBox();

};

#endif // _SERIALPORTBOX__H
