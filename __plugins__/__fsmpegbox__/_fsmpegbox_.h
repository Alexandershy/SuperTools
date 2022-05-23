#ifndef _FSMPEGBOX__H
#define _FSMPEGBOX__H
#define _FSMPEGBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__supercodec__/_superapedecoder_.h"
#include "__supercodec__/_supermp3decoder_.h"
#include "__supercodec__/_superflacdecoder_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__audioformatdialog__/_audioformatdialog_.h"
#include "__superprogressbardialog__/_superprogressbardialog_.h"
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

    SuperMultiMedia *Multimedia         = nullptr;
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
    SuperFlacDecoder *Flacdecoder        = nullptr;
    SuperApeDecoder *Apedecoder          = nullptr;
    SuperMp3Decoder *Mp3decoder          = nullptr;
    QString Sourcepath                  = "./";

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void convert();

    void convertMode(
            int convertid);

    void selectConvertPostion(
            int convertpath);

    void convertPosition(
            QString convertpath);

    void findDecoder();

    void decodeFlac();

    void decodeEnd();

    void decodeApe();

    void decodeMp3();

    void setProgress(
            int progress);

    void convertError(
            QString error);

    void openConvertPath();

};

#endif // _FSMPEGBOX__H
