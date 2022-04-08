#ifndef _ITEMBOX__H
#define _ITEMBOX__H

#include "_itembox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class ItemBox; }
QT_END_NAMESPACE

class ItemBox : public QFrame
{
    Q_OBJECT

public:

    Ui::ItemBox *ui = nullptr;

public:

    ItemBox(
            QWidget *parent = nullptr);

    ~ItemBox();

};

#endif // _ITEMBOX__H
