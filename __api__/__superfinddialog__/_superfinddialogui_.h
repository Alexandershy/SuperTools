#ifndef _SUPERFINDDIALOGUI__H
#define _SUPERFINDDIALOGUI__H

#include "ui__superfinddialogui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperFindDialogui; }
QT_END_NAMESPACE

class SuperFindDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperFindDialogui *ui = nullptr;

public:

    SuperFindDialogui(
            QWidget *parent = nullptr);

    ~SuperFindDialogui();

};

#endif // _SUPERFINDDIALOGUI__H
