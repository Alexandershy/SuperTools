#include "_superfiledialog_.h"
#include "ui__superfiledialogui_.h"

SuperFileDialog::SuperFileDialog(QWidget *parent,QString folderpath,QStringList filterlist)
    :SuperWindow(parent)
{
    Foldersourcepath = folderpath;
    Filterlist = filterlist;
    disableMaxisize();
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    setTitle("SuperFileDialog");
    init();
}

SuperFileDialog::~SuperFileDialog()
{
    delete Dir;
}

void SuperFileDialog::init()
{
    objectInit();
    dirInit();
    systemModelInit();
    menuInit();
    iconInit();
    locationPathInit();
    quickAccessInit();
}

void SuperFileDialog::objectInit()
{
    Plugin = new SuperFileDialogui(this);
    Pluginlayout->addWidget(Plugin);
    Plugin->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    Plugin->ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    Plugin->ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    Plugin->ui->tableWidget->verticalHeader()->setHidden(true);
    Plugin->ui->comboBox_3->addItems(Filterlist);
    Plugin->ui->lineEdit->setFocus();
    connect(Plugin->ui->treeView,       &QTreeView::clicked,                this,&SuperFileDialog::transferModelIndex);
    connect(Plugin->ui->treeWidget,     &QTreeWidget::clicked,              this,&SuperFileDialog::refreshQuickAccessFolder);
    connect(Plugin->ui->treeWidget,     &QTreeWidget::pressed,              this,&SuperFileDialog::execTreeMenu);
    connect(Plugin->ui->comboBox,       &QComboBox::textActivated,          this,&SuperFileDialog::refreshFolder);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::getFileList);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemPressed,         this,&SuperFileDialog::execFileMenu);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemSelectionChanged,this,&SuperFileDialog::enableSelectFileButton);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::getFileList);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,              this,&SuperFileDialog::checkFolder);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,              this,&SuperFileDialog::close);
    connect(Plugin->ui->pushButton_4,   &QPushButton::clicked,              this,&SuperFileDialog::cdUpFolder);
    connect(Plugin->ui->pushButton_5,   &QPushButton::clicked,              this,&SuperFileDialog::creatNewFolder);
    connect(Plugin->ui->pushButton_6,   &QPushButton::clicked,              this,&SuperFileDialog::addToQuickAccess);
    connect(Plugin->ui->pushButton_7,   &QPushButton::clicked,              this,&SuperFileDialog::changeFileIconMode);
    connect(Plugin->ui->lineEdit,       &QLineEdit::textChanged,            this,&SuperFileDialog::searchFile);
}

/*  creat object and connect its slot;*/

void SuperFileDialog::dirInit()
{
    Dir = new QDir(Foldersourcepath);
    if(!Dir->exists())
    {
        Dir->setPath(QDir::currentPath());
    }
}

/*  check parameter correctly;*/

void SuperFileDialog::systemModelInit()
{
    Filesystemmodel = new SuperFileSystemModel(this);
    Plugin->ui->treeView->setModel(Filesystemmodel);
    Plugin->ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    expandModelFolder(Dir);
    for(int i = 1;i < Filesystemmodel->columnCount();i++)
    {
        Plugin->ui->treeView->hideColumn(i);
    }
}

/*  tree system model init;*/

void SuperFileDialog::menuInit()
{
    Filemenu = new QMenu(this);
    Selectfile = new QAction(Filemenu);
    Openfile = new QAction(Filemenu);
    Openpath = new QAction(Filemenu);
    Deletefile = new QAction(Filemenu);
    connect(Selectfile, &QAction::triggered,this,&SuperFileDialog::getFileList);
    connect(Openfile,   &QAction::triggered,this,&SuperFileDialog::openFiles);
    connect(Openpath,   &QAction::triggered,this,&SuperFileDialog::openPaths);
    connect(Deletefile, &QAction::triggered,this,&SuperFileDialog::deleteitem);
    Core->addAction(Filemenu,Selectfile,"select file","Selectfile");
    Core->addAction(Filemenu,Openfile,"open file","Openfile");
    Core->addAction(Filemenu,Openpath,"open path","Openpath");
    Core->addAction(Filemenu,Deletefile,"delete file","Deletefile");
    Selectfile->setIcon(QIcon(":/__supericon__/_open_.svg"));
    Openfile->setIcon(QIcon(":/__supericon__/_edit_.svg"));
    Openpath->setIcon(QIcon(":/__supericon__/_openpath_.svg"));
    Deletefile->setIcon(QIcon(":/__supericon__/_delete_.svg"));
    Treemenu = new QMenu(this);
    Openfolder = new QAction(Treemenu);
    Unpin = new QAction(Treemenu);
    connect(Openfolder, &QAction::triggered,this,&SuperFileDialog::refreshQuickAccessFolder);
    connect(Unpin,      &QAction::triggered,this,&SuperFileDialog::deleteQuickAccess);
    Core->addAction(Treemenu,Openfolder,"Open folder","Openfolder");
    Core->addAction(Treemenu,Unpin,"Unpin folder","Unpinfolder");
    Openfolder->setIcon(QIcon(":/__supericon__/_open_.svg"));
    Unpin->setIcon(QIcon(":/__supericon__/_unlock_.svg"));
}

/*  menu init;*/

void SuperFileDialog::iconInit()
{
    Plugin->ui->pushButton->setIcon(QIcon(":/__supericon__/_reset_.svg"));
    Plugin->ui->pushButton_4->setIcon(QIcon(":/__supericon__/_backward_.svg"));
    Plugin->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_newfolder_.svg"));
    Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_lock_.svg"));
    Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_picture_.svg"));
    Plugin->ui->comboBox->addItem(Dir->absolutePath());
    refreshFolder(Dir->absolutePath());
}

/*  set widget icon;*/

void SuperFileDialog::locationPathInit()
{
    QStringList locationpathlist = Core->readOnlyFile(Locationpath).split("<split>");
    for(int i = 0;i < locationpathlist.count();i++)
    {
        QFileInfo fileinfo(locationpathlist.at(i));
        if(fileinfo.isDir())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget);
            item->setText(0,fileinfo.fileName());
            item->setText(1,fileinfo.absoluteFilePath());
            item->setIcon(0,Iconprovider.icon(fileinfo));
            Plugin->ui->treeWidget->addTopLevelItem(item);
            Quickaccesscounts = i;
        }
    }
}

/*  add location path;*/

void SuperFileDialog::quickAccessInit()
{
    treeWidgetAddItemApi(QStandardPaths::DesktopLocation);
    treeWidgetAddItemApi(QStandardPaths::DocumentsLocation);
    treeWidgetAddItemApi(QStandardPaths::MusicLocation);
    treeWidgetAddItemApi(QStandardPaths::PicturesLocation);
    treeWidgetAddItemApi(QStandardPaths::DownloadLocation);
    treeWidgetAddItemApi(QStandardPaths::MoviesLocation);
}

/*  add quick access path;*/

void SuperFileDialog::treeWidgetAddItemApi(QStandardPaths::StandardLocation path)
{
    QStringList locationpathlist = Core->readOnlyFile(Locationpath).split("<split>");
    QStringList locationpath = QStandardPaths::standardLocations(path);
    for(int i = 0;i < locationpath.count();i++)
    {
        QFileInfo fileinfo(locationpath.at(i));
        if(!locationpathlist.contains(fileinfo.absoluteFilePath()))
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget);
            item->setText(0,fileinfo.fileName());
            item->setText(1,fileinfo.absoluteFilePath());
            item->setIcon(0,Iconprovider.icon(fileinfo));
            Plugin->ui->treeWidget->addTopLevelItem(item);
            Core->appendFile(Locationpath,fileinfo.absoluteFilePath() + "<split>");
        }
    }
}

/*  add path api;*/

void SuperFileDialog::transferModelIndex(QModelIndex index)
{
    QString filepath = Filesystemmodel->filePath(index);
    Plugin->ui->comboBox->insertItem(0,filepath);
    Plugin->ui->comboBox->setCurrentIndex(0);
    refreshFolder(filepath);
}

/*  transfer model index to string path;*/

void SuperFileDialog::checkFolder()
{
    refreshFolder(Plugin->ui->comboBox->currentText());
}

/*  refresh folder no parameter;*/

void SuperFileDialog::refreshQuickAccessFolder()
{
    QString pathtemp = Plugin->ui->treeWidget->currentItem()->text(1);
    Plugin->ui->comboBox->insertItem(0,pathtemp);
    Plugin->ui->comboBox->setCurrentIndex(0);
    refreshFolder(pathtemp);
}

/*  refresh quick access folder;*/

void SuperFileDialog::refreshFolder(QString folderpath)
{
    Dir->setPath(folderpath);
    if(Dir->exists())
    {
        Allfileinfolist.clear();
        Folderinfolist = Dir->entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
        Fileinfolist = Dir->entryInfoList(Filterlist,QDir::Files | QDir::NoDotAndDotDot);
        Allfileinfolist.append(Folderinfolist);
        Allfileinfolist.append(Fileinfolist);
        Rowcounts = Folderinfolist.count() + Fileinfolist.count();
        Core->setTableWidgetItem(Rowcounts,Columncounts,Fileiconmode,Plugin->ui->tableWidget);
        switch (Fileiconmode)
        {
            case 32:
            {
                fileInfoMode();
                break;
            }
            case 48:
            {
                filePictureMode();
                break;
            }
        }
    }
    else
    {
        Dir->setPath(QDir::currentPath());
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,folderpath + " is not exist;");
        notedialog->messageInit();
    }
}

/*  refresh current folders' files;*/

void SuperFileDialog::fileInfoMode()
{
    Plugin->ui->tableWidget->setHorizontalHeaderLabels(Fileinfoheader);
    for(int i = 0;i < Folderinfolist.count();i++)
    {
        Plugin->ui->tableWidget->item(i,0)->setIcon(Iconprovider.icon(QFileIconProvider::Folder));
        Plugin->ui->tableWidget->item(i,0)->setText(Folderinfolist.at(i).fileName());
        Plugin->ui->tableWidget->item(i,3)->setText("folder");
    }
    for(int i = Folderinfolist.count();i < Rowcounts;i++)
    {
        QFileInfo fileinfotemp = Allfileinfolist.at(i);
        Plugin->ui->tableWidget->item(i,0)->setIcon(Iconprovider.icon(fileinfotemp));
        Plugin->ui->tableWidget->item(i,0)->setText(fileinfotemp.fileName());
        Plugin->ui->tableWidget->item(i,1)->setText(QString::number(fileinfotemp.size()) + " bits");
        Plugin->ui->tableWidget->item(i,2)->setText(fileinfotemp.birthTime().toString("yyyy/MM/dd") + " " + fileinfotemp.birthTime().toString("hh:mm:ss"));
        Plugin->ui->tableWidget->item(i,3)->setText("file");
    }
}

/*  add file as info mode;*/

void SuperFileDialog::filePictureMode()
{
    Plugin->ui->tableWidget->setHorizontalHeaderLabels(Filepictureheader);
    int versize = Plugin->ui->tableWidget->verticalHeader()->minimumSectionSize();
    int horsize = Plugin->ui->tableWidget->horizontalHeader()->minimumSectionSize();
    for(int i = 0;i < Folderinfolist.count();i++)
    {
        QIcon icon(Iconprovider.icon(QFileIconProvider::Folder));
        QLabel *label = new QLabel(Plugin->ui->tableWidget);
        QPixmap pixmap(icon.pixmap(Fileiconmode,Fileiconmode));
        label->setPixmap(pixmap.scaled(versize,horsize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        Plugin->ui->tableWidget->setCellWidget(i,0,label);
        Plugin->ui->tableWidget->item(i,1)->setText(Folderinfolist.at(i).fileName());
        Plugin->ui->tableWidget->item(i,3)->setText("folder");
    }
    for(int i = Folderinfolist.count();i < Rowcounts;i++)
    {
        QPixmap pixmap;
        QFileInfo fileinfotemp = Allfileinfolist.at(i);
        QLabel *label = new QLabel(Plugin->ui->tableWidget);
        if(pixmap.convertFromImage(QImage(fileinfotemp.absoluteFilePath())))
        {
            label->setPixmap(pixmap.scaled(versize,horsize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else
        {
            QIcon icon(Iconprovider.icon(fileinfotemp));
            pixmap = icon.pixmap(Fileiconmode,Fileiconmode);
            label->setPixmap(pixmap.scaled(versize,horsize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        Plugin->ui->tableWidget->setCellWidget(i,0,label);
        Plugin->ui->tableWidget->item(i,1)->setText(fileinfotemp.fileName());
        Plugin->ui->tableWidget->item(i,2)->setText(QString::number(fileinfotemp.size()) + " bits");
        Plugin->ui->tableWidget->item(i,3)->setText("file");
    }
}

/*  add file as picture mode;*/

void SuperFileDialog::setSingleFile()
{
    Dialogmode = 1;
    Plugin->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::getFileList);
    disconnect(Plugin->ui->pushButton_2,&QPushButton::clicked,              this,&SuperFileDialog::getFileList);
    disconnect(Selectfile,              &QAction::triggered,                this,&SuperFileDialog::getFileList);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::getFile);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::getFile);
    connect(Selectfile,                 &QAction::triggered,                this,&SuperFileDialog::getFile);
}

/*  set table select mode as single;*/

void SuperFileDialog::setSaveFile()
{
    Dialogmode = 2;
    Plugin->ui->comboBox_2->setEnabled(true);
    Plugin->ui->comboBox_3->setEnabled(true);
    Plugin->ui->comboBox_2->setFocus();
    Plugin->ui->pushButton_2->setText("Save");
    Plugin->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemSelectionChanged,this,&SuperFileDialog::enableSelectFileButton);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::getFileList);
    disconnect(Plugin->ui->pushButton_2,&QPushButton::clicked,              this,&SuperFileDialog::getFileList);
    disconnect(Selectfile,              &QAction::triggered,                this,&SuperFileDialog::getFileList);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::getFileSaveMode);
    connect(Selectfile,                 &QAction::triggered,                this,&SuperFileDialog::getFileSaveMode);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::saveFile);
    connect(Plugin->ui->comboBox_2,     &QComboBox::currentTextChanged,     this,&SuperFileDialog::enableSaveFileButton);
}

/*  set save file mode;*/

void SuperFileDialog::setSaveFolder()
{
    Dialogmode = 3;
    Plugin->ui->pushButton_2->setEnabled(true);
    Plugin->ui->pushButton_2->setText("Current Folder");
    Plugin->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemSelectionChanged,this,&SuperFileDialog::enableSelectFileButton);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::getFileList);
    disconnect(Plugin->ui->pushButton_2,&QPushButton::clicked,              this,&SuperFileDialog::getFileList);
    disconnect(Selectfile,              &QAction::triggered,                this,&SuperFileDialog::getFileList);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::getFolderSaveMode);
    connect(Selectfile,                 &QAction::triggered,                this,&SuperFileDialog::getFolderSaveMode);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::saveFolder);
    connect(Plugin->ui->comboBox_2,     &QComboBox::currentTextChanged,     this,&SuperFileDialog::enableSaveFileButton);
}

/*  set save folder mode;*/

void SuperFileDialog::getFile()
{
    QList<QTableWidgetItem*> itemlist = Plugin->ui->tableWidget->selectedItems();
    int currentrow = itemlist.at(0)->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        QString filetemp = Allfileinfolist.at(currentrow).absoluteFilePath();
        emit signalFb(filetemp);
    }
    else
    {
        Plugin->ui->comboBox->insertItem(0,Allfileinfolist.at(currentrow).absoluteFilePath());
        Plugin->ui->comboBox->setCurrentIndex(0);
        refreshFolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get single file;*/

void SuperFileDialog::getFileSaveMode()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        saveFile();
    }
    else
    {
        Plugin->ui->comboBox->insertItem(0,Allfileinfolist.at(currentrow).absoluteFilePath());
        Plugin->ui->comboBox->setCurrentIndex(0);
        refreshFolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get single file;*/

void SuperFileDialog::saveFile()
{
    QString filesuffixtemp = Plugin->ui->comboBox_3->currentText().split("*").at(1);
    QString filenametemp = Plugin->ui->comboBox_2->currentText().split(filesuffixtemp).at(0);
    QString file = Core->fixFilePath(Dir->absolutePath()) + filenametemp + filesuffixtemp;
    if(checkRepeatFile(filenametemp,filesuffixtemp))
    {
        emit signalFb(file);
    }
}

/*  save single file;*/

void SuperFileDialog::getFolderSaveMode()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        saveFolder();
    }
    else
    {
        Plugin->ui->comboBox->insertItem(0,Allfileinfolist.at(currentrow).absoluteFilePath());
        Plugin->ui->comboBox->setCurrentIndex(0);
        refreshFolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get single folder;*/

void SuperFileDialog::saveFolder()
{
    emit signalFb(Core->fixFilePath(Dir->absolutePath()));
}

/*  save single folder;*/

bool SuperFileDialog::checkRepeatFile(QString filename,QString filesuffix)
{
    for(int i = 0;i < Allfileinfolist.count();i++)
    {
        if(Allfileinfolist.at(i).completeBaseName() == filename && "." + Allfileinfolist.at(i).suffix() == filesuffix)
        {
            Currentfileindex = i;
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"replace with " + filename + filesuffix + " ?");
            connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileDialog::replaceFile);
            notedialog->messageInit();
            return false;
        }
    }
    return true;
}

/*  check current folder repeat files;*/

void SuperFileDialog::getFileList()
{
    QStringList filestringlisttemp;
    QStringList folderstringlisttemp;
    QFileInfoList fileinfolistemp;
    QFileInfoList folderinfolistemp;
    QList<QTableWidgetItem*> itemlist = Plugin->ui->tableWidget->selectedItems();
    for(int i = 0;i < itemlist.count();i++)
    {
        int rowtemp = itemlist.at(i)->row();
        if(Allfileinfolist.at(rowtemp).isFile())
        {
            if(!fileinfolistemp.contains(Allfileinfolist.at(rowtemp)))
            {
                fileinfolistemp.append(Allfileinfolist.at(rowtemp));
                filestringlisttemp.append(Allfileinfolist.at(rowtemp).absoluteFilePath());
            }
        }
        else if(Allfileinfolist.at(rowtemp).isDir())
        {
            if(!folderinfolistemp.contains(Allfileinfolist.at(rowtemp)))
            {
                folderinfolistemp.append(Allfileinfolist.at(rowtemp));
                folderstringlisttemp.append(Allfileinfolist.at(rowtemp).absoluteFilePath());
            }
        }
    }
    if(!fileinfolistemp.isEmpty())
    {
        emit signalFc(filestringlisttemp);
    }
    else if(!folderstringlisttemp.isEmpty())
    {
        Plugin->ui->comboBox->insertItem(0,folderstringlisttemp.at(0));
        Plugin->ui->comboBox->setCurrentIndex(0);
        refreshFolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get file list;*/

void SuperFileDialog::enableSelectFileButton()
{
    if(Plugin->ui->tableWidget->selectedItems().isEmpty())
    {
        Plugin->ui->pushButton_2->setEnabled(false);
    }
    else
    {
        Plugin->ui->pushButton_2->setEnabled(true);
    }
}

/*  enable open button or not;*/

void SuperFileDialog::enableSaveFileButton()
{
    if(Plugin->ui->comboBox_2->currentText().isEmpty())
    {
        Plugin->ui->pushButton_2->setEnabled(false);
    }
    else
    {
        Plugin->ui->pushButton_2->setEnabled(true);
    }
}

/*  enable open button or not;*/

void SuperFileDialog::cdUpFolder()
{
    Dir->cdUp();
    Plugin->ui->comboBox->insertItem(0,Dir->absolutePath());
    Plugin->ui->comboBox->setCurrentIndex(0);
    refreshFolder(Dir->absolutePath());
}

/*  cd up folder;*/

void SuperFileDialog::execFileMenu()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        Selectfile->setText(Filemenutext.at(Dialogmode).at(0));
        Openfile->setText(Filemenutext.at(Dialogmode).at(1));
        Openpath->setText(Filemenutext.at(Dialogmode).at(2));
        Deletefile->setText(Filemenutext.at(Dialogmode).at(3));
        Openfile->setEnabled(true);
        Plugin->ui->comboBox_2->insertItem(0,Allfileinfolist.at(currentrow).fileName());
        Plugin->ui->comboBox_2->setCurrentIndex(0);
    }
    else
    {
        Selectfile->setText(Foldermenutext.at(Dialogmode).at(0));
        Openfile->setText(Foldermenutext.at(Dialogmode).at(1));
        Openpath->setText(Foldermenutext.at(Dialogmode).at(2));
        Deletefile->setText(Foldermenutext.at(Dialogmode).at(3));
        Openfile->setEnabled(false);
    }
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Filemenu->exec(QCursor::pos());
    }
}

/*  exec filemenu;*/

void SuperFileDialog::execTreeMenu()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Treemenu->exec(QCursor::pos());
    }
}

/*  exec treemenu;*/

void SuperFileDialog::openFiles()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    QString filepath = Allfileinfolist.at(currentrow).absoluteFilePath();
    QString filename = Allfileinfolist.at(currentrow).fileName();
    bool boola = QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));
    if(!boola)
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"open " + filename + " failed;/nclick ok open path;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileDialog::openPaths);
        notedialog->messageInit();
    }
}

/*  exec filemenu;*/

void SuperFileDialog::openPaths()
{
    Core->openPath(Dir->absolutePath());
}

/*  exec filemenu;*/

void SuperFileDialog::replaceFile()
{
    QString file = Allfileinfolist.at(Currentfileindex).absoluteFilePath();
    bool boola = QFile::remove(file);
    if(boola)
    {
        emit signalFb(file);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"replace file failed;\nclick ok open path;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileDialog::openPaths);
        notedialog->messageInit();
    }
}

/*  replace file;*/

void SuperFileDialog::creatNewFolder()
{
    int i = 0;
    bool boola = Dir->mkdir("New folder");
    while (boola == false)
    {
        i = i + 1;
        boola = Dir->mkdir("New folder " + QString::number(i));
    }
    refreshFolder(Dir->absolutePath());
}

/*  creat new folder;*/

void SuperFileDialog::deleteitem()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        bool boola = QFile::remove(Allfileinfolist.at(currentrow).absoluteFilePath());
        if(boola)
        {
            refreshFolder(Plugin->ui->comboBox->currentText());
        }
        else
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"delete file failed;\nclick ok open path;");
            connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileDialog::openPaths);
            notedialog->messageInit();
        }
    }
    else if(Allfileinfolist.at(currentrow).isDir())
    {
        QDir dir(Allfileinfolist.at(currentrow).absoluteFilePath());
        bool boola = dir.removeRecursively();
        if(boola)
        {
            refreshFolder(Plugin->ui->comboBox->currentText());
        }
        else
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"delete folder failed;\nclick ok open path;");
            connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileDialog::openPaths);
            notedialog->messageInit();
        }
    }
}

/*  delete file or folder;*/

void SuperFileDialog::searchFile(QString text)
{
    if(text.isEmpty())
    {
        for(int i = 0;i < Plugin->ui->tableWidget->rowCount();i++)
        {
            for(int j = 0;j < Plugin->ui->tableWidget->columnCount();j++)
            {
                Plugin->ui->tableWidget->item(i,j)->setSelected(false);
            }
        }
    }
    else
    {
        for(int i = 0;i < Plugin->ui->tableWidget->rowCount();i++)
        {
            for(int j = 0;j < Plugin->ui->tableWidget->columnCount();j++)
            {
                QTableWidgetItem *item = Plugin->ui->tableWidget->item(i,j);
                if(item->text().contains(text,Qt::CaseInsensitive))
                {
                    item->setSelected(true);
                    Plugin->ui->tableWidget->setCurrentCell(i,j,QItemSelectionModel::Rows);
                }
                else
                {
                    item->setSelected(false);
                }
            }
        }
    }
}

/*  search file or folder;*/

void SuperFileDialog::addToQuickAccess()
{
    QFileInfo fileinfo(Dir->path());
    QStringList locationpathlist = Core->readOnlyFile(Locationpath).split("<split>");
    if(!locationpathlist.contains(fileinfo.absoluteFilePath()))
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget);
        item->setText(0,fileinfo.fileName());
        item->setText(1,fileinfo.absoluteFilePath());
        item->setIcon(0,Iconprovider.icon(fileinfo));
        Plugin->ui->treeWidget->addTopLevelItem(item);
        Core->appendFile(Locationpath,fileinfo.absoluteFilePath() + "<split>");
    }
}

/*  add current folder path to quick access;*/

void SuperFileDialog::changeFileIconMode()
{
    if(Fileiconmode == 32)
    {
        Fileiconmode = 48;
        Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_info_.svg"));
    }
    else
    {
        Fileiconmode = 32;
        Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_picture_.svg"));
    }
    checkFolder();
}

/*  change file icon mode;*/

void SuperFileDialog::deleteQuickAccess()
{
    delete Plugin->ui->treeWidget->currentItem();
    Core->writeOnlyFile(Locationpath,"");
    for(int i = 0;i < Plugin->ui->treeWidget->topLevelItemCount();i++)
    {
        Core->appendFile(Locationpath,Plugin->ui->treeWidget->topLevelItem(i)->text(1) + "<split>");
    }
}

/*  remove current folder path from quick access;*/

void SuperFileDialog::expandModelFolder(QDir *dir)
{
    QStringList absolutefilepathlist = {};
    QDir newdir(dir->absolutePath());
    for(int i = 0;newdir.cdUp();i++)
    {
        absolutefilepathlist.insert(0,Core->fixFilePath(newdir.absolutePath()));
    }
    absolutefilepathlist.append(Core->fixFilePath(dir->absolutePath()));
    for(int i = 0;i < absolutefilepathlist.count();i++)
    {
        Plugin->ui->treeView->expand(Filesystemmodel->index(absolutefilepathlist.at(i)));
    }
    Plugin->ui->treeView->setCurrentIndex(Filesystemmodel->index(Core->getListLastMember(&absolutefilepathlist)));
}

/*  expand current folder path by treeview;*/
