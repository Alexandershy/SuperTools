#include "_chatuser_.h"

ChatUser::ChatUser(QWidget *parent,QString role,QString username) : QLabel(parent)
{
    Role = role;
    Username = username;
    init();
}

ChatUser::~ChatUser()
{

}

void ChatUser::init()
{
    policyInit();
    setUserIcon();
}

void ChatUser::policyInit()
{
    setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy);
    setMinimumWidth(50);
    setMinimumHeight(50);
}

void ChatUser::setUserIcon()
{
    QString filename = "./__depycache__/__chat__/__" + Username + "__/_user_.png";
    if(!QFile::exists(filename))
    {
        if(Role == "self")
        {
            filename = ":/__supericon__/_superwizard_.png";
        }
        else
        {
            filename = ":/__supericon__/_supergirl_.png";
        }
    }
    QPixmap pixmap(filename);
    pixmap.scaled(size(), Qt::KeepAspectRatio);
    setScaledContents(true);
    setPixmap(pixmap);
}

/*  set default user icon by user kind;*/
