#ifndef _HITBRICKSBOX__H
#define _HITBRICKSBOX__H

#include "_hitbricksbox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class HitBricksBox; }
QT_END_NAMESPACE

class HitBricksBox : public QFrame
{
    Q_OBJECT

public:

    Ui::HitBricksBox *ui    = nullptr;

public:

    HitBricksBox(
            QWidget *parent = nullptr);

    ~HitBricksBox();

};

#endif // _HITBRICKSBOX__H
