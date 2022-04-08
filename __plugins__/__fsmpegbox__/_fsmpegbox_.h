#ifndef _FSMPEGBOX__H
#define _FSMPEGBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__supercodec__/_apedecoder_.h"
#include "__supercodec__/_mp3decoder_.h"
#include "__supercodec__/_flacdecoder_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__audioformatdialog__/_audioformatdialog_.h"
#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "_fsmpegbox__global.h"
#include <QDesktopServices>

/**************interface****************/
class _FSMPEGBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class csvdatabox new instance pointer;*/
};

class FsmpegBox : public SuperTab
{
    Q_OBJECT

public:

    FsmpegBox(
            QWidget *parent = nullptr);

    ~FsmpegBox();

private:

    SuperMultiMedia *SuperM             = nullptr;
    QString Mpegfile                    = "";
    QStringList *Mpegfilelist           = nullptr;
    QString Cachefile                   = "./__depycache__/__fsmpeg__/_fsmpegfile_.";
    QString Convertsuffix               = "wav";
    QString Infilename                  = "";
    QString Outfilename                 = "./__depycache__/__fsmpeg__/_fsmpegfile_.wav";
    int Convertid                       = 0;
    QString Convertfolder               = "";
    QFileInfo Infileinfo                = {};
    int Channel                         = 0;
    int Samplerate                      = 0;
    int Bits                            = 0;
    QString Error                       = "convert error;";
    SuperProgressBarDialog *Progressbar = nullptr;
    SuperLogger *Logger                 = nullptr;
    SuperFileManager *Filemanager       = nullptr;
    QMenu *Mpegfilemenu                 = nullptr;
    QAction *Openmpegfile               = nullptr;
    QAction *Deletempegfile             = nullptr;
    FlacFileDecoder *Flacdecoder        = nullptr;
    ApeFileDecoder *Apedecoder          = nullptr;
    Mp3FileDecoder *Mp3decoder          = nullptr;
    QString Sourcepath                  = "./";

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

    void Convert();

    void Convertmode(
            int convertid);

    void Selectconvertpostion(
            int convertpath);

    void Convertposition(
            QString convertpath);

    void Finddecoder();

    void Decodeflac();

    void Decodeend();

    void Decodeape();

    void Decodemp3();

    void Setprogress(
            int progress);

    void Converterror(
            QString error);

    void Openconvertpath();

};

#endif // _FSMPEGBOX__H
