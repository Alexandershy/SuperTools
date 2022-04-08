#ifndef _AUDIOFORMATDIALOG__H
#define _AUDIOFORMATDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_audioformatbox_.h"

class AudioFormatDialog : public SuperWindow
{
    Q_OBJECT

public:

    AudioFormatDialog(
            QWidget *parent = nullptr);

    ~AudioFormatDialog();

private:

    AudioFormatBox *Plugin      = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Convert();

    void Convertmode();

signals:

    void Signalaa(
            int formatindex);

    void Signalab(
            int convertpath);

};

#endif // _AUDIOFORMATDIALOG__H
