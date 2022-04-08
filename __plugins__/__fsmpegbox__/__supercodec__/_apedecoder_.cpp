/***************************************************************************************
Decompress - Sample 1
Copyright (C) 2000-2001 by Matthew T. Ashland   All Rights Reserved.
Feel free to use this code in any way that you like.

This example illustrates using MACDLib.lib and the simple IAPESimple class to verify
or decompress a file. (verify and decompress work the same, except that verify doesn't
have an output file)  Also, shows how to use a callback to display the progress.

General Notes:
    -the terminology "Sample" refers to a single sample value, and "Block" refers
    to a collection	of "Channel" samples.  For simplicity, MAC typically uses blocks
    everywhere so that channel mis-alignment cannot happen.

Notes for use in a new project:
    -you need to include "MACLib.lib" in the included libraries list
    -life will be easier if you set the [MAC SDK]\\Shared directory as an include
    directory and an additional library input path in the project settings
    -set the runtime library to "Mutlithreaded"

WARNING:
    -This class driven system for using Monkey's Audio is still in development, so
    I can't make any guarantees that the classes and libraries won't change before
    everything gets finalized.  Use them at your own risk.
***************************************************************************************/

#include "_apedecoder_.h"

using namespace APE;

ApeFileDecoder::ApeFileDecoder(QObject *parent,QString infilename,QString outfilename)
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

ApeFileDecoder::~ApeFileDecoder()
{
    c_APEDecompress_Destroy(Apedecoder);
    delete Timer;
    delete Buffer;
}

void ApeFileDecoder::Init()
{
    Objectinit();
}

void ApeFileDecoder::Objectinit()
{
    SuperM = new SuperMultiMedia(this);
    Timer = new QTimer();
    Timer->setInterval(100);
    connect(Timer,&QTimer::timeout,this,&ApeFileDecoder::Returnprogress);
    Timer->start();
}

void ApeFileDecoder::run()
{   
    Getapefileinfo();
    Writewavfile();
    Rewritewavfile();
}

void ApeFileDecoder::Getapefileinfo()
{
    Apedecoder = c_APEDecompress_Create(Infilename,&Errorcode);
    if(Errorcode == 0 && Apedecoder)
    {
        Bits = c_APEDecompress_GetInfo(Apedecoder,APE_INFO_BITS_PER_SAMPLE,0,0);
        Samplerate = c_APEDecompress_GetInfo(Apedecoder,APE::APE_INFO_SAMPLE_RATE,0,0);
        Channels = c_APEDecompress_GetInfo(Apedecoder,APE_INFO_CHANNELS,0,0);
        Wavlength = c_APEDecompress_GetInfo(Apedecoder,APE_INFO_WAV_TOTAL_BYTES,0,0);
    }
}

/*  get ape file info;*/

void ApeFileDecoder::Writewavfile()
{
    APE::int64 nBlockAlign = c_APEDecompress_GetInfo(Apedecoder,APE_INFO_BLOCK_ALIGN, 0, 0);
    Buffer = new char [size_t(1024 * nBlockAlign)];
    APE::int64 nTotalBlocks = c_APEDecompress_GetInfo(Apedecoder,APE::APE_DECOMPRESS_TOTAL_BLOCKS, 0, 0);
    APE::int64 nBlocksRetrieved = 1;
    APE::int64 nTotalBlocksRetrieved = 0;
    unsigned int nChecksum = 0;
    FILE *file = fopen(Outfilename,"wb");
    while (nBlocksRetrieved > 0)
    {
        c_APEDecompress_GetData(Apedecoder,Buffer, 1024, &nBlocksRetrieved);
        for (int z = 0; z < (nBlockAlign * nBlocksRetrieved); z++)
        {
            nChecksum = nChecksum + abs(int(Buffer[z]));
        }
        nTotalBlocksRetrieved += nBlocksRetrieved;
        Progress = 100 * nTotalBlocksRetrieved / nTotalBlocks;
        fwrite(Buffer,nBlocksRetrieved,Channels * Bits / 8,file);
    }
    fclose(file);
}

/*  ape source code;*/

void ApeFileDecoder::Rewritewavfile()
{
    QFile file(Qoutfilename);
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QByteArray bytes = file.readAll();
        file.close();
        file.remove();
        SuperM->Writewavfile(Qoutfilename,Wavlength,Channels,Samplerate,Channels * Samplerate * 2,Channels * 2,bytes);
    }
}

/*  add wav header;*/

void ApeFileDecoder::Returnprogress()
{
    if(Progress < 100)
    {
        emit Signalaa(Progress);
    }
}
