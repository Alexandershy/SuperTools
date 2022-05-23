#include "_richerbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new RicherBox();
}

/*  return class RicherBox new instance pointer;*/

RicherBox::RicherBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("RicherBox");
    setGroupBox(1,1);
    init();
}

RicherBox::~RicherBox()
{

}

void RicherBox::init()
{
    objectInit();
    parameterInit();
}

void RicherBox::objectInit()
{
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.html"});
    connect(Filemanager,&SuperFileManager::signalFa,Logger,&SuperLogger::displayLog);
    connect(Filemanager,&SuperFileManager::signalFc,this,&RicherBox::open);
    connect(Filemanager,&SuperFileManager::signalFd,this,&RicherBox::open);
}

/*  object init;*/

void RicherBox::parameterInit()
{
    Richerfilelist = &Filemanager->Filelist;
    Filemanager->enableWidgetList();
    Filemanager->personalization(Sourcepath,"Richer");
    Filemanager->checkFileVaildInit();
}

/*  parameter init;*/

void RicherBox::open()
{
    QString richerfile = Filemanager->getCurrentItemText();
    RicherDataDialog *dialog = new RicherDataDialog(richerfile);
    Filemanager->setCurrentFile(richerfile);
    dialog->show();
    Logger->displayLog("N",richerfile + " opened","Open function run completed");
}

/*  open csvdata table;*/
