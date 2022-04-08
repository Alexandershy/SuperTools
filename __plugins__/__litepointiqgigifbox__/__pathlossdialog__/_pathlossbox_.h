#ifndef _PATHLOSSBOX__H
#define _PATHLOSSBOX__H

#include "_pathlossbox__ui_.h"

QT_BEGIN_NAMESPACE
namespace Ui {class PathLossBox;}
QT_END_NAMESPACE

class PathLossBox : public QFrame
{
    Q_OBJECT

public:

    Ui::PathLossBox *ui = nullptr;

public:

    PathLossBox(
            QWidget *parent = nullptr);

    ~PathLossBox();

};

#endif // _PATHLOSSBOX__H
