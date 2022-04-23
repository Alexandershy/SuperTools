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
    Setplotmode(!Plotmode);
    emit Signalca(Plotmode);
}

/*  rewrite double click event;*/

void SuperChartView::mousePressEvent(QMouseEvent *event)
{
    Pressed = true;
    if(Mousemode)
    {
        Point = event->globalPosition();
    }
    else
    {
        if(event->button() == Qt::LeftButton)
        {
            Point = event->pos();
            Rubberband->setGeometry(Point.x(),Point.y(),0,0);
            Rubberband->show();
            Recordstartpoint(Point);
        }
        else
        {
            Deselectallpoint();
        }
    }
}

/*  record this global pos;*/

void SuperChartView::mouseMoveEvent(QMouseEvent *event)
{
    if(Pressed)
    {
        switch(Mousemode)
        {
            case 0:
            {
                Rubberband->setGeometry(QRect(Point.toPoint(),event->pos()).normalized());
                break;
            }
            case 1:
            {
                int dx = Point.x() - event->globalPosition().x();
                int dy = event->globalPosition().y() - Point.y();
                Point = event->globalPosition();
                Chart->scroll(dx,dy);
                break;
            }
        }
    }
}

/*  move to this global pos;*/

void SuperChartView::mouseReleaseEvent(QMouseEvent *event)
{
    Pressed = false;
    if(Mousemode)
    {
        Point = event->globalPosition();
    }
    else
    {
        if(event->button() == Qt::LeftButton)
        {
            Point = event->pos();
            Selectpoints(Point);
            Rubberband->hide();
        }
    }
}

/*  move to global pos;*/

void SuperChartView::wheelEvent(QWheelEvent *event)
{
    Q_UNUSED(event);
}

/*  override wheel event;*/

void SuperChartView::Init()
{
    Objectinit();
    Parameterinit();
    Setdragmode();
}

/*  init;*/

void SuperChartView::Objectinit()
{
    Chart = chart();
    Core = new SuperCore(this);
    Xaxis = new QValueAxis(this);
    Yaxis = new QValueAxis(this);
    Rubberband = new QRubberBand(QRubberBand::Rectangle,this);
}

/*  object init;*/

void SuperChartView::Parameterinit()
{
    Core->Colorinit(&Backgroundcolor,&Fontcolor,&Concolor,&Strbackgroundcolor,&Strfontcolor,&Strconcolor);
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
        connect(Lineseriesvector.at(i),&QLineSeries::pointsReplaced,this,&SuperChartView::Deselectallpoint);
        Chart->addSeries(Lineseriesvector.at(i));
        Lineseriesvector.at(i)->attachAxis(Xaxis);
        Lineseriesvector.at(i)->attachAxis(Yaxis);
        Minvector.append({Initmin,Initmin});
        Maxvector.append({Initmax,Initmax});
        if(i)
        {
            Lineseriesvector.at(i)->setPen(QPen(Concolor,1,Qt::SolidLine));
        }
        else
        {
            Lineseriesvector.at(i)->setPen(QPen(Backgroundcolor,1,Qt::SolidLine));
        }
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

void SuperChartView::Setplotmode(bool boola)
{
    Plotmode = boola;
}

/*  set auto plot or not;*/

void SuperChartView::Recordstartpoint(QPointF point)
{
    if(Lineseriesvector.count())
    {
        Valuepoint = Chart->mapToValue(point,Lineseriesvector.at(0));
    }
}

/*  record start point;*/

void SuperChartView::Selectpoints(QPointF point)
{
    int linecount = Lineseriesvector.count();
    if(linecount)
    {
        QVector<int> pointvector = {};
        QPointF endpoint = Chart->mapToValue(point,Lineseriesvector.at(0));
        QVector<QPointF> valuevector = {Valuepoint,endpoint};
        QPointF pointmax = Core->Getqvectormaxpointf(&valuevector,valuevector.count());
        QPointF pointmin = Core->Getqvectorminpointf(&valuevector,valuevector.count());
        for(int i = pointmin.x();i < pointmax.x();i++)
        {
            pointvector.append(i);
        }
        for(int i = 0;i < linecount;i++)
        {
            Lineseriesvector.at(i)->selectPoints(pointvector);
        }
    }
}

/*  select points function;*/

void SuperChartView::Deselectallpoint()
{
    int linecount = Lineseriesvector.count();
    for(int i = 0;i < linecount;i++)
    {
        Lineseriesvector.at(i)->deselectAllPoints();
    }
}

/*  deselect points function;*/




