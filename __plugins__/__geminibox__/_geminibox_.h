#ifndef _GEMINIBOX__H
#define _GEMINIBOX__H
#define _GEMINIBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__superserial__/_superserial_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_geminimodulea_.h"
#include "__module__/_geminimoduleb_.h"
#include <QTimer>

/**************interface****************/
class _GEMINIBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class geminibox new instance pointer;*/
};

class GeminiBox : public SuperTab
{
    Q_OBJECT

public:

    GeminiBox(
            QWidget *parent = nullptr);

    ~GeminiBox();

private:

    SuperSerial *Serial                 = nullptr;
    GeminiModuleA *Modulea              = nullptr;
    GeminiModuleB *Moduleb              = nullptr;
    QStringList Serialnamelist          = {};
    QList<QWidget*> Connectwidgetet     = {};
    QList<QWidget*> Connectwidgetef     = {};
    QList<QWidget*> Disconnectwidgetet  = {};
    QList<QWidget*> Disconnectwidgetef  = {};
    QSerialPort *Serialport             = nullptr;
    SuperScanSerial *Threadsa           = nullptr;
    QTimer *Timerca                     = nullptr;
    SuperSerialThread *Threadta         = nullptr;
    SuperSerialThread *Threadtb         = nullptr;
    SuperSerialThread *Threadtc         = nullptr;
    SuperSerialThread *Threadtd         = nullptr;
    SuperSerialThread *Threadte         = nullptr;
    SuperLogger *Logger                 = nullptr;

private slots:

    /*  main function*/
    void init();

    void objectInit();

    void timerInit();

    void widgetListInit();

    void getSerialPort();

    bool enableConnectButton();

    void connectSerialPort();

    void disconnectSerialPort();

    void geminiCommand(
            QString strcommand);

    void help();

    void checkVersion();

    void runTxTest();

    void startRxTest();

    void endRxTest();

    void enableRunTxTest();

    void enableStartRxTest();

    void scanGeminiPort();

    void signalSbSlot(
            QString strcommand);

    void signalScSlot();

    void timerCaSlot();

    void signalTtaSlot();

    void signalTfaSlot();

    void signalTtbSlot();

    void signalTfbSlot();

    void signalTtcSlot();

    void signalTfcSlot();

    void signalTtdSlot();

    void signalTfdSlot();

    void signalTteSlot();

    void signalTfeSlot();

};

#endif // _GEMINIBOX__H
