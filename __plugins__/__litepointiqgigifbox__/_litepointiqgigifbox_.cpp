#include "_litepointiqgigifbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new LitePointIQGigIfBox();
}

/*  return class litepointiqgigifbox new instance pointer;*/

LitePointIQGigIfBox::LitePointIQGigIfBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("LitePointIQGigIfBox");
    Setgroupbox(2,2);
    Setstretch({1,99},{5,5});
    Init();
}

LitePointIQGigIfBox::~LitePointIQGigIfBox()
{
    delete Rout;
    delete Pathloss;
    delete Pldatamenu;
}

void LitePointIQGigIfBox::Init()
{
    Objectinit();
}

/*  init ui;*/

void LitePointIQGigIfBox::Objectinit()
{
    SuperN = new SuperNetwork(this);
    Tcpsocket = new QTcpSocket(this);
    Technologymenu = new Technology(this);
    Rout = new RoutDialog(nullptr);
    Pathloss = new PathLossDialog(nullptr);
    Pldatamenu = new PathLossDataMenu(nullptr);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(1)->Insidelayout);
    connect(Modulea->ui->lineEdit,              &QLineEdit::textChanged,    this,   &LitePointIQGigIfBox::Enableconnectlitepoint);
    connect(Modulea->ui->pushButton_2,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Connecttcpserver);
    connect(Modulea->ui->pushButton_8,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Disconnecttcpserver);
    connect(Modulea->ui->pushButton_3,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Opentechnologymenu);
    connect(Modulea->ui->pushButton_5,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Openroutconfig);
    connect(Modulea->ui->pushButton,            &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Openpathlosseditor);
    connect(Modulea->ui->pushButton_6,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Displayvsasetting);
    connect(Modulea->ui->pushButton_7,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Displaytrigglesetting);
    connect(Moduleb->ui->pushButton_10,         &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Displayimpairmentssetting);
    connect(Tcpsocket,                          &QTcpSocket::disconnected,  this,   &LitePointIQGigIfBox::Operatordisconnectui);
    connect(Technologymenu->Gprf,               &QAction::triggered,        this,   &LitePointIQGigIfBox::Settechnology);
    connect(Technologymenu->Fivegaction,        &QAction::triggered,        this,   &LitePointIQGigIfBox::Settechnology);
    connect(Technologymenu->Fivegsmallcell,     &QAction::triggered,        this,   &LitePointIQGigIfBox::Settechnology);
    connect(Technologymenu->Wifigig,            &QAction::triggered,        this,   &LitePointIQGigIfBox::Settechnology);
    connect(Pathloss->Plugin->ui->pushButton_7, &QPushButton::clicked,      this,   &LitePointIQGigIfBox::Refreshpathloss);
    connect(Pathloss->Plugin->ui->treeWidget,   &QTreeWidget::itemClicked,  this,   &LitePointIQGigIfBox::Refreshpathlossdata);
    connect(Pathloss->Configmenu->Newconfig,    &QAction::triggered,        this,   &LitePointIQGigIfBox::Newpathlossconfig);
    connect(Pathloss->Datamenu->Newrow,         &QAction::triggered,        this,   &LitePointIQGigIfBox::Newpathlossdatarow);
    connect(Pathloss->Datamenu->Save,           &QAction::triggered,        this,   &LitePointIQGigIfBox::Savepathlossdata);
    connect(Pathloss->Datamenu->Deleterow,      &QAction::triggered,        this,   &LitePointIQGigIfBox::Deletepathlossdatarow);
}

/*  object init;*/

void LitePointIQGigIfBox::Enableconnectlitepoint()
{
    bool boola;
    boola = SuperC->Checkiprules(Modulea->ui->lineEdit->text());
    if(boola == true)
    {
        Modulea->ui->pushButton_2->setEnabled(true);
        Logger->Displaylog("N","ipaddress check rules passed","Enableconnectlitepoint function run completed;");
    }
    else
    {
        Modulea->ui->pushButton_2->setEnabled(false);
        Logger->Displaylog("N","ipaddress check rules failed,local ip is: " + Modulea->ui->lineEdit->text(),"Enableconnectlitepoint function run completed;");
    }
}

/*  enable connect litepoint button or not;*/

void LitePointIQGigIfBox::Connecttcpserver()
{
    bool boola = SuperN->Connecttcpserver(Tcpsocket,Modulea->ui->lineEdit->text(),24000,1000);
    if(boola)
    {
        Operatorconnectui();
    }
}

/*  connect to litepoint;*/

void LitePointIQGigIfBox::Operatorconnectui()
{
    Modulea->ui->pushButton_2->setEnabled(false);
    Modulea->ui->lineEdit->setEnabled(false);
    Modulea->ui->pushButton_8->setEnabled(true);
    Modulea->ui->pushButton_3->setEnabled(true);
    Modulea->ui->pushButton->setEnabled(true);
    Modulea->ui->pushButton_4->setEnabled(true);
    Modulea->ui->pushButton_5->setEnabled(true);
//    Modulea->ui->progressBar->setValue(99);
    Logger->Displaylog("N","Connect litepoint success","Connecttcpserver function run completed;");
}

/*  enable widget after connect litepoint;*/

void LitePointIQGigIfBox::Disconnecttcpserver()
{
    SuperN->Disconnecttcpserver(Tcpsocket,1000);
}

/*  disconnect from litepoint;*/

void LitePointIQGigIfBox::Operatordisconnectui()
{
    Modulea->ui->pushButton_2->setEnabled(true);
    Modulea->ui->lineEdit->setEnabled(true);
    Modulea->ui->pushButton_8->setEnabled(false);
    Modulea->ui->pushButton_3->setEnabled(false);
    Modulea->ui->pushButton->setEnabled(false);
    Modulea->ui->pushButton_4->setEnabled(false);
    Modulea->ui->pushButton_5->setEnabled(false);
    Logger->Displaylog("N","Disconnect litepoint success","Disconnecttcpserver function run completed;");
}

/*  disable widget after disconnect litepoint;*/

void LitePointIQGigIfBox::Litepointwriteapi(QString command)
{
    Modulea->ui->lineEdit_3->setText(command);
    SuperN->Writesocket(Modulea->ui->checkBox_29,Modulea->ui->checkBox_27,Modulea->ui->checkBox_29,Tcpsocket,Modulea->ui->lineEdit_3);
    Logger->Displaylog("W",command,"Litepointwriteapi function run completed;");
}

/*  write to litepoint api;*/

void LitePointIQGigIfBox::Litepointwaitapi(double timeout)
{
    Threadta = new Tcpsocketthread(Tcpsocket,timeout);
    connect(Threadta,&Tcpsocketthread::Signaltf,this,      &LitePointIQGigIfBox::Litepointreadtimeoutslot);
    connect(Threadta,&Tcpsocketthread::finished,Threadta,  &QObject::deleteLater);
}

/*  wait data from litepoint api;*/

QByteArray LitePointIQGigIfBox::Litepointreadapi()
{
    QByteArray result = SuperN->Readdatastream(Tcpsocket,Modulea->ui->checkBox_29);
    Logger->Displaylog("R",result,"Litepointreadapi function run completed;");
    return result;
}

/*  read data from litepoint api;*/

void LitePointIQGigIfBox::Opentechnologymenu()
{
    Technologymenu->exec(QCursor::pos());
}

/*  open technology menu;*/

void LitePointIQGigIfBox::Settechnology()
{
    QString command = Modulea->ui->comboBox->currentText() + ";" + sender()->objectName();
    Litepointwriteapi(command);
    Litepointwriteapi("MOD?");
    Litepointwaitapi(1000);
    connect(Threadta,&Tcpsocketthread::Signaltt,this,&LitePointIQGigIfBox::Getactivemodulesolt);
    Threadta->start();
}

/*  set technology and read sucessfully;*/

void LitePointIQGigIfBox::Openpathlosseditor()
{
    Refreshpathloss();
    Pathloss->Show();
}

/*  refresh pathloss info and exec pathloss editor;*/

void LitePointIQGigIfBox::Refreshpathloss()
{
    Refreshpathlossconfig();
}

/*  refresh pathloss info;*/

void LitePointIQGigIfBox::Refreshpathlossconfig()
{
    Pathloss->Plugin->ui->treeWidget->clear();
    Litepointwriteapi("TABL:LOSS:CAT?");
    Litepointwaitapi(1000);
    connect(Threadta,&Tcpsocketthread::Signaltt,this,&LitePointIQGigIfBox::Refreshconfigslot);
    Threadta->start();
}

/*  refresh pathloss config;*/

void LitePointIQGigIfBox::Newpathlossconfig()
{
    QString configtime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    QString command = "MEM:TABLE '" + configtime + "';MEM:TABLE:DEFINE 'FREQ,LOSS'";
    Litepointwriteapi(command);
    Refreshpathlossconfig();
}

/*  new pathloss config;*/

void LitePointIQGigIfBox::Newpathlossdatarow()
{
    int rowpos = Pathloss->Plugin->ui->tableWidget->rowCount();
    Pathloss->Plugin->ui->tableWidget->setRowCount(rowpos + 1);
    for(int i = 0;i < Pathloss->Plugin->ui->tableWidget->columnCount();i++)
    {
        Pathloss->Plugin->ui->tableWidget->setItem(rowpos,i,new QTableWidgetItem());
        Pathloss->Plugin->ui->tableWidget->item(rowpos,i)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        Pathloss->Plugin->ui->tableWidget->item(rowpos,i)->setText("0");
    }
}

/*  new pathloss data row;*/

void LitePointIQGigIfBox::Savepathlossdata()
{
    QString configname = Pathloss->Plugin->ui->treeWidget->currentItem()->text(0);
    QString waitforwritedata = Getlocalpathlossdataapi();
    Litepointwriteapi("MEM:TABLE '" + configname + "';MEMory:TABLe:CLEar;MEM:TABLE:INSert:POINt " + waitforwritedata);
    Refreshpathlossdata();
}

/*  save pathloss data;*/

void LitePointIQGigIfBox::Deletepathlossdatarow()
{
    int rowpos = Pathloss->Plugin->ui->tableWidget->currentRow();
    if(rowpos < 0)
    {
        rowpos = 0;
    }
    QString currentconfig = Pathloss->Plugin->ui->treeWidget->currentItem()->text(0);
    QString command = "MEM:TABLE '" + currentconfig + "';MEM:TABLE:DELete:POINt " + Pathloss->Plugin->ui->tableWidget->item(rowpos,0)->text() + "MHz";
    Litepointwriteapi(command);
    Refreshpathlossdata();
}

/*  delete pathloss data;*/

void LitePointIQGigIfBox::Refreshpathlossdata()
{
    QString configname = Pathloss->Plugin->ui->treeWidget->currentItem()->text(0);
    QString command = "MEM:TABLE '" + configname + "';TABL:FREQ:POIN?;TABL:LOSS:POIN?;TABL:FREQ?;TABL:LOSS?";
    Litepointwriteapi(command);
    Litepointwaitapi(1000);
    connect(Threadta,&Tcpsocketthread::Signaltt,this,&LitePointIQGigIfBox::Refreshpathlossdataslot);
    Threadta->start();
}

/*  refresh pathloss data depend config;*/

void LitePointIQGigIfBox::Openpathlossdatamenu()
{
    Pldatamenu->exec(QCursor::pos());
}

/*  exec pathloss data menu;*/

void LitePointIQGigIfBox::Sethiddenapi(QGroupBox* groupbox)
{
    if(groupbox->isHidden())
    {
        groupbox->setHidden(false);
    }
    else
    {
        groupbox->setHidden(true);
    }
}

/*  click for display or hide groupbox api;*/

void LitePointIQGigIfBox::Displayvsasetting()
{
    Sethiddenapi(Moduleb->ui->groupBox_5);
}

/*  display or hide vsa setting;*/

void LitePointIQGigIfBox::Displaytrigglesetting()
{
    Sethiddenapi(Moduleb->ui->groupBox_6);
}

/*  display or hide triggle setting;*/

void LitePointIQGigIfBox::Displayimpairmentssetting()
{
    Sethiddenapi(Moduleb->ui->groupBox_8);
}

/*  display or hide impairments setting;*/

QString LitePointIQGigIfBox::Litepointreadslotapi()
{
    Threadta = nullptr;
    return Litepointreadapi();
}

/*  thread set as nullptr and return result;*/

void LitePointIQGigIfBox::Litepointreadtimeoutslot()
{
    Threadta = nullptr;
    Logger->Displaylog("R","tcpsocket receive data timeout;","Refreshpathlossdataslot function run completed;");
}

/*  thread set as nullptr and return timeout;*/

void LitePointIQGigIfBox::Getactivemodulesolt()
{
    Modulea->ui->pushButton_3->setText(Litepointreadslotapi());
}

/*  set activate module name;*/

void LitePointIQGigIfBox::Refreshconfigslot()
{
    QStringList resultlist = Litepointreadslotapi().split("\"");
    int resultlistcount = resultlist.count();
    for(int i = 0;i < resultlistcount;i++)
    {
        QString config = resultlist.at(i);
        if(config.contains("TABLE"))
        {
            QTreeWidgetItem *newwidgetitem = new QTreeWidgetItem(Pathloss->Plugin->ui->treeWidget);
            newwidgetitem->setText(0,config.split(",TABLE,").at(0));
            newwidgetitem->setText(1,config.split(",TABLE,").at(1));
            Pathloss->Plugin->ui->treeWidget->addTopLevelItem(newwidgetitem);
        }
    }
    if(Pathloss->Plugin->ui->treeWidget->topLevelItemCount() > 0)
    {
        Pathloss->Plugin->ui->treeWidget->header()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
        Pathloss->Plugin->ui->treeWidget->header()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
        Pathloss->Plugin->ui->treeWidget->header()->setStretchLastSection(false);
        Pathloss->Plugin->ui->treeWidget->setCurrentItem(Pathloss->Plugin->ui->treeWidget->topLevelItem(0));
        Refreshpathlossdata();
    }
}

/*  refresh pathloss config slot;*/

void LitePointIQGigIfBox::Refreshpathlossdataslot()
{
    Pathloss->Plugin->ui->tableWidget->clear();
    Setlocalpathlossdataapi();
}

/*  refresh pathloss data slot;*/

void LitePointIQGigIfBox::Setlocalpathlossdataapi()
{
    QStringList resultlist = Litepointreadslotapi().split(";");
    double countsarray[2] = {resultlist.at(0).toDouble(),resultlist.at(1).toDouble()};
    int rowcounts = SuperC->Getdoublearraymaxvalue(countsarray,2);
    QStringList freqlist = resultlist.at(2).split(",");
    QStringList losslist = resultlist.at(3).split(",");
    Pathloss->Plugin->ui->tableWidget->setRowCount(rowcounts);
    for(int i = 0;i<rowcounts;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            QString temp;
            Pathloss->Plugin->ui->tableWidget->setItem(i,j,new QTableWidgetItem());
            Pathloss->Plugin->ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            if(j == 0)
            {
                temp = QString::number(freqlist.at(i).toDouble() / 1000000);
            }
            else if(j == 1)
            {
                temp = QString::number(losslist.at(i).toDouble());
            }
            Pathloss->Plugin->ui->tableWidget->item(i,j)->setText(temp);
        }
    }
    Pathloss->Plugin->ui->tableWidget->setHorizontalHeaderLabels({"Frequency(mhz)","Correction(db)"});
}

/*  refresh pathloss data slot;*/

QString LitePointIQGigIfBox::Getlocalpathlossdataapi()
{
    int row = Pathloss->Plugin->ui->tableWidget->rowCount();
    int column = Pathloss->Plugin->ui->tableWidget->columnCount();
    QString data = "";
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < column;j++)
        {
            if(j == 0)
            {
                data = data + Pathloss->Plugin->ui->tableWidget->item(i,j)->text() + "Mhz,";
            }
            else if(j == 1)
            {
                data = data + Pathloss->Plugin->ui->tableWidget->item(i,j)->text() + ",";
            }
        }
    }
    return data.mid(0,data.size() - 1);
}

/*  refresh local pathloss data as command;*/

QString LitePointIQGigIfBox::Getlocalpathlossfreqapi()
{
    int row = Pathloss->Plugin->ui->tableWidget->rowCount();
    int column = Pathloss->Plugin->ui->tableWidget->columnCount();
    QString data = "";
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < column;j++)
        {
            if(j == 0)
            {
                data = data + Pathloss->Plugin->ui->tableWidget->item(i,j)->text() + "Mhz,";
            }
        }
    }
    return data.mid(0,data.size() - 1);
}

/*  refresh local pathloss freq as command;*/

void LitePointIQGigIfBox::Openroutconfig()
{
    Rout->show();
}

/*  exec rout dialog;*/

Technology::Technology(QWidget *parent)
    : QMenu(parent)
{
    Init();
}

void Technology::Init()
{
    Objectinit();
    Actioninit();
}

void Technology::Objectinit()
{
    SuperC = new SuperCore(this);
}

void Technology::Actioninit()
{
    SuperC->Addaction(this,Gprf,"GPRF","GPRF");
    SuperC->Addmenu(this,Fivegmenu,"5G");
    SuperC->Addaction(Fivegmenu,Fivegaction,"5G","5G");
    SuperC->Addaction(Fivegmenu,Fivegsmallcell,"5G Small Cell","5GBS");
    SuperC->Addaction(this,Wifigig,"WiGig","WIGIG");
}
