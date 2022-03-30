#ifndef _FORMATBOX__H
#define _FORMATBOX__H

#include "_formatbox__ui.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class FormatBox; }
QT_END_NAMESPACE

class FormatBox : public QFrame
{
    Q_OBJECT

public:

    Ui::FormatBox *ui = nullptr;

public:

    FormatBox(
            QWidget *parent = nullptr);

    ~FormatBox();

};

#endif // _FORMATBOX__H
