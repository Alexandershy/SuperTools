#include "_superlogger_.h"

SuperLogger::SuperLogger(QWidget *parent,QLayout *layout)
    : QWidget(parent)
{
    Widget = parent;
    Layout = layout;
    Init();
}

SuperLogger::~SuperLogger()
{

}

void SuperLogger::Init()
{
    Objectinit();
    Addinit();
}

/*  init;*/

void SuperLogger::Objectinit()
{
    Core = new SuperCore(this);
    Textbrowser = new SuperTextBrowser(Widget);
    Lineedit = new SuperLineEdit(Widget);
    connect(Textbrowser->Clearbrowser,&QAction::triggered,this,&SuperLogger::Cleartextbrowser);
    connect(Textbrowser->Transfercodec,&QAction::triggered,this,&SuperLogger::Transfercodecs);
    connect(Textbrowser->Openfilepath,&QAction::triggered,this,&SuperLogger::Openfilepath);
}

/*  objectinit;*/

void SuperLogger::Addinit()
{
    Layout->addWidget(Textbrowser);
    Layout->addWidget(Lineedit);
}

/*  addinit;*/

void SuperLogger::Displaylog(QString direction, QString strtlog, QString strllog)
{
    QString daytime = QDateTime::currentDateTime().toString("yyyyMMdd");
    QString secondtime = QTime::currentTime().toString();
    strtlog = secondtime + Displaylogdirection(direction) +  strtlog;
    Textbrowser->append(strtlog);
    Lineedit->setText(strllog);
    Textbrowser->moveCursor(Textbrowser->textCursor().End);
    Core->Appendfile(Filepath + daytime + " _" + Core->Allwordlower(Widget->objectName()) + "_.txt",strtlog + "\n");
}

/*  display logs on textbrowser editline and append to log.txt, enable clear button;*/

QString SuperLogger::Displaylogdirection(QString direction)
{
    if(direction == "N")
    {
        return " ";
    }
    else if(direction == "R")
    {
        return " <<<---  ";
    }
    else
    {
        return " --->>>  ";
    }
}

void SuperLogger::Cleartextbrowser()
{
    Textbrowser->clear();
    Lineedit->setText("Cleartextbrowser function run completed");
    Textbrowser->append("here will display " + Core->Allwordlower(Widget->objectName()) + " textbrowser logs!!!");
}

/*  clear logs on textbrowser and set init states;*/

void SuperLogger::Addtransfercodec()
{
    Textbrowser->Enabletransfercodec = true;
}

/*  enable transfer codec;*/

void SuperLogger::Transfercodecs()
{
    QString text = QTextCodec::codecForName("GBK")->toUnicode(Result);
    if(text.isEmpty())
    {
        Displaylog("N","need generate new result;","Transfercodecs function run completed");
    }
    else
    {
        Displaylog("R",text,"Transfercodecs function run completed");
    }
}

/*  retransfer codec;*/

void SuperLogger::Openfilepath()
{
    Core->Openpath(Filepath);
}

/*  retransfer codec;*/
