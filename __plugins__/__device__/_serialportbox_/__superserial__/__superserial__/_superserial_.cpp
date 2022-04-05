#include "_superserial_.h"

SuperSerial::SuperSerial(QObject *parent)
    : QObject(parent)
{
    SuperC = new SuperCore(this);
}

SuperSerial::~SuperSerial()
{

}

//*************************************************QSerialport*****************************************************//

void SuperSerial::Getserialport(QStringList *listname,QComboBox* comboboxnamelist)
{
    QString serialname;
    listname->clear();
    comboboxnamelist->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        serialname = info.description() + " " + info.portName();
        listname->append(info.portName());
        comboboxnamelist->addItem(serialname);
    }
}

/*  get windows system serial port name and description, add them to combobox;*/

void SuperSerial::Enableserialcombobox(QStringList *namelist,QComboBox *comboboxnamelist,QComboBox* comboboxbaudrate)
{
    if(namelist->isEmpty())
    {
        comboboxnamelist->setEnabled(false);
        comboboxbaudrate->setEnabled(false);
    }
    else
    {
        comboboxnamelist->setEnabled(true);
        comboboxbaudrate->setEnabled(true);
    }
}

/*  is enable serial port name and baudrate combobox;*/

bool SuperSerial::Enableconnectbutton(QComboBox* comboboxnamelist,QComboBox* comboboxbaudrate,QPushButton* pushbuttonconnect)
{
    QString serialname = comboboxnamelist->currentText();
    bool result = comboboxbaudrate->currentText().toInt();
    if(serialname.contains("COM") && !serialname.contains("Select") && result)
    {
        pushbuttonconnect->setEnabled(true);
        return true;
    }
    pushbuttonconnect->setEnabled(false);
    return false;
}

//*  is enable serial port connect button;*/

void SuperSerial::Connectserialport(QSerialPort* seriala,QString strportname,int intbaudrate)
{
    seriala->setPortName("\\\\.\\" + strportname);
    seriala->setBaudRate(intbaudrate);
    seriala->setDataBits(QSerialPort::Data8);
    seriala->setFlowControl(QSerialPort::NoFlowControl);
    seriala->setParity(QSerialPort::NoParity);
    seriala->setStopBits(QSerialPort::OneStop);
    seriala->setReadBufferSize(4096);
    seriala->open(QIODevice::ReadWrite);
}

/*  connect and set serial port info*/

void SuperSerial::Writeserial(QCheckBox* checkboxstring,QCheckBox* checkboxaddr,QCheckBox* checkboxaddn,QSerialPort* seriala,QLineEdit* lineeditdata)
{
    QByteArray data = "";
    if(checkboxstring->isChecked())
    {
        data = lineeditdata->text().toUtf8();
        if(checkboxaddr->isChecked() && checkboxaddn->isChecked())
        {
            seriala->write(data + "\r" + "\n");
        }
        else if(!checkboxaddr->isChecked() && checkboxaddn->isChecked())
        {
            seriala->write(data + "\n");
        }
        else if(checkboxaddr->isChecked() && !checkboxaddn->isChecked())
        {
            seriala->write(data + "\r");
        }
        else
        {
            seriala->write(data);
        }
    }
    else if(!checkboxstring->isChecked())
    {
        seriala->write(data.fromHex(lineeditdata->text().toUtf8()));
    }
    seriala->waitForBytesWritten(1000);
}

/*  serial port write data api,adapted to supertools rules;*/

bool SuperSerial::Checkserialdevice(QSerialPort *serial,QString portname)
{
    if(!serial->isOpen())
    {
        return false;
    }
    else
    {
        QStringList serialnamelist;
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            serialnamelist.append(info.description() + " " + info.portName());
        }
        if(SuperC->Findlistmember(&serialnamelist,portname) >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/*  check serial port exist or not;*/

QByteArray SuperSerial::Readdatastream(QSerialPort* serial,QCheckBox* checkboxstring)
{
    if(checkboxstring->isChecked())
    {
        return serial->readAll();
    }
    else
    {
        return serial->readAll().toHex();
    }
}

/*  receive stream data api;*/

void SuperSerial::Closeserial(QSerialPort* seriala)
{
    if(seriala->isOpen())
    {
        seriala->close();
    }
}

/*  close serial port;*/

ScanSerialPort::ScanSerialPort(QWidget *widget,QSerialPort* seriala,int baudrate,QString commanda,QString commandb,QCheckBox* checkboxstring,QLineEdit* lineedita,QString strbackvaluea,QString strbackvalueb)
{
    Widget = widget;
    Seriala = seriala;
    Baudrate = baudrate;
    Commanda = commanda;
    Commandb = commandb;
    Checkboxstring = checkboxstring;
    Lineedita = lineedita;
    Strbackvaluea = strbackvaluea;
    Strbackvalueb = strbackvalueb;
}

ScanSerialPort::~ScanSerialPort()
{
    delete SuperS;
}

void ScanSerialPort::Init()
{
    Objectinit();
}

void ScanSerialPort::Objectinit()
{
    SuperS = new SuperSerial();
}

void ScanSerialPort::Initrun()
{
    Realportlist.clear();
    Listname.clear();
    Realportstringa = "no device ";
    Realportstringb = "";
    Timeout = 1000;
    Inittime = 0;
    Bytesavailable = 0;
    Result = "";
}

/*  parameter init;*/

void ScanSerialPort::run()
{
    Initrun();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        Listname.append(info.portName());
        emit Signalsa("N","add " + info.portName() + " completed","ScanSerialPort function running...");
    }
    if(Listname.isEmpty())
    {
        emit Signalsa("N","have not found serial port","ScanSerialPort function run completed");
    }
    else
    {
        emit Signalsa("N","all serial port add completed","ScanSerialPort function running...");
        Connectserialport();
    }
    for(int i = 0;i < Realportlist.count();i++)
    {
        Realportstringb = Realportstringb + Realportlist.at(i) + " ";
        Realportstringa = Realportstringb;
    }
    Signalsa("N",Realportstringa + "is the " + Widget->objectName(),Realportstringa + "is the " + Widget->objectName());
    emit Signalsc();
}

/*  from windows serial port scan this serial device;*/

void ScanSerialPort::Connectserialport()
{
    for(int i = 0;i < Listname.count();i++)
    {
        SuperS->Connectserialport(Seriala,Listname[i],Baudrate);
        if(Seriala->isOpen())
        {
            emit Signalsa("N","connect " + Listname[i] + " completed...","connectserialport function run completed");
            Communicatewithserialporta(Listname[i]);
        }
        else
        {
            emit Signalsa("N","connect " + Listname[i] + " failed...","connectserialport function run completed");
        }
    }
}

/*  connect with serial port;*/

void ScanSerialPort::Waitforbytes()
{
    while(Inittime < Timeout)
    {
        QThread::msleep(50);
        Seriala->waitForReadyRead(1);
        Inittime = Inittime + 50;
        int bytesAvailable = Seriala->bytesAvailable();
        if(Bytesavailable != bytesAvailable && bytesAvailable != 0)
        {
            Bytesavailable = bytesAvailable;
        }
        else if(Bytesavailable == bytesAvailable && Bytesavailable != 0)
        {
            Result = SuperS->Readdatastream(Seriala,Checkboxstring);
            Inittime = 0;
            break;
        }
        else if(Inittime >= Timeout)
        {
            Result = "serial port receive time out";
            Inittime = 0;
            break;
        }
    }
}

void ScanSerialPort::Communicatewithserialporta(QString strport)
{
    emit Signalsa("N","try communicate with " + strport,"Communicatewithserialport function running...");
    emit Signalsb(Commanda);
    Waitforbytes();
    emit Signalsa("W",Lineedita->text(),"Communicatewithserialport function running...");
    emit Signalsa("R",Result,"Communicatewithserialport function running...");
    if(!Result.contains("serial port receive time out") && Result.contains(Strbackvaluea))
    {
        emit Signalsa("N","first command write and receive backvalue success","Communicatewithserialport function running...");
        Communicatewithserialportb(strport);
    }
    else
    {
        Seriala->close();
        emit Signalsa("N",strport + " is not " + Widget->objectName(),"Communicatewithserialport function completed");
    }
}

/*  Communicate with serialporta;*/

void ScanSerialPort::Communicatewithserialportb(QString strport)
{
    emit Signalsb(Commandb);
    Waitforbytes();
    emit Signalsa("W",Lineedita->text(),"Communicatewithserialport function running...");
    emit Signalsa("R",Result,"Communicatewithserialport function running...");
    if(!Result.contains("serial port receive time out") && Result.contains(Strbackvalueb))
    {
        emit Signalsa("N","second command write and receive backvalue success",strport + " is " + Widget->objectName());
        Realportlist.append(strport);
    }
    else
    {
        emit Signalsa("N","the " + strport + " is not " + Widget->objectName(),"Communicatewithserialport function completed");
    }
    Seriala->close();
}

/*  Communicate with serialportb;*/

SerialThread::SerialThread(QSerialPort *serial,double timeout)
{
    Serial = serial;
    Inittimeout = timeout;
}

void SerialThread::Init()
{
    Inittime     = 0;
    Timeout      = Inittimeout;
    Bytesavailable  = 0;
}

/*  parameter init;*/

void SerialThread::run()
{
    Init();
    while(Inittime < Timeout)
    {
        QThread::msleep(50);
        Serial->waitForReadyRead(1);
        Inittime = Inittime + 50;
        int bytesAvailable = Serial->bytesAvailable();
        if(Bytesavailable != bytesAvailable && bytesAvailable != 0)
        {
            Bytesavailable = bytesAvailable;
        }
        else if(Bytesavailable == bytesAvailable && Bytesavailable != 0)
        {
            emit Signaltt();
            break;
        }
        else if(Inittime >= Timeout)
        {
            emit Signaltf();
            break;
        }
    }
}

/*  run loog time serial command;*/
