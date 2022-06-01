#include "_superfinddialog_.h"
#include "ui__superfinddialogui_.h"

SuperFindDialog::SuperFindDialog(QWidget *parent,QTextEdit *textedit)
    :SuperWindow(parent)
{
    Textedit = textedit;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::ApplicationModal);
    disableMaxisize();
    setTitle("SuperFindDialog");
    init();
}

SuperFindDialog::~SuperFindDialog()
{

}

void SuperFindDialog::init()
{
    objectInit();
    parameterInit();
}

void SuperFindDialog::objectInit()
{
    Plugin = new SuperFindDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,          this,&SuperFindDialog::findNextText);
    connect(Plugin->ui->comboBox,       &QComboBox::textActivated,      this,&SuperFindDialog::findNextText);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,          this,&SuperFindDialog::findLastText);
    connect(Plugin->ui->comboBox,       &QComboBox::currentTextChanged, this,&SuperFindDialog::enableNextButton);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,          this,&SuperFindDialog::close);
}

/*  creat object and connect its slot;*/

void SuperFindDialog::parameterInit()
{
    Plugin->ui->comboBox->setFocus();
}

/*  parameter init;*/

void SuperFindDialog::enableNextButton()
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

void SuperFindDialog::highLightPalette(QWidget *widget)
{
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
    widget->setPalette(palette);
}

/*  high light next text;*/

void SuperFindDialog::findNextText()
{
    QString text = Plugin->ui->comboBox->currentText();
    if(Textedit->find(text))
    {
        highLightPalette(Textedit);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"cannot find \"" + text + "\";,\nclick ok move to start;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFindDialog::moveToStart);
        notedialog->messageInit();
    }
}

/*  find next text;*/

void SuperFindDialog::findLastText()
{
    QString text = Plugin->ui->comboBox->currentText();
    if(Textedit->find(text,QTextDocument::FindBackward))
    {
        highLightPalette(Textedit);
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"cannot find \"" + text + "\";,\nclick ok move to end;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&SuperFindDialog::moveToEnd);
        notedialog->messageInit();
    }
}

/*  find last text;*/

void SuperFindDialog::moveToStart()
{
    Textedit->moveCursor(Textedit->textCursor().Start);
}

/*  move text cursor to start;*/

void SuperFindDialog::moveToEnd()
{
    Textedit->moveCursor(Textedit->textCursor().End);
}

/*  move text cursor to end;*/


