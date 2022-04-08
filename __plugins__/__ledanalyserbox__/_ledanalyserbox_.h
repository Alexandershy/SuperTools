#ifndef _LEDANALYSERBOX__H
#define _LEDANALYSERBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__superserial__/_superserial_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "_ledanalyserbox__global.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include <QTimer>

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

    SuperSerial *SuperS             = nullptr;
    ModuleA *Modulea                = nullptr;
    ModuleB *Moduleb                = nullptr;
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
    QSerialPort *Serial             = nullptr;
    QTimer *Timerca                 = nullptr;
    Analysisled *Threadaa           = nullptr;
    ScanSerialPort *Threadsa        = nullptr;
    SerialThread *Threadta          = nullptr;
    SerialThread *Threadtb          = nullptr;
    SuperLogger *Logger             = nullptr;

private slots:

    /*main function;*/

    void Init();

    void Objectinit();

    void Timerinit();

    void Widgetlistinit();

    void Selectledanalyserinfo();

    void Resetfunction();

    void Ledanalyserinfo();

    void Enableledanalyserfunction();

    void Getserialport();

    void Connectserialport();

    bool Enableconnectbutton();

    void Enablescanportbutton();

    void Disconnectserialport();

    void Enablepwm();

    void Startdisplayvalue();

    QString Setcommandlineedit();

    void Stopdisplayvalue();

    void ledanalysercommandapi(
            QString strcommand);

    void Systemcommand();

    void Scanledport();

    QStringList Processresult(
            QString strresult);

    QStringList Checkboxenabled();

    void Resetlabelvalue();

    void Timercaslot();

    void Signalttaslot();

    void Signaltfaslot();

    void Signalttbslot();

    void Signaltfbslot();

    void Signalaaslot(
            int counts);

    void Signalabslot(
            int counts);

    void Signalsbslot(
            QString strcommand);

    void Signalscslot();

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

    SuperSerial SuperS;
    QSerialPort *Serial         = nullptr;
    double Timeout              = 0;
    double Inittime             = 0;
    int BytesAvailable          = 0;
    QCheckBox *Checkboxstring   = nullptr;
    QStringList *Channellist    = nullptr;

signals:

    void Signalaa(
            int counts);

    void Signalab(
            int counts);

    void Signalac();

    void Signalad();
};

#endif // _LEDANALYSERBOX__H
