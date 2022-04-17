#ifndef _SUPERNOTEDIALOGUI__H
#define _SUPERNOTEDIALOGUI__H

#include "ui__supernotedialogui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperNoteDialogui; }
QT_END_NAMESPACE

class SuperNoteDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperNoteDialogui *ui = nullptr;

public:

    SuperNoteDialogui(
            QWidget *parent = nullptr);

    ~SuperNoteDialogui();

};

#endif // _SUPERNOTEDIALOGUI__H
