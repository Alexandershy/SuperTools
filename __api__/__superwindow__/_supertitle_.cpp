#include "_supertitle_.h"
#include "ui__supertitleui_.h"

SuperTitle::SuperTitle(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::SuperTitleui)
{
    ui->setupUi(this);
    init();
}

SuperTitle::~SuperTitle()
{
    delete ui;
}

void SuperTitle::mouseDoubleClickEvent(QMouseEvent *)
{
    emit signalSb();
}

/*  emit signal for change maxisize or normal;*/

void SuperTitle::enterEvent(QEnterEvent *)
{
    emit signalSa(true);
    emit signalSc(Qt::ArrowCursor);
}

/*  emit signal for could move;*/

void SuperTitle::leaveEvent(QEvent *)
{
    emit signalSa(false);
}

/*  emit signal for could not move;*/

void SuperTitle::init()
{
    objectInit();
}

/*  init;*/

void SuperTitle::objectInit()
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

void SuperTitle::setSourceColor(QString rgbcolor)
{
    Minisizebutton->setSourceColor(rgbcolor);
    Maxisizebutton->setSourceColor(rgbcolor);
}

/*  change title style sheet;*/
