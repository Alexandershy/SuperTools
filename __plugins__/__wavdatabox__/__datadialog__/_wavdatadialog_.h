#ifndef _WAVDATADIALOG__H
#define _WAVDATADIALOG__H

#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "__supermultimedia__/_supermultimedia_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superchartview__/_superchartview_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superfftw__/fftw3.h"
#include "_wavdatadialogui_.h"
#include <QAudioOutput>
#include <QAudioFormat>

class SuperReadWav;
class SuperToFft;

class WavDataDialog : public SuperWindow
{
    Q_OBJECT

public:

    WavDataDialog(
            QWidget *parent = nullptr,
            QString wavfile = "");

    ~WavDataDialog();

private:

    SuperMultiMedia *Multimedia                         = nullptr;
    WavDataDialogui *Plugin                             = nullptr;
    SuperProgressBarDialog *Progressbardialog           = nullptr;
    SuperChartView *Fftchartview                        = nullptr;
    QVector<SuperChartView*> Chartviewqvector           = {};
    QVector<int> Selectdata                             = {};
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
    int Slidermode                                      = 1;
    int Buffersize                                      = 0;

private slots:

    void init();

    void objectInit();

    void colorInit();

    void infoInit();

    void plotInit();

    void fftPlotInit();

    void creatPlotApi(
            SuperChartView *chartview,
            int index);

    void channelTextInit();

    void iconInit();

    void threadInit();

    void checkDeviceChangedInit();

    void reset();

    void dragMode();

    void selectMode();

    void changeRefreshRate();

    void changeSliderMode();

    void play();

    void playInit();

    void setWavFilePos();

    void setCurrentChannel();

    void stop();

    void getDataSelection();

    void setProgressBar(
            int progressbarvalue,
            QString message);

    void setProgressBarValue(
            double selectionbegin,
            double selectionend);

    void fftReset();

    void refresh();

    void fftCanvasTextapi(
            QString text);

    void fftDragMode();

    void fftSelectMode();

    void changeDbvMode();

    void calRealData(
            int count,
            fftw_complex* complex,
            double* yreal,
            QVector<double>* y);

    void signalRaSlot();

    void signalRcSlot();

    void signalPaSlot();

    void signalPbSlot(
            QString strstatus);

    void signalPcSlot();

    void trackMode();

    void rangeMode();

    void signalCaSlot();

    void signalCbSlot();

    void displayWavFileInfo();

    void calRefreshRate();

    void signalRdSlot(
        int index);

signals:

    void signalDa();

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
            int channels);

    ~SuperReadWav();

public:

    QVector<double> X                           = {};
    QVector<double> Y                           = {};

public slots:

    void run();

private:

    SuperMultiMedia *Multimedia                 = nullptr;
    QString Wavfile                             = "";
    int Samplerate                              = 0;
    int Bits                                    = 0;
    int Channels                                = 0;
    int Bitspersample                           = 0;
    double Timelength                           = 0;
    QByteArray Wavfiledata                      = "";
    int Wavfiledatacount                        = 0;

private slots:

    /*main function*/
    void init();

    void objectInit();

    void initRun();

    void readWavData();

    void cal16BitsData();

signals:

    void signalRa();

    void signalRb(
            int value,
            QString message);

    void signalRc();

    void signalRd(
        int index);

};

class SuperToFft : public QThread
{
    Q_OBJECT

public:

    SuperToFft(
            QWidget *parent = nullptr,
            SuperChartView *timechartview = nullptr,
            QVector<int> *selectdata = nullptr,
            int samplerate = 0,
            int maxval = 0,
            SuperChartView *fftchartview = nullptr,
            QByteArray *dbvmode = nullptr);

    ~SuperToFft();

public slots:

    void run();

private:

    SuperCore *Core                 = nullptr;
    SuperMultiMedia *Multimedia     = nullptr;
    SuperChartView *Timechartview   = nullptr;
    SuperChartView *Fftchartview    = nullptr;
    QVector<int> *Selectdata        = nullptr;
    int Samplerate                  = 0;
    int Maxval                      = 0;
    QByteArray *Dbvmode             = nullptr;
    QVector<double> Xlfftvector     = {};
    QVector<double> Ylfftvector     = {};
    int Datacount                   = 0;
    int Start                       = 0;
    double *Ylffti                  = nullptr;
    fftw_complex *Ylffto            = nullptr;
    double *Ylfftro                 = nullptr;
    fftw_plan Plan                  = {};

private slots:

    void init();

    void parameterInit();

    void objectInit();

    void calRealData(
            int count,
            fftw_complex* complex,
            double* yreal,
            QVector<double>* yvector);

    void fftCanvasInfo(
            double *ylffti,
            double *ylfftro,
            int count);

signals:

    void signalTa(
            QString text);

    void signalTb(
            int value,
            QString text);
};

#endif // _WAVDATADIALOG__H
