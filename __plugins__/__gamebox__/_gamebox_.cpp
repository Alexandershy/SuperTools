#include "_gamebox_.h"

SuperTab* Interface::Loadplugin()
{
    return new GameBox();
}

/*  return class GameBox new instance pointer;*/

GameBox::GameBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("GameBox");
    setGroupBox(2,1);
    setStretch({99,1},{100});
    init();
}

GameBox::~GameBox()
{

}

void GameBox::init()
{
    objectInit();
    parameterInit();
    creatGameFileInit();
}

void GameBox::objectInit()
{
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.super"});
    Modulea = new GameModuleA(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Filemanager,&SuperFileManager::signalFa,Logger,&SuperLogger::displayLog);
    connect(Filemanager,&SuperFileManager::signalFc,this,&GameBox::play);
    connect(Filemanager,&SuperFileManager::signalFd,this,&GameBox::play);
}

/*  object init;*/

void GameBox::parameterInit()
{
    Gamefilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Modulea->ui->pushButton);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_2);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_3);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_4);
    Filemanager->enableWidgetList();
    Filemanager->personalization(Sourcepath,"Super");
    Filemanager->checkFileVaildInit();
}

/*  parameter init;*/

void GameBox::creatGameFileInit()
{
    Core->creatFile(Hitbricks);
    Core->writeOnlyFile(Hitbricks,"0");
}

/*  creat game file init;*/

void GameBox::play()
{
    bool boola = false;
    QString gamefile = Filemanager->getCurrentItemText();
    int gameindex = Core->readOnlyFile(gamefile).toInt(&boola);
    Filemanager->setCurrentFile(gamefile);
    if(boola)
    {
        switch (gameindex)
        {
            case 0:
            {
                HitBricksDialog *hitbricksdialog = new HitBricksDialog(nullptr);
                hitbricksdialog->show();
                break;
            }
            default:
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"game index error;");
                notedialog->messageInit();
                notedialog->show();
                break;
            }
        }
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,gamefile + " has been broken;");
        notedialog->messageInit();
        notedialog->show();
    }
}

/*  play games depend on current item text;*/
