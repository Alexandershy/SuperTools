#ifndef _SUPERFILEDIALOGUI__H
#define _SUPERFILEDIALOGUI__H

#include "ui__superfiledialogui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperFileDialogui; }
QT_END_NAMESPACE

class SuperFileDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperFileDialogui *ui = nullptr;

public:

    SuperFileDialogui(
        QWidget *parent = nullptr);

    ~SuperFileDialogui();

};

#endif // _SUPERFILEDIALOGUI__H
