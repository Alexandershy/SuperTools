#include "_gamebox_.h"

SuperTab* Interface::Loadplugin()
{
    return new GameBox();
}

/*  return class GameBox new instance pointer;*/

GameBox::GameBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("GameBox");
    Setgroupbox(2,1);
    Setstretch({99,1},{100});
    Init();
}

GameBox::~GameBox()
{

}

void GameBox::Init()
{
    Objectinit();
    Parameterinit();
    Creatgamefileinit();
}

void GameBox::Objectinit()
{
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.super"});
    Modulea = new ModuleA(this,Leftgroupboxlist.at(1)->Insidelayout);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    connect(Filemanager,&SuperFileManager::Signalfa,Logger,&SuperLogger::Displaylog);
    connect(Filemanager,&SuperFileManager::Signalfc,this,&GameBox::Play);
    connect(Filemanager,&SuperFileManager::Signalfd,this,&GameBox::Play);
}

/*  object init;*/

void GameBox::Parameterinit()
{
    Gamefilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Modulea->ui->pushButton);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_2);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_3);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_4);
    Filemanager->Enablewidgetlist();
    Filemanager->Personalization(Sourcepath,"Super");
    Filemanager->Checkfilevaildinit();
}

/*  parameter init;*/

void GameBox::Creatgamefileinit()
{
    SuperC->Creatfile(Hitbricks);
    SuperC->Writeonlyfile(Hitbricks,"0");
}

/*  creat game file init;*/

void GameBox::Play()
{
    bool boola = false;
    QString gamefile = Filemanager->Getcurrentitemtext();
    int gameindex = SuperC->Readonlyfile(gamefile).toInt(&boola);
    Filemanager->Setcurrentfile(gamefile);
    if(boola)
    {
        switch (gameindex)
        {
            case 0:
            {
                HitBricksDialog *hitbricksdialog = new HitBricksDialog(nullptr);
                hitbricksdialog->Show();
                break;
            }
            default:
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"game index error;");
                notedialog->Messageinit();
                notedialog->Show();
                break;
            }
        }
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,gamefile + " has been broken;");
        notedialog->Messageinit();
        notedialog->Show();
    }
}

/*  play games depend on current item text;*/
