#include "_supermain_.h"

#ifdef Q_OS_UNIX
const char* Supertabsymbol = "_ZN9Interface10LoadpluginEv";
#endif

#ifdef Q_OS_WIN
const char* Supertabsymbol = "_ZN9Interface10LoadpluginEv";
#endif

SuperMain::SuperMain(QWidget *parent,QString setting)
    : SuperTabWidget(parent)
{
    Setting = setting;
    setMovable(true);
    connect(this,&QTabWidget::tabCloseRequested,this,&SuperMain::Openclosetabbox);
    Init();
}

SuperMain::~SuperMain()
{

}

void SuperMain::keyPressEvent(QKeyEvent *event)
{
    if((event->modifiers() == Qt::ControlModifier))
    {
        switch (event->key())
        {
            case Qt::Key_S:
            {
                Save();
                break;
            }
            case Qt::Key_L:
            {
                Loadmodule();
                break;
            }
            case Qt::Key_O:
            {
                Opencachepath();
                break;
            }
            case Qt::Key_P:
            {
                Openclosetabbox(currentIndex());
                break;
            }
        }
    }
}

void SuperMain::enterEvent(QEnterEvent *)
{
    emit Signalmc(Qt::ArrowCursor);
}

/*  mouse enter;*/

void SuperMain::Init()
{
    Parameterinit();
    Objectinit();
    Actioninit();
    Importsetting(Setting);
}

/*  main init;*/

void SuperMain::Parameterinit()
{
    setTabsClosable(true);
    setMouseTracking(true);
    setMinimumSize(800,550);
}

/*  setfoucs*/

void SuperMain::Objectinit()
{
    SuperC = new SuperCore(this);
    Load = new QMenu(this);
    Help = new QMenu(this);
    Config = new QMenu(this);
    Load->setIcon(QIcon(":/__supericon__/_load_.svg"));
    Help->setIcon(QIcon(":/__supericon__/_help_.svg"));
    Config->setIcon(QIcon(":/__supericon__/_config_.svg"));
}

/*  object init;*/

void SuperMain::Actioninit()
{
    Actionplugin = new QAction(QIcon(":/__supericon__/_plugin_.svg"),"Plugin",Load);
    Actionsetting = new QAction(QIcon(":/__supericon__/_setting_.svg"),"Setting",Load);
    Actionsave = new QAction(QIcon(":/__supericon__/_save_.svg"),"Save",this);
    Actionsaveas = new QAction(QIcon(":/__supericon__/_saveas_.svg"),"Save As",this);
    Actionchangelanguage = new QAction(QIcon(":/__supericon__/_changelanguage_.svg"),"Change Language",Config);
    Actionopencachepath = new QAction(QIcon(":/__supericon__/_opencachefolder_.svg"),"Open Cache Path",Help);
    Actionversion = new QAction(QIcon(":/__supericon__/_version_.svg"),"Version",Help);
    Actionreadme = new QAction(QIcon(":/__supericon__/_instructions_.svg"),"Readme",Help);
    Actionsuperapi = new QAction(QIcon(":/__supericon__/_superapi_.svg"),"Superapi",Help);
    Actionquit = new QAction(QIcon(":/__supericon__/_quit_.svg"),"Quit",this);
    Actionchangelanguage->setEnabled(false);
    connect(Actionsetting,          &QAction::triggered,    this,&SuperMain::Loadsetting);
    connect(Actionplugin,           &QAction::triggered,    this,&SuperMain::Loadmodule);
    connect(Actionsave,             &QAction::triggered,    this,&SuperMain::Save);
    connect(Actionsaveas,           &QAction::triggered,    this,&SuperMain::Saveas);
    connect(Actionquit,             &QAction::triggered,    this,&SuperMain::Closeevent);
    connect(Actionopencachepath,    &QAction::triggered,    this,&SuperMain::Opencachepath);
    connect(Actionversion,          &QAction::triggered,    this,&SuperMain::Checkversion);
    connect(Actionreadme,           &QAction::triggered,    this,&SuperMain::Readme);
    connect(Actionsuperapi,         &QAction::triggered,    this,&SuperMain::Superapi);
    Load->addAction(Actionplugin);
    Load->addAction(Actionsetting);
    Config->addAction(Actionchangelanguage);
    Help->addAction(Actionopencachepath);
    Help->addAction(Actionversion);
    Help->addAction(Actionreadme);
    Help->addAction(Actionsuperapi);
}

/*  action init;*/

void SuperMain::Loadsetting()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__readme__/__setting__/",{"*.ini"});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &SuperMain::Importsetting);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsinglefile();
    filedialog->Show();
}

/*  open windows resource manager and select ini fils, run Importsetting function;*/

void SuperMain::Loadmodule()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__readme__/__module__/",{"*.pdf"});
    connect(filedialog,&SuperFileDialog::Signalfc,this,         &SuperMain::Importplugins);
    connect(filedialog,&SuperFileDialog::Signalfc,filedialog,   &QObject::deleteLater);
    filedialog->Show();
}

/*  open windows resource manager and select pdf files, run Importplugin function;*/

void SuperMain::Importplugins(QStringList listpdf)
{
    QStringList templist = {};
    QStringList listpdfpath = {};
    QString cacheini = "./__depycache__/__cache__/__ini__/_cachesetting_.ini";
    if(!listpdf.isEmpty())
    {
        for(int i = 0;i < listpdf.count() ; i++)
        {
            listpdfpath = listpdf.at(i).split("/");
            templist.append(SuperC->Getlistlastmember(&listpdfpath).split(".").at(0) + " = 1\n");
        }
    }
    SuperC->Writeonlyfilelist(cacheini,&templist,"",true);
    Importsetting(cacheini);
}

/*  before import plugin,check pdf files is broken, write pdf names to ini file,and run Importsetting function;*/

void SuperMain::Importsetting(QString strini)
{
    QString plugin = SuperC->Readonlyfile(strini);
    QStringList fileimport = plugin.split("\n");
    int fileimportcount = fileimport.count();
    for(int i = 0;i < fileimportcount;i++)
    {
        if(fileimport[i].contains("=") && (fileimport[i].split("=")[1].toInt() == 1))
        {
            QStringList filenamesplit = fileimport[i].split('_');
            if(filenamesplit.count() >= 2)
            {
                QString filename = fileimport[i].split('_')[1];
                QString dllname = "_" + filename + "box_";
                QString tabname = SuperC->Firstwordupper(filename);
                Addtabapi(dllname,tabname,filename);
            }
            else
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"load plugin error;");
                notedialog->Hideleftbutton();
                notedialog->Messageinit();
            }
        }
    }
}

/*  read setting from ini file,and run Addtabapi function;*/

void SuperMain::Addtabapi(QString strdllname,QString strtabname,QString strobjname)
{
    QLibrary library("./__plugins__/__device__/" + strdllname);
    if(library.isLoaded())
    {
        Tab = (Groupboxfun)library.resolve(Supertabsymbol);
        Addtab(strtabname, Tab(),strobjname);
    }
    else if(library.load())
    {
        Tab = (Groupboxfun)library.resolve(Supertabsymbol);
        Addtab(strtabname, Tab(),strobjname);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,library.errorString());
        notedialog->Hideleftbutton();
        notedialog->Messageinit();
    }
}

/*  load dll,run Addtab function,if not found that dll,eject a message box;*/

void SuperMain::Addtab(QString strtabname,QWidget* widget,QString strobjname)
{
    int tabcount = count();
    if(SuperC->Findlistmember(&Tabnamelist,strobjname) == -1)
    {
        addTab(widget,strtabname);
        setCurrentIndex(tabcount);
        Tabnamelist.append(strobjname);
    }
    else
    {
        delete widget;
        Showtab(&Tabnamelist,strobjname);
    }
}

/*  creat a new tab to Tab_Init,and show it,if object name has repeated,run Showtab function;*/

void SuperMain::Showtab(QStringList *listobjname,QString strobjname)
{
    for(int i = 0;i < listobjname->count();i++)
    {
        if(strobjname == listobjname->at(i))
        {
            setCurrentIndex(i);
        }
    }
}

/*  show tab by objectname*/

void SuperMain::Save()
{
    Savesetting(Setting);
}

/*  run Savesetting and eject notedialog;*/

void SuperMain::Savesetting(QString strtitle)
{
    QStringList listobjname = {};
    for(int i = 0;i < count();i++)
    {
        listobjname.append("_" + Tabnamelist.at(i) + "_ = 1\n");
    }
    SuperC->Writeonlyfilelist(strtitle,&listobjname,"",true);
    QStringList savedsetting = SuperC->Readonlyfile(strtitle).split("\n");
    for(int i = 0;i < count();i++)
    {
        if(!savedsetting.at(i).contains(Tabnamelist.at(i)) || !savedsetting.at(i).contains(" = 1"))
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"Save Error!!");
            notedialog->Hideleftbutton();
            notedialog->Messageinit();
            return;
        }
    }
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"Save Success!!");
    notedialog->Hideleftbutton();
    notedialog->Messageinit();
}

/*  add tab objectname to ini file;*/

void SuperMain::Saveas()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__readme__/__setting__/",{"*.ini"});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &SuperMain::Savesetting);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsavefile();
    filedialog->Show();
}

/*  write tab objectname to a new ini file;*/

void SuperMain::Opencachepath()
{
    QString dirpath = "./__depycache__/__" + Tabnamelist.at(currentIndex()) + "__";
    QDir dir(dirpath);
    if(dir.exists())
    {
        SuperC->Openpath(dirpath);
    }
    else
    {
        SuperC->Openpath("./__depycache__");
    }
}

/*  open folder;*/

void SuperMain::Checkversion()
{
    emit Signalma("./__readme__/__frame__/_super_.pdf");
}

/*  display version;*/

void SuperMain::Readme()
{
    emit Signalma("./__readme__/__module__/_" + Tabnamelist.at(currentIndex()) + "_.pdf");
}

/*  open and view readme;*/

void SuperMain::Superapi()
{
    emit Signalma("./__readme__/__frame__/_superapi_.pdf");
}

/*  open and view super api;*/

void SuperMain::Openclosetabbox(int intindex)
{
    setCurrentIndex(intindex);
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"sure to close " + Tabnamelist.at(intindex) + "?");
    connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperMain::Closetab);
    notedialog->Messageinit();
}

/*  show close tab first,eject notedialog;*/

void SuperMain::Closetab()
{
    if(count() > 1)
    {
        Tabnamelist.removeAt(currentIndex());
        delete widget(currentIndex());
    }
    else if(count() == 1)
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"can not close the last tab;");
        notedialog->Hideleftbutton();
        notedialog->Messageinit();
    }
}

/*  close current tab,can not close the last tab;*/

void SuperMain::Closeevent()
{
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"you sure to quit?");
    connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperMain::Signalmb);
    notedialog->Messageinit();
}

/*  eject message box when close app;*/

void SuperMain::Setfocus()
{
    setFocus();
}

/*  set focus;*/
