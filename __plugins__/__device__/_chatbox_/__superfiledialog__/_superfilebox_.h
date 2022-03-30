#ifndef _SUPERFILEBOX__H
#define _SUPERFILEBOX__H

#include "_superfilebox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperFileBox; }
QT_END_NAMESPACE

class SuperFileBox : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperFileBox *ui = nullptr;

public:

    SuperFileBox(
        QWidget *parent = nullptr);

    ~SuperFileBox();

};

#endif // _SUPERFILEBOX__H
