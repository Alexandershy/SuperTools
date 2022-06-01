#ifndef _LEDANALYSERMODULEA__H
#define _LEDANALYSERMODULEA__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class LedAnalyserModuleA;}
QT_END_NAMESPACE

class LedAnalyserModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::LedAnalyserModuleA *ui = nullptr;

public:

    LedAnalyserModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~LedAnalyserModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _LEDANALYSERMODULEA__H
