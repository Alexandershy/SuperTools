#ifndef _RICHERBOX__H
#define _RICHERBOX__H
#define _RICHERBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__datadialog__/_richerdatadialog_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"

/**************interface****************/
class _RICHERBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();
};

class RicherBox : public SuperTab
{
    Q_OBJECT

public:

    RicherBox(
            QWidget *parent = nullptr);

    ~RicherBox();

private:

    SuperLogger *Logger             = nullptr;
    QStringList *Richerfilelist     = nullptr;
    SuperFileManager *Filemanager   = nullptr;
    QString Sourcepath              = "./";

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void open();

};

#endif // _RICHERBOX__H
