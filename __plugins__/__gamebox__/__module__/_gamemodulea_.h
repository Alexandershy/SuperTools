#ifndef _MODULEA__H
#define _MODULEA__H

#include "ui__gamemodulea_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class GameModuleA;}
QT_END_NAMESPACE

class GameModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::GameModuleA *ui = nullptr;

public:

    GameModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~GameModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _MODULEA__H
