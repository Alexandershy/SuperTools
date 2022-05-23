#ifndef _RELAYBOX__H
#define _RELAYBOX__H
#define _RELAYBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__channel15__/_channel15_.h"
#include "__channel34__/_channel34_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superserial__/_superserial_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__module__/_relaymodulea_.h"
#include "__module__/_relaymoduleb_.h"
#include "__module__/_relaymodulec_.h"
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

    SuperSerial *Serial                         = nullptr;
    QSerialPort *Serialport                     = nullptr;
    RelayModuleA *Modulea                       = nullptr;
    RelayModuleB *Moduleb                       = nullptr;
    RelayModuleC *Modulec                       = nullptr;
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
    SuperScanSerial *Threadsa                   = nullptr;
    SuperSerialThread *Threadta                 = nullptr;
    QFileInfo Fileinfo                          = {};
    QString Defaultsettingpath                  = "./__depycache__/__gtkrelay__/_defaultsetting_.ini";
    SuperLogger *Logger                         = nullptr;

private slots:

    /*  main function*/
    void init();

    void timerInit();

    void widgetListInit();

    void objectInit();

    void getSerialPort();

    bool enableConnectButton();

    void enableScanPortButton();

    void connectSerialPort();

    void disconnectSerialPort();

    void enableLineEditList(
            QList<QLineEdit*>* lineeditlist,
            bool boola);

    void resetAllChannel();

    void closeAllChannel();

    void openSelectChannel();

    void closeSelectChannel();

    void enableRelayButton();

    QString checkSelectChannel();

    void scanRelayPort();

    void selectRelayModel();

    void timerCaSlot();

    void signalSbSlot(
            QString strcommand);

    void signalScSlot();

    void readyReadSlot();

    void readTimeoutSlot();

    void writeCommand(
            QString strcommand);

    void opreateAllChannel(
            QStringList *listcommand);

    void opreateSelectChannel(
            QStringList *listcommand);

    void operatorProgressBar(
            QString backvalue,
            QStringList *backvaluelist,
            int intlight);

    void selectSetting();

    void setSetting(
            QString file);

};

#endif // _RELAYBOX__H
