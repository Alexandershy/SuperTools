#include "_pathlossdialog_.h"
#include "ui__pathlossdialogui_.h"

PathLossDialog::PathLossDialog(QWidget *parent)
    : SuperWindow(parent)
{
    setTitle("Pathloss Editor");
    init();
}

PathLossDialog::~PathLossDialog()
{

}

void PathLossDialog::init()
{
    objectInit();
}

void PathLossDialog::objectInit()
{
    Plugin = new PathLossDialogui(this);
    Pluginlayout->addWidget(Plugin);
    Datamenu    = new PathLossDataMenu(this);
    Configmenu  = new PathLossConfigMenu(this);
    Settingmenu = new PathLossSettingMenu(this);
    connect(Plugin->ui->treeWidget,     &QTableWidget::customContextMenuRequested,  this,&PathLossDialog::openPathLossConfigMenu);
    connect(Plugin->ui->tableWidget,    &QTableWidget::customContextMenuRequested,  this,&PathLossDialog::openPathLossDataMenu);
    connect(Plugin->ui->tableWidget_2,  &QTreeWidget::customContextMenuRequested,   this,&PathLossDialog::openPathLossSettingMenu);
    Datamenu->creatAction();
    Configmenu->creatAction();
    Settingmenu->creatAction();
}

void PathLossDialog::openPathLossConfigMenu()
{
    Configmenu->exec(QCursor::pos());
}

void PathLossDialog::openPathLossDataMenu()
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

void PathLossDialog::openPathLossSettingMenu()
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

void PathLossDataMenu::creatAction()
{
    Core->addAction(this,Newrow,"New Row","Newrow");
    Core->addAction(this,Save,"Save","Save");
    Core->addAction(this,Deleterow,"Delete Row","Deleterow");
}

PathLossConfigMenu::PathLossConfigMenu(QWidget *parent)
    : QMenu(parent)
{

}

void PathLossConfigMenu::creatAction()
{
    Core->addAction(this,Newconfig,"New Config","Newconfig");
    Core->addAction(this,Save,"Save","Save");
    Core->addAction(this,Deleteconfig,"Delete Config","Deleteconfig");
    Core->addAction(this,Importcsv,"Import Csv","Importcsv");
    Core->addAction(this,Exportcsv,"Export Csv","Exportcsv");
}

PathLossSettingMenu::PathLossSettingMenu(QWidget *parent)
    : QMenu(parent)
{

}

void PathLossSettingMenu::creatAction()
{
    Core->addAction(this,Apply,"Apply","Apply");
}
