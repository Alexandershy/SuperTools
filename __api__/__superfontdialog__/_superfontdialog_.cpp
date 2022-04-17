#include "_superfontdialog_.h"

SuperFontDialog::SuperFontDialog(QWidget *parent,QStringList *fontfamilies)
    :SuperWindow(parent)
{
    Fontfamilies = fontfamilies;
    Disablemaxisize();
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Settitle("SuperFontDialog");
    Init();
}

SuperFontDialog::~SuperFontDialog()
{

}

void SuperFontDialog::Init()
{
    Objectinit();
    Parameterinit();
    Fontlistinit();
    Currentfontinit();
}

void SuperFontDialog::Objectinit()
{
    Plugin = new SuperFontDialogui(this);
    Pluginlayout->addWidget(Plugin);
    Plugin->ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    Plugin->ui->treeWidget->header()->setStretchLastSection(false);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemDoubleClicked,    this,&SuperFontDialog::Sendfont);
    connect(Plugin->ui->treeWidget, &QTreeWidget::itemPressed,          this,&SuperFontDialog::Previewfont);
    connect(Plugin->ui->lineEdit,   &QLineEdit::textChanged,            this,&SuperFontDialog::Searchfont);
}

/*  creat object and connect its slot;*/

void SuperFontDialog::Parameterinit()
{
    Plugin->ui->lineEdit->setFocus();
}

/*  parameter init;;*/

void SuperFontDialog::Fontlistinit()
{
    QStringList fontstringlist = QFontDatabase::families();
    for(int i = 0;i < fontstringlist.count();i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(Plugin->ui->treeWidget);
        item->setText(0,fontstringlist.at(i));
        Plugin->ui->treeWidget->addTopLevelItem(item);
    }
}

/*  get families from family database;*/

void SuperFontDialog::Currentfontinit()
{
    if(!Fontfamilies->isEmpty())
    {
        for(int i = 0;i < Plugin->ui->treeWidget->topLevelItemCount();i++)
        {
            QTreeWidgetItem *item = Plugin->ui->treeWidget->topLevelItem(i);
            if(item->text(0).contains(Fontfamilies->at(0),Qt::CaseInsensitive) && item->text(0).size() == Fontfamilies->at(0).size())
            {
                Plugin->ui->treeWidget->setCurrentItem(item);
                Plugin->ui->treeWidget->setTreePosition(i);
                Previewfont();
                break;
            }
        }
    }
}

/*  find current families and preview it;*/

void SuperFontDialog::Searchfont()
{
    QString fonttemp = Plugin->ui->lineEdit->text();
    if(!fonttemp.isEmpty())
    {
        for(int i = 0;i < Plugin->ui->treeWidget->topLevelItemCount();i++)
        {
            QTreeWidgetItem *item = Plugin->ui->treeWidget->topLevelItem(i);
            if(item->text(0).contains(fonttemp,Qt::CaseInsensitive))
            {
                item->setHidden(false);
            }
            else
            {
                item->setHidden(true);
            }
        }
    }
    else
    {
        for(int i = 0;i < Plugin->ui->treeWidget->topLevelItemCount();i++)
        {
            Plugin->ui->treeWidget->topLevelItem(i)->setHidden(false);
        }
    }
}

/*  search font by user input families' name;*/

void SuperFontDialog::Previewfont()
{
    QFont font(Plugin->ui->treeWidget->currentItem()->text(0),20,75,false);
    Plugin->ui->label->setFont(font);
}

/*  display font families at label;*/

void SuperFontDialog::Sendfont()
{
    QStringList fontfamilies(Plugin->ui->treeWidget->currentItem()->text(0));
    emit Signalfa(fontfamilies);
    close();
}

/*  emit stringlist signal for set families;*/

