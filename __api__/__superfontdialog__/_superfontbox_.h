#ifndef _SUPERFONTBOX__H
#define _SUPERFONTBOX__H

#include "_superfontbox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperFontBox; }
QT_END_NAMESPACE

class SuperFontBox : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperFontBox *ui = nullptr;

public:

    SuperFontBox(
            QWidget *parent = nullptr);

    ~SuperFontBox();

};

#endif // _SUPERFONTBOX__H
