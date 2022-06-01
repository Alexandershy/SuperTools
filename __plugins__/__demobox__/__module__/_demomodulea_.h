#ifndef _DEMOMODULEA__H
#define _DEMOMODULEA__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class DemoModuleA;}
QT_END_NAMESPACE

class DemoModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::DemoModuleA *ui = nullptr;

public:

    DemoModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~DemoModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _DEMOMODULEA__H
