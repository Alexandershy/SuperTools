#ifndef _WASAPIBOX__H
#define _WASAPIBOX__H
#define _WASAPIBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__formatdialog__/_wasapiformatdialog_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superchartview__/_superchartview_.h"
#include "__supertabwidget__/_supertabwidget_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__module__/_wasapimodulea_.h"
#include "__module__/_wasapimoduleb_.h"
#include "__module__/_wasapimodulec_.h"
#include "__superfftw__/fftw3.h"

class _WASAPIBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class wasapibox new instance pointer;*/
};

class UpdateFigure;

class WasapiBox : public SuperTab
{
    Q_OBJECT

public:

    WasapiBox(
            QWidget *parent = nullptr);

    ~WasapiBox();

private:

    SuperMultiMedia *Multimedia                 = nullptr;
    SuperLogger *Logger                         = nullptr;
    WasapiModuleA *Modulea                      = nullptr;
    WasapiModuleB *Moduleb                      = nullptr;
    WasapiModuleC *Modulec                      = nullptr;
    SuperTabWidget *Tabwidget                   = nullptr;
    QList<QWidget*> Outputwidgetlist            = {};
    QList<QWidget*> Inputwidgetlist             = {};
    QString Temppath                            = "./__depycache__/__wasapi__/";
    QString Currentpath                         = "./__depycache__/__wasapi__/";
    QFile *File                                 = nullptr;
    int Samplewidth                             = 2;
    QAudioFormat::SampleFormat Initbits         = QAudioFormat::Int16;
    int Maxval                                  = 0;
    int Volume                                  = 0;
    QVector<int> Updatefigureparameter          = {1,0,0,4,0,268435456,1800};//autoplot,thddegree,dbv,analysis status,limitmode,maxsize,maxlength;
    SuperChartView* Timechartview               = nullptr;
    SuperChartView* Fftchartview                = nullptr;
    QAudioFormat Format                         = {};
    SuperPlayWav *Threadpw                      = nullptr;
    SuperPlaySignal *Threadps                   = nullptr;
    UpdateFigure *Threaduf                      = nullptr;
    QStringList Listoutputname                  = {};
    QStringList Listoutputnumber                = {};
    QList <QAudioDevice> Outputdevicelist       = {};
    QAudioFormat Outputformat                   = {};
    double Amplitude                            = 0;
    double Frequency                            = 0;
    double Durationtime                         = 0;
    int Outputsamplerate                        = 0;
    int Outputbits                              = 0;
    int Outputchannelcount                      = 0;
    QStringList Listinputname                   = {};
    QStringList Listinputnumber                 = {};
    QList <QAudioDevice> Inputdevicelist        = {};
    QAudioFormat Inputformat                    = {};
    QByteArray Allrecorddata                    = "";
    int Inputsamplerate                         = 0;
    int Inputbits                               = 0;
    int Inputchannelcount                       = 0;
    QByteArray Playstatus                       = "play";
    QByteArray Analysisstatus                   = "analysis";

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void enableRefreshDeviceButton();

    void refreshDevices();

    void refreshOutputNumber();

    void addOutputChannel();

    void refreshInputNumber();

    void refreshDevicesInit();

    void setAudioFormat();

    void audioFormat(
            QAudioFormat* format);

    void refreshAudioFormatApi(
            QAudioFormat *format,
            int intsamplerate,
            int bits,
            int intchannelcount,
            QString straudioname);

    void refreshOutputParameter(
            int samplerate,
            int bits,
            int channels);

    void refreshInputParameter(
            int samplerate,
            int bits,
            int channels);

    void enableWidget(
            QStringList listname,
            QList<QWidget*> *widgetlist);

    void selectWavFile();

    void setWavFile(
            QString file);

    void playAudio();

    void playWavInit();

    void playSignalInit();

    void setPlayMode();

    void stopPlayAudio();

    QByteArray sineWave(
            double sampletime,
            double amplitude,
            int frequency);

    void displayGenerateMode();

    void displayAmplitude();

    void displayFrequency();

    void displayTime();

    QByteArray signalWave();

    void analysisAudio();

    void analysisAudioInit(
            bool boola,
            bool boolb);

    void plotInit();

    void stopAnalysisAudio();

    void changePlotMode();

    void changeLimitMode();

    void changeLimit();

    void changeDbvMode();

    void changeThdDegree();

    void generateWavFileInit();

    void generateWavFile(
            QString wavfilepath);

    void openRecordPath();

    void openGeneratePath();

    void signalPwaSlot();

    void signalPwbSlot(
            QString status);

    void signalPwSlotApi();

    void signalspSlot();

    void signalUarSlot(
            QString strdbv,
            QString strfreq,
            QString strthd);

    void signalUbrSlot(
            QString text);

    void saveWavFile();

};

class UpdateFigure : public QThread
{
    Q_OBJECT

public: 

    UpdateFigure(
            QByteArray *allrecorddata,
            QAudioSource *audiosource,
            QVector<int> *updatefigureparameter);

    ~UpdateFigure();

public:

    void run();

public:

    int Maxinputchannel                         = 0;
    QVector<QPointF> Pointl                     = {};
    QVector<QPointF> Pointr                     = {};
    QVector<QPointF> Pointlfft                  = {};
    QVector<QPointF> Pointrfft                  = {};

private:

    SuperCore *Core                             = nullptr;
    SuperMultiMedia *Multimedia                 = nullptr;
    QAudioSource *Audiosource                   = nullptr;
    int Buffersize                              = 0;
    QVector<int> *Updatefigureparameter         = nullptr;
    QVector<double> Xtime                       = {};
    QVector<double> Xfft                        = {};
    double *Ylffti                              = nullptr;
    fftw_complex *Ylffto                        = nullptr;
    double *Yrffti                              = nullptr;
    fftw_complex *Yrffto                        = nullptr;
    double *Ylfftro                             = nullptr;
    double *Yrfftro                             = nullptr;
    fftw_plan Plan                              = {};
    int Inputsamplerate                         = 0;
    int Samplecount                             = 0;
    int Intcount                                = 0;
    int Bits                                    = 0;
    int Maxval                                  = 0;
    double Frequencyl                           = 0;
    double Frequencyr                           = 0;
    double Autorange                            = 2000;
    QString Resultdbv                           = "(dbv)";
    QString Resultfrequency                     = "(hz)";
    QString Resultthd                           = "(thd)";
    QByteArray Recorddata                       = "";
    QByteArray *Allrecorddata                   = nullptr;
    QString Analysisresult                      = "audio analysis completed";

private slots:

    void init();

    void recordAudioInit();

    void recording(
            QIODevice* iodevice,
            QAudioSource* audiosource);

    void calData(
            QIODevice* iodevice);

    void analysisChannela(
            QIODevice* iodevice);

    void analysisChannelb(
            QIODevice* iodevice);

    bool read(
            QIODevice* iodevice,
            QByteArray *data);

    void calRealData(
            int count,
            fftw_complex* complex,
            double* yreal,
            QVector<QPointF> *point);

    void emitResult();

signals:

    void signalUa(
            QString,
            QString,
            QString);

    void signalUb(
            QString text);

    void signalUc();

};

#endif // _WASAPIBOX__H
