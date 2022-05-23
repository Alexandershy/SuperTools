#ifndef _WASAPIFORMATDIALOG__H
#define _WASAPIFORMATDIALOG__H

#include "__supermultimedia__/_supermultimedia_.h"
#include "__superwindow__/_superwindow_.h"
#include "_wasapiformatdialogui_.h"
#include <QAudioFormat>

class WasapiFormatDialog : public SuperWindow
{
    Q_OBJECT

public:

    WasapiFormatDialog(
            QWidget *parent = nullptr,
            QAudioFormat *outputformat = nullptr,
            QAudioFormat *inputformat = nullptr);

    ~WasapiFormatDialog();

private:

    SuperMultiMedia *Multimedia     = nullptr;
    WasapiFormatDialogui *Plugin    = nullptr;
    QAudioFormat *Outputformat      = nullptr;
    QAudioFormat *Inputformat       = nullptr;

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void changeOutputFormat();

    void changeInputFormat();

signals:

    void signalFa(
            QAudioFormat *format,
            int samplerate,
            int bits,
            int channels,
            QString audioname);

    void signalFb(
            int outputsamplerate,
            int outputbits,
            int outputchannels);

    void signalFc(
            int inputsamplerate,
            int inputbits,
            int inputchannels);

};

#endif // _WASAPIFORMATDIALOG__H
