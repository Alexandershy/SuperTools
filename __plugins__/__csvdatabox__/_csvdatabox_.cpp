#include "_csvdatabox_.h"

SuperTab* Interface::Loadplugin()
{
    return new CsvDataBox();
}

/*  return class csvdatabox new instance pointer;*/

CsvDataBox::CsvDataBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("CsvDataBox");
    Setgroupbox(2,1);
    Setstretch({99,1},{100});
    Init();
}

CsvDataBox::~CsvDataBox()
{
    SuperC->Closethread(Threadpa);
}

void CsvDataBox::Init()
{
    Objectinit();
    Parameterinit();
    Threadinit();
}

/*  set dll file*/

void CsvDataBox::Objectinit()
{
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.csv"});
    Modulea = new ModuleA(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Progressbardialog = new SuperProgressBarDialog();
    connect(Filemanager,                &SuperFileManager::Signalfa,Logger, &SuperLogger::Displaylog);
    connect(Filemanager,                &SuperFileManager::Signalfc,this,   &CsvDataBox::Open);
    connect(Filemanager,                &SuperFileManager::Signalfd,this,   &CsvDataBox::Open);
    connect(Modulea->ui->pushButton_7,  &QPushButton::clicked,      this,   &CsvDataBox::Process);
    connect(Modulea->ui->checkBox,      &QCheckBox::stateChanged,   this,   &CsvDataBox::Enableprocessbutton);
    connect(Modulea->ui->checkBox_2,    &QCheckBox::stateChanged,   this,   &CsvDataBox::Enableprocessbutton);
    connect(Modulea->ui->checkBox_3,    &QCheckBox::stateChanged,   this,   &CsvDataBox::Enableprocessbutton);
}

/*  object init;*/

void CsvDataBox::Parameterinit()
{
    Csvfilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Modulea->ui->checkBox);
    Filemanager->Widgetlist.append(Modulea->ui->checkBox_2);
    Filemanager->Widgetlist.append(Modulea->ui->checkBox_3);
    Filemanager->Checkboxlist.append(Modulea->ui->checkBox);
    Filemanager->Checkboxlist.append(Modulea->ui->checkBox_2);
    Filemanager->Checkboxlist.append(Modulea->ui->checkBox_3);
    Filemanager->Enablewidgetlist();
    Filemanager->Personalization(Sourcepath,"Csv");
    Filemanager->Checkfilevaildinit();
}

/*  parameter init;*/

void CsvDataBox::Threadinit()
{
    Threadpa = new ProcessData(Modulea->ui->checkBox,Modulea->ui->checkBox_2,Modulea->ui->checkBox_3,Csvfilelist,&Waitforremoved,&Processtime);
    connect(Threadpa,   &ProcessData::Signalpa, Logger, &SuperLogger::Displaylog);
    connect(Threadpa,   &ProcessData::Signalpb, this,   &CsvDataBox::Signalpbslot);
    connect(Threadpa,   &ProcessData::Signalpc, this,   &CsvDataBox::Setprogressbar);
}

/*  thread init;*/

void CsvDataBox::Enableprocessbutton()
{
    Checkcurrentfunction();
    if(Modulea->ui->checkBox->isChecked() || Modulea->ui->checkBox_2->isChecked() || Modulea->ui->checkBox_3->isChecked())
    {
        Modulea->ui->pushButton_7->setEnabled(true);
        Logger->Displaylog("N","process button enable completed","Enableprocessbutton function run completed");
    }
    else
    {
        Modulea->ui->pushButton_7->setEnabled(false);
        Logger->Displaylog("N","process button disable completed","Enableprocessbutton function run completed");
    }
}

/*  is enable widget button or not;*/

void CsvDataBox::Open()
{
    QString csvfile = Filemanager->Getcurrentitemtext();
    Filemanager->Setcurrentfile(csvfile);
    DataDialog *dialog = new DataDialog(nullptr,csvfile);
    Logger->Displaylog("N",csvfile + " opened","Open function run completed");
    dialog->Show();
}

/*  open csvdata table;*/

void CsvDataBox::Checkcurrentfunction()
{
    Logger->Displaylog("N","current function: ","Checkcurrentfunction function run completed");
    for(int i = 0;i < Filemanager->Checkboxlist.count();i++)
    {
        if(Filemanager->Checkboxlist.at(i)->isChecked())
        {
            Logger->Displaylog("N",Filemanager->Checkboxlist.at(i)->text(),"Checkcurrentfunction function run completed");
        }
    }
}

/*  check current function;*/

void CsvDataBox::Process()
{
    Modulea->ui->pushButton_7->setEnabled(false);
    Processtime = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    Waitforremoved = *Csvfilelist;
    Threadpa->start();
    Progressbardialog->Show();
}

/*  start a new thread to process select files;*/

void CsvDataBox::Signalpbslot()
{
    Waitforremoved.clear();
    Modulea->ui->pushButton_7->setEnabled(true);
    Logger->Displaylog("N","files has been process completed","Signalpbslot function run completed");
}

/*  receive signal and enable process button;*/

void CsvDataBox::Setprogressbar(int progressbarvalue,QString message)
{
    Progressbardialog->Setvaluemessage(progressbarvalue,message);
    Logger->Displaylog("N",message,"Signalpcslot function running...");
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
    Init();
}

void ProcessData::run()
{
    Mergecsvfiledata();
    Removeduplicateitem(Waitforremoved);
    Openpath();
    emit Signalpb();
}

void ProcessData::Init()
{
    Objectinit();
}

void ProcessData::Objectinit()
{
    SuperC = new SuperCore(this);
}

void ProcessData::Mergecsvfiledata()
{
    QString temp;
    if(Checkboxa->isChecked())
    {
        int filecount = Csvfilelist->count();
        for(int i = 0;i < filecount;i++)
        {
            emit Signalpc(double(i + 1) / double(filecount) * 99,"(1/3)mergecsvfiledata function running...");
            temp = temp + SuperC->Readonlyfile(Csvfilelist->at(i));
            emit Signalpa("N","merge " + Csvfilelist->at(i) + " completed","mergecsvfiledata function run completed");
        }
        Waitforremoved->clear();
        Waitforremoved->append("./__depycache__/__csvdata__/" + *Processtime + ".csv");
        SuperC->Writeonlyfile("./__depycache__/__csvdata__/" + *Processtime + ".csv",temp);
    }
    else
    {
        emit Signalpc(99,"(1/3)mergecsvfiledata function skiped;");
    }
}

/*  merge csv file data at treewidget;*/

void ProcessData::Removeduplicateitem(QStringList *csvfilelist)
{
    if(Checkboxb->isChecked())
    {
        for(int i = 0;i < csvfilelist->count();i++)
        {
            emit Signalpc(double(i + 1) / double(csvfilelist->count()) * 99,"(2/3)removeduplicateitem function running...");
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
            emit Signalpa("N",csvfile + "remove duplicate item completed","Removeduplicateitem function run completed");
            QStringList filepathlist = csvfile.split(".csv").at(0).split("/");
            QString csvfilename = SuperC->Getlistlastmember(&filepathlist);
            QString newcsvfile = "__depycache__/__csvdata__/" + csvfilename + *Processtime + "-removeduplicateitem.csv";
            SuperC->Writeonlyfile(newcsvfile,data);
        }
    }
    else
    {
        emit Signalpc(99,"(2/3)removeduplicateitem function skiped;");
    }
}

/*  remove duplicate item by string path list;*/

void ProcessData::Openpath()
{
    if(Checkboxc->isChecked())
    {
        SuperC->Openpath("./__depycache__/__csvdata__");
    }
    emit Signalpc(100,"(3/3)openpath function run completed;");
}

/*  open folder;*/

