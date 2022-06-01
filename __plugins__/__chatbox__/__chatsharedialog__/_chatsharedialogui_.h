#ifndef _CHATSHAREDIALOGUI__H
#define _CHATSHAREDIALOGUI__H

#include <QMenu>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatShareDialogui; }
QT_END_NAMESPACE

class ChatShareDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatShareDialogui *ui   = nullptr;
    QMenu *Itemoptions          = nullptr;
    QAction *Cancelshared       = nullptr;
    QAction *Downloadfile       = nullptr;
    QAction *Downloadfileas     = nullptr;
    QAction *Openpath           = nullptr;

public:

    ChatShareDialogui(
            QWidget *parent = nullptr);

    ~ChatShareDialogui();


private slots:

    void init();

    void pointerInit();

};

#endif // _CHATSHAREDIALOGUI__H
