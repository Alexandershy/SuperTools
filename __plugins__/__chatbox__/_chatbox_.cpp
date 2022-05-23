#include "_chatbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new ChatBox();
}

/*  return class ChatBox new instance pointer;*/

ChatBox::ChatBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("ChatBox");
    setGroupBox(2,2);
    setStretch({1,99},{99,1});
    init();
}

ChatBox::~ChatBox()
{

}

void ChatBox::resizeEvent(QResizeEvent *)
{
    emit signalCa();
}

void ChatBox::init()
{
    moduleInit();
    userInit();
    clientInit();
    serverInit();
}

void ChatBox::moduleInit()
{
    Modulea = new ChatModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ChatModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Modulec = new ChatModuleC(this,Rightgroupboxlist.at(0)->Insidelayout);
    Moduled = new ChatModuleD(this,Rightgroupboxlist.at(1)->Insidelayout);
    connect(Modulea->ui->pushButton_3,                       &QPushButton::clicked,              this,&ChatBox::getContacts);
    connect(Modulea->ui->pushButton_10,                      &QPushButton::clicked,              this,&ChatBox::openProfile);
    connect(Modulea->ui->pushButton,                         &QPushButton::clicked,              this,&ChatBox::openSharedFiles);
    connect(Moduleb->ui->treeWidget,                         &QTreeWidget::itemPressed,          this,&ChatBox::openContacts);
    connect(Modulec->ui->scrollArea->verticalScrollBar(),    &QAbstractSlider::rangeChanged,     this,&ChatBox::moveToBottom);
    connect(Moduled->ui->pushButton_5,                       &QPushButton::clicked,              this,&ChatBox::openContactsShared);
    connect(Moduled->ui->pushButton_4,                       &QPushButton::clicked,              this,&ChatBox::getChatAnwser);
    connect(Moduled->ui->textEdit,                           &QTextEdit::textChanged,            this,&ChatBox::enableSendButton);
}

/*  module init;*/

void ChatBox::userInit()
{
    Username = QDir::home().dirName() + " " + QHostInfo::localHostName();
    Userfolder = "./__depycache__/__chat__/__" + Username + "__/";
    Userprofile = Userfolder + "_user_.png";
    Usersharedfile = Userfolder + "_filesshared_.txt";
    Modulea->ui->lineEdit->setText(Username);
    Modulec->ui->lineEdit_2->setText(Username);
}

/*  set user init;*/

void ChatBox::clientInit()
{
    Timerca             = new QTimer(this);
    Timercb             = new QTimer(this);
    Udppackclient       = new QUdpSocket(this);
    Udpchatclient       = new QUdpSocket(this);
    Tcpfileinfoclient   = new QTcpSocket(this);
    Tcpfilebyteclient   = new QTcpSocket(this);
    Infodialog          = new ChatInfoDialog(nullptr,Modulea->ui->lineEdit);
    Progressbardialog   = new SuperProgressBarDialog();
    Timercb->setInterval(1000);
    Timerca->setInterval(1000);
    Udppackclient->bind(37061,QAbstractSocket::ShareAddress);
    Udpchatclient->bind(37064,QAbstractSocket::ShareAddress);
    connect(Progressbardialog,  &SuperProgressBarDialog::signalPa,  this,&ChatBox::getFileByteStop);
    connect(Timerca,            &QTimer::timeout,                   this,&ChatBox::getContactsfSlot);
    connect(Timercb,            &QTimer::timeout,                   this,&ChatBox::getChatAnwserfSlot);
    connect(Udppackclient,      &QUdpSocket::readyRead,             this,&ChatBox::getContactstSlot);
    connect(Tcpfileinfoclient,  &QTcpSocket::readyRead,             this,&ChatBox::getFileInfoSlot);
    //connect(Tcpfileinfoclient,  &QTcpSocket::disconnected,        this,&ChatBox::Getfileinfoslot);
    connect(Tcpfilebyteclient,  &QTcpSocket::readyRead,             this,&ChatBox::getFileByteSlot);
    connect(Tcpfilebyteclient,  &QTcpSocket::disconnected,          this,&ChatBox::getFileByteEnd);
    connect(Udpchatclient,      &QUdpSocket::readyRead,             this,&ChatBox::getChatAnwsertSlot);
}

/*  set client init;*/

void ChatBox::serverInit()
{
    Udppackserver       = new QUdpSocket(this);
    Tcpfileinfoserver   = new QTcpServer(this);
    Tcpfilebyteserver   = new QTcpServer(this);
    Udpchatserver       = new QUdpSocket(this);
    Udppackserver->bind(37071,QAbstractSocket::ShareAddress);
    Tcpfileinfoserver->listen(Udppackserver->localAddress(),37072);
    Tcpfilebyteserver->listen(Udppackserver->localAddress(),37073);
    Udpchatserver->bind(37074,QAbstractSocket::ShareAddress);
    connect(Udppackserver,      &QUdpSocket::readyRead,     this,&ChatBox::returnContacts);
    connect(Tcpfileinfoserver,  &QTcpServer::newConnection, this,&ChatBox::newFileInfoTcpsocket);
    connect(Tcpfilebyteserver,  &QTcpServer::newConnection, this,&ChatBox::newFileByteTcpsocket);
    connect(Udpchatserver,      &QUdpSocket::readyRead,     this,&ChatBox::returnChatAnwser);
}

/*  set server init;*/

void ChatBox::openProfile()
{
    Infodialog->show();
}

/*  edit your profile;*/

void ChatBox::openSharedFiles()
{
    ChatShareDialog *usersharedialog = new ChatShareDialog(nullptr,Modulea->ui->lineEdit);
    usersharedialog->show();
}

/*  edit your shared files;*/

void ChatBox::getContacts()
{
    Moduleb->ui->treeWidget->clear();
    Udppackclient->writeDatagram("supertools<split>contacts",QHostAddress::Broadcast,37071);
    Modulea->ui->pushButton_3->setEnabled(false);
    Moduled->ui->pushButton_5->setEnabled(false);
    Timerca->start();
}

/*  broadcast supertools for get online device info;*/

void ChatBox::getContactstSlot()
{
    QNetworkDatagram datagram = Udppackclient->receiveDatagram();
    QByteArray info = datagram.data();
    if(info.contains("<split>") == true)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(Moduleb->ui->treeWidget);
        item->setText(0,QString(info).split("<split>").at(0));
        item->setText(1,datagram.senderAddress().toString());
        item->setText(2,QString(info).split("<split>").at(1));
        Moduleb->ui->treeWidget->addTopLevelItem(item);
        getContactsfSlot();
    }
}

/*  anwser device has online and local time;*/

void ChatBox::getContactsfSlot()
{
    if(Modulea->ui->pushButton_3->isEnabled() == false)
    {
        Modulea->ui->pushButton_3->setEnabled(true);
        Timerca->stop();
    }
}

/*  client have not receive any server anwser;*/

void ChatBox::openContacts()
{
    Core->deleteAllItemsOfLayout(Modulec->ui->verticalLayout_9);
    Contactsname = Moduleb->ui->treeWidget->currentItem()->text(0);
    Contactsfolder = "./__depycache__/__chat__/__" + Contactsname + "__/";
    Hostaddress.setAddress(Moduleb->ui->treeWidget->currentItem()->text(1).split("ffff:").at(1).split("%").at(0));
    Modulec->ui->lineEdit_2->setText(Contactsname);
    Moduled->ui->pushButton_5->setEnabled(true);
    downloadSharedFiles(-1,Contactsfolder);
    addContactsMessageRecord();
}

/*  open contacts and get his profile and file shared;*/

void ChatBox::addContactsMessageRecord()
{
    QString datatime = QDateTime::currentDateTime().toString("yyyyMMdd");
    Core->creatFolder(Contactsfolder);
    Messagerecorded = Contactsfolder + "_" + datatime + "_.txt";
    QFile file(Messagerecorded);
    if(file.exists())
    {
        QStringList messagelist = Core->readOnlyFile(file.fileName()).split(":\r\n<messagesplits>\r\n");
        QString selfsplitchar = Modulea->ui->lineEdit->text() + " self:\r\n";
        QString othersplitchar = Contactsname + " other:\r\n";
        for(int i = 0;i < messagelist.count();i++)
        {
            QString message = messagelist.at(i);
            if(message.contains(othersplitchar))
            {
                Chatter *chatter = new Chatter(Modulec->ui->scrollArea,"other",Contactsname,message.split(othersplitchar).at(1));
                connect(this,&ChatBox::signalCa,chatter,&Chatter::adjustSize);
                Modulec->ui->verticalLayout_9->addWidget(chatter);
            }
            else if(messagelist.at(i).contains(selfsplitchar))
            {
                Chatter *chatter = new Chatter(Modulec->ui->scrollArea,"self",Modulea->ui->lineEdit->text(),messagelist.at(i).split(selfsplitchar).at(1));
                connect(this,&ChatBox::signalCa,chatter,&Chatter::adjustSize);
                Modulec->ui->verticalLayout_9->addWidget(chatter);
            }
        }
    }
    else
    {
        Core->creatFile(Messagerecorded);
    }
}

/*  add today's chatter with contacts;*/

void ChatBox::getFileInfo(QByteArray fileindex)
{
    Network->connectTcpServer(Tcpfileinfoclient,Moduleb->ui->treeWidget->currentItem()->text(1).split("ffff:").at(1).split("%").at(0),37072,1000);
    if(Tcpfileinfoclient->state() == QTcpSocket::ConnectedState)
    {
        QByteArray command = fileindex + "<split>";
        command.resize(128);
        Tcpfileinfoclient->write(command);
        Progressbardialog->setTitle("Receive " + Contactsname + " profileing...");
        Progressbardialog->setValueMessage(0,"(1/2)check fileinfo...");
        Progressbardialog->show();
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"connect server error;\ntry again;");
        notedialog->messageInit();
    }
}

/*  send command to get file's info;*/

void ChatBox::getFileInfoSlot()
{
    if(Tcpfileinfoclient->bytesAvailable() == 512)
    {
        QStringList fileinfolist = QString(Tcpfileinfoclient->readAll()).split("<split>");
        Tranfilepath = Contactsfolder + fileinfolist.at(1);
        Tranfilehash = fileinfolist.at(4);
        Network->disConnectTcpServer(Tcpfileinfoclient,1000);
        if(replaceFile(Tranfilepath,fileinfolist.at(2),Tranfilehash))
        {
            Core->creatFile(Tranfilepath);
            Progressbardialog->setValueMessage(0,"(1/2)receive fileinfo success");
            Network->connectTcpServer(Tcpfilebyteclient,Moduleb->ui->treeWidget->currentItem()->text(1).split("ffff:").at(1).split("%").at(0),37073,1000);
            Tranendmessage = "Get " + Tranfilepath  + " interrupt;";
            getFileByte();
        }
        else
        {
            copyToTargetPath();
            Progressbardialog->setValueMessage(100,"(2/2)check fileinfo success");
        }
    }
}

/*  analysis file's info,include name,size,birthtime,1mbit hash,available;*/

bool ChatBox::replaceFile(QString filename,QString filesize,QString filehash)
{
    bool boola = false;
    QFileInfo file(filename);
    Tranfilesize = filesize.toULongLong(&boola);
    if(file.exists())
    {
        if((file.size() != Tranfilesize || Core->getFileHash(filename) != filehash.toUtf8()) && boola == true)
        {
            QFile::remove(filename);
            return true;
        }
        return false;
    }
    return true;
}

/*  check file exist or changed and return result;*/

void ChatBox::getFileByte()
{
    if(Tranfilesize - Tranwritecompletedsize >= Trandatasize)
    {
        QByteArray command = QByteArray::number(Fileindexreceiving) + "<split>" + QByteArray::number(Tranwritecompletedsize) + "<split>" + QByteArray::number(Trandatasize) + "<split>";
        command.resize(128);
        Tcpfilebyteclient->write(command);
    }
    else if(Tranfilesize - Tranwritecompletedsize < Trandatasize && Tranfilesize != Tranwritecompletedsize)
    {
        Trandatasize = Tranfilesize - Tranwritecompletedsize;
        QByteArray command = QByteArray::number(Fileindexreceiving) + "<split>" + QByteArray::number(Tranwritecompletedsize) + "<split>" + QByteArray::number(Trandatasize) + "<split>";
        command.resize(128);
        Tcpfilebyteclient->write(command);
    }
    else
    {
        Tranendmessage = "Get " + Tranfilepath  + " completed;";
        getFileByteStop();
    }
}

/*  send command to get file bytes;*/

void ChatBox::getFileByteStop()
{
    Network->disConnectTcpServer(Tcpfilebyteclient,1000);
}

/*  stop get file bytes;*/

void ChatBox::getFileByteEnd()
{
    if(Fileindexreceiving >= 0)
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,Tranendmessage);
        notedialog->messageInit();
    }
    Core->appendBytes(Tranfilepath,Trandata);
    Tranwritecompletedsize = 0;
    Trandata.clear();
    Trandatasize = 1024000;
    copyToTargetPath();
    Progressbardialog->setValueMessage(100,"(2/2)" + Tranendmessage);
    emit signalCb();
}

/*  receive file bytes end,write bytes to local file;*/

void ChatBox::copyToTargetPath()
{
    QStringList filepathlist = Tranfilepath.split("/");
    QString newtargetpath = Targetfolder + Core->getListLastMember(&filepathlist);
    if(Tranfilepath != newtargetpath)
    {
        QFile::remove(newtargetpath);
        QFile::copy(Tranfilepath,newtargetpath);
    }
}

/*  download to new target path;*/

void ChatBox::getFileByteSlot()
{
    if(Tcpfilebyteclient->bytesAvailable() == Trandatasize)
    {
        QByteArray data = Tcpfilebyteclient->readAll();
        Trandata.append(data);
        Tranwritecompletedsize = Tranwritecompletedsize + data.size();
        Progressbardialog->setValueMessage(double(Tranwritecompletedsize) / Tranfilesize * 99,"(2/2)receive file byte...");
        getFileByte();
    }
    else if(Trandata.size() > Trandatasize * 100)
    {
        Core->appendBytes(Tranfilepath,Trandata);
        Trandata.clear();
    }
}

/*  receive file bytes and save as cache;*/

void ChatBox::openContactsShared()
{
    downloadSharedFiles(-2,Contactsfolder);
    ChatShareDialog *contactssharedialog = new ChatShareDialog(nullptr,Modulec->ui->lineEdit_2);
    connect(contactssharedialog,&ChatShareDialog::signalCa,this,&ChatBox::downloadSharedFiles);
    connect(this,&ChatBox::signalCb,contactssharedialog,&ChatShareDialog::refreshSharedFiles);
    contactssharedialog->show();
}

/*  open contacts and get its profile and file shared;*/

void ChatBox::downloadSharedFiles(int fileindex,QString path)
{
    Targetfolder = path;
    Fileindexreceiving = fileindex;
    getFileInfo(QByteArray::number(Fileindexreceiving));
}

/*  download files' api;*/

void ChatBox::enableSendButton()
{
    if(Moduled->ui->textEdit->toPlainText().isEmpty() || Hostaddress.isNull())
    {
        Moduled->ui->pushButton_4->setEnabled(false);
    }
    else
    {
        Moduled->ui->pushButton_4->setEnabled(true);
    }
}

/*  enable send button or not;*/

void ChatBox::getChatAnwser()
{
    Moduled->ui->pushButton_4->setText("message sending");
    Udpchatclient->writeDatagram(Modulea->ui->lineEdit->text().toUtf8() + "<namesplit>" + Moduled->ui->textEdit->toHtml().toUtf8(),Hostaddress,37074);
    Timercb->start();
}

/*  send message to contacts and command for anwser;*/

void ChatBox::moveToBottom()
{
    Modulec->ui->scrollArea->verticalScrollBar()->setValue(Modulec->ui->scrollArea->verticalScrollBar()->maximum());
}

/*  scroll area move to bottom when send message;*/

void ChatBox::getChatAnwsertSlot()
{
    QNetworkDatagram datagram = Udpchatclient->receiveDatagram();
    QByteArray info = datagram.data();
    if(info == "OK")
    {
        Timercb->stop();
        Moduled->ui->pushButton_4->setText("Send");
        QString message = Moduled->ui->textEdit->toHtml();
        Core->appendFile(Messagerecorded,Modulea->ui->lineEdit->text() + " self:\r\n" + message + ":\r\n<messagesplits>\r\n");
        Chatter *chatter = new Chatter(Modulec->ui->scrollArea,"self",Modulea->ui->lineEdit->text(),message);
        connect(this,&ChatBox::signalCa,chatter,&Chatter::adjustSize);
        Modulec->ui->verticalLayout_9->addWidget(chatter);
        Moduled->ui->textEdit->clear();
    }
}

/*  receive contacts anwser and record message to local;*/

void ChatBox::getChatAnwserfSlot()
{
    Timercb->stop();
    Moduled->ui->pushButton_4->setText("Resend");
}

/*  set send text as resend,stop timer;*/

//***************************************************Server*********************************************************//

void ChatBox::newFileInfoTcpsocket()
{
    QTcpSocket *fileinfosocket = Tcpfileinfoserver->nextPendingConnection();
    connect(fileinfosocket,&QTcpSocket::readyRead,this,&ChatBox::returnFileInfo);
}

/*  new tcpsocket has connected,connect its slot;*/

void ChatBox::newFileByteTcpsocket()
{
    QTcpSocket *filebytesocket = Tcpfilebyteserver->nextPendingConnection();
    connect(filebytesocket,&QTcpSocket::readyRead,this,&ChatBox::returnFileByte);
}

/*  new tcpsocket has connected,connect its slot;*/

void ChatBox::returnContacts()
{
    QNetworkDatagram datagram = Udppackserver->receiveDatagram();
    if(datagram.data() == "supertools<split>contacts")
    {
        QByteArray time = QDateTime::currentDateTime().toString("hh:mm:ss").toUtf8();
        Udppackserver->writeDatagram(Username.toUtf8() + "<split>" + time,datagram.senderAddress(),37061);
    }
}

/*  anwser device has online and local time;*/

void ChatBox::returnFileInfo()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    if(tcpsocket->bytesAvailable() == 128)
    {
        QByteArray command = tcpsocket->readAll();
        int fileindex = QString(command).split("<split>").at(0).toInt();
        QByteArray fileinfo;
        switch (fileindex)
        {
            case -1:
            {
                Core->getFileInfoByte(Userprofile,&fileinfo);
                fileinfo.resize(512);
                tcpsocket->write(fileinfo);
                break;
            }
            case -2:
            {
                Core->getFileInfoByte(Usersharedfile,&fileinfo);
                fileinfo.resize(512);
                tcpsocket->write(fileinfo);
                break;
            }
            default:
            {
                Fileinfolist = Core->readOnlyFile(Usersharedfile).split("\r\n");
                QString filename = Fileinfolist.at(fileindex).split("<split>").at(0) + Fileinfolist.at(fileindex).split("<split>").at(1);
                Core->getFileInfoByte(filename,&fileinfo);
                fileinfo.resize(512);
                tcpsocket->write(fileinfo);
            }
        }
    }
}

/*  return file's info;*/

void ChatBox::returnFileByte()
{
    QTcpSocket *tcpsocket = (QTcpSocket*)sender();
    if(tcpsocket->bytesAvailable() == 128)
    {
        QStringList fileinfo = QString(tcpsocket->readAll()).split("<split>");
        int fileindex = fileinfo.at(0).toInt();
        qint64 fileseek = fileinfo.at(1).toLongLong();
        qint64 datasize = fileinfo.at(2).toLongLong();
        switch (fileindex)
        {
            case -1:
            {
                QByteArray filedata = Core->readBytesInt64(Userprofile,fileseek,datasize);
                tcpsocket->write(filedata);
                break;
            }
            case -2:
            {
                QByteArray filedata = Core->readBytesInt64(Usersharedfile,fileseek,datasize);
                tcpsocket->write(filedata);
                break;
            }
            default:
            {
                QString filepath = Fileinfolist.at(fileindex).split("<split>").at(0) + Fileinfolist.at(fileindex).split("<split>").at(1);
                QByteArray filedata = Core->readBytesInt64(filepath,fileseek,datasize);
                tcpsocket->write(filedata);
            }
        }
    }
}

/*  return file's bytes;*/

void ChatBox::returnChatAnwser()
{
    QNetworkDatagram datagram = Udpchatserver->receiveDatagram();
    QStringList messageinfo = QString(datagram.data()).split("<namesplit>");
    if(messageinfo.count() == 2)
    {
        QString username = messageinfo.at(0);
        QString message = messageinfo.at(1);
        QString messagefolder = "./__depycache__/__chat__/__" + username + "__";
        QString messagerecorded = messagefolder + "/_" + QDateTime::currentDateTime().toString("yyyyMMdd") + "_.txt";
        Core->creatFolder(messagefolder);
        Core->appendFile(messagerecorded,username + " other:\r\n" + message + ":\r\n<messagesplits>\r\n");
        Modulec->ui->comboBox->insertItem(0,"a message from " + username);
        Modulec->ui->comboBox->setCurrentIndex(0);
        Udpchatserver->writeDatagram("OK",datagram.senderAddress(),37064);
        if(username == Contactsname)
        {
            Chatter *chatter = new Chatter(Modulec->ui->scrollArea,"other",Contactsname,message);
            connect(this,&ChatBox::signalCa,chatter,&Chatter::adjustSize);
            Modulec->ui->verticalLayout_9->addWidget(chatter);
        }
    }
}

/*  receive contacts' message and receive anwser;*/
