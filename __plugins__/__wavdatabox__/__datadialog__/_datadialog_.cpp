#include "_datadialog_.h"

DataDialog::DataDialog(QWidget *parent,QString wavfile)
    : SuperWindow(parent)
{
    Wavfile = wavfile;
    setAttribute(Qt::WA_DeleteOnClose);
    Settitle(wavfile);
    Init();
}

DataDialog::~DataDialog()
{
    Stop();
    emit Signalda();
    SuperC->Closethread(Threadpa);
    SuperC->Closethread(Threadra);
    File->close();
    delete Progressbardialog;
}

void DataDialog::Init()
{
    Objectinit();
    Colorinit();
    Infoinit();
    Plotinit();
    Icoinit();
    Threadinit();
    Checkdevicechangedinit();
}

void DataDialog::Objectinit()
{
    SuperM = new SuperMultiMedia(this);
    Timerca = new QTimer(this);
    Timerca->setInterval(1000);
    Plugin = new DataBox(this);
    Pluginlayout->addWidget(Plugin);
    Progressbardialog = new SuperProgressBarDialog();
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,  this,&DataDialog::Play);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,  this,&DataDialog::Refresh);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,  this,&DataDialog::Dragmode);
    connect(Plugin->ui->pushButton_4,   &QPushButton::clicked,  this,&DataDialog::Selectmode);
    connect(Plugin->ui->pushButton_7,   &QPushButton::clicked,  this,&DataDialog::Fftselectmode);
    connect(Plugin->ui->pushButton_8,   &QPushButton::clicked,  this,&DataDialog::Fftdragmode);
    connect(Plugin->ui->pushButton_9,   &QPushButton::clicked,  this,&DataDialog::Fftreset);
    connect(Plugin->ui->pushButton_5,   &QPushButton::clicked,  this,&DataDialog::Reset);
    connect(Plugin->ui->pushButton_6,   &QPushButton::clicked,  this,&DataDialog::Changerefreshrate);
    connect(Plugin->ui->pushButton_10,  &QPushButton::clicked,  this,&DataDialog::Changedbvmode);
    connect(Plugin->ui->pushButton_11,  &QPushButton::clicked,  this,&DataDialog::Changeslidermode);
    connect(Timerca,                    &QTimer::timeout,       this,&DataDialog::Calrefreshrate);
}

void DataDialog::Colorinit()
{
    SuperC->Colorinit(&Backgroundcolor,&Fontcolor,&Concolor,&Strrgbbackgroundcolor,&Strrgbfontcolor,&Strrgbconcolor);
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

void DataDialog::Infoinit()
{
    QStringList wavfileinfo = SuperM->Wavinfo(Wavfile);
    Timelength = wavfileinfo.at(1).toInt();
    Channels = wavfileinfo.at(6).toInt();
    Samplerate = wavfileinfo.at(7).toInt();
    Bitspersample = wavfileinfo.at(9).toInt();
    Bits = wavfileinfo.at(10).toInt();
    Maxval = pow(2,Bits -1) -1;
    Outputformat.setChannelCount(Channels);
    Outputformat.setSampleRate(Samplerate);
    Outputformat.setSampleFormat(SuperM->Intbitstoenum(Bits));
    Displaywavfileinfo();
}

/*  init format;*/

void DataDialog::Plotinit()
{
    Fftplotinit();
    for(int i = 0;i < Channels;i++)
    {
        Canvasqvector.append(new QCustomPlot(this));
        connect(Canvasqvector.at(i),&QCustomPlot::selectionChangedByUser,this,&DataDialog::Setwavfilepos);
        connect(Canvasqvector.at(i),&QCustomPlot::selectionChangedByUser,this,&DataDialog::Setcurrentchannel);
        Canvasqvector.at(i)->setMinimumHeight(200);
        Creatplotapi(Canvasqvector.at(i),i);
        Plugin->ui->verticalLayout_5->addWidget(Canvasqvector.at(i));
        Channeltextinit(Canvasqvector.at(i),i + 1);
    }
}

/*  init plot;*/

void DataDialog::Fftplotinit()
{
    Fftcanvas = new QCustomPlot(this);
    Creatplotapi(Fftcanvas,0);
    Plugin->ui->verticalLayout_8->addWidget(Fftcanvas);
}

/*  fft plot;*/

void DataDialog::Creatplotapi(QCustomPlot *plot,int index)
{
    plot->setObjectName(QString::number(index));
    plot->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
    plot->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);
    plot->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables| QCP::iMultiSelect);
    plot->addGraph();
    plot->graph(0)->setPen(Colorvector.at(index % 2));
    plot->graph(0)->setSelectable(QCP::SelectionType::stDataRange);
}

/*  creat plot api;*/

void DataDialog::Channeltextinit(QCustomPlot *plot,int channel)
{
    QCPItemText *plottext = new QCPItemText(plot);
    plottext->position->setType(QCPItemPosition::ptAxisRectRatio);
    plottext->setPositionAlignment(Qt::AlignHCenter | Qt::AlignTop);
    plottext->position->setCoords(0.5, 0);
    plottext->setText("channel " + QString::number(channel));
}

/*  add channel title to plot;*/

void DataDialog::Icoinit()
{
    Plugin->ui->pushButton_3->setIcon(QIcon(":/__supericon__/_drag_.svg"));
    Plugin->ui->pushButton_4->setIcon(QIcon(":/__supericon__/_select_.svg"));
    Plugin->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_reset_.svg"));
    Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_lowrefreshrate_.svg"));
    Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_select_.svg"));
    Plugin->ui->pushButton_8->setIcon(QIcon(":/__supericon__/_drag_.svg"));
    Plugin->ui->pushButton_9->setIcon(QIcon(":/__supericon__/_reset_.svg"));
    Plugin->ui->pushButton_10->setIcon(QIcon(":/__supericon__/_peak_.svg"));
    Plugin->ui->pushButton_11->setIcon(QIcon(":/__supericon__/_toggleleft_.svg"));
}

/*  init icon;*/

void DataDialog::Threadinit()
{
    Threadra = new SuperReadWav(Wavfile,Timelength,Samplerate,Bitspersample,Bits,Channels,&Canvasqvector);
    connect(Threadra,   &SuperReadWav::Signalra,this,       &DataDialog::Signalraslot);
    connect(Threadra,   &SuperReadWav::Signalrb,this,       &DataDialog::Setprogressbar);
    connect(Threadra,   &SuperReadWav::Signalrc,this,       &DataDialog::Signalrcslot);
    connect(Threadra,   &SuperReadWav::finished,this,       &DataDialog::Reset);
    connect(Threadra,   &SuperReadWav::finished,Threadra,   &QObject::deleteLater);
    Threadra->start();
    Progressbardialog->Show();
}

/*  init thread;*/

void DataDialog::Checkdevicechangedinit()
{
    Mediadevices = new QMediaDevices(this);
    connect(Mediadevices,&QMediaDevices::audioOutputsChanged,this,&DataDialog::Signalcaslot);
}

/*  Check device changed init;*/

void DataDialog::Reset()
{
    for(int i = 0;i < Channels;i++)
    {
        Canvasqvector.at(i)->rescaleAxes();
        Canvasqvector.at(i)->replot(QCustomPlot::rpQueuedReplot);
    }
}

/*  replot Canvas;*/

void DataDialog::Dragmode()
{
    Plugin->ui->pushButton_3->setEnabled(false);
    Plugin->ui->pushButton_4->setEnabled(true);
    for(int i = 0;i < Channels;i++)
    {
        Canvasqvector.at(i)->setInteraction(QCP::iRangeDrag,true);
        Canvasqvector.at(i)->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
    }
}

/*  set canvas as drag mode;*/

void DataDialog::Selectmode()
{
    Plugin->ui->pushButton_3->setEnabled(true);
    Plugin->ui->pushButton_4->setEnabled(false);
    for(int i = 0;i < Channels;i++)
    {
        Canvasqvector.at(i)->setInteraction(QCP::iNone,true);
        Canvasqvector.at(i)->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
    }
}

/*  set canvas as select mode;*/

void DataDialog::Changerefreshrate()
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

void DataDialog::Changeslidermode()
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

void DataDialog::Play()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            Timerca->start();
            SuperM->Changeplaytext(Plugin->ui->pushButton,&Playstatus,7);
            Playinit();
            break;
        }
        case 7:
        {
            Timerca->stop();
            Timerta->stop();
            SuperM->Changeplaytext(Plugin->ui->pushButton,&Playstatus,9);
            break;
        }
        case 9:
        {
            Timerca->start();
            Timerta->start();
            SuperM->Changeplaytext(Plugin->ui->pushButton,&Playstatus,7);
            break;
        }
    }
}

/*  start play wav file;*/

void DataDialog::Playinit()
{
    QAudioSink *audiosink = new QAudioSink(QMediaDevices::defaultAudioOutput(),Outputformat);
    Plugin->ui->pushButton_6->setEnabled(true);
    if(Plugin->ui->progressBar->value() == 50)
    {
        int filepos = double(Selection.dataRange().begin()) / Samplerate;
        File->seek(filepos * Bitspersample * Samplerate);
        Threadpa = new SuperPlayWav(File,Endverlineqvector.at(0)->point1->key() * Samplerate * Bitspersample,&Playstatus,audiosink);
    }
    else
    {
        Threadpa = new SuperPlayWav(File,File->size(),&Playstatus,audiosink);
    }
    Timerta = Threadpa->Timer;
    connect(Timerta,        &QTimer::timeout,       this,       &DataDialog::Signalpcslot);
    connect(Threadpa,       &SuperPlayWav::Signalpa,this,       &DataDialog::Signalpaslot);
    connect(Threadpa,       &SuperPlayWav::Signalpb,this,       &DataDialog::Signalpbslot);
    connect(Threadpa,       &SuperPlayWav::finished,Threadpa,   &QObject::deleteLater);
    Timerta->setInterval(Refreshrate);
    Buffersize = audiosink->bufferSize();
    Threadpa->start();
}

/*  play wav file init;*/

void DataDialog::Getdataselection()
{
    for(int i = 0;i < Channels;i++)
    {
        if(Canvasqvector.at(i)->graph(0)->selected())
        {
            QCPDataSelection empty;
            Selection = Canvasqvector.at(i)->graph(0)->selection();
            Canvasqvector.at(i)->graph(0)->setSelection(empty);
        }
    }
    Setprogressbarvalue(Selection.dataRange().begin(),Selection.dataRange().end());
}

/*  get canvas selection and set as all;*/

void DataDialog::Setprogressbarvalue(double selectionbegin,double selectionend)
{
    if(selectionend - selectionbegin >= Samplerate)
    {
        Plugin->ui->progressBar->setValue(50);
    }
    else
    {
        Plugin->ui->progressBar->setValue(100);
    }
}

/*  display play mode,whole or selection;*/

void DataDialog::Setprogressbar(int progressbarvalue,QString message)
{
    Progressbardialog->Setvaluemessage(progressbarvalue,message);
}

/*  receive signal set progressbar value and message;*/

void DataDialog::Stop()
{
    Timerca->stop();
    Beforestopstatus = Playstatus;
    SuperM->Changeplaytext(Plugin->ui->pushButton,&Playstatus,4);
}

/*  stop play audio;*/

void DataDialog::Displaywavfileinfo()
{
    Plugin->ui->sampleratelabel->setText(QString::number(Samplerate));
    Plugin->ui->bitslabel->setText(QString::number(Bits));
    Plugin->ui->channelslabel->setText(QString::number(Channels));
    Plugin->ui->secondslabel->setText(QString::number(double(Timelength) / Bitspersample / Samplerate));
}

/*  display wavfile info to ui top;*/

void DataDialog::Setwavfilepos()
{
    Stop();
    Getdataselection();
    for(int i = 0;i < Channels;i++)
    {
        double posbegin = double(Selection.dataRange().begin()) / Samplerate;
        double posend = double(Selection.dataRange().end()) / Samplerate;
        Beginverlineqvector.at(i)->point1->setCoords(posbegin,1);
        Beginverlineqvector.at(i)->point2->setCoords(posbegin,-1);
        Slidinglineqvector.at(i)->point1->setCoords(posbegin,1);
        Slidinglineqvector.at(i)->point2->setCoords(posbegin,-1);
        Endverlineqvector.at(i)->point1->setCoords(posend,1);
        Endverlineqvector.at(i)->point2->setCoords(posend,-1);
        Canvasqvector.at(i)->replot(QCustomPlot::rpQueuedReplot);
        File->seek(int(posbegin) * Samplerate * Bitspersample);
    }
}

/*  set wav file pos;*/

void DataDialog::Setcurrentchannel()
{
    QCustomPlot *plot = (QCustomPlot*)sender();
    Currentchannel = plot->objectName().toInt();
}

/*  set current channel;*/

void DataDialog::Refresh()
{
    Threadta = new SuperToFft(this,Canvasqvector.at(Currentchannel),&Selection,Samplerate,Maxval,Fftcanvas,&Dbvmode);
    connect(Threadta,   &SuperToFft::Signalta,  this,       &DataDialog::Fftcanvastextapi);
    connect(Threadta,   &SuperToFft::Signaltb,  this,       &DataDialog::Setprogressbar);
    connect(Threadta,   &SuperToFft::finished,  Threadta,   &QObject::deleteLater);
    Threadta->start();
    Progressbardialog->Show();
}

/*  refresh source data to fft;*/

void DataDialog::Fftcanvastextapi(QString text)
{
    QCPItemText *plottext = new QCPItemText(Fftcanvas);
    plottext->position->setType(QCPItemPosition::ptAxisRectRatio);
    plottext->setPositionAlignment(Qt::AlignHCenter | Qt::AlignTop);
    plottext->position->setCoords(0.9, 0.1);
    plottext->setText(text);
    Fftreset();
}

/*  add fft text to plot;*/

void DataDialog::Fftreset()
{
    Fftcanvas->rescaleAxes();
    Fftcanvas->replot(QCustomPlot::rpQueuedReplot);
}

/*  replot canvas;*/

void DataDialog::Fftdragmode()
{
    Plugin->ui->pushButton_7->setEnabled(true);
    Plugin->ui->pushButton_8->setEnabled(false);
    Fftcanvas->setInteraction(QCP::iRangeDrag,true);
    Fftcanvas->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
}

/*  set canvas as drag mode;*/

void DataDialog::Fftselectmode()
{
    Plugin->ui->pushButton_7->setEnabled(false);
    Plugin->ui->pushButton_8->setEnabled(true);
    Fftcanvas->setInteraction(QCP::iNone,true);
    Fftcanvas->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
}

/*  set canvas as select mode;*/

void DataDialog::Changedbvmode()
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
    Refresh();
}

/*  set canvas as select mode;*/

void DataDialog::Calrealdata(int count,fftw_complex* complex,double* yreal,QVector<double>* y)
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

void DataDialog::Signalraslot()
{
    Threadra = nullptr;
    File = new QFile(Wavfile,this);
    File->open(QIODevice::ReadOnly);
    Selection.addDataRange(QCPDataRange(0,1));
    Refresh();
    for(int i = 0;i < Channels;i++)
    {
        Beginverlineqvector.append(new QCPItemStraightLine(Canvasqvector.at(i)));
        Beginverlineqvector.at(i)->setPen(Penvector.at(i % 2));
        Beginverlineqvector.at(i)->setLayer("overlay");
        Beginverlineqvector.at(i)->point1->setCoords(0,1);
        Beginverlineqvector.at(i)->point2->setCoords(0,-1);
        Slidinglineqvector.append(new QCPItemStraightLine(Canvasqvector.at(i)));
        Slidinglineqvector.at(i)->setPen(Penvector.at(i % 2));
        Slidinglineqvector.at(i)->setLayer("overlay");
        Slidinglineqvector.at(i)->point1->setCoords(0,1);
        Slidinglineqvector.at(i)->point2->setCoords(0,-1);
        Endverlineqvector.append(new QCPItemStraightLine(Canvasqvector.at(i)));
        Endverlineqvector.at(i)->setPen(Penvector.at(i % 2));
        Endverlineqvector.at(i)->setLayer("overlay");
        Endverlineqvector.at(i)->point1->setCoords(0,1);
        Endverlineqvector.at(i)->point2->setCoords(0,-1);
    }
}

/*  creat plot by channels;*/

void DataDialog::Signalrcslot()
{
    Plugin->ui->pushButton->setEnabled(false);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"audio data is empty;\ndisable play button;");
    messagebox->Messageinit();
}

/*  wav file data error check;*/

void DataDialog::Signalpaslot()
{
    Threadpa = nullptr;
    Plugin->ui->pushButton_6->setEnabled(false);
    if(Beforestopstatus.at(0) == 'p')
    {
        Play();
    }
}

/*  continus play when wav play stopped;*/

void DataDialog::Signalpbslot(QString status)
{
    Threadpa = nullptr;
    Plugin->ui->pushButton_6->setEnabled(false);
    SuperM->Changeplaytext(Plugin->ui->pushButton,&Playstatus,4);
    if(status == "selection")
    {
        double posbegin = double(Selection.dataRange().begin()) / Samplerate;
        File->seek(int(posbegin) * Samplerate * Bitspersample);
    }
    else
    {
        File->seek(0);
    }
    if(Beforestopstatus.at(0) == 'p')
    {
        Play();
    }
}

/*  file seek pos depend on progressbar status;*/

void DataDialog::Signalpcslot()
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
                Trackmode();
                break;
            }
            case 1:
            {
                Rangemode();
                break;
            }
        }
    }
}

/*  begin verline seek pos depend on signal;*/

void DataDialog::Trackmode()
{
    for(int i = 0;i < Channels;i++)
    {
        Slidinglineqvector.at(i)->point1->setCoords(Filepos,1);
        Slidinglineqvector.at(i)->point2->setCoords(Filepos,-1);
        double xaxissize = Canvasqvector.at(i)->xAxis->range().size();
        Canvasqvector.at(i)->xAxis->setRange(Filepos - xaxissize / 2,Filepos + xaxissize / 2);
        Canvasqvector.at(i)->replot(QCustomPlot::rpQueuedReplot);
    }
}

/*  refresh plot follow mode*/

void DataDialog::Rangemode()
{
    for(int i = 0;i < Channels;i++)
    {
        Slidinglineqvector.at(i)->point1->setCoords(Filepos,1);
        Slidinglineqvector.at(i)->point2->setCoords(Filepos,-1);
        double xaxissize = Canvasqvector.at(i)->xAxis->range().size();
        double lower = Canvasqvector.at(i)->xAxis->range().lower;
        double upper = Canvasqvector.at(i)->xAxis->range().upper;
        if(lower > Filepos || upper < Filepos)
        {
            Canvasqvector.at(i)->xAxis->setRange(Filepos,Filepos + xaxissize);
        }
        Canvasqvector.at(i)->replot(QCustomPlot::rpQueuedReplot);
    }
}

/*  refresh plot follow mode*/

void DataDialog::Signalcaslot()
{
    if(Playstatus.size() == 7)
    {
        SuperM->Changeplaytext(Plugin->ui->pushButton_7,&Playstatus,9);
        Stop();
    }
}

/*  default play device changed;*/

void DataDialog::Signalcbslot()
{
    Plugin->ui->pushButton->setEnabled(false);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"can not find any output deivce;");
    messagebox->Hideleftbutton();
    messagebox->Messageinit();
}

/*  not found any play device;*/

void DataDialog::Calrefreshrate()
{
    Plugin->ui->label_2->setText(QString::number(Fps) + " fps");
    Fps = 0;
}

SuperReadWav::SuperReadWav(QString wavfile,int timelength,int samplerate,int bitspersample,int bits,int channels,QVector<QCustomPlot*> *canvasqvector)
{
    Wavfile = wavfile;
    Timelength = timelength;
    Samplerate = samplerate;
    Bitspersample = bitspersample;
    Bits = bits;
    Channels = channels;
    Canvasqvector = canvasqvector;
    Init();
}

SuperReadWav::~SuperReadWav()
{
    X.clear();
    Y.clear();
    Wavfiledata.clear();
}

void SuperReadWav::Init()
{
    Objectinit();
}

void SuperReadWav::Objectinit()
{
    SuperM = new SuperMultiMedia(this);
}

void SuperReadWav::Initrun()
{
    Wavfiledata = "";
    Wavfiledatacount = 0;
    X.clear();
    Y.clear();
}

/*  parameter init;*/

void SuperReadWav::run()
{
    Initrun();
    Readwavdata();
    Cal16bitsdata();
    emit Signalrb(100,"(3/3)Readwav function run completed");
    emit Signalra();
}

/*  begin verline seek pos depend on signal;*/

void SuperReadWav::Readwavdata()
{
    QFile file(Wavfile);
    if(file.size() > 44)
    {
        file.open(QIODevice::ReadOnly);
        file.read(44);
        Wavfiledata = file.read(int(Timelength - Bitspersample * Samplerate / 20));
        Wavfiledatacount = Wavfiledata.count() / Bitspersample;
        file.close();
        emit Signalrb(99,"(1/3)Readwavdata function running...");
    }
}

/*  read wavfile data to QBytearray Wavfiledata;*/

void SuperReadWav::Cal16bitsdata()
{
    if(Wavfiledata.size() && Wavfiledatacount)
    {
        for(int i = 0;i < Channels;i++)
        {
            SuperM->Cal16bitsdata(Channels,i,&X,&Y,Wavfiledatacount,Samplerate,&Wavfiledata);
            Canvasqvector->at(i)->graph(0)->setData(X,Y);
            emit Signalrb(99 * (i + 1) / Channels,"(2/3)Cal16bitsdata function running...");
            Canvasqvector->at(i)->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        emit Signalrc();
    }
}

/*  cal channel int16 data;*/

SuperToFft::SuperToFft(QWidget *parent,QCustomPlot *timeplot,QCPDataSelection *selection,int samplerate,int maxval,QCustomPlot *fftplot,QByteArray *dbvmode)
    : QThread(parent)
{
    Timeplot = timeplot;
    Selection = selection;
    Samplerate = samplerate;
    Maxval = maxval;
    Fftplot = fftplot;
    Dbvmode = dbvmode;
    Init();
}

/*  refresh source data to fft;*/

SuperToFft::~SuperToFft()
{
    fftw_destroy_plan(Plan);
    fftw_free(Ylffti);
    fftw_free(Ylffto);
    fftw_free(Ylfftro);
    delete SuperC;
    delete SuperM;
}

void SuperToFft::Init()
{
    Parameterinit();
    Objectinit();
}

void SuperToFft::Parameterinit()
{
    Datacount = Selection->dataPointCount();
    Start = Selection->dataRange().begin();
    Ylffti = (double*)fftw_malloc(sizeof(double)* Datacount);
    Ylffto = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* Datacount);
    Ylfftro = (double*)fftw_malloc(sizeof(double)* Datacount);
}

void SuperToFft::Objectinit()
{
    SuperC = new SuperCore();
    SuperM = new SuperMultiMedia();
}

void SuperToFft::run()
{
    emit Signaltb(99,"(1/2)to fft function init...;");
    for (int i = Start;i < Start + Datacount;i++)
    {
          Ylffti[i - Start] = Timeplot->graph(0)->data()->at(i)->value;
    }
    Plan = fftw_plan_dft_r2c_1d(Datacount, Ylffti, Ylffto,FFTW_ESTIMATE);
    fftw_execute_dft_r2c(Plan,Ylffti,Ylffto);
    Xlfftvector = SuperC->Linspace(0,Samplerate / 2,Datacount / 2);
    Calrealdata(Datacount,Ylffto,Ylfftro,&Ylfftvector);
    Fftplot->clearItems();
    Fftplot->graph(0)->setData(Xlfftvector,Ylfftvector);
    Fftplot->replot(QCustomPlot::rpQueuedReplot);
    Fftplot->rescaleAxes();
    Fftcanvasinfo(Ylffti,Ylfftro,Datacount);
    emit Signaltb(100,"(2/2)to fft function run completed;");
}

void SuperToFft::Calrealdata(int count,fftw_complex* complex,double* yreal,QVector<double>* y)
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

void SuperToFft::Fftcanvasinfo(double *ylffti,double *ylfftro,int count)
{
    QString resultdbv = SuperM->Caldbv(ylffti,count,Dbvmode->toInt(),Maxval) + "(dbv)\n";
    double temp = SuperM->Calfreq(ylffti,count,Samplerate);
    QString resultfrequency = QString::number(temp,'f',3) + "(hz)\n";
    QString resultthd = SuperM->Calthd(temp,ylfftro,Samplerate,count,0) + "(thd)";
    emit Signalta(resultdbv + resultfrequency + resultthd);
}

/*  display current channel;*/
