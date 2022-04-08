#include "_supernotedialog_.h"

SuperNoteDialog::SuperNoteDialog(QWidget *parent,QString filestring)
    : SuperWindow(parent)
{
    Filestring = filestring;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Settitle("Super NoteDialog");
    Init();
}

SuperNoteDialog::~SuperNoteDialog()
{

}

void SuperNoteDialog::Init()
{
    Objectinit();
}

void SuperNoteDialog::Objectinit()
{
    Plugin = new SuperNoteDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,this,&SuperNoteDialog::Signalna);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,this,&SuperNoteDialog::Signalnb);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,this,&SuperNoteDialog::deleteLater);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,this,&SuperNoteDialog::deleteLater);
}

/*  creat object and connect its slot;*/

void SuperNoteDialog::Noteinit()
{
    Hidebutton();
    setMinimumSize({900,600});
    Plugin->ui->textBrowser->setHtml(Filestring);
    Show();
}

/*  set as note mode;*/

void SuperNoteDialog::Messageinit()
{
    setMinimumSize({300,100});
    Disablemaxisize();
    Plugin->ui->textBrowser->setAlignment(Qt::AlignCenter);
    Plugin->ui->textBrowser->setContextMenuPolicy(Qt::NoContextMenu);
    QStringList message = Filestring.split("\n");
    for(int i = 0;i < message.count();i++)
    {
        Plugin->ui->textBrowser->append(message.at(i));
    }
    Show();
}

/*  set as message box mode;*/

void SuperNoteDialog::Hidebutton()
{
    Hideleftbutton();
    Hiderightbutton();
}

/*  hide all button;*/

void SuperNoteDialog::Hideleftbutton()
{
    Plugin->ui->pushButton->setHidden(true);
}

/*  hide left button;*/

void SuperNoteDialog::Hiderightbutton()
{
    Plugin->ui->pushButton_2->setHidden(true);
}

/*  hide right button;*/


