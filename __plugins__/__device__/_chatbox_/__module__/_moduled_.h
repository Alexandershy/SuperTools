#ifndef _MODULED__H
#define _MODULED__H

#include "__module__/_moduled__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ModuleD;}
QT_END_NAMESPACE

class ModuleD : public QFrame
{
    Q_OBJECT

public:

    Ui::ModuleD *ui = nullptr;

public:

    ModuleD(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ModuleD();

private:

    QLayout *Layout = nullptr;

private slots:

    void Init();

    void Parameterinit();

    void Iconinit();

};

#endif // _MODULED__H
