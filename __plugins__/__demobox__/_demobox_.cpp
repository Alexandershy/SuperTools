#include "_demobox_.h"

SuperTab* Interface::Loadplugin()
{
    return new DemoBox();
}

/*  return class DemoBox new instance pointer;*/

DemoBox::DemoBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("DemoBox");
    Setgroupbox(3,1);
    Setstretch({1,1,99},{100});
    Init();
}

DemoBox::~DemoBox()
{

}

void DemoBox::Init()
{
    Objectinit();
    Parameterinit();
}

void DemoBox::Objectinit()
{
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    Moduleb = new ModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(2)->Insidelayout,{"*.csv"});
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Moduleb->ui->pushButton,    &QPushButton::clicked,this,&DemoBox::Selectsnfile);
    connect(Filemanager,                &SuperFileManager::Signalfa,Logger, &SuperLogger::Displaylog);
    connect(Moduleb->ui->pushButton_3,  &QPushButton::clicked,      this,   &DemoBox::Process);
}

void DemoBox::Parameterinit()
{
    Demofilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Moduleb->ui->pushButton_3);
    Filemanager->Enablewidgetlist();
    Filemanager->Personalization("","Csv");
    Filemanager->Checkfilevaildinit();
}

/*  parameter init;*/

void DemoBox::Selectsnfile()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{"*.csv"});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &DemoBox::Displaysnfile);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsinglefile();
    filedialog->Show();
}

void DemoBox::Displaysnfile(QString text)
{
    Moduleb->ui->lineEdit->setText(text);
}

void DemoBox::Process()
{
    SuperC->Creatfile(Democachefile);
    QString text = SuperC->Readonlyfile(Moduleb->ui->lineEdit->text());
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
                Logger->Displaylog("N",sntemp,"processing...");
                Processcsvfile(sntemp);
            }
        }
        file.close();
    }
    else
    {
        SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,Moduleb->ui->lineEdit->text() + " is not exists;");
        messagebox->Messageinit();
    }
}

void DemoBox::Processcsvfile(QString serialnumber)
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
                SuperC->Appendfile(Democachefile,result);
                sncounttemp = sncounttemp + 1;
            }
        }
    }
    if(!sncounttemp)
    {
        SuperC->Appendfile(Democachefile,serialnumber + " has not found\r\n");
        Logger->Displaylog("N",serialnumber + " has not found;","processing...");
    }
}
