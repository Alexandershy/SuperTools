#ifndef _ROUTDIALOG__H
#define _ROUTDIALOG__H

#include "_routdialogui_.h"
#include "__superwindow__/_superwindow_.h"

class RoutDialog : public SuperWindow
{
    Q_OBJECT

public:

    RoutDialogui *Plugin = nullptr;

public:

    RoutDialog(
            QWidget *parent = nullptr);

    ~RoutDialog();

private slots:

    void init();

    void objectInit();

};


#endif // _ROUTDIALOG__H
