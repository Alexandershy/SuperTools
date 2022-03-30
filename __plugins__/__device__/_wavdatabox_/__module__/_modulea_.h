#ifndef _MODULEA__H
#define _MODULEA__H

#include "__supercore__/_supercore_.h"
#include "__supermultimedia__/_supermultimedia_.h"
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

public slots:

    void Checkdefaultdevice();

private:

    SuperMultiMedia *SuperM         = nullptr;
    QMediaDevices *Mediadevices     = nullptr;
    QLayout *Layout                 = nullptr;

private slots:

    /*  main function;*/

    void Init();

    void Iconinit();

    void Objectinit();

    void Parameterinit();

    void Checkdevicechanged();

signals:

    void Signalwa();

    void Signalwb();

};

#endif // _MODULEA__H
