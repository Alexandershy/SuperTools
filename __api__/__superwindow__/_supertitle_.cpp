#include "_supertitle_.h"

SuperTitle::SuperTitle(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperTitleui)
{
    ui->setupUi(this);
    Init();
}

SuperTitle::~SuperTitle()
{
    delete ui;
}

void SuperTitle::mouseDoubleClickEvent(QMouseEvent *)
{
    emit Signalsb();
}

/*  emit signal for change maxisize or normal;*/

void SuperTitle::enterEvent(QEnterEvent *)
{
    emit Signalsa(true);
    emit Signalsc(Qt::ArrowCursor);
}

/*  emit signal for could move;*/

void SuperTitle::leaveEvent(QEvent *)
{
    emit Signalsa(false);
}

/*  emit signal for could not move;*/

void SuperTitle::Init()
{
    Objectinit();
}

/*  init;*/

void SuperTitle::Objectinit()
{
    Minisizebutton = new SuperTitleButton(this);
    Maxisizebutton = new SuperTitleButton(this);
    Closebutton = new SuperTitleButton(this);
    ui->horizontalLayout_6->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    ui->horizontalLayout_6->addWidget(Minisizebutton);
    ui->horizontalLayout_6->addWidget(Maxisizebutton);
    ui->horizontalLayout_6->addWidget(Closebutton);
}

/*  object init;*/

void SuperTitle::Setsourcecolor(QString rgbcolor)
{
    Minisizebutton->Setsourcecolor(rgbcolor);
    Maxisizebutton->Setsourcecolor(rgbcolor);
}

/*  change title style sheet;*/
