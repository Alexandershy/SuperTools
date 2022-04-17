#include "_superchartview_.h"

SuperChartView::SuperChartView(QWidget *parent)
    : QChartView(parent)
{
    Init();
}

SuperChartView::~SuperChartView()
{

}

void SuperChartView::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(Plotmode)
    {
        emit Signalca(Plotmode);
        Plotmode = 0;
    }
    else
    {
        emit Signalca(Plotmode);
        Plotmode = 1;
    }
}

/*  rewrite double click event;*/

void SuperChartView::mousePressEvent(QMouseEvent *event)
{
    if(Mousemode)
    {
        Point = event->globalPosition();
        Pressed = true;
    }
}

/*  record this global pos;*/

void SuperChartView::mouseMoveEvent(QMouseEvent *event)
{
    if(Pressed && Mousemode)
    {
        int dx = Point.x() - event->globalPosition().x();
        int dy = event->globalPosition().y() - Point.y();
        Point = event->globalPosition();
        Chart->scroll(dx,dy);
    }
}

/*  move to this global pos;*/

void SuperChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if(Mousemode)
    {
        Point = event->globalPosition();
        Pressed = false;
    }
}

/*  move to global pos;*/

void SuperChartView::Init()
{
    Objectinit();
    Parameterinit();
}

/*  init;*/

void SuperChartView::Objectinit()
{
    Chart = chart();
    Xaxis = new QValueAxis(this);
    Yaxis = new QValueAxis(this);
    Core = new SuperCore(this);
}

/*  object init;*/

void SuperChartView::Parameterinit()
{
    Xaxis->setRange(Initmin,Initmax);
    Yaxis->setRange(Initmin,Initmax);
    Chart->legend()->hide();
    Chart->setMargins(QMargins(1,1,1,1));
    Chart->layout()->setContentsMargins(1,1,1,1);    
    Chart->addAxis(Xaxis,Qt::AlignBottom);
    Chart->addAxis(Yaxis,Qt::AlignLeft);
}

/*  parameter init;*/

void SuperChartView::Addseries(int seriesnumber)
{
    for(int i = 0;i < seriesnumber;i++)
    {
        Lineseriesvector.append(new QLineSeries(this));
        Chart->addSeries(Lineseriesvector.at(i));
        Lineseriesvector.at(i)->attachAxis(Xaxis);
        Lineseriesvector.at(i)->attachAxis(Yaxis);
        Minvector.append({Initmin,Initmin});
        Maxvector.append({Initmax,Initmax});
    }
}

/*  add series line;*/

void SuperChartView::Setdata(int seriesindex,QVector<QPointF> point)
{
    int pointcount = point.count();
    if(pointcount)
    {
        Minvector[seriesindex] = Core->Getqvectorminpointf(&point,pointcount);
        Maxvector[seriesindex] = Core->Getqvectormaxpointf(&point,pointcount);
        Lineseriesvector.at(seriesindex)->replace(point);
    }
}

/*  set data;*/

void SuperChartView::Rescaleaxes()
{
    if(Plotmode)
    {
        int seriescounts = Lineseriesvector.count();
        QPointF mintemp = Core->Getqvectorminpointf(&Minvector,seriescounts);
        QPointF maxtemp = Core->Getqvectormaxpointf(&Maxvector,seriescounts);
        Xaxis->setRange(mintemp.x(),maxtemp.x());
        Yaxis->setRange(mintemp.y(),maxtemp.y());
    }
}

/*  rescale axes;*/

void SuperChartView::Setdragmode()
{
    Mousemode = 1;
}

/*  set drag mode;*/

void SuperChartView::Setselectmode()
{
    Mousemode = 0;
}

/*  set select mode;*/

void SuperChartView::Enablewheel()
{
    Wheelmode = 1;
}

/*  enable wheel;*/

void SuperChartView::Disablewheel()
{
    Wheelmode = 0;
}

/*  disable wheel;*/


