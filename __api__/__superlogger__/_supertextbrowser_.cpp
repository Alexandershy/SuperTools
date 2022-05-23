#include "_supertextbrowser_.h"

SuperTextBrowser::SuperTextBrowser(QWidget *parent)
    : QTextBrowser(parent)
{
    Widget = parent;
    connect(this,&QTextBrowser::customContextMenuRequested,this,&SuperTextBrowser::menuShow);
    init();
}

SuperTextBrowser::~SuperTextBrowser()
{

}

void SuperTextBrowser::init()
{
    parameterInit();
    appendTextInit();
    appendActionInit();
}

/*  textbrowser init;*/

void SuperTextBrowser::parameterInit()
{
    Core = new SuperCore(this);
    setContextMenuPolicy(Qt::CustomContextMenu);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameShape(QFrame::NoFrame);
    Menu = createStandardContextMenu();
    Copy = Menu->actions().at(0);
    Copylinklocation = Menu->actions().at(1);
    Selectall = Menu->actions().at(3);
}

/*  change textbrowser parameter;*/

void SuperTextBrowser::appendTextInit()
{
    QString texttemp = Widget->objectName();
    QString text = Core->allWordLower(texttemp);
    append("here will display " + text + " textbrowser logs!!!");
}

/*  append textbrowser text init;*/

void SuperTextBrowser::addAction(QAction *action,QString text,QString objectname)
{
    Menu->addSeparator();
    Menu->addAction(action);
    action->setText(text);
    action->setObjectName(objectname);
}

/*  add action;*/

void SuperTextBrowser::appendActionInit()
{
    Clearbrowser = new QAction(this);
    Transfercodec = new QAction(this);
    Openfilepath = new QAction(this);
    addAction(Clearbrowser,"Clear Browser","ClearBrowser");
    addAction(Transfercodec,"Transfer Codec","TransferCodec");
    addAction(Openfilepath,"Open Filepath","OpenFilepath");
}

/*  add super action;*/

void SuperTextBrowser::menuShowInit()
{
    Copy->setEnabled(!textCursor().selectedText().isEmpty());
    Selectall->setEnabled(!toHtml().isEmpty());
    Transfercodec->setEnabled(Enabletransfercodec);
}

/*  menu show init;*/

void SuperTextBrowser::menuShow()
{
    menuShowInit();
    Menu->exec(QCursor::pos());
}

/*  show menu;*/
