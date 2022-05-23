#include "_superlogger_.h"

SuperLogger::SuperLogger(QWidget *parent,QLayout *layout)
    : QWidget(parent)
{
    Widget = parent;
    Layout = layout;
    init();
}

SuperLogger::~SuperLogger()
{

}

void SuperLogger::init()
{
    objectInit();
    addInit();
}

/*  init;*/

void SuperLogger::objectInit()
{
    Core = new SuperCore(this);
    Textbrowser = new SuperTextBrowser(Widget);
    Lineedit = new SuperLineEdit(Widget);
    connect(Textbrowser->Clearbrowser,&QAction::triggered,this,&SuperLogger::clearTextBrowser);
    connect(Textbrowser->Transfercodec,&QAction::triggered,this,&SuperLogger::transferCodecs);
    connect(Textbrowser->Openfilepath,&QAction::triggered,this,&SuperLogger::openFilePath);
}

/*  objectinit;*/

void SuperLogger::addInit()
{
    Layout->addWidget(Textbrowser);
    Layout->addWidget(Lineedit);
}

/*  addinit;*/

void SuperLogger::displayLog(QString direction, QString strtlog, QString strllog)
{
    QString daytime = QDateTime::currentDateTime().toString("yyyyMMdd");
    QString secondtime = QTime::currentTime().toString();
    strtlog = secondtime + displayLogDirection(direction) +  strtlog;
    Textbrowser->append(strtlog);
    Lineedit->setText(strllog);
    Textbrowser->moveCursor(Textbrowser->textCursor().End);
    Core->appendFile(Filepath + daytime + " _" + Core->allWordLower(Widget->objectName()) + "_.txt",strtlog + "\n");
}

/*  display logs on textbrowser editline and append to log.txt, enable clear button;*/

QString SuperLogger::displayLogDirection(QString direction)
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

void SuperLogger::clearTextBrowser()
{
    Textbrowser->clear();
    Lineedit->setText("Cleartextbrowser function run completed");
    Textbrowser->append("here will display " + Core->allWordLower(Widget->objectName()) + " textbrowser logs!!!");
}

/*  clear logs on textbrowser and set init states;*/

void SuperLogger::addTransferCodec()
{
    Textbrowser->Enabletransfercodec = true;
}

/*  enable transfer codec;*/

void SuperLogger::transferCodecs()
{
    QString text = QTextCodec::codecForName("GBK")->toUnicode(Result);
    if(text.isEmpty())
    {
        displayLog("N","need generate new result;","Transfercodecs function run completed");
    }
    else
    {
        displayLog("R",text,"Transfercodecs function run completed");
    }
}

/*  retransfer codec;*/

void SuperLogger::openFilePath()
{
    Core->openPath(Filepath);
}

/*  retransfer codec;*/
