#ifndef _CHATINFODIALOG__H
#define _CHATINFODIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "_chatinfobox_.h"

class ChatInfoDialog : public SuperWindow
{
    Q_OBJECT

public:

    ChatInfoDialog(
            QWidget *parent = nullptr,
            QLineEdit *lineedit = nullptr);

    ~ChatInfoDialog();

private:

    ChatInfoBox *Plugin = nullptr;
    QLineEdit *Lineedit = nullptr;
    QString Userfolder = "";
    QString Userpicture = "";

private slots:

    void Init();

    void Objectinit();

    void Profileinit();

    void Selectprofile();

    void Changeprofile(
            QString profile);
};

#endif // _CHATINFODIALOG__H
