#include "_itemdialog_.h"

ItemDialog::ItemDialog(QWidget *parent,QStringList *dataitems,QStringList *datacounts)
    : SuperWindow(parent)
{
    Dataitems = dataitems;
    Datacounts = datacounts;
    Disablemaxisize();
    Settitle("CPK Mode");
    setWindowModality(Qt::ApplicationModal);
    Init();
}

ItemDialog::~ItemDialog()
{

}

void ItemDialog::Init()
{
    Objectinit();
    Menuinit();
}

void ItemDialog::Objectinit()
{
    Plugin = new ItemBox(this);
    Pluginlayout->addWidget(Plugin);
    connect(this,                   &ItemDialog::Signalia,          this,&ItemDialog::hide);
    connect(this,                   &ItemDialog::Signalib,          this,&ItemDialog::hide);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemPressed,      this,&ItemDialog::Itemoptions);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemDoubleClicked,this,&ItemDialog::Open);
    Plugin->ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->treeWidget->header()->setStretchLastSection(false);
}

/*  item object init;*/

void ItemDialog::Menuinit()
{
    Itemdialogmenu = new QMenu(this);
    Openitem = new QAction(Itemdialogmenu);
    Changemode = new QAction(Itemdialogmenu);
    Openitem->setIcon(QIcon(":/__supericon__/_open_.svg"));
    Changemode->setIcon(QIcon(":/__supericon__/_changemode_.svg"));
    SuperC->Addaction(Itemdialogmenu,Openitem,"Open","Open");
    SuperC->Addaction(Itemdialogmenu,Changemode,"GRR Mode","GRR Mode");
    connect(Openitem,    &QAction::triggered,this,&ItemDialog::Open);
    connect(Changemode,  &QAction::triggered,this,&ItemDialog::Changemodes);
}

/*  menu init;*/

void ItemDialog::Refresh()
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

void ItemDialog::Itemoptions()
{
    if(qApp->mouseButtons() == Qt::RightButton)
    {
        Itemdialogmenu->exec(QCursor::pos());
    }
}

/*  exec menu;*/

void ItemDialog::Open()
{
    QString itemindex = Plugin->ui->treeWidget->currentItem()->text(0);
    if(Changemode->text() == "GRR Mode")
    {
        emit Signalia(itemindex.toInt());
    }
    else
    {
        emit Signalib(itemindex.toInt());
    }
}

/*  write items' index to local file and close this;*/

void ItemDialog::Changemodes()
{
    if(Changemode->text() == "GRR Mode")
    {
        Changemode->setText("CPK Mode");
        Settitle("GRR Mode");
    }
    else
    {
        Changemode->setText("GRR Mode");
        Settitle("CPK Mode");
    }
}

/*  change export mode;*/
