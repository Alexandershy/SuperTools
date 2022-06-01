#ifndef _SERIALPORTMODULEB__H
#define _SERIALPORTMODULEB__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SerialPortModuleB;}
QT_END_NAMESPACE

class SerialPortModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::SerialPortModuleB *ui = nullptr;

public:

    SerialPortModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~SerialPortModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

    void uiInit();

};

#endif // _SERIALPORTMODULEB__H
