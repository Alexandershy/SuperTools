#ifndef _SUPERLOGGER__H
#define _SUPERLOGGER__H
#define _SUPERLOGGER__EXPORT Q_DECL_EXPORT

#include "__supercore__/_supercore_.h"
#include "_supertextbrowser_.h"
#include "_superlineedit_.h"
#include <QTextCodec>

class _SUPERLOGGER__EXPORT SuperLogger : public QWidget
{
    Q_OBJECT

public:

    SuperTextBrowser *Textbrowser   = nullptr;
    SuperLineEdit *Lineedit         = nullptr;
    QByteArray Result               = "";

public:

    SuperLogger(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~SuperLogger();

public slots:

    void Displaylog(
        QString direction,
        QString strllog,
        QString strtlog);

    void Cleartextbrowser();

    void Addtransfercodec();

private:

    SuperCore *Core     = nullptr;
    QLayout *Layout     = nullptr;
    QWidget *Widget     = nullptr;
    QString Filepath    = "./__depycache__/__cache__/__textbrowser__/";

private slots:

    void Init();

    void Objectinit();

    void Addinit();

    QString Displaylogdirection(
        QString direction);

    void Transfercodecs();

    void Openfilepath();

};

#endif // _SUPERLOGGER__H
