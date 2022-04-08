#include "_superlineedit_.h"

SuperLineEdit::SuperLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    Widget = parent;
    Init();
}

SuperLineEdit::~SuperLineEdit()
{

}

void SuperLineEdit::Init()
{
    Objectinit();
    Parameterinit();
    Appendtextinit();
}

/*  lineedit init;*/

void SuperLineEdit::Objectinit()
{
    SuperC = new SuperCore(this);
}

/*  object init;*/

void SuperLineEdit::Parameterinit()
{
    setFrame(false);
    setReadOnly(true);
    setClearButtonEnabled(true);
    setMinimumSize(80,20);
    setMaximumSize(16777215,20);
}

/*  parameter init;*/

void SuperLineEdit::Appendtextinit()
{
    QString texttemp = Widget->objectName();
    QString text = SuperC->Allwordlower(texttemp);
    setText("here will display " + text + " programe run logs!!!");
}
