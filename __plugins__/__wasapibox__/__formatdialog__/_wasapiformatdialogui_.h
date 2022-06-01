#ifndef _WASAPIFORMATDIALOGUI__H
#define _WASAPIFORMATDIALOGUI__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class WasapiFormatDialogui; }
QT_END_NAMESPACE

class WasapiFormatDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::WasapiFormatDialogui *ui = nullptr;

public:

    WasapiFormatDialogui(
            QWidget *parent = nullptr);

    ~WasapiFormatDialogui();

};

#endif // _WASAPIFORMATDIALOGUI__H
