#ifndef _WAVDATADIALOGUI__H
#define _WAVDATADIALOGUI__H

#include "ui__wavdatadialogui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class WavDataDialogui; }
QT_END_NAMESPACE

class WavDataDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::WavDataDialogui *ui = nullptr;

public:

    WavDataDialogui(
            QWidget *parent = nullptr);

    ~WavDataDialogui();

};

#endif // _WAVDATADIALOGUI__H
