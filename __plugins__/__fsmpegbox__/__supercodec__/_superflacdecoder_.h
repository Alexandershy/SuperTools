#ifndef _SUPERFLACDECODER__H
#define _SUPERFLACDECODER__H
#define _SUPERFLACDECODER__EXPORT Q_DECL_EXPORT

#include "__superflac__/FLAC/stream_decoder.h"
#include <stdlib.h>
#include <QThread>
#include <stdio.h>
#include <QTimer>

class _SUPERFLACDECODER__EXPORT SuperFlacDecoder : public QThread
{
    Q_OBJECT

public:

    SuperFlacDecoder(
            QObject *parent = nullptr,
            QString infilename = "",
            QString outfilename = "");

    ~SuperFlacDecoder();

public slots:

    void run();

protected:

    static FLAC__bool write_little_endian_uint16(
            FILE *file,
            FLAC__uint16 x);

    static FLAC__bool write_little_endian_int16(
            FILE *file,
            FLAC__int16 x);

    static FLAC__bool write_little_endian_uint32(
            FILE *file,
            FLAC__uint32 x);

    static FLAC__StreamDecoderWriteStatus write_callback(
            const FLAC__StreamDecoder *decoder,
            const FLAC__Frame *frame,
            const FLAC__int32 * const buffer[],
            void *client_data);

    static void metadata_callback(
            const FLAC__StreamDecoder *decoder,
            const FLAC__StreamMetadata *metadata,
            void *client_data);

    static void error_callback(
            const FLAC__StreamDecoder *decoder,
            FLAC__StreamDecoderErrorStatus status,
            void *client_data);

private:

    QString Qinfilename                         = "";
    QString Qoutfilename                        = "";
    QByteArray Infilenamebyte                   = "";
    QByteArray Outfilenamebyte                  = "";
    FILE *Outfile                               = nullptr;
    char *Infilename                            = nullptr;
    char *Outfilename                           = nullptr;
    FLAC__StreamDecoder *Decoder                = nullptr;
    FLAC__bool Flacbool                         = false;
    FLAC__StreamDecoderInitStatus Initstatus    = FLAC__STREAM_DECODER_INIT_STATUS_OK;
    QTimer *Timer                               = nullptr;

private slots:

    void init();

    void objectInit();

    void decoderInit();

    void md5CheckInit();

    void fileInit();

    void processInit();

    void returnProgress();

signals:

    void signalFa(
            int progress);

    void signalFb(
            QString error);

};

#endif // _SUPERFLACDECODER__H
