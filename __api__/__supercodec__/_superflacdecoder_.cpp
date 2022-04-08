/* example_cpp_decode_file - Simple FLAC file decoder using libFLAC
 * Copyright (C) 2007-2009  Josh Coalson
 * Copyright (C) 2011-2016  Xiph.Org Foundation
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*
 * This example shows how to use libFLAC++ to decode a FLAC file to a WAVE
 * file.  It only supports 16-bit stereo files.
 *
 * Complete API documentation can be found at:
 *   http://xiph.org/flac/api/
 */

#include "_flacdecoder_.h"

QString error = "";
static FLAC__uint64 totalsamples = 0;
static unsigned samplerate = 0;
static unsigned channels = 0;
static unsigned bps = 0;
static unsigned writesamples = 0;

SuperFlacDecoder::SuperFlacDecoder(QObject *parent,QString infilename,QString outfilename)
    : QThread(parent)
{
    Qinfilename = infilename;
    Qoutfilename = outfilename;
    Infilenamebyte = infilename.toUtf8();
    Infilename = Infilenamebyte.data();
    Outfilenamebyte = outfilename.toUtf8();
    Outfilename = Outfilenamebyte.data();
    fopen_s(&Outfile,Outfilename,"wb");
    Init();
}

SuperFlacDecoder::~SuperFlacDecoder()
{
    totalsamples = 0;
    samplerate = 0;
    channels = 0;
    bps = 0;
    writesamples = 0;
    error = "";
    fclose(Outfile);
    FLAC__stream_decoder_delete(Decoder);
    delete Timer;
}

FLAC__bool SuperFlacDecoder::write_little_endian_uint16(FILE *file, FLAC__uint16 x)
{
    return fputc(x, file) != EOF && fputc(x >> 8, file) != EOF;
}

/*  flac source code;*/

FLAC__bool SuperFlacDecoder::write_little_endian_int16(FILE *file, FLAC__int16 x)
{
    return write_little_endian_uint16(file, (FLAC__uint16)x);
}

/*  flac source code;*/

FLAC__bool SuperFlacDecoder::write_little_endian_uint32(FILE *file, FLAC__uint32 x)
{
    return fputc(x, file) != EOF && fputc(x >> 8, file) != EOF && fputc(x >> 16, file) != EOF && fputc(x >> 24, file) != EOF;
}

/*  flac source code;*/

FLAC__StreamDecoderWriteStatus SuperFlacDecoder::write_callback(const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data)
{
    FILE *f = (FILE*)client_data;
    const FLAC__uint32 total_size = (FLAC__uint32)(totalsamples * channels * (16 / 8));
    size_t i;
    (void)decoder;
    if(totalsamples == 0) {
        error = "ERROR: only works for FLAC files that have a total_samples count in STREAMINFO;";
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if(channels != 2) {
        error = "ERROR: only supports 2 channels streams;\ncurrent: " + QString::number(channels) + " bits;";
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if(frame->header.channels != 2) {
        error = "ERROR: This frame contains %d channels (should be 2);\ncurrent: " + QString::number(frame->header.channels) + " channels;";
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if(buffer [0] == NULL) {
        error = "ERROR: buffer [0] is NULL;";
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if(buffer [1] == NULL) {
        error = "ERROR: buffer [1] is NULL;";
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    /* write WAVE header before we write the first frame */
    if(frame->header.number.sample_number == 0) {
        if(
            fwrite("RIFF", 1, 4, f) < 4 ||
            !write_little_endian_uint32(f, total_size + 36) ||
            fwrite("WAVEfmt ", 1, 8, f) < 8 ||
            !write_little_endian_uint32(f, 16) ||
            !write_little_endian_uint16(f, 1) ||
            !write_little_endian_uint16(f, (FLAC__uint16)channels) ||
            !write_little_endian_uint32(f, samplerate) ||
            !write_little_endian_uint32(f, samplerate * channels * (16 / 8)) ||
            !write_little_endian_uint16(f, (FLAC__uint16)(channels * (16 / 8))) || /* block align */
            !write_little_endian_uint16(f, (FLAC__uint16)16) ||
            fwrite("data", 1, 4, f) < 4 ||
            !write_little_endian_uint32(f, total_size)
        ) {
            return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
        }
    }
    /* write 16bits decoded PCM samples */
    switch (bps)
    {
        case 16:
        {
            for(i = 0; i < frame->header.blocksize; i++)
            {
                if(!write_little_endian_int16(f, (FLAC__int16)buffer[0][i]) || !write_little_endian_int16(f, (FLAC__int16)buffer[1][i]))
                {
                    return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
                }
            }
            break;
        }
        case 24:
        {
            for(i = 0; i < frame->header.blocksize; i++)
            {
                FLAC__int16 templ = buffer[0][i] >> 8;
                FLAC__int16 tempr = buffer[0][i] >> 8;
                if(!write_little_endian_int16(f, templ) || !write_little_endian_int16(f, tempr))
                {
                    return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
                }
            }
            break;
        }
    }
    writesamples = writesamples + frame->header.blocksize;
    return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
}

/*  flac source code;*/

void SuperFlacDecoder::metadata_callback(const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data)
{
    (void)decoder, (void)client_data;
    /* print some stats */
    if(metadata->type == FLAC__METADATA_TYPE_STREAMINFO) {
        /* save for later */
        totalsamples = metadata->data.stream_info.total_samples;
        samplerate = metadata->data.stream_info.sample_rate;
        channels = metadata->data.stream_info.channels;
        bps = metadata->data.stream_info.bits_per_sample;
    }
}

/*  flac source code;*/

void SuperFlacDecoder::error_callback(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data)
{
    (void)decoder, (void)client_data;
    error = FLAC__StreamDecoderErrorStatusString[status];
}

void SuperFlacDecoder::Init()
{
    Objectinit();
}

void SuperFlacDecoder::Objectinit()
{
    Timer = new QTimer();
    Timer->setInterval(100);
    connect(Timer,&QTimer::timeout,this,&SuperFlacDecoder::Returnprogress);
    Timer->start();
}

void SuperFlacDecoder::run()
{
    Decoderinit();
    Md5checkinit();
    Fileinit();
    Processinit();
}

void SuperFlacDecoder::Decoderinit()
{
    Decoder = FLAC__stream_decoder_new();
}

/*  creat decoder for flac;*/

void SuperFlacDecoder::Md5checkinit()
{
    if(Decoder)
    {
        Flacbool = FLAC__stream_decoder_set_md5_checking(Decoder, true);
    }
}

/*  run md5 check for decoder;*/

void SuperFlacDecoder::Fileinit()
{
    if(Flacbool)
    {
        Initstatus = FLAC__stream_decoder_init_file(Decoder,Infilename, write_callback, metadata_callback, error_callback,Outfile);
    }
}

/*  file decoder init;*/

void SuperFlacDecoder::Processinit()
{
    if(Initstatus == FLAC__STREAM_DECODER_INIT_STATUS_OK)
    {
        Flacbool = FLAC__stream_decoder_process_until_end_of_stream(Decoder);
    }
    emit Signalfb(error);
}

/*  process flac;*/

void SuperFlacDecoder::Returnprogress()
{
    int progress = 100 * double(writesamples) / totalsamples;
    if(progress < 100)
    {
        emit Signalfa(progress);
    }
}

/*  process file;*/
