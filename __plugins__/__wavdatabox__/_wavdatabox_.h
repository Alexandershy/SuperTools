#ifndef _WAVDATABOX__H
#define _WAVDATABOX__H
#define _WAVDATABOX__EXPORT Q_DECL_EXPORT

#define PLAYKEY 179
#define PLAYNEXT 176
#define PLAYLAST 177

#include "__datadialog__/_wavdatadialog_.h"
#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superhook__/_superhook_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__module__/_wavdatamodulea_.h"
#include <QAudioFormat>

/**************interface****************/
class _WAVDATABOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class wasapibox new instance pointer;*/
};

class WavDataBox : public SuperTab
{
    Q_OBJECT

public:

    WavDataBox(
            QWidget *parent = nullptr);

    ~WavDataBox();

private:

    SuperMultiMedia *Multimedia                 = nullptr;
    SuperFileManager *Filemanager               = nullptr;
    WavdataModuleA *Modulea                     = nullptr;
    QAudioDevice Deviceinfo                     = {};
    QString Defaultoutputdevice                 = "";
    QString Wavfile                             = "";
    QStringList *Wavfilelist                    = nullptr;
    QStringList Wavfileinfo                     = {};
    int Timelength                              = 0;
    int Samplerate                              = 0;
    int Bits                                    = 0;
    int Bitspersample                           = 0;
    int Channelcounts                           = 0;
    int Wavfilelistcount                        = 0;
    bool Keyenabled                             = true;
    QAudioFormat Format                         = {};
    QFile *File                                 = nullptr;
    SuperPlayWav *Threadpa                      = nullptr;
    int Wavfilechangedirection                  = 1;
    SuperLogger *Logger                         = nullptr;
    int Playmode                                = 2;
    QByteArray Playstatus                       = "play";
    QString Sourcepath                          = "./";
    SuperHook *Hook                             = nullptr;
    QList<int> Multikeylist                     = {PLAYLAST,PLAYKEY,PLAYNEXT};
    int Dialogcounts                            = 0;

private slots:

    /*  main function;*/
    void init();

    void objectInit();

    void parameterInit();

    void play();

    void setPlayWavFile();

    void playWavFiles();

    void getWavFileFormat();

    void setDeviceFormat(
            QAudioFormat *format,
            int samplerate,
            int samplesize,
            int channels);

    void setSliderValue();

    void setWavFilePos();

    void stop();

    void showDataDialog();

    void actionOpen();

    void disableClicked();

    void changePlayMode();

    void changeWavFileApi(
            int direction);

    void nextWavFile();

    void lastWavFile();

    void clickWavFile();

    void deleteFileSlot(
        QString file);

    void signalWpSlotApi();

    void signalWpaSlot();

    void signalWpbSlot(
            QString status);

    void signalWpcSlot();

    void signalCaSlot();

    void nodeviceExist();

    void enablePlayKey();

    void keyPressedEvent(
        int key);

};

#endif // _WAVDATABOX__H
