#ifndef _LEDANALYSERBOX__H
#define _LEDANALYSERBOX__H
#define _LEDANALYSERBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__superserial__/_superserial_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_ledanalysermodulea_.h"
#include "__module__/_ledanalysermoduleb_.h"
#include <QTimer>
#include <QLabel>

/**************interface****************/
class _LEDANALYSERBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class ledanalyserbox new instance pointer;*/
};

class Analysisled;

class LedAnalyserBox : public SuperTab
{
    Q_OBJECT

public:

    LedAnalyserBox(
            QWidget *parent = nullptr);

    ~LedAnalyserBox();

private:

    SuperSerial *Serial             = nullptr;
    LedAnalyserModuleA *Modulea     = nullptr;
    LedAnalyserModuleB *Moduleb     = nullptr;
    int Channels                    = 0;
    QString Model                   = "";
    QString Function                = "";
    int Baudrate                    = 57600;
    QString Command                 = "getwi";
    bool Rgbbool                    = false;
    int Index[2]                    = {0,0};
    QList<QLabel*> Titlelable       = {};
    QList<QLabel*> Valuelabel       = {};
    QList<QCheckBox*> Checkbox      = {};
    QStringList Serialnamelist      = {};
    QStringList Systemcommandlist   = {"null","help","getversion","getHW","getSerial"};
    QStringList Channelrule         = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20"};
    QStringList Channellist         = {};
    QSerialPort *Serialport         = nullptr;
    QTimer *Timerca                 = nullptr;
    Analysisled *Threadaa           = nullptr;
    SuperScanSerial *Threadsa       = nullptr;
    SuperSerialThread *Threadta     = nullptr;
    SuperSerialThread *Threadtb     = nullptr;
    SuperLogger *Logger             = nullptr;

private slots:

    /*main function;*/
    void init();

    void objectInit();

    void timerInit();

    void widgetListInit();

    void selectLedAnalyserInfo();

    void resetFunction();

    void ledAnalyserInfo();

    void enableLedAnalyserFunction();

    void getSerialPort();

    void connectSerialPort();

    bool enableConnectButton();

    void enableScanPortButton();

    void disconnectSerialPort();

    void enablePwm();

    void startDisplayValue();

    QString setCommandLineEdit();

    void stopDisplayValue();

    void ledAnalyserCommandApi(
            QString strcommand);

    void systemCommand();

    void scanLedPort();

    QStringList processResult(
            QString strresult);

    QStringList checkBoxEnabled();

    void resetLabelValue();

    void timerCaSlot();

    void signalTtaSlot();

    void signalTfaSlot();

    void signalTtbSlot();

    void signalTfbSlot();

    void signalAaSlot(
            int counts);

    void signalAbSlot(
            int counts);

    void signalSbSlot(
            QString strcommand);

    void signalScSlot();

};

class Analysisled : public QThread
{
    Q_OBJECT

public:

    Analysisled(
            QSerialPort* serial,
            double timeout,
            QCheckBox* checkboxstring,
            QStringList* channellist);

private slots:

    /*main function;*/
    void run();

private:

    SuperSerial *Serial         = nullptr;
    QSerialPort *Serialport     = nullptr;
    double Timeout              = 0;
    double Inittime             = 0;
    int BytesAvailable          = 0;
    QCheckBox *Checkboxstring   = nullptr;
    QStringList *Channellist    = nullptr;

signals:

    void signalAa(
            int counts);

    void signalAb(
            int counts);

    void signalAc();

    void signalAd();
};

#endif // _LEDANALYSERBOX__H
