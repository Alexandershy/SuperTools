#ifndef _CHATMODULEA__H
#define _CHATMODULEA__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ChatModuleA;}
QT_END_NAMESPACE

class ChatModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatModuleA *ui = nullptr;

public:

    ChatModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~ChatModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _CHATMODULEA__H
