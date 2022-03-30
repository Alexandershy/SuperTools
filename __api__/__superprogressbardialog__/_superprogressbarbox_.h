#ifndef _Superprogressbar__H
#define _Superprogressbar__H

#include "_superprogressbarbox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperProgressBarBox; }
QT_END_NAMESPACE

class SuperProgressBarBox : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperProgressBarBox *ui;

public:

    SuperProgressBarBox(
            QWidget *parent = nullptr);

    ~SuperProgressBarBox();

};

#endif // _Superprogressbar__H
