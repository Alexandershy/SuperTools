#ifndef _AUDIOFORMATDIALOG__H
#define _AUDIOFORMATDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_audioformatdialogui_.h"

class AudioFormatDialog : public SuperWindow
{
    Q_OBJECT

public:

    AudioFormatDialog(
            QWidget *parent = nullptr);

    ~AudioFormatDialog();

private:

    AudioFormatDialogui *Plugin      = nullptr;

private slots:

    void init();

    void objectInit();

    void convert();

    void convertMode();

signals:

    void signalAa(
            int formatindex);

    void signalAb(
            int convertpath);

};

#endif // _AUDIOFORMATDIALOG__H
