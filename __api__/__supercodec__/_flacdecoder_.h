#ifndef _FLACDECODER__H
#define _FLACDECODER__H

#include "__superflac__/FLAC/stream_decoder.h"
#include <stdlib.h>
#include <QThread>
#include <stdio.h>
#include <QTimer>

class FlacFileDecoder : public QThread
{
    Q_OBJECT

public:

    FlacFileDecoder(
            QObject *parent = nullptr,
            QString infilename = "",
            QString outfilename = "");

    ~FlacFileDecoder();

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

    void Init();

    void Objectinit();

    void Decoderinit();

    void Md5checkinit();

    void Fileinit();

    void Processinit();

    void Returnprogress();

signals:

    void Signalfa(
            int progress);

    void Signalfb(
            QString error);

};

#endif // _FLACDECODER__H
