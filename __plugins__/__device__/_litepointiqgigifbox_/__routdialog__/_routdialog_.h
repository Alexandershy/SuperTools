#ifndef _ROUTDIALOG__H
#define _ROUTDIALOG__H

#include "_routbox_.h"
#include "__superwindow__/_superwindow_.h"

class RoutDialog : public SuperWindow
{
    Q_OBJECT

public:

    RoutBox *Plugin = nullptr;

public:

    RoutDialog(
            QWidget *parent = nullptr);

    ~RoutDialog();

private slots:

    void Init();

    void Objectinit();

};


#endif // _ROUTDIALOG__H
