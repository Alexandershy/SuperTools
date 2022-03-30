#ifndef _ITEMDIALOG__H
#define _ITEMDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_itembox_.h"

class ItemDialog : public SuperWindow
{
    Q_OBJECT

public:

    ItemDialog(
            QWidget *parent = nullptr,
            QStringList *dataitems = {},
            QStringList *datacounts = {});

    ~ItemDialog();

public slots:

    void Refresh();

private:

    ItemBox *Plugin                 = nullptr;
    QStringList *Dataitems          = nullptr;
    QStringList *Datacounts         = nullptr;
    QMenu *Itemdialogmenu           = nullptr;
    QAction *Openitem               = nullptr;
    QAction *Changemode             = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Menuinit();

    void Itemoptions();

    void Open();

    void Changemodes();

signals:

    void Signalia(
            int itemindex);

    void Signalib(
            int itemindex);

};

#endif // _ITEMDIALOG__H
