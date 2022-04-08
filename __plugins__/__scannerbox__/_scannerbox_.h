#ifndef _SCANNERBOX__H
#define _SCANNERBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superserial__/_superserial_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "_scannerbox__global.h"
#include <QTimer>

/**************interface****************/
class _SCANNERBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class scannerbox new instance pointer;*/
};

class ScanPort;

class ScannerBox : public SuperTab
{
    Q_OBJECT

public:

    ScannerBox(QWidget *parent = nullptr);

    ~ScannerBox();

private:

    SuperSerial *SuperS                 = nullptr;
    ModuleA *Modulea                    = nullptr;
    ModuleB *Moduleb                    = nullptr;
    QList<QWidget*> Connectwidgetet     = {};
    QList<QWidget*> Connectwidgetef     = {};
    QList<QWidget*> Disconnectwidgetet  = {};
    QList<QWidget*> Disconnectwidgetef  = {};
    QStringList Serialnamelist          = {};
    QStringList Scannerpicturelist      = {};
    QStringList Fs361415rpicturelist    = {};
    QStringList Honeywellpicturelist    = {};
    QStringList Scannerfunction         = {};
    QStringList Fs361415rfunction       = {};
    QStringList Honeywellfunction       = {};
    QVector <QStringList> Picture       = {};
    QVector <QStringList> Function      = {};
    QPixmap Pixmap                      = {};
    int Slidermaxvalue                  = 0;
    QSize Labelsize                     = {0,0};
    QSerialPort *Serial                 = nullptr;
    QTimer *Timerca                     = nullptr;
    QTimer *Timercb                     = nullptr;
    ScanPort *Threadsa                  = nullptr;
    SuperLogger *Logger                 = nullptr;

private slots:

    /*  main function*/

    void Init();

    void Objectinit();

    void Timerinit();

    void Widgetlistinit();

    void Pictureinit();

    void Functioninit();

    void Sliderinit();

    void Getserialport();

    bool Enableconnectbutton();

    void Connectserialport();

    void Disconnectserialport();

    void Openscanner();

    void Closescanner();

    void Scanscannerport();

    void Displayscanner(
            bool boola,
            QString strpicturepath,
            QStringList Scanneritem);

    void Displayscannerpicture();

    void Displayfunction(
            QString strpicturepath);

    void Displayscannerfunction();

    void Timercaslot();

    void Timercbslot();

    void Signalsbsolt();

    void Readyreadslot();

    void Changepicturesize();

};

class ScanPort : public QThread
{
    Q_OBJECT

public:

    ScanPort(
            int baudrate);

    ~ScanPort();

public slots:

    void run();

private slots:

    /*  main function*/

    void Init();

    void Objectinit();

    void Initrun();

    void Connectserialport();

    void Receivedata();

    void Releaseobject(
            QVector <QSerialPort*> *Seriallist);

private:

    SuperSerial *SuperS                 = nullptr;
    QSerialPort* Serial                 = nullptr;
    int Baudrate                        = 0;
    QString Serialportname              = "no device ";
    QStringList Listname                = {};
    QVector <QSerialPort*> Seriallista  = {};
    QVector <QSerialPort*> Seriallistb  = {};

signals:

    void Signalsa(
            QString direction,
            QString strtlog,
            QString strllog);

    void Signalsb();

};

#endif // _SCANNERBOX__H
