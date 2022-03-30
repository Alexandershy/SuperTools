#include "_supertitlebutton_.h"

SuperTitleButton::SuperTitleButton(QWidget *parent)
    : QPushButton(parent)
{
    Init();
    connect(this,&QPushButton::clicked,this,&SuperTitleButton::Removebackgroundcolor);
}

SuperTitleButton::~SuperTitleButton()
{

}

void SuperTitleButton::enterEvent(QEnterEvent *)
{
    if(isEnabled())
    {
        Addbackgroundcolor();
    }
}

/*  emit signal for could move;*/

void SuperTitleButton::leaveEvent(QEvent *)
{
    if(isEnabled())
    {
        Removebackgroundcolor();
    }
}

/*  emit signal for could not move;*/

void SuperTitleButton::Init()
{
    Sizeinit();
    Stylesheetinit();
}

/*  init;*/

void SuperTitleButton::Sizeinit()
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

void SuperTitleButton::Stylesheetinit()
{
    setStyleSheet("QPushButton{border-style: none;background-color: transparent;}");
}

/*  stylesheetinit;*/

void SuperTitleButton::Setsourcecolor(QString rgbcolor)
{
    Rgbcolor = rgbcolor;
}

/*  set rgb color;*/

void SuperTitleButton::Addbackgroundcolor()
{
    setStyleSheet("QPushButton{border-style: none;background-color: " + Rgbcolor + ";}");
}

/*  remove color;*/

void SuperTitleButton::Removebackgroundcolor()
{
    setStyleSheet("QPushButton{border-style: none;background-color: transparent;}");
}

/*  remove color;*/
