#include "_supertextbrowser_.h"

SuperTextBrowser::SuperTextBrowser(QWidget *parent)
    : QTextBrowser(parent)
{
    Widget = parent;
    connect(this,&QTextBrowser::customContextMenuRequested,this,&SuperTextBrowser::Menushow);
    Init();
}

SuperTextBrowser::~SuperTextBrowser()
{

}

void SuperTextBrowser::Init()
{
    Parameterinit();
    Appendtextinit();
    Appendactioninit();
}

/*  textbrowser init;*/

void SuperTextBrowser::Parameterinit()
{
    SuperC = new SuperCore(this);
    setContextMenuPolicy(Qt::CustomContextMenu);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameShape(QFrame::NoFrame);
    Menu = createStandardContextMenu();
    Copy = Menu->actions().at(0);
    Copylinklocation = Menu->actions().at(1);
    Selectall = Menu->actions().at(3);
}

/*  change textbrowser parameter;*/

void SuperTextBrowser::Appendtextinit()
{
    QString texttemp = Widget->objectName();
    QString text = SuperC->Allwordlower(texttemp);
    append("here will display " + text + " textbrowser logs!!!");
}

/*  append textbrowser text init;*/

void SuperTextBrowser::Addaction(QAction *action,QString text,QString objectname)
{
    Menu->addSeparator();
    Menu->addAction(action);
    action->setText(text);
    action->setObjectName(objectname);
}

/*  add action;*/

void SuperTextBrowser::Appendactioninit()
{
    Clearbrowser = new QAction(this);
    Transfercodec = new QAction(this);
    Openfilepath = new QAction(this);
    Addaction(Clearbrowser,"Clear Browser","ClearBrowser");
    Addaction(Transfercodec,"Transfer Codec","TransferCodec");
    Addaction(Openfilepath,"Open Filepath","OpenFilepath");
}

/*  add super action;*/

void SuperTextBrowser::Menushowinit()
{
    Copy->setEnabled(!textCursor().selectedText().isEmpty());
    Selectall->setEnabled(!toHtml().isEmpty());
    Transfercodec->setEnabled(Enabletransfercodec);
}

/*  menu show init;*/

void SuperTextBrowser::Menushow()
{
    Menushowinit();
    Menu->exec(QCursor::pos());
}

/*  show menu;*/
