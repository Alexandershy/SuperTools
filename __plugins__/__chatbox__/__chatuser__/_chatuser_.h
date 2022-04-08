#ifndef _CHATUSER__H
#define _CHATUSER__H

#include <QLabel>
#include <QDir>

class ChatUser : public QLabel
{

public:

    ChatUser(
            QWidget *parent = nullptr,
            QString role = "self",
            QString username = "username");

    ~ChatUser();

private:

    QString Role = "";
    QString Username = "";

private slots:

    void Init();

    void Policyinit();

    void Setusericon();

};


#endif // _CHATUSER__H
