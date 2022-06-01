#include "_demobox_.h"
#include "ui__demomodulea_.h"
#include "ui__demomoduleb_.h"

SuperTab* Interface::Loadplugin()
{
    return new DemoBox();
}

/*  return class DemoBox new instance pointer;*/

DemoBox::DemoBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("DemoBox");
    setGroupBox(3,1);
    setStretch({1,1,99},{100});
    init();
}

DemoBox::~DemoBox()
{

}

void DemoBox::init()
{
    objectInit();
    parameterInit();
}

void DemoBox::objectInit()
{
    Modulea = new DemoModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new DemoModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(2)->Insidelayout,{"*.csv"});
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Moduleb->ui->pushButton,    &QPushButton::clicked,      this,   &DemoBox::selectSnFile);
    connect(Filemanager,                &SuperFileManager::signalFa,Logger, &SuperLogger::displayLog);
    connect(Moduleb->ui->pushButton_3,  &QPushButton::clicked,      this,   &DemoBox::process);
}

void DemoBox::parameterInit()
{
    Demofilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Moduleb->ui->pushButton_3);
    Filemanager->enableWidgetList();
    Filemanager->personalization("","Csv");
    Filemanager->checkFileVaildInit();
}

/*  parameter init;*/

void DemoBox::selectSnFile()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{"*.csv"});
    connect(filedialog,&SuperFileDialog::signalFb,this,         &DemoBox::displaySnFile);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
    filedialog->setSingleFile();
    filedialog->show();
}

void DemoBox::displaySnFile(QString text)
{
    Moduleb->ui->lineEdit->setText(text);
}

void DemoBox::process()
{
    Core->creatFile(Democachefile);
    QString text = Core->readOnlyFile(Moduleb->ui->lineEdit->text());
    QFile file(Moduleb->ui->lineEdit->text());
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        for(int i = 0;!file.atEnd();i++)
        {
            QString result = file.readLine();
            if(result.contains("AUP"))
            {
                QString sntemp = "AUP" + result.split('\r').at(0).split("AUP").at(1);
                Logger->displayLog("N",sntemp,"processing...");
                processCsvFile(sntemp);
            }
        }
        file.close();
    }
    else
    {
        SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,Moduleb->ui->lineEdit->text() + " is not exists;");
        messagebox->messageInit();
    }
}

void DemoBox::processCsvFile(QString serialnumber)
{
    int sncounttemp = 0;
    for(int i = 0;i < Demofilelist->count();i++)
    {
        QFile file(Demofilelist->at(i));
        file.open(QIODevice::ReadOnly);
        for(int j = 0;!file.atEnd();j++)
        {
            QString result = file.readLine();
            if(result.contains(serialnumber))
            {
                Core->appendFile(Democachefile,result);
                sncounttemp = sncounttemp + 1;
            }
        }
    }
    if(!sncounttemp)
    {
        Core->appendFile(Democachefile,serialnumber + " has not found\r\n");
        Logger->displayLog("N",serialnumber + " has not found;","processing...");
    }
}
