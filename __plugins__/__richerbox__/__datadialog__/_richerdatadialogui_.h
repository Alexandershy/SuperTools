#ifndef _RICHERDATADIALOGUI__H
#define _RICHERDATADIALOGUI__H

#include "ui__richerdatadialogui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class RicherDataDialogui; }
QT_END_NAMESPACE

class RicherDataDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::RicherDataDialogui *ui = nullptr;

public:

    RicherDataDialogui(
            QWidget *parent = nullptr);

    ~RicherDataDialogui();

};

#endif // _RICHERDATADIALOGUI__H
