#include "_supertitlebutton_.h"

SuperTitleButton::SuperTitleButton(QWidget *parent)
    : QPushButton(parent)
{
    init();
    connect(this,&QPushButton::clicked,this,&SuperTitleButton::removeBackGroundColor);
}

SuperTitleButton::~SuperTitleButton()
{

}

void SuperTitleButton::enterEvent(QEnterEvent *)
{
    if(isEnabled())
    {
        addBackGroundColor();
    }
}

/*  emit signal for could move;*/

void SuperTitleButton::leaveEvent(QEvent *)
{
    if(isEnabled())
    {
        removeBackGroundColor();
    }
}

/*  emit signal for could not move;*/

void SuperTitleButton::init()
{
    sizeInit();
    styleSheetInit();
}

/*  init;*/

void SuperTitleButton::sizeInit()
{
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy1);
    setMinimumSize(QSize(24, 24));
    setMaximumSize(QSize(24, 24));
}

/*  size init;*/

void SuperTitleButton::styleSheetInit()
{
    setStyleSheet("QPushButton{border-style: none;background-color: transparent;}");
}

/*  stylesheetinit;*/

void SuperTitleButton::setSourceColor(QString rgbcolor)
{
    Rgbcolor = rgbcolor;
}

/*  set rgb color;*/

void SuperTitleButton::addBackGroundColor()
{
    setStyleSheet("QPushButton{border-style: none;background-color: " + Rgbcolor + ";}");
}

/*  remove color;*/

void SuperTitleButton::removeBackGroundColor()
{
    setStyleSheet("QPushButton{border-style: none;background-color: transparent;}");
}

/*  remove color;*/
