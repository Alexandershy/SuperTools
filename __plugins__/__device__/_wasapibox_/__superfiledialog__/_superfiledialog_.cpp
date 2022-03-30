#include "_superfiledialog_.h"

SuperFileDialog::SuperFileDialog(QWidget *parent,QString folderpath,QStringList filterlist)
    :SuperWindow(parent)
{
    Foldersourcepath = folderpath;
    Filterlist = filterlist;
    Disablemaxisize();
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Settitle("Super FileDialog");
    Init();
}

SuperFileDialog::~SuperFileDialog()
{
    delete Dir;
}

void SuperFileDialog::Init()
{
    Objectinit();
    Dirinit();
    Systemmodelinit();
    Menuinit();
    Iconinit();
    Locationpathinit();
    Quickaccessinit();
}

void SuperFileDialog::Objectinit()
{
    Plugin = new SuperFileBox(this);
    Pluginlayout->addWidget(Plugin);
    Plugin->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    Plugin->ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    Plugin->ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    Plugin->ui->tableWidget->verticalHeader()->setHidden(true);
    Plugin->ui->comboBox_3->addItems(Filterlist);
    Plugin->ui->lineEdit->setFocus();
    connect(Plugin->ui->treeView,       &QTreeView::clicked,                this,&SuperFileDialog::Transfermodelindex);
    connect(Plugin->ui->treeWidget,     &QTreeWidget::clicked,              this,&SuperFileDialog::Refreshquickaccessfolder);
    connect(Plugin->ui->treeWidget,     &QTreeWidget::pressed,              this,&SuperFileDialog::Exectreemenu);
    connect(Plugin->ui->comboBox,       &QComboBox::textActivated,          this,&SuperFileDialog::Refreshfolder);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::Getfilelist);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemPressed,         this,&SuperFileDialog::Execfilemenu);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemSelectionChanged,this,&SuperFileDialog::Enableselectfilebutton);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::Getfilelist);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,              this,&SuperFileDialog::Checkfolder);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,              this,&SuperFileDialog::close);
    connect(Plugin->ui->pushButton_4,   &QPushButton::clicked,              this,&SuperFileDialog::Cdupfolder);
    connect(Plugin->ui->pushButton_5,   &QPushButton::clicked,              this,&SuperFileDialog::Creatnewfolder);
    connect(Plugin->ui->pushButton_6,   &QPushButton::clicked,              this,&SuperFileDialog::Addtoquickaccess);
    connect(Plugin->ui->pushButton_7,   &QPushButton::clicked,              this,&SuperFileDialog::Changefileiconmode);
    connect(Plugin->ui->lineEdit,       &QLineEdit::textChanged,            this,&SuperFileDialog::Searchfile);
}

/*  creat object and connect its slot;*/

void SuperFileDialog::Dirinit()
{
    Dir = new QDir(Foldersourcepath);
    if(!Dir->exists())
    {
        Dir->setPath(QDir::currentPath());
    }
}

/*  check parameter correctly;*/

void SuperFileDialog::Systemmodelinit()
{
    Filesystemmodel = new SuperFileSystemModel(this);
    Plugin->ui->treeView->setModel(Filesystemmodel);
    Plugin->ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Expandmodelfolder(Dir);
    for(int i = 1;i < Filesystemmodel->columnCount();i++)
    {
        Plugin->ui->treeView->hideColumn(i);
    }
}

/*  tree system model init;*/

void SuperFileDialog::Menuinit()
{
    Filemenu = new QMenu(this);
    Selectfile = new QAction(Filemenu);
    Openfile = new QAction(Filemenu);
    Openpath = new QAction(Filemenu);
    Deletefile = new QAction(Filemenu);
    connect(Selectfile, &QAction::triggered,this,&SuperFileDialog::Getfilelist);
    connect(Openfile,   &QAction::triggered,this,&SuperFileDialog::Openfiles);
    connect(Openpath,   &QAction::triggered,this,&SuperFileDialog::Openpaths);
    connect(Deletefile, &QAction::triggered,this,&SuperFileDialog::Delete);
    SuperC->Addaction(Filemenu,Selectfile,"select file","Selectfile");
    SuperC->Addaction(Filemenu,Openfile,"open file","Openfile");
    SuperC->Addaction(Filemenu,Openpath,"open path","Openpath");
    SuperC->Addaction(Filemenu,Deletefile,"delete file","Deletefile");
    Selectfile->setIcon(QIcon(":/__supericon__/_open_.svg"));
    Openfile->setIcon(QIcon(":/__supericon__/_edit_.svg"));
    Openpath->setIcon(QIcon(":/__supericon__/_openpath_.svg"));
    Deletefile->setIcon(QIcon(":/__supericon__/_delete_.svg"));
    Treemenu = new QMenu(this);
    Openfolder = new QAction(Treemenu);
    Unpin = new QAction(Treemenu);
    connect(Openfolder, &QAction::triggered,this,&SuperFileDialog::Refreshquickaccessfolder);
    connect(Unpin,      &QAction::triggered,this,&SuperFileDialog::Deletequickaccess);
    SuperC->Addaction(Treemenu,Openfolder,"Open folder","Openfolder");
    SuperC->Addaction(Treemenu,Unpin,"Unpin folder","Unpinfolder");
    Openfolder->setIcon(QIcon(":/__supericon__/_open_.svg"));
    Unpin->setIcon(QIcon(":/__supericon__/_unlock_.svg"));
}

/*  menu init;*/

void SuperFileDialog::Iconinit()
{
    Plugin->ui->pushButton->setIcon(QIcon(":/__supericon__/_reset_.svg"));
    Plugin->ui->pushButton_4->setIcon(QIcon(":/__supericon__/_backward_.svg"));
    Plugin->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_newfolder_.svg"));
    Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_lock_.svg"));
    Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_picture_.svg"));
    Plugin->ui->comboBox->addItem(Dir->absolutePath());
    Refreshfolder(Dir->absolutePath());
}

/*  set widget icon;*/

void SuperFileDialog::Locationpathinit()
{
    QStringList locationpathlist = SuperC->Readonlyfile(Locationpath).split("<split>");
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

void SuperFileDialog::Quickaccessinit()
{
    Treewidgetadditemapi(QStandardPaths::DesktopLocation);
    Treewidgetadditemapi(QStandardPaths::DocumentsLocation);
    Treewidgetadditemapi(QStandardPaths::MusicLocation);
    Treewidgetadditemapi(QStandardPaths::PicturesLocation);
    Treewidgetadditemapi(QStandardPaths::DownloadLocation);
    Treewidgetadditemapi(QStandardPaths::MoviesLocation);
}

/*  add quick access path;*/

void SuperFileDialog::Treewidgetadditemapi(QStandardPaths::StandardLocation path)
{
    QStringList locationpathlist = SuperC->Readonlyfile(Locationpath).split("<split>");
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
            SuperC->Appendfile(Locationpath,fileinfo.absoluteFilePath() + "<split>");
        }
    }
}

/*  add path api;*/

void SuperFileDialog::Transfermodelindex(QModelIndex index)
{
    QString filepath = Filesystemmodel->filePath(index);
    Plugin->ui->comboBox->insertItem(0,filepath);
    Plugin->ui->comboBox->setCurrentIndex(0);
    Refreshfolder(filepath);
}

/*  transfer model index to string path;*/

void SuperFileDialog::Checkfolder()
{
    Refreshfolder(Plugin->ui->comboBox->currentText());
}

/*  refresh folder no parameter;*/

void SuperFileDialog::Refreshquickaccessfolder()
{
    QString pathtemp = Plugin->ui->treeWidget->currentItem()->text(1);
    Plugin->ui->comboBox->insertItem(0,pathtemp);
    Plugin->ui->comboBox->setCurrentIndex(0);
    Refreshfolder(pathtemp);
}

/*  refresh quick access folder;*/

void SuperFileDialog::Refreshfolder(QString folderpath)
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
        SuperC->Settablewidgetitem(Rowcounts,Columncounts,Fileiconmode,Plugin->ui->tableWidget);
        switch (Fileiconmode)
        {
            case 32:
            {
                Fileinfomode();
                break;
            }
            case 48:
            {
                Filepicturemode();
                break;
            }
        }
    }
    else
    {
        Dir->setPath(QDir::currentPath());
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,folderpath + " is not exist;");
        notedialog->Messageinit();
    }
}

/*  refresh current folders' files;*/

void SuperFileDialog::Fileinfomode()
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

void SuperFileDialog::Filepicturemode()
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

void SuperFileDialog::Setsinglefile()
{
    Dialogmode = 1;
    Plugin->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::Getfilelist);
    disconnect(Plugin->ui->pushButton_2,&QPushButton::clicked,              this,&SuperFileDialog::Getfilelist);
    disconnect(Selectfile,              &QAction::triggered,                this,&SuperFileDialog::Getfilelist);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::Getfile);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::Getfile);
    connect(Selectfile,                 &QAction::triggered,                this,&SuperFileDialog::Getfile);
}

/*  set table select mode as single;*/

void SuperFileDialog::Setsavefile()
{
    Dialogmode = 2;
    Plugin->ui->comboBox_2->setEnabled(true);
    Plugin->ui->comboBox_3->setEnabled(true);
    Plugin->ui->comboBox_2->setFocus();
    Plugin->ui->pushButton_2->setText("Save");
    Plugin->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemSelectionChanged,this,&SuperFileDialog::Enableselectfilebutton);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::Getfilelist);
    disconnect(Plugin->ui->pushButton_2,&QPushButton::clicked,              this,&SuperFileDialog::Getfilelist);
    disconnect(Selectfile,              &QAction::triggered,                this,&SuperFileDialog::Getfilelist);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::Getfilesavemode);
    connect(Selectfile,                 &QAction::triggered,                this,&SuperFileDialog::Getfilesavemode);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::Savefile);
    connect(Plugin->ui->comboBox_2,     &QComboBox::currentTextChanged,     this,&SuperFileDialog::Enablesavefilebutton);
}

/*  set save file mode;*/

void SuperFileDialog::Setsavefolder()
{
    Dialogmode = 3;
    Plugin->ui->pushButton_2->setEnabled(true);
    Plugin->ui->pushButton_2->setText("Current Folder");
    Plugin->ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemSelectionChanged,this,&SuperFileDialog::Enableselectfilebutton);
    disconnect(Plugin->ui->tableWidget, &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::Getfilelist);
    disconnect(Plugin->ui->pushButton_2,&QPushButton::clicked,              this,&SuperFileDialog::Getfilelist);
    disconnect(Selectfile,              &QAction::triggered,                this,&SuperFileDialog::Getfilelist);
    connect(Plugin->ui->tableWidget,    &QTableWidget::itemDoubleClicked,   this,&SuperFileDialog::Getfoldersavemode);
    connect(Selectfile,                 &QAction::triggered,                this,&SuperFileDialog::Getfoldersavemode);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,&SuperFileDialog::Savefolder);
    connect(Plugin->ui->comboBox_2,     &QComboBox::currentTextChanged,     this,&SuperFileDialog::Enablesavefilebutton);
}

/*  set save folder mode;*/

void SuperFileDialog::Getfile()
{
    QList<QTableWidgetItem*> itemlist = Plugin->ui->tableWidget->selectedItems();
    int currentrow = itemlist.at(0)->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        QString filetemp = Allfileinfolist.at(currentrow).absoluteFilePath();
        emit Signalfb(filetemp);
    }
    else
    {
        Plugin->ui->comboBox->insertItem(0,Allfileinfolist.at(currentrow).absoluteFilePath());
        Plugin->ui->comboBox->setCurrentIndex(0);
        Refreshfolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get single file;*/

void SuperFileDialog::Getfilesavemode()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        Savefile();
    }
    else
    {
        Plugin->ui->comboBox->insertItem(0,Allfileinfolist.at(currentrow).absoluteFilePath());
        Plugin->ui->comboBox->setCurrentIndex(0);
        Refreshfolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get single file;*/

void SuperFileDialog::Savefile()
{
    QString filesuffixtemp = Plugin->ui->comboBox_3->currentText().split("*").at(1);
    QString filenametemp = Plugin->ui->comboBox_2->currentText().split(filesuffixtemp).at(0);
    QString file = SuperC->Fixfilepath(Dir->absolutePath()) + filenametemp + filesuffixtemp;
    if(Checkrepeatfile(filenametemp,filesuffixtemp))
    {
        emit Signalfb(file);
    }
}

/*  save single file;*/

void SuperFileDialog::Getfoldersavemode()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        Savefolder();
    }
    else
    {
        Plugin->ui->comboBox->insertItem(0,Allfileinfolist.at(currentrow).absoluteFilePath());
        Plugin->ui->comboBox->setCurrentIndex(0);
        Refreshfolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get single folder;*/

void SuperFileDialog::Savefolder()
{
    emit Signalfb(SuperC->Fixfilepath(Dir->absolutePath()));
}

/*  save single folder;*/

bool SuperFileDialog::Checkrepeatfile(QString filename,QString filesuffix)
{
    for(int i = 0;i < Allfileinfolist.count();i++)
    {
        if(Allfileinfolist.at(i).completeBaseName() == filename && "." + Allfileinfolist.at(i).suffix() == filesuffix)
        {
            Currentfileindex = i;
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"replace with " + filename + filesuffix + " ?");
            connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileDialog::Replacefile);
            notedialog->Messageinit();
            return false;
        }
    }
    return true;
}

/*  check current folder repeat files;*/

void SuperFileDialog::Getfilelist()
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
        emit Signalfc(filestringlisttemp);
    }
    else if(!folderstringlisttemp.isEmpty())
    {
        Plugin->ui->comboBox->insertItem(0,folderstringlisttemp.at(0));
        Plugin->ui->comboBox->setCurrentIndex(0);
        Refreshfolder(Plugin->ui->comboBox->currentText());
    }
}

/*  get file list;*/

void SuperFileDialog::Enableselectfilebutton()
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

void SuperFileDialog::Enablesavefilebutton()
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

void SuperFileDialog::Cdupfolder()
{
    Dir->cdUp();
    Plugin->ui->comboBox->insertItem(0,Dir->absolutePath());
    Plugin->ui->comboBox->setCurrentIndex(0);
    Refreshfolder(Dir->absolutePath());
}

/*  cd up folder;*/

void SuperFileDialog::Execfilemenu()
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

void SuperFileDialog::Exectreemenu()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Treemenu->exec(QCursor::pos());
    }
}

/*  exec treemenu;*/

void SuperFileDialog::Openfiles()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    QString filepath = Allfileinfolist.at(currentrow).absoluteFilePath();
    QString filename = Allfileinfolist.at(currentrow).fileName();
    bool boola = QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));
    if(!boola)
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"open " + filename + " failed;/nclick ok open path;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileDialog::Openpaths);
        notedialog->Messageinit();
    }
}

/*  exec filemenu;*/

void SuperFileDialog::Openpaths()
{
    SuperC->Openpath(Dir->absolutePath());
}

/*  exec filemenu;*/

void SuperFileDialog::Replacefile()
{
    QString file = Allfileinfolist.at(Currentfileindex).absoluteFilePath();
    bool boola = QFile::remove(file);
    if(boola)
    {
        emit Signalfb(file);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"replace file failed;\nclick ok open path;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileDialog::Openpaths);
        notedialog->Messageinit();
    }
}

/*  replace file;*/

void SuperFileDialog::Creatnewfolder()
{
    int i = 0;
    bool boola = Dir->mkdir("New folder");
    while (boola == false)
    {
        i = i + 1;
        boola = Dir->mkdir("New folder " + QString::number(i));
    }
    Refreshfolder(Dir->absolutePath());
}

/*  creat new folder;*/

void SuperFileDialog::Delete()
{
    int currentrow = Plugin->ui->tableWidget->currentItem()->row();
    if(Allfileinfolist.at(currentrow).isFile())
    {
        bool boola = QFile::remove(Allfileinfolist.at(currentrow).absoluteFilePath());
        if(boola)
        {
            Refreshfolder(Plugin->ui->comboBox->currentText());
        }
        else
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"delete file failed;\nclick ok open path;");
            connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileDialog::Openpaths);
            notedialog->Messageinit();
        }
    }
    else if(Allfileinfolist.at(currentrow).isDir())
    {
        QDir dir(Allfileinfolist.at(currentrow).absoluteFilePath());
        bool boola = dir.removeRecursively();
        if(boola)
        {
            Refreshfolder(Plugin->ui->comboBox->currentText());
        }
        else
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"delete folder failed;\nclick ok open path;");
            connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileDialog::Openpaths);
            notedialog->Messageinit();
        }
    }
}

/*  delete file or folder;*/

void SuperFileDialog::Searchfile(QString text)
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

void SuperFileDialog::Addtoquickaccess()
{
    QFileInfo fileinfo(Dir->path());
    QStringList locationpathlist = SuperC->Readonlyfile(Locationpath).split("<split>");
    if(!locationpathlist.contains(fileinfo.absoluteFilePath()))
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget);
        item->setText(0,fileinfo.fileName());
        item->setText(1,fileinfo.absoluteFilePath());
        item->setIcon(0,Iconprovider.icon(fileinfo));
        Plugin->ui->treeWidget->addTopLevelItem(item);
        SuperC->Appendfile(Locationpath,fileinfo.absoluteFilePath() + "<split>");
    }
}

/*  add current folder path to quick access;*/

void SuperFileDialog::Changefileiconmode()
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
    Checkfolder();
}

/*  change file icon mode;*/

void SuperFileDialog::Deletequickaccess()
{
    delete Plugin->ui->treeWidget->currentItem();
    SuperC->Writeonlyfile(Locationpath,"");
    for(int i = 0;i < Plugin->ui->treeWidget->topLevelItemCount();i++)
    {
        SuperC->Appendfile(Locationpath,Plugin->ui->treeWidget->topLevelItem(i)->text(1) + "<split>");
    }
}

/*  remove current folder path from quick access;*/

void SuperFileDialog::Expandmodelfolder(QDir *dir)
{
    QStringList absolutefilepathlist = {};
    QDir newdir(dir->absolutePath());
    for(int i = 0;newdir.cdUp();i++)
    {
        absolutefilepathlist.insert(0,SuperC->Fixfilepath(newdir.absolutePath()));
    }
    absolutefilepathlist.append(SuperC->Fixfilepath(dir->absolutePath()));
    for(int i = 0;i < absolutefilepathlist.count();i++)
    {
        Plugin->ui->treeView->expand(Filesystemmodel->index(absolutefilepathlist.at(i)));
    }
    Plugin->ui->treeView->setCurrentIndex(Filesystemmodel->index(SuperC->Getlistlastmember(&absolutefilepathlist)));
}

/*  expand current folder path by treeview;*/
