#ifndef _SUPERPROGRESSBARDIALOGUI__H
#define _SUPERPROGRESSBARDIALOGUI__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperProgressBarDialogui; }
QT_END_NAMESPACE

class SuperProgressBarDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperProgressBarDialogui *ui = nullptr;

public:

    SuperProgressBarDialogui(
            QWidget *parent = nullptr);

    ~SuperProgressBarDialogui();

};

#endif // _SUPERPROGRESSBARDIALOGUI__H
