#include "_wasapibox_.h"
#include "ui__wasapimodulea_.h"
#include "ui__wasapimoduleb_.h"
#include "ui__wasapimodulec_.h"
#include "ui__wasapiformatdialogui_.h"

SuperTab* Interface::Loadplugin()
{
    return new WasapiBox();
}

/*  return class WasapiBox new instance pointer;*/

WasapiBox::WasapiBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("WasapiBox");
    setGroupBox(3,2);
    setStretch({1,1,98},{5,5});
    init();
}

WasapiBox::~WasapiBox()
{
    stopPlayAudio();
    stopAnalysisAudio();
    Core->closeThread(Threadpw);
    Core->closeThread(Threadps);
    Core->closeThread(Threaduf);
}

void WasapiBox::init()
{
    objectInit();
    parameterInit();
    plotInit();
    audioFormat(&Format);
}

/*  init parameter,plot,audioformat;*/

void WasapiBox::objectInit()
{
    Multimedia = new SuperMultiMedia(this);
    Modulea = new WasapiModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    connect(Modulea->ui->pushButton_95,     &QPushButton::clicked,          this,   &WasapiBox::refreshDevices);
    connect(Modulea->ui->pushButton,        &QPushButton::clicked,          this,   &WasapiBox::setAudioFormat);
    connect(Modulea->ui->comboBox_24,       &QComboBox::textActivated,      this,   &WasapiBox::refreshOutputNumber);
    connect(Modulea->ui->comboBox_25,       &QComboBox::textActivated,      this,   &WasapiBox::refreshInputNumber);
    Moduleb = new WasapiModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    connect(Moduleb->ui->pushButton_97,     &QPushButton::clicked,          this,   &WasapiBox::playAudio);
    connect(Moduleb->ui->pushButton_100,    &QPushButton::clicked,          this,   &WasapiBox::stopPlayAudio);
    connect(Moduleb->ui->checkBox_24,       &QCheckBox::stateChanged,       this,   &WasapiBox::setPlayMode);
    connect(Moduleb->ui->comboBox,          &QComboBox::textActivated,      this,   &WasapiBox::displayGenerateMode);
    connect(Moduleb->ui->doubleSpinBox,     &QDoubleSpinBox::textChanged,   this,   &WasapiBox::displayAmplitude);
    connect(Moduleb->ui->doubleSpinBox_2,   &QDoubleSpinBox::textChanged,   this,   &WasapiBox::displayFrequency);
    connect(Moduleb->ui->doubleSpinBox_3,   &QDoubleSpinBox::textChanged,   this,   &WasapiBox::displayTime);
    connect(Moduleb->ui->pushButton_98,     &QPushButton::clicked,          this,   &WasapiBox::selectWavFile);
    connect(Moduleb->ui->pushButton_2,      &QPushButton::clicked,          this,   &WasapiBox::generateWavFileInit);
    Modulec = new WasapiModuleC(this,Leftgroupboxlist.at(2)->Insidelayout);
    connect(Modulec->ui->pushButton_99,     &QPushButton::clicked,          this,   &WasapiBox::analysisAudio);
    connect(Modulec->ui->pushButton_101,    &QPushButton::clicked,          this,   &WasapiBox::stopAnalysisAudio);
    connect(Modulec->ui->comboBox,          &QComboBox::textActivated,      this,   &WasapiBox::changeLimitMode);
    connect(Modulec->ui->spinBox,           &QSpinBox::textChanged,         this,   &WasapiBox::changeLimit);
    connect(Modulec->ui->comboBox_33,       &QComboBox::textActivated,      this,   &WasapiBox::changeDbvMode);
    connect(Modulec->ui->checkBox_2,        &QCheckBox::clicked,            this,   &WasapiBox::changePlotMode);
    connect(Modulec->ui->doubleSpinBox_5,   &QDoubleSpinBox::textChanged,   this,   &WasapiBox::changeThdDegree);
    Timechartview = new SuperChartView(this);
    Fftchartview = new SuperChartView(this);
    Tabwidget = new SuperTabWidget(this);
    Rightgroupboxlist.at(0)->Insidelayout->addWidget(Tabwidget);
    Tabwidget->addTab(Timechartview,"Time");
    Tabwidget->addTab(Fftchartview,"Frequency");
    connect(Timechartview,  &SuperChartView::signalCa,  this,   &WasapiBox::changePlotMode);
    connect(Fftchartview,   &SuperChartView::signalCa,  this,   &WasapiBox::changePlotMode);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(1)->Insidelayout);
    Modulec->ui->spinBox->setSpecialValueText("");
    changeLimitMode();
}

void WasapiBox::parameterInit()
{
    Outputwidgetlist    = {Modulea->ui->comboBox_24,Modulea->ui->lineEdit_40,Moduleb->ui->checkBox_24,Moduleb->ui->pushButton_97,Modulea->ui->pushButton};
    Inputwidgetlist     = {Modulea->ui->comboBox_25,Modulea->ui->lineEdit_41,Modulec->ui->pushButton_99,Modulec->ui->checkBox_2,Modulec->ui->label_5,Modulec->ui->doubleSpinBox_4,Modulec->ui->label,Modulec->ui->comboBox};
    Maxval = pow(Samplewidth,Multimedia->enumBitsToInt(Initbits) -1) -1;
}

/*  init widget pointer;*/

void WasapiBox::enableRefreshDeviceButton()
{
    if(Playstatus.size() == 4 && Analysisstatus.size() == 8)
    {
        Modulea->ui->pushButton_95->setEnabled(true);
    }
    else
    {
        Modulea->ui->pushButton_95->setEnabled(false);
    }
}

/*  check enable refresh device button;*/

void WasapiBox::refreshDevices()
{
    refreshDevicesInit();
    Multimedia->getAudioOutputDeviceInfo(&Outputdevicelist,&Listoutputname,&Listoutputnumber);
    Multimedia->getAudioInputDeviceInfo(&Inputdevicelist,&Listinputname,&Listinputnumber);
    if(!Listoutputname.isEmpty())
    {
        Modulea->ui->comboBox_24->addItems(Listoutputname);
        Moduleb->ui->pushButton_2->setEnabled(true);
        refreshOutputNumber();
        setPlayMode();
    }
    if(!Listinputname.isEmpty())
    {
        Modulea->ui->comboBox_25->addItems(Listinputname);
        refreshInputNumber();
    }
    enableWidget(Listinputname,&Inputwidgetlist);
    enableWidget(Listoutputname,&Outputwidgetlist);
}

/*  refresh audio output and input device,add device number to lineedit;*/

void WasapiBox::refreshDevicesInit()
{
    Modulea->ui->comboBox_24->clear();
    Modulea->ui->comboBox_25->clear();
    Moduleb->ui->comboBox_34->clear();
    Outputdevicelist.clear();
    Inputdevicelist.clear();
    Listoutputname.clear();
    Listoutputnumber.clear();
    Listinputname.clear();
    Listinputnumber.clear();
}

/*  refresh audio output and input device init;*/

void WasapiBox::enableWidget(QStringList listname,QList<QWidget*> *widgetlist)
{
    if(listname.isEmpty())
    {
        for(int i = 0;i < widgetlist->count();i++)
        {
            widgetlist->at(i)->setEnabled(false);
        }
    }
    else
    {
        for(int i = 0;i < widgetlist->count();i++)
        {
            widgetlist->at(i)->setEnabled(true);
        }
    }
}

/*  if have device, enable widget;;*/

void WasapiBox::refreshOutputNumber()
{
    Modulea->ui->lineEdit_40->setText(Listoutputnumber.at(Modulea->ui->comboBox_24->currentIndex()));
    if(Moduleb->ui->lineEdit_34->text().isEmpty())
    {
        Outputsamplerate = Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()).preferredFormat().sampleRate();
        Outputbits = Multimedia->enumBitsToInt(Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()).preferredFormat().sampleFormat());
        Outputchannelcount = Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()).preferredFormat().channelCount();
    }
    else
    {
        QStringList Wavinfo = Multimedia->wavInfo(Moduleb->ui->lineEdit_34->text());
        Outputsamplerate = Wavinfo.at(7).toInt();
        Outputbits = Wavinfo.at(10).toInt();
        Outputchannelcount = Wavinfo.at(6).toInt();
    }
    refreshAudioFormatApi(&Outputformat,Outputsamplerate,Outputbits,Outputchannelcount,Modulea->ui->comboBox_24->currentText());
    addOutputChannel();
}

/*  refresh audio output number;*/

void WasapiBox::addOutputChannel()
{
    Moduleb->ui->comboBox_34->clear();
    Moduleb->ui->comboBox_34->addItem("Both");
    for(int i = 0;i < Outputchannelcount;i++)
    {
        Moduleb->ui->comboBox_34->addItem("Chan " + QString::number(i));
    }
}

/*  add output device channle count and could select;*/

void WasapiBox::refreshInputNumber()
{
    Modulea->ui->lineEdit_41->setText(Listinputnumber.at(Modulea->ui->comboBox_25->currentIndex()));
    Inputsamplerate = Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()).preferredFormat().sampleRate();
    Inputbits = Multimedia->enumBitsToInt(Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()).preferredFormat().sampleFormat());
    Inputchannelcount = Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()).preferredFormat().channelCount();
    refreshAudioFormatApi(&Inputformat,Inputsamplerate,Inputbits,Inputchannelcount,Modulea->ui->comboBox_25->currentText());
}

/*  refresh audio input number;*/

void WasapiBox::setAudioFormat()
{
    WasapiFormatDialog *audioformatdialog = new WasapiFormatDialog(nullptr,&Outputformat,&Inputformat);
    connect(audioformatdialog,&WasapiFormatDialog::signalFa,this,&WasapiBox::refreshAudioFormatApi);
    connect(audioformatdialog,&WasapiFormatDialog::signalFb,this,&WasapiBox::refreshOutputParameter);
    connect(audioformatdialog,&WasapiFormatDialog::signalFc,this,&WasapiBox::refreshInputParameter);
    audioformatdialog->show();
}

void WasapiBox::audioFormat(QAudioFormat* format)
{
    format->setSampleRate(48000);
    format->setChannelCount(2);
    format->setSampleFormat(QAudioFormat::Int16);
}

/*  set default audio format;*/

void WasapiBox::refreshAudioFormatApi(QAudioFormat *format,int intsamplerate,int intsamplesize,int intchannelcount,QString straudioname)
{
    format->setSampleRate(intsamplerate);
    format->setSampleFormat(Multimedia->intBitsToEnum(intsamplesize));
    format->setChannelCount(intchannelcount);
    Logger->displayLog("N",straudioname + " format: ","Refreshaudioformatapi function run completed");
    Logger->displayLog("N","set " + straudioname + " format samplerate: " + QString::number(intsamplerate) + "(hz)","Refreshaudioformatapi function run completed");
    Logger->displayLog("N","set " + straudioname + " format samplesize: " + QString::number(intsamplesize) + "(bits)","Refreshaudioformatapi function run completed");
    Logger->displayLog("N","set " + straudioname + " format channelcount: " + QString::number(intchannelcount) + "(channels)","Refreshaudioformatapi function run completed");
    Logger->displayLog("N","set " + straudioname + " format codec: audio/pcm","Refreshaudioformatapi function run completed");
}

/*  set audio format api and display logs;*/

void WasapiBox::refreshOutputParameter(int samplerate,int bits,int channels)
{
    Outputsamplerate = samplerate;
    Outputbits = bits;
    Outputchannelcount = channels;
}

/*  set audio output parameter and display logs;*/

void WasapiBox::refreshInputParameter(int samplerate,int bits,int channels)
{
    Inputsamplerate = samplerate;
    Inputbits = bits;
    Inputchannelcount = channels;
}

/*  set audio input parameter and display logs;*/

void WasapiBox::selectWavFile()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{"*.wav"});
    connect(filedialog,&SuperFileDialog::signalFb,this,         &WasapiBox::setWavFile);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
    filedialog->setSingleFile();
    filedialog->show();
}

/*  Select wav file;*/

void WasapiBox::setWavFile(QString file)
{
    if(file.isEmpty())
    {
        Logger->displayLog("N","select wav file canceled","Selectwavfile function run completed");
    }
    else
    {
        Moduleb->ui->lineEdit_34->setText(file);
        QStringList wavinfo = Multimedia->wavInfo(Moduleb->ui->lineEdit_34->text());
        QVector<QString> wavelist = {"RIFF","filelen","WAVE","fmt","fmtlen","wformattag","wchannels","dwsamplerate","dwavgbyterate","wblockalign","wbitspersample","wextsize","extralinfo"};
        Outputsamplerate = wavinfo.at(7).toInt();
        Outputbits = wavinfo.at(10).toInt();
        Outputchannelcount = wavinfo.at(6).toInt();
        refreshAudioFormatApi(&Outputformat,Outputsamplerate,Outputbits,Outputchannelcount,Modulea->ui->comboBox_24->currentText());
        Logger->displayLog("N","selected wav: " + file,"Selectwavfile function run completed");
        for(int i = 0;i < wavinfo.count();i++)
        {
            Logger->displayLog("N",wavelist.at(i) + ": " + wavinfo.at(i),"Selectwavfile function run completed");
        }
    }
}

/*  set wav file and add to lineedit,if cancel,lineedit set empty;*/

void WasapiBox::playAudio()
{
    if(Moduleb->ui->lineEdit_34->text().isEmpty())
    {
        playSignalInit();
    }
    else
    {
        playWavInit();
    }
    enableRefreshDeviceButton();
    setPlayMode();
}

/*  play wav file or signal;*/

void WasapiBox::playWavInit()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            Multimedia->changePlayText(Moduleb->ui->pushButton_97,&Playstatus,7);
            Moduleb->ui->pushButton_100->setEnabled(true);
            Moduleb->ui->checkBox_24->setEnabled(false);
            Modulea->ui->comboBox_24->setEnabled(false);
            File = new QFile(Moduleb->ui->lineEdit_34->text(),this);
            File->open(QIODevice::ReadOnly);
            QAudioSink *audiosink = new QAudioSink(Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()),Outputformat);
            Threadpw = new SuperPlayWav(File,File->size(),&Playstatus,audiosink);
            connect(Threadpw,&SuperPlayWav::signalPa,   this,       &WasapiBox::signalPwaSlot);
            connect(Threadpw,&SuperPlayWav::signalPb,   this,       &WasapiBox::signalPwbSlot);
            connect(Threadpw,&SuperPlayWav::finished,   Threadpw,   &QObject::deleteLater);
            Threadpw->start();
            Logger->displayLog("N","start new thread for play wav file","Playaudio function running...");
            break;
        }
        case 7:
        {
            Multimedia->changePlayText(Moduleb->ui->pushButton_97,&Playstatus,9);
            Logger->displayLog("N","wav file play suspended","Playaudio function suspended");
            break;
        }
        case 9:
        {
            Multimedia->changePlayText(Moduleb->ui->pushButton_97,&Playstatus,7);
            Logger->displayLog("N","wav file resume playing...","Playaudio function running...");
            break;
        }
    }
}

/*  change play mode ,play or suspended,and operate some widget;*/

void WasapiBox::playSignalInit()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            Multimedia->changePlayText(Moduleb->ui->pushButton_97,&Playstatus,7);
            Amplitude = Moduleb->ui->doubleSpinBox->value();
            Frequency = Moduleb->ui->doubleSpinBox_2->value();
            Durationtime = Moduleb->ui->doubleSpinBox_3->value();
            Moduleb->ui->pushButton_100->setEnabled(true);
            Moduleb->ui->checkBox_24->setChecked(true);
            Moduleb->ui->checkBox_24->setEnabled(false);
            Modulea->ui->comboBox_24->setEnabled(false);
            Moduleb->ui->pushButton_97->setEnabled(false);
            QAudioSink *audiosink = new QAudioSink(Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()),Outputformat);
            Threadps = new SuperPlaySignal(signalWave(),Moduleb->ui->doubleSpinBox_3->value(),&Playstatus,audiosink);
            connect(Threadps,&SuperPlaySignal::signalPa,this,       &WasapiBox::signalspSlot);
            connect(Threadps,&SuperPlaySignal::finished,Threadps,   &QObject::deleteLater);
            Threadps->start();
            Logger->displayLog("N","start new thread for play signal,signal playing...","Playaudio function running...");
            break;
        }
    }
}

/*  start signal play and init widget;*/

void WasapiBox::setPlayMode()
{
    QWidgetList widgetlista = {Moduleb->ui->comboBox_32,Moduleb->ui->doubleSpinBox, Moduleb->ui->doubleSpinBox_2, Moduleb->ui->doubleSpinBox_3,Moduleb->ui->comboBox_34,Moduleb->ui->comboBox};
    QWidgetList widgetlistb = {Moduleb->ui->lineEdit_34,Moduleb->ui->pushButton_98};
    if(Moduleb->ui->checkBox_24->isChecked() && Playstatus.size() == 4)
    {
        Core->enableWidgetList(&widgetlista,true);
        Core->enableWidgetList(&widgetlistb,false);
        Moduleb->ui->lineEdit_34->clear();
        Logger->displayLog("N","play mode has been changed to signal","Setplaymode function run completed");
    }
    else if(!Moduleb->ui->checkBox_24->isChecked() && Playstatus.size() == 4)
    {
        Core->enableWidgetList(&widgetlista,false);
        Core->enableWidgetList(&widgetlistb,true);
        Logger->displayLog("N","play mode has been changed to wav,select file to play","Setplaymode function run completed");
    }
    else if(Playstatus.size() != 4)
    {
        Core->enableWidgetList(&widgetlista,false);
        Core->enableWidgetList(&widgetlistb,false);
    }
}

/*  operate checkbox widget,choose play mode;*/

void WasapiBox::stopPlayAudio()
{
    Multimedia->changePlayText(Moduleb->ui->pushButton_97,&Playstatus,4);
}

/*  stop play audio;*/

void WasapiBox::displayGenerateMode()
{
    QString mode = Moduleb->ui->comboBox->currentText();
    Logger->displayLog("N","generate mode changed to " + mode,"Displaygeneratemode function run completed");
}

/*  display pcm generate mode;*/

void WasapiBox::displayAmplitude()
{
    double value = Moduleb->ui->doubleSpinBox->value();
    Logger->displayLog("N","amplitude changed to " + QString::number(value) + " (db)","Displayamplitude function run completed");
}

/*  display amplitude value;*/

void WasapiBox::displayFrequency()
{
    double value = Moduleb->ui->doubleSpinBox_2->value();
    Logger->displayLog("N","frequency changed to " + QString::number(value) + " (hz)","Displayfrequency function run completed");
}

/*  display frequency value;*/

void WasapiBox::displayTime()
{
    double value = Moduleb->ui->doubleSpinBox_3->value();
    Logger->displayLog("N","time changed to " + QString::number(value) + " (s)","Displaytime function run completed");
}

/*  display time value;*/

QByteArray WasapiBox::sineWave(double sampletime,double amplitude,int frequency)
{
    QByteArray signaldata = "";
    double amplitudetemp = 0;
    int samplenum = sampletime * Outputsamplerate;
    switch(Moduleb->ui->comboBox->currentIndex())
    {
        case 0:
        {
            amplitudetemp = amplitude;
            break;
        }
        case 1:
        {
            amplitudetemp = amplitude * sqrt(2);
            break;
        }
    }
    switch(Outputchannelcount)
    {
        case 1:
        {
            for(int i = 0;i < samplenum;i++)
            {
                int16_t sineint = (int16_t)(sin(2 * M_PI * i * frequency / Outputsamplerate) * Maxval * amplitudetemp);
                signaldata.append((sineint & 0xFF));
                signaldata.append(((sineint >> 8) & 0xFF));
            }
            break;
        }
        case 2:
        {
            for(int i = 0;i < samplenum;i++)
            {
                int16_t sinelint = (int16_t)(sin(2 * M_PI * i * frequency / Outputsamplerate) * Maxval * amplitudetemp);
                int16_t sinerint = sinelint;
                if (Moduleb->ui->comboBox_34->currentText() == "Chan 0")
                {
                    sinerint = sinerint * 0;
                }
                else if(Moduleb->ui->comboBox_34->currentText() == "Chan 1")
                {
                    sinelint = sinelint * 0;
                }
                signaldata.append((sinelint & 0xFF));
                signaldata.append(((sinelint >> 8) & 0xFF));
                signaldata.append((sinerint & 0xFF));
                signaldata.append(((sinerint >> 8) & 0xFF));
            }
            break;
        }
    }
    Logger->displayLog("N","generate sinewave completed","Sinewave function run completed");
    return signaldata;
}

/*  return signal wave data;*/

QByteArray WasapiBox::signalWave()
{
    return sineWave(0.01,Amplitude,Frequency);
}

/*  return sine wave data;*/

void WasapiBox::analysisAudio()
{
    int status = Analysisstatus.size();
    if(status == 8)
    {
        Updatefigureparameter[3] = 11;
        Multimedia->changeAnalysisText(Modulec->ui->pushButton_99,&Analysisstatus,Updatefigureparameter.at(3));
        analysisAudioInit(true,false);
        QAudioSource *audiosource = new QAudioSource(Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()),Inputformat);
        audiosource->setBufferSize(Modulec->ui->doubleSpinBox_4->value() * 2);
        Threaduf = new UpdateFigure(&Allrecorddata,audiosource,&Updatefigureparameter);
        connect(Threaduf,&UpdateFigure::signalUa,   this,       &WasapiBox::signalUarSlot);
        connect(Threaduf,&UpdateFigure::signalUb,   this,       &WasapiBox::signalUbrSlot);
        connect(Threaduf,&UpdateFigure::signalUc,   this,       &WasapiBox::stopAnalysisAudio);
        connect(Threaduf,&UpdateFigure::finished,   Threaduf,   &QObject::deleteLater);
        Threaduf->start();
        Logger->displayLog("N","start new thread analysis audio and update figure","Analysisaudio function running...");
    }
}

/*  opearte ui and start analysis audio;*/

void WasapiBox::analysisAudioInit(bool boola,bool boolb)
{
    QWidgetList widgetlista = {Modulec->ui->pushButton_101,Modulec->ui->lineEdit_42,Modulec->ui->lineEdit_47,Modulec->ui->lineEdit_49, Modulec->ui->comboBox_33,Modulec->ui->label_2,Modulec->ui->label_3,Modulec->ui->label_4,Modulec->ui->doubleSpinBox_5};
    QWidgetList widgetlistb = {Modulea->ui->comboBox_25,Modulec->ui->pushButton_99,Modulec->ui->label_5,Modulec->ui->doubleSpinBox_4,Modulec->ui->label,Modulec->ui->comboBox,Modulec->ui->spinBox};
    for(int i = 0;i < widgetlista.count();i++)
    {
        widgetlista.at(i)->setEnabled(boola);
    }
    for(int i = 0;i < widgetlistb.count();i++)
    {
        widgetlistb.at(i)->setEnabled(boolb);
    }
    enableRefreshDeviceButton();
}

/*  opearte ui;*/

void WasapiBox::plotInit()
{
    int counts = 2;
    Timechartview->setLine(counts);
    Fftchartview->setLine(counts);
    for(int i = 0;i < counts;i++)
    {
        Timechartview->setLineColor(Timechartview->Lineseriesvector.at(i),i,Qt::SolidLine);
        Fftchartview->setLineColor(Timechartview->Lineseriesvector.at(i),i,Qt::SolidLine);
    }
}

/*  figure init;*/

void WasapiBox::stopAnalysisAudio()
{
    Updatefigureparameter[3] = 8;
    Multimedia->changeAnalysisText(Modulec->ui->pushButton_99,&Analysisstatus,Updatefigureparameter.at(3));
}

/*  stop analysis audio;*/

void WasapiBox::changePlotMode()
{
    if(Updatefigureparameter.at(0) == 1)
    {
        Updatefigureparameter[0] = 0;
        Timechartview->setPlotMode(false);
        Fftchartview->setPlotMode(false);
        Modulec->ui->checkBox_2->setChecked(false);
        Logger->displayLog("N","plot display mode changed to manual","Changeplotmode function run completed");
    }
    else
    {
        Updatefigureparameter[0] = 1;
        Timechartview->setPlotMode(true);
        Fftchartview->setPlotMode(true);
        Modulec->ui->checkBox_2->setChecked(true);
        Logger->displayLog("N","plot display mode changed to auto","Changeplotmode function run completed");
    }
}

/* change plot display mode;*/

void WasapiBox::changeLimitMode()
{
    Updatefigureparameter[4] = Modulec->ui->comboBox->currentIndex();
    Modulec->ui->spinBox->setEnabled(Updatefigureparameter.at(4));
    switch(Updatefigureparameter.at(4))
    {
        case 0:
        {
            Modulec->ui->spinBox->setSuffix("wait for enabled...");
            Modulec->ui->spinBox->clear();
            break;
        }
        case 1:
        {
            Modulec->ui->spinBox->setSuffix("(mb)");
            Modulec->ui->spinBox->setSingleStep(8);
            Modulec->ui->spinBox->setMaximum(256);
            Modulec->ui->spinBox->setMinimum(8);
            Modulec->ui->spinBox->setValue(256);
            break;
        }
        case 2:
        {
            Modulec->ui->spinBox->setSuffix("(minutes)");
            Modulec->ui->spinBox->setSingleStep(1);
            Modulec->ui->spinBox->setMaximum(30);
            Modulec->ui->spinBox->setMinimum(1);
            Modulec->ui->spinBox->setValue(30);
            break;
        }
    }
    Logger->displayLog("N","record limit mode changed as " + Modulec->ui->comboBox->currentText(),"Changelimitmode function run completed");
}

/* change limit mode;*/

void WasapiBox::changeLimit()
{
    switch(Modulec->ui->comboBox->currentIndex())
    {
        case 1:
        {
            Updatefigureparameter[5] = Modulec->ui->spinBox->value() * 1048576;
            break;
        }
        case 2:
        {
            Updatefigureparameter[6] = Modulec->ui->spinBox->value() * 60;
            break;
        }
    }
    Logger->displayLog("N","record limit changed as " + Modulec->ui->spinBox->text(),"Changelimit function run completed");
}

/* change limit;*/

void WasapiBox::changeDbvMode()
{
    Updatefigureparameter[2] = Modulec->ui->comboBox_33->currentIndex();
    Logger->displayLog("N","dbv mode changed as " + Modulec->ui->comboBox_33->currentText(),"Changedbvmode function run completed");
}

/* change dbv mode;*/

void WasapiBox::changeThdDegree()
{
    int degree = Modulec->ui->doubleSpinBox_5->value();
    Updatefigureparameter[1] = degree;
    Logger->displayLog("N","thd degree changed to " + QString::number(degree),"Changethddegree function run completed");
}

/* change plot display mode;*/

void WasapiBox::generateWavFileInit()
{
    if(Moduleb->ui->doubleSpinBox_3->value() <= 0 || Moduleb->ui->doubleSpinBox->value() <= 0)
    {
        SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"amplitude or time must > 0");
        messagebox->messageInit();
        Logger->displayLog("N","amplitude or time must > 0","Generatewavfile function run completed");
    }
    else
    {
        SuperFileDialog *filedialog = new SuperFileDialog(nullptr,Currentpath,{"*.wav"});
        connect(filedialog,&SuperFileDialog::signalFb,this,         &WasapiBox::generateWavFile);
        connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
        filedialog->setSaveFile();
        filedialog->show();
    }
}

/* generate wav file init;*/

void WasapiBox::generateWavFile(QString wavfile)
{   
    QFileInfo fileinfo(wavfile);
    Currentpath = fileinfo.absolutePath();
    QByteArray bytes = sineWave(Moduleb->ui->doubleSpinBox_3->value(),Moduleb->ui->doubleSpinBox->value(),Moduleb->ui->doubleSpinBox_2->value());
    Core->creatFile(wavfile);
    Multimedia->writeWavFile(wavfile,bytes.size(),Outputchannelcount,Outputsamplerate,Outputchannelcount * Outputsamplerate * 2,Outputchannelcount * 2,bytes);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,wavfile + " has been created;\nclick ok open path;");
    connect(messagebox,&SuperNoteDialog::signalNb,this,&WasapiBox::openGeneratePath);
    messagebox->messageInit();
    Logger->displayLog("N","wav file generate completed","Generatewavfile function run completed");
}

/* generate wav file;*/

void WasapiBox::openRecordPath()
{
    Core->openPath(Temppath);
}

/* open record path;*/

void WasapiBox::openGeneratePath()
{
    Core->openPath(Currentpath);
}

/* open generate path;*/

void WasapiBox::signalPwaSlot()
{
    signalPwSlotApi();
}

/*  end signals' thread , release memory and reset ui;*/

void WasapiBox::signalPwbSlot(QString status)
{
    if(status != "selection")
    {
        signalPwSlotApi();
    }
}

/*  end signals' thread , release memory and reset ui;*/

void WasapiBox::signalPwSlotApi()
{
    File->close();
    File = nullptr;
    Threadpw = nullptr;
    Multimedia->changePlayText(Moduleb->ui->pushButton_97,&Playstatus,4);
    Moduleb->ui->pushButton_97->setEnabled(true);
    Moduleb->ui->pushButton_100->setEnabled(false);
    Moduleb->ui->checkBox_24->setEnabled(true);
    Modulea->ui->comboBox_24->setEnabled(true);
    enableRefreshDeviceButton();
    setPlayMode();
    Logger->displayLog("N","wav file has been play completed","Signalwpslot function run completed");
}

void WasapiBox::signalspSlot()
{
    Threadps = nullptr;
    Moduleb->ui->pushButton_97->setEnabled(true);
    Multimedia->changePlayText(Moduleb->ui->pushButton_97,&Playstatus,4);
    Moduleb->ui->pushButton_100->setEnabled(false);
    Moduleb->ui->checkBox_24->setEnabled(true);
    Modulea->ui->comboBox_24->setEnabled(true);
    enableRefreshDeviceButton();
    setPlayMode();
    Logger->displayLog("N","signal has been play completed","Signalspslot function run completed");
}

/*  end signals' thread , release memory and reset ui;*/

void WasapiBox::signalUarSlot(QString strdbv,QString strfreq,QString strthd)
{
    if(Threaduf != nullptr)
    {
        Modulec->ui->lineEdit_42->setText(strdbv);
        Modulec->ui->lineEdit_47->setText(strfreq);
        Modulec->ui->lineEdit_49->setText(strthd);
        Timechartview->setLineData(0,Threaduf->Pointl);
        Timechartview->setLineData(1,Threaduf->Pointr);
        Fftchartview->setLineData(0,Threaduf->Pointlfft);
        Fftchartview->setLineData(1,Threaduf->Pointrfft);
        Timechartview->rescaleAxes();
        Fftchartview->rescaleAxes();
    }
}

/*  display dbv freq thd and plot;*/

void WasapiBox::signalUbrSlot(QString text)
{
    Threaduf = nullptr;
    analysisAudioInit(false,true);
    saveWavFile();
    Modulec->ui->spinBox->setEnabled(Updatefigureparameter.at(4));
    Logger->displayLog("N",text,"signalUbslot function run completed");
}

/*  end analysis wav thread and operate ui;*/

void WasapiBox::saveWavFile()
{
    if(Modulec->ui->comboBox->currentIndex())
    {
        QString localtime = "_" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + "_";
        Multimedia->writeWavFile(Temppath + localtime + ".wav",Allrecorddata.size(),Inputchannelcount,Inputsamplerate,Inputchannelcount * Inputsamplerate * 2,Inputchannelcount * 2,Allrecorddata);
        SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,localtime + ".wav has been created;\nclick ok open path;");
        connect(messagebox,&SuperNoteDialog::signalNb,this,&WasapiBox::openRecordPath);
        messagebox->messageInit();
    }
    Allrecorddata.clear();
}

/*  save wav file;*/

UpdateFigure::UpdateFigure(QByteArray *allrecorddata,QAudioSource *audiosource,QVector<int> *updatefigureparameter)
{
    Allrecorddata = allrecorddata;
    Audiosource = audiosource;
    Updatefigureparameter = updatefigureparameter;
    init();
}

UpdateFigure::~UpdateFigure()
{
    delete Audiosource;
    fftw_destroy_plan(Plan);
    fftw_free(Ylffti);
    fftw_free(Ylffto);
    fftw_free(Yrffti);
    fftw_free(Yrffto);
    fftw_free(Ylfftro);
    fftw_free(Yrfftro);
}

void UpdateFigure::init()
{
    Core = new SuperCore(this);
    Multimedia = new SuperMultiMedia(this);
    Bits = Multimedia->enumBitsToInt(Audiosource->format().sampleFormat());
    Inputsamplerate = Audiosource->format().sampleRate();
    Maxinputchannel = Audiosource->format().channelCount();
    Maxval = pow(2,Bits - 1) - 1;
}

/*  object init;*/

void UpdateFigure::run()
{
    recordAudioInit();
    emitResult();
}

void UpdateFigure::recordAudioInit()
{
    QIODevice *iodevice = Audiosource->start();
    Buffersize = Audiosource->bufferSize();
    Intcount = Buffersize / sizeof(int16_t) / Maxinputchannel;
    Xtime.append(Core->arange(0,Intcount,1));
    Xfft.append(Core->linspace(0,Inputsamplerate / 2,Intcount / 2));
    Ylffti  = (double*)fftw_malloc(sizeof(double)* Intcount);
    Ylffto  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)* Intcount);
    Yrffti  = (double*)fftw_malloc(sizeof(double)* Intcount);
    Yrffto  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)* Intcount);
    Ylfftro = (double*)fftw_malloc(sizeof(double)* Intcount);
    Yrfftro = (double*)fftw_malloc(sizeof(double)* Intcount);
    Plan = fftw_plan_dft_r2c_1d(Intcount, Ylffti, Ylffto, FFTW_MEASURE);
    recording(iodevice,Audiosource);
}

/*  record audio init;*/

void UpdateFigure::recording(QIODevice* iodevice,QAudioSource* audiosource)
{
    while(true)
    {
        if(Updatefigureparameter->at(3) == 11)
        {
            calData(iodevice);
        }
        else
        {
            audiosource->stop();
            break;
        }
    }
}

/*  record audio and analysis, draw data;*/

void UpdateFigure::calData(QIODevice* iodevice)
{
    if(Maxinputchannel == 1)
    {
        analysisChannela(iodevice);
    }
    else
    {
        analysisChannelb(iodevice);
    }
}

/*  cal single or double channel data;*/

void UpdateFigure::analysisChannela(QIODevice* iodevice)
{
    if(read(iodevice,&Recorddata))
    {
        int16_t yl = 0;
        Pointl.clear();
        Pointlfft.clear();
        for(int i = 0;i < Intcount;i++)
        {
            yl = Recorddata.at(i * 2) & 0x00FF;
            yl |= (Recorddata.at(i * 2 + 1) << 8) & 0xFF00;
            Ylffti[i] = yl;
            Pointl.append({Xtime.at(i),(double)yl});
        }
        fftw_execute_dft_r2c(Plan,Ylffti,Ylffto);
        calRealData(Intcount / 2,Ylffto,Ylfftro,&Pointlfft);
        Resultdbv = Multimedia->calDecibelVoltage(Ylffti,Intcount,Updatefigureparameter->at(2),Maxval) + "(dbv)";
        Frequencyl = Multimedia->calFrequency(Ylffti,Intcount,Inputsamplerate);
        Resultfrequency = QString::number(Frequencyl,'f',3) + "(hz)";
        Resultthd = Multimedia->calTotalHarmonicDistortion(Frequencyl,Ylfftro,Inputsamplerate,Intcount,Updatefigureparameter->at(1)) + "(thd)";
        emit signalUa(Resultdbv,Resultfrequency,Resultthd);
    }
}

/*  cal single data;*/

void UpdateFigure::analysisChannelb(QIODevice* iodevice)
{
    if(read(iodevice,&Recorddata))
    {
        int16_t yl = 0;
        int16_t yr = 0;
        Pointl.clear();
        Pointr.clear();
        Pointlfft.clear();
        Pointrfft.clear();
        for(int i = 0;i < Intcount;i++)
        {
            yl = Recorddata.at(i * 4) & 0x00FF;
            yl |= (Recorddata.at(i * 4 + 1) << 8) & 0xFF00;
            yr = Recorddata.at(i * 4 + 2) & 0x00FF;
            yr |= (Recorddata.at(i * 4 + 3) << 8) & 0xFF00;
            Ylffti[i] = yl;
            Yrffti[i] = yr;
            Pointl.append({Xtime.at(i),(double)yl});
            Pointr.append({Xtime.at(i),(double)yr});
        }
        fftw_execute_dft_r2c(Plan,Ylffti,Ylffto);
        fftw_execute_dft_r2c(Plan,Yrffti,Yrffto);
        calRealData(Intcount / 2,Ylffto,Ylfftro,&Pointlfft);
        calRealData(Intcount / 2,Yrffto,Yrfftro,&Pointrfft);
        Resultdbv = Multimedia->calDecibelVoltage(Ylffti,Intcount,Updatefigureparameter->at(2),Maxval) + "," + Multimedia->calDecibelVoltage(Yrffti,Intcount,Updatefigureparameter->at(2),Maxval) + "(dbv)";
        Frequencyl = Multimedia->calFrequency(Ylffti,Intcount,Inputsamplerate);
        Frequencyr = Multimedia->calFrequency(Yrffti,Intcount,Inputsamplerate);
        Resultfrequency = QString::number(Frequencyl,'f',3) + "," + QString::number(Frequencyr,'f',3) + "(hz)";
        Resultthd = Multimedia->calTotalHarmonicDistortion(Frequencyl,Ylfftro,Inputsamplerate,Intcount,Updatefigureparameter->at(1)) + "," + Multimedia->calTotalHarmonicDistortion(Frequencyr,Yrfftro,Inputsamplerate,Intcount,Updatefigureparameter->at(1)) + "(thd)";
        emit signalUa(Resultdbv,Resultfrequency,Resultthd);
    }
}

/*  cal double channel data;*/

void UpdateFigure::calRealData(int count,fftw_complex* complex,double* yreal,QVector<QPointF>* point)
{
    double temp = 0;
    for (int i = 0;i < count;i++)
    {
        temp = sqrt(complex[i][0] * complex[i][0] + complex[i][1] * complex[i][1]) / count / Maxval;
        yreal[i] = temp;
        point->append({Xfft.at(i),20 * log10(temp)});
    }
}

/*  add int_16 data to doubleqvector,double pointer;*/

bool UpdateFigure::read(QIODevice* iodevice,QByteArray *data)
{
    data->clear();
    QByteArray temp = "";
    while(Buffersize > data->size())
    {
        QThread::msleep(1);
        iodevice->waitForReadyRead(10);
        temp = iodevice->read(Buffersize);
        data->append(temp);
        switch(Updatefigureparameter->at(4))
        {
            case 1:
            {
                if(Allrecorddata->size() < Updatefigureparameter->at(5))
                {
                    Allrecorddata->append(temp);
                    break;
                }
                else
                {
                    Analysisresult = "audio record more than " + QString::number(Updatefigureparameter->at(5)) + " bits,analysis audio thread stop autoly;";
                    emit signalUc();
                    return false;
                }
            }
            case 2:
            {
                if(Allrecorddata->size() / sizeof(int16_t) / Maxinputchannel / Inputsamplerate < (long long unsigned int)Updatefigureparameter->at(6))
                {
                    Allrecorddata->append(temp);
                    break;
                }
                else
                {
                    Analysisresult = "audio record more than " + QString::number(Updatefigureparameter->at(6)) + " minutes,analysis audio thread stop autoly;";
                    emit signalUc();
                    return false;
                }
            }
        }
    }
    return true;
}

/*  read data from inputdevice;*/

void UpdateFigure::emitResult()
{
    emit signalUb(Analysisresult);
}

/*  emit result;*/
