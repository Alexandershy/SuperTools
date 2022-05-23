#ifndef _HITBRICKSBOX__H
#define _HITBRICKSBOX__H

#include "ui__hitbricksdialogui_.h"

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

#endif // _HITBRICKSBOX__H
