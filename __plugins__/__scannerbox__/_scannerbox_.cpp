#include "_scannerbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new ScannerBox();
}

/*  return class ScannerBox new instance pointer;*/

ScannerBox::ScannerBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("ScannerBox");
    Setgroupbox(2,1);
    Setstretch({1,99},{100});
    Init();
}

ScannerBox::~ScannerBox()
{
    SuperS->Closeserial(Serial);
    SuperC->Closethread(Threadsa);
    delete Serial;
}

void ScannerBox::Init()
{
    Objectinit();
    Timerinit();
    Widgetlistinit();
    Pictureinit();
    Functioninit();
    Displayscannerpicture();
    Sliderinit();
}

void ScannerBox::Objectinit()
{
    SuperS = new SuperSerial(this);
    Serial  = new QSerialPort(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Logger = new SuperLogger(this,Leftgroupboxlist.at(1)->Insidelayout);
    Moduleb = new ModuleB(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Serial,                         &QSerialPort::readyRead,    this,   &ScannerBox::Readyreadslot);
    connect(Modulea->ui->pushButton_58,     &QPushButton::clicked,      this,   &ScannerBox::Getserialport);
    connect(Modulea->ui->comboBox_11,       &QComboBox::textActivated,  this,   &ScannerBox::Enableconnectbutton);
    connect(Modulea->ui->pushButton_59,     &QPushButton::clicked,      this,   &ScannerBox::Connectserialport);
    connect(Modulea->ui->pushButton_60,     &QPushButton::clicked,      this,   &ScannerBox::Scanscannerport);
    connect(Modulea->ui->pushButton_61,     &QPushButton::clicked,      this,   &ScannerBox::Disconnectserialport);
    connect(Modulea->ui->pushButton_62,     &QPushButton::clicked,      this,   &ScannerBox::Openscanner);
    connect(Modulea->ui->pushButton_63,     &QPushButton::clicked,      this,   &ScannerBox::Closescanner);
    connect(Moduleb->ui->comboBox_10,       &QComboBox::textActivated,  this,   &ScannerBox::Displayscannerpicture);
    connect(Moduleb->ui->comboBox_12,       &QComboBox::textActivated,  this,   &ScannerBox::Displayscannerfunction);
    connect(Moduleb->ui->horizontalSlider,  &QSlider::valueChanged,     this,   &ScannerBox::Changepicturesize);
}

void ScannerBox::Timerinit()
{
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    connect(Timerca,&QTimer::timeout,this,&ScannerBox::Timercaslot);
}

void ScannerBox::Widgetlistinit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_61,Modulea->ui->pushButton_62,Modulea->ui->pushButton_63};
    Connectwidgetef     = {Modulea->ui->pushButton_58,Modulea->ui->pushButton_59,Modulea->ui->pushButton_60,Modulea->ui->comboBox_11};
    Disconnectwidgetet  = {Modulea->ui->pushButton_58,Modulea->ui->pushButton_59,Modulea->ui->pushButton_60,Modulea->ui->comboBox_11};
    Disconnectwidgetef  = {Modulea->ui->pushButton_61,Modulea->ui->pushButton_62,Modulea->ui->pushButton_63};
}

void ScannerBox::Pictureinit()
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

void ScannerBox::Functioninit()
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

void ScannerBox::Sliderinit()
{
    Timercb = new QTimer(this);
    Timercb->setInterval(1000);
    connect(Timercb,&QTimer::timeout,this,&ScannerBox::Timercbslot);
    Slidermaxvalue = Moduleb->ui->horizontalSlider->maximum();
    Timercb->start();
}

/*  slider init;*/

void ScannerBox::Getserialport()
{
    SuperS->Getserialport(&Serialnamelist,Modulea->ui->comboBox_11);
    SuperS->Enableserialcombobox(&Serialnamelist,Modulea->ui->comboBox_11,Modulea->ui->comboBox_11);
    SuperS->Enableconnectbutton(Modulea->ui->comboBox_11,Modulea->ui->comboBox_35,Modulea->ui->pushButton_59);
    if(Modulea->ui->comboBox_11->currentText().isEmpty())
    {
        Logger->Displaylog("N","can not find any serial device","Getserialport function run completed");
    }
    else
    {
        for(int i = 0;i < Modulea->ui->comboBox_11->count();i++)
        {
            Logger->Displaylog("N",Modulea->ui->comboBox_11->itemText(i),"Getserialport function run completed");
        }
    }
}

/*  get windows system serial port and add item to combobox, enable connect button or not;*/

bool ScannerBox::Enableconnectbutton()
{
    return SuperS->Enableconnectbutton(Modulea->ui->comboBox_11,Modulea->ui->comboBox_35,Modulea->ui->pushButton_59);
}

/*  is enable serial port connect button;*/

void ScannerBox::Connectserialport()
{
    SuperS->Connectserialport(Serial,Serialnamelist[Modulea->ui->comboBox_11->currentIndex()],Modulea->ui->comboBox_35->currentText().toInt());
    if(Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Connectwidgetet,true);
        SuperC->Enablewidgetlist(&Connectwidgetef,false);
        Timerca->start();
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_11->currentText() + " and set baudrate as " + Modulea->ui->comboBox_35->currentText() + " success","connectserialport function run completed");
    }
    else
    {
        Logger->Displaylog("N","connect " + Modulea->ui->comboBox_11->currentText() + " and set baudrate as " + Modulea->ui->comboBox_35->currentText() + " failed","connectserialport function run completed");
    }
}

/*  connect serial port and operate ui,start new thread for check connected device;*/

void ScannerBox::Disconnectserialport()
{
    Serial->close();
    if(!Serial->isOpen())
    {
        SuperC->Enablewidgetlist(&Disconnectwidgetet,true);
        SuperC->Enablewidgetlist(&Disconnectwidgetef,false);
        Timerca->stop();
        Logger->Displaylog("N",this->objectName() + " has been disconnected","disconnectserialport function run completed");
    }
}

/*  disconnect serial port and operate ui*/

void ScannerBox::Openscanner()
{
    Modulea->ui->lineEdit_35->setText("16540d");
    SuperS->Writeserial(Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Serial,Modulea->ui->lineEdit_35);
    Logger->Displaylog("W","16540d","Openscanner function run completed");
}

/*  write 16540d to serial port;*/

void ScannerBox::Closescanner()
{
    Modulea->ui->lineEdit_35->setText("16550d");
    SuperS->Writeserial(Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Modulea->ui->checkBox_31,Serial,Modulea->ui->lineEdit_35);
    Logger->Displaylog("W","16550d","Openscanner function run completed");
}

/*  write 16550d to serial port;*/

void ScannerBox::Scanscannerport()
{
    Modulea->ui->pushButton_60->setEnabled(false);
    Threadsa = new ScanPort(115200);
    connect(Threadsa,&ScanPort::Signalsa,Logger,&SuperLogger::Displaylog);
    connect(Threadsa,&ScanPort::Signalsb,this,&ScannerBox::Signalsbsolt);
    connect(Threadsa,&QThread::finished,Threadsa,&QObject::deleteLater);
    Threadsa->start();
}

/*  start a new thread to scan scanner;*/

void ScannerBox::Displayscanner(bool boola,QString strpicturepath,QStringList Scanneritem)
{
    Moduleb->ui->comboBox_12->clear();
    Moduleb->ui->comboBox_12->setEnabled(boola);
    Moduleb->ui->comboBox_12->addItems(Scanneritem);
    Moduleb->ui->horizontalSlider->setEnabled(false);
    Pixmap.convertFromImage(QImage(strpicturepath));
    Moduleb->ui->horizontalSlider->setValue(Moduleb->ui->horizontalSlider->maximum());
    Moduleb->ui->label_63->setPixmap(Pixmap);
    Logger->Displaylog("N",strpicturepath,"Timercaslot function run completed");
}

/*  display scanner picture and add its function api;*/

void ScannerBox::Displayscannerpicture()
{
    Displayscanner(true,Scannerpicturelist.at(Moduleb->ui->comboBox_10->currentIndex()),Function.at(Moduleb->ui->comboBox_10->currentIndex()));
}

/*  display scanner picture and add its function;*/

void ScannerBox::Displayfunction(QString strpicturepath)
{
    Moduleb->ui->comboBox_12->setEnabled(true);
    Moduleb->ui->horizontalSlider->setEnabled(true);
    Pixmap.convertFromImage(QImage(strpicturepath));
    Moduleb->ui->label_63->setPixmap(Pixmap.scaled(Moduleb->ui->label_63->width(), Moduleb->ui->label_63->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    Logger->Displaylog("N",strpicturepath,"Timercaslot function run completed");
}

/*  display function picture and add its function api;*/

void ScannerBox::Displayscannerfunction()
{
    int scannerindex = Moduleb->ui->comboBox_10->currentIndex();
    int functionindex = Moduleb->ui->comboBox_12->currentIndex();
    QStringList tempa = Picture.at(scannerindex);
    QStringList tempb = Function.at(scannerindex);
    Displayfunction(tempa.at(functionindex));
}

/*  display function picture and add its function;*/

void ScannerBox::Timercaslot()
{
    if(SuperS->Checkserialdevice(Serial,Modulea->ui->comboBox_11->currentText()) == false)
    {
        Disconnectserialport();
        Getserialport();
        Logger->Displaylog("N","serial port has been removed","Timercaslot function run completed");
        Enableconnectbutton();
        Timerca->stop();
    }
}

/*  receive result from signalc,check serial port is connect or not;*/

void ScannerBox::Timercbslot()
{
    if(Moduleb->ui->label_63->height() != 30 && Moduleb->ui->label_63->width() != 100)
    {
        Labelsize = Moduleb->ui->label_63->size();
        Timercb->stop();
    }
}

/*  cal label size;*/

void ScannerBox::Signalsbsolt()
{
    Threadsa = nullptr;
    Modulea->ui->pushButton_60->setEnabled(true);
}

/*  receive signal from signalsb,enable pushbutton;*/

void ScannerBox::Readyreadslot()
{
    QByteArray result = SuperS->Readdatastream(Serial,Modulea->ui->checkBox);
    Logger->Displaylog("R",result,"Readyreadslot function receive result completed");
}

/*  receive singalr result, and display on textbrowser;*/

void ScannerBox::Changepicturesize()
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
    Init();
}

ScanPort::~ScanPort()
{
    delete SuperS;
}

void ScanPort::Init()
{
    Objectinit();
}

void ScanPort::Objectinit()
{
    SuperS = new SuperSerial();
}

void ScanPort::Initrun()
{
    Serialportname = "no device ";
    Listname.clear();
    Seriallista.clear();
    Seriallistb.clear();
}

/*  init before start thread;*/

void ScanPort::run()
{
    Initrun();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString Portname = info.portName();
        Listname.append(Portname);
        emit Signalsa("N","add " + Portname + " completed","Scanscannerport function running...");
    }
    if(Listname.isEmpty())
    {
        emit Signalsa("N","have not found serial port","Scanscannerport function run completed");
    }
    else
    {
        emit Signalsa("N","all serial port add completed","scanserialport function running...");
        Connectserialport();
    }
    emit Signalsb();
    Releaseobject(&Seriallista);
    emit Signalsa("N","all serial port scan completed",Serialportname + " is scanner");
}

/*  run scan scanner thread;*/

void ScanPort::Connectserialport()
{
    for(int i = 0;i < Listname.count();i++)
    {
        QString Portname = Listname.at(i);
        Seriallista.append(new QSerialPort());
        emit Signalsa("N","try to connect " + Portname + "...","Connectserialport function running...");
        SuperS->Connectserialport(Seriallista.at(i),Portname,Baudrate);
        if(Seriallista.at(i)->isOpen())
        {
            emit Signalsa("N","connect " + Portname + " completed","Connectserialport function running...");
            Seriallistb.append(Seriallista.at(i));
        }
        else
        {
            emit Signalsa("N","connect " + Portname + " failed","Connectserialport function running...");
        }
    }
    if(!Seriallistb.isEmpty())
    {
        emit Signalsa("N","have 10 seconds scan any info QR!!","Connectserialport function running...");
        Receivedata();
    }
    else
    {
        emit Signalsa("N","no port could return value","Connectserialport function running...");
    }
}

/*  connect all serial port;*/

void ScanPort::Receivedata()
{
    QString temp = "";
    for(int i = 0;i < 10;i++)
    {
        emit Signalsa("N","time remains " + QString::number(10 - i) + " seconds","Receivedata function running...");
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
                    emit Signalsa("N",Serialportname + " is scanner",Serialportname + " is scanner");
                    break;
                }
            }
        }
    }
}

/*  receive data form all serial port;*/

void ScanPort::Releaseobject(QVector<QSerialPort*> *seriallist)
{
    for(int i = 0;i < seriallist->count();i++)
    {
        if(seriallist->at(i)->isOpen())
        {
            seriallist->at(i)->close();
            emit Signalsa("N","close " + seriallist->at(i)->portName() + " completed","Releaseobject function run completed");
        }
        delete seriallist->at(i);
    }
}

/*  release all object;*/


