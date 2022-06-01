#include "_supertab_.h"
#include "ui__supertabui_.h"

SuperTab::SuperTab(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::SuperTabui)
{
    ui->setupUi(this);
    init();
}

SuperTab::~SuperTab()
{
    delete ui;
}

void SuperTab::init()
{
    objectInit();
}

/*  tab init;*/

void SuperTab::objectInit()
{
    Core = new SuperCore(this);
}

/*  object init;*/

void SuperTab::setGroupBox(int left,int right)
{
    Groupboxcounts.clear();
    Groupboxcounts.append(left);
    Groupboxcounts.append(right);
    for(int i = 0;i < Groupboxcounts.at(0);i++)
    {
        Leftgroupboxlist.append(new SuperGroupBox(this,ui->Leftlayout));
    }
    for(int i = 0;i < Groupboxcounts.at(1);i++)
    {
        Rightgroupboxlist.append(new SuperGroupBox(this,ui->Rightlayout));
    }
}

/*  object init;*/

void SuperTab::setStretch(QList<int> leftstretch,QList<int> rightstretch)
{
    for(int i = 0;i < Groupboxcounts.at(0);i++)
    {
        ui->Leftlayout->setStretch(i,leftstretch.at(i));
    }
    for(int i = 0;i < Groupboxcounts.at(1);i++)
    {
        ui->Rightlayout->setStretch(i,rightstretch.at(i));
    }
}

/*  set tab stretch;*/

void SuperTab::readMe(QString objectname)
{
    setObjectName(objectname);
    Core->replaceFile(":/pdf/_" + Core->allWordLower(objectname) + "_.pdf","./__readme__/__plugins__/_" + Core->allWordLower(objectname).split("box").at(0) + "_.pdf");
    Core->creatFolder("__depycache__/__" + Core->allWordLower(objectname).split("box").at(0) + "__");
    Core->creatFile("__depycache__/__" + Core->allWordLower(objectname).split("box").at(0) + "__/_defaultsetting_.ini");
}

/*  read me;*/
