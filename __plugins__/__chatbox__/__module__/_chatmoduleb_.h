#ifndef _CHATMODULEB__H
#define _CHATMODULEB__H

#include "ui__chatmoduleb_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ChatModuleB;}
QT_END_NAMESPACE

class ChatModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatModuleB *ui = nullptr;

public:

    ChatModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ChatModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _CHATMODULEB__H
