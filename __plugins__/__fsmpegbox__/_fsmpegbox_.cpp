#include "_fsmpegbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new FsmpegBox();
}

/*  return class FsmpegBox new instance pointer;*/

FsmpegBox::FsmpegBox(QWidget *parent)
    : SuperTab(parent)
{
    readMe("FsmpegBox");
    setGroupBox(1,1);
    setStretch({100},{100});
    init();
}

FsmpegBox::~FsmpegBox()
{
    delete Progressbar;
}

void FsmpegBox::init()
{
    objectInit();
    parameterInit();
}

void FsmpegBox::objectInit()
{
    Multimedia = new SuperMultiMedia(this);
    Progressbar = new SuperProgressBarDialog(nullptr);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.flac","*.ape","*.mp3"});
    connect(Filemanager,&SuperFileManager::signalFa,Logger,&SuperLogger::displayLog);
    connect(Filemanager,&SuperFileManager::signalFc,this,&FsmpegBox::convert);
    connect(Filemanager,&SuperFileManager::signalFd,this,&FsmpegBox::convert);
}

/*  object init;*/

void FsmpegBox::parameterInit()
{
    Mpegfilelist = &Filemanager->Filelist;
    Filemanager->enableWidgetList();
    Filemanager->personalization(Sourcepath,"Mpeg");
    Filemanager->checkFileVaildInit();
}

/*  parameter init;*/

void FsmpegBox::convert()
{
    QString mpegfile = Filemanager->getCurrentItemText();
    Filemanager->setCurrentFile(mpegfile);
    AudioFormatDialog *audiodialog = new AudioFormatDialog(nullptr);
    connect(audiodialog,&AudioFormatDialog::signalAa,this,&FsmpegBox::convertMode);
    connect(audiodialog,&AudioFormatDialog::signalAb,this,&FsmpegBox::selectConvertPostion);
    audiodialog->show();
    Logger->displayLog("N",mpegfile + " audio format dialog opened;","Convert function run completed");
}

/*  convert;*/

void FsmpegBox::convertMode(int id)
{
    Convertid = id;
}

/*  record convert id;*/

void FsmpegBox::selectConvertPostion(int convertpath)
{
    QString convertfoldertemp = "";
    if(convertpath)
    {
        SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{});
        connect(filedialog,&SuperFileDialog::signalFb,this,         &FsmpegBox::convertPosition);
        connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
        filedialog->setSaveFolder();
        filedialog->show();
    }
    else
    {
        QFileInfo fileinfo(Filemanager->getCurrentItemText());
        convertPosition(fileinfo.absolutePath());
    }
}

/*  select convert path;*/

void FsmpegBox::convertPosition(QString convertpath)
{
    Convertfolder = Core->fixFilePath(convertpath);
    findDecoder();
}

/*  select convert path;*/

void FsmpegBox::findDecoder()
{
    if(!Convertfolder.isEmpty())
    {
        Infileinfo.setFile(Filemanager->getCurrentItemText());
        QFile::remove(Outfilename);
        Infilename = Cachefile + Infileinfo.suffix();
        Core->replaceFile(Infileinfo.absoluteFilePath(),Infilename);
        Logger->displayLog("N","convert path:\n" + Convertfolder,"Convertaslocalpath function run completed;");
        if(Infileinfo.suffix().contains("flac",Qt::CaseInsensitive))
        {
            decodeFlac();
        }
        else if(Infileinfo.suffix().contains("ape",Qt::CaseInsensitive))
        {
            decodeApe();
        }
        else if(Infileinfo.suffix().contains("mp3",Qt::CaseInsensitive))
        {
            decodeMp3();
        }
    }
    else
    {
        Logger->displayLog("N","cancel select convert path;","Selectconvertpath function run completed;");
    }
}

/*  find decoder;*/

void FsmpegBox::decodeFlac()
{
    Flacdecoder = new SuperFlacDecoder(this,Infilename,Outfilename);
    connect(Flacdecoder,&SuperFlacDecoder::finished,this,        &FsmpegBox::decodeEnd);
    connect(Flacdecoder,&SuperFlacDecoder::signalFa,this,        &FsmpegBox::setProgress);
    connect(Flacdecoder,&SuperFlacDecoder::signalFb,this,        &FsmpegBox::convertError);
    connect(Flacdecoder,&SuperFlacDecoder::finished,Flacdecoder, &QObject::deleteLater);
    Progressbar->show();
    Flacdecoder->start();
}

/*  decode flac file;*/

void FsmpegBox::decodeEnd()
{
    QFileInfo fileinfo(Outfilename);
    Progressbar->setValueMessage(100,"convert completed;");
    if(fileinfo.exists() && fileinfo.size() > 44)
    {
        Core->replaceFile(Outfilename,Convertfolder + Infileinfo.completeBaseName() + "." + fileinfo.suffix());
        QStringList wavfileinfo = Multimedia->wavInfo(fileinfo.absoluteFilePath());
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"samplerate: " + wavfileinfo.at(7) + ",bits: " + wavfileinfo.at(10) + ",channel: " + wavfileinfo.at(6) + ";\nclick ok open path;");
        connect(notedialog,&SuperNoteDialog::signalNb,this,&FsmpegBox::openConvertPath);
        notedialog->messageInit();
    }
    else
    {
        QFile::remove(fileinfo.absoluteFilePath());
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,Error + ";/ntips: make sure no chinese path;");
        notedialog->messageInit();
    }
}

/*  delete flac decoder;*/

void FsmpegBox::decodeApe()
{
    Apedecoder = new SuperApeDecoder(this,Infilename,Outfilename);
    connect(Apedecoder,&SuperApeDecoder::finished,Apedecoder,&QObject::deleteLater);
    connect(Apedecoder,&SuperApeDecoder::signalAa,this,      &FsmpegBox::setProgress);
    connect(Apedecoder,&SuperApeDecoder::finished,this,      &FsmpegBox::decodeEnd);
    Progressbar->show();
    Apedecoder->start();
}

/*  decode flac file;*/

void FsmpegBox::decodeMp3()
{
    Mp3decoder = new SuperMp3Decoder(this,Infilename,Outfilename);
    connect(Mp3decoder,&SuperMp3Decoder::finished,Mp3decoder,&QObject::deleteLater);
    connect(Mp3decoder,&SuperMp3Decoder::Signalma,this,      &FsmpegBox::setProgress);
    connect(Mp3decoder,&SuperMp3Decoder::finished,this,      &FsmpegBox::decodeEnd);
    Progressbar->show();
    Mp3decoder->start();
}

/*  decode mp3 file;*/

void FsmpegBox::setProgress(int progress)
{
    Progressbar->setValueMessage(progress,"converting...");
}

/*  set progress;*/

void FsmpegBox::convertError(QString error)
{
    Error = error;
}

/*  change error info;*/

void FsmpegBox::openConvertPath()
{
    Core->openPath(Convertfolder);
}

/*  open convert path;*/
