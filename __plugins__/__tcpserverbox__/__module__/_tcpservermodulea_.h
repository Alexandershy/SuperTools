#ifndef _TCPSERVERMODULEA__H
#define _TCPSERVERMODULEA__H

#include "ui__tcpservermodulea_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class TcpServerModuleA;}
QT_END_NAMESPACE

class TcpServerModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::TcpServerModuleA *ui = nullptr;

public:

    TcpServerModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~TcpServerModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _TCPSERVERMODULEA__H
