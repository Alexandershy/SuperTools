#ifndef _LITEPOINTIQGIGIFMODULEB__H
#define _LITEPOINTIQGIGIFMODULEB__H

#include "ui__litepointiqgigifmoduleb_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class LitePointIQGigIfModuleB;}
QT_END_NAMESPACE

class LitePointIQGigIfModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::LitePointIQGigIfModuleB *ui = nullptr;

public:

    LitePointIQGigIfModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~LitePointIQGigIfModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

    void uiInit();

};

#endif // _LITEPOINTIQGIGIFMODULEB__H
