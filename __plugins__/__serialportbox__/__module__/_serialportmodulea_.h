#ifndef _SERIALPORTMODULEA__H
#define _SERIALPORTMODULEA__H

#include "ui__serialportmodulea_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SerialPortModuleA;}
QT_END_NAMESPACE

class SerialPortModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::SerialPortModuleA *ui = nullptr;

public:

    SerialPortModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~SerialPortModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _SERIALPORTMODULEA__H
