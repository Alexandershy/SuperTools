#ifndef _SUPERTEXTBROWSER__H
#define _SUPERTEXTBROWSER__H

#include "__supercore__/_supercore_.h"
#include <QTextBrowser>
#include <QAction>
#include <QLayout>
#include <QMenu>

class SuperTextBrowser : public QTextBrowser
{
    Q_OBJECT

public:

    bool Enabletransfercodec    = false;
    QAction *Clearbrowser       = nullptr;
    QAction *Transfercodec      = nullptr;
    QAction *Openfilepath       = nullptr;

public:

    SuperTextBrowser(
            QWidget *parent = nullptr);

    ~SuperTextBrowser();

public slots:

    void Addaction(
            QAction *action,
            QString text,
            QString objectname);

private:

    SuperCore *SuperC           = nullptr;
    QMenu *Menu                 = nullptr;
    QWidget *Widget             = nullptr;
    QAction *Copy               = nullptr;
    QAction *Copylinklocation   = nullptr;
    QAction *Selectall          = nullptr;

private slots:

    void Init();

    void Parameterinit();

    void Appendtextinit();

    void Appendactioninit();

    void Menushowinit();

    void Menushow();

};

#endif // _SUPERTEXTBROWSER__H
