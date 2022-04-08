#ifndef _MP3DECODER__H
#define _MP3DECODER__H

#include "__supermultimedia__/_supermultimedia_.h"
#include "__supermp3__/mpg123.h"
#include <stdio.h>
#include <io.h>
#include <process.h>
#include <windows.h>
#include <sys/stat.h>
#include <QThread>
#include <QTimer>

class Mp3FileDecoder : public QThread
{
    Q_OBJECT

public:

    Mp3FileDecoder(
            QObject *parent = nullptr,
            QString infilename = "",
            QString outfilename = "");

    ~Mp3FileDecoder();

public slots:

    void run();

private:

    SuperMultiMedia *SuperM     = nullptr;
    QString Qinfilename         = "";
    QString Qoutfilename        = "";
    QByteArray Infilenamebyte   = "";
    QByteArray Outfilenamebyte  = "";
    char *Infilename            = nullptr;
    char *Outfilename           = nullptr;
    mpg123_pars *Mpgpars        = nullptr;
    int Errorcode               = 0;
    mpg123_handle *Mp3handle    = nullptr;
    unsigned char *Frame        = nullptr;
    size_t Wframesize           = 0;
    off_t Frameindex            = 0;
    FILE *File                  = nullptr;
    int64_t Filesize            = 0;
    int64_t Dframesize          = 0;
    long Samplerate             = 0;
    int Channels                = 0;
    int Mp3format               = 0;
    mpg123_frameinfo2 Frameinfo = {};
    QByteArray Wavheader        = "";
    QByteArray Wavdata          = "";
    QTimer *Timer               = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Outfileinit();

    void Decoderinit();

    void Decode();

    void Writeaswavfile();

    void Returnprogress();

signals:

    void Signalma(
            int progress);

};

#endif // _MP3DECODER__H
