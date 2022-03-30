#ifndef _MODULEA__H
#define _MODULEA__H

#include "__module__/_modulea__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ModuleA;}
QT_END_NAMESPACE

class ModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::ModuleA *ui = nullptr;

public:

    ModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void Init();

    void Parameterinit();

};

#endif // _MODULEA__H
