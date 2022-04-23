#ifndef _DATABOX__H
#define _DATABOX__H

#include "ui__datadialogui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class DataDialogui; }
QT_END_NAMESPACE

class DataDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::DataDialogui *ui = nullptr;

public:

    DataDialogui(
            QWidget *parent = nullptr);

    ~DataDialogui();

};

#endif // _DATABOX__H
