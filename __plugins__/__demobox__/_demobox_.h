#ifndef _DEMOBOX__H
#define _DEMOBOX__H
#define _DEMOBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superlogger__/_superlogger_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__superwindow__/_superwindow_.h"
#include "__module__/_demomodulea_.h"
#include "__module__/_demomoduleb_.h"

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

    DemoModuleA *Modulea            = nullptr;
    DemoModuleB *Moduleb            = nullptr;
    SuperLogger *Logger             = nullptr;
    SuperFileManager *Filemanager   = nullptr;
    QStringList *Demofilelist       = nullptr;
    QString Democachefile           = "./__depycache__/__demo__/_splitdata_.csv";

private slots:

    /*  main function*/
    void init();

    void objectInit();

    void parameterInit();

    void selectSnFile();

    void displaySnFile(
        QString text);

    void process();

    void processCsvFile(
        QString serialnumber);

};

#endif // _DEMOBOX__H
