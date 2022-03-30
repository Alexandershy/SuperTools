#ifndef _WASAPIBOX__H
#define _WASAPIBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superplot__/_superplot_.h"
#include "__superlogger__/_superlogger_.h"
#include "__formatdialog__/_formatdialog_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__supertabwidget__/_supertabwidget_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "__module__/_modulec_.h"
#include "__superfftw__/fftw3.h"
#include "_wasapibox__global.h"

/**************interface****************/
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

    SuperMultiMedia *SuperM                     = nullptr;
    SuperLogger *Logger                         = nullptr;
    ModuleA *Modulea                            = nullptr;
    ModuleB *Moduleb                            = nullptr;
    ModuleC *Modulec                            = nullptr;
    SuperTabWidget *Tabwidget                   = nullptr;
    QList<QWidget*> Outputwidgetlist            = {};
    QList<QWidget*> Inputwidgetlist             = {};
    QColor Backgroundcolor                      = Qt::red;
    QColor Fontcolor                            = Qt::black;
    QColor Concolor                             = Qt::white;
    QString Strrgbbackgroundcolor               = "";
    QString Strrgbfontcolor                     = "";
    QString Strrgbconcolor                      = "";
    QString Temppath                            = "./__depycache__/__wasapi__/";
    QString Currentpath                         = "./__depycache__/__wasapi__/";
    QFile *File                                 = nullptr;
    int Samplewidth                             = 2;
    QAudioFormat::SampleFormat Initbits         = QAudioFormat::Int16;
    int Maxval                                  = 0;
    int Volume                                  = 0;
    QVector<int> Updatefigureparameter          = {1,0,0,4,0,268435456,1800};//autoplot,thddegree,dbv,analysis status,limitmode,maxsize,maxlength;
    SuperPlot* Timefigwidget                    = nullptr;
    SuperPlot* Fftfigwidget                     = nullptr;
    QAudioFormat Format                         = {};
    PlayWav *Threadpw                           = nullptr;
    PlaySignal *Threadps                        = nullptr;
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

    void Init();

    void Objectinit();

    void Parameterinit();

    void Colorinit();

    void Enablerefreshdevicebutton();

    void Refreshdevices();

    void Refreshoutputnumber();

    void Addoutputchannel();

    void Refreshinputnumber();

    void Refreshdevicesinit();

    void Setaudioformat();

    void Audioformat(
            QAudioFormat* format);

    void Refreshaudioformatapi(
            QAudioFormat *format,
            int intsamplerate,
            int bits,
            int intchannelcount,
            QString straudioname);

    void Refreshoutputparameter(
            int samplerate,
            int bits,
            int channels);

    void Refreshinputparameter(
            int samplerate,
            int bits,
            int channels);

    void Enablewidget(
            QStringList listname,
            QList<QWidget*> *widgetlist);

    void Selectwavfile();

    void Setwavfile(
            QString file);

    void Playaudio();

    void Playwavinit();

    void Playsignalinit();

    void Setplaymode();

    void Stopplayaudio();

    QByteArray Sinewave(
            double sampletime,
            double amplitude,
            int frequency);

    void Displaygeneratemode();

    void Displayamplitude();

    void Displayfrequency();

    void Displaytime();

    QByteArray Signalwave();

    void Analysisaudio();

    void Analysisaudioinit(
            bool boola,
            bool boolb);

    void Plotinit();

    void Stopanalysisaudio();

    void Changeplotmode();

    void Changelimitmode();

    void Changelimit();

    void Changedbvmode();

    void Changethddegree();

    void Generatewavfileinit();

    void Generatewavfile(
            QString wavfilepath);

    void Openrecordpath();

    void Opengeneratepath();

    void Signalpwaslot();

    void Signalpwbslot(
            QString status);

    void Signalpwslotapi();

    void Signalspslot();

    void Signaluarslot(
            QString strdbv,
            QString strfreq,
            QString strthd);

    void Signalubrslot(
            QString text);

    void Savewavfile();

};

class UpdateFigure : public QThread
{
    Q_OBJECT

public: 

    UpdateFigure(
            QByteArray *allrecorddata,
            QAudioSource *audiosource,
            SuperPlot* timefigwidget,
            SuperPlot* fftfigwidget,
            QVector<int> *updatefigureparameter);

    ~UpdateFigure();

    void run();

private:

    SuperCore *SuperC                           = nullptr;
    SuperMultiMedia *SuperM                     = nullptr;
    QAudioSource *Audiosource                   = nullptr;
    int Buffersize                              = 0;
    SuperPlot *Timeplot                         = nullptr;
    SuperPlot *Fftplot                          = nullptr;
    QVector<int> *Updatefigureparameter         = nullptr;
    QVector <double> Xtime                      = {};
    QVector <double> Xfft                       = {};
    double *Ylffti                              = nullptr;
    fftw_complex *Ylffto                        = nullptr;
    double *Yrffti                              = nullptr;
    fftw_complex *Yrffto                        = nullptr;
    double *Ylfftro                             = nullptr;
    double *Yrfftro                             = nullptr;
    fftw_plan Plan                              = {};
    int Maxinputchannel                         = 0;
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

    void Init();

    void Recordaduioinit();

    void Recording(
            QIODevice* iodevice,
            QAudioSource* audiosource);

    void Caldata(
            QIODevice* iodevice);

    void Analysischannela(
            QIODevice* iodevice);

    void Analysischannelb(
            QIODevice* iodevice);

    bool Read(
            QIODevice* iodevice,
            QByteArray *data);

    void Updatefiga(
            QVector<double> yl,
            QVector<double> yr,
            QVector<double> ylfft,
            QVector<double> yrfft);

    void Updatefigb(
            QVector<double> yl,
            QVector<double> ylfft);

    void Calrealdata(
            int count,
            fftw_complex* complex,
            double* yreal,
            QVector<double> *y);

    void Emitresult();

signals:

    void Signalua(
            QString,
            QString,
            QString);

    void Signalub(
            QString text);

    void Signaluc();

};

#endif // _WASAPIBOX__H
