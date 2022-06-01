#include "_csvdatabox_.h"
#include "ui__csvdatamodulea_.h"

SuperTab* Interface::Loadplugin()
{
    return new CsvDataBox();
}

/*  return class csvdatabox new instance pointer;*/

CsvDataBox::CsvDataBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("CsvDataBox");
    setGroupBox(2,1);
    setStretch({99,1},{100});
    init();
}

CsvDataBox::~CsvDataBox()
{
    Core->closeThread(Threadpa);
}

void CsvDataBox::init()
{
    objectInit();
    parameterInit();
    threadInit();
}

/*  set dll file*/

void CsvDataBox::objectInit()
{
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.csv"});
    Modulea = new CsvDataModuleA(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Progressbardialog = new SuperProgressBarDialog();
    connect(Filemanager,                &SuperFileManager::signalFa,Logger, &SuperLogger::displayLog);
    connect(Filemanager,                &SuperFileManager::signalFc,this,   &CsvDataBox::open);
    connect(Filemanager,                &SuperFileManager::signalFd,this,   &CsvDataBox::open);
    connect(Modulea->ui->pushButton_7,  &QPushButton::clicked,      this,   &CsvDataBox::process);
    connect(Modulea->ui->checkBox,      &QCheckBox::stateChanged,   this,   &CsvDataBox::enableProcessButton);
    connect(Modulea->ui->checkBox_2,    &QCheckBox::stateChanged,   this,   &CsvDataBox::enableProcessButton);
    connect(Modulea->ui->checkBox_3,    &QCheckBox::stateChanged,   this,   &CsvDataBox::enableProcessButton);
}

/*  object init;*/

void CsvDataBox::parameterInit()
{
    Csvfilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Modulea->ui->checkBox);
    Filemanager->Widgetlist.append(Modulea->ui->checkBox_2);
    Filemanager->Widgetlist.append(Modulea->ui->checkBox_3);
    Filemanager->Checkboxlist.append(Modulea->ui->checkBox);
    Filemanager->Checkboxlist.append(Modulea->ui->checkBox_2);
    Filemanager->Checkboxlist.append(Modulea->ui->checkBox_3);
    Filemanager->enableWidgetList();
    Filemanager->personalization(Sourcepath,"Csv");
    Filemanager->checkFileVaildInit();
}

/*  parameter init;*/

void CsvDataBox::threadInit()
{
    Threadpa = new ProcessData(Modulea->ui->checkBox,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Csvfilelist,&Waitforremoved,&Processtime);
    connect(Threadpa,   &ProcessData::signalPa, Logger, &SuperLogger::displayLog);
    connect(Threadpa,   &ProcessData::signalPb, this,   &CsvDataBox::signalpbSlot);
    connect(Threadpa,   &ProcessData::signalPc, this,   &CsvDataBox::setProgressBar);
}

/*  thread init;*/

void CsvDataBox::enableProcessButton()
{
    checkCurrentFunction();
    if(Modulea->ui->checkBox->isChecked() || Modulea->ui->checkBox_2->isChecked() || Modulea->ui->checkBox_3->isChecked())
    {
        Modulea->ui->pushButton_7->setEnabled(true);
        Logger->displayLog("N","process button enable completed","Enableprocessbutton function run completed");
    }
    else
    {
        Modulea->ui->pushButton_7->setEnabled(false);
        Logger->displayLog("N","process button disable completed","Enableprocessbutton function run completed");
    }
}

/*  is enable widget button or not;*/

void CsvDataBox::open()
{
    QString csvfile = Filemanager->getCurrentItemText();
    Filemanager->setCurrentFile(csvfile);
    CsvDataDialog *dialog = new CsvDataDialog(nullptr,csvfile);
    Logger->displayLog("N",csvfile + " opened","Open function run completed");
    dialog->show();
}

/*  open csvdata table;*/

void CsvDataBox::checkCurrentFunction()
{
    Logger->displayLog("N","current function: ","Checkcurrentfunction function run completed");
    for(int i = 0;i < Filemanager->Checkboxlist.count();i++)
    {
        if(Filemanager->Checkboxlist.at(i)->isChecked())
        {
            Logger->displayLog("N",Filemanager->Checkboxlist.at(i)->text(),"Checkcurrentfunction function run completed");
        }
    }
}

/*  check current function;*/

void CsvDataBox::process()
{
    Modulea->ui->pushButton_7->setEnabled(false);
    Processtime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    Waitforremoved = *Csvfilelist;
    Threadpa->start();
    Progressbardialog->show();
}

/*  start a new thread to process select files;*/

void CsvDataBox::signalpbSlot()
{
    Waitforremoved.clear();
    Modulea->ui->pushButton_7->setEnabled(true);
    Logger->displayLog("N","files has been process completed","signalPbslot function run completed");
}

/*  receive signal and enable process button;*/

void CsvDataBox::setProgressBar(int progressbarvalue,QString message)
{
    Progressbardialog->setValueMessage(progressbarvalue,message);
    Logger->displayLog("N",message,"signalPcslot function running...");
}

/*  set progress bar value and message;*/

ProcessData::ProcessData(QCheckBox* checkboxa,QCheckBox* checkboxb,QCheckBox* checkboxc,QStringList *csvfilelist,QStringList* waitforremoved,QString* processtime)
{
    Checkboxa = checkboxa;
    Checkboxb = checkboxb;
    Checkboxc = checkboxc;
    Csvfilelist = csvfilelist;
    Waitforremoved = waitforremoved;
    Processtime = processtime;
    init();
}

void ProcessData::run()
{
    mergeCsvFileData();
    removeDuplicateItem(Waitforremoved);
    openPath();
    emit signalPb();
}

void ProcessData::init()
{
    objectInit();
}

void ProcessData::objectInit()
{
    Core = new SuperCore(this);
}

void ProcessData::mergeCsvFileData()
{
    QString temp;
    if(Checkboxa->isChecked())
    {
        int filecount = Csvfilelist->count();
        for(int i = 0;i < filecount;i++)
        {
            emit signalPc(double(i + 1) / double(filecount) * 99,"(1/3)mergecsvfiledata function running...");
            temp = temp + Core->readOnlyFile(Csvfilelist->at(i));
            emit signalPa("N","merge " + Csvfilelist->at(i) + " completed","mergecsvfiledata function run completed");
        }
        Waitforremoved->clear();
        Waitforremoved->append("./__depycache__/__csvdata__/" + *Processtime + ".csv");
        Core->writeOnlyFile("./__depycache__/__csvdata__/" + *Processtime + ".csv",temp);
    }
    else
    {
        emit signalPc(99,"(1/3)mergecsvfiledata function skiped;");
    }
}

/*  merge csv file data at treewidget;*/

void ProcessData::removeDuplicateItem(QStringList *csvfilelist)
{
    if(Checkboxb->isChecked())
    {
        for(int i = 0;i < csvfilelist->count();i++)
        {
            emit signalPc(double(i + 1) / double(csvfilelist->count()) * 99,"(2/3)removeduplicateitem function running...");
            QString data;
            QStringList datalist;
            QString csvfile = csvfilelist->at(i);
            QFile file(csvfile);
            file.open(QIODevice::ReadOnly);
            QString datatemp = file.readLine();
            while(!datatemp.isEmpty())
            {
                if(!datalist.contains(datatemp))
                {
                    datalist.append(datatemp);
                    data = data + datatemp.split("\r\n").at(0) + "\n";
                }
                datatemp = file.readLine();
            }
            file.close();
            emit signalPa("N",csvfile + "remove duplicate item completed","Removeduplicateitem function run completed");
            QStringList filepathlist = csvfile.split(".csv").at(0).split("/");
            QString csvfilename = Core->getListLastMember(&filepathlist);
            QString newcsvfile = "__depycache__/__csvdata__/" + csvfilename + *Processtime + "-removeduplicateitem.csv";
            Core->writeOnlyFile(newcsvfile,data);
        }
    }
    else
    {
        emit signalPc(99,"(2/3)removeduplicateitem function skiped;");
    }
}

/*  remove duplicate item by string path list;*/

void ProcessData::openPath()
{
    if(Checkboxc->isChecked())
    {
        Core->openPath("./__depycache__/__csvdata__");
    }
    emit signalPc(100,"(3/3)openpath function run completed;");
}

/*  open folder;*/

