#include "_pathlossdialog_.h"

PathLossDialog::PathLossDialog(QWidget *parent)
    : SuperWindow(parent)
{
    Settitle("Pathloss Editor");
    Init();
}

PathLossDialog::~PathLossDialog()
{

}

void PathLossDialog::Init()
{
    Objectinit();
}

void PathLossDialog::Objectinit()
{
    Plugin = new PathLossBox(this);
    Pluginlayout->addWidget(Plugin);
    Datamenu    = new PathLossDataMenu(this);
    Configmenu  = new PathLossConfigMenu(this);
    Settingmenu = new PathLossSettingMenu(this);
    connect(Plugin->ui->treeWidget,     &QTableWidget::customContextMenuRequested,  this,&PathLossDialog::Openpathlossconfigmenu);
    connect(Plugin->ui->tableWidget,    &QTableWidget::customContextMenuRequested,  this,&PathLossDialog::Openpathlossdatamenu);
    connect(Plugin->ui->tableWidget_2,  &QTreeWidget::customContextMenuRequested,   this,&PathLossDialog::Openpathlosssettingmenu);
    Datamenu->Creataction();
    Configmenu->Creataction();
    Settingmenu->Creataction();
}

void PathLossDialog::Openpathlossconfigmenu()
{
    Configmenu->exec(QCursor::pos());
}

void PathLossDialog::Openpathlossdatamenu()
{
    if(Plugin->ui->treeWidget->topLevelItemCount() == 0)
    {
        Datamenu->Newrow->setEnabled(false);
        Datamenu->Save->setEnabled(false);
    }
    else
    {
        Datamenu->Newrow->setEnabled(true);
        Datamenu->Save->setEnabled(true);
    }
    if(Plugin->ui->tableWidget->rowCount() == 0)
    {
        Datamenu->Deleterow->setEnabled(false);
    }
    else
    {
        Datamenu->Deleterow->setEnabled(true);
    }
    Datamenu->exec(QCursor::pos());
}

void PathLossDialog::Openpathlosssettingmenu()
{
    if(Plugin->ui->tableWidget_2->selectedItems().count() > 0 && Plugin->ui->treeWidget->topLevelItemCount() > 0)
    {
        Settingmenu->Apply->setEnabled(true);
    }
    else
    {
        Settingmenu->Apply->setEnabled(false);
    }
    Settingmenu->exec(QCursor::pos());
}

PathLossDataMenu::PathLossDataMenu(QWidget *parent)
    : QMenu(parent)
{

}

void PathLossDataMenu::Creataction()
{
    SuperC->Addaction(this,Newrow,"New Row","Newrow");
    SuperC->Addaction(this,Save,"Save","Save");
    SuperC->Addaction(this,Deleterow,"Delete Row","Deleterow");
}

PathLossConfigMenu::PathLossConfigMenu(QWidget *parent)
    : QMenu(parent)
{

}

void PathLossConfigMenu::Creataction()
{
    SuperC->Addaction(this,Newconfig,"New Config","Newconfig");
    SuperC->Addaction(this,Save,"Save","Save");
    SuperC->Addaction(this,Deleteconfig,"Delete Config","Deleteconfig");
    SuperC->Addaction(this,Importcsv,"Import Csv","Importcsv");
    SuperC->Addaction(this,Exportcsv,"Export Csv","Exportcsv");
}

PathLossSettingMenu::PathLossSettingMenu(QWidget *parent)
    : QMenu(parent)
{

}

void PathLossSettingMenu::Creataction()
{
    SuperC->Addaction(this,Apply,"Apply","Apply");
}
