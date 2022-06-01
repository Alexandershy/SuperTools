#include "_chatinfodialog_.h"
#include "ui__chatinfodialogui_.h"

ChatInfoDialog::ChatInfoDialog(QWidget *parent,QLineEdit *lineedit)
    : SuperWindow(parent)
{
    Lineedit = lineedit;
    setWindowModality(Qt::ApplicationModal);
    disableMaxisize();
    setTitle("Profile");
    init();
}

ChatInfoDialog::~ChatInfoDialog()
{

}

void ChatInfoDialog::init()
{
    objectInit();
    profileInit();
}

void ChatInfoDialog::objectInit()
{
    Plugin = new ChatInfoDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton,&QPushButton::clicked,this,&ChatInfoDialog::selectProfile);
}

/*  creat object and connect slot;*/

void ChatInfoDialog::profileInit()
{
    Userfolder = "./__depycache__/__chat__/__" + Lineedit->text() + "__/";
    Userpicture = Userfolder + "_user_.png";
    if(!QFile::exists(Userpicture))
    {
        Core->creatFolder(Userfolder);
        QFile::copy(":/__supericon__/_superwizard_.png",Userpicture);
    }
    QPixmap pixmap(Userpicture);
    pixmap.scaled(size(), Qt::KeepAspectRatio);
    Plugin->ui->label->setScaledContents(true);
    Plugin->ui->label->setPixmap(pixmap);
}

/*  set label pixmap user _user_.png;*/

void ChatInfoDialog::selectProfile()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__readme__/__module__/",{"*.png"});
    connect(filedialog,&SuperFileDialog::signalFb,this,         &ChatInfoDialog::changeProfile);
    connect(filedialog,&SuperFileDialog::signalFb,filedialog,   &QObject::deleteLater);
    filedialog->setSingleFile();
    filedialog->show();
}

/*  select profile files;*/

void ChatInfoDialog::changeProfile(QString file)
{
    if(!file.isEmpty())
    {
        QFile::setPermissions(Userpicture,QFile::ReadOther | QFile::WriteOther);
        QFile::remove(Userpicture);
        QFile::copy(file,Userpicture);
        profileInit();
    }
}

/*  change _user_.png and replace pixmap;*/
