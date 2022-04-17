#ifndef _MODULEC__H
#define _MODULEC__H

#include "ui__modulec_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ModuleC;}
QT_END_NAMESPACE

class ModuleC : public QFrame
{
    Q_OBJECT

public:

    Ui::ModuleC *ui = nullptr;

public:

    ModuleC(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ModuleC();

private:

    QLayout *Layout = nullptr;

private slots:

    void Init();

    void Parameterinit();

};

#endif // _MODULEC__H
