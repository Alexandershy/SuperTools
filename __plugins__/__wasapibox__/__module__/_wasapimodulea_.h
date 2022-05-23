#ifndef _WASAPIMODULEA__H
#define _WASAPIMODULEA__H

#include "ui__wasapimodulea_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class WasapiModuleA;}
QT_END_NAMESPACE

class WasapiModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::WasapiModuleA *ui = nullptr;

public:

    WasapiModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~WasapiModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _WASAPIMODULEA__H
