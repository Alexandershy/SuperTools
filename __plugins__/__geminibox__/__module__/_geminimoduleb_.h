#ifndef _GEMINIMODULEB__H
#define _GEMINIMODULEB__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class GeminiModuleB;}
QT_END_NAMESPACE

class GeminiModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::GeminiModuleB *ui = nullptr;

public:

    GeminiModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~GeminiModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _GEMINIMODULEB__H
