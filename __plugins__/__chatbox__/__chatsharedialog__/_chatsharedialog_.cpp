#include "_chatsharedialog_.h"

ChatShareDialog::ChatShareDialog(QWidget *parent,QLineEdit *lineedit)
    : SuperWindow(parent)
{
    Lineedit = lineedit;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    setTitle(Lineedit->text() + "'s file shared");
    init();
}

ChatShareDialog::~ChatShareDialog()
{
    Core->closeThread(Threadga);
}

void ChatShareDialog::init()
{
    objectInit();
    checkUserInit();
    refreshSharedFiles();
}

void ChatShareDialog::objectInit()
{
    Localuser = QDir::home().dirName() + " " + QHostInfo::localHostName();
    Sharedfolder = "./__depycache__/__chat__/__" + Lineedit->text() + "__/";
    Targetpath = Sharedfolder + "_targetpath_.txt";
    Sharedfilepath = Sharedfolder + "_filesshared_.txt";
    Core->creatFile(Sharedfilepath);
    Plugin = new ChatShareDialogui(this);
    Threadga = new GetFileInfoThread(Sharedfilepath,Plugin->ui->treeWidget->columnCount(),Lineedit->text(),Localuser,&Fileslist,Sharedfolder);
    Pluginlayout->addWidget(Plugin);
    Plugin->ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->treeWidget->header()->setStretchLastSection(false);
    connect(Plugin->Cancelshared,   &QAction::triggered,            this,&ChatShareDialog::cancelSharedFiles);
    connect(Plugin->Downloadfile,   &QAction::triggered,            this,&ChatShareDialog::downloadFiles);
    connect(Plugin->Downloadfileas, &QAction::triggered,            this,&ChatShareDialog::selectDownloadPath);
    connect(Plugin->Openpath,       &QAction::triggered,            this,&ChatShareDialog::openContactFolder);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemPressed,      this,&ChatShareDialog::openItemOptions);
    connect(Threadga,               &GetFileInfoThread::signalGa,   this,&ChatShareDialog::refreshSharedFilesSlot);
    connect(Threadga,               &GetFileInfoThread::finished,   this,&ChatShareDialog::writeToLocal);
}

/*  creat plugin box,thread and connect its slot;*/

void ChatShareDialog::checkUserInit()
{
    if(Lineedit->text() == Localuser)
    {
        connect(Plugin->ui->pushButton, &QPushButton::clicked,this,&ChatShareDialog::selectSharedFiles);
        Core->addAction(Plugin->Itemoptions,Plugin->Cancelshared,"Cancel Shared","Cancel Shared");
        Core->addAction(Plugin->Itemoptions,Plugin->Openpath,"Open path","Open path");
    }
    else
    {
        Plugin->ui->pushButton->setText("Refresh Files");
        connect(Plugin->ui->pushButton, &QPushButton::clicked,      this,&ChatShareDialog::refreshSharedFiles);
        Core->addAction(Plugin->Itemoptions,Plugin->Downloadfile,"Download file","Download file");
        Core->addAction(Plugin->Itemoptions,Plugin->Downloadfileas,"Download file as","Download file as");
        Core->addAction(Plugin->Itemoptions,Plugin->Openpath,"Open path","Open path");
    }
}

/*  change button's function by user name;*/

void ChatShareDialog::openItemOptions()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Plugin->Itemoptions->exec(QCursor::pos());
    }
}

/*  exec menu;*/

void ChatShareDialog::selectSharedFiles()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{});
    connect(filedialog,&SuperFileDialog::signalFc,this,         &ChatShareDialog::addSharedFiles);
    connect(filedialog,&SuperFileDialog::signalFc,filedialog,   &QObject::deleteLater);
    filedialog->show();
}

/*  select shared files;*/

void ChatShareDialog::addSharedFiles(QStringList fileslist)
{
    for(int i = 0;i < fileslist.count();i++)
    {
        QString file = fileslist.at(i);
        if(!Fileslist.contains(file))
        {
            QFileInfo fileinfo(file);
            Fileslist.append(file);
            Core->getFileInfoList(file,&Fileinfotemp);
            QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget,Fileinfotemp);
            item->setIcon(0,Iconprovider.icon(fileinfo));
            Plugin->ui->treeWidget->addTopLevelItem(item);
            Plugin->ui->treeWidget->header()->setStretchLastSection(false);
        }
    }
    writeToLocal();
}

/*  open file dialog and select file or files;*/

void ChatShareDialog::appendToLocal(QStringList *fileinfo)
{
    for(int i = 0;i < fileinfo->count();i++)
    {
        if(fileinfo->count() - 1 != i)
        {
            Core->appendFile(Sharedfilepath,fileinfo->at(i) + "<split>");
        }
        else
        {
            Core->appendFile(Sharedfilepath,fileinfo->at(i));
            Core->appendFile(Sharedfilepath,"\r\n");
        }
    }
}

/*  add split char by fileinfo position,include <split>,"\r\n";*/

void ChatShareDialog::refreshSharedFiles()
{
    Fileslist.clear();
    Plugin->ui->treeWidget->clear();
    Threadga->start();
    emit signalCa(-2,Sharedfolder);
}

/*  refresh shared files;*/

void ChatShareDialog::refreshSharedFilesSlot(QStringList fileinfotemp)
{
    QFileInfo fileinfo(fileinfotemp.at(0) + fileinfotemp.at(1));
    QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget,fileinfotemp);
    item->setIcon(0,Iconprovider.icon(fileinfo));
    Plugin->ui->treeWidget->addTopLevelItem(item);
}

/*  refresh shared files slot;*/

void ChatShareDialog::cancelSharedFiles()
{
    Fileslist.remove(Plugin->ui->treeWidget->currentIndex().row());
    delete Plugin->ui->treeWidget->currentItem();
    writeToLocal();
}

/*  cancel shared file;*/

void ChatShareDialog::writeToLocal()
{
    if(Lineedit->text() == Localuser)
    {
        Core->writeOnlyFile(Sharedfilepath,"");
        for(int i = 0;i < Fileslist.count();i++)
        {
            Core->getFileInfoList(Fileslist.at(i),&Fileinfotemp);
            appendToLocal(&Fileinfotemp);
        }
    }
}

/*  clear sharedfile,append treewidget info to sharedfile;*/

void ChatShareDialog::downloadFiles()
{
    QString path = Plugin->ui->treeWidget->currentItem()->text(0);
    if(path == "unavailable")
    {
        path = Sharedfolder;
    }
    emit signalCa(Plugin->ui->treeWidget->currentIndex().row(),path);
}

/*  emit file index for download file;*/

void ChatShareDialog::selectDownloadPath()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{});
    connect(filedialog,&SuperFileDialog::signalFb,this,         &ChatShareDialog::downloadFiles);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
    filedialog->setSaveFolder();
    filedialog->show();
}

/*  select download path;*/

void ChatShareDialog::downloadFilesAs(QString folder)
{
    if(!folder.isEmpty())
    {
        emit signalCa(Plugin->ui->treeWidget->currentIndex().row(),folder);
    }
}

/*  emit file index and path for download file;*/

void ChatShareDialog::openContactFolder()
{
    QString filepath = Plugin->ui->treeWidget->currentItem()->text(0);
    QString filename = Plugin->ui->treeWidget->currentItem()->text(1);
    QString filesize = Plugin->ui->treeWidget->currentItem()->text(2);
    if(filesize == "unavailable")
    {
        Core->openPath(Sharedfolder);
    }
    else
    {
        Core->openPath(filepath.split(filename).at(0));
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
    init();
}

GetFileInfoThread::~GetFileInfoThread()
{

}

void GetFileInfoThread::init()
{
    objectInit();
}

void GetFileInfoThread::objectInit()
{
    Core = new SuperCore(this);
}

void GetFileInfoThread::run()
{
    QString sharedfilesinfo = Core->readOnlyFile(Sharedfilepath);
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
                filename = Core->fixFilePath(fileinfolist.at(0)) + fileinfolist.at(1);
                Core->getFileInfoList(filename,&fileinfotemp);
                Fileslist->append(filename);
            }
            else
            {
                filename = Sharedfolder + fileinfolist.at(1);
                Core->getFileInfoList(filename,&fileinfotemp);
            }
            emit signalGa(fileinfotemp);
        }
    }
}

/*  get file info by shared file, and emit fileinfo list;*/
