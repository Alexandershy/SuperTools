#ifndef _AUDIOFORMATBOX__H
#define _AUDIOFORMATBOX__H

#include "_audioformatbox__ui.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class AudioFormatBox; }
QT_END_NAMESPACE

class AudioFormatBox : public QFrame
{
    Q_OBJECT

public:

    Ui::AudioFormatBox *ui = nullptr;

public:

    AudioFormatBox(
            QWidget *parent = nullptr);

    ~AudioFormatBox();

};

#endif // _AUDIOFORMATBOX__H
