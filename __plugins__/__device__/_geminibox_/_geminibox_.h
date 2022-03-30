#ifndef _GEMINIBOX__H
#define _GEMINIBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__superserial__/_superserial_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "_geminibox__global.h"
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

    SuperSerial *SuperS                 = nullptr;
    ModuleA *Modulea                    = nullptr;
    ModuleB *Moduleb                    = nullptr;
    QStringList Serialnamelist          = {};
    QList<QWidget*> Connectwidgetet     = {};
    QList<QWidget*> Connectwidgetef     = {};
    QList<QWidget*> Disconnectwidgetet  = {};
    QList<QWidget*> Disconnectwidgetef  = {};
    QSerialPort *Serial                 = nullptr;
    ScanSerialPort *Threadsa            = nullptr;
    QTimer *Timerca                     = nullptr;
    SerialThread *Threadta              = nullptr;
    SerialThread *Threadtb              = nullptr;
    SerialThread *Threadtc              = nullptr;
    SerialThread *Threadtd              = nullptr;
    SerialThread *Threadte              = nullptr;
    SuperLogger *Logger                 = nullptr;

private slots:

    /*  main function*/

    void Init();

    void Objectinit();

    void Timerinit();

    void Widgetlistinit();

    void Getserialport();

    bool Enableconnectbutton();

    void Connectserialport();

    void Disconnectserialport();

    void Geminicommand(
            QString strcommand);

    void Help();

    void Checkversion();

    void Runtxtest();

    void Startrxtest();

    void Endrxtest();

    void Enableruntxtest();

    void Enablestartrxtest();

    void Scangeminiport();

    void Signalsbslot(
            QString strcommand);

    void Signalscslot();

    void Timercaslot();

    void Signalttaslot();

    void Signaltfaslot();

    void Signalttbslot();

    void Signaltfbslot();

    void Signalttcslot();

    void Signaltfcslot();

    void Signalttdslot();

    void Signaltfdslot();

    void Signaltteslot();

    void Signaltfeslot();

};

#endif // _GEMINIBOX__H
