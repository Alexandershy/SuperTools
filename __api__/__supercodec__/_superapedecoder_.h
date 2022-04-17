#ifndef _SUPERAPEDECODER__H
#define _SUPERAPEDECODER__H
#define _SUPERAPEDECODER__EXPORT Q_DECL_EXPORT

#include "__supermultimedia__/_supermultimedia_.h"
#include "__superape__/MACDll.h"
#include "__superape__/APETag.h"
#include "stdio.h"
#include <windows.h>
#include <QTimer>

class _SUPERAPEDECODER__EXPORT SuperApeDecoder : public QThread
{
    Q_OBJECT

public:

    SuperApeDecoder(
            QObject *parent = nullptr,
            QString infilename = "",
            QString outfilename = "");

    ~SuperApeDecoder();

public slots:

    void run();

private:

    SuperMultiMedia *Multimedia         = nullptr;
    QString Qinfilename                 = "";
    QString Qoutfilename                = "";
    QByteArray Infilenamebyte           = "";
    QByteArray Outfilenamebyte          = "";
    char *Infilename                    = nullptr;
    char *Outfilename                   = nullptr;
    APE_DECOMPRESS_HANDLE Apedecoder    = NULL;
    int Errorcode                       = 0;
    char *Buffer                        = NULL;
    QByteArray Databytes                = "";
    QTimer *Timer                       = nullptr;
    int64_t Wavlength                   = 0;
    int Progress                        = 0;
    int Bits                            = 0;
    int Channels                        = 0;
    int Samplerate                      = 0;
    int Sizepersample                   = 0;

private slots:

    void Init();

    void Objectinit();

    void Getapefileinfo();

    void Writewavfile();

    void Rewritewavfile();

    void Returnprogress();

signals:

    void Signalaa(
            double progress);

};

#endif // _SUPERAPEDECODER__H
