#ifndef _TCPSERVERMODULEB__H
#define _TCPSERVERMODULEB__H

#include "ui__tcpservermoduleb_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class TcpServerModuleB;}
QT_END_NAMESPACE

class TcpServerModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::TcpServerModuleB *ui = nullptr;

public:

    TcpServerModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~TcpServerModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _MODULEB__H
