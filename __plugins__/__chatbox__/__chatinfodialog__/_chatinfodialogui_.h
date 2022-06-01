#ifndef _CHATINFODIALOGUI__H
#define _CHATINFODIALOGUI__H

#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatInfoDialogui; }
QT_END_NAMESPACE

class ChatInfoDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatInfoDialogui *ui = nullptr;

public:

    ChatInfoDialogui(
            QWidget *parent = nullptr);

    ~ChatInfoDialogui();

};

#endif // _CHATINFODIALOGUI__H
