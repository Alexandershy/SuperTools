
/*
    libmpg123: MPEG Audio Decoder library (version 1.29.2)

    copyright 1995-2015 by the mpg123 project
    free software under the terms of the LGPL 2.1
    see COPYING and AUTHORS files in distribution or http://mpg123.org
*/

#include "_supermp3decoder_.h"

SuperMp3Decoder::SuperMp3Decoder(QObject *parent,QString infilename,QString outfilename)
    : QThread(parent)
{
    Qinfilename = infilename;
    Qoutfilename = outfilename;
    Infilenamebyte = infilename.toUtf8();
    Infilename = Infilenamebyte.data();
    Outfilenamebyte = outfilename.toUtf8();
    Outfilename = Outfilenamebyte.data();
    Init();
}

SuperMp3Decoder::~SuperMp3Decoder()
{
    mpg123_delete_pars(Mpgpars);
    mpg123_delete(Mp3handle);
    mpg123_exit();
    fclose(File);
    delete Timer;
}

void SuperMp3Decoder::Init()
{
    Objectinit();
    mpg123_init();
    mpg123_decoders();
    Outfileinit();
    Decoderinit();
}

void SuperMp3Decoder::Objectinit()
{
    Multimedia = new SuperMultiMedia(this);
    Timer = new QTimer();
    Timer->setInterval(100);
    connect(Timer,&QTimer::timeout,this,&SuperMp3Decoder::Returnprogress);
    Timer->start();
}

void SuperMp3Decoder::Outfileinit()
{
    QFileInfo fileinfo(Qinfilename);
    Filesize = fileinfo.size();
    fopen_s(&File,Outfilename,"wb");
}

void SuperMp3Decoder::Decoderinit()
{
    Mp3handle = mpg123_new(NULL, &Errorcode);
    Errorcode = mpg123_open(Mp3handle,Infilename);
    Frameindex = mpg123_seek_frame(Mp3handle, 0, SEEK_SET);
    mpg123_getformat(Mp3handle, &Samplerate, &Channels, &Mp3format);
    mpg123_info2(Mp3handle,&Frameinfo);
}

void SuperMp3Decoder::run()
{
    Decode();
    Writeaswavfile();
}

void SuperMp3Decoder::Decode()
{
    while(true)
    {
        Errorcode = mpg123_decode_frame(Mp3handle, &Frameindex, &Frame, &Wframesize);
        if(Errorcode == MPG123_OK && Wframesize > 0)
        {
            Frameindex = Frameindex + 1;
            Dframesize = Dframesize + Frameinfo.framesize;
            fwrite(Frame,Wframesize,sizeof(unsigned char),File);
        }
        else
        {
            break;
        }
    }
}

void SuperMp3Decoder::Writeaswavfile()
{
    QFile file(Qoutfilename);
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QByteArray bytes = file.readAll();
        int64_t filesize = file.size();
        file.close();
        file.remove();
        Multimedia->Writewavfile(Qoutfilename,filesize,Channels,Samplerate,Channels * Samplerate * 2,Channels * 2,bytes);
    }
}

void SuperMp3Decoder::Returnprogress()
{
    int progress = 100 * double(Dframesize) / Filesize;
    if(progress < 100)
    {
        emit Signalma(progress);
    }
}

/*  process file;*/

