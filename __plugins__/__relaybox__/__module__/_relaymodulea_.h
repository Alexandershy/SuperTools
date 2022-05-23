#ifndef _RELAYMODULEA__H
#define _RELAYMODULEA__H

#include "ui__relaymodulea_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class RelayModuleA;}
QT_END_NAMESPACE

class RelayModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::RelayModuleA *ui = nullptr;

public:

    RelayModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~RelayModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _RELAYMODULEA__H
