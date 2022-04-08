#ifndef _SUPERMULTIMEDIA__H
#define _SUPERMULTIMEDIA__H
#define _SUPERMULTIMEDIA__EXPORT Q_DECL_EXPORT
#define _SUPERPLAYWAV__EXPORT Q_DECL_EXPORT
#define _SUPERPLAYSIGNAL__EXPORT Q_DECL_EXPORT

#include "__supercore__/_supercore_.h"
#include <QMediaDevices>
#include <QAudioDevice>
#include <QAudioSource>
#include <QPushButton>
#include <QAudioSink>
#include <QThread>
#include <QTimer>
#include <QFile>

class _SUPERMULTIMEDIA__EXPORT SuperMultiMedia : public QObject
{
    Q_OBJECT

public:

    SuperMultiMedia(
        QObject *object = nullptr);

    ~SuperMultiMedia();

public slots:

    /*  wav file;*/

    QStringList Wavinfo(
        QString wavfile);

    void Writewavfile(
        QString wavfile,
        int filelen,
        short channels,
        int samplerate,
        int transmitrate,
        short blockalign,
        QByteArray data);

    QByteArray Writewavinfo(
        int filelen,
        short channels,
        int samplerate,
        int transmitrate,
        short blockalign);

    void Int2bytearray(
        QByteArray *bytearry,
        int inta);

    void Short2bytearray(
        QByteArray *bytearry,
        short shorta);

    /*  audio device;*/
    void Checkdeviceexist(
        QList<bool> *boollist);

    void Getaudiooutputdeviceinfo(
        QList<QAudioDevice> *outputdevicelist,
        QStringList* listname,
        QStringList* listnumber);

    void Getaudioinputdeviceinfo(
        QList<QAudioDevice> *inputdevicelist,
        QStringList* listname,
        QStringList* listnumber);

    int Enumbitstoint(
        QAudioFormat::SampleFormat bits);

    QAudioFormat::SampleFormat Intbitstoenum(
        int bits);

    /*  audio analysis*/
    void Cal16bitsdata(
        int channels,
        int channel,
        QVector<double> *vectorx,
        QVector<double> *vectory,
        int wavfiledatacount,
        int samplerate,
        QByteArray *wavfiledata);

    QString Caldbv(
        double* y,
        int intcount,
        int mode,
        int maxval);

    double Calfreq(
        double* y,
        int inicount,
        int samplerate);

    QString Calthd(
        double realfreq,
        double* yfft,
        int samplerate,
        int count,
        int degree);

    void Changeplayicon(
        QPushButton *playbutton,
        QByteArray *playstatus,
        int status);

    void Changeplaytext(
        QPushButton *playbutton,
        QByteArray *playstatus,
        int status);

    void Changeanalysistext(
        QPushButton *playbutton,
        QByteArray *analysisstatus,
        int status);

private:

    SuperCore *SuperC = nullptr;

};

class _SUPERPLAYWAV__EXPORT SuperPlayWav : public QThread
{
    Q_OBJECT

public:

    QTimer *Timer = nullptr;

public:

    SuperPlayWav(
        QFile *file,
        int filepos,
        QByteArray* playstatus,
        QAudioSink* audiosink);

    ~SuperPlayWav();

public slots:

    void run();

private slots:

    void Init();

    void Timerinit();

    void Filestatusinit();

    void Iodeviceinit();

    void Playing();

    void Writedata();

private:

    QByteArray *Playstatus  = nullptr;
    QAudioSink *Audiosink   = nullptr;
    QIODevice *Iodevice     = nullptr;
    int Filepos             = 0;
    int Channel             = 0;
    QString Status          = "whole";
    QFile *File             = nullptr;

signals:

    void Signalpa();

    void Signalpb(
        QString strstatus);

    void Signalpc();

};

class _SUPERPLAYSIGNAL__EXPORT SuperPlaySignal : public QThread
{
    Q_OBJECT

public:

    SuperPlaySignal(
        QByteArray signaldata,
        double time,
        QByteArray* playstatus,
        QAudioSink* audiosink);

    ~SuperPlaySignal();

public slots:

    void run();

private:

    QByteArray Signaldata       = "";
    double Time                 = 0;
    QByteArray *Playstatus      = nullptr;
    QAudioSink *Audiosink       = nullptr;
    QIODevice *Iodevice         = nullptr;
    QAudioFormat Outputformat   = {};
    QTimer *Timer               = nullptr;
    int Signalstatus            = 1;

private slots:

    void Init();

    void Timerinit();

    void Iodeviceinit();

    void Initrun();

    void Playing();

    void Stop();

    void Writedata();

signals:

    void Signalpa();

    void Signalpb();

};

#endif // SUPERMULTIMEDIA_H
