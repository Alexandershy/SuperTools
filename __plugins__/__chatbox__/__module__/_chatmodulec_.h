#ifndef _CHATMODULEC__H
#define _CHATMODULEC__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ChatModuleC;}
QT_END_NAMESPACE

class ChatModuleC : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatModuleC *ui = nullptr;

public:

    ChatModuleC(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ChatModuleC();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

    void uiInit();

};

#endif // _CHATMODULEC__H
