#include "_supertabwidget_.h"

SuperTabWidget::SuperTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    Init();
}

SuperTabWidget::~SuperTabWidget()
{

}

void SuperTabWidget::Init()
{
    Parameterinit();
}

/*  tab init;*/

void SuperTabWidget::Parameterinit()
{
    setStyleSheet("QTabWidget::pane{border-style:none;background: white}");
}

/*  style init;*/
