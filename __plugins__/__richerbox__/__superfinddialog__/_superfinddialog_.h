#ifndef _SUPERFINDDIALOG__H
#define _SUPERFINDDIALOG__H

#include "_superfindbox_.h"
#include "__superwindow__/_superwindow_.h"
#include "__supernotedialog__/_supernotedialog_.h"

class SuperFindDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperFindDialog(
            QWidget *parent = nullptr,
            QTextEdit *textedit = nullptr);

    SuperFindDialog(
            QWidget *parent = nullptr,
            QTextBrowser *textbrowser = nullptr);

    ~SuperFindDialog();

private:

    SuperFindBox *Plugin            = nullptr;
    QTextEdit *Textedit             = nullptr;
    QTextBrowser *Textbrowser       = nullptr;
    int Widgetindex                 = 0;

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
