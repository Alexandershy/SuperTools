#include "_supertabwidget_.h"

SuperTabWidget::SuperTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    init();
}

SuperTabWidget::~SuperTabWidget()
{

}

void SuperTabWidget::init()
{
    parameterInit();
}

/*  tab init;*/

void SuperTabWidget::parameterInit()
{
    setStyleSheet("QTabWidget::pane{border-style:none;background: white}");
}

/*  style init;*/
