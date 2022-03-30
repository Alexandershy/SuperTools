#ifndef _RICHERBOX__H
#define _RICHERBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__datadialog__/_datadialog_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "_richerbox__global.h"

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

    void Init();

    void Objectinit();

    void Parameterinit();

    void Open();

};

#endif // _RICHERBOX__H
