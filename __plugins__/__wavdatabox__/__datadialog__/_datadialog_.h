#ifndef _DATADIALOG__H
#define _DATADIALOG__H

#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superplot__/_superplot_.h"
#include "__superfftw__/fftw3.h"
#include "_databox_.h"
#include <QAudioOutput>
#include <QAudioFormat>

class SuperReadWav;
class SuperToFft;

class DataDialog : public SuperWindow
{
    Q_OBJECT

public:

    DataDialog(
            QWidget *parent = nullptr,
            QString wavfile = "");

    ~DataDialog();

private:

    QCPDataSelection Selection;
    SuperMultiMedia *SuperM                             = nullptr;
    DataBox *Plugin                                     = nullptr;
    SuperProgressBarDialog *Progressbardialog           = nullptr;
    QCustomPlot *Fftcanvas                              = nullptr;
    QVector<QCustomPlot*> Canvasqvector                 = {};
    QVector<QCPItemStraightLine*> Beginverlineqvector   = {};
    QVector<QCPItemStraightLine*> Slidinglineqvector    = {};
    QVector<QCPItemStraightLine*> Endverlineqvector     = {};
    QVector<QColor> Colorvector                         = {};
    QPen Pena                                           = {};
    QPen Penb                                           = {};
    QVector<QPen> Penvector                             = {};
    QColor Backgroundcolor                              = Qt::red;
    QColor Fontcolor                                    = Qt::black;
    QColor Concolor                                     = Qt::white;
    QString Strrgbbackgroundcolor                       = "";
    QString Strrgbfontcolor                             = "";
    QString Strrgbconcolor                              = "";
    QString Wavfile                                     = "";
    QByteArray Beforestopstatus                         = "";
    int Samplerate                                      = 0;
    int Bits                                            = 0;
    int Channels                                        = 0;
    int Bitspersample                                   = 0;
    int Maxval                                          = 0;
    int Refreshrate                                     = 1000;
    int Currentchannel                                  = 0;
    double Filepos                                      = 0;
    double Timelength                                   = 0;
    double *Fftx                                        = nullptr;
    double *Ffty                                        = nullptr;
    QByteArray Datatemp                                 = "";
    QByteArray Dbvmode                                  = "0";
    QAudioFormat Outputformat                           = {};
    QFile *File                                         = nullptr;
    SuperReadWav *Threadra                              = nullptr;
    SuperPlayWav *Threadpa                              = nullptr;
    SuperToFft *Threadta                                = nullptr;
    QTimer *Timerca                                     = nullptr;
    QTimer *Timerta                                     = nullptr;
    int Fps                                             = 0;
    QMediaDevices *Mediadevices                         = nullptr;
    QByteArray Playstatus                               = "play";
    int Slidermode                                      = 0;
    int Buffersize                                      = 0;

private slots:

    void Init();

    void Objectinit();

    void Colorinit();

    void Infoinit();

    void Plotinit();

    void Fftplotinit();

    void Creatplotapi(
            QCustomPlot *plot,
            int index);

    void Channeltextinit(
            QCustomPlot *plot,
            int channel);

    void Icoinit();

    void Threadinit();

    void Checkdevicechangedinit();

    void Reset();

    void Dragmode();

    void Selectmode();

    void Changerefreshrate();

    void Changeslidermode();

    void Play();

    void Playinit();

    void Setwavfilepos();

    void Setcurrentchannel();

    void Stop();

    void Getdataselection();

    void Setprogressbar(
            int progressbarvalue,
            QString message);

    void Setprogressbarvalue(
            double selectionbegin,
            double selectionend);

    void Refresh();

    void Fftcanvastextapi(
            QString text);

    void Fftreset();

    void Fftdragmode();

    void Fftselectmode();

    void Changedbvmode();

    void Calrealdata(
            int count,
            fftw_complex* complex,
            double* yreal,
            QVector<double>* y);

    void Signalraslot();

    void Signalrcslot();

    void Signalpaslot();

    void Signalpbslot(
            QString strstatus);

    void Signalpcslot();

    void Trackmode();

    void Rangemode();

    void Signalcaslot();

    void Signalcbslot();

    void Displaywavfileinfo();

    void Calrefreshrate();

signals:

    void Signalda();

};

class SuperReadWav : public QThread
{
    Q_OBJECT

public:

    SuperReadWav(
            QString wavfile,
            int timelength,
            int samplerate,
            int bitspersample,
            int bits,
            int channels,
            QVector<QCustomPlot*> *canvasqvector);

    ~SuperReadWav();

public slots:

    void run();

private:

    SuperMultiMedia *SuperM                 = nullptr;
    QString Wavfile                         = "";
    int Samplerate                          = 0;
    int Bits                                = 0;
    int Channels                            = 0;
    int Bitspersample                       = 0;
    double Timelength                       = 0;
    QByteArray Wavfiledata                  = "";
    int Wavfiledatacount                    = 0;
    QVector<double> X                       = {};
    QVector<double> Y                       = {};
    QVector<QCustomPlot*> *Canvasqvector    = {};

private slots:

    /*main function*/

    void Init();

    void Objectinit();

    void Initrun();

    void Readwavdata();

    void Cal16bitsdata();

signals:

    void Signalra();

    void Signalrb(
            int value,
            QString message);

    void Signalrc();
};

class SuperToFft : public QThread
{
    Q_OBJECT

public:

    SuperToFft(
            QWidget *parent = nullptr,
            QCustomPlot *timeplot = nullptr,
            QCPDataSelection *selection = nullptr,
            int samplerate = 0,
            int maxval = 0,
            QCustomPlot *fftplot = nullptr,
            QByteArray *dbvmode = nullptr);

    ~SuperToFft();

public slots:

    void run();

private:

    SuperCore *SuperC           = nullptr;
    SuperMultiMedia *SuperM     = nullptr;
    QCustomPlot * Timeplot        = nullptr;
    QCustomPlot * Fftplot         = nullptr;
    QCPDataSelection *Selection = nullptr;
    int Samplerate              = 0;
    int Maxval                  = 0;
    QByteArray *Dbvmode         = nullptr;
    QVector<double> Xlfftvector = {};
    QVector<double> Ylfftvector = {};
    int Datacount               = 0;
    int Start                   = 0;
    double *Ylffti              = nullptr;
    fftw_complex *Ylffto        = nullptr;
    double *Ylfftro             = nullptr;
    fftw_plan Plan              = {};

private slots:

    void Init();

    void Parameterinit();

    void Objectinit();

    void Calrealdata(
            int count,
            fftw_complex* complex,
            double* yreal,
            QVector<double>* yvector);

    void Fftcanvasinfo(
            double *ylffti,
            double *ylfftro,
            int count);

signals:

    void Signalta(
            QString text);

    void Signaltb(
            int value,
            QString text);
};

#endif // _DATADIALOG__H
