#ifndef _SUPERFINDDIALOG__H
#define _SUPERFINDDIALOG__H
#define _SUPERFINDDIALOG__EXPORT Q_DECL_EXPORT

#include "__superwindow__/_superwindow_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "_superfinddialogui_.h"
#include <QTextBrowser>

class _SUPERFINDDIALOG__EXPORT SuperFindDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperFindDialog(
        QWidget *parent = nullptr,
         QTextEdit* textedit = nullptr);

    ~SuperFindDialog();

private:

    SuperFindDialogui *Plugin   = nullptr;
    QTextEdit *Textedit         = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

    void Enablenextbutton();

    void Highlightpalette(
            QWidget *widget);

    void Findnexttext();

    void Findlasttext();

    void Movetostart();

    void Movetoend();

};


#endif // _SUPERFINDDIALOG__H
