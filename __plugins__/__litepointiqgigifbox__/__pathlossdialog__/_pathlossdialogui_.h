#ifndef _PATHLOSSBOX__H
#define _PATHLOSSBOX__H

#include "ui__pathlossdialogui_.h"

QT_BEGIN_NAMESPACE
namespace Ui {class PathLossDialogui;}
QT_END_NAMESPACE

class PathLossDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::PathLossDialogui *ui = nullptr;

public:

    PathLossDialogui(
            QWidget *parent = nullptr);

    ~PathLossDialogui();

};

#endif // _PATHLOSSBOX__H
