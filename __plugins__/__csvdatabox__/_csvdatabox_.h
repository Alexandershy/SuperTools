#ifndef _CSVDATABOX__H
#define _CSVDATABOX__H
#define _CSVDATABOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__datadialog__/_csvdatadialog_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__superfilemanager__/_superfilemanager_.h"
#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "__module__/_csvdatamodulea_.h"
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

    CsvDataModuleA *Modulea                     = nullptr;
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
    void init();

    void objectInit();

    void parameterInit();

    void threadInit();

    void enableProcessButton();

    void open();

    void checkCurrentFunction();

    void process();

    void signalpbSlot();

    void setProgressBar(
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

    void init();

    void objectInit();

private slots:

    void mergeCsvFileData();

    void removeDuplicateItem(
            QStringList *csvfilelist);

    void openPath();

private:

    SuperCore *Core                 = nullptr;
    QCheckBox *Checkboxa            = nullptr;
    QCheckBox *Checkboxb            = nullptr;
    QCheckBox *Checkboxc            = nullptr;
    QStringList *Csvfilelist        = nullptr;
    QStringList *Waitforremoved     = nullptr;
    QString *Processtime            = nullptr;

signals:

    void signalPa(
            QString direction,
            QString strtlog,
            QString strllog);

    void signalPb();

    void signalPc(
            int progressbarvalue,
            QString message);

};

#endif // _CSVDATABOX__H
