#include "_routdialog_.h"

RoutDialog::RoutDialog(QWidget *parent)
    : SuperWindow(parent)
{
    Init();
    Settitle("Rout dialog");
}

RoutDialog::~RoutDialog()
{

}

void RoutDialog::Init()
{
    Objectinit();
}

void RoutDialog::Objectinit()
{
    Plugin = new RoutBox(this);
    Pluginlayout->addWidget(Plugin);
}
