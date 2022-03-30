#ifndef _SERIALPORTBOX__H
#define _SERIALPORTBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superserial__/_superserial_.h"
#include "__supersender__/_supersender_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "_serialportbox__global.h"

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

    SuperSerial *SuperS                     = nullptr;
    ModuleA *Modulea                        = nullptr;
    ModuleB *Moduleb                        = nullptr;
    QStringList Serialnamelist              = {};
    QList<QWidget*> Connectwidgetet         = {};
    QList<QWidget*> Connectwidgetef         = {};
    QList<QWidget*> Disconnectwidgetef      = {};
    QList<QWidget*> Disconnectwidgetet      = {};
    QSerialPort *Serial                     = nullptr;
    QTimer *Timerca                         = nullptr;
    SuperLogger *Logger                     = nullptr;
    QList<SuperSender*> Senderboxlist       = {};
    QStringList Stringlist                  = {};
    QString Cachefile                       = "./__depycache__/__serialport__/_defaultsetting_.ini";
    QString Spliter                         = "<split>";

private slots:

    /*  main function*/

    void Init();

    void Parameterinit();

    void Objectinit();

    void Timerinit();

    void Widgetlistinit();

    void Getserialport();

    void Enablesenderbox(
            bool boola);

    void Connectserialport();

    void Disconnectserialport();

    void Enableaddn();

    void Enableaddr();

    void Changetypea();

    void Changetypeb();

    bool Enableconnectbutton();

    void Readyreadslot();

    void Writeapi(
            QLineEdit* lineedit);

    void Recordtext();

    void Timercaslot();

    void Changetypeapi(
            QCheckBox* checkboxtype,
            QString strtlog,
            QString strllog,
            bool boola,
            bool boolb,
            bool boolc);

    void Adjustsenderbox();

};

#endif // _SERIALPORTBOX__H
