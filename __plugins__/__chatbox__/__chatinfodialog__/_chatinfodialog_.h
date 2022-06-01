#ifndef _CHATINFODIALOG__H
#define _CHATINFODIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "_chatinfodialogui_.h"
#include <QLineEdit>

class ChatInfoDialog : public SuperWindow
{
    Q_OBJECT

public:

    ChatInfoDialog(
            QWidget *parent = nullptr,
            QLineEdit *lineedit = nullptr);

    ~ChatInfoDialog();

private:

    ChatInfoDialogui *Plugin    = nullptr;
    QLineEdit *Lineedit         = nullptr;
    QString Userfolder          = "";
    QString Userpicture         = "";

private slots:

    void init();

    void objectInit();

    void profileInit();

    void selectProfile();

    void changeProfile(
            QString profile);
};

#endif // _CHATINFODIALOG__H
