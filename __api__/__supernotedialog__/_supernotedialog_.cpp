#include "_supernotedialog_.h"
#include "ui__supernotedialogui_.h"

SuperNoteDialog::SuperNoteDialog(QWidget *parent,QString filestring)
    : SuperWindow(parent)
{
    Filestring = filestring;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    setTitle("SuperNoteDialog");
    init();
}

SuperNoteDialog::~SuperNoteDialog()
{

}

void SuperNoteDialog::init()
{
    objectInit();
}

void SuperNoteDialog::objectInit()
{
    Plugin = new SuperNoteDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,this,&SuperNoteDialog::signalNa);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,this,&SuperNoteDialog::signalNb);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,this,&SuperNoteDialog::deleteLater);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,this,&SuperNoteDialog::deleteLater);
}

/*  creat object and connect its slot;*/

void SuperNoteDialog::noteInit()
{
    hideButton();
    setMinimumSize({900,600});
    Plugin->ui->textBrowser->setHtml(Filestring);
    show();
}

/*  set as note mode;*/

void SuperNoteDialog::messageInit()
{
    setMinimumSize({300,100});
    disableMaxisize();
    Plugin->ui->textBrowser->setAlignment(Qt::AlignCenter);
    Plugin->ui->textBrowser->setContextMenuPolicy(Qt::NoContextMenu);
    QStringList message = Filestring.split("\n");
    for(int i = 0;i < message.count();i++)
    {
        Plugin->ui->textBrowser->append(message.at(i));
    }
    show();
}

/*  set as message box mode;*/

void SuperNoteDialog::hideButton()
{
    hideLeftButton();
    hideRightButton();
}

/*  hide all button;*/

void SuperNoteDialog::hideLeftButton()
{
    Plugin->ui->pushButton->setHidden(true);
}

/*  hide left button;*/

void SuperNoteDialog::hideRightButton()
{
    Plugin->ui->pushButton_2->setHidden(true);
}

/*  hide right button;*/


