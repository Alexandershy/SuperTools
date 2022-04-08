#ifndef _CSVDATABOX__H
#define _CSVDATABOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__datadialog__/_datadialog_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "__module__/_modulea_.h"
#include "_csvdatabox__global.h"
#include <QThread>

/**************interface****************/
class _CSVDATABOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class csvdatabox new instance pointer;*/
};

class ProcessData;

class CsvDataBox : public SuperTab
{
    Q_OBJECT

public:

    CsvDataBox(
            QWidget *parent = nullptr);

    ~CsvDataBox();

private:

    ModuleA *Modulea                            = nullptr;
    SuperProgressBarDialog *Progressbardialog   = nullptr;
    QStringList *Csvfilelist                    = nullptr;
    QString Processtime                         = "";
    QStringList Waitforremoved                  = {};
    ProcessData* Threadpa                       = nullptr;
    SuperLogger *Logger                         = nullptr;
    SuperFileManager *Filemanager               = nullptr;
    QString Sourcepath                          = "./";

private slots:

    /*  main function*/

    void Init();

    void Objectinit();

    void Parameterinit();

    void Threadinit();

    void Enableprocessbutton();

    void Open();

    void Checkcurrentfunction();

    void Process();

    void Signalpbslot();

    void Setprogressbar(
            int progressbarvalue,
            QString message);
};

class ProcessData : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    ProcessData(
            QCheckBox* checkboxa,
            QCheckBox* checkboxb,
            QCheckBox* checkboxc,
            QStringList *csvfilelist,
            QStringList* waitforremoved,
            QString* processtime);

public slots:

    void run();

    void Init();

    void Objectinit();

private slots:

    void Mergecsvfiledata();

    void Removeduplicateitem(
            QStringList *csvfilelist);

    void Openpath();

private:

    SuperCore *SuperC               = nullptr;
    QCheckBox *Checkboxa            = nullptr;
    QCheckBox *Checkboxb            = nullptr;
    QCheckBox *Checkboxc            = nullptr;
    QStringList *Csvfilelist        = nullptr;
    QStringList *Waitforremoved     = nullptr;
    QString *Processtime            = nullptr;

signals:

    void Signalpa(
            QString direction,
            QString strtlog,
            QString strllog);

    void Signalpb();

    void Signalpc(
            int progressbarvalue,
            QString message);

};

#endif // _CSVDATABOX__H
