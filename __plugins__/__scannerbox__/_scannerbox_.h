#ifndef _SCANNERBOX__H
#define _SCANNERBOX__H
#define _SCANNERBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superserial__/_superserial_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__module__/_scannermodulea_.h"
#include "__module__/_scannermoduleb_.h"
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

    ScannerBox(
        QWidget *parent = nullptr);

    ~ScannerBox();

private:

    SuperSerial *Serial                 = nullptr;
    ScannerModuleA *Modulea             = nullptr;
    ScannerModuleB *Moduleb             = nullptr;
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
    QSerialPort *Serialport             = nullptr;
    QTimer *Timerca                     = nullptr;
    QTimer *Timercb                     = nullptr;
    ScanPort *Threadsa                  = nullptr;
    SuperLogger *Logger                 = nullptr;

private slots:

    /*  main function*/
    void init();

    void objectInit();

    void timerInit();

    void widgetListInit();

    void pictureInit();

    void functionInit();

    void sliderInit();

    void getSerialPort();

    bool enableConnectButton();

    void connectSerialPort();

    void disconnectSerialPort();

    void openScanner();

    void closeScanner();

    void scanScannerPort();

    void displayScanner(
            bool boola,
            QString strpicturepath,
            QStringList Scanneritem);

    void displayScannerPicture();

    void displayFunction(
            QString strpicturepath);

    void displayScannerFunction();

    void timerCaSlot();

    void timerCbSlot();

    void signalSbSlot();

    void readyReadSlot();

    void changePictureSize();

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
    void init();

    void objectInit();

    void initRun();

    void connectSerialPort();

    void receiveData();

    void releaseObject(
            QVector <QSerialPort*> *seriallist);

private:

    SuperSerial *Serial                 = nullptr;
    QSerialPort* Serialport             = nullptr;
    int Baudrate                        = 0;
    QString Serialportname              = "no device ";
    QStringList Listname                = {};
    QVector <QSerialPort*> Seriallista  = {};
    QVector <QSerialPort*> Seriallistb  = {};

signals:

    void signalSa(
            QString direction,
            QString strtlog,
            QString strllog);

    void signalSb();

};

#endif // _SCANNERBOX__H
