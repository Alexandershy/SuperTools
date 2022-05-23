#ifndef _LEDANALYSERMODULEB__H
#define _LEDANALYSERMODULEB__H

#include "ui__ledanalysermoduleb_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class LedAnalyserModuleB;}
QT_END_NAMESPACE

class LedAnalyserModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::LedAnalyserModuleB *ui = nullptr;

public:

    LedAnalyserModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~LedAnalyserModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _LEDANALYSERMODULEB__H
