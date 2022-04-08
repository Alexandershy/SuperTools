#include "_superfinddialog_.h"

SuperFindDialog::SuperFindDialog(QWidget *parent,QTextEdit *textedit)
    :SuperWindow(parent)
{
    Widgetindex = 0;
    Textedit = textedit;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Disablemaxisize();
    Settitle("Super FindDialog");
    Init();
}

SuperFindDialog::SuperFindDialog(QWidget *parent,QTextBrowser *textbrowser)
    :SuperWindow(parent)
{
    Widgetindex = 1;
    Textbrowser = textbrowser;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    Disablemaxisize();
    Settitle("search dialog");
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
    Plugin = new SuperFindBox(this);
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
    switch (Widgetindex)
    {
        case 0:
        {
            if(Textedit->find(text))
            {
                Highlightpalette(Textedit);
            }
            else
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"cannot find \"" + text + "\";,\nclick ok move to start;");
                connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFindDialog::Movetostart);
                notedialog->Messageinit();
            }
            break;
        }
        case 1:
        {
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
            break;
        }
    }
}

/*  find next text;*/

void SuperFindDialog::Findlasttext()
{
    QString text = Plugin->ui->comboBox->currentText();
    switch (Widgetindex)
    {
        case 0:
        {
            if(Textedit->find(text,QTextDocument::FindBackward))
            {
                Highlightpalette(Textedit);
            }
            else
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"cannot find \"" + text + "\";,\nclick ok move to end;");
                connect(notedialog,&SuperNoteDialog::Signalnb,this,&SuperFindDialog::Movetoend);
                notedialog->Messageinit();
            }
            break;
        }
        case 1:
        {
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
            break;
        }
    }
}

/*  find last text;*/

void SuperFindDialog::Movetostart()
{
    switch(Widgetindex)
    {
        case 0:
        {
            Textedit->moveCursor(Textedit->textCursor().Start);
            break;
        }
        case 1:
        {
            Textbrowser->moveCursor(Textbrowser->textCursor().Start);
            break;
        }
    }
}

/*  move text cursor to start;*/

void SuperFindDialog::Movetoend()
{
    switch(Widgetindex)
    {
        case 0:
        {
            Textedit->moveCursor(Textedit->textCursor().End);
            break;
        }
        case 1:
        {
            Textbrowser->moveCursor(Textbrowser->textCursor().End);
            break;
        }
    }
}

/*  move text cursor to end;*/


