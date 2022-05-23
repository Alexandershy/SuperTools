#include "_superlineedit_.h"

SuperLineEdit::SuperLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    Widget = parent;
    init();
}

SuperLineEdit::~SuperLineEdit()
{

}

void SuperLineEdit::init()
{
    objectInit();
    parameterInit();
    appendTextInit();
}

/*  lineedit init;*/

void SuperLineEdit::objectInit()
{
    Core = new SuperCore(this);
}

/*  object init;*/

void SuperLineEdit::parameterInit()
{
    setFrame(false);
    setReadOnly(true);
    setClearButtonEnabled(true);
    setMinimumSize(80,20);
    setMaximumSize(16777215,20);
}

/*  parameter init;*/

void SuperLineEdit::appendTextInit()
{
    QString texttemp = Widget->objectName();
    QString text = Core->allWordLower(texttemp);
    setText("here will display " + text + " programe run logs!!!");
}
