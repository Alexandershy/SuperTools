#ifndef _LITEPOINTIQGIGIFMODULEA__H
#define _LITEPOINTIQGIGIFMODULEA__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class LitePointIQGigIfModuleA;}
QT_END_NAMESPACE

class LitePointIQGigIfModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::LitePointIQGigIfModuleA *ui = nullptr;

public:

    LitePointIQGigIfModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~LitePointIQGigIfModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _LITEPOINTIQGIGIFMODULEA__H
