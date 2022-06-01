#ifndef _TCPCLIENTMODULEA__H
#define _TCPCLIENTMODULEA__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class TcpClientModuleA;}
QT_END_NAMESPACE

class TcpClientModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::TcpClientModuleA *ui = nullptr;

public:

    TcpClientModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~TcpClientModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _TCPCLIENTMODULEA__H
