#ifndef _DEMOMODULEB__H
#define _DEMOMODULEB__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class DemoModuleB;}
QT_END_NAMESPACE

class DemoModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::DemoModuleB *ui = nullptr;

public:

    DemoModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~DemoModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};


#endif // _DEMOMODULEB__H
