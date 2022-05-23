#ifndef _CSVDATAITEMDIALOG__H
#define _CSVDATAITEMDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_csvdataitemdialogui_.h"

class CsvDataItemDialog : public SuperWindow
{
    Q_OBJECT

public:

    CsvDataItemDialog(
            QWidget *parent = nullptr,
            QStringList *dataitems = {},
            QStringList *datacounts = {});

    ~CsvDataItemDialog();

public slots:

    void refresh();

private:

    CsvDataItemDialogui *Plugin     = nullptr;
    QStringList *Dataitems          = nullptr;
    QStringList *Datacounts         = nullptr;
    QMenu *Itemdialogmenu           = nullptr;
    QAction *Openitem               = nullptr;
    QAction *Changemode             = nullptr;

private slots:

    void init();

    void objectInit();

    void menuInit();

    void itemOptions();

    void open();

    void changeModes();

signals:

    void signalIa(
            int itemindex);

    void signalIb(
            int itemindex);

};

#endif // _CSVDATAITEMDIALOG__H
