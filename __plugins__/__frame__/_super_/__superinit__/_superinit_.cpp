#include "_superinit_.h"

SuperInit::SuperInit(QWidget *parent)
    : QFrame(parent),
      ui(new Ui::SuperInit)
{
    ui->setupUi(this);
    connect(ui->Default_SuperSetting,   &QPushButton::clicked,      this,&SuperInit::Default);
    connect(ui->SuperSetting_Select,    &QPushButton::clicked,      this,&SuperInit::Selectini);
    connect(ui->Local_SuperSetting,     &QPushButton::clicked,      this,&SuperInit::Local);
    Init();
}

SuperInit::~SuperInit()
{
    delete ui;
}

void SuperInit::Init()
{
    Objectinit();
    Creatfolder();
    Creatfile();
    Readmeinit();
}

/*  init function for this object creat;*/

void SuperInit::Objectinit()
{
    SuperC = new SuperCore(this);
}

/*  object init;*/

void SuperInit::Creatfolder()
{
    SuperC->Creatfolder("__depycache__");
    SuperC->Creatfolder("__depycache__/__cache__");
    SuperC->Creatfolder("__depycache__/__cache__/__bat__");
    SuperC->Creatfolder("__depycache__/__cache__/__ini__");
    SuperC->Creatfolder("__depycache__/__cache__/__picture__");
    SuperC->Creatfolder("__depycache__/__cache__/__textbrowser__");
    SuperC->Creatfolder("__readme__");
    SuperC->Creatfolder("__readme__/__setting__");
    SuperC->Creatfolder("__readme__/__module__");
    SuperC->Creatfolder("__readme__/__frame__");
}

/*  creat folder for save any files;*/

void SuperInit::Creatfile()
{
    SuperC->Creatfile("./__readme__/__setting__/_defaultsetting_.ini");
    SuperC->Creatfile("./__depycache__/__cache__/__ini__/_theme_.ini");
    SuperC->Creatfile("./__depycache__/__cache__/__ini__/_backgroundcolor_.ini");
    SuperC->Creatfile("./__depycache__/__cache__/__ini__/_fontcolor_.ini");
    SuperC->Creatfile("./__depycache__/__cache__/__ini__/_cachesetting_.ini");
    SuperC->Creatfile("./__depycache__/__cache__/__ini__/_quickaccess_.ini");
    SuperC->Creatfile("./__depycache__/__cache__/__ini__/_openedstatus_.ini");
    SuperC->Replacefile(":/__supericon__/_localtitle_.png","./__depycache__/__cache__/__picture__/_localtitle_.png");
    SuperC->Replacefile(":/__supericon__/_supertools_.ico","./__depycache__/__cache__/__picture__/_supertools_.ico");
    Creatmodulefiles();
}

/*  creat file for use;*/

void SuperInit::Creatmodulefiles()
{
    QDir dir("./__plugins__/__device__/");
    dir.setNameFilters({"*.dll"});
    QStringList files = dir.entryList();
    for(int i = 0;i < files.count();i++)
    {
        SuperC->Creatfile("./__readme__/__module__/" + files.at(i).split("box").at(0) + "_.pdf");
    }
}

/*  creat super module files for import module;*/

void SuperInit::Readmeinit()
{
    SuperC->Replacefile(":/pdf/_super_.pdf","./__readme__/__frame__/_super_.pdf");
    SuperC->Replacefile(":/pdf/_superapi_.pdf","./__readme__/__frame__/_superapi_.pdf");
}

void SuperInit::Default()
{
    QString file = "./__readme__/__setting__/_defaultsetting_.ini";
    QString defaultbox = SuperC->Readonlyfile(file);
    if(defaultbox.isEmpty())
    {
        SuperC->Writeonlyfile(file, "_serialport_ = 1\n");
    }
    ui->SuperSetting_Edit->setText(qApp->applicationDirPath() + "/__readme__/__setting__/_defaultsetting_.ini");
    ui->Default_SuperSetting->setEnabled(false);
    Entermainframe();
}

/*  creat default file and write init plugin, run Entermainframe function;*/

void SuperInit::Entermainframe()
{
    QString setting = ui->SuperSetting_Edit->text();
    QString data = SuperC->Readonlyfile(setting);
    if(data.contains("_") && data.contains("=") && data.contains("1"))
    {
        qApp->setQuitOnLastWindowClosed(false);
        emit Signalia(ui->SuperSetting_Edit->text());
    }
}

/*  set dont close app when last window close,save select ini file path,load _frame_.dll;*/

void SuperInit::Selectini()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__readme__/__setting__/",{"*.ini"});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &SuperInit::Setinifile);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsinglefile();
    filedialog->Show();
}

/*  select ini file;*/

void SuperInit::Setinifile(QString file)
{
    if(file.isEmpty())
    {
        ui->Default_SuperSetting->setEnabled(true);
        ui->Local_SuperSetting->setEnabled(false);
        ui->SuperSetting_Edit->setEnabled(false);
        file = "./__readme__/__setting__/_defaultsetting_.ini";
    }
    else
    {
        ui->Default_SuperSetting->setEnabled(false);
        ui->Local_SuperSetting->setEnabled(true);
        ui->SuperSetting_Edit->setEnabled(true);
    }
    ui->SuperSetting_Edit->setText(file);
}

/*  set ini file;*/

void SuperInit::Local()
{
    Entermainframe();
}

/*  run entermainframe function by local ini file;*/


