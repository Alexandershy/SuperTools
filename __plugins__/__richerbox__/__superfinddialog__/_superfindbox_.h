#ifndef _SUPERFINDBOX__H
#define _SUPERFINDBOX__H

#include "_superfindbox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperFindBox; }
QT_END_NAMESPACE

class SuperFindBox : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperFindBox *ui = nullptr;

public:

    SuperFindBox(
            QWidget *parent = nullptr);

    ~SuperFindBox();

};

#endif // _SUPERFINDBOX__H
