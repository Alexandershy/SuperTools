#ifndef _DATADIALOG__H
#define _DATADIALOG__H

#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superwindow__/_superwindow_.h"
#include "__itemdialog__/_itemdialog_.h"
#include "__infodialog__/_infodialog_.h"
#include "__superplot__/_superplot_.h"
#include "_databox_.h"

class DisplayTable;
class SaveCell;
class RefreshItems;

class DataDialog : public SuperWindow
{
    Q_OBJECT

public:

    DataDialog(
            QWidget *parent = nullptr,
            QString csvfile = "");

    ~DataDialog();

private:

    DataBox *Plugin                                 = nullptr;
    SuperProgressBarDialog *Progressbardialog       = nullptr;
    ItemDialog *Itemstreedialog                     = nullptr;
    InfoDialog *Infoscombodialog                    = nullptr;
    QString Csvfile                                 = "";
    int Columns                                     = 0;
    int Rows                                        = 0;
    QVector<QStringList> Csvqvectorstringlist       = {};
    SuperPlot *Canvas                               = nullptr;
    QCPBars *Histogram                              = nullptr;
    QColor Backgroundcolor                          = Qt::red;
    QColor Fontcolor                                = Qt::black;
    QColor Concolor                                 = Qt::red;
    QVector<QColor> Colorvector                     = {Qt::red,Qt::green,Qt::blue,Qt::black};
    QString Strrgbbackgroundcolor                   = "";
    QString Strrgbfontcolor                         = "";
    QString Strrgbconcolor                          = "";
    int Currentmode                                 = 0;
    QVector<QStringList> Chartmode                  = {{"line","scatter","histogram"},{"range","appraiser","part","Interaction"}};
    QVector<QStringList> Charticon                  = {{":/__supericon__/_linechart_.svg",":/__supericon__/_scatterchart_.svg",":/__supericon__/_histogramchart_.svg"},{":/__supericon__/_rangechart_.svg",":/__supericon__/_appraiserchart_.svg",":/__supericon__/_partchart_.svg",":/__supericon__/_interactionchart_.svg"}};
    QString Itemtitle                               = "";
    QStringList Dataitems                           = {};
    QVector<QStringList> Datalistvector             = {};
    QStringList Datalistcount                       = {};
    int Itemindex                                   = 0;
    int Groupcounts                                 = 0;
    double Groupdistance                            = 0;
    double Xminvalue                                = 0;
    double Xmaxvalue                                = 0;
    double Xmeanvalue                               = 0;
    double Xstddev                                  = 0;
    double Tolerance                                = 0;
    double Xcentervalue                             = 0;
    double Ymaxvalue                                = 0;
    double Yminvalue                                = 0;
    double Capabilityofaccuracy                     = 0;
    double Capabilityofprecision                    = 0;
    double Processcapabilityindex                   = 0;
    QVector<double> Alldata                         = {};
    QVector<double> Xdata                           = {};
    QVector<double> Ydata                           = {};
    QStringList Dutlist                             = {};
    QStringList Testerlist                          = {};
    QStringList Appraiserlist                       = {};
    QVector<double> Appraisertesttime               = {};
    QVector<bool> Grrcheckbool                      = {false,false,false,false};
    QVector<QVector<int>> Dutidentificationvector   = {};
    QVector<QVector<double>> Dutappraiservector     = {};
    QVector<QVector<double>> Rangechartvector       = {};
    QVector<QVector<double>> Appraiserchartvector   = {};
    QVector<QVector<double>> Partchartvector        = {};
    QVector<QVector<double>> Interactionvector      = {};
    int Dutcounts                                   = 0;
    int Itemrow                                     = 0;
    int Upperlimitrow                               = 1;
    int Lowerlimitrow                               = 2;
    int Datarow                                     = 3;
    int Dutcolumn                                   = 0;
    int Testercolumn                                = 1;
    int Appraisercolumn                             = 2;
    double Dutaveragedifference                     = 0;
    double Average                                  = 0;
    double Extremedifference                        = 0;
    double Averagedifference                        = 0;
    double Uclr                                     = 0;
    QVector<double> D4                              = {0,0,3.27,2.58};
    QVector<double> K1                              = {0,0,0.8862,0.5908};
    QVector<double> K2                              = {0,0,0.7071,0.5231};
    QVector<double> K3                              = {0,0,0.7071,0.5231,0.4467,0.4030,0.3742,0.3534,0.3375,0.3249,0.3146};
    double Ev                                       = 0;
    double Av                                       = 0;
    double Grr                                      = 0;
    double Pv                                       = 0;
    double Tv                                       = 0;
    double Percentev                                = 0;
    double Percentav                                = 0;
    double Percentgrr                               = 0;
    double Percentpv                                = 0;
    double Ndc                                      = 0;
    double Upperlimit                               = 0;
    double Lowerlimit                               = 0;
    bool Upperlimitbool                             = false;
    bool Lowerlimitbool                             = false;
    DisplayTable *Threadda                          = nullptr;
    SaveCell *Threadsa                              = nullptr;
    RefreshItems *Threadra                          = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Colorinit();

    void Iconinit();

    void Threadinit();

    void Plotinit();

    void Seteditable();

    void Apply();

    void Setplotinfo();

    void Setplotitemindex(
            int itemindex);

    void Setplotupperindex(
            int upperindex);

    void Setplotlowerindex(
            int lowerindex);

    void Setplotdataindex(
            int dataindex);

    void Setplotdutindex(
            int dutindex);

    void Setplottesterindex(
            int testerindex);

    void Setplotappraiserindex(
            int appraiserindex);

    void Items();

    void Refresh();

    void Selectmode();

    void Dragmode();

    void Resetplot();

    void Displayselecteddata();

    void Changecpkmode();

    void Changechartmode();

    void Cpkdisplayitemplot(
            int index);

    void Grrdisplayitemplot(
            int index);

    void Appendalldata(
            int itemindex);

    void Appendxydata();

    void Cpkfigureplot();

    void Grrfigureplot();

    void Cpkfigureplotinit();

    void Cleargraphs();

    void Grrfigureplotinit();

    void Cpkfigureplotchart();

    void Grrfigureplotchart();

    void Linechart();

    void Histogramchart();

    void Scatterchart();

    void Figureplotcpkmode();

    void Figureplotrescaleaxes(
            double xmax,
            double xmin,
            double ymax,
            double ymin);

    void Additemtitle();

    void Adddatatexta();

    void Displaydatainfoapia(
            QString strinfo,
            double posx,
            double posy,
            QColor color = Qt::black);

    void Displaydatainfoapib(
            QString strinfo,
            double posx,
            double posy,
            QColor color = Qt::black,
            double rotationdegress = 0,
            double fontsize = 6);

    void Displaydatainfo();

    void Displaydatainfou();

    void Displaydatainfol();

    void Grrcheck();

    void Grrplot();

    void Grrcheckinit();

    void Grrcheckdutnumber();

    void Grrcheckdutidentification();

    void Grrchecktester();

    void Grrcheckappraiser();

    void Grrcheckitemvalue();

    void Grrcalresultinit();

    void Grrcalresult();

    void Grrplotinit();

    void Rangeplot();

    void Appraiserplot();

    void Partplot();

    void Interactionplot();

    void Signaldaslot();

    void Signaldbslot(
            int rows,
            int columns);

    void Signaldcslot(
            int valuea,
            int cellcount,
            QStringList stringlist);

    void Setprogressbar(
            int progressbarvalue,
            QString message);

    void Signalsaslot();

    void Signalraslot();

};

class DisplayTable : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    DisplayTable(
            QString strfilepath,
            QVector<QStringList>* csvqvectorstringlist);

    ~DisplayTable();

public slots:

    void run();

    void Init();

    void Objectinit();

private:

    SuperCore *SuperC                           = nullptr;
    QString Strfilepath                         = {};
    QVector<QStringList>* Csvqvectorstringlist  = {};
    int Columns                                 = 0;
    int Rows                                    = 0;

private slots:

    void Getcsvfileinfo();

    void Settablewidgetitem();

signals:

    void Signalda();

    void Signaldb(
            int valuea,
            int valueb);

    void Signaldc(
            int valuea,
            int cellcount,
            QStringList stringlist);

    void Signaldd(
            int progressbarvalue,
            QString message);

};

class SaveCell : public QThread
{
    Q_OBJECT

public:

    /*main function;*/

    SaveCell(
            QString csvfilepath,
            QTableWidget* tablewidget);

public slots:

    void run();

private:

    SuperCore *SuperC           = nullptr;
    QString Strcell             = "";
    QString Csvfilepath         = "";
    QTableWidget* Tablewidget   = nullptr;
    int Rows                    = 0;
    int Columns                 = 0;

private slots:

    void Init();

    void Objectinit();

    void Getcellinfo();

signals:

    void Signalsa();

    void Signalsb(
            int progressbarvalue,
            QString message);

};

class RefreshItems : public QThread
{
    Q_OBJECT

public:
    /*main function;*/
    RefreshItems(
            int* row,
            int* columns,
            QTableWidget *tablewidget,
            QStringList *dataitems,
            QVector<QStringList> *datalistvector,
            QStringList *datalistcount);

    ~RefreshItems();

public slots:

    void run();

private:

    SuperCore *SuperC                       = nullptr;
    int* Rows                               = nullptr;
    int* Columns                            = nullptr;
    QTableWidget *Tablewidget               = nullptr;
    QStringList *Dataitems                  = nullptr;
    QVector<QStringList>* Datalistvector    = {};
    QStringList* Datalistcount              = nullptr;
    QStringList Tdataitems                  = {};
    QVector<QStringList> Tdatalistvector    = {};

private slots:

    void Init();

    void Objectinit();

    void Initrun();

    void Finddataitem();

    void Getdatabyitema();

    void Getdatabyitemb(
            QString strcell,
            int itemindex);

    void Analysisitems();

signals:

    void Signalra();

    void Signalrb(
            int progressbarvalue,
            QString message);

};

#endif // _DATADIALOG__H
