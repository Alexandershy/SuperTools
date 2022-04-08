#ifndef _RELAYBOX__H
#define _RELAYBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__channel15__/_channel15_.h"
#include "__channel34__/_channel34_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superserial__/_superserial_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "__module__/_modulec_.h"
#include "_relaybox__global.h"
#include <QProgressBar>
#include <QTimer>

/**************interface****************/
class _RELAYBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class relaybox new instance pointer;*/
};

class RelayBox : public SuperTab
{
    Q_OBJECT

public:

    RelayBox(
        QWidget *parent = nullptr);

    ~RelayBox();

private:

    SuperSerial *SuperS                         = nullptr;
    QSerialPort *Serial                         = nullptr;
    ModuleA *Modulea                            = nullptr;
    ModuleB *Moduleb                            = nullptr;
    ModuleC *Modulec                            = nullptr;
    QTimer *Timerca                             = nullptr;
    QStringList Serialnamelist                  = {};
    QStringList *Gtkrelayclosecommand           = nullptr;
    QStringList *Gtkrelayclosebackvalue         = nullptr;
    QStringList *Gtkrelayopencommand            = nullptr;
    QStringList *Gtkrelayopenbackvalue          = nullptr;
    QList<QWidget*> *Relayconnectwidgetet       = nullptr;
    QList<QWidget*> Connectwidgetef             = {};
    QList<QWidget*> Connectwidgetet             = {};
    QList<QWidget*> Disconnectwidgetet          = {};
    QList<QWidget*> Disconnectwidgetef          = {};
    QList<QWidget*> *Relaydisconnectwidgetef    = nullptr;
    QList<QProgressBar*> *Progressbarlist       = nullptr;
    QList<QCheckBox*> *Checkboxlist             = nullptr;
    QList<QLineEdit*> *Lineeditlist             = nullptr;
    Channel15 *Channel15relay                   = nullptr;
    Channel34 *Channel34relay                   = nullptr;
    ScanSerialPort *Threadsa                    = nullptr;
    SerialThread *Threadta                      = nullptr;
    QFileInfo Fileinfo                          = {};
    QString Defaultsettingpath                  = "./__depycache__/__gtkrelay__/_defaultsetting_.ini";
    SuperLogger *Logger                         = nullptr;

private slots:

    /*  main function*/

    void Init();

    void Timerinit();

    void Widgetlistinit();

    void Objectinit();

    void Getserialport();

    bool Enableconnectbutton();

    void Enablescanportbutton();

    void Connectserialport();

    void Disconnectserialport();

    void Enablelineeditlist(
            QList<QLineEdit*>* lineeditlist,
            bool boola);

    void Resetallchannel();

    void Closeallchannel();

    void Openselectchannel();

    void Closeselectchannel();

    void Enablerelaybutton();

    QString Checkselectchannel();

    void Scanrelayport();

    void Selectrelaymodel();

    void Timercaslot();

    void Signalsbslot(
            QString strcommand);

    void Signalscslot();

    void Readyreadslot();

    void Readtimeoutslot();

    void Writecommand(
            QString strcommand);

    void Opreateallchannel(
            QStringList *listcommand);

    void Opreateselectchannel(
            QStringList *listcommand);

    void Operatorprogressbar(
            QString backvalue,
            QStringList *backvaluelist,
            int intlight);

    void Selectsetting();

    void Setsetting(
            QString file);

};

#endif // _RELAYBOX__H
