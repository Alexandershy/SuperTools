#ifndef _FORMATDIALOG__H
#define _FORMATDIALOG__H

#include "__supermultimedia__/_supermultimedia_.h"
#include "__superwindow__/_superwindow_.h"
#include "_formatbox_.h"
#include <QAudioFormat>

class FormatDialog : public SuperWindow
{
    Q_OBJECT

public:

    FormatDialog(
            QWidget *parent = nullptr,
            QAudioFormat *outputformat = nullptr,
            QAudioFormat *inputformat = nullptr);

    ~FormatDialog();

private:

    SuperMultiMedia *SuperM     = nullptr;
    FormatBox *Plugin           = nullptr;
    QAudioFormat *Outputformat  = nullptr;
    QAudioFormat *Inputformat   = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

    void Changeoutputformat();

    void Changeinputformat();

signals:

    void Signalfa(
            QAudioFormat *format,
            int samplerate,
            int bits,
            int channels,
            QString audioname);

    void Signalfb(
            int outputsamplerate,
            int outputbits,
            int outputchannels);

    void Signalfc(
            int inputsamplerate,
            int inputbits,
            int inputchannels);

};

#endif // _FORMATDIALOG__H
