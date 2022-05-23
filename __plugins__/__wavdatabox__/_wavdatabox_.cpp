#include "_wavdatabox_.h"

SuperTab* Interface::Loadplugin()
{
    return new WavDataBox();
}

/*  return class wavdatabox new instance pointer;*/

WavDataBox::WavDataBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("WavDataBox");
    setGroupBox(2,1);
    setStretch({99,1},{100});
    init();
}

WavDataBox::~WavDataBox()
{
    stop();
    Core->closeThread(Threadpa);
}

void WavDataBox::init()
{
    objectInit();
    parameterInit();
}

/*  object init;*/

void WavDataBox::objectInit()
{
    File = new QFile(this);
    Hook = new SuperHook(this);
    Multimedia = new SuperMultiMedia(this);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.wav"});
    Modulea = new WavdataModuleA(this,Leftgroupboxlist.at(1)->Insidelayout);
    connect(Filemanager,&SuperFileManager::signalFa,Logger, &SuperLogger::displayLog);
    connect(Filemanager,&SuperFileManager::signalFb,this,   &WavDataBox::stop);
    connect(Filemanager,&SuperFileManager::signalFc,this,   &WavDataBox::clickWavFile);
    connect(Filemanager,&SuperFileManager::signalFd,this,   &WavDataBox::actionOpen);
    connect(Filemanager,&SuperFileManager::signalFe,this,   &WavDataBox::deleteFileSlot);
    connect(Modulea->ui->pushButton_5,    &QPushButton::clicked,    this,   &WavDataBox::changePlayMode);
    connect(Modulea->ui->pushButton_7,    &QPushButton::clicked,    this,   &WavDataBox::play);
    connect(Modulea->ui->pushButton_2,    &QPushButton::clicked,    this,   &WavDataBox::stop);
    connect(Modulea->ui->horizontalSlider,&QSlider::sliderReleased, this,   &WavDataBox::setWavFilePos);
    connect(Modulea->ui->pushButton_6,    &QPushButton::clicked,    this,   &WavDataBox::nextWavFile);
    connect(Modulea->ui->pushButton_3,    &QPushButton::clicked,    this,   &WavDataBox::lastWavFile);
    connect(Modulea,                      &WavdataModuleA::signalWa,this,   &WavDataBox::nodeviceExist);
    connect(Modulea,                      &WavdataModuleA::signalWb,this,   &WavDataBox::signalCaSlot);
    Hook->setPressedFunction(std::bind(&WavDataBox::keyPressedEvent,this,std::placeholders::_1));
    Hook->setSourceKeyList(&Multikeylist);
}

/*  object init;*/

void WavDataBox::parameterInit()
{
    Wavfilelist = &Filemanager->Filelist;
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_5);
    Filemanager->Widgetlist.append(Modulea->ui->pushButton_7);
    Filemanager->enableWidgetList();
    Filemanager->personalization(Sourcepath,"Wav");
    Filemanager->checkFileVaildInit();
    Modulea->checkDefaultDevice();
}

/*  parameter init;*/

void WavDataBox::deleteFileSlot(QString file)
{
    if(Wavfile == file)
    {
        stop();
    }
}

/*  delete wav files;*/

void WavDataBox::changeWavFileApi(int direction)
{
    QTableWidgetItem *item = nullptr;
    int index = Core->findListMember(Wavfilelist,Wavfile);
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
        Wavfile = Filemanager->getCurrentItemText();
        Filemanager->setCurrentFile(Wavfile);
    }
}

/*  change wavfile api;*/

void WavDataBox::nextWavFile()
{
    stop();
    Wavfilechangedirection = 1;
}

/*  cal next item position;*/

void WavDataBox::lastWavFile()
{
    stop();
    Wavfilechangedirection = -1;
}

/*  cal last item position;*/

void WavDataBox::clickWavFile()
{
    if(Filemanager->getCurrentItemText() == Wavfile)
    {
        play();
    }
    else
    {
        if(Playstatus.size() == 4)
        {
            play();
        }
        else
        {
            stop();
            disconnect(Filemanager,&SuperFileManager::signalFc,this,&WavDataBox::clickWavFile);
            Wavfilechangedirection = 10;
        }
    }
}

/*  cal next item position;*/

void WavDataBox::changePlayMode()
{
    switch(Playmode)
    {
        case 0:
        {
            Playmode = 1;
            Logger->displayLog("N","play mode set as list loop","Changeplaymode function run completed;");
            Modulea->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_listloop_.svg"));
            break;
        }
        case 1:
        {
            Playmode = 2;
            Logger->displayLog("N","play mode set as random","Changeplaymode function run completed;");
            Modulea->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_random_.svg"));
            break;
        }
        case 2:
        {
            Playmode = 0;
            Logger->displayLog("N","play mode set as single cycle","Changeplaymode function run completed;");
            Modulea->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_singlecycle_.svg"));
            break;
        }
    }
}

/*  change play mode;*/

void WavDataBox::play()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            Multimedia->changePlayIcon(Modulea->ui->pushButton_7,&Playstatus,7);
            setPlayWavFile();
            playWavFiles();
            break;
        }
        case 7:
        {
            Multimedia->changePlayIcon(Modulea->ui->pushButton_7,&Playstatus,9);
            Logger->displayLog("N","wav file play suspended","Play function suspended");
            break;
        }
        case 9:
        {
            Multimedia->changePlayIcon(Modulea->ui->pushButton_7,&Playstatus,7);
            Logger->displayLog("N","wav file resume playing...","Play function running...");
            break;
        }
    }
}

/*  change play mode ,play or suspended,and operate some widget;*/

void WavDataBox::setPlayWavFile()
{
    if(Filemanager->ui->tableWidget->currentItem() == nullptr)
    {
        Filemanager->ui->tableWidget->setCurrentItem(Filemanager->ui->tableWidget->item(0,0));
    }
    Wavfile = Filemanager->getCurrentItemText();
    Filemanager->setCurrentFile(Wavfile);
}

/*  set wav file will be play;*/

void WavDataBox::playWavFiles()
{
    getWavFileFormat();
    Modulea->ui->pushButton_2->setEnabled(true);
    Modulea->ui->pushButton_3->setEnabled(true);
    Modulea->ui->pushButton_6->setEnabled(true);
    Modulea->ui->horizontalSlider->setEnabled(true);
    QAudioSink *audiosink = new QAudioSink(QMediaDevices::defaultAudioOutput(),Format);
    Threadpa = new SuperPlayWav(File,File->size(),&Playstatus,audiosink);
    connect(Threadpa,       &SuperPlayWav::signalPa,this,       &WavDataBox::signalWpaSlot);
    connect(Threadpa,       &SuperPlayWav::signalPb,this,       &WavDataBox::signalWpbSlot);
    connect(Threadpa->Timer,&QTimer::timeout,       this,       &WavDataBox::signalWpcSlot);
    connect(Threadpa,       &SuperPlayWav::finished,Threadpa,   &QObject::deleteLater);
    Threadpa->Timer->setInterval(200);
    Threadpa->start();
    Logger->displayLog("N","start new thread for play wav file","Play function running...");
}

/*  play wav files;*/

void WavDataBox::getWavFileFormat()
{
    File->setFileName(Wavfile);
    File->open(QIODevice::ReadOnly);
    Wavfileinfo = Multimedia->wavInfo(Wavfile);
    Timelength = Wavfileinfo.at(1).toInt();
    Samplerate = Wavfileinfo.at(7).toInt();
    Bits = Wavfileinfo.at(10).toInt();
    Bitspersample = Wavfileinfo.at(9).toInt();
    Channelcounts = Wavfileinfo.at(6).toInt();
    QList<QString> wavelist = {"RIFF","filelen","WAVE","fmt","fmtlen","wformattag","wchannels","dwsamplerate","dwavgbyterate","wblockalign","wbitspersample","wextsize","extralinfo"};
    setDeviceFormat(&Format,Samplerate,Bits,Channelcounts);
    Logger->displayLog("N","selected wav: " + Wavfile,"Getwavfileformat function run completed");
    setSliderValue();
    for(int i = 0;i < Wavfileinfo.count();i++)
    {
        Logger->displayLog("N",wavelist.at(i) + ": " + Wavfileinfo.at(i),"Getwavfileformat function run completed");
    }
}

/*  get wav file format and set slider pos;*/

void WavDataBox::setDeviceFormat(QAudioFormat *format,int samplerate,int samplesize,int channels)
{
    format->setSampleRate(samplerate);
    format->setSampleFormat(Multimedia->intBitsToEnum(samplesize));
    format->setChannelCount(channels);
}

/*  set default audio format;*/

void WavDataBox::setSliderValue()
{
    Modulea->ui->horizontalSlider->setMaximum(Timelength);
    Modulea->ui->label->setText(QString::number(0,'f',1));
    Modulea->ui->label_3->setText(QString::number(double(Timelength) / Bitspersample / Samplerate,'f',1) + " (s)");
}

void WavDataBox::stop()
{
    Wavfilechangedirection = 0;
    Multimedia->changePlayIcon(Modulea->ui->pushButton_7,&Playstatus,4);
}

/*  stop play audio;*/

void WavDataBox::setWavFilePos()
{
    int filepostemp = Modulea->ui->horizontalSlider->value() / Bitspersample;
    Modulea->ui->label->setText(QString::number(filepostemp / Samplerate,'f',1));
    int filepos = filepostemp * Bitspersample;
    File->seek(filepos);
}

/*  set wav file pos;*/

void WavDataBox::showDataDialog()
{
    Modulea->ui->pushButton_7->setEnabled(false);
    WavDataDialog *dialog = new WavDataDialog(nullptr,Wavfile);
    connect(dialog,&WavDataDialog::signalDa,this,&WavDataBox::enablePlayKey);
    Dialogcounts = Dialogcounts + 1;
    dialog->show();
}

/*  show wav datadialog;*/

void WavDataBox::actionOpen()
{
    switch(Playstatus.size())
    {
        case 4:
        {
            disableClicked();
            showDataDialog();
            break;
        }
        case 7:
        case 9:
        {
            stop();
            disableClicked();
            break;
        }
    }
}

/*  open wavfile table;*/

void WavDataBox::disableClicked()
{
    Wavfilechangedirection = 11;
    Wavfile = Filemanager->getCurrentItemText();
    Filemanager->setCurrentFile(Wavfile);
    Logger->displayLog("N",Wavfile + " opened","Open function run completed");
    if(!Dialogcounts)
    {
        disconnect(Filemanager,&SuperFileManager::signalFc,this,&WavDataBox::clickWavFile);
        Logger->displayLog("N","filemanager module clicked opened disabled","Disableclicked function run completed");
    }
}

/*  disable click wav file;*/

void WavDataBox::signalWpSlotApi()
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
    Multimedia->changePlayIcon(Modulea->ui->pushButton_7,&Playstatus,4);
    Modulea->ui->horizontalSlider->setEnabled(false);
    Logger->displayLog("N",Wavfile + " has been play completed","signalWpslot function run completed");
}

/*  end signals' thread api;*/

void WavDataBox::signalWpaSlot()
{
    signalWpSlotApi();
    switch(Wavfilechangedirection)
    {
        case -1:
        case 1:
        {
            changeWavFileApi(Wavfilechangedirection);
            play();
            break;
        }
        case 10:
        {
            play();
            connect(Filemanager,&SuperFileManager::signalFc,this,&WavDataBox::clickWavFile);
            break;
        }
        case 11:
        {
            showDataDialog();
            break;
        }
    }
}

/*  end signals' thread, release memory and reset ui;*/

void WavDataBox::signalWpbSlot(QString status)
{
    if(status != "selection")
    {
        signalWpSlotApi();
        changeWavFileApi(1);
        play();
    }
}

/*  end signals' thread , restart thread;*/

void WavDataBox::signalWpcSlot()
{
    if(!Modulea->ui->horizontalSlider->isSliderDown() && File->isOpen())
    {
        QString postempa = QString::number(double(File->pos()) / Samplerate / Bitspersample,'f',1);
        Modulea->ui->horizontalSlider->setValue(File->pos());
        Modulea->ui->label->setText(postempa);
    }
}

/*  display file pos by horizontalslider;*/

void WavDataBox::signalCaSlot()
{
    if(Playstatus.size() == 7 || Playstatus.size() == 9)
    {
        stop();
        Logger->displayLog("N","default device changed,wav file play stoped","signalCaslot function run completed;");
    }
}

/*  default play device changed;*/

void WavDataBox::nodeviceExist()
{
    Filemanager->disableOpen();
    disconnect(Modulea->ui->pushButton_7,&QPushButton::clicked,this,&WavDataBox::play);
    SuperNoteDialog *messagebox = new SuperNoteDialog(nullptr,"can not find any output deivce;");
    messagebox->hideLeftButton();
    messagebox->messageInit();
}

/*  not found any play device;*/

void WavDataBox::enablePlayKey()
{
    Dialogcounts = Dialogcounts - 1;
    if(!Dialogcounts)
    {
        Modulea->ui->pushButton_7->setEnabled(true);
        connect(Filemanager,&SuperFileManager::signalFc,this,&WavDataBox::clickWavFile);
        Logger->displayLog("N","filemanager module clicked opened enabled","Disableclicked function run completed");
    }
}

/*  enable play key;*/

void WavDataBox::keyPressedEvent(int key)
{
    switch(key)
    {
        case PLAYLAST:
        {
            if(Modulea->ui->pushButton_3->isEnabled())
            {
                lastWavFile();
            }
            break;
        }
        case PLAYKEY:
        {
            if(Modulea->ui->pushButton_7->isEnabled())
            {
                play();
            }
            break;
        }
        case PLAYNEXT:
        {
            if(Modulea->ui->pushButton_6->isEnabled())
            {
                nextWavFile();
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
