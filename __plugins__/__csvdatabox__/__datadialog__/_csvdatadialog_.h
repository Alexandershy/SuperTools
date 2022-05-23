#ifndef _CSVDATADIALOG__H
#define _CSVDATADIALOG__H

#include "__superprogressbardialog__/_superprogressbardialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superwindow__/_superwindow_.h"
#include "__itemdialog__/_csvdataitemdialog_.h"
#include "__infodialog__/_csvdatainfodialog_.h"
#include "__superchartview__/_superchartview_.h"
#include "_csvdatadialogui_.h"

class DisplayTable;
class SaveCell;
class RefreshItems;

class CsvDataDialog : public SuperWindow
{
    Q_OBJECT

public:

    CsvDataDialog(
            QWidget *parent = nullptr,
            QString csvfile = "");

    ~CsvDataDialog();

private:

    CsvDataDialogui *Plugin                         = nullptr;
    SuperProgressBarDialog *Progressbardialog       = nullptr;
    CsvDataItemDialog *Itemstreedialog              = nullptr;
    CsvDataInfoDialog *Infoscombodialog             = nullptr;
    QString Csvfile                                 = "";
    int Columns                                     = 0;
    int Rows                                        = 0;
    QVector<QStringList> Csvqvectorstringlist       = {};
    SuperChartView *Chartview                       = nullptr;
//    QCPBars *Histogram                              = nullptr;
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

    void init();

    void objectInit();

    void colorInit();

    void iconInit();

    void threadInit();

    void plotInit();

    void setEditable();

    void apply();

    void setPlotInfo();

    void setPlotItemIndex(
            int itemindex);

    void setPlotUpperIndex(
            int upperindex);

    void setPlotLowerIndex(
            int lowerindex);

    void setPlotDataIndex(
            int dataindex);

    void setPlotDutIndex(
            int dutindex);

    void setPlotTesterIndex(
            int testerindex);

    void setPlotAppraiserIndex(
            int appraiserindex);

    void items();

    void refresh();

    void selectMode();

    void dragMode();

    void resetPlot();

    void displaySelectedData();

    void changeCpkMode();

    void changeChartMode();

    void cpkDisplayItemPlot(
            int index);

    void grrDisplayItemPlot(
            int index);

    void appendAllData(
            int itemindex);

    void appendXyData();

    void cpkFigurePlot();

    void grrFigurePlot();

    void cpkFigurePlotInit();

    void clearGraphs();

    void grrFigurePlotInit();

    void cpkFigurePlotChart();

    void grrFigurePlotChart();

    void lineChart();

    void histogramChart();

    void scatterChart();

    void figurePlotCpkMode();

    void figurePlotRescaleaxes(
            double xmax,
            double xmin,
            double ymax,
            double ymin);

    void addItemTitle();

    void addDataTexta();

    void displayDataInfoApia(
            QString strinfo,
            double posx,
            double posy,
            QColor color = Qt::black);

    void displayDataInfoApib(
            QString strinfo,
            double posx,
            double posy,
            QColor color = Qt::black,
            double rotationdegress = 0,
            double fontsize = 6);

    void displayDataInfo();

    void displayDataInfou();

    void displayDataInfol();

    void grrCheck();

    void grrPlot();

    void grrCheckInit();

    void grrCheckDutNumber();

    void grrCheckDutIdentification();

    void grrCheckTester();

    void grrCheckAppraiser();

    void grrCheckItemValue();

    void grrCalResultInit();

    void grrCalResult();

    void grrPlotInit();

    void rangePlot();

    void appraiserPlot();

    void partPlot();

    void interactionPlot();

    void signalDaSlot();

    void signalDbSlot(
            int rows,
            int columns);

    void signalDcSlot(
            int valuea,
            int cellcount,
            QStringList stringlist);

    void setProgressBar(
            int progressbarvalue,
            QString message);

    void signalSaSlot();

    void signalRaSlot();

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

    void init();

    void objectInit();

private:

    SuperCore *Core                             = nullptr;
    QString Strfilepath                         = {};
    QVector<QStringList>* Csvqvectorstringlist  = {};
    int Columns                                 = 0;
    int Rows                                    = 0;

private slots:

    void getCsvFileInfo();

    void setTableWidgetItem();

signals:

    void signalDa();

    void signalDb(
            int valuea,
            int valueb);

    void signalDc(
            int valuea,
            int cellcount,
            QStringList stringlist);

    void signalDd(
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

    SuperCore *Core             = nullptr;
    QString Strcell             = "";
    QString Csvfilepath         = "";
    QTableWidget* Tablewidget   = nullptr;
    int Rows                    = 0;
    int Columns                 = 0;

private slots:

    void init();

    void objectInit();

    void getCellInfo();

signals:

    void signalSa();

    void signalSb(
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

    SuperCore *Core                         = nullptr;
    int* Rows                               = nullptr;
    int* Columns                            = nullptr;
    QTableWidget *Tablewidget               = nullptr;
    QStringList *Dataitems                  = nullptr;
    QVector<QStringList>* Datalistvector    = {};
    QStringList* Datalistcount              = nullptr;
    QStringList Tdataitems                  = {};
    QVector<QStringList> Tdatalistvector    = {};

private slots:

    void init();

    void objectInit();

    void initRun();

    void findDataItem();

    void getDataByItema();

    void getDataByItemb(
            QString strcell,
            int itemindex);

    void analysisItems();

signals:

    void signalRa();

    void signalRb(
            int progressbarvalue,
            QString message);

};

#endif // _CSVDATADIALOG__H
