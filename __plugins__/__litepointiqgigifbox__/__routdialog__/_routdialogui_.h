#ifndef _ROUTDIALOGUI__H
#define _ROUTDIALOGUI__H

#include "ui__routdialogui_.h"

QT_BEGIN_NAMESPACE
namespace Ui {class RoutDialogui;}
QT_END_NAMESPACE

class RoutDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::RoutDialogui *ui = nullptr;

public:

    RoutDialogui(
            QWidget *parent = nullptr);

    ~RoutDialogui();

};

#endif // _ROUTBOX__H
