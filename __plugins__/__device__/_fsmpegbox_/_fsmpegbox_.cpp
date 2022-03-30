#include "_fsmpegbox_.h"

SuperTab* Interface::Loadplugin()
{
    return new FsmpegBox();
}

/*  return class FsmpegBox new instance pointer;*/

FsmpegBox::FsmpegBox(QWidget *parent)
    : SuperTab(parent)
{
    Readme("FsmpegBox");
    Setgroupbox(1,1);
    Setstretch({100},{100});
    Init();
}

FsmpegBox::~FsmpegBox()
{
    delete Progressbar;
}

void FsmpegBox::Init()
{
    Objectinit();
    Parameterinit();
}

void FsmpegBox::Objectinit()
{
    SuperM = new SuperMultiMedia(this);
    Progressbar = new SuperProgressBarDialog(nullptr);
    Logger = new SuperLogger(this,Rightgroupboxlist.at(0)->Insidelayout);
    Filemanager = new SuperFileManager(this,Leftgroupboxlist.at(0)->Insidelayout,{"*.flac","*.ape","*.mp3"});
    connect(Filemanager,&SuperFileManager::Signalfa,Logger,&SuperLogger::Displaylog);
    connect(Filemanager,&SuperFileManager::Signalfc,this,&FsmpegBox::Convert);
    connect(Filemanager,&SuperFileManager::Signalfd,this,&FsmpegBox::Convert);
}

/*  object init;*/

void FsmpegBox::Parameterinit()
{
    Mpegfilelist = &Filemanager->Filelist;
    Filemanager->Enablewidgetlist();
    Filemanager->Personalization(Sourcepath,"Mpeg");
    Filemanager->Checkfilevaildinit();
}

/*  parameter init;*/

void FsmpegBox::Convert()
{
    QString mpegfile = Filemanager->Getcurrentitemtext();
    Filemanager->Setcurrentfile(mpegfile);
    AudioFormatDialog *audiodialog = new AudioFormatDialog(nullptr);
    connect(audiodialog,&AudioFormatDialog::Signalaa,this,&FsmpegBox::Convertmode);
    connect(audiodialog,&AudioFormatDialog::Signalab,this,&FsmpegBox::Selectconvertpostion);
    audiodialog->Show();
    Logger->Displaylog("N",mpegfile + " audio format dialog opened;","Convert function run completed");
}

/*  convert;*/

void FsmpegBox::Convertmode(int id)
{
    Convertid = id;
}

/*  record convert id;*/

void FsmpegBox::Selectconvertpostion(int convertpath)
{
    QString convertfoldertemp = "";
    if(convertpath)
    {
        SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./",{});
        connect(filedialog,&SuperFileDialog::Signalfb,this,         &FsmpegBox::Convertposition);
        connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
        filedialog->Setsavefolder();
        filedialog->Show();
    }
    else
    {
        QFileInfo fileinfo(Filemanager->Getcurrentitemtext());
        Convertposition(fileinfo.absolutePath());
    }
}

/*  select convert path;*/

void FsmpegBox::Convertposition(QString convertpath)
{
    Convertfolder = SuperC->Fixfilepath(convertpath);
    Finddecoder();
}

/*  select convert path;*/

void FsmpegBox::Finddecoder()
{
    if(!Convertfolder.isEmpty())
    {
        Infileinfo.setFile(Filemanager->Getcurrentitemtext());
        QFile::remove(Outfilename);
        Infilename = Cachefile + Infileinfo.suffix();
        SuperC->Replacefile(Infileinfo.absoluteFilePath(),Infilename);
        Logger->Displaylog("N","convert path:\n" + Convertfolder,"Convertaslocalpath function run completed;");
        if(Infileinfo.suffix().contains("flac",Qt::CaseInsensitive))
        {
            Decodeflac();
        }
        else if(Infileinfo.suffix().contains("ape",Qt::CaseInsensitive))
        {
            Decodeape();
        }
        else if(Infileinfo.suffix().contains("mp3",Qt::CaseInsensitive))
        {
            Decodemp3();
        }
    }
    else
    {
        Logger->Displaylog("N","cancel select convert path;","Selectconvertpath function run completed;");
    }
}

/*  find decoder;*/

void FsmpegBox::Decodeflac()
{
    Flacdecoder = new FlacFileDecoder(this,Infilename,Outfilename);
    connect(Flacdecoder,&FlacFileDecoder::finished,this,        &FsmpegBox::Decodeend);
    connect(Flacdecoder,&FlacFileDecoder::Signalfa,this,        &FsmpegBox::Setprogress);
    connect(Flacdecoder,&FlacFileDecoder::Signalfb,this,        &FsmpegBox::Converterror);
    connect(Flacdecoder,&FlacFileDecoder::finished,Flacdecoder, &QObject::deleteLater);
    Progressbar->Show();
    Flacdecoder->start();
}

/*  decode flac file;*/

void FsmpegBox::Decodeend()
{
    QFileInfo fileinfo(Outfilename);
    Progressbar->Setvaluemessage(100,"convert completed;");
    if(fileinfo.exists() && fileinfo.size() > 44)
    {
        SuperC->Replacefile(Outfilename,Convertfolder + Infileinfo.completeBaseName() + "." + fileinfo.suffix());
        QStringList wavfileinfo = SuperM->Wavinfo(fileinfo.absoluteFilePath());
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"samplerate: " + wavfileinfo.at(7) + ",bits: " + wavfileinfo.at(10) + ",channel: " + wavfileinfo.at(6) + ";\nclick ok open path;");
        connect(notedialog,&SuperNoteDialog::Signalnb,this,&FsmpegBox::Openconvertpath);
        notedialog->Messageinit();
    }
    else
    {
        QFile::remove(fileinfo.absoluteFilePath());
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,Error + ";/ntips: make sure no chinese path;");
        notedialog->Messageinit();
    }
}

/*  delete flac decoder;*/

void FsmpegBox::Decodeape()
{
    Apedecoder = new ApeFileDecoder(this,Infilename,Outfilename);
    connect(Apedecoder,&ApeFileDecoder::finished,Apedecoder,&QObject::deleteLater);
    connect(Apedecoder,&ApeFileDecoder::Signalaa,this,      &FsmpegBox::Setprogress);
    connect(Apedecoder,&ApeFileDecoder::finished,this,      &FsmpegBox::Decodeend);
    Progressbar->Show();
    Apedecoder->start();
}

/*  decode flac file;*/

void FsmpegBox::Decodemp3()
{
    Mp3decoder = new Mp3FileDecoder(this,Infilename,Outfilename);
    connect(Mp3decoder,&Mp3FileDecoder::finished,Mp3decoder,&QObject::deleteLater);
    connect(Mp3decoder,&Mp3FileDecoder::Signalma,this,      &FsmpegBox::Setprogress);
    connect(Mp3decoder,&Mp3FileDecoder::finished,this,      &FsmpegBox::Decodeend);
    Progressbar->Show();
    Mp3decoder->start();
}

/*  decode mp3 file;*/

void FsmpegBox::Setprogress(int progress)
{
    Progressbar->Setvaluemessage(progress,"converting...");
}

/*  set progress;*/

void FsmpegBox::Converterror(QString error)
{
    Error = error;
}

/*  change error info;*/

void FsmpegBox::Openconvertpath()
{
    SuperC->Openpath(Convertfolder);
}

/*  open convert path;*/
