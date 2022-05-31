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
    QStringList wavInfo(
        QString wavfile);

    void writeWavFile(
        QString wavfile,
        int filelen,
        short channels,
        int samplerate,
        int transmitrate,
        short blockalign,
        QByteArray data);

    QByteArray writeWavInfo(
        int filelen,
        short channels,
        int samplerate,
        int transmitrate,
        short blockalign);

    void int2ByteArray(
        QByteArray *bytearry,
        int inta);

    void short2ByteArray(
        QByteArray *bytearry,
        short shorta);

    /*  audio device;*/
    void checkDeviceExist(
        QList<bool> *boollist);

    void getAudioOutputDeviceInfo(
        QList<QAudioDevice> *outputdevicelist,
        QStringList* listname,
        QStringList* listnumber);

    void getAudioInputDeviceInfo(
        QList<QAudioDevice> *inputdevicelist,
        QStringList* listname,
        QStringList* listnumber);

    int enumBitsToInt(
        QAudioFormat::SampleFormat bits);

    QAudioFormat::SampleFormat intBitsToEnum(
        int bits);

    /*  audio analysis*/
    void cal16BitsData(
        int channels,
        int channel,
        QVector<double> *vectorx,
        QVector<double> *vectory,
        int wavfiledatacount,
        int samplerate,
        QByteArray *wavfiledata);

    QString calDecibelVoltage(
        double* y,
        int intcount,
        int mode,
        int maxval);

    double calFrequency(
        double* y,
        int inicount,
        int samplerate);

    QString calTotalHarmonicDistortion(
        double realfreq,
        double* yfft,
        int samplerate,
        int count,
        int degree);

    void changePlayIcon(
        QPushButton *playbutton,
        QByteArray *playstatus,
        int status);

    void changePlayText(
        QPushButton *playbutton,
        QByteArray *playstatus,
        int status);

    void changeAnalysisText(
        QPushButton *playbutton,
        QByteArray *analysisstatus,
        int status);

private:

    SuperCore *Core = nullptr;

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

    void init();

    void timerInit();

    void fileStatusInit();

    void ioDeviceInit();

    void playing();

    void writeData();

private:

    QByteArray *Playstatus  = nullptr;
    QAudioSink *Audiosink   = nullptr;
    QIODevice *Iodevice     = nullptr;
    int Filepos             = 0;
    int Channel             = 0;
    int Samplerate          = 0;
    QString Status          = "whole";
    QFile *File             = nullptr;

signals:

    void signalPa();

    void signalPb(
        QString strstatus);

    void signalPc();

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

    void init();

    void timerInit();

    void ioDeviceInit();

    void initRun();

    void playing();

    void stop();

    void writeData();

signals:

    void signalPa();

    void signalPb();

};

#endif // SUPERMULTIMEDIA_H
