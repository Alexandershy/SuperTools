#ifndef _HITBRICKSDIALOG__H
#define _HITBRICKSDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_hitbricksdialogui_.h"
#include "_hitbricksscene_.h"

class HitBricksDialog : public SuperWindow
{
    Q_OBJECT

public:

    HitBricksDialog(
            QWidget *parent = nullptr);

    ~HitBricksDialog();

private:

    HitBricksDialogui *Plugin   = nullptr;
    SuperCore *Core             = nullptr;
    HitBricksScene *Mainscene   = nullptr;
    QTimer *Refreshview         = nullptr;

private slots:

    void init();

    void objectInit();

    void backgroundInit();

    void setFocus();

    void addSceneInit();

};

#endif // _HITBRICKSDIALOG__H
