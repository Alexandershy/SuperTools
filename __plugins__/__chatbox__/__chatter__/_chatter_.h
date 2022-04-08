#ifndef _CHATTER__H
#define _CHATTER__H

#include "__chatbubble__/_chatbubble_.h"
#include "__chatuser__/_chatuser_.h"
#include "__chatter__/_chatter__ui_.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Chatter; }
QT_END_NAMESPACE

class Chatter : public QWidget
{

    Q_OBJECT

public:

    Chatter(
            QWidget *parent = nullptr,
            QString role = "self",
            QString username = "username",
            QString message = "");

    ~Chatter();

    void Adjustsize();

private:

    Ui::Chatter *ui     = nullptr;
    QWidget *Parent     = nullptr;
    QString Role        = "self";
    QString Message     = "";
    QString Username    = "";
    ChatUser *User      = nullptr;
    ChatBubble *Bubble  = nullptr;
    QTimer *Timer       = nullptr;


private slots:

    void Init();

    void Objectinit();

    void Setplaceinit();

    void Timerinit();

};

#endif // _CHATTER__H
