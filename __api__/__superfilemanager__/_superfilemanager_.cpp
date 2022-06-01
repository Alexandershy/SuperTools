#include "_superfilemanager_.h"
#include "ui__superfilemanagerui_.h"

SuperFileManager::SuperFileManager(QWidget *parent,QLayout *layout,QStringList filesplit)
    : QFrame(parent)
    , ui(new Ui::SuperFileManagerui)
{
    Widget = parent;
    Layout = layout;
    Filesplit = filesplit;
    ui->setupUi(this);
    connect(ui->lineEdit,                       &QLineEdit::textChanged,                    this,   &SuperFileManager::searchFiles);
    connect(ui->tableWidget,                    &QTableWidget::itemDoubleClicked,           this,   &SuperFileManager::clickOpen);
    connect(ui->tableWidget,                    &QTableWidget::itemPressed,                 this,   &SuperFileManager::itemOptions);
    connect(ui->tableWidget->horizontalHeader(),&QHeaderView::customContextMenuRequested,   this,   &SuperFileManager::tableOptions);
    connect(ui->tableWidget,                    &QTableWidget::customContextMenuRequested,  this,   &SuperFileManager::tableOptions);
    connect(ui->pushButton,                     &QPushButton::clicked,                      this,   &SuperFileManager::locationFile);
    connect(ui->pushButton_2,                   &QPushButton::clicked,                      this,   &SuperFileManager::checkFileVaildInit);
    init();
}

SuperFileManager::~SuperFileManager()
{

}

void SuperFileManager::init()
{
    parameterInit();
    objectInit();
    addActionInit();
    loadFilesInit();
}

/*  treewidget init;*/

void SuperFileManager::parameterInit()
{
    headerViewInit();
    Layout->addWidget(this);
    ui->pushButton->setIcon(QIcon(":/__supericon__/_location_.svg"));
    ui->pushButton_2->setIcon(QIcon(":/__supericon__/_check_.svg"));
    Cachesetting = "./__depycache__/__" + Core->allWordLower(Widget->objectName()).split("box").at(0) + "__/_defaultsetting_.ini";
    Core->creatFolder("./__depycache__/__" + Core->allWordLower(Widget->objectName()).split("box").at(0) + "__");
    Core->creatFile(Cachesetting);
    Widgetlist.append(ui->pushButton);
    Widgetlist.append(ui->pushButton_2);
}

/*  parameter init;*/

void SuperFileManager::headerViewInit()
{
    if(Filelist.isEmpty())
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    else
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    ui->tableWidget->setHorizontalHeaderLabels(Fileinfoheader);
    ui->tableWidget->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

/*  header view init;*/

void SuperFileManager::objectInit()
{
    Core = new SuperCore(this);
    Filemenu = new QMenu(this);
    Tablemenu = new QMenu(this);
    Openfile = new QAction(QIcon(":/__supericon__/_open_.svg"),"",Filemenu);
    Openpath = new QAction(QIcon(":/__supericon__/_openpath_.svg"),"",Filemenu);
    Deletefile = new QAction(QIcon(":/__supericon__/_delete_.svg"),"",Filemenu);
    Importfiles = new QAction(QIcon(":/__supericon__/_insert_.svg"),"",Tablemenu);
    Deleteallfiles = new QAction(QIcon(":/__supericon__/_delete2_.svg"),"",Tablemenu);
    connect(Openfile,       &QAction::triggered,this,&SuperFileManager::actionOpen);
    connect(Openpath,       &QAction::triggered,this,&SuperFileManager::openFilePath);
    connect(Deletefile,     &QAction::triggered,this,&SuperFileManager::deleteFilesInit);
    connect(Importfiles,    &QAction::triggered,this,&SuperFileManager::importFilesSlot);
    connect(Deleteallfiles, &QAction::triggered,this,&SuperFileManager::clearFileInit);
}

/*  object init;*/

void SuperFileManager::addActionInit()
{
    Core->addAction(Filemenu,Openfile,"Open File","Openfile");
    Core->addAction(Filemenu,Openpath,"Open Path","Openpath");
    Filemenu->addSeparator();
    Core->addAction(Filemenu,Deletefile,"Delete File","Deletefile");
    Core->addAction(Tablemenu,Importfiles,"Import Super Files","ImportFiles");
    Tablemenu->addSeparator();
    Core->addAction(Tablemenu,Deleteallfiles,"Delete All Files","DeleteAllFiles");
}

/*  add action init;*/

void SuperFileManager::loadFilesInit()
{
    QString filelisttemp = Core->readOnlyFile(Cachesetting);
    if(!filelisttemp.isEmpty())
    {
        setFiles(filelisttemp.split(Split));
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"no found file list,\nclick ok open filedialog select;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileManager::importFilesSlot);
        notedialog->messageInit();
    }
}

/*  super load files;*/

void SuperFileManager::importFilesSlot()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,Sourcepath,Filesplit);
    connect(filedialog,&SuperFileDialog::signalFc,this,         &SuperFileManager::setFiles);
    connect(filedialog,&SuperFileDialog::signalFc,filedialog,   &QObject::deleteLater);
    filedialog->show();
}

/*  exec superfiledialog and select files;*/

void SuperFileManager::setFiles(QStringList filelistinput)
{
    for(int i = 0;i < filelistinput.count();i++)
    {
        QString file = filelistinput.at(i);
        if(!Filelist.contains(file))
        {
            Filelist.append(file);
            emit signalFa("N",file + " add completed","Selectfilesapi function run completed");
        }
    }
    Core->setTableWidgetItem(Filelist.count(),Fileinfoheader.count(),24,ui->tableWidget);
    headerViewInit();
    for(int i = 0;i < Filelist.count();i++)
    {
        QFileInfo fileinfo(Filelist.at(i));
        ui->tableWidget->item(i,0)->setText(QString("%1").arg(i,4,10,QChar('0')));
        ui->tableWidget->item(i,1)->setIcon(Iconprovider.icon(fileinfo));
        ui->tableWidget->item(i,1)->setText(fileinfo.completeBaseName() + "." + fileinfo.suffix());
        ui->tableWidget->item(i,2)->setText(Core->fixFilePath(fileinfo.absolutePath()));
        ui->tableWidget->item(i,3)->setText(QString::number(fileinfo.size()) + " bits");
    }
    Core->writeOnlyFileList(Cachesetting,&Filelist,Split,false);
    setCurrentFile(Core->getListLastMember(&filelistinput));
    enableWidgetList();
}

/*  set files and record as setting;*/

void SuperFileManager::clearFileInit()
{
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"sure to clear all files ?");
    connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileManager::clearTreeWidget);
    notedialog->messageInit();
}

/*  clear treewidget items;*/

void SuperFileManager::clearTreeWidget()
{
    Filelist.clear();
    enableWidgetList();
    Core->writeOnlyFileList(Cachesetting,&Filelist,Split,false);
    Core->setTableWidgetItem(Filelist.count(),Fileinfoheader.count(),24,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(Fileinfoheader);
    emit signalFa("N","all file delete completed","Cleantreewidget function run completed");
    emit signalFb();
}

/*  clear treewidget;*/

void SuperFileManager::searchFiles(QString text)
{
    if(!text.isEmpty())
    {
        for(int i = 0;i < Filelist.count();i++)
        {
            QTableWidgetItem *iditem = ui->tableWidget->item(i,0);
            QTableWidgetItem *nameitem = ui->tableWidget->item(i,1);
            if(iditem->text().contains(text,Qt::CaseInsensitive) || nameitem->text().contains(text,Qt::CaseInsensitive))
            {
                ui->tableWidget->showRow(i);
            }
            else
            {
                ui->tableWidget->hideRow(i);
            }
        }
    }
    else
    {
        for(int i = 0;i < Filelist.count();i++)
        {
            ui->tableWidget->showRow(i);
        }
    }
}

/*  search files;*/

void SuperFileManager::itemOptions()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Filemenu->exec(QCursor::pos());
    }
}

/*  exec item menu;*/

void SuperFileManager::tableOptions()
{
    QPoint point = QCursor::pos();
    QModelIndex index = ui->tableWidget->indexAt(point);
    if(!index.isValid())
    {
        Tablemenu->exec(point);
    }
}

/*  exec table menu;*/

void SuperFileManager::clickOpen()
{
    if(openInit())
    {
        emit signalFc();
    }
}

/*  click open file;*/

void SuperFileManager::actionOpen()
{
    if(openInit())
    {
        emit signalFd();
    }
}

/*  action open file;*/

void SuperFileManager::openFilePath()
{
    int row = ui->tableWidget->currentRow();
    Core->openPath(ui->tableWidget->item(row,2)->text());
}

/*  open file path*/

bool SuperFileManager::openInit()
{
    QString file = getCurrentItemText();
    QFileInfo fileinfo(file);
    if(fileinfo.exists())
    {
        return true;
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,file + " is not exists,\nclick ok delete invalid file;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileManager::deleteFiles);
        notedialog->messageInit();
        return false;
    }
}

/*  action open file;*/

void SuperFileManager::enableWidgetList()
{
    bool boola = Filelist.isEmpty();
    Deleteallfiles->setEnabled(!boola);
    for(int i = 0;i < Widgetlist.count();i++)
    {
        Widgetlist.at(i)->setEnabled(!boola);
    }
    if(boola)
    {
        for(int i = 0;i < Checkboxlist.count();i++)
        {
            Checkboxlist.at(i)->setChecked(!boola);
        }
    }
}

/*  is enable widget button or not;*/

void SuperFileManager::deleteFilesInit()
{
    int row = ui->tableWidget->currentRow();
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"sure to delete " + ui->tableWidget->item(row,1)->text() + " ?");
    connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileManager::deleteFiles);
    notedialog->messageInit();
}

/*  delete files init;*/

void SuperFileManager::deleteFiles()
{
    QString filedelete = getCurrentItemText();
    Filelist.removeOne(filedelete);
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    Core->writeOnlyFileList(Cachesetting,&Filelist,Split,false);
    enableWidgetList();
    resetIndex();
    emit signalFa("N",filedelete + " has been delete from filemanager;","Checkfilevaild function run completed;");
    emit signalFe(filedelete);
}

/*  delete files;*/

void SuperFileManager::resetIndex()
{
    for(int i = 0;i < Filelist.count();i++)
    {
        ui->tableWidget->item(i,0)->setText(QString("%1").arg(i,4,10,QChar('0')));
    }
}

/*  reset index;*/

void SuperFileManager::disableOpen()
{
    disconnect(Openfile,&QAction::triggered,this,&SuperFileManager::actionOpen);
    disconnect(ui->tableWidget,&QTableWidget::itemDoubleClicked,this,&SuperFileManager::clickOpen);
    connect(Openfile,&QAction::triggered,this,&SuperFileManager::disableOpenTips);
    connect(ui->tableWidget,&QTableWidget::itemDoubleClicked,this,&SuperFileManager::disableOpenTips);
}

/*  disable click open files;*/

void SuperFileManager::disableOpenTips()
{
    QString file = getCurrentItemText();
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"error: " + file + " can not open!;");
    notedialog->messageInit();
}

/*  disable tips;*/

QString SuperFileManager::getCurrentItemText()
{
    int row = ui->tableWidget->currentRow();
    return ui->tableWidget->item(row,2)->text() + ui->tableWidget->item(row,1)->text();
}

/*  get item text;*/

void SuperFileManager::personalization(QString sourcepath,QString text)
{
    Filesuffix = text;
    Sourcepath = sourcepath;
    Importfiles->setText("Import " + Filesuffix + " Files");
    ui->label->setText(Filesuffix + " File Manager Module");
}

/*  make this personalizaton;*/

void SuperFileManager::locationFile()
{
    int index = 0;
    if(Filetemp.isEmpty())
    {
        ui->tableWidget->setCurrentItem(ui->tableWidget->item(0,0));
    }
    else
    {
        index = Core->findListMember(&Filelist,Filetemp);
        if(index == -1)
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"error: " + Filetemp + " can not determined!;");
            notedialog->messageInit();
            return;
        }
    }
    ui->tableWidget->setCurrentItem(ui->tableWidget->item((index + 1) % Filelist.count(),0));
    ui->tableWidget->setCurrentItem(ui->tableWidget->item(index % Filelist.count(),0));
    ui->tableWidget->setFocus();
}

/*  location current file;*/

void SuperFileManager::setCurrentFile(QString filetemp)
{
    Filetemp = filetemp;
    locationFile();
}

/*  set current file temp;*/

void SuperFileManager::checkFileVaildInit()
{
    Invaildfilelist.clear();
    for(int i = 0;i < Filelist.count();i++)
    {
        QFileInfo fileinfo(Filelist.at(i));
        if(!fileinfo.exists())
        {
            Invaildfilelist.append(i);
        }
    }
    if(!Filelist.isEmpty())
    {
        checkFileVaild();
    }
}

/*  check file vaild or not init;*/

QTableWidgetItem* SuperFileManager::firstItem(int rowindex)
{
    return ui->tableWidget->item(rowindex,0);
}

/*  return current item;*/

QTableWidgetItem* SuperFileManager::currentItem()
{
    return ui->tableWidget->currentItem();
}

/*  return current item;*/

void SuperFileManager::setCurrentItem(QTableWidgetItem* item)
{
    ui->tableWidget->setCurrentItem(item);
}

/*  set current item;*/

void SuperFileManager::checkFileVaild()
{
    if(!Invaildfilelist.isEmpty())
    {
        emit signalFa("N","invaild filelist: ","Checkfilevaild function run completed;");
        for(int i = 0;i < Invaildfilelist.count();i++)
        {
            emit signalFa("N",Filelist.at(Invaildfilelist.at(i)),"Checkfilevaild function run completed;");
        }
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"invaild file display on logger;\nclick ok remove invaild files;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFileManager::deleteInvaildFiles);
        notedialog->messageInit();
    }
    else
    {
        emit signalFa("N","all " + Core->firstWordLower(Filesuffix) + " files are vaild;","Checkfilevaild function run completed;");
    }
}

/*  check file vaild or not;*/

void SuperFileManager::deleteInvaildFiles()
{
    for(int i = Invaildfilelist.count();i > 0;i--)
    {
        ui->tableWidget->setCurrentItem(ui->tableWidget->item(Invaildfilelist.at(i - 1),0));
        deleteFiles();
    }
}

/*  delete invaild files;*/
