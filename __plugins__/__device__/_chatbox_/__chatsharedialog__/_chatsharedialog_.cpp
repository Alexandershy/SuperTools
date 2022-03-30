#include "_chatsharedialog_.h"

ChatShareDialog::ChatShareDialog(QWidget *parent,QLineEdit *lineedit)
    : SuperWindow(parent)
{
    Lineedit = lineedit;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Settitle(Lineedit->text() + "'s file shared");
    Init();
}

ChatShareDialog::~ChatShareDialog()
{
    SuperC->Closethread(Threadga);
}

void ChatShareDialog::Init()
{
    Objectinit();
    Checkuserinit();
    Refreshsharedfiles();
}

void ChatShareDialog::Objectinit()
{
    Localuser = QDir::home().dirName() + " " + QHostInfo::localHostName();
    Sharedfolder = "./__depycache__/__chat__/__" + Lineedit->text() + "__/";
    Targetpath = Sharedfolder + "_targetpath_.txt";
    Sharedfilepath = Sharedfolder + "_filesshared_.txt";
    SuperC->Creatfile(Sharedfilepath);
    Plugin = new ChatShareBox(this);
    Threadga = new GetFileInfoThread(Sharedfilepath,Plugin->ui->treeWidget->columnCount(),Lineedit->text(),Localuser,&Fileslist,Sharedfolder);
    Pluginlayout->addWidget(Plugin);
    Plugin->ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->treeWidget->header()->setStretchLastSection(false);
    connect(Plugin->Cancelshared,   &QAction::triggered,            this,&ChatShareDialog::Cancelsharedfiles);
    connect(Plugin->Downloadfile,   &QAction::triggered,            this,&ChatShareDialog::Downloadfiles);
    connect(Plugin->Downloadfileas, &QAction::triggered,            this,&ChatShareDialog::Selectdownloadpath);
    connect(Plugin->Openpath,       &QAction::triggered,            this,&ChatShareDialog::Opencontactfolder);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemPressed,      this,&ChatShareDialog::Openitemoptions);
    connect(Threadga,               &GetFileInfoThread::Signalga,   this,&ChatShareDialog::Refreshsharedfilesslot);
    connect(Threadga,               &GetFileInfoThread::finished,   this,&ChatShareDialog::Writetolocal);
}

/*  creat plugin box,thread and connect its slot;*/

void ChatShareDialog::Checkuserinit()
{
    if(Lineedit->text() == Localuser)
    {
        connect(Plugin->ui->pushButton, &QPushButton::clicked,      this,&ChatShareDialog::Selectsharedfiles);
        SuperC->Addaction(Plugin->Itemoptions,Plugin->Cancelshared,"Cancel Shared","Cancel Shared");
        SuperC->Addaction(Plugin->Itemoptions,Plugin->Openpath,"Open path","Open path");
    }
    else
    {
        Plugin->ui->pushButton->setText("Refresh Files");
        connect(Plugin->ui->pushButton, &QPushButton::clicked,      this,&ChatShareDialog::Refreshsharedfiles);
        SuperC->Addaction(Plugin->Itemoptions,Plugin->Downloadfile,"Download file","Download file");
        SuperC->Addaction(Plugin->Itemoptions,Plugin->Downloadfileas,"Download file as","Download file as");
        SuperC->Addaction(Plugin->Itemoptions,Plugin->Openpath,"Open path","Open path");
    }
}

/*  change button's function by user name;*/

void ChatShareDialog::Openitemoptions()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Plugin->Itemoptions->exec(QCursor::pos());
    }
}

/*  exec menu;*/

void ChatShareDialog::Selectsharedfiles()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{});
    connect(filedialog,&SuperFileDialog::Signalfc,this,         &ChatShareDialog::Addsharedfiles);
    connect(filedialog,&SuperFileDialog::Signalfc,filedialog,   &QObject::deleteLater);
    filedialog->Show();
}

/*  select shared files;*/

void ChatShareDialog::Addsharedfiles(QStringList fileslist)
{
    for(int i = 0;i < fileslist.count();i++)
    {
        QString file = fileslist.at(i);
        if(!Fileslist.contains(file))
        {
            QFileInfo fileinfo(file);
            Fileslist.append(file);
            SuperC->Getfileinfolist(file,&Fileinfotemp);
            QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget,Fileinfotemp);
            item->setIcon(0,Iconprovider.icon(fileinfo));
            Plugin->ui->treeWidget->addTopLevelItem(item);
            Plugin->ui->treeWidget->header()->setStretchLastSection(false);
        }
    }
    Writetolocal();
}

/*  open file dialog and select file or files;*/

void ChatShareDialog::Appendtolocal(QStringList *fileinfo)
{
    for(int i = 0;i < fileinfo->count();i++)
    {
        if(fileinfo->count() - 1 != i)
        {
            SuperC->Appendfile(Sharedfilepath,fileinfo->at(i) + "<split>");
        }
        else
        {
            SuperC->Appendfile(Sharedfilepath,fileinfo->at(i));
            SuperC->Appendfile(Sharedfilepath,"\r\n");
        }
    }
}

/*  add split char by fileinfo position,include <split>,"\r\n";*/

void ChatShareDialog::Refreshsharedfiles()
{
    Fileslist.clear();
    Plugin->ui->treeWidget->clear();
    Threadga->start();
    emit Signalca(-2,Sharedfolder);
}

/*  refresh shared files;*/

void ChatShareDialog::Refreshsharedfilesslot(QStringList fileinfotemp)
{
    QFileInfo fileinfo(fileinfotemp.at(0) + fileinfotemp.at(1));
    QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget,fileinfotemp);
    item->setIcon(0,Iconprovider.icon(fileinfo));
    Plugin->ui->treeWidget->addTopLevelItem(item);
}

/*  refresh shared files slot;*/

void ChatShareDialog::Cancelsharedfiles()
{
    Fileslist.remove(Plugin->ui->treeWidget->currentIndex().row());
    delete Plugin->ui->treeWidget->currentItem();
    Writetolocal();
}

/*  cancel shared file;*/

void ChatShareDialog::Writetolocal()
{
    if(Lineedit->text() == Localuser)
    {
        SuperC->Writeonlyfile(Sharedfilepath,"");
        for(int i = 0;i < Fileslist.count();i++)
        {
            SuperC->Getfileinfolist(Fileslist.at(i),&Fileinfotemp);
            Appendtolocal(&Fileinfotemp);
        }
    }
}

/*  clear sharedfile,append treewidget info to sharedfile;*/

void ChatShareDialog::Downloadfiles()
{
    QString path = Plugin->ui->treeWidget->currentItem()->text(0);
    if(path == "unavailable")
    {
        path = Sharedfolder;
    }
    emit Signalca(Plugin->ui->treeWidget->currentIndex().row(),path);
}

/*  emit file index for download file;*/

void ChatShareDialog::Selectdownloadpath()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &ChatShareDialog::Downloadfilesas);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsavefolder();
    filedialog->Show();
}

/*  select download path;*/

void ChatShareDialog::Downloadfilesas(QString folder)
{
    if(!folder.isEmpty())
    {
        emit Signalca(Plugin->ui->treeWidget->currentIndex().row(),folder);
    }
}

/*  emit file index and path for download file;*/

void ChatShareDialog::Opencontactfolder()
{
    QString filepath = Plugin->ui->treeWidget->currentItem()->text(0);
    QString filename = Plugin->ui->treeWidget->currentItem()->text(1);
    QString filesize = Plugin->ui->treeWidget->currentItem()->text(2);
    if(filesize == "unavailable")
    {
        SuperC->Openpath(Sharedfolder);
    }
    else
    {
        SuperC->Openpath(filepath.split(filename).at(0));
    }
}

/*  open current file path;*/

GetFileInfoThread::GetFileInfoThread(QString sharedfilepath,int columncount,QString shared,QString user,QStringList *fileslist,QString sharedfolder)
{
    Sharedfilepath = sharedfilepath;
    Columncount = columncount;
    Shared = shared;
    User = user;
    Fileslist = fileslist;
    Sharedfolder = sharedfolder;
    Init();
}

GetFileInfoThread::~GetFileInfoThread()
{
    delete SuperC;
}

void GetFileInfoThread::Init()
{
    Objectinit();
}

void GetFileInfoThread::Objectinit()
{
    SuperC = new SuperCore();
}

void GetFileInfoThread::run()
{
    QString sharedfilesinfo = SuperC->Readonlyfile(Sharedfilepath);
    QStringList sharedfileslist = sharedfilesinfo.split("\r\n");
    for(int i = 0;i < sharedfileslist.count();i++)
    {
        QStringList fileinfolist = sharedfileslist.at(i).split("<split>");
        if(fileinfolist.count() == Columncount)
        {
            QString filename;
            QStringList fileinfotemp;
            if(Shared == User)
            {
                filename = SuperC->Fixfilepath(fileinfolist.at(0)) + fileinfolist.at(1);
                SuperC->Getfileinfolist(filename,&fileinfotemp);
                Fileslist->append(filename);
            }
            else
            {
                filename = Sharedfolder + fileinfolist.at(1);
                SuperC->Getfileinfolist(filename,&fileinfotemp);
            }
            emit Signalga(fileinfotemp);
        }
    }
}

/*  get file info by shared file, and emit fileinfo list;*/
