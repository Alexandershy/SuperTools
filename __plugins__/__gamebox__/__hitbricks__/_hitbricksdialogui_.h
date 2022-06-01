#ifndef _HITBRICKSDIALOGUI__H
#define _HITBRICKSDIALOGUI__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class HitBricksDialogui; }
QT_END_NAMESPACE

class HitBricksDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::HitBricksDialogui *ui    = nullptr;

public:

    HitBricksDialogui(
            QWidget *parent = nullptr);

    ~HitBricksDialogui();

};

#endif // _HITBRICKSDIALOGUI__H
