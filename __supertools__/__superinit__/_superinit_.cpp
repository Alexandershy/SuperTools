#include "_superinit_.h"

SuperInit::SuperInit(QWidget *parent)
    : QFrame(parent),
      ui(new Ui::SuperInit)
{
    ui->setupUi(this);
    connect(ui->Default_SuperSetting,   &QPushButton::clicked,      this,&SuperInit::defaultSetting);
    connect(ui->SuperSetting_Select,    &QPushButton::clicked,      this,&SuperInit::selectIni);
    connect(ui->Local_SuperSetting,     &QPushButton::clicked,      this,&SuperInit::local);
    init();
}

SuperInit::~SuperInit()
{
    delete ui;
}

void SuperInit::init()
{
    objectInit();
    creatFolder();
    creatFile();
    readmeInit();
}

/*  init function for this object creat;*/

void SuperInit::objectInit()
{
    Core = new SuperCore(this);
}

/*  object init;*/

void SuperInit::creatFolder()
{
    Core->creatFolder("./__depycache__");
    Core->creatFolder("./__depycache__/__cache__");
    Core->creatFolder("./__depycache__/__cache__/__bat__");
    Core->creatFolder("./__depycache__/__cache__/__ini__");
    Core->creatFolder("./__depycache__/__cache__/__picture__");
    Core->creatFolder("./__depycache__/__cache__/__setting__");
    Core->creatFolder("./__depycache__/__cache__/__textbrowser__");
    Core->creatFolder("./__readme__");
    Core->creatFolder("./__readme__/__plugins__");
}

/*  creat folder for save any files;*/

void SuperInit::creatFile()
{
    Core->creatFile("./__depycache__/__cache__/__ini__/_theme_.ini");
    Core->creatFile("./__depycache__/__cache__/__ini__/_backgroundcolor_.ini");
    Core->creatFile("./__depycache__/__cache__/__ini__/_fontcolor_.ini");
    Core->creatFile("./__depycache__/__cache__/__ini__/_quickaccess_.ini");
    Core->creatFile("./__depycache__/__cache__/__ini__/_openedstatus_.ini");
    Core->creatFile("." + Defaultsetting);
    Core->replaceFile(":/__supericon__/_localtitle_.png","./__depycache__/__cache__/__picture__/_localtitle_.png");
    creatModuleFiles();
}

/*  creat file for use;*/

void SuperInit::creatModuleFiles()
{
    QDir dir("./__plugins__/","*.so");
    QStringList files = dir.entryList();
    for(int i = 0;i < files.count();i++)
    {
        Core->creatFile("./__readme__/__plugins__/" + files.at(i).split("box").at(0) + "_.pdf");
    }
}

/*  creat super module files for import module;*/

void SuperInit::readmeInit()
{
    Core->replaceFile(":/pdf/_supertools_.pdf","./__readme__/_supertools_.pdf");
    Core->replaceFile(":/pdf/_superapi_.pdf","./__readme__/_superapi_.pdf");
}

void SuperInit::defaultSetting()
{
    QString file = "." + Defaultsetting;
    QString defaultbox = Core->readOnlyFile(file);
    if(defaultbox.isEmpty())
    {
        Core->writeOnlyFile(file, "_serialport_ = 1\n");
    }
    ui->SuperSetting_Edit->setText(qApp->applicationDirPath() + Defaultsetting);
    ui->Default_SuperSetting->setEnabled(false);
    enterMainFrame();
}

/*  creat default file and write init plugin, run Entermainframe function;*/

void SuperInit::enterMainFrame()
{
    QString setting = ui->SuperSetting_Edit->text();
    QString data = Core->readOnlyFile(setting);
    if(data.contains("_") && data.contains("=") && data.contains("1"))
    {
        qApp->setQuitOnLastWindowClosed(false);
        emit signalIa(ui->SuperSetting_Edit->text());
    }
}

/*  set dont close app when last window close,save select ini file path,load _frame_.dll;*/

void SuperInit::selectIni()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__depycache__/__cache__/__setting__/",{"*.ini"});
    connect(filedialog,&SuperFileDialog::signalFb,this,         &SuperInit::setIniFile);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
    filedialog->setSingleFile();
    filedialog->show();
}

/*  select ini file;*/

void SuperInit::setIniFile(QString file)
{
    ui->Default_SuperSetting->setEnabled(false);
    ui->Local_SuperSetting->setEnabled(true);
    ui->SuperSetting_Edit->setEnabled(true);
    ui->SuperSetting_Edit->setText(file);
}

/*  set ini file;*/

void SuperInit::local()
{
    enterMainFrame();
}

/*  run entermainframe function by local ini file;*/


