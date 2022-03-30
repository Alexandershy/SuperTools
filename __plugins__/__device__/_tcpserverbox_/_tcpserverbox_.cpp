#include "_tcpserverbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new TcpServerBox();
}

/*  return class TcpServerBox new instance pointer;*/

TcpServerBox::TcpServerBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("TcpServerBox");
    Setgroupbox(2,1);
    Setstretch({1,99},{100});
    Init();
}

TcpServerBox::~TcpServerBox()
{
    Forcedisconnect();
}

void TcpServerBox::Init()
{
    Objectinit();
    Widgetlistinit();
    Tempdirinit();
}

void TcpServerBox::Objectinit()
{
    SuperN = new SuperNetwork(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Tcpserver = new QTcpServer(this);
    connect(Tcpserver,                  &QTcpServer::newConnection,     this,&TcpServerBox::Newtcpsocket);
    connect(Modulea->ui->pushButton_2,  &QPushButton::clicked,          this,&TcpServerBox::Getlocalipaddress);
    connect(Modulea->ui->comboBox,      &QComboBox::currentTextChanged, this,&TcpServerBox::Enablestarttcpserver);
    connect(Modulea->ui->comboBox_2,    &QComboBox::currentTextChanged, this,&TcpServerBox::Enablestarttcpserver);
    connect(Modulea->ui->pushButton_3,  &QPushButton::clicked,          this,&TcpServerBox::Starttcpserver);
    connect(Modulea->ui->pushButton_4,  &QPushButton::clicked,          this,&TcpServerBox::Closetcpserver);
}

void TcpServerBox::Widgetlistinit()
{
    Connectwidgetet     = {Modulea->ui->pushButton_4};
    Connectwidgetef     = {Modulea->ui->comboBox,Modulea->ui->comboBox_2,Modulea->ui->pushButton_2,Modulea->ui->pushButton_3};
    Disconnectwidgetet  = {Modulea->ui->comboBox,Modulea->ui->comboBox_2,Modulea->ui->pushButton_2,Modulea->ui->pushButton_3};
    Disconnectwidgetef  = {Modulea->ui->pushButton_4};
}

/*  widget list init;*/

void TcpServerBox::Tempdirinit()
{
    Dir = new QDir(Tempfilepath);
}

/*  set temp init dir;*/

void TcpServerBox::Getlocalipaddress()
{
    Modulea->ui->comboBox->clear();
    Networkinterface = QNetworkInterface::allInterfaces();
    for(int i = 0;i < Networkinterface.count();i++)
    {
        Networkaddressentry = Networkinterface.at(i).addressEntries();
        SuperN->Getlocalipaddress(&Networkaddressentry,Modulea->ui->comboBox);
    }
    for(int i = 0;i < Modulea->ui->comboBox->count();i++)
    {
        Logger->Displaylog("N",Modulea->ui->comboBox->itemText(i),"Getlocalipaddress function run completed");
    }
}

/*  get system ip address to combobox;*/

void TcpServerBox::Enablestarttcpserver()
{
    bool boola;
    bool boolb;
    boola = SuperC->Checkiprules(Modulea->ui->comboBox->currentText());
    int port = Modulea->ui->comboBox_2->currentText().toInt(&boolb);
    if(boola == true && boolb == true && port > 100 && port < 65535)
    {
        Modulea->ui->pushButton_3->setEnabled(true);
    }
}

/*  enable start tcp server button or not;*/

void TcpServerBox::Starttcpserver()
{
    QHostAddress ipaddress(Modulea->ui->comboBox->currentText());
    Tcpserver->listen(ipaddress,Modulea->ui->comboBox_2->currentText().toInt());
    if(Tcpserver->isListening())
    {
        SuperC->Enablewidgetlist(&Connectwidgetet,true);
        SuperC->Enablewidgetlist(&Connectwidgetef,false);
        Logger->Displaylog("N","server start success","Starttcpserver function run completed");
    }
    else
    {
        Logger->Displaylog("N","server start failed","Starttcpserver function run completed");
    }
}

/*  start tcp server;*/

void TcpServerBox::Closetcpserver()
{
    Tcpserver->close();
    Forcedisconnect();
    if(!Tcpserver->isListening())
    {
        SuperC->Enablewidgetlist(&Disconnectwidgetet,true);
        SuperC->Enablewidgetlist(&Disconnectwidgetef,false);
        Logger->Displaylog("N","server close success","Closetcpserver function run completed");
    }
    else
    {
        Logger->Displaylog("N","server close failed","Closetcpserver function run completed");
    }
}

/* close tcp server and tick off all client;*/

void TcpServerBox::Forcedisconnect()
{
    QList<int> connectsocket;
    for(int i = 0;i < Moduleb->ui->treeWidget->topLevelItemCount();i++)
    {
        connectsocket.append(Moduleb->ui->treeWidget->topLevelItem(i)->text(0).toInt());
    }
    for(int j = 0;j < connectsocket.count();j++)
    {
        SuperN->Disconnecttcpserver(Tcpsocketlist.at(connectsocket.at(j)),1000);
    }
}

/*  tick off all client;*/

void TcpServerBox::Newtcpsocket()
{
    int tcpsocketindex = Tcpsocketlist.count();
    Tcpsocketlist.append(Tcpserver->nextPendingConnection());
    QString ipaddress = Tcpsocketlist.at(tcpsocketindex)->peerAddress().toString();
    int port = Tcpsocketlist.at(tcpsocketindex)->peerPort();
    Logger->Displaylog("N",ipaddress + "::" + QString::number(port) + " connect success;","Newtcpsocket function run completed");
    connect(Tcpsocketlist.at(tcpsocketindex),&QTcpSocket::readyRead,this,&TcpServerBox::Receivecommand);
    connect(Tcpsocketlist.at(tcpsocketindex),&QTcpSocket::disconnected,this,&TcpServerBox::Disconnected);
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,QString::number(tcpsocketindex));
    item->setText(1,ipaddress);
    item->setText(2,QString::number(port));
    Moduleb->ui->treeWidget->addTopLevelItem(item);
    Writeapi(Tcpsocketlist.at(tcpsocketindex),"<connect superserver success>");
}

/*  new tcpsocket connected and add it to treewidget;*/

void TcpServerBox::Writeapi(QTcpSocket *tcpsocket,QByteArray serverinfo)
{
    Modulea->ui->lineEdit_2->setText(serverinfo);
    SuperN->Writesocket(Modulea->ui->checkBox,Modulea->ui->checkBox,Modulea->ui->checkBox,tcpsocket,Modulea->ui->lineEdit_2);
    Logger->Displaylog("W",serverinfo,"Writedata function run completed");
}

/*  write to socket api;*/

void TcpServerBox::Receivecommand()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->Displaylog("R",bytes,"Receivebytes function run completed");
    Operatorcommand(tcpsocket,bytes);
}

/*  receive command and run;*/

void TcpServerBox::Operatorcommand(QTcpSocket *tcpsocket,QByteArray bytes)
{
    if(bytes == "help")
    {
        for(int i = 0;i < Commandlist.count();i++)
        {
            Writeapi(tcpsocket,Commandlist.at(i).toUtf8());
        }
        Writeapi(tcpsocket,"\r\nInput index enter mode,such as 1;");
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
                    Writeapi(tcpsocket,"\r\nString to string mode enter success;");
                    Writeapi(tcpsocket,"Input string return string;");
                    Writeapi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Stringtostring);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receivecommand);
                    break;
                }
                case 2:
                {
                    Writeapi(tcpsocket,"\r\nString to hex mode enter success;");
                    Writeapi(tcpsocket,"Input string return hex;");
                    Writeapi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Stringtohex);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receivecommand);
                    break;
                }
                case 3:
                {
                    Writeapi(tcpsocket,"\r\nHex to string mode enter success;");
                    Writeapi(tcpsocket,"Input hex return string;");
                    Writeapi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Hextostring);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receivecommand);
                    break;
                }
                case 4:
                {
                    Writeapi(tcpsocket,"\r\nTransfer file mode enter success;");
                    Writeapi(tcpsocket,"Input tran name.extensions fileseek filesize transfer file;");
                    Writeapi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receiverfiles);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receivecommand);
                    break;
                }
                case 5:
                {
                    Writeapi(tcpsocket,"\r\nReceiver file mode enter success;");
                    Writeapi(tcpsocket,"Input recv find server file list;");
                    Writeapi(tcpsocket,"Input recv fileindex fileseek filesize receiver file;");
                    Writeapi(tcpsocket,"Input exit quit this mode;");
                    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Transferfiles);
                    disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receivecommand);
                    break;
                }
            }
        }
    }
}

/*  run tcp server command;*/

void TcpServerBox::Disconnected()
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
    Logger->Displaylog("N","tcpsocket disconnect from server;","Disconnected function run completed");
}

/*  if client disconnected ,run this function;*/

void TcpServerBox::Exitmode(QTcpSocket *tcpsocket)
{
    Writeapi(tcpsocket,Commandlist.at(Commandindex).toUtf8() + " mode exit success");
    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receivecommand);
}

/*  exit for quit this mode;*/

void TcpServerBox::Stringtostring()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->Displaylog("R",bytes,"Receivebytes function run completed");
    Writeapi(tcpsocket,bytes);
    Stringtostringmode(bytes,tcpsocket);
}

/*  string to string mode;*/

void TcpServerBox::Stringtostringmode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Stringtostring);
        Exitmode(tcpsocket);
    }
}

/*  if bytes is exit, quit this mode;*/

void TcpServerBox::Stringtohex()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->Displaylog("R",bytes,"Receivebytes function run completed");
    Writeapi(tcpsocket,bytes.toHex());
    Stringtohexmode(bytes,tcpsocket);
}

/*  string to hex mode;*/

void TcpServerBox::Stringtohexmode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Stringtohex);
        Exitmode(tcpsocket);
    }
}

/*  if bytes is exit, quit this mode;*/

void TcpServerBox::Hextostring()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Logger->Displaylog("R",bytes,"Receivebytes function run completed");
    Writeapi(tcpsocket,bytes.fromHex(bytes));
    Hextostringmode(bytes,tcpsocket);
}

/*  string to hex mode;*/

void TcpServerBox::Hextostringmode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Hextostring);
        Exitmode(tcpsocket);
    }
}

/*  if bytes is exit, quit this mode;*/

void TcpServerBox::Receiverfiles()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Receiverfilesmode(bytes,tcpsocket);
}

/*  receive file mode;*/

void TcpServerBox::Receiverfilesmode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes.mid(0,5) == "tran ")
    {
        QStringList fileinfo = QString(bytes).split(" ");
        if(fileinfo.count() == 4)
        {
            bool boola = SuperC->Checkfilename(fileinfo.at(1));
            bool boolb = false;
            bool boolc = false;
            int fileseek = fileinfo.at(2).toInt(&boolb);
            int filesize = QString(bytes).split(" ").at(3).toInt(&boolc);
            if(boola && boolb && fileseek >= 0 && boolc)
            {
                QString filename = "./__depycache__/__tcpserver__/" + fileinfo.at(1);
                disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receiverfiles);
                Writeapi(tcpsocket,filename.toUtf8() + " create success;");
                QFile *file = new QFile(filename);
                file->open(QIODevice::Append);
                file->seek(fileseek);
                ReceiverData *threadra = new ReceiverData(file,tcpsocket,filesize);
                connect(threadra,&ReceiverData::Signalra,this,&TcpServerBox::Signalraslot);
                connect(threadra,&ReceiverData::finished,threadra,&QObject::deleteLater);
                threadra->start();
            }
            else
            {
                Writeapi(tcpsocket,"check filename correctly ,fileseek or filesize could transform to int;");
            }
        }
        else
        {
            Writeapi(tcpsocket,"command format: \"tran name.extensions fileseek filesize\"");
        }
    }
    else if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receiverfiles);
        Exitmode(tcpsocket);
    }
}

/*  input tran name.extensions filesize transfer start file;*/

void TcpServerBox::Transferfiles()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    QByteArray bytes = tcpsocket->readAll();
    Transferfilesmode(bytes,tcpsocket);
}

/*  receive file mode;*/

void TcpServerBox::Transferfilesmode(QByteArray bytes,QTcpSocket *tcpsocket)
{
    if(bytes.mid(0,5) == "recv ")
    {
        Getfilepath();
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
                tcpsocket->write(SuperC->Readbytesint64(filename,fileseek,filesize));
            }
            else
            {
                Writeapi(tcpsocket,"check fileindex or fileseek or filesize correctly;");
            }
        }
        else
        {
            Writeapi(tcpsocket,"command format: \"recv fileindex fileseek filesize\"");
            Writeapi(tcpsocket,"server file list: ");
            for(int i = 0;i < Fileslist.count();i++)
            {
                QFile file(Tempfilepath + Fileslist.at(i));
                Writeapi(tcpsocket,"<" + QByteArray::number(i) + "><" + Fileslist.at(i).toUtf8() + "><" + QByteArray::number(file.size()) + ">");
            }
        }
    }
    else if(bytes == "exit")
    {
        disconnect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Transferfiles);
        Exitmode(tcpsocket);
    }
}

/*  input recv fileindex fileseek filesize receive file;*/

void TcpServerBox::Getfilepath()
{
    Fileslist = Dir->entryList(QDir::Files | QDir::Readable, QDir::Name);
}

/*  get fileslist;*/

void TcpServerBox::Signalraslot(QFile *file,QTcpSocket *tcpsocket,QString string)
{
    file->close();
    connect(tcpsocket,&QTcpSocket::readyRead,this,&TcpServerBox::Receiverfiles);
    Writeapi(tcpsocket,file->fileName().toUtf8() + string.toUtf8());
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

void ReceiverData::Initrun()
{
    Sizewrite = 0;
    Timeout = 1000;
    Inittime = 0;
}

void ReceiverData::run()
{
    Initrun();
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
            emit Signalra(File,Tcpsocket," receiver timeout;");
            break;
        }
    }
    if(Size <= Sizewrite)
    {
        emit Signalra(File,Tcpsocket," receiver completed;");
    }
}

/*  cal time out and emit signal;*/
