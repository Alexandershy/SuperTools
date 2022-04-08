#ifndef _SUPERNOTEBOX__H
#define _SUPERNOTEBOX__H

#include "_supernotebox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperNoteBox; }
QT_END_NAMESPACE

class SuperNoteBox : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperNoteBox *ui = nullptr;

public:

    SuperNoteBox(
            QWidget *parent = nullptr);

    ~SuperNoteBox();

};

#endif // _SUPERNOTEBOX__H
