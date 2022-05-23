#ifndef _WASAPIMODULEB__H
#define _WASAPIMODULEB__H

#include "ui__wasapimoduleb_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class WasapiModuleB;}
QT_END_NAMESPACE

class WasapiModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::WasapiModuleB *ui = nullptr;

public:

    WasapiModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~WasapiModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};


#endif // _WASAPIMODULEB__H
