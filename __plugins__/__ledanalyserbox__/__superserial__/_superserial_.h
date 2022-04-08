
#ifndef SUPERSERIAL_H
#define SUPERSERIAL_H

#include "__supercore__/_supercore_.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>

class SuperSerial : QObject
{
    Q_OBJECT

public:

    SuperSerial(
        QObject *parent = nullptr);

    ~SuperSerial();

public slots:

    /*  QSerialport */

    void Getserialport(
            QStringList* listname,
            QComboBox* comboboxnamelist);

    void Enableserialcombobox(
            QStringList *namelist,
            QComboBox *comboboxnamelist,
            QComboBox* comboboxbaudrate);

    bool Enableconnectbutton(
            QComboBox* comboboxnamelist,
            QComboBox* comboboxbaudrate,
            QPushButton* pushbuttonconnect);

    void Connectserialport(
            QSerialPort* seriala,
            QString strportname,
            int intbaudrate);

    void Writeserial(
            QCheckBox* checkboxstring,
            QCheckBox* checkboxaddr,
            QCheckBox* checkboxaddn,
            QSerialPort* seriala,
            QLineEdit* lineeditdata);

    QByteArray Readdatastream(
            QSerialPort* serial,
            QCheckBox* checkboxstring);

    bool Checkserialdevice(
            QSerialPort* serial,
            QString strportname);

    void Closeserial(
            QSerialPort* seriala);

private:

    SuperCore *SuperC = nullptr;

};

class ScanSerialPort : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    ScanSerialPort(
            QWidget* widget,
            QSerialPort* seriala,
            int baudrate,
            QString commanda,
            QString commandb,
            QCheckBox* checkboxstring,
            QLineEdit* lineedita,
            QString strbackvaluea,
            QString strbackvalueb);

    ~ScanSerialPort();

public slots:

    void run();

private slots:

    void Init();

    void Objectinit();

    void Initrun();

    void Connectserialport();

    void Waitforbytes();

    void Communicatewithserialporta(
            QString strport);

    void Communicatewithserialportb(
            QString strport);

private:

    SuperSerial *SuperS         = nullptr;
    QStringList Listname        = {};
    QSerialPort *Seriala        = nullptr;
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

    void Signalsa(
            QString direction,
            QString strtlog,
            QString strllog);

    void Signalsb(
            QString);

    void Signalsc();

};

class SerialThread : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    SerialThread(
            QSerialPort* serial,
            double timeout);

public slots:

    void run();

    void Init();

private:

    QSerialPort* Serial = nullptr;
    double Inittime     = 0;
    double Timeout      = 0;
    double Inittimeout  = 0;
    int Bytesavailable  = 0;

signals:

    void Signaltt();

    void Signaltf();

};

#endif // SUPERSERIAL_H
