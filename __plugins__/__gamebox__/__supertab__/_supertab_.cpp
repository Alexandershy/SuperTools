#include "_supertab_.h"

SuperTab::SuperTab(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::SuperTab)
{
    ui->setupUi(this);
    Init();
}

SuperTab::~SuperTab()
{
    delete ui;
}

void SuperTab::Init()
{
    Objectinit();
}

/*  tab init;*/

void SuperTab::Objectinit()
{
    SuperC = new SuperCore(this);
}

/*  object init;*/

void SuperTab::Setgroupbox(int left,int right)
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

void SuperTab::Setstretch(QList<int> leftstretch,QList<int> rightstretch)
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

void SuperTab::Readme(QString objectname)
{
    setObjectName(objectname);
    SuperC->Replacefile(":/pdf/_" + SuperC->Allwordlower(objectname) + "_.pdf","./__readme__/__module__/_" + SuperC->Allwordlower(objectname).split("box").at(0) + "_.pdf");
    SuperC->Creatfolder("__depycache__/__" + SuperC->Allwordlower(objectname).split("box").at(0) + "__");
    SuperC->Creatfile("__depycache__/__" + SuperC->Allwordlower(objectname).split("box").at(0) + "__/_defaultsetting_.ini");
}

/*  read me;*/
