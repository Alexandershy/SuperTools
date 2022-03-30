#ifndef _DEMOBOX__H
#define _DEMOBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superlogger__/_superlogger_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__superwindow__/_superwindow_.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include "_demobox__global.h"

/**************interface****************/
class _DEMOBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class demobox new instance pointer;*/
};

class DemoBox : public SuperTab
{
    Q_OBJECT

public:

    DemoBox(
            QWidget *parent = nullptr);

    ~DemoBox();

private:

    ModuleA *Modulea                = nullptr;
    ModuleB *Moduleb                = nullptr;
    SuperLogger *Logger             = nullptr;
    SuperFileManager *Filemanager   = nullptr;
    QStringList *Demofilelist       = nullptr;
    QString Democachefile           = "./__depycache__/__demo__/_splitdata_.csv";

private slots:

    /*  main function*/

    void Init();

    void Objectinit();

    void Parameterinit();

    void Selectsnfile();

    void Displaysnfile(
        QString text);

    void Process();

    void Processcsvfile(
        QString serialnumber);

};

#endif // _DEMOBOX__H
