#ifndef _HITBRICKSDIALOG__H
#define _HITBRICKSDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_hitbricksbox_.h"
#include "_hitbricksscene_.h"

class HitBricksDialog : public SuperWindow
{
    Q_OBJECT

public:

    HitBricksDialog(
            QWidget *parent = nullptr);

    ~HitBricksDialog();

private:

    HitBricksBox *Plugin        = nullptr;
    SuperCore *SuperC           = nullptr;
    HitBricksScene *Mainscene   = nullptr;
    QTimer *Refreshview         = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Backgroundinit();

    void Setfocus();

    void Addsceneinit();

};

#endif // _HITBRICKSDIALOG__H
