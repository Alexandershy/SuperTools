#include "_supermultimedia_.h"

SuperMultiMedia::SuperMultiMedia(QObject *parent)
    : QObject(parent)
{
    Core = new SuperCore(this);
}

SuperMultiMedia::~SuperMultiMedia()
{

}


QStringList SuperMultiMedia::Wavinfo(QString wavfile)
{
    QStringList listtemp = {"RIFF","filelen","WAVE","fmt","fmtlen","wformattag","wchannels","dwsamplerate","dwavgbyterate","wblockalign","wbitspersample","wextsize","extralinfo"};
    unsigned long longtemp;
    unsigned short shorttemp;
    QFile wav(wavfile);
    wav.open(QIODevice::ReadOnly);
    listtemp[0] = wav.read(4);                              //RIFF
    memcpy(&longtemp,wav.read(4),4);                        //filelen
    listtemp[1] = QString::number(longtemp);
    listtemp[2] = wav.read(4);                              //WAVE
    listtemp[3] = wav.read(4);                              //fmt
    memcpy(&longtemp,wav.read(4),4);                        //fmtlen
    listtemp[4] = QString::number(longtemp);
    memcpy(&shorttemp,wav.read(2),2);                       //wformattag
    listtemp[5] = QString::number(shorttemp);
    memcpy(&shorttemp,wav.read(2),2);                       //wchannels
    listtemp[6] = QString::number(shorttemp);
    memcpy(&longtemp,wav.read(4),4);                        //dwsamplerate
    listtemp[7] = QString::number(longtemp);
    memcpy(&longtemp,wav.read(4),4);                        //dwavgbyterate
    listtemp[8] = QString::number(longtemp);
    memcpy(&shorttemp,wav.read(2),2);                       //wblockalign
    listtemp[9] = QString::number(shorttemp);
    memcpy(&shorttemp,wav.read(2),2);                       //wbitspersample
    listtemp[10] = QString::number(shorttemp);
    listtemp[11] = wav.read(4);                             //data
    memcpy(&longtemp,wav.read(4),4);                        //size
    listtemp[12] = QString::number(longtemp);
    return listtemp;
}

/*  read wav title info;*/

QByteArray SuperMultiMedia::Writewavinfo(int filelen,short channels,int samplerate,int transmitrate,short blockalign)
{
    QByteArray byteriff = "RIFF";
    QByteArray bytefilelen;
    QByteArray bytewave = "WAVE";
    QByteArray bytefmt = "fmt ";
    QByteArray byteformatlen;
    QByteArray byteformattag;
    QByteArray bytechannels;
    QByteArray bytesamplerate;
    QByteArray bytetransmitraterate;
    QByteArray byteblockalign;
    QByteArray bytebitspersample;
    QByteArray bytedatachunk = """data";
    Int2bytearray(&bytefilelen,filelen);
    Int2bytearray(&byteformatlen,16);
    Short2bytearray(&byteformattag,1);
    Short2bytearray(&bytechannels,channels);
    Int2bytearray(&bytesamplerate,samplerate);
    Int2bytearray(&bytetransmitraterate,transmitrate);
    Short2bytearray(&byteblockalign,blockalign);
    Short2bytearray(&bytebitspersample,16);
    return byteriff + bytefilelen + bytewave + bytefmt + byteformatlen + byteformattag + bytechannels + bytesamplerate + bytetransmitraterate + byteblockalign + bytebitspersample + bytedatachunk + bytefilelen;
}

/*  write wav title info;*/

void SuperMultiMedia::Writewavfile(QString wavfile,int filelen,short channels,int samplerate,int transmitrate,short blockalign,QByteArray data)
{
    QByteArray Wavfiledata;
    QByteArray byteriff = "RIFF";
    QByteArray bytefilelen;
    QByteArray bytewave = "WAVE";
    QByteArray bytefmt = "fmt ";
    QByteArray byteformatlen;
    QByteArray byteformattag;
    QByteArray bytechannels;
    QByteArray bytesamplerate;
    QByteArray bytetransmitraterate;
    QByteArray byteblockalign;
    QByteArray bytebitspersample;
    QByteArray bytedatachunk = """data";
    Int2bytearray(&bytefilelen,filelen);
    Int2bytearray(&byteformatlen,16);
    Short2bytearray(&byteformattag,1);
    Short2bytearray(&bytechannels,channels);
    Int2bytearray(&bytesamplerate,samplerate);
    Int2bytearray(&bytetransmitraterate,transmitrate);
    Short2bytearray(&byteblockalign,blockalign);
    Short2bytearray(&bytebitspersample,16);
    Wavfiledata = byteriff + bytefilelen + bytewave + bytefmt + byteformatlen + byteformattag + bytechannels + bytesamplerate + bytetransmitraterate + byteblockalign + bytebitspersample + bytedatachunk + bytefilelen + data;
    QFile wav(wavfile);
    wav.open(QIODevice::WriteOnly);
    wav.write(Wavfiledata);
    wav.close();
}

/*  write wav title info and data;*/

void SuperMultiMedia::Int2bytearray(QByteArray *bytearry, int inta)
{
    bytearry->clear();
    bytearry->append((uchar)((0x000000FF  & inta) >> 0));
    bytearry->append((uchar)((0x0000FF00  & inta) >> 8));
    bytearry->append((uchar)((0x00FF0000  & inta) >> 16));
    bytearry->append((uchar)((0xFF000000  & inta) >> 24));
}

/*  transform int to byte;*/

void SuperMultiMedia::Short2bytearray(QByteArray *bytearry, short shorta)
{
    bytearry->clear();
    bytearry->append((uchar)((0x00FF  & shorta) >> 0));
    bytearry->append((uchar)((0xFF00  & shorta) >> 8));
}

/*  transform byte to int;*/

void SuperMultiMedia::Checkdeviceexist(QList<bool> *boollist)
{
    QMediaDevices mediadevice;
    boollist->clear();
    boollist->append(mediadevice.defaultAudioOutput().isNull());
    boollist->append(mediadevice.defaultAudioInput().isNull());
}

/*  check if has audio devices by audio mode;*/

void SuperMultiMedia::Getaudiooutputdeviceinfo(QList<QAudioDevice> *outputdevicelist,QStringList* listname,QStringList* listnumber)
{
    outputdevicelist->clear();
    outputdevicelist->append(QMediaDevices::audioOutputs());
    for(int i = 0;i < outputdevicelist->count();i++)
    {
        listname->append(outputdevicelist->at(i).description());
        listnumber->append(QString::number(i));
    }
}

/*  get audio output device info;*/

void SuperMultiMedia::Getaudioinputdeviceinfo(QList<QAudioDevice> *inputdevicelist,QStringList* listname,QStringList* listnumber)
{
    inputdevicelist->clear();
    inputdevicelist->append(QMediaDevices::audioInputs());
    for(int i = 0;i < inputdevicelist->count();i++)
    {
        listname->append(inputdevicelist->at(i).description());
        listnumber->append(QString::number(i));
    }
}

/*  get audio input device info;*/

int SuperMultiMedia::Enumbitstoint(QAudioFormat::SampleFormat bits)
{
    switch(bits)
    {
        case QAudioFormat::Unknown:
        {
            return 0;
            break;
        }
        case QAudioFormat::UInt8:
        {
            return 8;
            break;
        }
        case QAudioFormat::Int16:
        {
            return 16;
            break;
        }
        case QAudioFormat::Int32:
        {
            return 32;
            break;
        }
        case QAudioFormat::Float:
        {
            return 64;
            break;
        }
        default:
            return -1;
    }
}

/*  transfer enum bits to int bits;*/

QAudioFormat::SampleFormat SuperMultiMedia::Intbitstoenum(int bits)
{
    switch(bits)
    {
        case 0:
        {
            return QAudioFormat::Unknown;
            break;
        }
        case 8:
        {
            return QAudioFormat::UInt8;
            break;
        }
        case 16:
        {
            return QAudioFormat::Int16;
            break;
        }
        case 32:
        {
            return QAudioFormat::Int32;
            break;
        }
        case 64:
        {
            return QAudioFormat::Float;
            break;
        }
        default:
            return QAudioFormat::Unknown;
    }
}

/*  transfer enum bits to int bits;*/

void SuperMultiMedia::Cal16bitsdata(int channels,int channel,QVector<double> *vectorx,QVector<double> *vectory,int wavfiledatacount,int samplerate,QByteArray *wavfiledata)
{
    int16_t y = 0;
    vectorx->clear();
    vectory->clear();
    for(int i = 0;i < wavfiledatacount;i++)
    {
        y = wavfiledata->at(i * 2 * channels + 0 + channel * 2) & 0x00FF;
        y |= (wavfiledata->at(i * 2 * channels + 1 + channel * 2) << 8) & 0xFF00;
        vectory->append(double(y));
    }
    vectorx->append(Core->Linspace(0,double(wavfiledatacount) / samplerate,vectory->count()));
}

/*  cal channel int16 data;*/

QString SuperMultiMedia::Caldbv(double* y,int intcount,int mode,int maxval)
{
    if(mode)
    {
        double temp = 0;
        for(int i = 0;i < intcount;i++)
        {
            temp = temp + y[i] * y[i];
        }
        temp = temp / maxval / maxval;
        return QString::number(20 * log10(sqrt(temp / intcount)),'f',3);
    }
    else
    {
        double max = Core->Getdoublearraymaxvalue(y,intcount) / maxval;
        if(max <= 0)
        {
            return "0";
        }
        else
        {
            return QString::number(20 * log10(max),'f',3);
        }
    }
}

/*  cal dbv by audio input data;*/

double SuperMultiMedia::Calfreq(double* y,int inicount,int samplerate)
{
    double freqa = 0;
    double freqb = 0;
    QVector<double> valuepos = {};
    QVector<double> valueneg = {};
    QVector<int> changepointpos = {};
    QVector<int> changepointneg = {};
    QVector<double> sampleperroundpos = {};
    QVector<double> sampleperroundneg = {};
    for(int i = 0;i < inicount;i++)
    {
        if(y[i] >= 0)
        {
            valuepos.append(i);
        }
        else
        {
            valueneg.append(i);
        }
    }
    if(valuepos.count() != 0 && valueneg.count() != 0)
    {
        for(int i = 0;i < valuepos.count() - 1;i++)
        {
            if(valuepos.at(i) + 1 != valuepos.at(i + 1))
            {
                changepointpos.append(i);
            }
        }
        for(int i = 0;i < valueneg.count() - 1;i++)
        {
            if(valueneg.at(i) + 1 != valueneg.at(i + 1))
            {
                changepointneg.append(i);
            }
        }
        if(changepointpos.count() != 0 && changepointneg.count() != 0)
        {
            for(int i = 0;i < changepointpos.count() - 1;i++)
            {
                sampleperroundpos.append(changepointpos.at(i + 1) - changepointpos.at(i));
            }
            for(int i = 0;i < changepointneg.count() - 1;i++)
            {
                sampleperroundneg.append(changepointneg.at(i + 1) - changepointneg.at(i));
            }
            if(sampleperroundpos.count() + sampleperroundneg.count() == 0)
            {
                return 0;
            }
            else
            {
                freqa = Core->Getqvectormeanvalue(&sampleperroundpos,sampleperroundpos.count());
                freqb = Core->Getqvectormeanvalue(&sampleperroundneg,sampleperroundneg.count());
                return samplerate / (freqa + freqb);
            }
        }
    }
    return 0;
}

/*  cal freqency by audio input data;*/

QString SuperMultiMedia::Calthd(double realfreq,double* yfft,int samplerate,int count,int degree)
{
    double basicpowersquare = 1;
    double harmonicpowersquare = 0;
    if(realfreq > 100 && realfreq < samplerate / 2)
    {
        int index = round(realfreq / (double(samplerate) / count));
        basicpowersquare = yfft[index];
        switch(degree)
        {
            case 0:
            {
                for(int i = 0;i < count / 2 / index - 2;i++)
                {
                    harmonicpowersquare = harmonicpowersquare + yfft[index * (i + 2)];
                }
                break;
            }
            default:
            {
                int degreetemp = degree;
                if(degreetemp > count / 2 / index - 2)
                {
                    degreetemp = count / 2 / index - 2;
                }
                for(int i = 0;i < degreetemp;i++)
                {
                    harmonicpowersquare = harmonicpowersquare + yfft[index * (i + 2)];
                }
                break;
            }
        }
    }
    return QString::number(100 * harmonicpowersquare / basicpowersquare,'f',3);
}

/*  cal thd;*/

void SuperMultiMedia::Changeplayicon(QPushButton *playbutton,QByteArray *playstatus,int status)
{
    playstatus->clear();
    switch(status)
    {
        case 4:
        {
            playstatus->append("play");
            playbutton->setIcon(QIcon(":/__supericon__/_play_.svg"));
            break;
        }
        case 7:
        {
            playstatus->append("playing");
            playbutton->setIcon(QIcon(":/__supericon__/_playing_.svg"));
            break;
        }
        case 9:
        {
            playstatus->append("suspended");
            playbutton->setIcon(QIcon(":/__supericon__/_suspended_.svg"));
            break;
        }
    }
}

/*  change play status;*/

void SuperMultiMedia::Changeplaytext(QPushButton *playbutton,QByteArray *playstatus,int status)
{
    playstatus->clear();
    switch(status)
    {
        case 4:
        {
            playstatus->append("play");
            playbutton->setText("Play");
            break;
        }
        case 7:
        {
            playstatus->append("playing");
            playbutton->setText("Playing...");
            break;
        }
        case 9:
        {
            playstatus->append("suspended");
            playbutton->setText("Suspended");
            break;
        }
    }
}

/*  change play status;*/

void SuperMultiMedia::Changeanalysistext(QPushButton *playbutton,QByteArray *analysisstatus,int status)
{
    analysisstatus->clear();
    switch(status)
    {
        case 8:
        {
            analysisstatus->append("analysis");
            playbutton->setText("Analysis");
            break;
        }
        case 11:
        {
            analysisstatus->append("analysising");
            playbutton->setText("Analysising...");
            break;
        }
    }
}

/*  change analysis status;*/

SuperPlayWav::SuperPlayWav(QFile *file,int filepos,QByteArray* playstatus,QAudioSink* audiosink)
{
    File = file;
    Filepos = filepos;
    Playstatus = playstatus;
    Audiosink = audiosink;
    Init();
}

SuperPlayWav::~SuperPlayWav()
{
    delete Timer;
    delete Audiosink;
}

void SuperPlayWav::Init()
{
    Timerinit();
    Iodeviceinit();
    Filestatusinit();
}

/*  parameter init;*/

void SuperPlayWav::run()
{
    Playing();
}

/*  play wav file;*/

void SuperPlayWav::Timerinit()
{
    Timer = new QTimer();
    Timer->setInterval(1000);
    Timer->setTimerType(Qt::PreciseTimer);
    Timer->start();
}

/*  timer init;*/

void SuperPlayWav::Iodeviceinit()
{
    Channel = Audiosink->format().channelCount();
    Iodevice = Audiosink->start();
    connect(this,&SuperPlayWav::Signalpc,this,&SuperPlayWav::Writedata);
}

/*  iodevice init;*/

void SuperPlayWav::Filestatusinit()
{
    if(Filepos < File->size())
    {
        Status = "selection";
    }
}

/*  file status init;*/

void SuperPlayWav::Playing()
{
    while(true)
    {
        if(Playstatus->size() == 7 && File->pos() <= Filepos && !File->atEnd())
        {
            QThread::msleep(1);
            if(Audiosink->bytesFree())
            {
                emit Signalpc();
            }
        }
        else if(Playstatus->size() == 9)
        {
            QThread::msleep(100);
        }
        else if(File->pos() >= Filepos || File->atEnd())
        {
            emit Signalpb(Status);
            break;
        }
        else
        {
            emit Signalpa();
            break;
        }
    }
}

/*  playing wav file and check the status;*/

void SuperPlayWav::Writedata()
{
    Iodevice->write(File->read(Audiosink->bytesFree()));
}

/*  write data;*/

SuperPlaySignal::SuperPlaySignal(QByteArray signaldata,double time,QByteArray* playstatus,QAudioSink* audiosink)
{
    Signaldata = signaldata;
    Time = time;
    Playstatus = playstatus;
    Audiosink = audiosink;
    Init();
}

SuperPlaySignal::~SuperPlaySignal()
{
    delete Timer;
    delete Audiosink;
}

void SuperPlaySignal::Init()
{
    Timerinit();
    Iodeviceinit();
}

/*  parameter init;*/

void SuperPlaySignal::run()
{
    Initrun();
    Playing();
}

/*  play wav file;*/

void SuperPlaySignal::Timerinit()
{
    Timer = new QTimer();
    Timer->setInterval(Time * 1000);
    connect(Timer,&QTimer::timeout,this,&SuperPlaySignal::Stop);
    if(Time)
    {
        Timer->start();
    }
}

/*  play signal timer init;*/

void SuperPlaySignal::Iodeviceinit()
{
    Iodevice = Audiosink->start();
    connect(this,&SuperPlaySignal::Signalpb,this,&SuperPlaySignal::Writedata);
}

/*  play signal file init,creat audio output device and io device,read byte from file,choose cycle or by seconds;*/

void SuperPlaySignal::Initrun()
{
    Signalstatus = 1;
}

/*  init signal status;*/

void SuperPlaySignal::Playing()
{
    while(true)
    {
        if(Playstatus->size() == 7)
        {
            QThread::msleep(1);
            if(Audiosink->bytesFree())
            {
                emit Signalpb();
            }
        }
        else
        {
            if(Signalstatus)
            {
                emit Signalpa();
            }
            break;
        }
    }
}

/*  play signal by pushbutton text;*/

void SuperPlaySignal::Stop()
{
    Signalstatus = 0;
    emit Signalpa();
}

void SuperPlaySignal::Writedata()
{
    Iodevice->write(Signaldata);
}

/*  write data;*/


