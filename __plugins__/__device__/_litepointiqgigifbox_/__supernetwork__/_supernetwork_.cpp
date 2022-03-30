#include "_supernetwork_.h"

SuperNetwork::SuperNetwork(QObject* parent)
    :QObject(parent)
{

}

SuperNetwork::~SuperNetwork()
{

}

void SuperNetwork::Getlocalipaddress(QList<QNetworkAddressEntry> *entry,QComboBox *combobox)
{
    QHostAddress ip;
    combobox->setEnabled(false);
    for(int i = 0;i < entry->count();i++)
    {
        bool boola = false;
        ip = entry->at(i).ip();
        ip.toIPv4Address(&boola);
        if(boola == true)
        {
            combobox->addItem(ip.toString());
        }
    }
    if(combobox->count() > 0)
    {
        combobox->setEnabled(true);
    }
}

/*  Get network interface ipaddress ,enable combobox or not;*/

void SuperNetwork::Getlocalnetmask(QList<QNetworkAddressEntry> *entry,QComboBox *combobox)
{
    QHostAddress netmask;
    combobox->setEnabled(false);
    for(int i = 0;i < entry->count();i++)
    {
        bool boola = false;
        netmask = entry->at(i).netmask();
        netmask.toIPv4Address(&boola);
        if(boola == true)
        {
            combobox->addItem(netmask.toString());
        }
    }
    if(combobox->count() > 0)
    {
        combobox->setEnabled(true);
    }
}

/*  Get network interface netmask ,enable combobox or not;*/

bool SuperNetwork::Connecttcpserver(QTcpSocket* tcpsocket,QString ipaddress,int portnumber,int timeout)
{
    tcpsocket->connectToHost(ipaddress,portnumber);
    if(tcpsocket->waitForConnected(timeout))
    {
        return true;
    }
    return false;
}

bool SuperNetwork::Disconnecttcpserver(QTcpSocket* tcpsocket,int timeout)
{
    tcpsocket->disconnectFromHost();
    if(tcpsocket->state() == QTcpSocket::UnconnectedState || tcpsocket->waitForDisconnected(timeout))
    {
        return true;
    }
    return false;
}

/*  disconnect from tcp server;*/

void SuperNetwork::Writesocket(QCheckBox* checkboxstring,QCheckBox* checkboxaddr,QCheckBox* checkboxaddn,QTcpSocket* tcpsocket,QLineEdit* lineeditdata)
{
    QByteArray data = "";
    if(checkboxstring->isChecked())
    {
        data = lineeditdata->text().toUtf8();
        if(checkboxaddr->isChecked() && checkboxaddn->isChecked())
        {
            tcpsocket->write(data + "\r" + "\n");
        }
        else if(!checkboxaddr->isChecked() && checkboxaddn->isChecked())
        {
            tcpsocket->write(data + "\n");
        }
        else if(checkboxaddr->isChecked() && !checkboxaddn->isChecked())
        {
            tcpsocket->write(data + "\r");
        }
        else
        {
            tcpsocket->write(data);
        }
    }
    else if(!checkboxstring->isChecked())
    {
        tcpsocket->write(data.fromHex(lineeditdata->text().toUtf8()));
    }
    tcpsocket->waitForBytesWritten(1000);
}

/*  tcpsocket write data api,adapted to supertools rules;*/

QByteArray SuperNetwork::Readdatastream(QTcpSocket* tcpsocket,QCheckBox* checkboxstring)
{
    if(tcpsocket->state() == QTcpSocket::ConnectedState && checkboxstring->isChecked())
    {
        return tcpsocket->readAll();
    }
    else
    {
        return tcpsocket->readAll().toHex();
    }
}

/*  receive tcpsocket stream data api;*/

void SuperNetwork::Closetcpclient(QTcpSocket* tcpsocket)
{
    if(tcpsocket->state() == QTcpSocket::ConnectedState)
    {
        tcpsocket->disconnectFromHost();
        if(tcpsocket->state() != QTcpSocket::UnconnectedState)
        {
            tcpsocket->waitForDisconnected(1000);
        }
    }
}

/*  close tcp socket port;*/

Tcpsocketthread::Tcpsocketthread(QTcpSocket *tcpsocket,double timeout)
{
    Tcpsocket = tcpsocket;
    Timeout = timeout;
}

void Tcpsocketthread::run()
{
    while(Inittime < Timeout)
    {
        QThread::msleep(50);
        Tcpsocket->waitForReadyRead(1);
        Inittime = Inittime + 50;
        int bytesAvailable = Tcpsocket->bytesAvailable();
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

/*  run loog time tcpsocket command;*/

