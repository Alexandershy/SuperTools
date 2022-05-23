#ifndef _SUPERSERIAL__H
#define _SUPERSERIAL__H
#define _SUPERSERIAL__EXPORT Q_DECL_EXPORT
#define _SUPERSCANSERIAL__EXPORT Q_DECL_EXPORT
#define _SUPERSERIALTHREAD__EXPORT Q_DECL_EXPORT

#include "__supercore__/_supercore_.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>

class _SUPERSERIAL__EXPORT SuperSerial : public QObject
{
    Q_OBJECT

public:

    SuperSerial(
        QObject *parent = nullptr);

    ~SuperSerial();

public slots:

    /*  QSerialport */
    void getSerialPort(
            QStringList* listname,
            QComboBox* comboboxnamelist);

    void enableSerialComboBox(
            QStringList *namelist,
            QComboBox *comboboxnamelist,
            QComboBox* comboboxbaudrate);

    bool enableConnectButton(
            QComboBox* comboboxnamelist,
            QComboBox* comboboxbaudrate,
            QPushButton* pushbuttonconnect);

    void connectSerialPort(
            QSerialPort* seriala,
            QString strportname,
            int intbaudrate);

    void writeSerial(
            QCheckBox* checkboxstring,
            QCheckBox* checkboxaddr,
            QCheckBox* checkboxaddn,
            QSerialPort* seriala,
            QLineEdit* lineeditdata);

    QByteArray readDataStream(
            QSerialPort* serial,
            QCheckBox* checkboxstring);

    bool checkSerialDevice(
            QSerialPort* serial,
            QString strportname);

    void closeSerial(
            QSerialPort* seriala);

private:

    SuperCore *Core = nullptr;

};

class _SUPERSCANSERIAL__EXPORT SuperScanSerial : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    SuperScanSerial(
            QWidget* widget,
            QSerialPort* serialport,
            int baudrate,
            QString commanda,
            QString commandb,
            QCheckBox* checkboxstring,
            QLineEdit* lineedita,
            QString strbackvaluea,
            QString strbackvalueb);

    ~SuperScanSerial();

public slots:

    void run();

private slots:

    void init();

    void objectInit();

    void initRun();

    void connectSerialPort();

    void waitForBytes();

    void communicateWithSerialPorta(
            QString strport);

    void communicateWithSerialPortb(
            QString strport);

private:

    SuperSerial *Serial         = nullptr;
    QStringList Listname        = {};
    QSerialPort *Serialport     = nullptr;
    int Baudrate                = 0;
    int Timeout                 = 1000;
    int Inittime                = 0;
    int Bytesavailable          = 0;
    QString Commanda            = "";
    QString Commandb            = "";
    QCheckBox *Checkboxstring   = nullptr;
    QLineEdit *Lineedita        = nullptr;
    QString Strbackvaluea       = "";
    QString Strbackvalueb       = "";
    QString Result              = "";
    QWidget *Widget             = nullptr;
    QStringList Realportlist    = {};
    QString Realportstringa     = "no device ";
    QString Realportstringb     = "";

signals:

    void signalSa(
            QString direction,
            QString strtlog,
            QString strllog);

    void signalSb(
            QString);

    void signalSc();

};

class _SUPERSERIALTHREAD__EXPORT SuperSerialThread : public QThread
{
    Q_OBJECT

public:

    /*main function;*/
    SuperSerialThread(
            QSerialPort* serial,
            double timeout);

public slots:

    void run();

    void init();

private:

    QSerialPort* Serialport = nullptr;
    double Inittime         = 0;
    double Timeout          = 0;
    double Inittimeout      = 0;
    int Bytesavailable      = 0;

signals:

    void signalTt();

    void signalTf();

};

#endif // SUPERSERIAL_H
