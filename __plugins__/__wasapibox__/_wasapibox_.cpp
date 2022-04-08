#include "_wasapibox_.h"

SuperTab* Interface::Loadplugin()
{
    return new WasapiBox();
}

/*  return class WasapiBox new instance pointer;*/

WasapiBox::WasapiBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("WasapiBox");
    Setgroupbox(3,2);
    Setstretch({1,1,98},{5,5});
    Init();
}

WasapiBox::~WasapiBox()
{
    Stopplayaudio();
    Stopanalysisaudio();
    SuperC->Closethread(Threadpw);
    SuperC->Closethread(Threadps);
    SuperC->Closethread(Threaduf);
    delete Timefigwidget;
    delete Fftfigwidget;
}

void WasapiBox::Init()
{
    Objectinit();
    Parameterinit();
    Colorinit();
    Plotinit();
    Audioformat(&Format);
}

/*  init parameter,color,plot,audioformat;*/

void WasapiBox::Objectinit()
{
    SuperM = new SuperMultiMedia(this);
    Modulea = new ModuleA(this,Leftgroupboxlist.at(0)->Insidelayout);
    connect(Modulea->ui->pushButton_95,     &QPushButton::clicked,          this,   &WasapiBox::Refreshdevices);
    connect(Modulea->ui->pushButton,        &QPushButton::clicked,          this,   &WasapiBox::Setaudioformat);
    connect(Modulea->ui->comboBox_24,       &QComboBox::textActivated,      this,   &WasapiBox::Refreshoutputnumber);
    connect(Modulea->ui->comboBox_25,       &QComboBox::textActivated,      this,   &WasapiBox::Refreshinputnumber);
    Moduleb = new ModuleB(this,Leftgroupboxlist.at(1)->Insidelayout);
    connect(Moduleb->ui->pushButton_97,     &QPushButton::clicked,          this,   &WasapiBox::Playaudio);
    connect(Moduleb->ui->pushButton_100,    &QPushButton::clicked,          this,   &WasapiBox::Stopplayaudio);
    connect(Moduleb->ui->checkBox_24,       &QCheckBox::stateChanged,       this,   &WasapiBox::Setplaymode);
    connect(Moduleb->ui->comboBox,          &QComboBox::textActivated,      this,   &WasapiBox::Displaygeneratemode);
    connect(Moduleb->ui->doubleSpinBox,     &QDoubleSpinBox::textChanged,   this,   &WasapiBox::Displayamplitude);
    connect(Moduleb->ui->doubleSpinBox_2,   &QDoubleSpinBox::textChanged,   this,   &WasapiBox::Displayfrequency);
    connect(Moduleb->ui->doubleSpinBox_3,   &QDoubleSpinBox::textChanged,   this,   &WasapiBox::Displaytime);
    connect(Moduleb->ui->pushButton_98,     &QPushButton::clicked,          this,   &WasapiBox::Selectwavfile);
    connect(Moduleb->ui->pushButton_2,      &QPushButton::clicked,          this,   &WasapiBox::Generatewavfileinit);
    Modulec = new ModuleC(this,Leftgroupboxlist.at(2)->Insidelayout);
    connect(Modulec->ui->pushButton_99,     &QPushButton::clicked,          this,   &WasapiBox::Analysisaudio);
    connect(Modulec->ui->pushButton_101,    &QPushButton::clicked,          this,   &WasapiBox::Stopanalysisaudio);
    connect(Modulec->ui->comboBox,          &QComboBox::textActivated,      this,   &WasapiBox::Changelimitmode);
    connect(Modulec->ui->spinBox,           &QSpinBox::textChanged,         this,   &WasapiBox::Changelimit);
    connect(Modulec->ui->comboBox_33,       &QComboBox::textActivated,      this,   &WasapiBox::Changedbvmode);
    connect(Modulec->ui->checkBox_2,        &QCheckBox::clicked,            this,   &WasapiBox::Changeplotmode);
    connect(Modulec->ui->doubleSpinBox_5,   &QDoubleSpinBox::textChanged,   this,   &WasapiBox::Changethddegree);
    Timefigwidget = new SuperPlot(this);
    Fftfigwidget = new SuperPlot(this);
    Tabwidget = new SuperTabWidget(this);
    Rightgroupboxlist.at(0)->Insidelayout->addWidget(Tabwidget);
    Tabwidget->addTab(Timefigwidget,"Time");
    Tabwidget->addTab(Fftfigwidget,"Frequency");
    connect(Timefigwidget,  &QCustomPlot::mouseDoubleClick, this,   &WasapiBox::Changeplotmode);
    connect(Fftfigwidget,   &QCustomPlot::mouseDoubleClick, this,   &WasapiBox::Changeplotmode);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(1)->Insidelayout);
    Modulec->ui->spinBox->setSpecialValueText("");
    Changelimitmode();
}

void WasapiBox::Parameterinit()
{
    Outputwidgetlist    = {Modulea->ui->comboBox_24,Modulea->ui->lineEdit_40,Moduleb->ui->checkBox_24,Moduleb->ui->pushButton_97,Modulea->ui->pushButton};
    Inputwidgetlist     = {Modulea->ui->comboBox_25,Modulea->ui->lineEdit_41,Modulec->ui->pushButton_99,Modulec->ui->checkBox_2,Modulec->ui->label_5,Modulec->ui->doubleSpinBox_4,Modulec->ui->label,Modulec->ui->comboBox};
    Maxval = pow(Samplewidth,SuperM->Enumbitstoint(Initbits) -1) -1;
}

/*  init widget pointer;*/

void WasapiBox::Colorinit()
{
    SuperC->Colorinit(&Backgroundcolor,&Fontcolor,&Concolor,&Strrgbbackgroundcolor,&Strrgbfontcolor,&Strrgbconcolor);
}

/*  init color;*/

void WasapiBox::Enablerefreshdevicebutton()
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

void WasapiBox::Refreshdevices()
{
    Refreshdevicesinit();
    SuperM->Getaudiooutputdeviceinfo(&Outputdevicelist,&Listoutputname,&Listoutputnumber);
    SuperM->Getaudioinputdeviceinfo(&Inputdevicelist,&Listinputname,&Listinputnumber);
    if(!Listoutputname.isEmpty())
    {
        Modulea->ui->comboBox_24->addItems(Listoutputname);
        Moduleb->ui->pushButton_2->setEnabled(true);
        Refreshoutputnumber();
        Setplaymode();
    }
    if(!Listinputname.isEmpty())
    {
        Modulea->ui->comboBox_25->addItems(Listinputname);
        Refreshinputnumber();
    }
    Enablewidget(Listinputname,&Inputwidgetlist);
    Enablewidget(Listoutputname,&Outputwidgetlist);
}

/*  refresh audio output and input device,add device number to lineedit;*/

void WasapiBox::Refreshdevicesinit()
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

void WasapiBox::Enablewidget(QStringList listname,QList<QWidget*> *widgetlist)
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

void WasapiBox::Refreshoutputnumber()
{
    Modulea->ui->lineEdit_40->setText(Listoutputnumber.at(Modulea->ui->comboBox_24->currentIndex()));
    if(Moduleb->ui->lineEdit_34->text().isEmpty())
    {
        Outputsamplerate = Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()).preferredFormat().sampleRate();
        Outputbits = SuperM->Enumbitstoint(Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()).preferredFormat().sampleFormat());
        Outputchannelcount = Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()).preferredFormat().channelCount();
    }
    else
    {
        QStringList Wavinfo = SuperM->Wavinfo(Moduleb->ui->lineEdit_34->text());
        Outputsamplerate = Wavinfo.at(7).toInt();
        Outputbits = Wavinfo.at(10).toInt();
        Outputchannelcount = Wavinfo.at(6).toInt();
    }
    Refreshaudioformatapi(&Outputformat,Outputsamplerate,Outputbits,Outputchannelcount,Modulea->ui->comboBox_24->currentText());
    Addoutputchannel();
}

/*  refresh audio output number;*/

void WasapiBox::Addoutputchannel()
{
    Moduleb->ui->comboBox_34->clear();
    Moduleb->ui->comboBox_34->addItem("Both");
    for(int i = 0;i < Outputchannelcount;i++)
    {
        Moduleb->ui->comboBox_34->addItem("Chan " + QString::number(i));
    }
}

/*  add output device channle count and could select;*/

void WasapiBox::Refreshinputnumber()
{
    Modulea->ui->lineEdit_41->setText(Listinputnumber.at(Modulea->ui->comboBox_25->currentIndex()));
    Inputsamplerate = Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()).preferredFormat().sampleRate();
    Inputbits = SuperM->Enumbitstoint(Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()).preferredFormat().sampleFormat());
    Inputchannelcount = Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()).preferredFormat().channelCount();
    Refreshaudioformatapi(&Inputformat,Inputsamplerate,Inputbits,Inputchannelcount,Modulea->ui->comboBox_25->currentText());
}

/*  refresh audio input number;*/

void WasapiBox::Setaudioformat()
{
    FormatDialog *audioformatdialog = new FormatDialog(nullptr,&Outputformat,&Inputformat);
    connect(audioformatdialog,&FormatDialog::Signalfa,this,&WasapiBox::Refreshaudioformatapi);
    connect(audioformatdialog,&FormatDialog::Signalfb,this,&WasapiBox::Refreshoutputparameter);
    connect(audioformatdialog,&FormatDialog::Signalfc,this,&WasapiBox::Refreshinputparameter);
    audioformatdialog->Show();
}

void WasapiBox::Audioformat(QAudioFormat* format)
{
    format->setSampleRate(48000);
    format->setChannelCount(2);
    format->setSampleFormat(QAudioFormat::Int16);
}

/*  set default audio format;*/

void WasapiBox::Refreshaudioformatapi(QAudioFormat *format,int intsamplerate,int intsamplesize,int intchannelcount,QString straudioname)
{
    format->setSampleRate(intsamplerate);
    format->setSampleFormat(SuperM->Intbitstoenum(intsamplesize));
    format->setChannelCount(intchannelcount);
    Logger->Displaylog("N",straudioname + " format: ","Refreshaudioformatapi function run completed");
    Logger->Displaylog("N","set " + straudioname + " format samplerate: " + QString::number(intsamplerate) + "(hz)","Refreshaudioformatapi function run completed");
    Logger->Displaylog("N","set " + straudioname + " format samplesize: " + QString::number(intsamplesize) + "(bits)","Refreshaudioformatapi function run completed");
    Logger->Displaylog("N","set " + straudioname + " format channelcount: " + QString::number(intchannelcount) + "(channels)","Refreshaudioformatapi function run completed");
    Logger->Displaylog("N","set " + straudioname + " format codec: audio/pcm","Refreshaudioformatapi function run completed");
}

/*  set audio format api and display logs;*/

void WasapiBox::Refreshoutputparameter(int samplerate,int bits,int channels)
{
    Outputsamplerate = samplerate;
    Outputbits = bits;
    Outputchannelcount = channels;
}

/*  set audio output parameter and display logs;*/

void WasapiBox::Refreshinputparameter(int samplerate,int bits,int channels)
{
    Inputsamplerate = samplerate;
    Inputbits = bits;
    Inputchannelcount = channels;
}

/*  set audio input parameter and display logs;*/

void WasapiBox::Selectwavfile()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{"*.wav"});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &WasapiBox::Setwavfile);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsinglefile();
    filedialog->Show();
}

/*  Select wav file;*/

void WasapiBox::Setwavfile(QString file)
{
    if(file.isEmpty())
    {
        Logger->Displaylog("N","select wav file canceled","Selectwavfile function run completed");
    }
    else
    {
        Moduleb->ui->lineEdit_34->setText(file);
        QStringList wavinfo = SuperM->Wavinfo(Moduleb->ui->lineEdit_34->text());
        QVector<QString> wavelist = {"RIFF","filelen","WAVE","fmt","fmtlen","wformattag","wchannels","dwsamplerate","dwavgbyterate","wblockalign","wbitspersample","wextsize","extralinfo"};
        Outputsamplerate = wavinfo.at(7).toInt();
        Outputbits = wavinfo.at(10).toInt();
        Outputchannelcount = wavinfo.at(6).toInt();
        Refreshaudioformatapi(&Outputformat,Outputsamplerate,Outputbits,Outputchannelcount,Modulea->ui->comboBox_24->currentText());
        Logger->Displaylog("N","selected wav: " + file,"Selectwavfile function run completed");
        for(int i = 0;i < wavinfo.count();i++)
        {
            Logger->Displaylog("N",wavelist.at(i) + ": " + wavinfo.at(i),"Selectwavfile function run completed");
        }
    }
}

/*  set wav file and add to lineedit,if cancel,lineedit set empty;*/

void WasapiBox::Playaudio()
{
    if(Moduleb->ui->lineEdit_34->text().isEmpty())
    {
        Playsignalinit();
    }
    else
    {
        Playwavinit();
    }
    Enablerefreshdevicebutton();
    Setplaymode();
}

/*  play wav file or signal;*/

void WasapiBox::Playwavinit()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            SuperM->Changeplaytext(Moduleb->ui->pushButton_97,&Playstatus,7);
            Moduleb->ui->pushButton_100->setEnabled(true);
            Moduleb->ui->checkBox_24->setEnabled(false);
            Modulea->ui->comboBox_24->setEnabled(false);
            File = new QFile(Moduleb->ui->lineEdit_34->text(),this);
            File->open(QIODevice::ReadOnly);
            QAudioSink *audiosink = new QAudioSink(Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()),Outputformat);
            Threadpw = new PlayWav(File,File->size(),&Playstatus,audiosink);
            connect(Threadpw,&PlayWav::Signalpa,    this,       &WasapiBox::Signalpwaslot);
            connect(Threadpw,&PlayWav::Signalpb,    this,       &WasapiBox::Signalpwbslot);
            connect(Threadpw,&PlayWav::finished,    Threadpw,   &QObject::deleteLater);
            Threadpw->start();
            Logger->Displaylog("N","start new thread for play wav file","Playaudio function running...");
            break;
        }
        case 7:
        {
            SuperM->Changeplaytext(Moduleb->ui->pushButton_97,&Playstatus,9);
            Logger->Displaylog("N","wav file play suspended","Playaudio function suspended");
            break;
        }
        case 9:
        {
            SuperM->Changeplaytext(Moduleb->ui->pushButton_97,&Playstatus,7);
            Logger->Displaylog("N","wav file resume playing...","Playaudio function running...");
            break;
        }
    }
}

/*  change play mode ,play or suspended,and operate some widget;*/

void WasapiBox::Playsignalinit()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            SuperM->Changeplaytext(Moduleb->ui->pushButton_97,&Playstatus,7);
            Amplitude = Moduleb->ui->doubleSpinBox->value();
            Frequency = Moduleb->ui->doubleSpinBox_2->value();
            Durationtime = Moduleb->ui->doubleSpinBox_3->value();
            Moduleb->ui->pushButton_100->setEnabled(true);
            Moduleb->ui->checkBox_24->setChecked(true);
            Moduleb->ui->checkBox_24->setEnabled(false);
            Modulea->ui->comboBox_24->setEnabled(false);
            Moduleb->ui->pushButton_97->setEnabled(false);
            QAudioSink *audiosink = new QAudioSink(Outputdevicelist.at(Modulea->ui->comboBox_24->currentIndex()),Outputformat);
            Threadps = new PlaySignal(Signalwave(),Moduleb->ui->doubleSpinBox_3->value(),&Playstatus,audiosink);
            connect(Threadps,&PlaySignal::Signalpa, this,       &WasapiBox::Signalspslot);
            connect(Threadps,&PlaySignal::finished,Threadps,    &QObject::deleteLater);
            Threadps->start();
            Logger->Displaylog("N","start new thread for play signal,signal playing...","Playaudio function running...");
            break;
        }
    }
}

/*  start signal play and init widget;*/

void WasapiBox::Setplaymode()
{
    QWidgetList widgetlista = {Moduleb->ui->comboBox_32,Moduleb->ui->doubleSpinBox, Moduleb->ui->doubleSpinBox_2, Moduleb->ui->doubleSpinBox_3,Moduleb->ui->comboBox_34,Moduleb->ui->comboBox};
    QWidgetList widgetlistb = {Moduleb->ui->lineEdit_34,Moduleb->ui->pushButton_98};
    if(Moduleb->ui->checkBox_24->isChecked() && Playstatus.size() == 4)
    {
        SuperC->Enablewidgetlist(&widgetlista,true);
        SuperC->Enablewidgetlist(&widgetlistb,false);
        Moduleb->ui->lineEdit_34->clear();
        Logger->Displaylog("N","play mode has been changed to signal","Setplaymode function run completed");
    }
    else if(!Moduleb->ui->checkBox_24->isChecked() && Playstatus.size() == 4)
    {
        SuperC->Enablewidgetlist(&widgetlista,false);
        SuperC->Enablewidgetlist(&widgetlistb,true);
        Logger->Displaylog("N","play mode has been changed to wav,select file to play","Setplaymode function run completed");
    }
    else if(Playstatus.size() != 4)
    {
        SuperC->Enablewidgetlist(&widgetlista,false);
        SuperC->Enablewidgetlist(&widgetlistb,false);
    }
}

/*  operate checkbox widget,choose play mode;*/

void WasapiBox::Stopplayaudio()
{
    SuperM->Changeplaytext(Moduleb->ui->pushButton_97,&Playstatus,4);
}

/*  stop play audio;*/

void WasapiBox::Displaygeneratemode()
{
    QString mode = Moduleb->ui->comboBox->currentText();
    Logger->Displaylog("N","generate mode changed to " + mode,"Displaygeneratemode function run completed");
}

/*  display pcm generate mode;*/

void WasapiBox::Displayamplitude()
{
    double value = Moduleb->ui->doubleSpinBox->value();
    Logger->Displaylog("N","amplitude changed to " + QString::number(value) + " (db)","Displayamplitude function run completed");
}

/*  display amplitude value;*/

void WasapiBox::Displayfrequency()
{
    double value = Moduleb->ui->doubleSpinBox_2->value();
    Logger->Displaylog("N","frequency changed to " + QString::number(value) + " (hz)","Displayfrequency function run completed");
}

/*  display frequency value;*/

void WasapiBox::Displaytime()
{
    double value = Moduleb->ui->doubleSpinBox_3->value();
    Logger->Displaylog("N","time changed to " + QString::number(value) + " (s)","Displaytime function run completed");
}

/*  display time value;*/

QByteArray WasapiBox::Sinewave(double sampletime,double amplitude,int frequency)
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
    Logger->Displaylog("N","generate sinewave completed","Sinewave function run completed");
    return signaldata;
}

/*  return signal wave data;*/

QByteArray WasapiBox::Signalwave()
{
    return Sinewave(0.01,Amplitude,Frequency);
}

/*  return sine wave data;*/

void WasapiBox::Analysisaudio()
{
    int status = Analysisstatus.size();
    if(status == 8)
    {
        Updatefigureparameter[3] = 11;
        SuperM->Changeanalysistext(Modulec->ui->pushButton_99,&Analysisstatus,Updatefigureparameter.at(3));
        Analysisaudioinit(true,false);
        QAudioSource *audiosource = new QAudioSource(Inputdevicelist.at(Modulea->ui->comboBox_25->currentIndex()),Inputformat);
        audiosource->setBufferSize(Modulec->ui->doubleSpinBox_4->value() * 2);
        Threaduf = new UpdateFigure(&Allrecorddata,audiosource,Timefigwidget,Fftfigwidget,&Updatefigureparameter);
        connect(Threaduf,&UpdateFigure::Signalua,   this,       &WasapiBox::Signaluarslot);
        connect(Threaduf,&UpdateFigure::Signalub,   this,       &WasapiBox::Signalubrslot);
        connect(Threaduf,&UpdateFigure::Signaluc,   this,       &WasapiBox::Stopanalysisaudio);
        connect(Threaduf,&UpdateFigure::finished,   Threaduf,   &QObject::deleteLater);
        Threaduf->start();
        Logger->Displaylog("N","start new thread analysis audio and update figure","Analysisaudio function running...");
    }
}

/*  opearte ui and start analysis audio;*/

void WasapiBox::Analysisaudioinit(bool boola,bool boolb)
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
    Enablerefreshdevicebutton();
}

/*  opearte ui;*/

void WasapiBox::Plotinit()
{
    Timefigwidget->addGraph();
    Timefigwidget->addGraph();
    Timefigwidget->graph(0)->setPen(Backgroundcolor);
    Timefigwidget->graph(1)->setPen(Concolor);
    Timefigwidget->graph(0)->setAdaptiveSampling(true);
    Timefigwidget->graph(1)->setAdaptiveSampling(true);
    Timefigwidget->replot(QCustomPlot::rpQueuedReplot);
    Timefigwidget->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
    Timefigwidget->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);
    Timefigwidget->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
    Fftfigwidget->addGraph();
    Fftfigwidget->addGraph();
    Fftfigwidget->graph(0)->setPen(Backgroundcolor);
    Fftfigwidget->graph(1)->setPen(Concolor);
    Fftfigwidget->graph(0)->setAdaptiveSampling(true);
    Fftfigwidget->graph(1)->setAdaptiveSampling(true);
    Fftfigwidget->replot(QCustomPlot::rpQueuedReplot);
    Fftfigwidget->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
    Fftfigwidget->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);
    Fftfigwidget->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
}

/*  figure init;*/

void WasapiBox::Stopanalysisaudio()
{
    Updatefigureparameter[3] = 8;
    SuperM->Changeanalysistext(Modulec->ui->pushButton_99,&Analysisstatus,Updatefigureparameter.at(3));
}

/*  stop analysis audio;*/

void WasapiBox::Changeplotmode()
{
    if(Updatefigureparameter.at(0) == 1)
    {
        Updatefigureparameter[0] = 0;
        Modulec->ui->checkBox_2->setChecked(false);
        Logger->Displaylog("N","plot display mode changed to manual","Changeplotmode function run completed");
    }
    else
    {
        Updatefigureparameter[0] = 1;
        Modulec->ui->checkBox_2->setChecked(true);
        Logger->Displaylog("N","plot display mode changed to auto","Changeplotmode function run completed");
    }
}

/* change plot display mode;*/

void WasapiBox::Changelimitmode()
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
    Logger->Displaylog("N","record limit mode changed as " + Modulec->ui->comboBox->currentText(),"Changelimitmode function run completed");
}

/* change limit mode;*/

void WasapiBox::Changelimit()
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
    Logger->Displaylog("N","record limit changed as " + Modulec->ui->spinBox->text(),"Changelimit function run completed");
}

/* change limit;*/

void WasapiBox::Changedbvmode()
{
    Updatefigureparameter[2] = Modulec->ui->comboBox_33->currentIndex();
    Logger->Displaylog("N","dbv mode changed as " + Modulec->ui->comboBox_33->currentText(),"Changedbvmode function run completed");
}

/* change dbv mode;*/

void WasapiBox::Changethddegree()
{
    int degree = Modulec->ui->doubleSpinBox_5->value();
    Updatefigureparameter[1] = degree;
    Logger->Displaylog("N","thd degree changed to " + QString::number(degree),"Changethddegree function run completed");
}

/* change plot display mode;*/

void WasapiBox::Generatewavfileinit()
{
    if(Moduleb->ui->doubleSpinBox_3->value() <= 0 || Moduleb->ui->doubleSpinBox->value() <= 0)
    {
        SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"amplitude or time must > 0");
        messagebox->Messageinit();
        Logger->Displaylog("N","amplitude or time must > 0","Generatewavfile function run completed");
    }
    else
    {
        SuperFileDialog *filedialog = new SuperFileDialog(nullptr,Currentpath,{"*.wav"});
        connect(filedialog,&SuperFileDialog::Signalfb,this,         &WasapiBox::Generatewavfile);
        connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
        filedialog->Setsavefile();
        filedialog->Show();
    }
}

/* generate wav file init;*/

void WasapiBox::Generatewavfile(QString wavfile)
{   
    QFileInfo fileinfo(wavfile);
    Currentpath = fileinfo.absolutePath();
    QByteArray bytes = Sinewave(Moduleb->ui->doubleSpinBox_3->value(),Moduleb->ui->doubleSpinBox->value(),Moduleb->ui->doubleSpinBox_2->value());
    SuperC->Creatfile(wavfile);
    SuperM->Writewavfile(wavfile,bytes.size(),Outputchannelcount,Outputsamplerate,Outputchannelcount * Outputsamplerate * 2,Outputchannelcount * 2,bytes);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,wavfile + " has been created;\nclick ok open path;");
    connect(messagebox,&SuperNoteDialog::Signalnb,this,&WasapiBox::Opengeneratepath);
    messagebox->Messageinit();
    Logger->Displaylog("N","wav file generate completed","Generatewavfile function run completed");
}

/* generate wav file;*/

void WasapiBox::Openrecordpath()
{
    SuperC->Openpath(Temppath);
}

/* open record path;*/

void WasapiBox::Opengeneratepath()
{
    SuperC->Openpath(Currentpath);
}

/* open generate path;*/

void WasapiBox::Signalpwaslot()
{
    Signalpwslotapi();
}

/*  end signals' thread , release memory and reset ui;*/

void WasapiBox::Signalpwbslot(QString status)
{
    if(status != "selection")
    {
        Signalpwslotapi();
    }
}

/*  end signals' thread , release memory and reset ui;*/

void WasapiBox::Signalpwslotapi()
{
    File->close();
    File = nullptr;
    Threadpw = nullptr;
    SuperM->Changeplaytext(Moduleb->ui->pushButton_97,&Playstatus,4);
    Moduleb->ui->pushButton_97->setEnabled(true);
    Moduleb->ui->pushButton_100->setEnabled(false);
    Moduleb->ui->checkBox_24->setEnabled(true);
    Modulea->ui->comboBox_24->setEnabled(true);
    Enablerefreshdevicebutton();
    Setplaymode();
    Logger->Displaylog("N","wav file has been play completed","Signalwpslot function run completed");
}

void WasapiBox::Signalspslot()
{
    Threadps = nullptr;
    Moduleb->ui->pushButton_97->setEnabled(true);
    SuperM->Changeplaytext(Moduleb->ui->pushButton_97,&Playstatus,4);
    Moduleb->ui->pushButton_100->setEnabled(false);
    Moduleb->ui->checkBox_24->setEnabled(true);
    Modulea->ui->comboBox_24->setEnabled(true);
    Enablerefreshdevicebutton();
    Setplaymode();
    Logger->Displaylog("N","signal has been play completed","Signalspslot function run completed");
}

/*  end signals' thread , release memory and reset ui;*/

void WasapiBox::Signaluarslot(QString strdbv,QString strfreq,QString strthd)
{
    Modulec->ui->lineEdit_42->setText(strdbv);
    Modulec->ui->lineEdit_47->setText(strfreq);
    Modulec->ui->lineEdit_49->setText(strthd);
}

/*  input dbv freq thd from signal;*/

void WasapiBox::Signalubrslot(QString text)
{
    Threaduf = nullptr;
    Analysisaudioinit(false,true);
    Savewavfile();
    Modulec->ui->spinBox->setEnabled(Updatefigureparameter.at(4));
    Logger->Displaylog("N",text,"Signalubslot function run completed");
}

/*  end analysis wav thread and operate ui;*/

void WasapiBox::Savewavfile()
{
    if(Modulec->ui->comboBox->currentIndex())
    {
        QString localtime = "_" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + "_";
        SuperM->Writewavfile(Temppath + localtime + ".wav",Allrecorddata.size(),Inputchannelcount,Inputsamplerate,Inputchannelcount * Inputsamplerate * 2,Inputchannelcount * 2,Allrecorddata);
        SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,localtime + ".wav has been created;\nclick ok open path;");
        connect(messagebox,&SuperNoteDialog::Signalnb,this,&WasapiBox::Openrecordpath);
        messagebox->Messageinit();
    }
    Allrecorddata.clear();
}

/*  save wav file;*/

UpdateFigure::UpdateFigure(QByteArray *allrecorddata,QAudioSource *audiosource,SuperPlot* timeplot,SuperPlot* fftplot,QVector<int> *updatefigureparameter)
{
    Allrecorddata = allrecorddata;
    Audiosource = audiosource;
    Timeplot = timeplot;
    Fftplot = fftplot;
    Updatefigureparameter = updatefigureparameter;
    Init();
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

void UpdateFigure::Init()
{
    SuperC = new SuperCore(this);
    SuperM = new SuperMultiMedia(this);
    Bits = SuperM->Enumbitstoint(Audiosource->format().sampleFormat());
    Inputsamplerate = Audiosource->format().sampleRate();
    Maxinputchannel = Audiosource->format().channelCount();
    Maxval = pow(2,Bits - 1) - 1;
}

/*  object init;*/

void UpdateFigure::run()
{
    Recordaduioinit();
    Emitresult();
}

void UpdateFigure::Recordaduioinit()
{
    QIODevice *iodevice = Audiosource->start();
    Buffersize = Audiosource->bufferSize();
    Intcount = Buffersize / sizeof(int16_t) / Maxinputchannel;
    Xtime   = SuperC->Arange(0,Intcount,1);
    Xfft    = SuperC->Linspace(0,Inputsamplerate / 2,Intcount / 2);
    Ylffti  = (double*)fftw_malloc(sizeof(double)* Intcount);
    Ylffto  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)* Intcount);
    Yrffti  = (double*)fftw_malloc(sizeof(double)* Intcount);
    Yrffto  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)* Intcount);
    Ylfftro = (double*)fftw_malloc(sizeof(double)* Intcount);
    Yrfftro = (double*)fftw_malloc(sizeof(double)* Intcount);
    Plan = fftw_plan_dft_r2c_1d(Intcount, Ylffti, Ylffto, FFTW_MEASURE);
    Recording(iodevice,Audiosource);
}

/*  record audio init;*/

void UpdateFigure::Recording(QIODevice* iodevice,QAudioSource* audiosource)
{
    while(true)
    {
        if(Updatefigureparameter->at(3) == 11)
        {
            Caldata(iodevice);
        }
        else
        {
            audiosource->stop();
            break;
        }
    }
}

/*  record audio and analysis, draw data;*/

void UpdateFigure::Caldata(QIODevice* iodevice)
{
    if(Maxinputchannel == 1)
    {
        Analysischannela(iodevice);
    }
    else
    {
        Analysischannelb(iodevice);
    }
}

/*  cal single or double channel data;*/

void UpdateFigure::Analysischannela(QIODevice* iodevice)
{
    int16_t yl = 0;
    QVector <double> ylvector = {};
    QVector <double> ylfftvector = {};
    bool boola = Read(iodevice,&Recorddata);
    if(!Recorddata.isEmpty() && boola)
    {
        for(int i = 0;i < Intcount;i++)
        {
            yl = Recorddata.at(i * 2) & 0x00FF;
            yl |= (Recorddata.at(i * 2 + 1) << 8) & 0xFF00;
            Ylffti[i] = yl;
            ylvector.append(yl);
        }
        fftw_execute_dft_r2c(Plan,Ylffti,Ylffto);
        Calrealdata(Intcount / 2,Ylffto,Ylfftro,&ylfftvector);
        Resultdbv = SuperM->Caldbv(Ylffti,Intcount,Updatefigureparameter->at(2),Maxval) + "(dbv)";
        Frequencyl = SuperM->Calfreq(Ylffti,Intcount,Inputsamplerate);
        Resultfrequency = QString::number(Frequencyl,'f',3) + "(hz)";
        Resultthd = SuperM->Calthd(Frequencyl,Ylfftro,Inputsamplerate,Intcount,Updatefigureparameter->at(1)) + "(thd)";
        emit Signalua(Resultdbv,Resultfrequency,Resultthd);
        Updatefigb(ylvector,ylfftvector);
        Timeplot->replot(QCustomPlot::rpQueuedReplot);
        Fftplot->replot(QCustomPlot::rpQueuedReplot);
    }
}

/*  cal single data;*/

void UpdateFigure::Analysischannelb(QIODevice* iodevice)
{
    int16_t yl = 0;
    int16_t yr = 0;
    QVector <double> ylvector = {};
    QVector <double> yrvector = {};
    QVector <double> ylfftvector = {};
    QVector <double> yrfftvector = {};
    bool boola = Read(iodevice,&Recorddata);
    if(!Recorddata.isEmpty() && boola)
    {
        for(int i = 0;i < Intcount;i++)
        {
            yl = Recorddata.at(i * 4) & 0x00FF;
            yl |= (Recorddata.at(i * 4 + 1) << 8) & 0xFF00;
            yr = Recorddata.at(i * 4 + 2) & 0x00FF;
            yr |= (Recorddata.at(i * 4 + 3) << 8) & 0xFF00;
            Ylffti[i] = yl;
            Yrffti[i] = yr;
            ylvector.append(yl);
            yrvector.append(yr);
        }
        fftw_execute_dft_r2c(Plan,Ylffti,Ylffto);
        fftw_execute_dft_r2c(Plan,Yrffti,Yrffto);
        Calrealdata(Intcount / 2,Ylffto,Ylfftro,&ylfftvector);
        Calrealdata(Intcount / 2,Yrffto,Yrfftro,&yrfftvector);
        Resultdbv = SuperM->Caldbv(Ylffti,Intcount,Updatefigureparameter->at(2),Maxval) + "," + SuperM->Caldbv(Yrffti,Intcount,Updatefigureparameter->at(2),Maxval) + "(dbv)";
        Frequencyl = SuperM->Calfreq(Ylffti,Intcount,Inputsamplerate);
        Frequencyr = SuperM->Calfreq(Yrffti,Intcount,Inputsamplerate);
        Resultfrequency = QString::number(Frequencyl,'f',3) + "," + QString::number(Frequencyr,'f',3) + "(hz)";
        Resultthd = SuperM->Calthd(Frequencyl,Ylfftro,Inputsamplerate,Intcount,Updatefigureparameter->at(1)) + "," + SuperM->Calthd(Frequencyr,Yrfftro,Inputsamplerate,Intcount,Updatefigureparameter->at(1)) + "(thd)";
        emit Signalua(Resultdbv,Resultfrequency,Resultthd);
        Updatefiga(ylvector,yrvector,ylfftvector,yrfftvector);
        Timeplot->replot(QCustomPlot::rpQueuedReplot);
        Fftplot->replot(QCustomPlot::rpQueuedReplot);
    }
}

/*  cal double channel data;*/

void UpdateFigure::Calrealdata(int count,fftw_complex* complex,double* yreal,QVector<double>* y)
{
    double temp = 0;
    for (int i = 0;i < count;i++)
    {
        temp = sqrt(complex[i][0] * complex[i][0] + complex[i][1] * complex[i][1]) / count / Maxval;
        yreal[i] = temp;
        y->append(20 * log10(temp));
    }
}

/*  add int_16 data to doubleqvector,double pointer;*/

bool UpdateFigure::Read(QIODevice* iodevice,QByteArray *data)
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
                    emit Signaluc();
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
                    emit Signaluc();
                    return false;
                }
            }
        }
    }
    return true;
}

/*  read data from inputdevice;*/

void UpdateFigure::Updatefiga(QVector<double> yl,QVector<double> yr,QVector<double> ylfft,QVector<double> yrfft)
{
    Timeplot->graph(0)->setData(Xtime,yl);
    Timeplot->graph(1)->setData(Xtime,yr);
    Fftplot->graph(0)->setData(Xfft,ylfft);
    Fftplot->graph(1)->setData(Xfft,yrfft);
    if(Updatefigureparameter->at(0))
    {
        Timeplot->rescaleAxes();
        Fftplot->xAxis->setRange(Frequencyl - Autorange,Frequencyl + Autorange);
        Fftplot->yAxis->rescale(true);
    }
}

/*  update figurea;*/

void UpdateFigure::Updatefigb(QVector<double> yl,QVector<double> ylfft)
{
    Timeplot->graph(0)->setData(Xtime,yl);
    Fftplot->graph(0)->setData(Xfft,ylfft);
    if(Updatefigureparameter->at(0))
    {
        Timeplot->rescaleAxes();
        Fftplot->xAxis->setRange(Frequencyl - Autorange,Frequencyl + Autorange);
        Fftplot->yAxis->rescale(true);
    }
}

/*  update figureb;*/

void UpdateFigure::Emitresult()
{
    emit Signalub(Analysisresult);
}

/*  emit result;*/
