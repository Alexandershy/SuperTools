#include "_richerbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new RicherBox();
}

/*  return class RicherBox new instance pointer;*/

RicherBox::RicherBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("RicherBox");
    Setgroupbox(1,1);
    Init();
}

RicherBox::~RicherBox()
{

}

void RicherBox::Init()
{
    Objectinit();
    Parameterinit();
}

void RicherBox::Objectinit()
{
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.html"});
    connect(Filemanager,&SuperFileManager::Signalfa,Logger,&SuperLogger::Displaylog);
    connect(Filemanager,&SuperFileManager::Signalfc,this,&RicherBox::Open);
    connect(Filemanager,&SuperFileManager::Signalfd,this,&RicherBox::Open);
}

/*  object init;*/

void RicherBox::Parameterinit()
{
    Richerfilelist = &Filemanager->Filelist;
    Filemanager->Enablewidgetlist();
    Filemanager->Personalization(Sourcepath,"Richer");
    Filemanager->Checkfilevaildinit();
}

/*  parameter init;*/

void RicherBox::Open()
{
    QString richerfile = Filemanager->Getcurrentitemtext();
    DataDialog *dialog = new DataDialog(richerfile);
    Filemanager->Setcurrentfile(richerfile);
    dialog->Show();
    Logger->Displaylog("N",richerfile + " opened","Open function run completed");
}

/*  open csvdata table;*/
