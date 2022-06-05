#include "_supermain_.h"

#ifdef Q_OS_WIN
const char *Supertabsymbol      = "?Loadplugin@Interface@@QEAAPEAVSuperTab@@XZ";
#else
const char *Supertabsymbol      = "_ZN9Interface10LoadpluginEv";
#endif

SuperMain::SuperMain(QWidget *parent,QString setting)
    : SuperTabWidget(parent)
{
    Setting = setting;
    setMovable(true);
    setTabsClosable(true);
    setMouseTracking(true);
    setMinimumSize(800,550);
    connect(this,&QTabWidget::tabCloseRequested,this,&SuperMain::openCloseTabBox);
    connect(this,&QTabWidget::tabBarDoubleClicked,this,&SuperMain::openEjectTabBox);
    init();
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
                save();
                break;
            }
            case Qt::Key_L:
            {
                loadPlugin();
                break;
            }
            case Qt::Key_O:
            {
                openCachePath();
                break;
            }
            case Qt::Key_P:
            {
                openCloseTabBox(currentIndex());
                break;
            }
        }
    }
}

void SuperMain::enterEvent(QEnterEvent *)
{
    emit signalMc(Qt::ArrowCursor);
}

/*  mouse enter;*/

void SuperMain::init()
{
    objectInit();
    actionInit();
    importSetting(Setting);
}

/*  main init;*/

void SuperMain::objectInit()
{
    Core = new SuperCore(this);
    Load = new QMenu(this);
    Help = new QMenu(this);
    Config = new QMenu(this);
    Load->setIcon(QIcon(":/__supericon__/_load_.svg"));
    Help->setIcon(QIcon(":/__supericon__/_help_.svg"));
    Config->setIcon(QIcon(":/__supericon__/_config_.svg"));
}

/*  object init;*/

void SuperMain::actionInit()
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
    connect(Actionsetting,          &QAction::triggered,    this,&SuperMain::loadSetting);
    connect(Actionplugin,           &QAction::triggered,    this,&SuperMain::loadPlugin);
    connect(Actionsave,             &QAction::triggered,    this,&SuperMain::save);
    connect(Actionsaveas,           &QAction::triggered,    this,&SuperMain::saveAs);
    connect(Actionquit,             &QAction::triggered,    this,&SuperMain::close);
    connect(Actionopencachepath,    &QAction::triggered,    this,&SuperMain::openCachePath);
    connect(Actionversion,          &QAction::triggered,    this,&SuperMain::checkVersion);
    connect(Actionreadme,           &QAction::triggered,    this,&SuperMain::readme);
    connect(Actionsuperapi,         &QAction::triggered,    this,&SuperMain::superApi);
    Load->addAction(Actionplugin);
    Load->addAction(Actionsetting);
    Config->addAction(Actionchangelanguage);
    Help->addAction(Actionopencachepath);
    Help->addAction(Actionversion);
    Help->addAction(Actionreadme);
    Help->addAction(Actionsuperapi);
}

/*  action init;*/

void SuperMain::loadSetting()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__depycache__/__cache__/__setting__/",{"*.ini"});
    connect(filedialog,&SuperFileDialog::signalFb,this,         &SuperMain::importSetting);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
    filedialog->setSingleFile();
    filedialog->show();
}

/*  open windows resource manager and select ini fils, run Importsetting function;*/

void SuperMain::loadPlugin()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__readme__/__plugins__/",{"*.pdf"});
    connect(filedialog,&SuperFileDialog::signalFc,this,         &SuperMain::importPlugins);
    connect(filedialog,&SuperFileDialog::signalFc,filedialog,   &QObject::deleteLater);
    filedialog->show();
}

/*  open windows resource manager and select pdf files, run Importplugin function;*/

void SuperMain::importPlugins(QStringList listpdf)
{
    QStringList templist = {};
    QStringList listpdfpath = {};
    QString cacheini = "./__depycache__/__cache__/__ini__/_cachesetting_.ini";
    if(!listpdf.isEmpty())
    {
        for(int i = 0;i < listpdf.count() ; i++)
        {
            listpdfpath = listpdf.at(i).split("/");
            templist.append(Core->getListLastMember(&listpdfpath).split(".").at(0) + " = 1\n");
        }
    }
    Core->creatFile(cacheini);
    Core->writeOnlyFileList(cacheini,&templist,"",true);
    importSetting(cacheini);
    QFile::remove(cacheini);
}

/*  before import plugin,check pdf files is broken, write pdf names to ini file,and run Importsetting function;*/

void SuperMain::importSetting(QString strini)
{
    QString plugin = Core->readOnlyFile(strini);
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
                QString tabname = Core->firstWordUpper(filename);
                addTabApi(dllname,tabname,filename);
            }
            else
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"load plugin error;");
                notedialog->hideLeftButton();
                notedialog->messageInit();
            }
        }
    }
}

/*  read setting from ini file,and run Addtabapi function;*/

void SuperMain::addTabApi(QString strdllname,QString strtabname,QString strobjname)
{
    QLibrary library("./__plugins__/" + strdllname);
    if(library.isLoaded())
    {
        Tab = (Groupboxfun)library.resolve(Supertabsymbol);
        addTab(strtabname, Tab(),strobjname);
    }
    else if(library.load())
    {
        Tab = (Groupboxfun)library.resolve(Supertabsymbol);
        addTab(strtabname, Tab(),strobjname);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,library.errorString());
        notedialog->hideLeftButton();
        notedialog->messageInit();
    }
}

/*  load dll,run Addtab function,if not found that dll,eject a message box;*/

void SuperMain::addTab(QString strtabname,QWidget* widget,QString strobjname)
{
    int tabcount = count();
    if(Core->findListMember(&Tabnamelist,strobjname) == -1)
    {
        QTabWidget::addTab(widget,strtabname);
        setCurrentIndex(tabcount);
        Tabnamelist.append(strobjname);
    }
    else
    {
        delete widget;
        showTab(&Tabnamelist,strobjname);
    }
}

/*  creat a new tab to Tab_Init,and show it,if object name has repeated,run Showtab function;*/

void SuperMain::showTab(QStringList *listobjname,QString strobjname)
{
    if(count() == listobjname->count())
    {
        for(int i = 0;i < listobjname->count();i++)
        {
            if(strobjname == listobjname->at(i))
            {
                setCurrentIndex(i);
            }
        }
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"need to return all tab;");
        notedialog->hideLeftButton();
        notedialog->messageInit();
    }
}

/*  show tab by objectname*/

void SuperMain::save()
{
    saveSetting(Setting);
}

/*  run Savesetting and eject notedialog;*/

void SuperMain::saveSetting(QString strtitle)
{
    QStringList listobjname = {};
    for(int i = 0;i < count();i++)
    {
        listobjname.append("_" + Tabnamelist.at(i) + "_ = 1\n");
    }
    Core->writeOnlyFileList(strtitle,&listobjname,"",true);
    QStringList savedsetting = Core->readOnlyFile(strtitle).split("\n");
    for(int i = 0;i < count();i++)
    {
        if(!savedsetting.at(i).contains(Tabnamelist.at(i)) || !savedsetting.at(i).contains(" = 1"))
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"Save Error!!");
            notedialog->hideLeftButton();
            notedialog->messageInit();
            return;
        }
    }
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"Save Success!!");
    notedialog->hideLeftButton();
    notedialog->messageInit();
}

/*  add tab objectname to ini file;*/

void SuperMain::saveAs()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__depycache__/__cache__/__setting__/",{"*.ini"});
    connect(filedialog,&SuperFileDialog::signalFb,this,         &SuperMain::saveSetting);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
    filedialog->setSaveFile();
    filedialog->show();
}

/*  write tab objectname to a new ini file;*/

void SuperMain::openCachePath()
{
    QString dirpath = "./__depycache__/__" + Core->firstWordLower(tabText(currentIndex())) + "__";
    QDir dir(dirpath);
    if(dir.exists())
    {
        Core->openPath(dirpath);
    }
    else
    {
        Core->openPath("./__depycache__");
    }
}

/*  open folder;*/

void SuperMain::checkVersion()
{
    emit signalMa("./__readme__/_supertools_.pdf");
}

/*  display version;*/

void SuperMain::readme()
{
    emit signalMa("./__readme__/__plugins__/_" + Core->firstWordLower(tabText(currentIndex())) + "_.pdf");
}

/*  open and view readme;*/

void SuperMain::superApi()
{
    emit signalMa("./__readme__/_superapi_.pdf");
}

/*  open and view super api;*/

void SuperMain::openCloseTabBox(int intindex)
{
    setCurrentIndex(intindex);
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"sure to close " + tabText(intindex) + "?");
    connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperMain::closeTab);
    notedialog->messageInit();
}

/*  show close tab first,eject notedialog;*/

void SuperMain::closeTab()
{
    if(count() > 1)
    {
        Tabnamelist.removeOne(Core->firstWordLower(tabText(currentIndex())));
        delete widget(currentIndex());
    }
    else if(count() == 1)
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"can not close the last tab;");
        notedialog->hideLeftButton();
        notedialog->messageInit();
    }
}

/*  close current tab;*/

void SuperMain::openEjectTabBox(int intindex)
{
    if(count() > 1)
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"sure to eject " + Core->firstWordLower(tabText(intindex)) + "?");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperMain::ejectTab);
        notedialog->messageInit();
    }
    else if(count() == 1)
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"can not eject last tab;");
        notedialog->hideLeftButton();
        notedialog->messageInit();
    }
}

/*  show eject tab first,eject notedialog;*/

void SuperMain::ejectTab()
{
    QWidget *widget = currentWidget();
    SuperWindow *window = new SuperWindow(nullptr);
    connect(window,&SuperWindow::signalWe,this,&SuperMain::returnTab);
    widget->setParent(nullptr);
    window->setTitle(widget->objectName().split("Box").at(0) + " Dialog");
    window->setWidget(widget);
    widget->setHidden(false);
    window->show();
}

/*  eject current tab;*/

void SuperMain::returnTab(QWidget *widget)
{
    widget->setParent(nullptr);
    QString tabname = Core->allWordLower(widget->objectName()).split("box").at(0);
    QTabWidget::addTab(widget,Core->firstWordUpper(tabname));
    setCurrentIndex(count() - 1);
}

/*  return tab;*/

void SuperMain::close()
{
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"you sure to quit?");
    connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperMain::signalMb);
    notedialog->messageInit();
}

/*  eject message box when close app;*/

void SuperMain::setFocus()
{
    QWidget::setFocus();
}

/*  set focus;*/
