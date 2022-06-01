#ifndef _WASAPIMODULEC__H
#define _WASAPIMODULEC__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class WasapiModuleC;}
QT_END_NAMESPACE

class WasapiModuleC : public QFrame
{
    Q_OBJECT

public:

    Ui::WasapiModuleC *ui = nullptr;

public:

    WasapiModuleC(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~WasapiModuleC();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _WASAPIMODULEC__H
