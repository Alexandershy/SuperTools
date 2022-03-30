#ifndef _MODULEB__H
#define _MODULEB__H

#include "__module__/_moduleb__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ModuleB;}
QT_END_NAMESPACE

class ModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::ModuleB *ui = nullptr;

public:

    ModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void Init();

    void Parameterinit();

};

#endif // _MODULEB__H
