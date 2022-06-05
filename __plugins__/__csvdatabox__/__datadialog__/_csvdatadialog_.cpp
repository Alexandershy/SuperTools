#include "_csvdatadialog_.h"
#include "ui__csvdatadialogui_.h"

CsvDataDialog::CsvDataDialog(QWidget *parent,QString csvfile)
    : SuperWindow(parent)
{
    Csvfile = csvfile;
    init();
    setAttribute(Qt::WA_DeleteOnClose);
    setTitle(csvfile);
}

CsvDataDialog::~CsvDataDialog()
{
    Core->closeThread(Threadda);
    Core->closeThread(Threadra);
    Core->closeThread(Threadsa);
    delete Itemstreedialog;
    delete Progressbardialog;
}

void CsvDataDialog::init()
{
    objectInit();
    colorInit();
    threadInit();
    iconInit();
    plotInit();
}

void CsvDataDialog::objectInit()
{
    Plugin = new CsvDataDialogui(this);
    setWidget(Plugin);
    Progressbardialog   = new SuperProgressBarDialog();
    Itemstreedialog     = new CsvDataItemDialog(nullptr,&Dataitems,&Datalistcount);
    Chartview           = new SuperChartView(this);
//    Histogram           = new QCPBars(Canvas->xAxis,Canvas->yAxis);//todo;
    Infoscombodialog    = new CsvDataInfoDialog(nullptr);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,          this,&CsvDataDialog::dragMode);
    connect(Plugin->ui->pushButton_4,   &QPushButton::clicked,          this,&CsvDataDialog::selectMode);
    connect(Plugin->ui->pushButton_5,   &QPushButton::clicked,          this,&CsvDataDialog::resetPlot);
    connect(Plugin->ui->pushButton_6,   &QPushButton::clicked,          this,&CsvDataDialog::displaySelectedData);
    connect(Plugin->ui->pushButton_7,   &QPushButton::clicked,          this,&CsvDataDialog::changeCpkMode);
    connect(Plugin->ui->pushButton_8,   &QPushButton::clicked,          this,&CsvDataDialog::changeChartMode);
    connect(Plugin->ui->pushButton_9,   &QPushButton::clicked,          this,&CsvDataDialog::setPlotInfo);
    connect(Plugin->ui->pushButton_10,  &QPushButton::clicked,          this,&CsvDataDialog::refresh);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,          this,&CsvDataDialog::items);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,          this,&CsvDataDialog::setEditable);
    connect(Itemstreedialog,            &CsvDataItemDialog::signalIa,   this,&CsvDataDialog::cpkDisplayItemPlot);
    connect(Itemstreedialog,            &CsvDataItemDialog::signalIb,   this,&CsvDataDialog::grrDisplayItemPlot);
    connect(Infoscombodialog,           &CsvDataInfoDialog::signalIa,   this,&CsvDataDialog::setPlotItemIndex);
    connect(Infoscombodialog,           &CsvDataInfoDialog::signalIb,   this,&CsvDataDialog::setPlotUpperIndex);
    connect(Infoscombodialog,           &CsvDataInfoDialog::signalIc,   this,&CsvDataDialog::setPlotLowerIndex);
    connect(Infoscombodialog,           &CsvDataInfoDialog::signalId,   this,&CsvDataDialog::setPlotDataIndex);
    connect(Infoscombodialog,           &CsvDataInfoDialog::signalIe,   this,&CsvDataDialog::setPlotDutIndex);
    connect(Infoscombodialog,           &CsvDataInfoDialog::signalIf,   this,&CsvDataDialog::setPlotTesterIndex);
    connect(Infoscombodialog,           &CsvDataInfoDialog::signalIg,   this,&CsvDataDialog::setPlotAppraiserIndex);
}

void CsvDataDialog::colorInit()
{
    Core->colorInit(&Backgroundcolor,&Fontcolor,&Concolor,&Strrgbbackgroundcolor,&Strrgbfontcolor,&Strrgbconcolor);
}

/*  init color;*/

void CsvDataDialog::plotInit()
{
    Groupcounts = 100;
//    C->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
//    Canvas->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);
//    Canvas->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables| QCP::iMultiSelect);
//    Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Plugin->ui->verticalLayout_5->addWidget(Chartview);
    selectMode();
}

/*  init plot;*/

void CsvDataDialog::iconInit()
{
    Plugin->ui->pushButton_4->setIcon(QIcon(":/__supericon__/_select_.svg"));
    Plugin->ui->pushButton_3->setIcon(QIcon(":/__supericon__/_drag_.svg"));
    Plugin->ui->pushButton_5->setIcon(QIcon(":/__supericon__/_reset_.svg"));
    Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_menu_.svg"));
    Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_doublelimitcpk_.svg"));
    Plugin->ui->pushButton_8->setIcon(QIcon(":/__supericon__/_histogramchart_.svg"));
    Plugin->ui->pushButton_9->setIcon(QIcon(":/__supericon__/_setting_.svg"));
}

/*  init icon;*/

void CsvDataDialog::threadInit()
{
    Threadsa = new SaveCell(Csvfile,Plugin->ui->tableWidget);
    Threadra = new RefreshItems(&Rows,&Columns,Plugin->ui->tableWidget,&Dataitems,&Datalistvector,&Datalistcount);
    Threadda = new DisplayTable(Csvfile,&Csvqvectorstringlist);
    connect(Threadsa,&SaveCell::signalSa,    this,      &CsvDataDialog::signalSaSlot);
    connect(Threadsa,&SaveCell::signalSb,    this,      &CsvDataDialog::setProgressBar);
    connect(Threadra,&RefreshItems::signalRa,this,      &CsvDataDialog::signalRaSlot);
    connect(Threadda,&DisplayTable::signalDa,this,      &CsvDataDialog::signalDaSlot);
    connect(Threadda,&DisplayTable::signalDb,this,      &CsvDataDialog::signalDbSlot);
    connect(Threadda,&DisplayTable::signalDc,this,      &CsvDataDialog::signalDcSlot);
    connect(Threadda,&DisplayTable::signalDd,this,      &CsvDataDialog::setProgressBar);
    Threadda->start();
    Progressbardialog->show();
}

/*  start init thread;*/

void CsvDataDialog::setEditable()
{
    if(Plugin->ui->pushButton_2->text() == "Apply")
    {
        Plugin->ui->pushButton_2->setEnabled(false);
        Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        apply();
    }
    else
    {
        Plugin->ui->pushButton_2->setText("Apply");
        Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
}

/*  enable edit or save cell to csvfile;*/

void CsvDataDialog::apply()
{
    Threadsa->start();
    Progressbardialog->show();
}

/*  start a new thread to save cell to csvfile;*/

void CsvDataDialog::dragMode()
{
    Plugin->ui->pushButton_3->setEnabled(false);
    Plugin->ui->pushButton_4->setEnabled(true);
    Chartview->setDragMode();
//    Canvas->setInteraction(QCP::iRangeDrag,true);
//    Canvas->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
}

/*  set canvas as drag mode;*/

void CsvDataDialog::selectMode()
{
    Plugin->ui->pushButton_3->setEnabled(true);
    Plugin->ui->pushButton_4->setEnabled(false);
    Chartview->setSelectMode();
//    Canvas->setInteraction(QCP::iNone,true);
//    Canvas->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
}

/*  set canvas as select mode;*/

void CsvDataDialog::resetPlot()
{
    if(Currentmode == 0)
    {
        cpkFigurePlot();
    }
    else
    {
        grrFigurePlot();
    }
}

/*  reset plot;*/

void CsvDataDialog::displaySelectedData()
{
    QList<QTableWidgetItem*> tablewidgetitems = Plugin->ui->tableWidget->selectedItems();
    bool boola = false;
    QString datatemp = "";
    QVector<double> alldatatemp = {};
    int count = tablewidgetitems.count();
    for(int i = 0; i < count; i++)
    {
        datatemp = tablewidgetitems.at(i)->text();
        datatemp.toDouble(&boola);
        if(boola == true)
        {
            alldatatemp.append(tablewidgetitems.at(i)->text().toDouble());
        }
    }
    if(alldatatemp.count() > 0)
    {
        Alldata = alldatatemp;
        Itemtitle = "table widget selected data";
        appendXyData();
        resetPlot();
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"valid cell on data tab;\nreselect data again;");
        notedialog->messageInit();
    }
}

/*  display select data at table widget;*/

void CsvDataDialog::changeCpkMode()
{
    if(Plugin->ui->cpkmode->text() == "double limit")
    {
        Plugin->ui->cpkmode->setText("upper limit");
        Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_upperlimitcpk_.svg"));
    }
    else if(Plugin->ui->cpkmode->text() == "upper limit")
    {
        Plugin->ui->cpkmode->setText("lower limit");
        Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_lowerlimitcpk_.svg"));
    }
    else
    {
        Plugin->ui->cpkmode->setText("double limit");
        Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_doublelimitcpk_.svg"));
    }
    cpkFigurePlot();
}

/*  change cpk display mode and replot;*/

void CsvDataDialog::changeChartMode()
{
    for(int i = 0;i < Chartmode.at(Currentmode).count();i++)
    {
        if(Plugin->ui->chartmode->text() == Chartmode.at(Currentmode).at(i))
        {
            int nexttemp = (i + 1) % Chartmode.at(Currentmode).count();
            Plugin->ui->chartmode->setText(Chartmode.at(Currentmode).at(nexttemp));
            Plugin->ui->pushButton_8->setIcon(QIcon(Charticon.at(Currentmode).at(nexttemp)));
            break;
        }
    }
    if(Currentmode == 0)
    {
        cpkFigurePlot();
    }
    else
    {
        grrFigurePlot();
    }
}

/*  change chart display mode and replot;*/

void CsvDataDialog::setPlotInfo()
{
    Infoscombodialog->show();
}

/*  set upper lower item line index;*/

void CsvDataDialog::setPlotItemIndex(int itemindex)
{
    Itemrow = itemindex;
}

/*  set item line index;*/

void CsvDataDialog::setPlotUpperIndex(int upperindex)
{
    Upperlimitrow = upperindex;
}

/*  set upper line index;*/

void CsvDataDialog::setPlotLowerIndex(int lowerindex)
{
    Lowerlimitrow = lowerindex;
}

/*  set lower line index;*/

void CsvDataDialog::setPlotDataIndex(int dataindex)
{
    Datarow = dataindex;
}

/*  set data line index;*/

void CsvDataDialog::setPlotDutIndex(int dutindex)
{
    Dutcolumn = dutindex;
}

/*  set data line index;*/

void CsvDataDialog::setPlotTesterIndex(int testerindex)
{
    Testercolumn = testerindex;
}

/*  set data line index;*/

void CsvDataDialog::setPlotAppraiserIndex(int appraiserindex)
{
    Appraisercolumn = appraiserindex;
}

/*  set data line index;*/

void CsvDataDialog::items()
{
    Itemstreedialog->refresh();
    Itemstreedialog->show();
}

/*  display items have double value at table widget;*/

void CsvDataDialog::cpkDisplayItemPlot(int index)
{
    Currentmode = 0;
    Itemindex = index;
    Alldata.clear();
    Itemtitle = Dataitems.at(Itemindex);
    Plugin->ui->label_9->setText("cpk: ");
    Plugin->ui->cpkmode->setText("double limit");
    Plugin->ui->chartmode->setText("histogram");
    Plugin->ui->pushButton_6->setEnabled(true);
    Plugin->ui->pushButton_7->setEnabled(true);
    appendAllData(Itemindex);
    appendXyData();
    cpkFigurePlot();
}

/*  open cpk selected items at items dialog;*/

void CsvDataDialog::grrDisplayItemPlot(int index)
{
    Currentmode = 1;
    Itemindex = index;
    Alldata.clear();
    Itemtitle = Dataitems.at(Itemindex);
    Plugin->ui->label_9->setText("grr: ");
    Plugin->ui->cpkmode->setText("/");
    Plugin->ui->chartmode->setText("range");
    Plugin->ui->pushButton_6->setEnabled(false);
    Plugin->ui->pushButton_7->setEnabled(false);
    appendAllData(Itemindex);
    appendXyData();
    grrFigurePlot();
}

/*  open grr selected items at items dialog;*/

void CsvDataDialog::appendAllData(int itemindex)
{
    bool boola = false;
    double datatemp = 0;
    if(itemindex >= 0)
    {
        for(int i = 0;i < Rows;i++)
        {
            datatemp = Plugin->ui->tableWidget->item(i,itemindex)->text().toDouble(&boola);
            if(boola)
            {
                Alldata.append(datatemp);
            }
        }
    }
}

/*  add all data append on index that at items dialog;*/

void CsvDataDialog::appendXyData()
{
    double datatemp = 0;
    int xdatacount = Alldata.count();
    Xminvalue = Core->getVectorMinValue(&Alldata,xdatacount);
    Xmaxvalue = Core->getVectorMaxValue(&Alldata,xdatacount);
    Tolerance = Xmaxvalue - Xminvalue;
    Xcentervalue = Xminvalue + Tolerance / 2;
    Xdata = Core->linspace(Xminvalue,Xmaxvalue,Groupcounts);
    Xdata.append(Xmaxvalue);
    Ydata = Core->linspace(0,0,Groupcounts + 1);
    Groupdistance = (Xmaxvalue - Xminvalue) / Groupcounts;
    for(int i = 0;i < xdatacount;i++)
    {
        datatemp = Alldata.at(i);
        if(datatemp == Xmaxvalue)
        {
            Ydata[Groupcounts] = Ydata.at(Groupcounts) + 1;
            continue;
        }
        for(int j = 0;j < Groupcounts;j++)
        {
            if(datatemp >= Xminvalue + Groupdistance * j && datatemp < Xminvalue + Groupdistance * (j + 1))
            {
                Ydata[j] = Ydata.at(j) + 1;
            }
        }
    }
    Ymaxvalue = Core->getVectorMaxValue(&Ydata,Groupcounts);
    Upperlimit = Plugin->ui->tableWidget->item(Upperlimitrow,Itemindex)->text().toDouble(&Upperlimitbool);
    Lowerlimit = Plugin->ui->tableWidget->item(Lowerlimitrow,Itemindex)->text().toDouble(&Lowerlimitbool);
}

/*  creat new xdata and ydata for histogram,and define cpk parameters;*/

void CsvDataDialog::cpkFigurePlot()
{
    cpkFigurePlotInit();
    cpkFigurePlotChart();
//    Chartview->re
    Plugin->ui->pushButton_5->setEnabled(true);  
}

/*  plot xdata and ydata and add its text,display cpk append on different parameters;*/

void CsvDataDialog::grrFigurePlot()
{
    grrFigurePlotInit();
    grrFigurePlotChart();
//    Canvas->replot(QCustomPlot::rpQueuedReplot);
    Plugin->ui->pushButton_5->setEnabled(true);
}

/*  plot xdata and ydata and add its text,display grr append on different parameters;*/

void CsvDataDialog::cpkFigurePlotInit()
{
    Chartview->clearItems();
    Chartview->setLine(1);
    Chartview->setSelectMode();

//    Histogram->setData(QVector<double> {0},QVector<double> {0});
    addItemTitle();
}

/*  cpk canvas init;*/

void CsvDataDialog::grrFigurePlotInit()
{
    clearGraphs();
//    Histogram->setData(QVector<double> {0},QVector<double> {0});
    addItemTitle();
}

/*  grr canvas init;*/

void CsvDataDialog::clearGraphs()
{
    Chartview->clearItems();
}

/*  clear graphs and data;*/

void CsvDataDialog::cpkFigurePlotChart()
{
    if(Plugin->ui->chartmode->text() == "line")
    {
        lineChart();
    }
    else if(Plugin->ui->chartmode->text() == "histogram")
    {
        histogramChart();
    }
    else
    {
        scatterChart();
    }
}

/*  display chart type;*/

void CsvDataDialog::lineChart()
{
    Chartview->setLineData(0,&Xdata,&Ydata);
//    Chartview->graph(0)->setData(Xdata,Ydata,true);
//    Canvas->graph(0)->setPen(Backgroundcolor);
//    Canvas->graph(0)->setLineStyle(QCPGraph::LineStyle::lsStepCenter);
//    Canvas->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone));
    figurePlotRescaleaxes(Xmaxvalue,Xminvalue,Ymaxvalue,Yminvalue);
    addDataTexta();
    figurePlotCpkMode();
}

/*  set canvas as line chart;*/

void CsvDataDialog::histogramChart()
{
    Chartview->setBarData(0,&Xdata,&Ydata);
    figurePlotRescaleaxes(Xmaxvalue,Xminvalue,Ymaxvalue,Yminvalue);
    addDataTexta();
    figurePlotCpkMode();
}

/*  set canvas as histogram chart;*/

void CsvDataDialog::scatterChart()
{
    QVector<double> xdata;
    QVector<double> ydata = Alldata;
    int alldatatempcount = ydata.count();
    xdata = Core->arange(0,alldatatempcount,1);
//    Canvas->graph(0)->setLineStyle(QCPGraph::lsNone);
//    Canvas->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,2));
//    Canvas->graph(0)->setPen(Backgroundcolor);
//    Canvas->graph(0)->setData(xdata,ydata,true);
    Chartview->setScatterData(0,&xdata,&ydata);
    displayDataInfoApia("Total counts: " + QString::number(alldatatempcount),0.85,0.15);
    figurePlotRescaleaxes(alldatatempcount,0,Core->getVectorMaxValue(&ydata,ydata.count()),Core->getVectorMinValue(&ydata,ydata.count()));
}

/*  set canvas as scatter chart;*/

void CsvDataDialog::figurePlotCpkMode()
{
    if(Plugin->ui->cpkmode->text() == "double limit")
    {
        displayDataInfo();
    }
    else if(Plugin->ui->cpkmode->text() == "upper limit")
    {
        displayDataInfou();
    }
    else
    {
        displayDataInfol();
    }
}

/*  display data info depend cpk mode;*/

void CsvDataDialog::figurePlotRescaleaxes(double xmax,double xmin,double ymax,double ymin)
{
    if(xmax == xmin || ymax == ymin)
    {
        Chartview->rescaleAxes();
    }
    else
    {
        double xrange = (xmax - xmin) * 0.1;
        double yrange = (ymax - ymin) * 0.1;
        Chartview->Xaxis->setRange(xmin - xrange,xmax + xrange);
        Chartview->Xaxis->setRange(ymin - yrange,ymax + yrange);
    }
}

/*  rescale axes;*/

void CsvDataDialog::addItemTitle()
{
    Chartview->setText(0,0.52,0.01,Itemtitle);
}

/*  add item title to canvas;*/

void CsvDataDialog::addDataTexta()
{
    for(int i = 0;i < Groupcounts + 1;i++)
    {
        double yvalue = Ydata.at(i);
        if(yvalue > 0)
        {
            double xpos = Xminvalue + Groupdistance * i;
            double ypos = Ydata.at(i);
            displayDataInfoApib(QString::number(yvalue),xpos,ypos);
        }
    }
}

/*  add data text to canvas;*/

void CsvDataDialog::displayDataInfoApia(QString strinfo,double posx,double posy,QColor color)
{
//    QFont infofont;
//    infofont.setPointSize(8);
    Chartview->setText(1,posx,posy,strinfo);
//    QCPItemText *itemtext = new QCPItemText(Canvas);
//    itemtext->position->setType(QCPItemPosition::ptAxisRectRatio);
//    itemtext->position->setCoords(posx,posy);
//    itemtext->setPositionAlignment(Qt::AlignLeft);
//    itemtext->setTextAlignment(Qt::AlignLeft);
//    itemtext->setFont(infofont);
//    itemtext->setText(strinfo);
//    itemtext->setColor(color);
    Q_UNUSED(color);
}

/*  add data info text api;*/

void CsvDataDialog::displayDataInfoApib(QString strinfo,double posx,double posy,QColor color,double rotationdegress,double fontsize)
{
    Chartview->setText(2,posx,posy,strinfo);
//    QFont infofont;
//    infofont.setPointSize(fontsize);
//    QCPItemText *itemtext = new QCPItemText(Canvas);
//    itemtext->setPositionAlignment(Qt::AlignHCenter | Qt::AlignBottom);
//    itemtext->setTextAlignment(Qt::AlignHCenter | Qt::AlignBottom);
//    itemtext->position->setType(QCPItemPosition::ptPlotCoords);
//    itemtext->position->setCoords(posx,posy);
//    itemtext->setFont(infofont);
//    itemtext->setText(strinfo);
//    itemtext->setColor(color);
//    itemtext->setRotation(rotationdegress);
    Q_UNUSED(color);
    Q_UNUSED(rotationdegress);
    Q_UNUSED(fontsize);
}

/*  add data info text api;*/

void CsvDataDialog::displayDataInfo()
{
    QVector<double> alldatatemp = Alldata;
    if(Upperlimitbool && Lowerlimitbool)
    {
        alldatatemp.removeOne(Upperlimit);
        alldatatemp.removeOne(Lowerlimit);
    }
    if(alldatatemp.count() > 0)
    {
        Xmeanvalue = Core->getVectorMeanValue(&alldatatemp,alldatatemp.count());
        Xstddev = Core->getVectorStandardDeviation(&alldatatemp,alldatatemp.count(),Xmeanvalue);
        Capabilityofaccuracy = (Xmeanvalue - Xcentervalue) / Tolerance * 2;
        Capabilityofprecision = Tolerance / Xstddev / 6;
        Processcapabilityindex = Capabilityofprecision * (1 - abs(Capabilityofaccuracy));
        displayDataInfoApia("Mean: \t" + QString::number(Xmeanvalue) + "\nSigma: \t" + QString::number(Xstddev) + "\nCpk: \t" + QString::number(Processcapabilityindex),0.85,0.15);
    }
}

/*  display data cpk with upper and lower limit;*/

void CsvDataDialog::displayDataInfou()
{
    QVector<double> alldatatemp = Alldata;
    if(Upperlimitbool)
    {
        alldatatemp.removeOne(Upperlimit);
    }
    if(alldatatemp.count() > 0)
    {
        Xmeanvalue = Core->getVectorMeanValue(&alldatatemp,alldatatemp.count());
        Xstddev = Core->getVectorStandardDeviation(&alldatatemp,alldatatemp.count(),Xmeanvalue);
        Capabilityofprecision = (Xmaxvalue - Xmeanvalue) / Xstddev / 3;
        displayDataInfoApia("Mean: \t" + QString::number(Xmeanvalue) + "\nSigma: \t" + QString::number(Xstddev) + "\nCpu: \t" + QString::number(Capabilityofprecision),0.85,0.15);
    }
}

/*  display data cpk with upper limit;*/

void CsvDataDialog::displayDataInfol()
{
    QVector<double> alldatatemp = Alldata;
    if(Lowerlimitbool)
    {
        alldatatemp.removeOne(Lowerlimit);
    }
    if(alldatatemp.count() > 0)
    {
        Xmeanvalue = Core->getVectorMeanValue(&alldatatemp,alldatatemp.count());
        Xstddev = Core->getVectorStandardDeviation(&alldatatemp,alldatatemp.count(),Xmeanvalue);
        Capabilityofprecision = (Xmeanvalue - Xminvalue) / Xstddev / 3;
        displayDataInfoApia("Mean: \t" + QString::number(Xmeanvalue) + "\nSigma: \t" + QString::number(Xstddev) + "\nCpl: \t" + QString::number(Capabilityofprecision),0.85,0.15);
    }
}

/*  display data cpk with lower limit;*/

void CsvDataDialog::refresh()
{
    Dataitems.clear();
    Datalistvector.clear();
    Datalistcount.clear();
    Plugin->ui->pushButton->setEnabled(false);
    Threadra->start();
}

/*  start a new thread refresh dataitem;*/

void CsvDataDialog::grrFigurePlotChart()
{
    grrCheck();
    grrPlot();
}

/*  display grr chart;*/

void CsvDataDialog::grrCheck()
{
    grrCheckInit();
    grrCheckDutNumber();
    grrCheckDutIdentification();
    grrCheckTester();
    grrCheckAppraiser();
    grrCheckItemValue();
    grrCalResultInit();
    grrCalResult();
}

/*  check source data format could genarate grr report;*/

void CsvDataDialog::grrPlot()
{
    if(Grrcheckbool.at(3))
    {
        grrPlotInit();
    }
}

/*  add source data to plot;*/

void CsvDataDialog::grrCheckInit()
{
    Dutcounts = 0;
    Grrcheckbool[0] = false;
    Grrcheckbool[1] = false;
    Grrcheckbool[2] = false;
    Grrcheckbool[3] = false;
    Dutlist.clear();
    Dutidentificationvector.clear();
    Testerlist.clear();
    Appraiserlist.clear();
    Appraisertesttime.clear();
    Dutappraiservector.clear();
    Partchartvector.clear();
    Rangechartvector.clear();
    Appraiserchartvector.clear();
}

/*  init grr check parameter;*/

void CsvDataDialog::grrCheckDutNumber()
{
    for(int startrow = Datarow;startrow < Plugin->ui->tableWidget->rowCount();startrow++)
    {
        QString duttemp = Plugin->ui->tableWidget->item(startrow,Dutcolumn)->text();
        Dutcounts = Dutcounts + 1;
        if(!Dutlist.contains(duttemp))
        {
            Dutlist.append(duttemp);
        }
    }
}

/*  check source data dut number;*/

void CsvDataDialog::grrCheckDutIdentification()
{
    QString info = "";
    for(int i = 0;i < Dutlist.count();i++)
    {
        Dutidentificationvector.append(QVector<int> {});
        for(int startrow = Datarow;startrow < Plugin->ui->tableWidget->rowCount();startrow++)
        {
            if(Plugin->ui->tableWidget->item(startrow,Dutcolumn)->text() == Dutlist.at(i))
            {
                Dutidentificationvector[i].append(startrow);
            }
        }
    }
    for(int i = 0;i < Dutidentificationvector.count();i++)
    {
        if(Dutidentificationvector.at(i).count() != double(Dutcounts) / Dutlist.count())
        {
            info.append(Dutlist.at(i) + " counts is " + QString::number(Dutidentificationvector.at(i).count()) + ";\n");
        }
    }
    if(!info.isEmpty())
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,info);
        notedialog->messageInit();
        Grrcheckbool[0] = false;
        return;
    }
    Grrcheckbool[0] = true;
}

/*  check source data dut identification;*/

void CsvDataDialog::grrCheckTester()
{
    if(Grrcheckbool.at(0))
    {
        QString info = "";
        for(int startrow = Datarow;startrow < Plugin->ui->tableWidget->rowCount();startrow++)
        {
            QString testertemp = Plugin->ui->tableWidget->item(startrow,Testercolumn)->text();
            if(!Testerlist.contains(testertemp))
            {
                Testerlist.append(testertemp);
                info.append(QString::number(startrow) + " row: " + testertemp + ";\n");
            }
        }
        if(Testerlist.count() > 1)
        {
            SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,info);
            notedialog->messageInit();
            Grrcheckbool[1] = false;
            return;
        }
        Grrcheckbool[1] = true;
    }
}

/*  check source data tester format;*/

void CsvDataDialog::grrCheckAppraiser()
{
    if(Grrcheckbool.at(1))
    {
        QString info = "";
        for(int startrow = Datarow;startrow < Plugin->ui->tableWidget->rowCount();startrow++)
        {
            QString appraisertemp = Plugin->ui->tableWidget->item(startrow,Appraisercolumn)->text();
            if(!Appraiserlist.contains(appraisertemp))
            {
                Appraiserlist.append(appraisertemp);
                Appraisertesttime.append(0);
                Dutappraiservector.append(QVector<double>());
                info.append(QString::number(startrow) + " row: " + appraisertemp + ";\n");
            }
        }
        for(int i = 0;i < Dutidentificationvector.count();i++)
        {
            for(int j = 0;j < Dutidentificationvector.at(i).count();j++)
            {
                int row = Dutidentificationvector.at(i).at(j);
                QString appraisertemp = Plugin->ui->tableWidget->item(row,Appraisercolumn)->text();
                for(int k = 0;k < Appraiserlist.count();k++)
                {
                    if(appraisertemp == Appraiserlist.at(k))
                    {
                        Appraisertesttime[k] = Appraisertesttime.at(k) + 1;
                    }
                }
            }
            double maxvalue = Core->getVectorMaxValue(&Appraisertesttime,Appraisertesttime.count());
            double minvalue = Core->getVectorMinValue(&Appraisertesttime,Appraisertesttime.count());
            if(maxvalue != minvalue)
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,info);
                notedialog->messageInit();
                Grrcheckbool[2] = false;
                return;
            }
        }
        Grrcheckbool[2] = true;
    }
}

/*  check source data appraiser format;*/

void CsvDataDialog::grrCheckItemValue()
{
    if(Grrcheckbool.at(2))
    {
        QString info = "";
        bool boola = false;
        for(int startrow = Datarow;startrow < Plugin->ui->tableWidget->rowCount();startrow++)
        {
            QString valuetemp = Plugin->ui->tableWidget->item(startrow,Itemindex)->text();
            valuetemp.toDouble(&boola);
            if(!boola)
            {
                info.append(QString::number(startrow) + " row: " + valuetemp + ";\n");
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,info);
                notedialog->messageInit();
                Grrcheckbool[3] = false;
                return;
            }
        }
        Grrcheckbool[3] = true;
    }
}

/*  check source data completed;*/

void CsvDataDialog::grrCalResultInit()
{
    if(Grrcheckbool.at(3))
    {
        for(int i = 0;i < Dutidentificationvector.count();i++)
        {
            for(int j = 0;j < Dutidentificationvector.at(i).count();j++)
            {
                int row = Dutidentificationvector.at(i).at(j);
                QString appraisertemp = Plugin->ui->tableWidget->item(row,Appraisercolumn)->text();
                QString itemvaluetemp = Plugin->ui->tableWidget->item(row,Itemindex)->text();
                for(int k = 0;k < Appraiserlist.count();k++)
                {
                    if(appraisertemp == Appraiserlist.at(k))
                    {
                        Dutappraiservector[k].append(itemvaluetemp.toDouble());
                    }
                }
            }
        }
    }
}

/*  cal source data init;*/

void CsvDataDialog::grrCalResult()
{
    if(Grrcheckbool.at(3))
    {
        QVector<double> avgvector = {};
        QVector<double> avgvectortempa = {};
        QVector<double> avgvectortempb = {};
        QVector<double> extremevector = {};
        QVector<double> extremevectortemp = {};
        int appraisertesttime = Dutcounts / Appraiserlist.count();
        int testtime = appraisertesttime / Dutlist.count();
        for(int i = 0;i < Dutappraiservector.count();i++)
        {
            Rangechartvector.append(QVector<double> ());
            Appraiserchartvector.append(QVector<double> ());
            avgvector.append(Core->getVectorMeanValue(&Dutappraiservector[i],Dutappraiservector.at(i).count()));
            for(int j = 0;j < appraisertesttime;j++)
            {
                extremevectortemp.append(Dutappraiservector.at(i).at(j));
                if(extremevectortemp.count() >= testtime)
                {
                    double maxvalue = Core->getVectorMaxValue(&extremevectortemp,extremevectortemp.count());
                    double minvalue = Core->getVectorMinValue(&extremevectortemp,extremevectortemp.count());
                    double meanvalue = Core->getVectorMeanValue(&extremevectortemp,extremevectortemp.count());
                    extremevectortemp.clear();
                    Rangechartvector[i].append(maxvalue - minvalue);
                    Appraiserchartvector[i].append(meanvalue);
                }
            }
            extremevector.append(Core->getVectorMeanValue(&Rangechartvector[i],Rangechartvector.at(i).count()));
        }
        for(int i = 0;i < Dutidentificationvector.count();i++)
        {
            avgvectortempa.clear();
            for(int j = 0;j < Dutidentificationvector.at(i).count();j++)
            {
                int row = Dutidentificationvector.at(i).at(j);
                QString itemvaluetemp = Plugin->ui->tableWidget->item(row,Itemindex)->text();
                avgvectortempa.append(itemvaluetemp.toDouble());
            }
            Partchartvector.append(avgvectortempa);
            avgvectortempb.append(Core->getVectorMeanValue(&avgvectortempa,avgvectortempa.count()));
        }
        double avtemp = 0;
        Average = Core->getVectorMeanValue(&avgvector,avgvector.count());//XAA
        Dutaveragedifference = Core->getVectorMaxValue(&avgvectortempb,avgvectortempb.count()) - Core->getVectorMinValue(&avgvectortempb,avgvectortempb.count());//Rp
        Extremedifference = Core->getVectorMeanValue(&extremevector,extremevector.count());//RA
        Averagedifference = Core->getVectorMaxValue(&avgvector,avgvector.count()) - Core->getVectorMinValue(&avgvector,avgvector.count());//XAD
        Uclr = Extremedifference * D4.at(testtime);
        Ev = Extremedifference * K1.at(testtime);
        avtemp = Averagedifference * K2.at(Appraiserlist.count()) * Averagedifference * K2.at(Appraiserlist.count()) - (Ev * Ev) / Dutlist.count() / testtime;
        if(avtemp > 0)
        {
            Av = sqrt(avtemp);
        }
        else
        {
            Av = 0;
        }
        Grr = sqrt((Ev * Ev + Av * Av));
        Pv = Dutaveragedifference * K3.at(Dutlist.count());
        Tv = sqrt((Grr * Grr + Pv * Pv));
        Percentev = 100 * (Ev / Tv);
        Percentav = 100 * (Av / Tv);
        Percentgrr = 100 * (Grr / Tv);
        Percentpv = 100 * (Pv / Tv);
        Ndc = 1.41 * (Pv / Grr);
    }
}

/*  cal source data result;*/

void CsvDataDialog::grrPlotInit()
{
    Chartview->setLine(Appraiserlist.count());
//    for(int i = 0;i < Appraiserlist.count();i++)
//    {
//        Chartview->setBar(1);
////        Canvas->addGraph();
////        Canvas->graph(i)->setSelectable(QCP::SelectionType::stMultipleDataRanges);
//    }
    if(Plugin->ui->chartmode->text() == "range")
    {
        rangePlot();
    }
    else if(Plugin->ui->chartmode->text() == "appraiser")
    {
        appraiserPlot();
    }
    else if(Plugin->ui->chartmode->text() == "part")
    {
        partPlot();
    }
    else if(Plugin->ui->chartmode->text() == "Interaction")
    {
        interactionPlot();
    }
}

/*  cal source data result;*/

void CsvDataDialog::rangePlot()
{
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    Xdata = Core->arange(0,Dutlist.count(),1);
    for(int i = 0;i < Chartview->Scatterseriesvector.count();i++)
    {
        Chartview->setScatterData(i,&Xdata,&Rangechartvector[i]);
        ymaxvaluetemp.append(Core->getVectorMaxValue(&Rangechartvector[i],Rangechartvector.at(i).count()));
        yminvaluetemp.append(Core->getVectorMinValue(&Rangechartvector[i],Rangechartvector.at(i).count()));
        displayDataInfoApia(" --- " + Appraiserlist.at(i) + " --- ",0.85,0.15 + 0.05 * i,Colorvector.at(i));
    }
    double xmaxvalue = Core->getVectorMaxValue(&Xdata,Xdata.count());
    double xminvalue = Core->getVectorMinValue(&Xdata,Xdata.count());
    double ymaxvalue = Core->getVectorMaxValue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = Core->getVectorMinValue(&yminvaluetemp,yminvaluetemp.count());
    figurePlotRescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Dutlist.count();i++)
    {
        displayDataInfoApib(Dutlist.at(i),i,0,Qt::black,10);
    }
}

/*  cal source data range plot;*/

void CsvDataDialog::appraiserPlot()
{
    QVector<double> xmaxvaluetemp = {};
    QVector<double> xminvaluetemp = {};
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    QVector<QVector<double>> xdatatemp = {};
    for(int i = 0;i < Appraiserlist.count();i++)
    {
        xdatatemp.append(QVector<double> ());
        xdatatemp[i] = Core->linspace(i,i,Appraiserchartvector.at(i).count());
        Chartview->setLineData(i,&xdatatemp[i],&Appraiserchartvector[i]);
//        Canvas->graph(i)->setData(,true);
//        Canvas->graph(i)->setPen(Colorvector.at(i));
//        Canvas->graph(i)->setLineStyle(QCPGraph::LineStyle::lsNone);
//        Canvas->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
        xmaxvaluetemp.append(Core->getVectorMaxValue(&xdatatemp[i],xdatatemp.at(i).count()));
        xminvaluetemp.append(Core->getVectorMinValue(&xdatatemp[i],xdatatemp.at(i).count()));
        ymaxvaluetemp.append(Core->getVectorMaxValue(&Appraiserchartvector[i],Appraiserchartvector.at(i).count()));
        yminvaluetemp.append(Core->getVectorMinValue(&Appraiserchartvector[i],Appraiserchartvector.at(i).count()));
        displayDataInfoApia(" --- " + Appraiserlist.at(i) + " --- ",0.85,0.15 + 0.05 * i,Colorvector.at(i));
    }
    double xmaxvalue = Core->getVectorMaxValue(&xmaxvaluetemp,xmaxvaluetemp.count());
    double xminvalue = Core->getVectorMinValue(&xminvaluetemp,xminvaluetemp.count());
    double ymaxvalue = Core->getVectorMaxValue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = Core->getVectorMinValue(&yminvaluetemp,yminvaluetemp.count());
    figurePlotRescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Appraiserlist.count();i++)
    {
        displayDataInfoApib(" ### " + Appraiserlist.at(i) + " ### ",i,yminvalue - (ymaxvalue - yminvalue) / 10,Qt::black,0,8);
    }
}

/*  cal source data appraiser plot;*/

void CsvDataDialog::partPlot()
{
    QVector<double> xmaxvaluetemp = {};
    QVector<double> xminvaluetemp = {};
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    QVector<QVector<double>> xdatatemp = {};
//    Canvas->graph(Canvas->graphCount() - 1)->setPen(Backgroundcolor);
//    Canvas->graph(Canvas->graphCount() - 1)->setLineStyle(QCPGraph::LineStyle::lsNone);
//    Canvas->graph(Canvas->graphCount() - 1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
    for(int i = 0;i < Partchartvector.count();i++)
    {
        xdatatemp.append(QVector<double> ());
        xdatatemp[i] = Core->linspace(i,i,Partchartvector.at(i).count());
        Chartview->setLineData(1,&xdatatemp[i],&Partchartvector[i]);
       // Canvas->graph(Canvas->graphCount() - 1)->addData(xdatatemp[i],Partchartvector[i],true);
        xmaxvaluetemp.append(Core->getVectorMaxValue(&xdatatemp[i],xdatatemp.at(i).count()));
        xminvaluetemp.append(Core->getVectorMinValue(&xdatatemp[i],xdatatemp.at(i).count()));
        ymaxvaluetemp.append(Core->getVectorMaxValue(&Partchartvector[i],Partchartvector.at(i).count()));
        yminvaluetemp.append(Core->getVectorMinValue(&Partchartvector[i],Partchartvector.at(i).count()));
    }
    double xmaxvalue = Core->getVectorMaxValue(&xmaxvaluetemp,xmaxvaluetemp.count());
    double xminvalue = Core->getVectorMinValue(&xmaxvaluetemp,xmaxvaluetemp.count());
    double ymaxvalue = Core->getVectorMaxValue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = Core->getVectorMinValue(&yminvaluetemp,yminvaluetemp.count());
    figurePlotRescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Dutlist.count();i++)
    {
        displayDataInfoApib(Dutlist.at(i),i,yminvalue - (ymaxvalue - yminvalue) / 10,Qt::black,6);
    }
}

/*  cal source data part plot;*/

void CsvDataDialog::interactionPlot()
{
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    Interactionvector = Appraiserchartvector;
    Xdata = Core->arange(0,Dutlist.count(),1);
    for(int i = 0;i < Chartview->Lineseriesvector.count();i++)
    {
        Chartview->setLineData(i,&Xdata,&Interactionvector[i]);
//        Canvas->graph(i)->setData(Xdata,Interactionvector[i],true);
//        Canvas->graph(i)->setPen(Colorvector.at(i));
//        Canvas->graph(i)->setLineStyle(QCPGraph::LineStyle::lsLine);
//        Canvas->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
        ymaxvaluetemp.append(Core->getVectorMaxValue(&Interactionvector[i],Interactionvector.at(i).count()));
        yminvaluetemp.append(Core->getVectorMinValue(&Interactionvector[i],Interactionvector.at(i).count()));
        displayDataInfoApia(" --- " + Appraiserlist.at(i) + " --- ",0.85,0.15 + 0.05 * i,Colorvector.at(i));
    }
    double xmaxvalue = Core->getVectorMaxValue(&Xdata,Xdata.count());
    double xminvalue = Core->getVectorMinValue(&Xdata,Xdata.count());
    double ymaxvalue = Core->getVectorMaxValue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = Core->getVectorMinValue(&yminvaluetemp,yminvaluetemp.count());
    figurePlotRescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Dutlist.count();i++)
    {
        displayDataInfoApib(Dutlist.at(i),i,yminvalue - (ymaxvalue - yminvalue) / 10,Qt::black,6);
    }
}

/*  cal source data interaction plot;*/

void CsvDataDialog::signalDaSlot()
{
    refresh();
}

/*  recevice display table end signal and start refresh;*/

void CsvDataDialog::signalDbSlot(int rows,int columns)
{
    Rows = rows;
    Columns = columns;
    int size = Plugin->ui->tableWidget->horizontalHeader()->minimumSectionSize();
    Core->setTableWidgetItem(Rows,Columns,size,Plugin->ui->tableWidget);
}

/*  receive signal set tablewiget row and columns;*/

void CsvDataDialog::signalDcSlot(int valuea,int cellcount,QStringList stringlist)
{
    for(int i = 0;i < cellcount;i++)
    {
        QString cellstring = stringlist.at(i);
        if(cellstring.contains("\r"))
        {
            cellstring.remove("\r");
        }
        Plugin->ui->tableWidget->item(valuea,i)->setText(cellstring);
    }
}

/*  receive signal set new cell and its text alignment;*/

void CsvDataDialog::setProgressBar(int progressbarvalue,QString message)
{
    Progressbardialog->setValueMessage(progressbarvalue,message);
}

/*  receive signal set progressbar value and message;*/

void CsvDataDialog::signalSaSlot()
{
    Plugin->ui->pushButton_2->setText("Edit");
    Plugin->ui->pushButton_2->setEnabled(true);
    refresh();
}

/*  receive signal enable button;*/

void CsvDataDialog::signalRaSlot()
{
    Plugin->ui->pushButton->setEnabled(true);
}

/*  receive signal enable pushbutton;*/

DisplayTable::DisplayTable(QString strfilepath,QVector<QStringList>* csvqvectorstringlist)
{
    Strfilepath = strfilepath;
    Csvqvectorstringlist = csvqvectorstringlist;
    init();
}

DisplayTable::~DisplayTable()
{

}

void DisplayTable::run()
{
    getCsvFileInfo();
    setTableWidgetItem();
    emit signalDa();
    emit signalDd(100,"(3/3)DisplayTable function run completed;");
}

void DisplayTable::init()
{
    objectInit();
}

void DisplayTable::objectInit()
{
    Core = new SuperCore(this);
}

void DisplayTable::getCsvFileInfo()
{
    QFile file(Strfilepath);
    QStringList bytetemplist;
    QVector<double> Columnsvector;
    Rows = 0;
    Columns = 0;
    emit signalDd(99,"(1/3)start get csv file info...");
    Csvqvectorstringlist->clear();
    file.open(QIODevice::ReadOnly);
    QString bytetemp = file.readLine();
    while(!bytetemp.isEmpty())
    {
        bytetemplist = bytetemp.split(",");
        Columnsvector.append(bytetemplist.count());
        bytetemp = file.readLine();
        Csvqvectorstringlist->append(bytetemplist);
    }
    file.close();
    Rows = Csvqvectorstringlist->count();
    Columns = Core->getVectorMaxValue(&Columnsvector,Rows);
    emit signalDb(Rows,Columns);
}

/*  get csv file info;*/

void DisplayTable::setTableWidgetItem()
{
    for(int i = 0;i < Rows;i++)
    {
        int Columnscounts = Csvqvectorstringlist->at(i).count();
        emit signalDc(i,Columnscounts,Csvqvectorstringlist->at(i));
        emit signalDd(double(i + 1) / double(Rows) * 99,"(2/3)setTableWidgetItem function running...");
    }
}

/*  set table widget items;*/

SaveCell::SaveCell(QString csvfilepath,QTableWidget* tablewidget)
{
    Csvfilepath = csvfilepath;
    Tablewidget = tablewidget;
    Rows = Tablewidget->rowCount();
    Columns = Tablewidget->columnCount();
    init();
}

void SaveCell::init()
{
    objectInit();
}

void SaveCell::objectInit()
{
    Core = new SuperCore(this);
}

void SaveCell::run()
{
    getCellInfo();
    Core->writeOnlyFile(Csvfilepath,Strcell);
    emit signalSb(100,"(2/2)Save completed");
    emit signalSa();
}

void SaveCell::getCellInfo()
{
    QString cell;
    for(int i = 0;i<Rows;i++)
    {
        cell = "";
        for(int j = 0;j < Columns;j++)
        {
            cell = cell + Tablewidget->item(i,j)->text() + ",";
        }
        cell = cell.split("\n").at(0);
        Strcell = Strcell + cell + "\n";
        emit signalSb(double(i) / double(Rows) * 99,"(1/2)Getcellinfo running...");
    }
}

/*  save cell info to strcell;*/

RefreshItems::RefreshItems(int *row,int *columns,QTableWidget *tablewidget,QStringList *dataitems,QVector<QStringList> *datalistvector,QStringList *datalistcount)
{
    Rows = row;
    Columns = columns;
    Tablewidget = tablewidget;
    Dataitems = dataitems;
    Datalistvector = datalistvector;
    Datalistcount = datalistcount;
    init();
}

RefreshItems::~RefreshItems()
{

}

void RefreshItems::init()
{
    objectInit();
}

void RefreshItems::objectInit()
{
    Core = new SuperCore(this);
}

void RefreshItems::run()
{
    initRun();
    findDataItem();
    getDataByItema();
    analysisItems();
    emit signalRb(100,"(4/4)RefreshItems function run completed");
    emit signalRa();
}

void RefreshItems::initRun()
{
    Datalistvector->clear();
    Tdataitems.clear();
    Tdatalistvector.clear();
}

/*  paremeter init;*/

void RefreshItems::findDataItem()
{
    QString dataitemtemp;
    for(int i = 0;i < *Columns;i++)
    {
        for(int j = 0;j < *Rows;j++)
        {
            dataitemtemp = Tablewidget->item(j,i)->text();
            if(!dataitemtemp.isEmpty())
            {
                break;
            }
        }
        Tdataitems.append(dataitemtemp);
        Tdatalistvector.append(QStringList());
    }
    emit signalRb(99,"(1/4)findDataItem function running...");
}

/*  find data items;*/

void RefreshItems::getDataByItema()
{
    QString strcell;
    for(int i = 0;i < *Columns;i++)
    {
        for(int j = 0;j < *Rows;j++)
        {
            strcell = Tablewidget->item(j,i)->text();
            getDataByItemb(strcell,i);
        }
        emit signalRb(double(i) / double(*Columns) * 99,"(2/4)findDataItem function running...");
    }
}

/*  add double data to list a;*/

void RefreshItems::getDataByItemb(QString strcell,int itemindex)
{
    bool boola;
    strcell.toDouble(&boola);
    if(boola)
    {
        Tdatalistvector[itemindex].append(strcell);
    }
}

/*  add double data to list b;*/

void RefreshItems::analysisItems()
{
    int itemscount = Tdataitems.count();
    for(int i = 0;i < itemscount;i++)
    {
        Datalistvector->append(Tdatalistvector.at(i));
        Dataitems->append(Tdataitems.at(i));
        Datalistcount->append(QString::number(Tdatalistvector.at(i).count()));
        emit signalRb(double(i) / double(itemscount) * 99,"(3/4)findDataItem function running...");
    }
}

/*  analysis items;*/
