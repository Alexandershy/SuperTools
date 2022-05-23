#ifndef _TCPCLIENTMODULEB__H
#define _TCPCLIENTMODULEB__H

#include "ui__tcpclientmoduleb_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class TcpClientModuleB;}
QT_END_NAMESPACE

class TcpClientModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::TcpClientModuleB *ui = nullptr;

public:

    TcpClientModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~TcpClientModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

    void uiInit();

};

#endif // _MODULEB__H
