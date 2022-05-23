#include "_tcpserverbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new TcpServerBox();
}

/*  return class TcpServerBox new instance pointer;*/

TcpServerBox::TcpServerBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("TcpServerBox");
    setGroupBox(2,1);
    setStretch({1,99},{100});
    init();
}

TcpServerBox::~TcpServerBox()
{
    forceDisconnect();
}

void TcpServerBox::init()
{
    objectInit();
    widgetListInit();
    tempDirInit();
}

void TcpServerBox::objectInit()
{
    Network = new SuperNetwork(this);
    Modulea = new TcpServerModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new TcpServerModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Tcpserver = new QTcpServer(this);
    connect(Tcpserver,                  &QTcpServer::newConnection,     this,&TcpServerBox::newTcpsocket);
    connect(Modulea->ui->pushButton_2,  &QPushButton::clicked,          this,&TcpServerBox::getLocalIpAddress);
    connect(Modulea->ui->comboBox,      &QComboBox::currentTextChanged, this,&TcpServerBox::enableStartTcpserver);
    connect(Modulea->ui->comboBox_2,    &QComboBox::currentTextChanged, this,&TcpServerBox::enableStartTcpserver);
    connect(Modulea->ui->pushButton_3,  &QPushButton::clicked,          this,&TcpServerBox::startTcpserver);
    connect(Modulea->ui->pushButton_4,  &QPushButton::clicked,          this,&TcpServerBox::closeTcpserver);
}

void TcpServerBox::widgetListInit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_4};
    Connectwidgetef     = {Modulea->ui->comboBox,Modulea->ui->comboBox_2,Modulea->ui->pushButton_2,Modulea->ui->pushButton_3};
    Disconnectwidgetet  = {Modulea->ui->comboBox,Modulea->ui->comboBox_2,Modulea->ui->pushButton_2,Modulea->ui->pushButton_3};
    Disconnectwidgetef  = {Modulea->ui->pushButton_4};
}

/*  widget list init;*/

void TcpServerBox::tempDirInit()
{
    Dir = new QDir(Tempfilepath);
}

/*  set temp init dir;*/

void TcpServerBox::getLocalIpAddress()
{
    Modulea->ui->comboBox->clear();
    Networkinterface = QNetworkInterface::allInterfaces();
    for(int i = 0;i < Networkinterface.count();i++)
    {
        Networkaddressentry = Networkinterface.at(i).addressEntries();
        Network->getLocalIpAddress(&Networkaddressentry,Modulea->ui->comboBox);
    }
    for(int i = 0;i < Modulea->ui->comboBox->count();i++)
    {
        Logger->displayLog("N",Modulea->ui->comboBox->itemText(i),"Getlocalipaddress function run completed");
    }
}

/*  get system ip address to combobox;*/

void TcpServerBox::enableStartTcpserver()
{
    bool boola;
    bool boolb;
    boola = Core->checkIpRules(Modulea->ui->comboBox->currentText());
    int port = Modulea->ui->comboBox_2->currentText().toInt(&boolb);
    if(boola == true && boolb == true && port > 100 && port < 65535)
    {
        Modulea->ui->pushButton_3->setEnabled(true);
    }
}

/*  enable start tcp server button or not;*/

void TcpServerBox::startTcpserver()
{
    QHostAddress ipaddress(Modulea->ui->comboBox->currentText());
    Tcpserver->listen(ipaddress,Modulea->ui->comboBox_2->currentText().toInt());
    if(Tcpserver->isListening())
    {
        Core->enableWidgetList(&Connectwidgetet,true);
        Core->enableWidgetList(&Connectwidgetef,false);
        Logger->displayLog("N","server start success","Starttcpserver function run completed");
    }
    else
    {
        Logger->displayLog("N","server start failed","Starttcpserver function run completed");
    }
}

/*  start tcp server;*/

void TcpServerBox::closeTcpserver()
{
    Tcpserver->close();
    forceDisconnect();
    if(!Tcpserver->isListening())
    {
        Core->enableWidgetList(&Disconnectwidgetet,true);
        Core->enableWidgetList(&Disconnectwidgetef,false);
        Logger->displayLog("N","server close success","Closetcpserver function run completed");
    }
    else
    {
        Logger->displayLog("N","server close failed","Closetcpserver function run completed");
    }
}

/* close tcp server and tick off all client;*/

void TcpServerBox::forceDisconnect()
{
    QList<int> connectsocket;
    for(int i = 0;i < Moduleb->ui->treeWidget->topLevelItemCount();i++)
    {
        connectsocket.append(Moduleb->ui->treeWidget->topLevelItem(i)->text(0).toInt());
    }
    for(int j = 0;j < connectsocket.count();j++)
    {
        Network->disConnectTcpServer(Tcpsocketlist.at(connectsocket.at(j)),1000);
    }
}

/*  tick off all client;*/

void TcpServerBox::newTcpsocket()
{
    int tcpsocketindex = Tcpsocketlist.count();
    Tcpsocketlist.append(Tcpserver->nextPendingConnection());
    QString ipaddress = Tcpsocketlist.at(tcpsocketindex)->peerAddress().toString();
    int port = Tcpsocketlist.at(tcpsocketindex)->peerPort();
    Logger->displayLog("N",ipaddress + "::" + QString::number(port) + " connect success;","Newtcpsocket function run completed");
    connect(Tcpsocketlist.at(tcpsocketindex),&QTcpSocket::readyRead,this,&TcpServerBox::receiveCommand);
    connect(Tcpsocketlist.at(tcpsocketindex),&QTcpSocket::disconnected,this,&TcpServerBox::disconnected);
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,QString::number(tcpsocketindex));
    item->setText(1,ipaddress);
    item->setText(2,QString::number(port));
    Moduleb->ui->treeWidget->addTopLevelItem(item);
    writeApi(Tcpsocketlist.at(tcpsocketindex),"<connect superserver success>");
}

/*  new tcpsocket connected and add it to treewidget;*/

void TcpServerBox::writeApi(QTcpSocket *tcpsocket,QByteArray serverinfo)
{
    Modulea->ui->lineEdit_2->setText(serverinfo);
    Network->writeSocket(Modulea->ui->checkBox,Modulea->ui->checkBox,Modulea->ui->checkBox,tcpsocket,Modulea->ui->lineEdit_2);
    Logger->displayLog("W",serverinfo,"Writedata function run completed");
}

/*  write to socket api;*/

void TcpServerBox::receiveCommand()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->displayLog("R",bytes,"Receivebytes function run completed");
    operatorCommand(tcpsocket,bytes);
}

/*  receive command and run;*/

void TcpServerBox::operatorCommand(QTcpSocket *tcpsocket,QByteArray bytes)
{
    if(bytes == "help")
    {
        for(int i = 0;i < Commandlist.count();i++)
        {
            writeApi(tcpsocket,Commandlist.at(i).toUtf8());
        }
        writeApi(tcpsocket,"\r\nInput index enter mode,such as 1;");
    }
    else
    {
        bool boola = false;
        int cmdindex = bytes.toInt(&boola);
        if(boola == true)
        {
            Commandindex = cmdindex;
            switch(cmdindex)
            {
                case 1:
                {
                    writeApi(tcpsocket,"\r\nString to string mode enter success;");
                    writeApi(tcpsocket,"Input string return string;");
                    writeApi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::stringToString);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiveCommand);
                    break;
                }
                case 2:
                {
                    writeApi(tcpsocket,"\r\nString to hex mode enter success;");
                    writeApi(tcpsocket,"Input string return hex;");
                    writeApi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::stringToHex);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiveCommand);
                    break;
                }
                case 3:
                {
                    writeApi(tcpsocket,"\r\nHex to string mode enter success;");
                    writeApi(tcpsocket,"Input hex return string;");
                    writeApi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::hexTostring);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiveCommand);
                    break;
                }
                case 4:
                {
                    writeApi(tcpsocket,"\r\nTransfer file mode enter success;");
                    writeApi(tcpsocket,"Input tran name.extensions fileseek filesize transfer file;");
                    writeApi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiverFiles);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiveCommand);
                    break;
                }
                case 5:
                {
                    writeApi(tcpsocket,"\r\nReceiver file mode enter success;");
                    writeApi(tcpsocket,"Input recv find server file list;");
                    writeApi(tcpsocket,"Input recv fileindex fileseek filesize receiver file;");
                    writeApi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::transferFiles);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiveCommand);
                    break;
                }
            }
        }
    }
}

/*  run tcp server command;*/

void TcpServerBox::disconnected()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    int port = tcpsocket->peerPort();
    for(int i = 0;i < Moduleb->ui->treeWidget->topLevelItemCount();i++)
    {
        QTreeWidgetItem *item = Moduleb->ui->treeWidget->topLevelItem(i);
        if(item->text(2) == QString::number(port))
        {
            delete item;
        }
    }
    Logger->displayLog("N","tcpsocket disconnect from server;","Disconnected function run completed");
}

/*  if client disconnected ,run this function;*/

void TcpServerBox::exitMode(QTcpSocket *tcpsocket)
{
    writeApi(tcpsocket,Commandlist.at(Commandindex).toUtf8() + " mode exit success");
    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiveCommand);
}

/*  exit for quit this mode;*/

void TcpServerBox::stringToString()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->displayLog("R",bytes,"Receivebytes function run completed");
    writeApi(tcpsocket,bytes);
    stringTostringMode(bytes,tcpsocket);
}

/*  string to string mode;*/

void TcpServerBox::stringTostringMode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&::TcpServerBox::stringToString);
        exitMode(tcpsocket);
    }
}

/*  if bytes is exit, quit this mode;*/

void TcpServerBox::stringToHex()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->displayLog("R",bytes,"Receivebytes function run completed");
    writeApi(tcpsocket,bytes.toHex());
    stringToHexMode(bytes,tcpsocket);
}

/*  string to hex mode;*/

void TcpServerBox::stringToHexMode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::stringToHex);
        exitMode(tcpsocket);
    }
}

/*  if bytes is exit, quit this mode;*/

void TcpServerBox::hexTostring()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->displayLog("R",bytes,"Receivebytes function run completed");
    writeApi(tcpsocket,bytes.fromHex(bytes));
    hexTostringMode(bytes,tcpsocket);
}

/*  string to hex mode;*/

void TcpServerBox::hexTostringMode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::hexTostring);
        exitMode(tcpsocket);
    }
}

/*  if bytes is exit, quit this mode;*/

void TcpServerBox::receiverFiles()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    receiverFilesMode(bytes,tcpsocket);
}

/*  receive file mode;*/

void TcpServerBox::receiverFilesMode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes.mid(0,5) == "tran ")
    {
        QStringList fileinfo = QString(bytes).split(" ");
        if(fileinfo.count() == 4)
        {
            bool boola = Core->checkFileName(fileinfo.at(1));
            bool boolb = false;
            bool boolc = false;
            int fileseek = fileinfo.at(2).toInt(&boolb);
            int filesize = QString(bytes).split(" ").at(3).toInt(&boolc);
            if(boola && boolb && fileseek >= 0 && boolc)
            {
                QString filename = "./__depycache__/__tcpserver__/" + fileinfo.at(1);
                disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiverFiles);
                writeApi(tcpsocket,filename.toUtf8() + " create success;");
                QFile *file = new QFile(filename);
                file->open(QIODevice::Append);
                file->seek(fileseek);
                ReceiverData *threadra = new ReceiverData(file,tcpsocket,filesize);
                connect(threadra,&ReceiverData::signalRa,this,&TcpServerBox::signalRaSlot);
                connect(threadra,&ReceiverData::finished,threadra,&QObject::deleteLater);
                threadra->start();
            }
            else
            {
                writeApi(tcpsocket,"check filename correctly ,fileseek or filesize could transform to int;");
            }
        }
        else
        {
            writeApi(tcpsocket,"command format: \"tran name.extensions fileseek filesize\"");
        }
    }
    else if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiverFiles);
        exitMode(tcpsocket);
    }
}

/*  input tran name.extensions filesize transfer start file;*/

void TcpServerBox::transferFiles()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    transferFilesMode(bytes,tcpsocket);
}

/*  receive file mode;*/

void TcpServerBox::transferFilesMode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes.mid(0,5) == "recv ")
    {
        getFilePath();
        QStringList fileinfo = QString(bytes).split(" ");
        if(fileinfo.count() == 4)
        {
            bool boola = false;
            bool boolb = false;
            bool boolc = false;
            int fileindex = fileinfo.at(1).toInt(&boola);
            int fileseek = fileinfo.at(2).toInt(&boolb);
            int filesize = fileinfo.at(3).toInt(&boolc);
            if(boola == true && fileindex < Fileslist.count() && fileindex >= 0 && boolb == true && fileseek >= 0 && boolc == true && filesize > 0 && filesize < 1024000)
            {
                QString filename = Tempfilepath + Fileslist.at(fileindex);
                tcpsocket->write(Core->readBytesInt64(filename,fileseek,filesize));
            }
            else
            {
                writeApi(tcpsocket,"check fileindex or fileseek or filesize correctly;");
            }
        }
        else
        {
            writeApi(tcpsocket,"command format: \"recv fileindex fileseek filesize\"");
            writeApi(tcpsocket,"server file list: ");
            for(int i = 0;i < Fileslist.count();i++)
            {
                QFile file(Tempfilepath + Fileslist.at(i));
                writeApi(tcpsocket,"<" + QByteArray::number(i) + "><" + Fileslist.at(i).toUtf8() + "><" + QByteArray::number(file.size()) + ">");
            }
        }
    }
    else if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::transferFiles);
        exitMode(tcpsocket);
    }
}

/*  input recv fileindex fileseek filesize receive file;*/

void TcpServerBox::getFilePath()
{
    Fileslist = Dir->entryList(QDir::Files | QDir::Readable, QDir::Name);
}

/*  get fileslist;*/

void TcpServerBox::signalRaSlot(QFile *file,QTcpSocket *tcpsocket,QString string)
{
    file->close();
    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::receiverFiles);
    writeApi(tcpsocket,file->fileName().toUtf8() + string.toUtf8());
}

/*  write file byte to local file;*/

ReceiverData::ReceiverData(QFile *file,QTcpSocket *tcpsocket,int size)
{
    File = file;
    Tcpsocket = tcpsocket;
    Size = size;
}

ReceiverData::~ReceiverData()
{

}

void ReceiverData::initRun()
{
    Sizewrite = 0;
    Timeout = 1000;
    Inittime = 0;
}

void ReceiverData::run()
{
    initRun();
    while(Size > Sizewrite)
    {
        if(Inittime < Timeout)
        {
            QThread::msleep(1);
            if(Tcpsocket->bytesAvailable() > 0)
            {
                QByteArray bytes = Tcpsocket->readAll();
                Sizewrite = Sizewrite + bytes.size();
                File->write(bytes);
                Inittime = 0;
            }
            else
            {
                Inittime = Inittime + 50;
                QThread::msleep(50);
            }
        }
        else
        {
            emit signalRa(File,Tcpsocket," receiver timeout;");
            break;
        }
    }
    if(Size <= Sizewrite)
    {
        emit signalRa(File,Tcpsocket," receiver completed;");
    }
}

/*  cal time out and emit signal;*/
