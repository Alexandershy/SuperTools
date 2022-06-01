#include "_routdialog_.h"
#include "ui__routdialogui_.h"

RoutDialog::RoutDialog(QWidget *parent)
    : SuperWindow(parent)
{
    init();
    setTitle("Rout dialog");
}

RoutDialog::~RoutDialog()
{

}

void RoutDialog::init()
{
    objectInit();
}

void RoutDialog::objectInit()
{
    Plugin = new RoutDialogui(this);
    Pluginlayout->addWidget(Plugin);
}
