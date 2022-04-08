#ifndef _SUPERFONTDIALOGUI__H
#define _SUPERFONTDIALOGUI__H

#include "ui__superfontdialogui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperFontDialogui; }
QT_END_NAMESPACE

class SuperFontDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperFontDialogui *ui = nullptr;

public:

    SuperFontDialogui(
            QWidget *parent = nullptr);

    ~SuperFontDialogui();

};

#endif // _SUPERFONTDIALOGUI__H
