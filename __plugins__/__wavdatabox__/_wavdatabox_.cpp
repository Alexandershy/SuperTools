#include "_wavdatabox_.h"

Interface::Interface()
{
    WavDataBox();
}

/*  return class wavdatabox new instance pointer;*/

WavDataBox::WavDataBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("WavDataBox");
    Setgroupbox(2,1);
    Setstretch({99,1},{100}); 
    Init();
}

WavDataBox::~WavDataBox()
{
    Stop();
    SuperC->Closethread(Threadpa);
}

void WavDataBox::Init()
{
    Objectinit();
    Parameterinit();
}

/*  object init;*/

void WavDataBox::Objectinit()
{
    File = new QFile(this);
    Hook = new SuperHook(this);
    SuperM = new SuperMultiMedia(this);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.wav"});
    Modulea = new ModuleA(this,Leftgroupboxlist.at(1)->Insidelayout);
    connect(Filemanager,&SuperFileManager::Signalfa,Logger, &SuperLogger::Displaylog);
    connect(Filemanager,&SuperFileManager::Signalfb,this,   &WavDataBox::Stop);
    connect(Filemanager,&SuperFileManager::Signalfc,this,   &WavDataBox::Clickwavfile);
    connect(Filemanager,&SuperFileManager::Signalfd,this,   &WavDataBox::Actionopen);
    connect(Filemanager,&SuperFileManager::Signalfe,this,   &WavDataBox::Deletefileslot);
    connect(Modulea->ui->pushButton_5,    &QPushButton::clicked,    this,   &WavDataBox::Changeplaymode);
    connect(Modulea->ui->pushButton_7,    &QPushButton::clicked,    this,   &WavDataBox::Play);
    connect(Modulea->ui->pushButton_2,    &QPushButton::clicked,    this,   &WavDataBox::Stop);
    connect(Modulea->ui->horizontalSlider,&QSlider::sliderReleased, this,   &WavDataBox::Setwavfilepos);
    connect(Modulea->ui->pushButton_6,    &QPushButton::clicked,    this,   &WavDataBox::Nextwavfile);
    connect(Modulea->ui->pushButton_3,    &QPushButton::clicked,    this,   &WavDataBox::Lastwavfile);
    connect(Modulea,                      &ModuleA::Signalwa,       this,   &WavDataBox::Nodeviceexist);
    connect(Modulea,                      &ModuleA::Signalwb,       this,   &WavDataBox::Signalcaslot);
    Hook->Setpressedfunction(std::bind(&WavDataBox::Keypressedevent,this,std::placeholders::_1));
    Hook->Setsourcekeylist(&Multikeylist);
}

/*  object init;*/

void WavDataBox::Parameterinit()
{
    Wavfilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_5);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_7);
    Filemanager->Enablewidgetlist();
    Filemanager->Personalization(Sourcepath,"Wav");
    Filemanager->Checkfilevaildinit();
    Modulea->Checkdefaultdevice();
}

/*  parameter init;*/

void WavDataBox::Deletefileslot(QString file)
{
    if(Wavfile == file)
    {
        Stop();
    }
}

/*  delete wav files;*/

void WavDataBox::Changewavfileapi(int direction)
{
    QTableWidgetItem *item = nullptr;
    int index = SuperC->Findlistmember(Wavfilelist,Wavfile);
    if(index >= 0)
    {
        switch(Playmode)
        {
            case 0:
            {
                item = Filemanager->ui->tableWidget->item(index,0);
                break;
            }
            case 1:
            {
                item = Filemanager->ui->tableWidget->item((index + direction + Wavfilelist->count()) % Wavfilelist->count(),0);
                break;
            }
            case 2:
            {
                int time = QDateTime::currentDateTime().toString("hhmmsszzz").toInt();
                item = Filemanager->ui->tableWidget->item(time % Wavfilelist->count(),0);
            }
        }
        Filemanager->ui->tableWidget->setCurrentItem(item);
        Wavfile = Filemanager->Getcurrentitemtext();
        Filemanager->Setcurrentfile(Wavfile);
    }
}

/*  change wavfile api;*/

void WavDataBox::Nextwavfile()
{
    Stop();
    Wavfilechangedirection = 1;
}

/*  cal next item position;*/

void WavDataBox::Lastwavfile()
{
    Stop();
    Wavfilechangedirection = -1;
}

/*  cal last item position;*/

void WavDataBox::Clickwavfile()
{
    if(Filemanager->Getcurrentitemtext() == Wavfile)
    {
        Play();
    }
    else
    {
        if(Playstatus.size() == 4)
        {
            Play();
        }
        else
        {
            Stop();
            disconnect(Filemanager,&SuperFileManager::Signalfc,this,&WavDataBox::Clickwavfile);
            Wavfilechangedirection = 10;
        }
    }
}

/*  cal next item position;*/

void WavDataBox::Changeplaymode()
{
    switch(Playmode)
    {
        case 0:
        {
            Playmode = 1;
            Logger->Displaylog("N","play mode set as list loop","Changeplaymode function run completed;");
            Modulea->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_listloop_.svg"));
            break;
        }
        case 1:
        {
            Playmode = 2;
            Logger->Displaylog("N","play mode set as random","Changeplaymode function run completed;");
            Modulea->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_random_.svg"));
            break;
        }
        case 2:
        {
            Playmode = 0;
            Logger->Displaylog("N","play mode set as single cycle","Changeplaymode function run completed;");
            Modulea->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_singlecycle_.svg"));
            break;
        }
    }
}

/*  change play mode;*/

void WavDataBox::Play()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            SuperM->Changeplayicon(Modulea->ui->pushButton_7,&Playstatus,7);
            Setplaywavfile();
            Playwavfiles();
            break;
        }
        case 7:
        {
            SuperM->Changeplayicon(Modulea->ui->pushButton_7,&Playstatus,9);
            Logger->Displaylog("N","wav file play suspended","Play function suspended");
            break;
        }
        case 9:
        {
            SuperM->Changeplayicon(Modulea->ui->pushButton_7,&Playstatus,7);
            Logger->Displaylog("N","wav file resume playing...","Play function running...");
            break;
        }
    }
}

/*  change play mode ,play or suspended,and operate some widget;*/

void WavDataBox::Setplaywavfile()
{
    if(Filemanager->ui->tableWidget->currentItem() == nullptr)
    {
        Filemanager->ui->tableWidget->setCurrentItem(Filemanager->ui->tableWidget->item(0,0));
    }
    Wavfile = Filemanager->Getcurrentitemtext();
    Filemanager->Setcurrentfile(Wavfile);
}

/*  set wav file will be play;*/

void WavDataBox::Playwavfiles()
{
    Getwavfileformat();
    Modulea->ui->pushButton_2->setEnabled(true);
    Modulea->ui->pushButton_3->setEnabled(true);
    Modulea->ui->pushButton_6->setEnabled(true);
    Modulea->ui->horizontalSlider->setEnabled(true);
    QAudioSink *audiosink = new QAudioSink(QMediaDevices::defaultAudioOutput(),Format);
    Threadpa = new SuperPlayWav(File,File->size(),&Playstatus,audiosink);
    connect(Threadpa,       &SuperPlayWav::Signalpa, this,       &WavDataBox::Signalwpaslot);
    connect(Threadpa,       &SuperPlayWav::Signalpb, this,       &WavDataBox::Signalwpbslot);
    connect(Threadpa->Timer,&QTimer::timeout,   this,       &WavDataBox::Signalwpcslot);
    connect(Threadpa,       &SuperPlayWav::finished, Threadpa,   &QObject::deleteLater);
    Threadpa->Timer->setInterval(200);
    Threadpa->start();
    Logger->Displaylog("N","start new thread for play wav file","Play function running...");
}

/*  play wav files;*/

void WavDataBox::Getwavfileformat()
{
    File->setFileName(Wavfile);
    File->open(QIODevice::ReadOnly);
    Wavfileinfo = SuperM->Wavinfo(Wavfile);
    Timelength = Wavfileinfo.at(1).toInt();
    Samplerate = Wavfileinfo.at(7).toInt();
    Bits = Wavfileinfo.at(10).toInt();
    Bitspersample = Wavfileinfo.at(9).toInt();
    Channelcounts = Wavfileinfo.at(6).toInt();
    QList<QString> wavelist = {"RIFF","filelen","WAVE","fmt","fmtlen","wformattag","wchannels","dwsamplerate","dwavgbyterate","wblockalign","wbitspersample","wextsize","extralinfo"};
    Setdeviceformat(&Format,Samplerate,Bits,Channelcounts);
    Logger->Displaylog("N","selected wav: " + Wavfile,"Getwavfileformat function run completed");
    Setslidervalue();
    for(int i = 0;i < Wavfileinfo.count();i++)
    {
        Logger->Displaylog("N",wavelist.at(i) + ": " + Wavfileinfo.at(i),"Getwavfileformat function run completed");
    }
}

/*  get wav file format and set slider pos;*/

void WavDataBox::Setdeviceformat(QAudioFormat *format,int samplerate,int samplesize,int channels)
{
    format->setSampleRate(samplerate);
    format->setSampleFormat(SuperM->Intbitstoenum(samplesize));
    format->setChannelCount(channels);
}

/*  set default audio format;*/

void WavDataBox::Setslidervalue()
{
    Modulea->ui->horizontalSlider->setMaximum(Timelength);
    Modulea->ui->label->setText(QString::number(0,'f',1));
    Modulea->ui->label_3->setText(QString::number(double(Timelength) / Bitspersample / Samplerate,'f',1) + " (s)");
}

void WavDataBox::Stop()
{
    Wavfilechangedirection = 0;
    SuperM->Changeplayicon(Modulea->ui->pushButton_7,&Playstatus,4);
}

/*  stop play audio;*/

void WavDataBox::Setwavfilepos()
{
    int filepostemp = Modulea->ui->horizontalSlider->value() / Bitspersample;
    Modulea->ui->label->setText(QString::number(filepostemp / Samplerate,'f',1));
    int filepos = filepostemp * Bitspersample;
    File->seek(filepos);
}

/*  set wav file pos;*/

void WavDataBox::Showdatadialog()
{
    Modulea->ui->pushButton_7->setEnabled(false);
    DataDialog *dialog = new DataDialog(nullptr,Wavfile);
    connect(dialog,&DataDialog::Signalda,this,&WavDataBox::Enableplaykey);
    Dialogcounts = Dialogcounts + 1;
    dialog->Show();
}

/*  show wav datadialog;*/

void WavDataBox::Actionopen()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            Disableclicked();
            Showdatadialog();
            break;
        }
        case 7:
        case 9:
        {
            Stop();
            Disableclicked();
            break;
        }
    }
}

/*  open wavfile table;*/

void WavDataBox::Disableclicked()
{
    Wavfilechangedirection = 11;
    Wavfile = Filemanager->Getcurrentitemtext();
    Filemanager->Setcurrentfile(Wavfile);
    Logger->Displaylog("N",Wavfile + " opened","Open function run completed");
    if(!Dialogcounts)
    {
        disconnect(Filemanager,&SuperFileManager::Signalfc,this,&WavDataBox::Clickwavfile);
        Logger->Displaylog("N","filemanager module clicked opened disabled","Disableclicked function run completed");
    }
}

/*  disable click wav file;*/

void WavDataBox::Signalwpslotapi()
{
    Threadpa = nullptr;
    File->close();
    if(!Wavfilelist->isEmpty())
    {
        Modulea->ui->pushButton_7->setEnabled(true);
    }
    Modulea->ui->pushButton_2->setEnabled(false);
    Modulea->ui->pushButton_3->setEnabled(false);
    Modulea->ui->pushButton_6->setEnabled(false);
    SuperM->Changeplayicon(Modulea->ui->pushButton_7,&Playstatus,4);
    Modulea->ui->horizontalSlider->setEnabled(false);
    Logger->Displaylog("N",Wavfile + " has been play completed","Signalwpslot function run completed");
}

/*  end signals' thread api;*/

void WavDataBox::Signalwpaslot()
{
    Signalwpslotapi();
    switch(Wavfilechangedirection)
    {
        case -1:
        case 1:
        {
            Changewavfileapi(Wavfilechangedirection);
            Play();
            break;
        }
        case 10:
        {
            Play();
            connect(Filemanager,&SuperFileManager::Signalfc,this,&WavDataBox::Clickwavfile);
            break;
        }
        case 11:
        {
            Showdatadialog();
            break;
        }
    }
}

/*  end signals' thread, release memory and reset ui;*/

void WavDataBox::Signalwpbslot(QString status)
{
    if(status != "selection")
    {
        Signalwpslotapi();
        Changewavfileapi(1);
        Play();
    }
}

/*  end signals' thread , restart thread;*/

void WavDataBox::Signalwpcslot()
{
    if(!Modulea->ui->horizontalSlider->isSliderDown() && File->isOpen())
    {
        QString postempa = QString::number(double(File->pos()) / Samplerate / Bitspersample,'f',1);
        Modulea->ui->horizontalSlider->setValue(File->pos());
        Modulea->ui->label->setText(postempa);
    }
}

/*  display file pos by horizontalslider;*/

void WavDataBox::Signalcaslot()
{
    if(Playstatus.size() == 7 || Playstatus.size() == 9)
    {
        Stop();
        Logger->Displaylog("N","default device changed,wav file play stoped","Signalcaslot function run completed;");
    }
}

/*  default play device changed;*/

void WavDataBox::Nodeviceexist()
{
    Filemanager->Disableopen();
    disconnect(Modulea->ui->pushButton_7,&QPushButton::clicked,this,&WavDataBox::Play);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"can not find any output deivce;");
    messagebox->Hideleftbutton();
    messagebox->Messageinit();
}

/*  not found any play device;*/

void WavDataBox::Enableplaykey()
{
    Dialogcounts = Dialogcounts - 1;
    if(!Dialogcounts)
    {
        Modulea->ui->pushButton_7->setEnabled(true);
        connect(Filemanager,&SuperFileManager::Signalfc,this,&WavDataBox::Clickwavfile);
        Logger->Displaylog("N","filemanager module clicked opened enabled","Disableclicked function run completed");
    }
}

/*  enable play key;*/

void WavDataBox::Keypressedevent(int key)
{
    switch(key)
    {
        case PLAYLAST:
        {
            if(Modulea->ui->pushButton_3->isEnabled())
            {
                Lastwavfile();
            }
            break;
        }
        case PLAYKEY:
        {
            if(Modulea->ui->pushButton_7->isEnabled())
            {
                Play();
            }
            break;
        }
        case PLAYNEXT:
        {
            if(Modulea->ui->pushButton_6->isEnabled())
            {
                Nextwavfile();
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

/*  key pressed event;;*/
