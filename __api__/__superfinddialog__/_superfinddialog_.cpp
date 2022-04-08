#include "_superfinddialog_.h"

SuperFindDialog::SuperFindDialog(QWidget *parent,QTextBrowser *textbrowser)
    :SuperWindow(parent)
{
    Textbrowser = textbrowser;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Disablemaxisize();
    Settitle("Super FindDialog");
    Init();
}

SuperFindDialog::~SuperFindDialog()
{

}

void SuperFindDialog::Init()
{
    Objectinit();
    Parameterinit();
}

void SuperFindDialog::Objectinit()
{
    Plugin = new SuperFindDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,          this,&SuperFindDialog::Findnexttext);
    connect(Plugin->ui->comboBox,       &QComboBox::textActivated,      this,&SuperFindDialog::Findnexttext);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,          this,&SuperFindDialog::Findlasttext);
    connect(Plugin->ui->comboBox,       &QComboBox::currentTextChanged, this,&SuperFindDialog::Enablenextbutton);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,          this,&SuperFindDialog::close);
}

/*  creat object and connect its slot;*/

void SuperFindDialog::Parameterinit()
{
    Plugin->ui->comboBox->setFocus();
}

/*  parameter init;*/

void SuperFindDialog::Enablenextbutton()
{
    if(Plugin->ui->comboBox->currentText().isEmpty())
    {
        Plugin->ui->pushButton_3->setEnabled(false);
        Plugin->ui->pushButton->setEnabled(false);
    }
    else
    {
        Plugin->ui->pushButton_3->setEnabled(true);
        Plugin->ui->pushButton->setEnabled(true);
    }
}

/*  enable button or not;*/

void SuperFindDialog::Highlightpalette(QWidget *widget)
{
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
    widget->setPalette(palette);
}

/*  high light next text;*/

void SuperFindDialog::Findnexttext()
{
    QString text = Plugin->ui->comboBox->currentText();
    if(Textbrowser->find(text))
    {
        Highlightpalette(Textbrowser);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"cannot find \"" + text + "\";,\nclick ok move to start;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFindDialog::Movetostart);
        notedialog->Messageinit();
    }
}

/*  find next text;*/

void SuperFindDialog::Findlasttext()
{
    QString text = Plugin->ui->comboBox->currentText();
    if(Textbrowser->find(text,QTextDocument::FindBackward))
    {
        Highlightpalette(Textbrowser);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"cannot find \"" + text + "\";,\nclick ok move to end;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFindDialog::Movetoend);
        notedialog->Messageinit();
    }
}

/*  find last text;*/

void SuperFindDialog::Movetostart()
{
    Textbrowser->moveCursor(Textbrowser->textCursor().Start);
}

/*  move text cursor to start;*/

void SuperFindDialog::Movetoend()
{
    Textbrowser->moveCursor(Textbrowser->textCursor().End);
}

/*  move text cursor to end;*/


