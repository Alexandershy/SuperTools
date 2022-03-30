#ifndef _WAVDATABOX__H
#define _WAVDATABOX__H

#define PLAYKEY 179
#define PLAYNEXT 176
#define PLAYLAST 177

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superhook__/_superhook_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__module__/_modulea_.h"
#include "__datadialog__/_datadialog_.h"
#include "_wavdatabox__global.h"
#include <QAudioFormat>

/**************interface****************/
class _WAVDATABOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class wavdatabox new instance pointer;*/
};

class WavDataBox : public SuperTab
{
    Q_OBJECT

public:

    WavDataBox(
            QWidget *parent = nullptr);

    ~WavDataBox();

private:

    SuperMultiMedia *SuperM                     = nullptr;
    SuperFileManager *Filemanager               = nullptr;
    ModuleA *Modulea                            = nullptr;
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
    PlayWav *Threadpa                           = nullptr;
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

    void Init();

    void Objectinit();

    void Parameterinit();

    void Play();

    void Setplaywavfile();

    void Playwavfiles();

    void Getwavfileformat();

    void Setdeviceformat(
            QAudioFormat *format,
            int samplerate,
            int samplesize,
            int channels);

    void Setslidervalue();

    void Setwavfilepos();

    void Stop();

    void Showdatadialog();

    void Actionopen();

    void Disableclicked();

    void Changeplaymode();

    void Changewavfileapi(
            int direction);

    void Nextwavfile();

    void Lastwavfile();

    void Clickwavfile();

    void Deletefileslot(
        QString file);

    void Signalwpslotapi();

    void Signalwpaslot();

    void Signalwpbslot(
            QString status);

    void Signalwpcslot();

    void Signalcaslot();

    void Nodeviceexist();

    void Enableplaykey();

    void Keypressedevent(
        int key);

};

#endif // _WAVDATABOX__H
