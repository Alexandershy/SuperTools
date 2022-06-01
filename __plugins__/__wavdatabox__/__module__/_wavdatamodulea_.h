#ifndef _WAVDATAMODULEA__H
#define _WAVDATAMODULEA__H

#include "__supercore__/_supercore_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class WavdataModuleA;}
QT_END_NAMESPACE

class WavdataModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::WavdataModuleA *ui = nullptr;

public:

    WavdataModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~WavdataModuleA();

public slots:

    void checkDefaultDevice();

private:

    SuperMultiMedia *Multimedia     = nullptr;
    QMediaDevices *Mediadevices     = nullptr;
    QLayout *Layout                 = nullptr;

private slots:

    /*  main function;*/
    void init();

    void iconInit();

    void objectInit();

    void parameterInit();

    void checkDeviceChanged();

signals:

    void signalWa();

    void signalWb();

};

#endif // _WAVDATAMODULEA__H
