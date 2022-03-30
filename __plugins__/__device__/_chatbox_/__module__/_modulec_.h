#ifndef _MODULEC__H
#define _MODULEC__H

#include "__module__/_modulec__ui_.h"

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

    void Uiinit();

};

#endif // _MODULEC__H
