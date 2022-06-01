#include "_csvdataitemdialog_.h"
#include "ui__csvdataitemdialogui_.h"

CsvDataItemDialog::CsvDataItemDialog(QWidget *parent,QStringList *dataitems,QStringList *datacounts)
    : SuperWindow(parent)
{
    Dataitems = dataitems;
    Datacounts = datacounts;
    disableMaxisize();
    setTitle("CPK Mode");
    setWindowModality(Qt::ApplicationModal);
    init();
}

CsvDataItemDialog::~CsvDataItemDialog()
{

}

void CsvDataItemDialog::init()
{
    objectInit();
    menuInit();
}

void CsvDataItemDialog::objectInit()
{
    Plugin = new CsvDataItemDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(this,                   &CsvDataItemDialog::signalIa,       this,&CsvDataItemDialog::hide);
    connect(this,                   &CsvDataItemDialog::signalIb,       this,&CsvDataItemDialog::hide);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemPressed,          this,&CsvDataItemDialog::itemOptions);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemDoubleClicked,    this,&CsvDataItemDialog::open);
    Plugin->ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->treeWidget->header()->setStretchLastSection(false);
}

/*  item object init;*/

void CsvDataItemDialog::menuInit()
{
    Itemdialogmenu = new QMenu(this);
    Openitem = new QAction(Itemdialogmenu);
    Changemode = new QAction(Itemdialogmenu);
    Openitem->setIcon(QIcon(":/__supericon__/_open_.svg"));
    Changemode->setIcon(QIcon(":/__supericon__/_changemode_.svg"));
    Core->addAction(Itemdialogmenu,Openitem,"Open","Open");
    Core->addAction(Itemdialogmenu,Changemode,"GRR Mode","GRR Mode");
    connect(Openitem,    &QAction::triggered,this,&CsvDataItemDialog::open);
    connect(Changemode,  &QAction::triggered,this,&CsvDataItemDialog::changeModes);
}

/*  menu init;*/

void CsvDataItemDialog::refresh()
{
    Plugin->ui->treeWidget->clear();
    for(int i = 0;i < Dataitems->count();i++)
    {
        QString itemname = Dataitems->at(i);
        int itemcounts = Datacounts->at(i).toInt();
        itemname.remove("\r");
        itemname.remove("\n");
        if(!itemname.isEmpty() && itemcounts > 0)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget);
            item->setText(0,QString::number(i));
            item->setText(1,Datacounts->at(i));
            item->setText(2,itemname);
            Plugin->ui->treeWidget->addTopLevelItem(item);
        }
    }
}

/*  get data tab items;*/

void CsvDataItemDialog::itemOptions()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Itemdialogmenu->exec(QCursor::pos());
    }
}

/*  exec menu;*/

void CsvDataItemDialog::open()
{
    QString itemindex = Plugin->ui->treeWidget->currentItem()->text(0);
    if(Changemode->text() == "GRR Mode")
    {
        emit signalIa(itemindex.toInt());
    }
    else
    {
        emit signalIb(itemindex.toInt());
    }
}

/*  write items' index to local file and close this;*/

void CsvDataItemDialog::changeModes()
{
    if(Changemode->text() == "GRR Mode")
    {
        Changemode->setText("CPK Mode");
        setTitle("GRR Mode");
    }
    else
    {
        Changemode->setText("GRR Mode");
        setTitle("CPK Mode");
    }
}

/*  change export mode;*/
