#include "_chatinfodialog_.h"

ChatInfoDialog::ChatInfoDialog(QWidget *parent,QLineEdit *lineedit)
    : SuperWindow(parent)
{
    Lineedit = lineedit;
    setWindowModality(Qt::ApplicationModal);
    Disablemaxisize();
    Settitle("Profile");
    Init();
}

ChatInfoDialog::~ChatInfoDialog()
{

}

void ChatInfoDialog::Init()
{
    Objectinit();
    Profileinit();
}

void ChatInfoDialog::Objectinit()
{
    Plugin = new ChatInfoBox(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton,&QPushButton::clicked,this,&ChatInfoDialog::Selectprofile);
}

/*  creat object and connect slot;*/

void ChatInfoDialog::Profileinit()
{
    Userfolder = "./__depycache__/__chat__/__" + Lineedit->text() + "__/";
    Userpicture = Userfolder + "_user_.png";
    if(!QFile::exists(Userpicture))
    {
        SuperC->Creatfolder(Userfolder);
        QFile::copy(":/__supericon__/_superwizard_.png",Userpicture);
    }
    QPixmap pixmap(Userpicture);
    pixmap.scaled(size(), Qt::KeepAspectRatio);
    Plugin->ui->label->setScaledContents(true);
    Plugin->ui->label->setPixmap(pixmap);
}

/*  set label pixmap user _user_.png;*/

void ChatInfoDialog::Selectprofile()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__readme__/__module__/",{"*.png"});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &ChatInfoDialog::Changeprofile);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsinglefile();
    filedialog->Show();
}

/*  select profile files;*/

void ChatInfoDialog::Changeprofile(QString file)
{
    if(!file.isEmpty())
    {
        QFile::setPermissions(Userpicture,QFile::ReadOther | QFile::WriteOther);
        QFile::remove(Userpicture);
        QFile::copy(file,Userpicture);
        Profileinit();
    }
}

/*  change _user_.png and replace pixmap;*/
