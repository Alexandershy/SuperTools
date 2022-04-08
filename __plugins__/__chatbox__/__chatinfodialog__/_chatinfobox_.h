#ifndef _CHATINFO__H
#define _CHATINFO__H

#include "_chatinfobox__ui_.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChatInfoBox; }
QT_END_NAMESPACE

class ChatInfoBox : public QFrame
{
    Q_OBJECT

public:

    Ui::ChatInfoBox *ui = nullptr;

public:

    ChatInfoBox(
            QWidget *parent = nullptr);

    ~ChatInfoBox();

};

#endif // _CHATINFO__H
