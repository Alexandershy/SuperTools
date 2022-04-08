#include "_datadialog_.h"

DataDialog::DataDialog(QWidget *parent,QString csvfile)
    : SuperWindow(parent)
{
    Csvfile = csvfile;
    Init();
    setAttribute(Qt::WA_DeleteOnClose);
    Settitle(csvfile);
}

DataDialog::~DataDialog()
{
    SuperC->Closethread(Threadda);
    SuperC->Closethread(Threadra);
    SuperC->Closethread(Threadsa);
    delete Itemstreedialog;
    delete Progressbardialog;
}

void DataDialog::Init()
{
    Objectinit();
    Colorinit();
    Threadinit();
    Iconinit();
    Plotinit();
}

void DataDialog::Objectinit()
{
    Plugin = new DataBox(this);
    Pluginlayout->addWidget(Plugin);
    Progressbardialog   = new SuperProgressBarDialog();
    Itemstreedialog     = new ItemDialog(nullptr,&Dataitems,&Datalistcount);
    Canvas              = new SuperPlot(this);
    Histogram           = new QCPBars(Canvas->xAxis,Canvas->yAxis);
    Infoscombodialog    = new InfoDialog(nullptr);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,  this,&DataDialog::Dragmode);
    connect(Plugin->ui->pushButton_4,   &QPushButton::clicked,  this,&DataDialog::Selectmode);
    connect(Plugin->ui->pushButton_5,   &QPushButton::clicked,  this,&DataDialog::Resetplot);
    connect(Plugin->ui->pushButton_6,   &QPushButton::clicked,  this,&DataDialog::Displayselecteddata);
    connect(Plugin->ui->pushButton_7,   &QPushButton::clicked,  this,&DataDialog::Changecpkmode);
    connect(Plugin->ui->pushButton_8,   &QPushButton::clicked,  this,&DataDialog::Changechartmode);
    connect(Plugin->ui->pushButton_9,   &QPushButton::clicked,  this,&DataDialog::Setplotinfo);
    connect(Plugin->ui->pushButton_10,  &QPushButton::clicked,  this,&DataDialog::Refresh);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,  this,&DataDialog::Items);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,  this,&DataDialog::Seteditable);
    connect(Itemstreedialog,            &ItemDialog::Signalia,  this,&DataDialog::Cpkdisplayitemplot);
    connect(Itemstreedialog,            &ItemDialog::Signalib,  this,&DataDialog::Grrdisplayitemplot);
    connect(Infoscombodialog,           &InfoDialog::Signalia,  this,&DataDialog::Setplotitemindex);
    connect(Infoscombodialog,           &InfoDialog::Signalib,  this,&DataDialog::Setplotupperindex);
    connect(Infoscombodialog,           &InfoDialog::Signalic,  this,&DataDialog::Setplotlowerindex);
    connect(Infoscombodialog,           &InfoDialog::Signalid,  this,&DataDialog::Setplotdataindex);
    connect(Infoscombodialog,           &InfoDialog::Signalie,  this,&DataDialog::Setplotdutindex);
    connect(Infoscombodialog,           &InfoDialog::Signalif,  this,&DataDialog::Setplottesterindex);
    connect(Infoscombodialog,           &InfoDialog::Signalig,  this,&DataDialog::Setplotappraiserindex);
}

void DataDialog::Colorinit()
{
    SuperC->Colorinit(&Backgroundcolor,&Fontcolor,&Concolor,&Strrgbbackgroundcolor,&Strrgbfontcolor,&Strrgbconcolor);
}

/*  init color;*/

void DataDialog::Plotinit()
{
    Groupcounts = 100;
    Canvas->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
    Canvas->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);
    Canvas->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables| QCP::iMultiSelect);
    Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Plugin->ui->verticalLayout_5->addWidget(Canvas);
}

/*  init plot;*/

void DataDialog::Iconinit()
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

void DataDialog::Threadinit()
{
    Threadsa = new SaveCell(Csvfile,Plugin->ui->tableWidget);
    Threadra = new RefreshItems(&Rows,&Columns,Plugin->ui->tableWidget,&Dataitems,&Datalistvector,&Datalistcount);
    Threadda = new DisplayTable(Csvfile,&Csvqvectorstringlist);
    connect(Threadsa,&SaveCell::Signalsa,    this,      &DataDialog::Signalsaslot);
    connect(Threadsa,&SaveCell::Signalsb,    this,      &DataDialog::Setprogressbar);
    connect(Threadra,&RefreshItems::Signalra,this,      &DataDialog::Signalraslot);
    connect(Threadda,&DisplayTable::Signalda,this,      &DataDialog::Signaldaslot);
    connect(Threadda,&DisplayTable::Signaldb,this,      &DataDialog::Signaldbslot);
    connect(Threadda,&DisplayTable::Signaldc,this,      &DataDialog::Signaldcslot);
    connect(Threadda,&DisplayTable::Signaldd,this,      &DataDialog::Setprogressbar);
    Threadda->start();
    Progressbardialog->Show();    
}

/*  start init thread;*/

void DataDialog::Seteditable()
{
    if(Plugin->ui->pushButton_2->text() == "Apply")
    {
        Plugin->ui->pushButton_2->setEnabled(false);
        Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Apply();
    }
    else
    {
        Plugin->ui->pushButton_2->setText("Apply");
        Plugin->ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
}

/*  enable edit or save cell to csvfile;*/

void DataDialog::Apply()
{
    Threadsa->start();
    Progressbardialog->Show();
}

/*  start a new thread to save cell to csvfile;*/

void DataDialog::Dragmode()
{
    Plugin->ui->pushButton_3->setEnabled(false);
    Plugin->ui->pushButton_4->setEnabled(true);
    Canvas->setInteraction(QCP::iRangeDrag,true);
    Canvas->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
}

/*  set canvas as drag mode;*/

void DataDialog::Selectmode()
{
    Plugin->ui->pushButton_3->setEnabled(true);
    Plugin->ui->pushButton_4->setEnabled(false);
    Canvas->setInteraction(QCP::iNone,true);
    Canvas->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
}

/*  set canvas as select mode;*/

void DataDialog::Resetplot()
{
    if(Currentmode == 0)
    {
        Cpkfigureplot();
    }
    else
    {
        Grrfigureplot();
    }
}

/*  reset plot;*/

void DataDialog::Displayselecteddata()
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
        Appendxydata();
        Resetplot();
    }
    else
    {
        SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,"valid cell on data tab;\nreselect data again;");
        notedialog->Messageinit();
    }
}

/*  display select data at table widget;*/

void DataDialog::Changecpkmode()
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
    Cpkfigureplot();
}

/*  change cpk display mode and replot;*/

void DataDialog::Changechartmode()
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
        Cpkfigureplot();
    }
    else
    {
        Grrfigureplot();
    }
}

/*  change chart display mode and replot;*/

void DataDialog::Setplotinfo()
{
    Infoscombodialog->Show();
}

/*  set upper lower item line index;*/

void DataDialog::Setplotitemindex(int itemindex)
{
    Itemrow = itemindex;
}

/*  set item line index;*/

void DataDialog::Setplotupperindex(int upperindex)
{
    Upperlimitrow = upperindex;
}

/*  set upper line index;*/

void DataDialog::Setplotlowerindex(int lowerindex)
{
    Lowerlimitrow = lowerindex;
}

/*  set lower line index;*/

void DataDialog::Setplotdataindex(int dataindex)
{
    Datarow = dataindex;
}

/*  set data line index;*/

void DataDialog::Setplotdutindex(int dutindex)
{
    Dutcolumn = dutindex;
}

/*  set data line index;*/

void DataDialog::Setplottesterindex(int testerindex)
{
    Testercolumn = testerindex;
}

/*  set data line index;*/

void DataDialog::Setplotappraiserindex(int appraiserindex)
{
    Appraisercolumn = appraiserindex;
}

/*  set data line index;*/

void DataDialog::Items()
{
    Itemstreedialog->Refresh();
    Itemstreedialog->Show();
}

/*  display items have double value at table widget;*/

void DataDialog::Cpkdisplayitemplot(int index)
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
    Appendalldata(Itemindex);
    Appendxydata();
    Cpkfigureplot();
}

/*  open cpk selected items at items dialog;*/

void DataDialog::Grrdisplayitemplot(int index)
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
    Appendalldata(Itemindex);
    Appendxydata();
    Grrfigureplot();
}

/*  open grr selected items at items dialog;*/

void DataDialog::Appendalldata(int itemindex)
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

void DataDialog::Appendxydata()
{
    double datatemp = 0;
    int xdatacount = Alldata.count();
    Xminvalue = SuperC->Getqvectorminvalue(&Alldata,xdatacount);
    Xmaxvalue = SuperC->Getqvectormaxvalue(&Alldata,xdatacount);
    Tolerance = Xmaxvalue - Xminvalue;
    Xcentervalue = Xminvalue + Tolerance / 2;
    Xdata = SuperC->Linspace(Xminvalue,Xmaxvalue,Groupcounts);
    Xdata.append(Xmaxvalue);
    Ydata = SuperC->Linspace(0,0,Groupcounts + 1);
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
    Ymaxvalue = SuperC->Getqvectormaxvalue(&Ydata,Groupcounts);
    Upperlimit = Plugin->ui->tableWidget->item(Upperlimitrow,Itemindex)->text().toDouble(&Upperlimitbool);
    Lowerlimit = Plugin->ui->tableWidget->item(Lowerlimitrow,Itemindex)->text().toDouble(&Lowerlimitbool);
}

/*  creat new xdata and ydata for histogram,and define cpk parameters;*/

void DataDialog::Cpkfigureplot()
{
    Cpkfigureplotinit();
    Cpkfigureplotchart();
    Canvas->replot(QCustomPlot::rpQueuedReplot);
    Plugin->ui->pushButton_5->setEnabled(true);  
}

/*  plot xdata and ydata and add its text,display cpk append on different parameters;*/

void DataDialog::Grrfigureplot()
{
    Grrfigureplotinit();
    Grrfigureplotchart();
    Canvas->replot(QCustomPlot::rpQueuedReplot);
    Plugin->ui->pushButton_5->setEnabled(true);
}

/*  plot xdata and ydata and add its text,display grr append on different parameters;*/

void DataDialog::Cpkfigureplotinit()
{
    Cleargraphs();
    Canvas->clearItems();
    Canvas->addGraph();
    Canvas->graph(0)->setSelectable(QCP::SelectionType::stMultipleDataRanges);
    Histogram->setData(QVector<double> {0},QVector<double> {0});
    Additemtitle();
}

/*  cpk canvas init;*/

void DataDialog::Grrfigureplotinit()
{
    Cleargraphs();
    Canvas->clearItems();
    Histogram->setData(QVector<double> {0},QVector<double> {0});
    Additemtitle();
}

/*  grr canvas init;*/

void DataDialog::Cleargraphs()
{
    for(int i = 0;i < Canvas->graphCount();i++)
    {
        Canvas->graph(i)->data().data()->clear();
    }
    Canvas->clearGraphs();
}

/*  clear graphs and data;*/

void DataDialog::Cpkfigureplotchart()
{
    if(Plugin->ui->chartmode->text() == "line")
    {
        Linechart();
    }
    else if(Plugin->ui->chartmode->text() == "histogram")
    {
        Histogramchart();
    }
    else
    {
        Scatterchart();
    }
}

/*  display chart type;*/

void DataDialog::Linechart()
{
    Canvas->graph(0)->setData(Xdata,Ydata,true);
    Canvas->graph(0)->setPen(Backgroundcolor);
    Canvas->graph(0)->setLineStyle(QCPGraph::LineStyle::lsStepCenter);
    Canvas->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone));
    Figureplotrescaleaxes(Xmaxvalue,Xminvalue,Ymaxvalue,Yminvalue);
    Adddatatexta();
    Figureplotcpkmode();
}

/*  set canvas as line chart;*/

void DataDialog::Histogramchart()
{
    Histogram->setData(Xdata,Ydata,true);
    Histogram->setAntialiased(false);
    Histogram->setWidth(Groupdistance);
    Histogram->setBrush(Backgroundcolor);
    Histogram->setPen(Fontcolor);
    Figureplotrescaleaxes(Xmaxvalue,Xminvalue,Ymaxvalue,Yminvalue);
    Adddatatexta();
    Figureplotcpkmode();
}

/*  set canvas as histogram chart;*/

void DataDialog::Scatterchart()
{
    QVector<double> xdata;
    QVector<double> ydata = Alldata;
    int alldatatempcount = ydata.count();
    xdata = SuperC->Arange(0,alldatatempcount,1);
    Canvas->graph(0)->setLineStyle(QCPGraph::lsNone);
    Canvas->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,2));
    Canvas->graph(0)->setPen(Backgroundcolor);
    Canvas->graph(0)->setData(xdata,ydata,true);
    Displaydatainfoapia("Total counts: " + QString::number(alldatatempcount),0.85,0.15);
    Figureplotrescaleaxes(alldatatempcount,0,SuperC->Getqvectormaxvalue(&ydata,ydata.count()),SuperC->Getqvectorminvalue(&ydata,ydata.count()));
}

/*  set canvas as scatter chart;*/

void DataDialog::Figureplotcpkmode()
{
    if(Plugin->ui->cpkmode->text() == "double limit")
    {
        Displaydatainfo();
    }
    else if(Plugin->ui->cpkmode->text() == "upper limit")
    {
        Displaydatainfou();
    }
    else
    {
        Displaydatainfol();
    }
}

/*  display data info depend cpk mode;*/

void DataDialog::Figureplotrescaleaxes(double xmax,double xmin,double ymax,double ymin)
{
    if(xmax == xmin || ymax == ymin)
    {
        Canvas->rescaleAxes();
    }
    else
    {
        double xrange = (xmax - xmin) * 0.1;
        double yrange = (ymax - ymin) * 0.1;
        Canvas->xAxis->setRange(xmin - xrange,xmax + xrange);
        Canvas->yAxis->setRange(ymin - yrange,ymax + yrange);
    }
}

/*  rescale axes;*/

void DataDialog::Additemtitle()
{
    QFont titlefont;
    QCPItemText *itemname = new QCPItemText(Canvas);
    titlefont.setUnderline(true);
    titlefont.setBold(true);
    titlefont.setPointSize(8);
    itemname->position->setType(QCPItemPosition::ptAxisRectRatio);
    itemname->position->setCoords(0.52, 0.01);
    itemname->setFont(titlefont);
    Itemtitle.remove("\r");
    Itemtitle.remove("\n");
    itemname->setText("  " + Itemtitle + "  ");
}

/*  add item title to canvas;*/

void DataDialog::Adddatatexta()
{
    for(int i = 0;i < Groupcounts + 1;i++)
    {
        double yvalue = Ydata.at(i);
        if(yvalue > 0)
        {
            double xpos = Xminvalue + Groupdistance * i;
            double ypos = Ydata.at(i);
            Displaydatainfoapib(QString::number(yvalue),xpos,ypos);
        }
    }
}

/*  add data text to canvas;*/

void DataDialog::Displaydatainfoapia(QString strinfo,double posx,double posy,QColor color)
{
    QFont infofont;
    infofont.setPointSize(8);
    QCPItemText *itemtext = new QCPItemText(Canvas);
    itemtext->position->setType(QCPItemPosition::ptAxisRectRatio);
    itemtext->position->setCoords(posx,posy);
    itemtext->setPositionAlignment(Qt::AlignLeft);
    itemtext->setTextAlignment(Qt::AlignLeft);
    itemtext->setFont(infofont);
    itemtext->setText(strinfo);
    itemtext->setColor(color);
}

/*  add data info text api;*/

void DataDialog::Displaydatainfoapib(QString strinfo,double posx,double posy,QColor color,double rotationdegress,double fontsize)
{
    QFont infofont;
    infofont.setPointSize(fontsize);
    QCPItemText *itemtext = new QCPItemText(Canvas);
    itemtext->setPositionAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    itemtext->setTextAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    itemtext->position->setType(QCPItemPosition::ptPlotCoords);
    itemtext->position->setCoords(posx,posy);
    itemtext->setFont(infofont);
    itemtext->setText(strinfo);
    itemtext->setColor(color);
    itemtext->setRotation(rotationdegress);
}

/*  add data info text api;*/

void DataDialog::Displaydatainfo()
{
    QVector<double> alldatatemp = Alldata;
    if(Upperlimitbool && Lowerlimitbool)
    {
        alldatatemp.removeOne(Upperlimit);
        alldatatemp.removeOne(Lowerlimit);
    }
    if(alldatatemp.count() > 0)
    {
        Xmeanvalue = SuperC->Getqvectormeanvalue(&alldatatemp,alldatatemp.count());
        Xstddev = SuperC->Getqvectorstandarddeviation(&alldatatemp,alldatatemp.count(),Xmeanvalue);
        Capabilityofaccuracy = (Xmeanvalue - Xcentervalue) / Tolerance * 2;
        Capabilityofprecision = Tolerance / Xstddev / 6;
        Processcapabilityindex = Capabilityofprecision * (1 - abs(Capabilityofaccuracy));
        Displaydatainfoapia("Mean: \t" + QString::number(Xmeanvalue) + "\nSigma: \t" + QString::number(Xstddev) + "\nCpk: \t" + QString::number(Processcapabilityindex),0.85,0.15);
    }
}

/*  display data cpk with upper and lower limit;*/

void DataDialog::Displaydatainfou()
{
    QVector<double> alldatatemp = Alldata;
    if(Upperlimitbool)
    {
        alldatatemp.removeOne(Upperlimit);
    }
    if(alldatatemp.count() > 0)
    {
        Xmeanvalue = SuperC->Getqvectormeanvalue(&alldatatemp,alldatatemp.count());
        Xstddev = SuperC->Getqvectorstandarddeviation(&alldatatemp,alldatatemp.count(),Xmeanvalue);
        Capabilityofprecision = (Xmaxvalue - Xmeanvalue) / Xstddev / 3;
        Displaydatainfoapia("Mean: \t" + QString::number(Xmeanvalue) + "\nSigma: \t" + QString::number(Xstddev) + "\nCpu: \t" + QString::number(Capabilityofprecision),0.85,0.15);
    }
}

/*  display data cpk with upper limit;*/

void DataDialog::Displaydatainfol()
{
    QVector<double> alldatatemp = Alldata;
    if(Lowerlimitbool)
    {
        alldatatemp.removeOne(Lowerlimit);
    }
    if(alldatatemp.count() > 0)
    {
        Xmeanvalue = SuperC->Getqvectormeanvalue(&alldatatemp,alldatatemp.count());
        Xstddev = SuperC->Getqvectorstandarddeviation(&alldatatemp,alldatatemp.count(),Xmeanvalue);
        Capabilityofprecision = (Xmeanvalue - Xminvalue) / Xstddev / 3;
        Displaydatainfoapia("Mean: \t" + QString::number(Xmeanvalue) + "\nSigma: \t" + QString::number(Xstddev) + "\nCpl: \t" + QString::number(Capabilityofprecision),0.85,0.15);
    }
}

/*  display data cpk with lower limit;*/

void DataDialog::Refresh()
{
    Dataitems.clear();
    Datalistvector.clear();
    Datalistcount.clear();
    Plugin->ui->pushButton->setEnabled(false);
    Threadra->start();
}

/*  start a new thread refresh dataitem;*/

void DataDialog::Grrfigureplotchart()
{
    Grrcheck();
    Grrplot();
}

/*  display grr chart;*/

void DataDialog::Grrcheck()
{
    Grrcheckinit();
    Grrcheckdutnumber();
    Grrcheckdutidentification();
    Grrchecktester();
    Grrcheckappraiser();
    Grrcheckitemvalue();
    Grrcalresultinit();
    Grrcalresult();
}

/*  check source data format could genarate grr report;*/

void DataDialog::Grrplot()
{
    if(Grrcheckbool.at(3))
    {
        Grrplotinit();
    }
}

/*  add source data to plot;*/

void DataDialog::Grrcheckinit()
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

void DataDialog::Grrcheckdutnumber()
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

void DataDialog::Grrcheckdutidentification()
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
        notedialog->Messageinit();
        Grrcheckbool[0] = false;
        return;
    }
    Grrcheckbool[0] = true;
}

/*  check source data dut identification;*/

void DataDialog::Grrchecktester()
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
            notedialog->Messageinit();
            Grrcheckbool[1] = false;
            return;
        }
        Grrcheckbool[1] = true;
    }
}

/*  check source data tester format;*/

void DataDialog::Grrcheckappraiser()
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
            double maxvalue = SuperC->Getqvectormaxvalue(&Appraisertesttime,Appraisertesttime.count());
            double minvalue = SuperC->Getqvectorminvalue(&Appraisertesttime,Appraisertesttime.count());
            if(maxvalue != minvalue)
            {
                SuperNoteDialog *notedialog = new SuperNoteDialog(nullptr,info);
                notedialog->Messageinit();
                Grrcheckbool[2] = false;
                return;
            }
        }
        Grrcheckbool[2] = true;
    }
}

/*  check source data appraiser format;*/

void DataDialog::Grrcheckitemvalue()
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
                notedialog->Messageinit();
                Grrcheckbool[3] = false;
                return;
            }
        }
        Grrcheckbool[3] = true;
    }
}

/*  check source data completed;*/

void DataDialog::Grrcalresultinit()
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

void DataDialog::Grrcalresult()
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
            avgvector.append(SuperC->Getqvectormeanvalue(&Dutappraiservector[i],Dutappraiservector.at(i).count()));
            for(int j = 0;j < appraisertesttime;j++)
            {
                extremevectortemp.append(Dutappraiservector.at(i).at(j));
                if(extremevectortemp.count() >= testtime)
                {
                    double maxvalue = SuperC->Getqvectormaxvalue(&extremevectortemp,extremevectortemp.count());
                    double minvalue = SuperC->Getqvectorminvalue(&extremevectortemp,extremevectortemp.count());
                    double meanvalue = SuperC->Getqvectormeanvalue(&extremevectortemp,extremevectortemp.count());
                    extremevectortemp.clear();
                    Rangechartvector[i].append(maxvalue - minvalue);
                    Appraiserchartvector[i].append(meanvalue);
                }
            }
            extremevector.append(SuperC->Getqvectormeanvalue(&Rangechartvector[i],Rangechartvector.at(i).count()));
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
            avgvectortempb.append(SuperC->Getqvectormeanvalue(&avgvectortempa,avgvectortempa.count()));
        }
        double avtemp = 0;
        Average = SuperC->Getqvectormeanvalue(&avgvector,avgvector.count());//XAA
        Dutaveragedifference = SuperC->Getqvectormaxvalue(&avgvectortempb,avgvectortempb.count()) - SuperC->Getqvectorminvalue(&avgvectortempb,avgvectortempb.count());//Rp
        Extremedifference = SuperC->Getqvectormeanvalue(&extremevector,extremevector.count());//RA
        Averagedifference = SuperC->Getqvectormaxvalue(&avgvector,avgvector.count()) - SuperC->Getqvectorminvalue(&avgvector,avgvector.count());//XAD
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

//        qDebug() << "Average" << Average;
//        qDebug() << "Dutaveragedifference" << Dutaveragedifference;
//        qDebug() << "Extremedifference" << Extremedifference;
//        qDebug() << "Averagedifference" << Averagedifference;
//        qDebug() << "Uclr" << Uclr;
//        qDebug() << "Ev" << Ev;
//        qDebug() << "Av" << Av;
//        qDebug() << "Grr" << Grr;
//        qDebug() << "Pv" << Pv;
//        qDebug() << "Tv" << Tv;
//        qDebug() << "Percentev" << Percentev;
//        qDebug() << "Percentav" << Percentav;
//        qDebug() << "Percentgrr" << Percentgrr;
//        qDebug() << "Percentpv" << Percentpv;
//        qDebug() << "Ndc" << Ndc;

    }
}

/*  cal source data result;*/

void DataDialog::Grrplotinit()
{
    for(int i = 0;i < Appraiserlist.count();i++)
    {
        Canvas->addGraph();
        Canvas->graph(i)->setSelectable(QCP::SelectionType::stMultipleDataRanges);
    }
    if(Plugin->ui->chartmode->text() == "range")
    {
        Rangeplot();
    }
    else if(Plugin->ui->chartmode->text() == "appraiser")
    {
        Appraiserplot();
    }
    else if(Plugin->ui->chartmode->text() == "part")
    {
        Partplot();
    }
    else if(Plugin->ui->chartmode->text() == "Interaction")
    {
        Interactionplot();
    }
}

/*  cal source data result;*/

void DataDialog::Rangeplot()
{
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    Xdata = SuperC->Arange(0,Dutlist.count(),1);
    for(int i = 0;i < Canvas->graphCount();i++)
    {
        Canvas->graph(i)->setData(Xdata,Rangechartvector[i],true);
        Canvas->graph(i)->setPen(Colorvector.at(i));
        Canvas->graph(i)->setLineStyle(QCPGraph::LineStyle::lsLine);
        Canvas->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone));
        ymaxvaluetemp.append(SuperC->Getqvectormaxvalue(&Rangechartvector[i],Rangechartvector.at(i).count()));
        yminvaluetemp.append(SuperC->Getqvectorminvalue(&Rangechartvector[i],Rangechartvector.at(i).count()));
        Displaydatainfoapia(" --- " + Appraiserlist.at(i) + " --- ",0.85,0.15 + 0.05 * i,Colorvector.at(i));
    }
    double xmaxvalue = SuperC->Getqvectormaxvalue(&Xdata,Xdata.count());
    double xminvalue = SuperC->Getqvectorminvalue(&Xdata,Xdata.count());
    double ymaxvalue = SuperC->Getqvectormaxvalue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = SuperC->Getqvectorminvalue(&yminvaluetemp,yminvaluetemp.count());
    Figureplotrescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Dutlist.count();i++)
    {
        Displaydatainfoapib(Dutlist.at(i),i,0,Qt::black,10);
    }
}

/*  cal source data range plot;*/

void DataDialog::Appraiserplot()
{
    QVector<double> xmaxvaluetemp = {};
    QVector<double> xminvaluetemp = {};
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    QVector<QVector<double>> xdatatemp = {};
    for(int i = 0;i < Appraiserlist.count();i++)
    {
        xdatatemp.append(QVector<double> ());
        xdatatemp[i] = SuperC->Linspace(i,i,Appraiserchartvector.at(i).count());
        Canvas->graph(i)->setData(xdatatemp[i],Appraiserchartvector[i],true);
        Canvas->graph(i)->setPen(Colorvector.at(i));
        Canvas->graph(i)->setLineStyle(QCPGraph::LineStyle::lsNone);
        Canvas->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
        xmaxvaluetemp.append(SuperC->Getqvectormaxvalue(&xdatatemp[i],xdatatemp.at(i).count()));
        xminvaluetemp.append(SuperC->Getqvectorminvalue(&xdatatemp[i],xdatatemp.at(i).count()));
        ymaxvaluetemp.append(SuperC->Getqvectormaxvalue(&Appraiserchartvector[i],Appraiserchartvector.at(i).count()));
        yminvaluetemp.append(SuperC->Getqvectorminvalue(&Appraiserchartvector[i],Appraiserchartvector.at(i).count()));
        Displaydatainfoapia(" --- " + Appraiserlist.at(i) + " --- ",0.85,0.15 + 0.05 * i,Colorvector.at(i));
    }
    double xmaxvalue = SuperC->Getqvectormaxvalue(&xmaxvaluetemp,xmaxvaluetemp.count());
    double xminvalue = SuperC->Getqvectorminvalue(&xminvaluetemp,xminvaluetemp.count());
    double ymaxvalue = SuperC->Getqvectormaxvalue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = SuperC->Getqvectorminvalue(&yminvaluetemp,yminvaluetemp.count());
    Figureplotrescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Appraiserlist.count();i++)
    {
        Displaydatainfoapib(" ### " + Appraiserlist.at(i) + " ### ",i,yminvalue - (ymaxvalue - yminvalue) / 10,Qt::black,0,8);
    }
}

/*  cal source data appraiser plot;*/

void DataDialog::Partplot()
{
    QVector<double> xmaxvaluetemp = {};
    QVector<double> xminvaluetemp = {};
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    QVector<QVector<double>> xdatatemp = {};
    Canvas->graph(Canvas->graphCount() - 1)->setPen(Backgroundcolor);
    Canvas->graph(Canvas->graphCount() - 1)->setLineStyle(QCPGraph::LineStyle::lsNone);
    Canvas->graph(Canvas->graphCount() - 1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
    for(int i = 0;i < Partchartvector.count();i++)
    {
        xdatatemp.append(QVector<double> ());
        xdatatemp[i] = SuperC->Linspace(i,i,Partchartvector.at(i).count());
        Canvas->graph(Canvas->graphCount() - 1)->addData(xdatatemp[i],Partchartvector[i],true);
        xmaxvaluetemp.append(SuperC->Getqvectormaxvalue(&xdatatemp[i],xdatatemp.at(i).count()));
        xminvaluetemp.append(SuperC->Getqvectorminvalue(&xdatatemp[i],xdatatemp.at(i).count()));
        ymaxvaluetemp.append(SuperC->Getqvectormaxvalue(&Partchartvector[i],Partchartvector.at(i).count()));
        yminvaluetemp.append(SuperC->Getqvectorminvalue(&Partchartvector[i],Partchartvector.at(i).count()));
    }
    double xmaxvalue = SuperC->Getqvectormaxvalue(&xmaxvaluetemp,xmaxvaluetemp.count());
    double xminvalue = SuperC->Getqvectorminvalue(&xmaxvaluetemp,xmaxvaluetemp.count());
    double ymaxvalue = SuperC->Getqvectormaxvalue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = SuperC->Getqvectorminvalue(&yminvaluetemp,yminvaluetemp.count());
    Figureplotrescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Dutlist.count();i++)
    {
        Displaydatainfoapib(Dutlist.at(i),i,yminvalue - (ymaxvalue - yminvalue) / 10,Qt::black,6);
    }
}

/*  cal source data part plot;*/

void DataDialog::Interactionplot()
{
    QVector<double> ymaxvaluetemp = {};
    QVector<double> yminvaluetemp = {};
    Interactionvector = Appraiserchartvector;
    Xdata = SuperC->Arange(0,Dutlist.count(),1);
    for(int i = 0;i < Canvas->graphCount();i++)
    {
        Canvas->graph(i)->setData(Xdata,Interactionvector[i],true);
        Canvas->graph(i)->setPen(Colorvector.at(i));
        Canvas->graph(i)->setLineStyle(QCPGraph::LineStyle::lsLine);
        Canvas->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
        ymaxvaluetemp.append(SuperC->Getqvectormaxvalue(&Interactionvector[i],Interactionvector.at(i).count()));
        yminvaluetemp.append(SuperC->Getqvectorminvalue(&Interactionvector[i],Interactionvector.at(i).count()));
        Displaydatainfoapia(" --- " + Appraiserlist.at(i) + " --- ",0.85,0.15 + 0.05 * i,Colorvector.at(i));
    }
    double xmaxvalue = SuperC->Getqvectormaxvalue(&Xdata,Xdata.count());
    double xminvalue = SuperC->Getqvectorminvalue(&Xdata,Xdata.count());
    double ymaxvalue = SuperC->Getqvectormaxvalue(&ymaxvaluetemp,ymaxvaluetemp.count());
    double yminvalue = SuperC->Getqvectorminvalue(&yminvaluetemp,yminvaluetemp.count());
    Figureplotrescaleaxes(xmaxvalue,xminvalue,ymaxvalue,yminvalue);
    for(int i = 0;i < Dutlist.count();i++)
    {
        Displaydatainfoapib(Dutlist.at(i),i,yminvalue - (ymaxvalue - yminvalue) / 10,Qt::black,6);
    }
}

/*  cal source data interaction plot;*/

void DataDialog::Signaldaslot()
{
    Refresh();
}

/*  recevice display table end signal and start refresh;*/

void DataDialog::Signaldbslot(int rows,int columns)
{
    Rows = rows;
    Columns = columns;
    int size = Plugin->ui->tableWidget->horizontalHeader()->minimumSectionSize();
    SuperC->Settablewidgetitem(Rows,Columns,size,Plugin->ui->tableWidget);
}

/*  receive signal set tablewiget row and columns;*/

void DataDialog::Signaldcslot(int valuea,int cellcount,QStringList stringlist)
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

void DataDialog::Setprogressbar(int progressbarvalue,QString message)
{
    Progressbardialog->Setvaluemessage(progressbarvalue,message);
}

/*  receive signal set progressbar value and message;*/

void DataDialog::Signalsaslot()
{
    Plugin->ui->pushButton_2->setText("Edit");
    Plugin->ui->pushButton_2->setEnabled(true);
    Refresh();
}

/*  receive signal enable button;*/

void DataDialog::Signalraslot()
{
    Plugin->ui->pushButton->setEnabled(true);
}

/*  receive signal enable pushbutton;*/

DisplayTable::DisplayTable(QString strfilepath,QVector<QStringList>* csvqvectorstringlist)
{
    Strfilepath = strfilepath;
    Csvqvectorstringlist = csvqvectorstringlist;
    Init();
}

DisplayTable::~DisplayTable()
{

}

void DisplayTable::run()
{
    Getcsvfileinfo();
    Settablewidgetitem();
    emit Signalda();
    emit Signaldd(100,"(3/3)DisplayTable function run completed;");
}

void DisplayTable::Init()
{
    Objectinit();
}

void DisplayTable::Objectinit()
{
    SuperC = new SuperCore(this);
}

void DisplayTable::Getcsvfileinfo()
{
    QFile file(Strfilepath);
    QStringList bytetemplist;
    QVector<double> Columnsvector;
    Rows = 0;
    Columns = 0;
    emit Signaldd(99,"(1/3)start get csv file info...");
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
    Columns = SuperC->Getqvectormaxvalue(&Columnsvector,Rows);
    emit Signaldb(Rows,Columns);
}

/*  get csv file info;*/

void DisplayTable::Settablewidgetitem()
{
    for(int i = 0;i < Rows;i++)
    {
        int Columnscounts = Csvqvectorstringlist->at(i).count();
        emit Signaldc(i,Columnscounts,Csvqvectorstringlist->at(i));
        emit Signaldd(double(i + 1) / double(Rows) * 99,"(2/3)Settablewidgetitem function running...");
    }
}

/*  set table widget items;*/

SaveCell::SaveCell(QString csvfilepath,QTableWidget* tablewidget)
{
    Csvfilepath = csvfilepath;
    Tablewidget = tablewidget;
    Rows = Tablewidget->rowCount();
    Columns = Tablewidget->columnCount();
    Init();
}

void SaveCell::Init()
{
    Objectinit();
}

void SaveCell::Objectinit()
{
    SuperC = new SuperCore(this);
}

void SaveCell::run()
{
    Getcellinfo();
    SuperC->Writeonlyfile(Csvfilepath,Strcell);
    emit Signalsb(100,"(2/2)Save completed");
    emit Signalsa();
}

void SaveCell::Getcellinfo()
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
        emit Signalsb(double(i) / double(Rows) * 99,"(1/2)Getcellinfo running...");
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
    Init();
}

RefreshItems::~RefreshItems()
{

}

void RefreshItems::Init()
{
    Objectinit();
}

void RefreshItems::Objectinit()
{
    SuperC = new SuperCore(this);
}

void RefreshItems::run()
{
    Initrun();
    Finddataitem();
    Getdatabyitema();
    Analysisitems();
    emit Signalrb(100,"(4/4)RefreshItems function run completed");
    emit Signalra();
}

void RefreshItems::Initrun()
{
    Datalistvector->clear();
    Tdataitems.clear();
    Tdatalistvector.clear();
}

/*  paremeter init;*/

void RefreshItems::Finddataitem()
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
    emit Signalrb(99,"(1/4)Finddataitem function running...");
}

/*  find data items;*/

void RefreshItems::Getdatabyitema()
{
    QString strcell;
    for(int i = 0;i < *Columns;i++)
    {
        for(int j = 0;j < *Rows;j++)
        {
            strcell = Tablewidget->item(j,i)->text();
            Getdatabyitemb(strcell,i);
        }
        emit Signalrb(double(i) / double(*Columns) * 99,"(2/4)Finddataitem function running...");
    }
}

/*  add double data to list a;*/

void RefreshItems::Getdatabyitemb(QString strcell,int itemindex)
{
    bool boola;
    strcell.toDouble(&boola);
    if(boola)
    {
        Tdatalistvector[itemindex].append(strcell);
    }
}

/*  add double data to list b;*/

void RefreshItems::Analysisitems()
{
    int itemscount = Tdataitems.count();
    for(int i = 0;i < itemscount;i++)
    {
        Datalistvector->append(Tdatalistvector.at(i));
        Dataitems->append(Tdataitems.at(i));
        Datalistcount->append(QString::number(Tdatalistvector.at(i).count()));
        emit Signalrb(double(i) / double(itemscount) * 99,"(3/4)Finddataitem function running...");
    }
}

/*  analysis items;*/
