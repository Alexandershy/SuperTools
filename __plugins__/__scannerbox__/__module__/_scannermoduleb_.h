#ifndef _SCANNERMODULEB__H
#define _SCANNERMODULEB__H

#include "ui__scannermoduleb_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ScannerModuleB;}
QT_END_NAMESPACE

class ScannerModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::ScannerModuleB *ui = nullptr;

public:

    ScannerModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ScannerModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _SCANNERMODULEB__H
