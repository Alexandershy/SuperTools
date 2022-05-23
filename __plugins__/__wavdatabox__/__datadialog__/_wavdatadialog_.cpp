#include "_wavdatadialog_.h"

WavDataDialog::WavDataDialog(QWidget *parent,QString wavfile)
    : SuperWindow(parent)
{
    Wavfile = wavfile;
    setAttribute(Qt::WA_DeleteOnClose);
    setTitle(wavfile);
    init();
}

WavDataDialog::~WavDataDialog()
{
    stop();
    emit signalDa();
    Core->closeThread(Threadpa);
    Core->closeThread(Threadra);
    File->close();
    delete Progressbardialog;
}

void WavDataDialog::init()
{
    objectInit();
    colorInit();
    infoInit();
    plotInit();
    iconInit();
    threadInit();
    checkDeviceChangedInit();
}

void WavDataDialog::objectInit()
{
    Multimedia = new SuperMultiMedia(this);
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    Plugin = new WavDataDialogui(this);
    Pluginlayout->addWidget(Plugin);
    Progressbardialog = new SuperProgressBarDialog();
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,  this,&WavDataDialog::play);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,  this,&WavDataDialog::refresh);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,  this,&WavDataDialog::dragMode);
    connect(Plugin->ui->pushButton_4,   &QPushButton::clicked,  this,&WavDataDialog::selectMode);
    connect(Plugin->ui->pushButton_7,   &QPushButton::clicked,  this,&WavDataDialog::fftSelectMode);
    connect(Plugin->ui->pushButton_8,   &QPushButton::clicked,  this,&WavDataDialog::fftDragMode);
    connect(Plugin->ui->pushButton_9,   &QPushButton::clicked,  this,&WavDataDialog::fftReset);
    connect(Plugin->ui->pushButton_5,   &QPushButton::clicked,  this,&WavDataDialog::reset);
    connect(Plugin->ui->pushButton_6,   &QPushButton::clicked,  this,&WavDataDialog::changeRefreshRate);
    connect(Plugin->ui->pushButton_10,  &QPushButton::clicked,  this,&WavDataDialog::changeDbvMode);
    connect(Plugin->ui->pushButton_11,  &QPushButton::clicked,  this,&WavDataDialog::changeSliderMode);
    connect(Timerca,                    &QTimer::timeout,       this,&WavDataDialog::calRefreshRate);
}

void WavDataDialog::colorInit()
{
    Core->colorInit(&Backgroundcolor,&Fontcolor,&Concolor,&Strrgbbackgroundcolor,&Strrgbfontcolor,&Strrgbconcolor);
    Colorvector.append(Backgroundcolor);
    Colorvector.append(Concolor);
    Pena = QPen(Qt::DashLine);
    Penb = QPen(Qt::DashLine);
    Pena.setColor(Concolor);
    Penb.setColor(Backgroundcolor);
    Penvector.append(Pena);
    Penvector.append(Penb);
}

/*  init color;*/

void WavDataDialog::infoInit()
{
    QStringList wavfileinfo = Multimedia->wavInfo(Wavfile);
    Timelength = wavfileinfo.at(1).toInt();
    Channels = wavfileinfo.at(6).toInt();
    Samplerate = wavfileinfo.at(7).toInt();
    Bitspersample = wavfileinfo.at(9).toInt();
    Bits = wavfileinfo.at(10).toInt();
    Maxval = pow(2,Bits -1) -1;
    Outputformat.setChannelCount(Channels);
    Outputformat.setSampleRate(Samplerate);
    Outputformat.setSampleFormat(Multimedia->intBitsToEnum(Bits));
    displayWavFileInfo();
}

/*  init format;*/

void WavDataDialog::plotInit()
{
    fftPlotInit();
    for(int i = 0;i < Channels;i++)
    {
        Chartviewqvector.append(new SuperChartView(this));
        creatPlotApi(Chartviewqvector.at(i),i);
        Chartviewqvector.at(i)->addProgressLine(i + 1);
        Chartviewqvector.at(i)->setLineDistance(Samplerate);
        connect(Chartviewqvector.at(i), &SuperChartView::signalCb,this,&WavDataDialog::setWavFilePos);
        connect(Chartviewqvector.at(i), &SuperChartView::signalCb,this,&WavDataDialog::setCurrentChannel);
        Plugin->ui->verticalLayout_5->addWidget(Chartviewqvector.at(i));
    }
}

/*  init plot;*/

void WavDataDialog::fftPlotInit()
{
    Fftchartview = new SuperChartView(this);
    creatPlotApi(Fftchartview,0);
    Plugin->ui->verticalLayout_8->addWidget(Fftchartview);
    Fftchartview->addText(0.9,0.1,"text");
}

/*  fft plot;*/

void WavDataDialog::creatPlotApi(SuperChartView *chartview,int index)
{
    chartview->setLine(1);
    chartview->setLineColor(chartview->Lineseriesvector.at(0),index,Qt::SolidLine);
    chartview->setObjectName(QString::number(index));
    chartview->setMinimumHeight(200);
    chartview->setPlotMode(true);
    chartview->setSelectMode();
}

/*  creat plot api;*/

void WavDataDialog::channelTextInit()
{
    for(int i = 0;i < Chartviewqvector.count();i++)
    {
        Chartviewqvector.at(i)->addText(0.5,0.05,"channel " + QString::number(i));
    }
}

/*  add channel title to plot;*/

void WavDataDialog::iconInit()
{
    Plugin->ui->pushButton_3->setIcon(QIcon(":/__supericon__/_drag_.svg"));
    Plugin->ui->pushButton_4->setIcon(QIcon(":/__supericon__/_select_.svg"));
    Plugin->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_reset_.svg"));
    Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_lowrefreshrate_.svg"));
    Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_select_.svg"));
    Plugin->ui->pushButton_8->setIcon(QIcon(":/__supericon__/_drag_.svg"));
    Plugin->ui->pushButton_9->setIcon(QIcon(":/__supericon__/_reset_.svg"));
    Plugin->ui->pushButton_10->setIcon(QIcon(":/__supericon__/_peak_.svg"));
    Plugin->ui->pushButton_11->setIcon(QIcon(":/__supericon__/_toggleright_.svg"));
}

/*  init icon;*/

void WavDataDialog::threadInit()
{
    Threadra = new SuperReadWav(Wavfile,Timelength,Samplerate,Bitspersample,Bits,Channels);
    connect(Threadra,   &SuperReadWav::signalRa,this,       &WavDataDialog::signalRaSlot);
    connect(Threadra,   &SuperReadWav::signalRb,this,       &WavDataDialog::setProgressBar);
    connect(Threadra,   &SuperReadWav::signalRc,this,       &WavDataDialog::signalRcSlot);
    connect(Threadra,   &SuperReadWav::signalRd,this,       &WavDataDialog::signalRdSlot,Qt::DirectConnection);
    connect(Threadra,   &SuperReadWav::finished,this,       &WavDataDialog::channelTextInit);
    connect(Threadra,   &SuperReadWav::finished,this,       &WavDataDialog::reset);
    connect(Threadra,   &SuperReadWav::finished,Threadra,   &QObject::deleteLater);
    Threadra->start();
    Progressbardialog->show();
}

/*  init thread;*/

void WavDataDialog::checkDeviceChangedInit()
{
    Mediadevices = new QMediaDevices(this);
    connect(Mediadevices,&QMediaDevices::audioOutputsChanged,this,&WavDataDialog::signalCaSlot);
}

/*  Check device changed init;*/

void WavDataDialog::reset()
{
    for(int i = 0;i < Channels;i++)
    {
        Chartviewqvector.at(i)->rescaleAxes();
    }
}

/*  replot Canvas;*/

void WavDataDialog::dragMode()
{
    Plugin->ui->pushButton_3->setEnabled(false);
    Plugin->ui->pushButton_4->setEnabled(true);
    for(int i = 0;i < Channels;i++)
    {
        Chartviewqvector.at(i)->setDragMode();
    }
}

/*  set canvas as drag mode;*/

void WavDataDialog::selectMode()
{
    Plugin->ui->pushButton_3->setEnabled(true);
    Plugin->ui->pushButton_4->setEnabled(false);
    for(int i = 0;i < Channels;i++)
    {
        Chartviewqvector.at(i)->setSelectMode();
    }
}

/*  set canvas as select mode;*/

void WavDataDialog::changeRefreshRate()
{
    switch(Timerta->interval())
    {
        case 1000:
        {
            Refreshrate = 100;
            Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_midrefreshrate_.svg"));
            Timerta->setInterval(Refreshrate);
            break;
        }
        case 100:
        {
            Refreshrate = 50;
            Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_highrefreshrate_.svg"));
            Timerta->setInterval(Refreshrate);
            break;
        }
        case 50:
        {
            Refreshrate = 8;
            Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_maxrefreshrate_.svg"));
            Timerta->setInterval(Refreshrate);
            break;
        }
        case 8:
        {
            Refreshrate = 1000;
            Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_lowrefreshrate_.svg"));
            Timerta->setInterval(Refreshrate);
            break;
        }
    }
}

/*  change canvas refresh rate;*/

void WavDataDialog::changeSliderMode()
{
    if(Slidermode)
    {
        Slidermode = 0;
        Plugin->ui->pushButton_11->setIcon(QIcon(":/__supericon__/_toggleleft_.svg"));
    }
    else
    {
        Slidermode = 1;
        Plugin->ui->pushButton_11->setIcon(QIcon(":/__supericon__/_toggleright_.svg"));
    }
}

/*  change slider mode;*/

void WavDataDialog::play()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            Timerca->start();
            Multimedia->changePlayText(Plugin->ui->pushButton,&Playstatus,7);
            playInit();
            break;
        }
        case 7:
        {
            Timerca->stop();
            Timerta->stop();
            Multimedia->changePlayText(Plugin->ui->pushButton,&Playstatus,9);
            break;
        }
        case 9:
        {
            Timerca->start();
            Timerta->start();
            Multimedia->changePlayText(Plugin->ui->pushButton,&Playstatus,7);
            break;
        }
    }
}

/*  start play wav file;*/

void WavDataDialog::playInit()
{
    QAudioSink *audiosink = new QAudioSink(QMediaDevices::defaultAudioOutput(),Outputformat);
    Plugin->ui->pushButton_6->setEnabled(true);
    if(Plugin->ui->progressBar->value() == 50)
    {
        int startpos = double(Core->getVectorMinValue(&Selectdata,Selectdata.count())) / Samplerate;
        int endpos = double(Core->getVectorMaxValue(&Selectdata,Selectdata.count())) / Samplerate;
        File->seek(startpos * Bitspersample * Samplerate);
        Threadpa = new SuperPlayWav(File,endpos * Bitspersample * Samplerate,&Playstatus,audiosink);
    }
    else
    {
        Threadpa = new SuperPlayWav(File,File->size(),&Playstatus,audiosink);
    }
    Timerta = Threadpa->Timer;
    connect(Timerta,        &QTimer::timeout,       this,       &WavDataDialog::signalPcSlot);
    connect(Threadpa,       &SuperPlayWav::signalPa,this,       &WavDataDialog::signalPaSlot);
    connect(Threadpa,       &SuperPlayWav::signalPb,this,       &WavDataDialog::signalPbSlot);
    connect(Threadpa,       &SuperPlayWav::finished,Threadpa,   &QObject::deleteLater);
    Timerta->setInterval(Refreshrate);
    Buffersize = audiosink->bufferSize();
    Threadpa->start();
}

/*  play wav file init;*/

void WavDataDialog::getDataSelection()
{
    for(int i = 0;i < Channels;i++)
    {
        if(!Chartviewqvector.at(i)->Lineseriesvector.at(0)->selectedPoints().isEmpty())
        {
            Selectdata = Chartviewqvector.at(i)->Lineseriesvector.at(0)->selectedPoints();
            Chartviewqvector.at(i)->Lineseriesvector.at(0)->deselectAllPoints();
        }
    }
    setProgressBarValue(Core->getVectorMinValue(&Selectdata,Selectdata.count()),Core->getVectorMaxValue(&Selectdata,Selectdata.count()));
}

/*  get canvas selection and set as all;*/

void WavDataDialog::setProgressBarValue(double selectionbegin,double selectionend)
{
    if(selectionend - selectionbegin >= Samplerate * 5)
    {
        Plugin->ui->progressBar->setValue(50);
    }
    else
    {
        Plugin->ui->progressBar->setValue(100);
    }
}

/*  display play mode,whole or selection;*/

void WavDataDialog::setProgressBar(int progressbarvalue,QString message)
{
    Progressbardialog->setValueMessage(progressbarvalue,message);
}

/*  receive signal set progressbar value and message;*/

void WavDataDialog::stop()
{
    Timerca->stop();
    Beforestopstatus = Playstatus;
    Multimedia->changePlayText(Plugin->ui->pushButton,&Playstatus,4);
}

/*  stop play audio;*/

void WavDataDialog::displayWavFileInfo()
{
    Plugin->ui->sampleratelabel->setText(QString::number(Samplerate));
    Plugin->ui->bitslabel->setText(QString::number(Bits));
    Plugin->ui->channelslabel->setText(QString::number(Channels));
    Plugin->ui->secondslabel->setText(QString::number(double(Timelength) / Bitspersample / Samplerate));
}

/*  display wavfile info to ui top;*/

void WavDataDialog::setWavFilePos()
{
    stop();
    getDataSelection();
    for(int i = 0;i < Channels;i++)
    {
        double posbegin = double(Core->getVectorMinValue(&Selectdata,Selectdata.count())) / Samplerate;
        double posend = double(Core->getVectorMaxValue(&Selectdata,Selectdata.count())) / Samplerate;
        Chartviewqvector.at(i)->setProgressLinePos(0,posbegin);
        Chartviewqvector.at(i)->setProgressLinePos(1,posbegin);
        Chartviewqvector.at(i)->setProgressLinePos(2,posend);
        File->seek(int(posbegin) * Samplerate * Bitspersample);
    }
}

/*  set wav file pos;*/

void WavDataDialog::setCurrentChannel()
{
    SuperChartView *plot = (SuperChartView*)sender();
    Currentchannel = plot->objectName().toInt();
}

/*  set current channel;*/

void WavDataDialog::fftReset()
{
    Fftchartview->rescaleAxes();
}

void WavDataDialog::refresh()
{
    Threadta = new SuperToFft(this,Chartviewqvector.at(Currentchannel),&Selectdata,Samplerate,Maxval,Fftchartview,&Dbvmode);
    connect(Threadta,   &SuperToFft::signalTa,  this,       &WavDataDialog::fftCanvasTextapi);
    connect(Threadta,   &SuperToFft::signalTb,  this,       &WavDataDialog::setProgressBar);
    connect(Threadta,   &SuperToFft::finished,  Threadta,   &QObject::deleteLater);
    Threadta->start();
    Progressbardialog->show();
}

/*  refresh source data to fft;*/

void WavDataDialog::fftCanvasTextapi(QString text)
{
    Fftchartview->setText(0,0.9,0.1,text);
    Fftchartview->rescaleAxes();
}

/*  add fft text to plot;*/

void WavDataDialog::fftDragMode()
{
    Plugin->ui->pushButton_7->setEnabled(true);
    Plugin->ui->pushButton_8->setEnabled(false);
    Fftchartview->setDragMode();
}

/*  set canvas as drag mode;*/

void WavDataDialog::fftSelectMode()
{
    Plugin->ui->pushButton_7->setEnabled(false);
    Plugin->ui->pushButton_8->setEnabled(true);
    Fftchartview->setSelectMode();
}

/*  set canvas as select mode;*/

void WavDataDialog::changeDbvMode()
{
    if(Dbvmode == "0")
    {
        Plugin->ui->pushButton_10->setIcon(QIcon(":/__supericon__/_rms_.svg"));
        Dbvmode = "1";
    }
    else
    {
        Plugin->ui->pushButton_10->setIcon(QIcon(":/__supericon__/_peak_.svg"));
        Dbvmode = "0";
    }
    refresh();
}

/*  set canvas as select mode;*/

void WavDataDialog::calRealData(int count,fftw_complex* complex,double* yreal,QVector<double>* y)
{
    double temp = 0;
    for (int i = 0; i < count / 2; i++)
    {
        temp = sqrt(complex[i][0] * complex[i][0] + complex[i][1] * complex[i][1]) / count / Maxval * 2;
        yreal[i] = temp;
        y->append(20 * log10(temp));
    }
}

/*  add int_16 data to doubleqvector,double pointer;*/

void WavDataDialog::signalRaSlot()
{
    Threadra = nullptr;
    File = new QFile(Wavfile,this);
    File->open(QIODevice::ReadOnly);
    Selectdata = {0,1};
    refresh();
}

/*  creat plot by channels;*/

void WavDataDialog::signalRcSlot()
{
    Plugin->ui->pushButton->setEnabled(false);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"audio data is empty;\ndisable play button;");
    messagebox->messageInit();
}

/*  wav file data error check;*/

void WavDataDialog::signalPaSlot()
{
    Threadpa = nullptr;
    Plugin->ui->pushButton_6->setEnabled(false);
    if(Beforestopstatus.size() == 7)
    {
        play();
    }
}

/*  continus play when wav play stopped;*/

void WavDataDialog::signalPbSlot(QString status)
{
    Threadpa = nullptr;
    Plugin->ui->pushButton_6->setEnabled(false);
    Multimedia->changePlayText(Plugin->ui->pushButton,&Playstatus,4);
    if(status == "selection")
    {
        double posbegin = double(Core->getVectorMinValue(&Selectdata,Selectdata.count())) / Samplerate;
        File->seek(int(posbegin) * Samplerate * Bitspersample);
    }
    else
    {
        File->seek(0);
    }
    if(Beforestopstatus.size() == 7)
    {
        play();
    }
}

/*  file seek pos depend on progressbar status;*/

void WavDataDialog::signalPcSlot()
{
    double filepos = double(File->pos() - Buffersize) / Samplerate / Bitspersample;
    if(Filepos != filepos && filepos > 0)
    {
        Fps = Fps + 1;
        Filepos = filepos;
        switch(Slidermode)
        {
            case 0:
            {
                trackMode();
                break;
            }
            case 1:
            {
                rangeMode();
                break;
            }
        }
    }
}

/*  begin verline seek pos depend on signal;*/

void WavDataDialog::trackMode()
{
    for(int i = 0;i < Channels;i++)
    {
        Chartviewqvector.at(i)->setProgressLinePos(1,Filepos);
        double xaxismax = Chartviewqvector.at(i)->Xaxis->max();
        double xaxismin = Chartviewqvector.at(i)->Xaxis->min();
        double xaxisrange = xaxismax - xaxismin;
        Chartviewqvector.at(i)->Xaxis->setRange(Filepos - xaxisrange / 2,Filepos + xaxisrange / 2);
    }
}

/*  refresh plot follow mode*/

void WavDataDialog::rangeMode()
{
    for(int i = 0;i < Channels;i++)
    {
        Chartviewqvector.at(i)->setProgressLinePos(1,Filepos);
        double xaxismax = Chartviewqvector.at(i)->Xaxis->max();
        double xaxismin = Chartviewqvector.at(i)->Xaxis->min();
        double xaxisrange = xaxismax - xaxismin;
        if(xaxismin > Filepos || xaxismax < Filepos)
        {
            Chartviewqvector.at(i)->Xaxis->setRange(Filepos,Filepos + xaxisrange);
        }
    }
}

/*  refresh plot follow mode*/

void WavDataDialog::signalCaSlot()
{
    if(Playstatus.size() == 7)
    {
        Multimedia->changePlayText(Plugin->ui->pushButton_7,&Playstatus,9);
        stop();
    }
}

/*  default play device changed;*/

void WavDataDialog::signalCbSlot()
{
    Plugin->ui->pushButton->setEnabled(false);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"can not find any output deivce;");
    messagebox->hideLeftButton();
    messagebox->messageInit();
}

/*  not found any play device;*/

void WavDataDialog::calRefreshRate()
{
    Plugin->ui->label_2->setText(QString::number(Fps) + " fps");
    Fps = 0;
}

/*  cal refresh rate*/

void WavDataDialog::signalRdSlot(int index)
{
    if(Threadra != nullptr)
    {
        Chartviewqvector.at(index)->setLineData(0,&Threadra->X,&Threadra->Y);
    }
}

/*  set chatview data;*/

SuperReadWav::SuperReadWav(QString wavfile,int timelength,int samplerate,int bitspersample,int bits,int channels)
{
    Wavfile = wavfile;
    Timelength = timelength;
    Samplerate = samplerate;
    Bitspersample = bitspersample;
    Bits = bits;
    Channels = channels;
    init();
}

SuperReadWav::~SuperReadWav()
{
    X.clear();
    Y.clear();
    Wavfiledata.clear();
}

void SuperReadWav::init()
{
    objectInit();
}

void SuperReadWav::objectInit()
{
    Multimedia = new SuperMultiMedia(this);
}

void SuperReadWav::initRun()
{
    Wavfiledata = "";
    Wavfiledatacount = 0;
    X.clear();
    Y.clear();
}

/*  parameter init;*/

void SuperReadWav::run()
{
    initRun();
    readWavData();
    cal16BitsData();
    emit signalRb(100,"(3/3)Readwav function run completed");
    emit signalRa();
}

/*  begin verline seek pos depend on signal;*/

void SuperReadWav::readWavData()
{
    QFile file(Wavfile);
    if(file.size() > 44)
    {
        file.open(QIODevice::ReadOnly);
        file.read(44);
        Wavfiledata = file.read(int(Timelength - Bitspersample * Samplerate / 20));
        Wavfiledatacount = Wavfiledata.count() / Bitspersample;
        file.close();
        emit signalRb(99,"(1/3)Readwavdata function running...");
    }
}

/*  read wavfile data to QBytearray Wavfiledata;*/

void SuperReadWav::cal16BitsData()
{
    if(Wavfiledata.size() && Wavfiledatacount)
    {
        for(int i = 0;i < Channels;i++)
        {
            Multimedia->cal16BitsData(Channels,i,&X,&Y,Wavfiledatacount,Samplerate,&Wavfiledata);
            emit signalRb(99 * (i + 1) / Channels,"(2/3)Cal16bitsdata function running...");
            emit signalRd(i);
        }
    }
    else
    {
        emit signalRc();
    }
}

/*  cal channel int16 data;*/

SuperToFft::SuperToFft(QWidget *parent,SuperChartView *timechartview,QVector<int> *selectdata,int samplerate,int maxval,SuperChartView *fftchartview,QByteArray *dbvmode)
    : QThread(parent)
{
    Timechartview = timechartview;
    Selectdata = selectdata;
    Samplerate = samplerate;
    Maxval = maxval;
    Fftchartview = fftchartview;
    Dbvmode = dbvmode;
    init();
}

/*  refresh source data to fft;*/

SuperToFft::~SuperToFft()
{
    fftw_destroy_plan(Plan);
    fftw_free(Ylffti);
    fftw_free(Ylffto);
    fftw_free(Ylfftro);
    delete Core;
    delete Multimedia;
}

void SuperToFft::init()
{
    parameterInit();
    objectInit();
}

void SuperToFft::parameterInit()
{
    Datacount = Selectdata->count();
    Start = Selectdata->at(0);
    Ylffti = (double*)fftw_malloc(sizeof(double)* Datacount);
    Ylffto = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* Datacount);
    Ylfftro = (double*)fftw_malloc(sizeof(double)* Datacount);
}

void SuperToFft::objectInit()
{
    Core = new SuperCore();
    Multimedia = new SuperMultiMedia();
}

void SuperToFft::run()
{
    emit signalTb(99,"(1/2)to fft function init...;");
    for (int i = Start;i < Start + Datacount;i++)
    {
        Ylffti[i - Start] = Timechartview->Lineseriesvector.at(0)->at(i).y();
    }
    Plan = fftw_plan_dft_r2c_1d(Datacount, Ylffti, Ylffto,FFTW_ESTIMATE);
    fftw_execute_dft_r2c(Plan,Ylffti,Ylffto);
    Xlfftvector = Core->linspace(0,Samplerate / 2,Datacount / 2);
    calRealData(Datacount,Ylffto,Ylfftro,&Ylfftvector);
    Fftchartview->Lineseriesvector.at(0)->clear();
    Fftchartview->setLineData(0,&Xlfftvector,&Ylfftvector);
    fftCanvasInfo(Ylffti,Ylfftro,Datacount);
    emit signalTb(100,"(2/2)to fft function run completed;");
}

void SuperToFft::calRealData(int count,fftw_complex* complex,double* yreal,QVector<double>* y)
{
    double temp = 0;
    for (int i = 0; i < count / 2; i++)
    {
        temp = sqrt(complex[i][0] * complex[i][0] + complex[i][1] * complex[i][1]) / count / Maxval * 2;
        yreal[i] = temp;
        y->append(20 * log10(temp));
    }
}

/*  add int_16 data to doubleqvector,double pointer;*/

void SuperToFft::fftCanvasInfo(double *ylffti,double *ylfftro,int count)
{
    QString resultdbv = Multimedia->calDecibelVoltage(ylffti,count,Dbvmode->toInt(),Maxval) + "(dbv)\n";
    double temp = Multimedia->calFrequency(ylffti,count,Samplerate);
    QString resultfrequency = QString::number(temp,'f',3) + "(hz)\n";
    QString resultthd = Multimedia->calTotalHarmonicDistortion(temp,ylfftro,Samplerate,count,0) + "(thd)";
    emit signalTa(resultdbv + resultfrequency + resultthd);
}

/*  display current channel;*/
