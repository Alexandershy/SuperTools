#ifndef _SCANNERMODULEA__H
#define _SCANNERMODULEA__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ScannerModuleA;}
QT_END_NAMESPACE

class ScannerModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::ScannerModuleA *ui = nullptr;

public:

    ScannerModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ScannerModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _MODULEA__H
