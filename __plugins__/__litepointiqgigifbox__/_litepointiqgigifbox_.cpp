#include "_litepointiqgigifbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new LitePointIQGigIfBox();
}

/*  return class litepointiqgigifbox new instance pointer;*/

LitePointIQGigIfBox::LitePointIQGigIfBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("LitePointIQGigIfBox");
    setGroupBox(2,2);
    setStretch({1,99},{5,5});
    init();
}

LitePointIQGigIfBox::~LitePointIQGigIfBox()
{
    delete Rout;
    delete Pathloss;
    delete Pldatamenu;
}

void LitePointIQGigIfBox::init()
{
    objectInit();
}

/*  init ui;*/

void LitePointIQGigIfBox::objectInit()
{
    Network = new SuperNetwork(this);
    Tcpsocket = new QTcpSocket(this);
    Technologymenu = new Technology(this);
    Rout = new RoutDialog(nullptr);
    Pathloss = new PathLossDialog(nullptr);
    Pldatamenu = new PathLossDataMenu(nullptr);
    Modulea = new LitePointIQGigIfModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new LitePointIQGigIfModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(1)->Insidelayout);
    connect(Modulea->ui->lineEdit,              &QLineEdit::textChanged,    this,   &LitePointIQGigIfBox::enableConnectLitePoint);
    connect(Modulea->ui->pushButton_2,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::connectTcpserver);
    connect(Modulea->ui->pushButton_8,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::disconnectTcpserver);
    connect(Modulea->ui->pushButton_3,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::openTechnologyMenu);
    connect(Modulea->ui->pushButton_5,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::openRoutConfig);
    connect(Modulea->ui->pushButton,            &QPushButton::clicked,      this,   &LitePointIQGigIfBox::openPathLossEditor);
    connect(Modulea->ui->pushButton_6,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::displayVSASetting);
    connect(Modulea->ui->pushButton_7,          &QPushButton::clicked,      this,   &LitePointIQGigIfBox::displayTriggleSetting);
    connect(Moduleb->ui->pushButton_10,         &QPushButton::clicked,      this,   &LitePointIQGigIfBox::displayImpairmentsSetting);
    connect(Tcpsocket,                          &QTcpSocket::disconnected,  this,   &LitePointIQGigIfBox::operatorDisconnectui);
    connect(Technologymenu->Gprf,               &QAction::triggered,        this,   &LitePointIQGigIfBox::setTechnology);
    connect(Technologymenu->Fivegaction,        &QAction::triggered,        this,   &LitePointIQGigIfBox::setTechnology);
    connect(Technologymenu->Fivegsmallcell,     &QAction::triggered,        this,   &LitePointIQGigIfBox::setTechnology);
    connect(Technologymenu->Wifigig,            &QAction::triggered,        this,   &LitePointIQGigIfBox::setTechnology);
    connect(Pathloss->Plugin->ui->pushButton_7, &QPushButton::clicked,      this,   &LitePointIQGigIfBox::refreshPathLoss);
    connect(Pathloss->Plugin->ui->treeWidget,   &QTreeWidget::itemClicked,  this,   &LitePointIQGigIfBox::refreshPathLossData);
    connect(Pathloss->Configmenu->Newconfig,    &QAction::triggered,        this,   &LitePointIQGigIfBox::newPathLossConfig);
    connect(Pathloss->Datamenu->Newrow,         &QAction::triggered,        this,   &LitePointIQGigIfBox::newPathLossDataRow);
    connect(Pathloss->Datamenu->Save,           &QAction::triggered,        this,   &LitePointIQGigIfBox::savePathLossData);
    connect(Pathloss->Datamenu->Deleterow,      &QAction::triggered,        this,   &LitePointIQGigIfBox::deletePathLossDataRow);
}

/*  object init;*/

void LitePointIQGigIfBox::enableConnectLitePoint()
{
    bool boola;
    boola = Core->checkIpRules(Modulea->ui->lineEdit->text());
    if(boola == true)
    {
        Modulea->ui->pushButton_2->setEnabled(true);
        Logger->displayLog("N","ipaddress check rules passed","Enableconnectlitepoint function run completed;");
    }
    else
    {
        Modulea->ui->pushButton_2->setEnabled(false);
        Logger->displayLog("N","ipaddress check rules failed,local ip is: " + Modulea->ui->lineEdit->text(),"Enableconnectlitepoint function run completed;");
    }
}

/*  enable connect litepoint button or not;*/

void LitePointIQGigIfBox::connectTcpserver()
{
    bool boola = Network->connectTcpServer(Tcpsocket,Modulea->ui->lineEdit->text(),24000,1000);
    if(boola)
    {
        operatorConnectui();
    }
}

/*  connect to litepoint;*/

void LitePointIQGigIfBox::operatorConnectui()
{
    Modulea->ui->pushButton_2->setEnabled(false);
    Modulea->ui->lineEdit->setEnabled(false);
    Modulea->ui->pushButton_8->setEnabled(true);
    Modulea->ui->pushButton_3->setEnabled(true);
    Modulea->ui->pushButton->setEnabled(true);
    Modulea->ui->pushButton_4->setEnabled(true);
    Modulea->ui->pushButton_5->setEnabled(true);
    Logger->displayLog("N","Connect litepoint success","Connecttcpserver function run completed;");
}

/*  enable widget after connect litepoint;*/

void LitePointIQGigIfBox::disconnectTcpserver()
{
    Network->disConnectTcpServer(Tcpsocket,1000);
}

/*  disconnect from litepoint;*/

void LitePointIQGigIfBox::operatorDisconnectui()
{
    Modulea->ui->pushButton_2->setEnabled(true);
    Modulea->ui->lineEdit->setEnabled(true);
    Modulea->ui->pushButton_8->setEnabled(false);
    Modulea->ui->pushButton_3->setEnabled(false);
    Modulea->ui->pushButton->setEnabled(false);
    Modulea->ui->pushButton_4->setEnabled(false);
    Modulea->ui->pushButton_5->setEnabled(false);
    Logger->displayLog("N","Disconnect litepoint success","Disconnecttcpserver function run completed;");
}

/*  disable widget after disconnect litepoint;*/

void LitePointIQGigIfBox::litepointWriteApi(QString command)
{
    Modulea->ui->lineEdit_3->setText(command);
    Network->writeSocket(Modulea->ui->checkBox_29,Modulea->ui->checkBox_27,Modulea->ui->checkBox_29,Tcpsocket,Modulea->ui->lineEdit_3);
    Logger->displayLog("W",command,"litepointWriteApi function run completed;");
}

/*  write to litepoint api;*/

void LitePointIQGigIfBox::litepointWaitApi(double timeout)
{
    Threadta = new SuperTcpSocketThread(Tcpsocket,timeout);
    connect(Threadta,&SuperTcpSocketThread::signalTf,this,      &LitePointIQGigIfBox::litepointReadTimeoutSlot);
    connect(Threadta,&SuperTcpSocketThread::finished,Threadta,  &QObject::deleteLater);
}

/*  wait data from litepoint api;*/

QByteArray LitePointIQGigIfBox::litepointReadApi()
{
    QByteArray result = Network->readDataStream(Tcpsocket,Modulea->ui->checkBox_29);
    Logger->displayLog("R",result,"Litepointreadapi function run completed;");
    return result;
}

/*  read data from litepoint api;*/

void LitePointIQGigIfBox::openTechnologyMenu()
{
    Technologymenu->exec(QCursor::pos());
}

/*  open technology menu;*/

void LitePointIQGigIfBox::setTechnology()
{
    QString command = Modulea->ui->comboBox->currentText() + ";" + sender()->objectName();
    litepointWriteApi(command);
    litepointWriteApi("MOD?");
    litepointWaitApi(1000);
    connect(Threadta,&SuperTcpSocketThread::signalTt,this,&::LitePointIQGigIfBox::getActiveModuleSlot);
    Threadta->start();
}

/*  set technology and read sucessfully;*/

void LitePointIQGigIfBox::openPathLossEditor()
{
    refreshPathLoss();
    Pathloss->show();
}

/*  refresh pathloss info and exec pathloss editor;*/

void LitePointIQGigIfBox::refreshPathLoss()
{
    refreshPathLossConfig();
}

/*  refresh pathloss info;*/

void LitePointIQGigIfBox::refreshPathLossConfig()
{
    Pathloss->Plugin->ui->treeWidget->clear();
    litepointWriteApi("TABL:LOSS:CAT?");
    litepointWaitApi(1000);
    connect(Threadta,&SuperTcpSocketThread::signalTt,this,&LitePointIQGigIfBox::refreshConfigSlot);
    Threadta->start();
}

/*  refresh pathloss config;*/

void LitePointIQGigIfBox::newPathLossConfig()
{
    QString configtime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    QString command = "MEM:TABLE '" + configtime + "';MEM:TABLE:DEFINE 'FREQ,LOSS'";
    litepointWriteApi(command);
    refreshPathLossConfig();
}

/*  new pathloss config;*/

void LitePointIQGigIfBox::newPathLossDataRow()
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

void LitePointIQGigIfBox::savePathLossData()
{
    QString configname = Pathloss->Plugin->ui->treeWidget->currentItem()->text(0);
    QString waitforwritedata = getLocalPathLossDataApi();
    litepointWriteApi("MEM:TABLE '" + configname + "';MEMory:TABLe:CLEar;MEM:TABLE:INSert:POINt " + waitforwritedata);
    refreshPathLossData();
}

/*  save pathloss data;*/

void LitePointIQGigIfBox::deletePathLossDataRow()
{
    int rowpos = Pathloss->Plugin->ui->tableWidget->currentRow();
    if(rowpos < 0)
    {
        rowpos = 0;
    }
    QString currentconfig = Pathloss->Plugin->ui->treeWidget->currentItem()->text(0);
    QString command = "MEM:TABLE '" + currentconfig + "';MEM:TABLE:DELete:POINt " + Pathloss->Plugin->ui->tableWidget->item(rowpos,0)->text() + "MHz";
    litepointWriteApi(command);
    refreshPathLossData();
}

/*  delete pathloss data;*/

void LitePointIQGigIfBox::refreshPathLossData()
{
    QString configname = Pathloss->Plugin->ui->treeWidget->currentItem()->text(0);
    QString command = "MEM:TABLE '" + configname + "';TABL:FREQ:POIN?;TABL:LOSS:POIN?;TABL:FREQ?;TABL:LOSS?";
    litepointWriteApi(command);
    litepointWaitApi(1000);
    connect(Threadta,&SuperTcpSocketThread::signalTt,this,&LitePointIQGigIfBox::refreshPathLossDataSlot);
    Threadta->start();
}

/*  refresh pathloss data depend config;*/

void LitePointIQGigIfBox::openPathLossDataMenu()
{
    Pldatamenu->exec(QCursor::pos());
}

/*  exec pathloss data menu;*/

void LitePointIQGigIfBox::setHiddenApi(QGroupBox* groupbox)
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

void LitePointIQGigIfBox::displayVSASetting()
{
    setHiddenApi(Moduleb->ui->groupBox_5);
}

/*  display or hide vsa setting;*/

void LitePointIQGigIfBox::displayTriggleSetting()
{
    setHiddenApi(Moduleb->ui->groupBox_6);
}

/*  display or hide triggle setting;*/

void LitePointIQGigIfBox::displayImpairmentsSetting()
{
    setHiddenApi(Moduleb->ui->groupBox_8);
}

/*  display or hide impairments setting;*/

QString LitePointIQGigIfBox::litepointReadSlotApi()
{
    Threadta = nullptr;
    return litepointReadApi();
}

/*  thread set as nullptr and return result;*/

void LitePointIQGigIfBox::litepointReadTimeoutSlot()
{
    Threadta = nullptr;
    Logger->displayLog("R","tcpsocket receive data timeout;","Refreshpathlossdataslot function run completed;");
}

/*  thread set as nullptr and return timeout;*/

void LitePointIQGigIfBox::getActiveModuleSlot()
{
    Modulea->ui->pushButton_3->setText(litepointReadSlotApi());
}

/*  set activate module name;*/

void LitePointIQGigIfBox::refreshConfigSlot()
{
    QStringList resultlist = litepointReadSlotApi().split("\"");
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
        refreshPathLossData();
    }
}

/*  refresh pathloss config slot;*/

void LitePointIQGigIfBox::refreshPathLossDataSlot()
{
    Pathloss->Plugin->ui->tableWidget->clear();
    setLocalPathLossDataApi();
}

/*  refresh pathloss data slot;*/

void LitePointIQGigIfBox::setLocalPathLossDataApi()
{
    QStringList resultlist = litepointReadSlotApi().split(";");
    double countsarray[2] = {resultlist.at(0).toDouble(),resultlist.at(1).toDouble()};
    int rowcounts = Core->getDoubleArrayMaxValue(countsarray,2);
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

QString LitePointIQGigIfBox::getLocalPathLossDataApi()
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

QString LitePointIQGigIfBox::getLocalPathLossFreqApi()
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

void LitePointIQGigIfBox::openRoutConfig()
{
    Rout->show();
}

/*  exec rout dialog;*/

Technology::Technology(QWidget *parent)
    : QMenu(parent)
{
    init();
}

void Technology::init()
{
    objectInit();
    actionInit();
}

void Technology::objectInit()
{
    Core = new SuperCore(this);
}

void Technology::actionInit()
{
    Core->addAction(this,Gprf,"GPRF","GPRF");
    Core->addMenu(this,Fivegmenu,"5G");
    Core->addAction(Fivegmenu,Fivegaction,"5G","5G");
    Core->addAction(Fivegmenu,Fivegsmallcell,"5G Small Cell","5GBS");
    Core->addAction(this,Wifigig,"WiGig","WIGIG");
}
