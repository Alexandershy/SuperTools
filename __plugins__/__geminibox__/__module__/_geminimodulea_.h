#ifndef _GEMINIMODULEA__H
#define _GEMINIMODULEA__H

#include "ui__geminimodulea_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class GeminiModuleA;}
QT_END_NAMESPACE

class GeminiModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::GeminiModuleA *ui = nullptr;

public:

    GeminiModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~GeminiModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _GEMINIMODULEA__H
