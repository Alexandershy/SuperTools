#include "_superfilemanager_.h"

SuperFileManager::SuperFileManager(QWidget *parent,QLayout *layout,QStringList filesplit)
    : QFrame(parent)
    , ui(new Ui::SuperFileManagerui)
{
    Widget = parent;
    Layout = layout;
    Filesplit = filesplit;
    ui->setupUi(this);
    connect(ui->lineEdit,                       &QLineEdit::textChanged,                    this,   &SuperFileManager::Searchfiles);
    connect(ui->tableWidget,                    &QTableWidget::itemDoubleClicked,           this,   &SuperFileManager::Clickopen);
    connect(ui->tableWidget,                    &QTableWidget::itemPressed,                 this,   &SuperFileManager::Itemoptions);
    connect(ui->tableWidget->horizontalHeader(),&QHeaderView::customContextMenuRequested,   this,   &SuperFileManager::Tableoptions);
    connect(ui->pushButton,                     &QPushButton::clicked,                      this,   &SuperFileManager::Locationfile);
    connect(ui->pushButton_2,                   &QPushButton::clicked,                      this,   &SuperFileManager::Checkfilevaildinit);
    Init();
}

SuperFileManager::~SuperFileManager()
{

}

void SuperFileManager::Init()
{
    Parameterinit();
    Objectinit();
    Addactioninit();
    Loadfilesinit();
}

/*  treewidget init;*/

void SuperFileManager::Parameterinit()
{
    Headerviewinit();
    Layout->addWidget(this);
    ui->pushButton->setIcon(QIcon(":/__supericon__/_location_.svg"));
    ui->pushButton_2->setIcon(QIcon(":/__supericon__/_check_.svg"));
    Cachesetting = "./__depycache__/__" + Core->Allwordlower(Widget->objectName()).split("box").at(0) + "__/_defaultsetting_.ini";
    Core->Creatfolder("./__depycache__/__" + Core->Allwordlower(Widget->objectName()).split("box").at(0) + "__");
    Core->Creatfile(Cachesetting);
    Widgetlist.append(ui->pushButton);
    Widgetlist.append(ui->pushButton_2);
}

/*  parameter init;*/

void SuperFileManager::Headerviewinit()
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

void SuperFileManager::Objectinit()
{
    Core = new SuperCore(this);
    Filemenu = new QMenu(this);
    Tablemenu = new QMenu(this);
    Openfile = new QAction(QIcon(":/__supericon__/_open_.svg"),"",Filemenu);
    Openpath = new QAction(QIcon(":/__supericon__/_openpath_.svg"),"",Filemenu);
    Deletefile = new QAction(QIcon(":/__supericon__/_delete_.svg"),"",Filemenu);
    Importfiles = new QAction(QIcon(":/__supericon__/_insert_.svg"),"",Tablemenu);
    Deleteallfiles = new QAction(QIcon(":/__supericon__/_delete2_.svg"),"",Tablemenu);
    connect(Openfile,       &QAction::triggered,this,&SuperFileManager::Actionopen);
    connect(Openpath,       &QAction::triggered,this,&SuperFileManager::Openfilepath);
    connect(Deletefile,     &QAction::triggered,this,&SuperFileManager::Deletefilesinit);
    connect(Importfiles,    &QAction::triggered,this,&SuperFileManager::Importfilesslot);
    connect(Deleteallfiles, &QAction::triggered,this,&SuperFileManager::Clearfileinit);
}

/*  object init;*/

void SuperFileManager::Addactioninit()
{
    Core->Addaction(Filemenu,Openfile,"Open File","Openfile");
    Core->Addaction(Filemenu,Openpath,"Open Path","Openpath");
    Filemenu->addSeparator();
    Core->Addaction(Filemenu,Deletefile,"Delete File","Deletefile");
    Core->Addaction(Tablemenu,Importfiles,"Import Super Files","ImportFiles");
    Tablemenu->addSeparator();
    Core->Addaction(Tablemenu,Deleteallfiles,"Delete All Files","DeleteAllFiles");
}

/*  add action init;*/

void SuperFileManager::Loadfilesinit()
{
    QString filelisttemp = Core->Readonlyfile(Cachesetting);
    if(!filelisttemp.isEmpty())
    {
        Setfiles(filelisttemp.split(Split));
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"no found file list,\nclick ok open filedialog select;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileManager::Importfilesslot);
        notedialog->Messageinit();
    }
}

/*  super load files;*/

void SuperFileManager::Importfilesslot()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,Sourcepath,Filesplit);
    connect(filedialog,&SuperFileDialog::Signalfc,this,         &SuperFileManager::Setfiles);
    connect(filedialog,&SuperFileDialog::Signalfc,filedialog,   &QObject::deleteLater);
    filedialog->Show();
}

/*  exec superfiledialog and select files;*/

void SuperFileManager::Setfiles(QStringList filelistinput)
{
    for(int i = 0;i < filelistinput.count();i++)
    {
        QString file = filelistinput.at(i);
        if(!Filelist.contains(file))
        {
            Filelist.append(file);
            emit Signalfa("N",file + " add completed","Selectfilesapi function run completed");
        }
    }
    Core->Settablewidgetitem(Filelist.count(),Fileinfoheader.count(),24,ui->tableWidget);
    Headerviewinit();
    for(int i = 0;i < Filelist.count();i++)
    {
        QFileInfo fileinfo(Filelist.at(i));
        ui->tableWidget->item(i,0)->setText(QString("%1").arg(i,4,10,QChar('0')));
        ui->tableWidget->item(i,1)->setIcon(Iconprovider.icon(fileinfo));
        ui->tableWidget->item(i,1)->setText(fileinfo.completeBaseName() + "." + fileinfo.suffix());
        ui->tableWidget->item(i,2)->setText(Core->Fixfilepath(fileinfo.absolutePath()));
        ui->tableWidget->item(i,3)->setText(QString::number(fileinfo.size()) + " bits");
    }
    Core->Writeonlyfilelist(Cachesetting,&Filelist,Split,false);
    Setcurrentfile(Core->Getlistlastmember(&filelistinput));
    Enablewidgetlist();
}

/*  set files and record as setting;*/

void SuperFileManager::Clearfileinit()
{
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"sure to clear all files ?");
    connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileManager::Cleartreewidget);
    notedialog->Messageinit();
}

/*  clear treewidget items;*/

void SuperFileManager::Cleartreewidget()
{
    Filelist.clear();
    Enablewidgetlist();
    Core->Writeonlyfilelist(Cachesetting,&Filelist,Split,false);
    Core->Settablewidgetitem(Filelist.count(),Fileinfoheader.count(),24,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(Fileinfoheader);
    emit Signalfa("N","all file delete completed","Cleantreewidget function run completed");
    emit Signalfb();
}

/*  clear treewidget;*/

void SuperFileManager::Searchfiles(QString text)
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

void SuperFileManager::Itemoptions()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Filemenu->exec(QCursor::pos());
    }
}

/*  exec item menu;*/

void SuperFileManager::Tableoptions()
{
    Tablemenu->exec(QCursor::pos());
}

/*  exec table menu;*/

void SuperFileManager::Clickopen()
{
    if(Openinit())
    {
        emit Signalfc();
    }
}

/*  click open file;*/

void SuperFileManager::Actionopen()
{
    if(Openinit())
    {
        emit Signalfd();
    }
}

/*  action open file;*/

void SuperFileManager::Openfilepath()
{
    int row = ui->tableWidget->currentRow();
    Core->Openpath(ui->tableWidget->item(row,2)->text());
}

/*  open file path*/

bool SuperFileManager::Openinit()
{
    QString file = Getcurrentitemtext();
    QFileInfo fileinfo(file);
    if(fileinfo.exists())
    {
        return true;
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,file + " is not exists,\nclick ok delete invalid file;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileManager::Deletefiles);
        notedialog->Messageinit();
        return false;
    }
}

/*  action open file;*/

void SuperFileManager::Enablewidgetlist()
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

void SuperFileManager::Deletefilesinit()
{
    int row = ui->tableWidget->currentRow();
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"sure to delete " + ui->tableWidget->item(row,1)->text() + " ?");
    connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileManager::Deletefiles);
    notedialog->Messageinit();
}

/*  delete files init;*/

void SuperFileManager::Deletefiles()
{
    QString filedelete = Getcurrentitemtext();
    Filelist.removeOne(filedelete);
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    Core->Writeonlyfilelist(Cachesetting,&Filelist,Split,false);
    Enablewidgetlist();
    Resetindex();
    emit Signalfa("N",filedelete + " has been delete from filemanager;","Checkfilevaild function run completed;");
    emit Signalfe(filedelete);
}

/*  delete files;*/

void SuperFileManager::Resetindex()
{
    for(int i = 0;i < Filelist.count();i++)
    {
        ui->tableWidget->item(i,0)->setText(QString("%1").arg(i,4,10,QChar('0')));
    }
}

/*  reset index;*/

void SuperFileManager::Disableopen()
{
    disconnect(Openfile,&QAction::triggered,this,&SuperFileManager::Actionopen);
    disconnect(ui->tableWidget,&QTableWidget::itemDoubleClicked,this,&SuperFileManager::Clickopen);
    connect(Openfile,&QAction::triggered,this,&SuperFileManager::Disableopentips);
    connect(ui->tableWidget,&QTableWidget::itemDoubleClicked,this,&SuperFileManager::Disableopentips);
}

/*  disable click open files;*/

void SuperFileManager::Disableopentips()
{
    QString file = Getcurrentitemtext();
    SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"error: " + file + " can not open!;");
    notedialog->Messageinit();
}

/*  disable tips;*/

QString SuperFileManager::Getcurrentitemtext()
{
    int row = ui->tableWidget->currentRow();
    return ui->tableWidget->item(row,2)->text() + ui->tableWidget->item(row,1)->text();
}

/*  get item text;*/

void SuperFileManager::Personalization(QString sourcepath,QString text)
{
    Filesuffix = text;
    Sourcepath = sourcepath;
    Importfiles->setText("Import " + Filesuffix + " Files");
    ui->label->setText(Filesuffix + " File Manager Module");
}

/*  make this personalizaton;*/

void SuperFileManager::Locationfile()
{
    int index = 0;
    if(Filetemp.isEmpty())
    {
        ui->tableWidget->setCurrentItem(ui->tableWidget->item(0,0));
    }
    else
    {
        index = Core->Findlistmember(&Filelist,Filetemp);
        if(index == -1)
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"error: " + Filetemp + " can not determined!;");
            notedialog->Messageinit();
            return;
        }
    }
    ui->tableWidget->setCurrentItem(ui->tableWidget->item((index + 1) % Filelist.count(),0));
    ui->tableWidget->setCurrentItem(ui->tableWidget->item(index % Filelist.count(),0));
    ui->tableWidget->setFocus();
}

/*  location current file;*/

void SuperFileManager::Setcurrentfile(QString filetemp)
{
    Filetemp = filetemp;
    Locationfile();
}

/*  set current file temp;*/

void SuperFileManager::Checkfilevaildinit()
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
        Checkfilevaild();
    }
}

/*  check file vaild or not init;*/

void SuperFileManager::Checkfilevaild()
{
    if(!Invaildfilelist.isEmpty())
    {
        emit Signalfa("N","invaild filelist: ","Checkfilevaild function run completed;");
        for(int i = 0;i < Invaildfilelist.count();i++)
        {
            emit Signalfa("N",Filelist.at(Invaildfilelist.at(i)),"Checkfilevaild function run completed;");
        }
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"invaild file display on logger;\nclick ok remove invaild files;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFileManager::Deleteinvaildfiles);
        notedialog->Messageinit();
    }
    else
    {
        emit Signalfa("N","all " + Core->Firstwordlower(Filesuffix) + " files are vaild;","Checkfilevaild function run completed;");
    }
}

/*  check file vaild or not;*/

void SuperFileManager::Deleteinvaildfiles()
{
    for(int i = Invaildfilelist.count();i > 0;i--)
    {
        ui->tableWidget->setCurrentItem(ui->tableWidget->item(Invaildfilelist.at(i - 1),0));
        Deletefiles();
    }
}

/*  delete invaild files;*/
