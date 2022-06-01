#ifndef _AUDIOFORMATDIALOGUI__H
#define _AUDIOFORMATDIALOGUI__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class AudioFormatDialogui; }
QT_END_NAMESPACE

class AudioFormatDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::AudioFormatDialogui *ui = nullptr;

public:

    AudioFormatDialogui(
            QWidget *parent = nullptr);

    ~AudioFormatDialogui();

};

#endif // _AUDIOFORMATDIALOGUI__H
