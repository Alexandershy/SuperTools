#include "_scannerbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new ScannerBox();
}

/*  return class ScannerBox new instance pointer;*/

ScannerBox::ScannerBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("ScannerBox");
    setGroupBox(2,1);
    setStretch({1,99},{100});
    init();
}

ScannerBox::~ScannerBox()
{
    Serial->closeSerial(Serialport);
    Core->closeThread(Threadsa);
    delete Serial;
}

void ScannerBox::init()
{
    objectInit();
    timerInit();
    widgetListInit();
    pictureInit();
    functionInit();
    displayScannerPicture();
    sliderInit();
}

void ScannerBox::objectInit()
{
    Serial = new SuperSerial(this);
    Serialport  = new QSerialPort(this);
    Modulea = new ScannerModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Logger = new SuperLogger(this,Leftgroupboxlist.at(1)->Insidelayout);
    Moduleb = new ScannerModuleB(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Serialport,                     &QSerialPort::readyRead,    this,   &ScannerBox::readyReadSlot);
    connect(Modulea->ui->pushButton_58,     &QPushButton::clicked,      this,   &ScannerBox::getSerialPort);
    connect(Modulea->ui->comboBox_11,       &QComboBox::textActivated,  this,   &ScannerBox::enableConnectButton);
    connect(Modulea->ui->pushButton_59,     &QPushButton::clicked,      this,   &ScannerBox::connectSerialPort);
    connect(Modulea->ui->pushButton_60,     &QPushButton::clicked,      this,   &ScannerBox::scanScannerPort);
    connect(Modulea->ui->pushButton_61,     &QPushButton::clicked,      this,   &ScannerBox::disconnectSerialPort);
    connect(Modulea->ui->pushButton_62,     &QPushButton::clicked,      this,   &ScannerBox::openScanner);
    connect(Modulea->ui->pushButton_63,     &QPushButton::clicked,      this,   &ScannerBox::closeScanner);
    connect(Moduleb->ui->comboBox_10,       &QComboBox::textActivated,  this,   &ScannerBox::displayScannerPicture);
    connect(Moduleb->ui->comboBox_12,       &QComboBox::textActivated,  this,   &ScannerBox::displayScannerFunction);
    connect(Moduleb->ui->horizontalSlider,  &QSlider::valueChanged,     this,   &ScannerBox::changePictureSize);
}

void ScannerBox::timerInit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&ScannerBox::timerCaSlot);
}

void ScannerBox::widgetListInit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_61,Modulea->ui->pushButton_62,Modulea->ui->pushButton_63};
    Connectwidgetef     = {Modulea->ui->pushButton_58,Modulea->ui->pushButton_59,Modulea->ui->pushButton_60,Modulea->ui->comboBox_11};
    Disconnectwidgetet  = {Modulea->ui->pushButton_58,Modulea->ui->pushButton_59,Modulea->ui->pushButton_60,Modulea->ui->comboBox_11};
    Disconnectwidgetef  = {Modulea->ui->pushButton_61,Modulea->ui->pushButton_62,Modulea->ui->pushButton_63};
}

void ScannerBox::pictureInit()
{
    Scannerpicturelist.append(":/__supericon__/_scanner_.png");
    Scannerpicturelist.append(":/__supericon__/_fs361415r_.png");
    Scannerpicturelist.append(":/__supericon__/_honeywell1900_.png");
    Fs361415rpicturelist.append(":/__supericon__/_fs361415r_.png");
    Fs361415rpicturelist.append(":/__supericon__/_fusbcomportmode_.png");
    Fs361415rpicturelist.append(":/__supericon__/_fusbkeyboardmode_.png");
    Fs361415rpicturelist.append(":/__supericon__/_frs232comportmode_.png");
    Fs361415rpicturelist.append(":/__supericon__/_finductionmode_.png");
    Fs361415rpicturelist.append(":/__supericon__/_fexitinductionmode_.png");
    Honeywellpicturelist.append(":/__supericon__/_honeywell1900_.png");
    Honeywellpicturelist.append(":/__supericon__/_husbcomportmode_.png");
    Honeywellpicturelist.append(":/__supericon__/_husbkeyboardmode_.png");
    Honeywellpicturelist.append(":/__supericon__/_hrs485comportmode1_.png");
    Honeywellpicturelist.append(":/__supericon__/_hrs485comportmode2_.png");
    Honeywellpicturelist.append(":/__supericon__/_hinductionmode_.png");
    Honeywellpicturelist.append(":/__supericon__/_hexitinductionmode_.png");
    Picture = {Scannerpicturelist,Fs361415rpicturelist,Honeywellpicturelist};
}

void ScannerBox::functionInit()
{
    Scannerfunction.append("no scanner function");
    Fs361415rfunction.append("select scanner function");
    Fs361415rfunction.append("usb return to com port factory setting");
    Fs361415rfunction.append("usb return to keyboard factory setting");
    Fs361415rfunction.append("rs232 return to factory setting");
    Fs361415rfunction.append("induction mode");
    Fs361415rfunction.append("exit induction mode");
    Honeywellfunction.append("select scanner function");
    Honeywellfunction.append("usb return to com port factory setting");
    Honeywellfunction.append("usb return to keyboard factory setting");
    Honeywellfunction.append("rs485 return to factory settinga");
    Honeywellfunction.append("rs485 return to factory settingb");
    Honeywellfunction.append("induction mode");
    Honeywellfunction.append("exit induction mode");
    Function = {Scannerfunction,Fs361415rfunction,Honeywellfunction};
}

void ScannerBox::sliderInit()
{
    Timercb = new QTimer(this);
    Timercb->setInterval(1000);
    connect(Timercb,&QTimer::timeout,this,&ScannerBox::timerCbSlot);
    Slidermaxvalue = Moduleb->ui->horizontalSlider->maximum();
    Timercb->start();
}

/*  slider init;*/

void ScannerBox::getSerialPort()
{
    Serial->getSerialPort(&Serialnamelist,Modulea->ui->comboBox_11);
    Serial->enableSerialComboBox(&Serialnamelist,Modulea->ui->comboBox_11,Modulea->ui->comboBox_11);
    Serial->enableConnectButton(Modulea->ui->comboBox_11,Modulea->ui->comboBox_35,Modulea->ui->pushButton_59);
    if(Modulea->ui->comboBox_11->currentText().isEmpty())
    {
        Logger->displayLog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_11->count();i++)
        {
            Logger->displayLog("N",Modulea->ui->comboBox_11->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

bool ScannerBox::enableConnectButton()
{
    return Serial->enableConnectButton(Modulea->ui->comboBox_11,Modulea->ui->comboBox_35,Modulea->ui->pushButton_59);
}

/*  is enable serial port connect button;*/

void ScannerBox::connectSerialPort()
{
    Serial->connectSerialPort(Serialport,Serialnamelist[Modulea->ui->comboBox_11->currentIndex()],Modulea->ui->comboBox_35->currentText().toInt());
    if(Serialport->isOpen())
    {
        Core->enableWidgetList(&Connectwidgetet,true);
        Core->enableWidgetList(&Connectwidgetef,false);
        Timerca->start();
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_11->currentText() + " and set baudrate as " + Modulea->ui->comboBox_35->currentText() + " success","connectSerialPort function run completed");
    }
    else
    {
        Logger->displayLog("N","connect " + Modulea->ui->comboBox_11->currentText() + " and set baudrate as " + Modulea->ui->comboBox_35->currentText() + " failed","connectSerialPort function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for check connected device;*/

void ScannerBox::disconnectSerialPort()
{
    Serialport->close();
    if(!Serialport->isOpen())
    {
        Core->enableWidgetList(&Disconnectwidgetet,true);
        Core->enableWidgetList(&Disconnectwidgetef,false);
        Timerca->stop();
        Logger->displayLog("N",this->objectName() + " has been disconnected","disconnectSerialPort function run completed");
    }
}

/*  disconnect serial port and operate ui*/

void ScannerBox::openScanner()
{
    Modulea->ui->lineEdit_35->setText("16540d");
    Serial->writeSerial(Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Serialport,Modulea->ui->lineEdit_35);
    Logger->displayLog("W","16540d","Openscanner function run completed");
}

/*  write 16540d to serial port;*/

void ScannerBox::closeScanner()
{
    Modulea->ui->lineEdit_35->setText("16550d");
    Serial->writeSerial(Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Serialport,Modulea->ui->lineEdit_35);
    Logger->displayLog("W","16550d","Openscanner function run completed");
}

/*  write 16550d to serial port;*/

void ScannerBox::scanScannerPort()
{
    Modulea->ui->pushButton_60->setEnabled(false);
    Threadsa = new ScanPort(115200);
    connect(Threadsa,&ScanPort::signalSa,Logger,&SuperLogger::displayLog);
    connect(Threadsa,&ScanPort::signalSb,this,&ScannerBox::signalSbSlot);
    connect(Threadsa,&QThread::finished,Threadsa,&QObject::deleteLater);
    Threadsa->start();
}

/*  start a new thread to scan scanner;*/

void ScannerBox::displayScanner(bool boola,QString strpicturepath,QStringList Scanneritem)
{
    Moduleb->ui->comboBox_12->clear();
    Moduleb->ui->comboBox_12->setEnabled(boola);
    Moduleb->ui->comboBox_12->addItems(Scanneritem);
    Moduleb->ui->horizontalSlider->setEnabled(false);
    Pixmap.convertFromImage(QImage(strpicturepath));
    Moduleb->ui->horizontalSlider->setValue(Moduleb->ui->horizontalSlider->maximum());
    Moduleb->ui->label_63->setPixmap(Pixmap);
    Logger->displayLog("N",strpicturepath,"Timercaslot function run completed");
}

/*  display scanner picture and add its function api;*/

void ScannerBox::displayScannerPicture()
{
    displayScanner(true,Scannerpicturelist.at(Moduleb->ui->comboBox_10->currentIndex()),Function.at(Moduleb->ui->comboBox_10->currentIndex()));
}

/*  display scanner picture and add its function;*/

void ScannerBox::displayFunction(QString strpicturepath)
{
    Moduleb->ui->comboBox_12->setEnabled(true);
    Moduleb->ui->horizontalSlider->setEnabled(true);
    Pixmap.convertFromImage(QImage(strpicturepath));
    Moduleb->ui->label_63->setPixmap(Pixmap.scaled(Moduleb->ui->label_63->width(), Moduleb->ui->label_63->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    Logger->displayLog("N",strpicturepath,"Timercaslot function run completed");
}

/*  display function picture and add its function api;*/

void ScannerBox::displayScannerFunction()
{
    int scannerindex = Moduleb->ui->comboBox_10->currentIndex();
    int functionindex = Moduleb->ui->comboBox_12->currentIndex();
    QStringList tempa = Picture.at(scannerindex);
    QStringList tempb = Function.at(scannerindex);
    displayFunction(tempa.at(functionindex));
}

/*  display function picture and add its function;*/

void ScannerBox::timerCaSlot()
{
    if(Serial->checkSerialDevice(Serialport,Modulea->ui->comboBox_11->currentText()) == false)
    {
        disconnectSerialPort();
        getSerialPort();
        Logger->displayLog("N","serial port has been removed","Timercaslot function run completed");
        enableConnectButton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void ScannerBox::timerCbSlot()
{
    if(Moduleb->ui->label_63->height() != 30 && Moduleb->ui->label_63->width() != 100)
    {
        Labelsize = Moduleb->ui->label_63->size();
        Timercb->stop();
    }
}

/*  cal label size;*/

void ScannerBox::signalSbSlot()
{
    Threadsa = nullptr;
    Modulea->ui->pushButton_60->setEnabled(true);
}

/*  receive signal from signalsb,enable pushbutton;*/

void ScannerBox::readyReadSlot()
{
    QByteArray result = Serial->readDataStream(Serialport,Modulea->ui->checkBox);
    Logger->displayLog("R",result,"Readyreadslot function receive result completed");
}

/*  receive singalr result, and display on textbrowser;*/

void ScannerBox::changePictureSize()
{
    double percent = double(Moduleb->ui->horizontalSlider->value()) / Slidermaxvalue;
    Moduleb->ui->lineEdit->setText(QString::number(100 * percent,'f',0) + "%");
    Moduleb->ui->label_63->setMaximumSize({int(Labelsize.width() * percent),int(Labelsize.height() * percent)});
    Moduleb->ui->label_63->setPixmap(Pixmap.scaled(Moduleb->ui->label_63->width(), Moduleb->ui->label_63->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

/*  change picture size by user move slider;*/

ScanPort::ScanPort(int baudrate)
{
    Baudrate = baudrate;
    init();
}

ScanPort::~ScanPort()
{
    delete Serial;
}

void ScanPort::init()
{
    objectInit();
}

void ScanPort::objectInit()
{
    Serial = new SuperSerial();
}

void ScanPort::initRun()
{
    Serialportname = "no device ";
    Listname.clear();
    Seriallista.clear();
    Seriallistb.clear();
}

/*  init before start thread;*/

void ScanPort::run()
{
    initRun();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString Portname = info.portName();
        Listname.append(Portname);
        emit signalSa("N","add " + Portname + " completed","Scanscannerport function running...");
    }
    if(Listname.isEmpty())
    {
        emit signalSa("N","have not found serial port","Scanscannerport function run completed");
    }
    else
    {
        emit signalSa("N","all serial port add completed","scanserialport function running...");
        connectSerialPort();
    }
    emit signalSb();
    releaseObject(&Seriallista);
    emit signalSa("N","all serial port scan completed",Serialportname + " is scanner");
}

/*  run scan scanner thread;*/

void ScanPort::connectSerialPort()
{
    for(int i = 0;i < Listname.count();i++)
    {
        QString Portname = Listname.at(i);
        Seriallista.append(new QSerialPort());
        emit signalSa("N","try to connect " + Portname + "...","connectSerialPort function running...");
        Serial->connectSerialPort(Seriallista.at(i),Portname,Baudrate);
        if(Seriallista.at(i)->isOpen())
        {
            emit signalSa("N","connect " + Portname + " completed","connectSerialPort function running...");
            Seriallistb.append(Seriallista.at(i));
        }
        else
        {
            emit signalSa("N","connect " + Portname + " failed","connectSerialPort function running...");
        }
    }
    if(!Seriallistb.isEmpty())
    {
        emit signalSa("N","have 10 seconds scan any info QR!!","connectSerialPort function running...");
        receiveData();
    }
    else
    {
        emit signalSa("N","no port could return value","connectSerialPort function running...");
    }
}

/*  connect all serial port;*/

void ScanPort::receiveData()
{
    QString temp = "";
    for(int i = 0;i < 10;i++)
    {
        emit signalSa("N","time remains " + QString::number(10 - i) + " seconds","Receivedata function running...");
        QThread::msleep(1000);
        if(!temp.isEmpty())
        {
            break;
        }
        else
        {
            for(int j = 0;j < Seriallistb.count();j++)
            {
                Seriallistb.at(j)->waitForReadyRead(100);
                int bytes = Seriallistb.at(j)->bytesAvailable();
                if(bytes > 0)
                {
                    temp = Seriallistb.at(j)->readAll();
                    Serialportname = Seriallistb.at(j)->portName();
                    emit signalSa("N",Serialportname + " is scanner",Serialportname + " is scanner");
                    break;
                }
            }
        }
    }
}

/*  receive data form all serial port;*/

void ScanPort::releaseObject(QVector<QSerialPort*> *seriallist)
{
    for(int i = 0;i < seriallist->count();i++)
    {
        if(seriallist->at(i)->isOpen())
        {
            seriallist->at(i)->close();
            emit signalSa("N","close " + seriallist->at(i)->portName() + " completed","Releaseobject function run completed");
        }
        delete seriallist->at(i);
    }
}

/*  release all object;*/


