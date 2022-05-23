#ifndef _CHATMODULED__H
#define _CHATMODULED__H

#include "ui__chatmoduled_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ChatModuleD;}
QT_END_NAMESPACE

class ChatModuleD : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatModuleD *ui = nullptr;

public:

    ChatModuleD(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ChatModuleD();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

    void iconInit();

};

#endif // _CHATMODULED__H
