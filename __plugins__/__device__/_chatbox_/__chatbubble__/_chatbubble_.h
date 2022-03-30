#ifndef _CHATBUBBLE__H
#define _CHATBUBBLE__H

#include <QTextEdit>
#include <QScrollBar>
#include <QFontMetrics>

class ChatBubble : public QTextEdit
{

public:

    ChatBubble(
            QWidget *parent = nullptr,
            QString message = "");

    ~ChatBubble();

    void Adjustwidth();

    void Adjustheight();

private slots:

    void Init();

private:

    QWidget *Parent = nullptr;

};

#endif // _CHATBUBBLE__H
