#ifndef _CHATSHAREBOX__H
#define _CHATSHAREBOX__H

#include "_chatsharebox__ui_.h"
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatShareBox; }
QT_END_NAMESPACE

class ChatShareBox : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatShareBox *ui        = nullptr;
    QMenu *Itemoptions          = nullptr;
    QAction *Cancelshared       = nullptr;
    QAction *Downloadfile       = nullptr;
    QAction *Downloadfileas     = nullptr;
    QAction *Openpath           = nullptr;

public:

    ChatShareBox(
            QWidget *parent = nullptr);

    ~ChatShareBox();


private slots:

    void Init();

    void Pointerinit();

};

#endif // _CHATSHAREBOX__H
