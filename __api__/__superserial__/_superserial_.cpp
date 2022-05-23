#include "_superserial_.h"

SuperSerial::SuperSerial(QObject *parent)
    : QObject(parent)
{
    Core = new SuperCore(this);
}

SuperSerial::~SuperSerial()
{

}

//*************************************************QSerialport*****************************************************//

void SuperSerial::getSerialPort(QStringList *listname,QComboBox* comboboxnamelist)
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

void SuperSerial::enableSerialComboBox(QStringList *namelist,QComboBox *comboboxnamelist,QComboBox* comboboxbaudrate)
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

bool SuperSerial::enableConnectButton(QComboBox* comboboxnamelist,QComboBox* comboboxbaudrate,QPushButton* pushbuttonconnect)
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

void SuperSerial::connectSerialPort(QSerialPort* seriala,QString strportname,int intbaudrate)
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

void SuperSerial::writeSerial(QCheckBox* checkboxstring,QCheckBox* checkboxaddr,QCheckBox* checkboxaddn,QSerialPort* seriala,QLineEdit* lineeditdata)
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

bool SuperSerial::checkSerialDevice(QSerialPort *serial,QString portname)
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
        if(Core->findListMember(&serialnamelist,portname) >= 0)
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

QByteArray SuperSerial::readDataStream(QSerialPort* serial,QCheckBox* checkboxstring)
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

void SuperSerial::closeSerial(QSerialPort* seriala)
{
    if(seriala->isOpen())
    {
        seriala->close();
    }
}

/*  close serial port;*/

SuperScanSerial::SuperScanSerial(QWidget *widget,QSerialPort* serialport,int baudrate,QString commanda,QString commandb,QCheckBox* checkboxstring,QLineEdit* lineedita,QString strbackvaluea,QString strbackvalueb)
{
    Widget = widget;
    Serialport = serialport;
    Baudrate = baudrate;
    Commanda = commanda;
    Commandb = commandb;
    Checkboxstring = checkboxstring;
    Lineedita = lineedita;
    Strbackvaluea = strbackvaluea;
    Strbackvalueb = strbackvalueb;
}

SuperScanSerial::~SuperScanSerial()
{

}

void SuperScanSerial::init()
{
    objectInit();
}

void SuperScanSerial::objectInit()
{
    Serial = new SuperSerial(this);
}

void SuperScanSerial::initRun()
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

void SuperScanSerial::run()
{
    initRun();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        Listname.append(info.portName());
        emit signalSa("N","add " + info.portName() + " completed","ScanSerialPort function running...");
    }
    if(Listname.isEmpty())
    {
        emit signalSa("N","have not found serial port","ScanSerialPort function run completed");
    }
    else
    {
        emit signalSa("N","all serial port add completed","ScanSerialPort function running...");
        connectSerialPort();
    }
    for(int i = 0;i < Realportlist.count();i++)
    {
        Realportstringb = Realportstringb + Realportlist.at(i) + " ";
        Realportstringa = Realportstringb;
    }
    emit signalSa("N",Realportstringa + "is the " + Widget->objectName(),Realportstringa + "is the " + Widget->objectName());
    emit signalSc();
}

/*  from windows serial port scan this serial device;*/

void SuperScanSerial::connectSerialPort()
{
    for(int i = 0;i < Listname.count();i++)
    {
        Serial->connectSerialPort(Serialport,Listname[i],Baudrate);
        if(Serialport->isOpen())
        {
            emit signalSa("N","connect " + Listname[i] + " completed...","connectserialport function run completed");
            communicateWithSerialPorta(Listname[i]);
        }
        else
        {
            emit signalSa("N","connect " + Listname[i] + " failed...","connectserialport function run completed");
        }
    }
}

/*  connect with serial port;*/

void SuperScanSerial::waitForBytes()
{
    while(Inittime < Timeout)
    {
        QThread::msleep(50);
        Serialport->waitForReadyRead(1);
        Inittime = Inittime + 50;
        int bytesAvailable = Serialport->bytesAvailable();
        if(Bytesavailable != bytesAvailable && bytesAvailable != 0)
        {
            Bytesavailable = bytesAvailable;
        }
        else if(Bytesavailable == bytesAvailable && Bytesavailable != 0)
        {
            Result = Serial->readDataStream(Serialport,Checkboxstring);
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

void SuperScanSerial::communicateWithSerialPorta(QString strport)
{
    emit signalSa("N","try communicate with " + strport,"Communicatewithserialport function running...");
    emit signalSb(Commanda);
    waitForBytes();
    emit signalSa("W",Lineedita->text(),"Communicatewithserialport function running...");
    emit signalSa("R",Result,"Communicatewithserialport function running...");
    if(!Result.contains("serial port receive time out") && Result.contains(Strbackvaluea))
    {
        emit signalSa("N","first command write and receive backvalue success","Communicatewithserialport function running...");
        communicateWithSerialPortb(strport);
    }
    else
    {
        Serialport->close();
        emit signalSa("N",strport + " is not " + Widget->objectName(),"Communicatewithserialport function completed");
    }
}

/*  Communicate with serialporta;*/

void SuperScanSerial::communicateWithSerialPortb(QString strport)
{
    emit signalSb(Commandb);
    waitForBytes();
    emit signalSa("W",Lineedita->text(),"Communicatewithserialport function running...");
    emit signalSa("R",Result,"Communicatewithserialport function running...");
    if(!Result.contains("serial port receive time out") && Result.contains(Strbackvalueb))
    {
        emit signalSa("N","second command write and receive backvalue success",strport + " is " + Widget->objectName());
        Realportlist.append(strport);
    }
    else
    {
        emit signalSa("N","the " + strport + " is not " + Widget->objectName(),"Communicatewithserialport function completed");
    }
    Serialport->close();
}

/*  Communicate with serialportb;*/

SuperSerialThread::SuperSerialThread(QSerialPort *serialport,double timeout)
{
    Serialport = serialport;
    Inittimeout = timeout;
}

void SuperSerialThread::init()
{
    Inittime = 0;
    Timeout = Inittimeout;
    Bytesavailable = 0;
}

/*  parameter init;*/

void SuperSerialThread::run()
{
    init();
    while(Inittime < Timeout)
    {
        QThread::msleep(50);
        Serialport->waitForReadyRead(1);
        Inittime = Inittime + 50;
        int bytesAvailable = Serialport->bytesAvailable();
        if(Bytesavailable != bytesAvailable && bytesAvailable != 0)
        {
            Bytesavailable = bytesAvailable;
        }
        else if(Bytesavailable == bytesAvailable && Bytesavailable != 0)
        {
            emit signalTt();
            break;
        }
        else if(Inittime >= Timeout)
        {
            emit signalTf();
            break;
        }
    }
}

/*  run loog time serial command;*/
