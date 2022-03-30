#ifndef _ROUTBOX__H
#define _ROUTBOX__H

#include "_routbox__ui_.h"

QT_BEGIN_NAMESPACE
namespace Ui {class RoutBox;}
QT_END_NAMESPACE

class RoutBox : public QFrame
{
    Q_OBJECT

public:

    Ui::RoutBox *ui = nullptr;

public:

    RoutBox(
            QWidget *parent = nullptr);

    ~RoutBox();

};

#endif // _ROUTBOX__H
