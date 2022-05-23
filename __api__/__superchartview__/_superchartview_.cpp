#include "_superchartview_.h"

SuperChartView::SuperChartView(QWidget *parent)
    : QChartView(parent)
{
    setRenderHint(QPainter::Antialiasing, true);
    init();
}

SuperChartView::~SuperChartView()
{
    clearItems();
}

void SuperChartView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPoint startpoint = event->pos();
    recordStartPoint(startpoint);
    QPoint point(startpoint.x() + 1,startpoint.y());
    selectPoints(point);
    emit signalCa(Chart->mapToValue(event->pos(),Lineseriesvector.at(0)));
    emit signalCb();
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
            recordStartPoint(Point);
        }
        else
        {
            deselectAllPoint();
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
            selectPoints(Point);
            Rubberband->hide();
            emit signalCb();
        }
    }
}

/*  move to global pos;*/

void SuperChartView::wheelEvent(QWheelEvent *event)
{
    double factor = 1;
    QPointF point = event->position();
    QPoint pointdelta = event->angleDelta();
    QRectF plotarea = Chart->plotArea();
    QPointF centerpoint = plotarea.center();
    if(pointdelta.y() / abs(pointdelta.y()) > 0)
    {
        factor = 0.9;
        if(point.x() > plotarea.x())
        {
            plotarea.setWidth(plotarea.width() * factor);
        }
        if(point.y() < (plotarea.y() + plotarea.height()))
        {
            plotarea.setHeight(plotarea.height() * factor);
        }
    }
    else
    {
        factor = 1.1;
        if(point.x() > plotarea.x())
        {
            plotarea.setWidth(plotarea.width() * factor);
        }
        if(point.y() < (plotarea.y() + plotarea.height()))
        {
            plotarea.setHeight(plotarea.height() * factor);
        }
    }
    plotarea.moveCenter(2 * centerpoint - event->position() - (centerpoint - event->position()) / factor);
    Chart->zoomIn(plotarea);
}

/*  override wheel event;*/

void SuperChartView::init()
{
    objectInit();
    parameterInit();
    setDragMode();
}

/*  init;*/

void SuperChartView::objectInit()
{
    Chart = chart();
    Core = new SuperCore(this);
    Xaxis = new QValueAxis(this);
    Yaxis = new QValueAxis(this);
    connect(Yaxis,&QValueAxis::rangeChanged,this,&SuperChartView::changeProgressLinePoint);
    Rubberband = new QRubberBand(QRubberBand::Rectangle,this);
}

/*  object init;*/

void SuperChartView::parameterInit()
{
    Core->colorInit(&Backgroundcolor,&Fontcolor,&Concolor,&Strbackgroundcolor,&Strfontcolor,&Strconcolor);
    Xaxis->setRange(Initmin,Initmax);
    Yaxis->setRange(Initmin,Initmax);
    Xaxis->setLabelFormat("%.1f");
    Yaxis->setLabelFormat("%.1f");
    Chart->legend()->hide();
    Chart->setMargins(QMargins(1,1,1,1));
    Chart->layout()->setContentsMargins(1,1,1,1);
    Chart->addAxis(Xaxis,Qt::AlignBottom);
    Chart->addAxis(Yaxis,Qt::AlignLeft);
}

/*  parameter init;*/

//  line

void SuperChartView::setLine(int linenumber)
{
    clearItems();
    for(int i = 0;i < linenumber;i++)
    {
        Lineseriesvector.append(new QLineSeries(this));
        connect(Lineseriesvector.at(i),&QLineSeries::pointsReplaced,this,&SuperChartView::deselectAllPoint);
        Chart->addSeries(Lineseriesvector.at(i));
        Lineseriesvector.at(i)->attachAxis(Xaxis);
        Lineseriesvector.at(i)->attachAxis(Yaxis);
        Minvector.append({Initmin,Initmin});
        Maxvector.append({Initmax,Initmax});
        Lineseriesvector.at(i)->setUseOpenGL(true);
    }
}

/*  add series line;*/

void SuperChartView::setLineData(int seriesindex,QVector<QPointF> point)
{
    int pointcount = point.count();
    if(pointcount > 0)
    {
        Minvector[seriesindex] = Core->getVectorMinPointF(&point,pointcount);
        Maxvector[seriesindex] = Core->getVectorMaxPointF(&point,pointcount);
        Lineseriesvector.at(seriesindex)->replace(point);
    }
}

/*  set data;*/

void SuperChartView::setLineData(int seriesindex,QVector<double> *xvector,QVector<double> *yvector)
{
    QVector<QPointF> pointvector = {};
    int vectorcountx = xvector->count();
    int vectorcounty = yvector->count();
    if(vectorcountx == vectorcounty && vectorcountx > 0)
    {
        for(int i = 0;i < vectorcountx;i++)
        {
            pointvector.append({xvector->at(i),yvector->at(i)});
        }
        Minvector[seriesindex] = Core->getVectorMinPointF(&pointvector,vectorcountx);
        Maxvector[seriesindex] = Core->getVectorMaxPointF(&pointvector,vectorcountx);
        Lineseriesvector.at(seriesindex)->replace(pointvector);
    }
}

/*  set data;*/

void SuperChartView::setLineColor(QLineSeries* line,int index,Qt::PenStyle style)
{
    if(index % 2)
    {
        line->setPen(QPen(Concolor,1,style));
    }
    else
    {
        line->setPen(QPen(Backgroundcolor,1,style));
    }
}

/*  set series different color;*/

void SuperChartView::addProgressLine(int colorindex)
{
    QPointF lowerpoint(Xaxis->min(),Yaxis->min());
    QPointF upperpoint(Xaxis->min(),Yaxis->max());
    for(int i = 0;i < 3;i++)
    {
        Progresslinevector.append(new QLineSeries(this));
        Progresslinevector.at(i)->replace({lowerpoint,upperpoint});
        Chart->addSeries(Progresslinevector.at(i));
        Progresslinevector.at(i)->attachAxis(Xaxis);
        Progresslinevector.at(i)->attachAxis(Yaxis);
        setLineColor(Progresslinevector.at(i),colorindex,Qt::DashLine);
    }
}

/*  add progress line;*/

void SuperChartView::setProgressLinePos(int index,double pos)
{
    QVector<QPointF> pointvector = Progresslinevector.at(index)->points();
    pointvector[0].setX(pos);
    pointvector[1].setX(pos);
    Progresslinevector.at(index)->replace(pointvector);
}

/*  set progress line pos;*/

void SuperChartView::setLineDistance(double linedistance)
{
    Linedistance = linedistance;
}

/*  set distance;*/

//  bar

void SuperChartView::setBar(int barnumber)
{
    clearItems();
    for(int i = 0;i < barnumber;i++)
    {
        Barseriesvector.append(new QBarSeries(this));
        connect(Barseriesvector.at(i),&QBarSeries::countChanged,this,&SuperChartView::deselectAllPoint);
        Chart->addSeries(Barseriesvector.at(i));
        Barseriesvector.at(i)->attachAxis(Xaxis);
        Barseriesvector.at(i)->attachAxis(Yaxis);
        Minvector.append({Initmin,Initmin});
        Maxvector.append({Initmax,Initmax});
        Barseriesvector.at(i)->setUseOpenGL(true);
    }
}

/*  add bar chart;*/

void SuperChartView::setBarData(int barindex,QVector<QPointF> point)
{
    int pointcount = point.count();
    for(int i = 0;i < point.count();i++)
    {
        QBarSet *barsettemp = new QBarSet(QString::number(i),Barseriesvector.at(barindex));
        barsettemp->append(point.at(i).y());
        Barseriesvector.at(barindex)->append(barsettemp);
    }
    Minvector[barindex] = Core->getVectorMinPointF(&point,pointcount);
    Maxvector[barindex] = Core->getVectorMaxPointF(&point,pointcount);
}

/*  set bar data;*/

void SuperChartView::setBarData(int barindex,QVector<double> *xvector,QVector<double> *yvector)
{
    QVector<QPointF> pointvector = {};
    int vectorcountx = xvector->count();
    int vectorcounty = yvector->count();
    if(vectorcountx == vectorcounty)
    {
        for(int i = 0;i < xvector->count();i++)
        {
            QBarSet *barsettemp = new QBarSet(QString::number(i),Barseriesvector.at(barindex));
            barsettemp->append(yvector->at(i));
            Barseriesvector.at(barindex)->append(barsettemp);
        }
        Minvector[barindex] = Core->getVectorMinPointF(&pointvector,vectorcountx);
        Maxvector[barindex] = Core->getVectorMaxPointF(&pointvector,vectorcountx);
    }
}

/*  set bar data;*/

void SuperChartView::setBarColor(QBarSeries* bar,int barindex)
{
    QVector<QBarSet*> barset = bar->barSets();
    if(barindex % 2)
    {
        for(int i = 0;i < barset.count();i++)
        {
            barset.at(i)->setColor(Concolor);
        }
    }
    else
    {
        for(int i = 0;i < barset.count();i++)
        {
            barset.at(i)->setColor(Backgroundcolor);
        }
    }
}

/*  set series different color;*/

void SuperChartView::setBarWidth(int barindex,double width)
{
    Barseriesvector.at(barindex)->setBarWidth(width);
}

/*  set bar data;*/

//  scatter

void SuperChartView::setScatter(int scatternumber)
{
    clearItems();
    for(int i = 0;i < scatternumber;i++)
    {
        Scatterseriesvector.append(new QScatterSeries(this));
        connect(Scatterseriesvector.at(i),&QScatterSeries::pointsReplaced,this,&SuperChartView::deselectAllPoint);
        Chart->addSeries(Scatterseriesvector.at(i));
        Scatterseriesvector.at(i)->attachAxis(Xaxis);
        Scatterseriesvector.at(i)->attachAxis(Yaxis);
        Minvector.append({Initmin,Initmin});
        Maxvector.append({Initmax,Initmax});
        Scatterseriesvector.at(i)->setUseOpenGL(true);
    }
}

/*  add bar chart;*/

void SuperChartView::setScatterData(int scatterindex,QVector<QPointF> point)
{
    int pointcount = point.count();
    if(pointcount > 0)
    {
        Minvector[scatterindex] = Core->getVectorMinPointF(&point,pointcount);
        Maxvector[scatterindex] = Core->getVectorMaxPointF(&point,pointcount);
        Scatterseriesvector.at(scatterindex)->replace(point);
    }
}

/*  set scatter data;*/

void SuperChartView::setScatterData(int scatterindex,QVector<double> *xvector,QVector<double> *yvector)
{
    QVector<QPointF> pointvector = {};
    int vectorcountx = xvector->count();
    int vectorcounty = yvector->count();
    if(vectorcountx == vectorcounty && vectorcountx > 0)
    {
        for(int i = 0;i < vectorcountx;i++)
        {
            pointvector.append({xvector->at(i),yvector->at(i)});
        }
        Minvector[scatterindex] = Core->getVectorMinPointF(&pointvector,vectorcountx);
        Maxvector[scatterindex] = Core->getVectorMaxPointF(&pointvector,vectorcountx);
        Scatterseriesvector.at(scatterindex)->replace(pointvector);
    }
}

/*  set scatter data;*/

void SuperChartView::setScatterColor(QScatterSeries* scatter,int index,Qt::PenStyle style)
{
    if(index % 2)
    {
        scatter->setPen(QPen(Concolor,1,style));
    }
    else
    {
        scatter->setPen(QPen(Backgroundcolor,1,style));
    }
}

/*  set scatter color;*/

void SuperChartView::setScatterDistance(double scatterdistance)
{
    Scatterdistance = scatterdistance;
}

/*  set scatter distance;*/

void SuperChartView::rescaleAxes()
{
    if(Plotmode)
    {
        int seriescounts = Lineseriesvector.count();
        QPointF mintemp = Core->getVectorMinPointF(&Minvector,seriescounts);
        QPointF maxtemp = Core->getVectorMaxPointF(&Maxvector,seriescounts);
        Xaxis->setRange(mintemp.x(),maxtemp.x());
        Yaxis->setRange(mintemp.y(),maxtemp.y());
    }
}

/*  rescale axes;*/

void SuperChartView::setDragMode()
{
    Mousemode = 1;
}

/*  set drag mode;*/

void SuperChartView::setSelectMode()
{
    Mousemode = 0;
}

/*  set select mode;*/

void SuperChartView::enableWheel()
{
    Wheelmode = 1;
}

/*  enable wheel;*/

void SuperChartView::disableWheel()
{
    Wheelmode = 0;
}

/*  disable wheel;*/

void SuperChartView::setPlotMode(bool boola)
{
    Plotmode = boola;
}

/*  set auto plot or not;*/

void SuperChartView::recordStartPoint(QPointF point)
{
    if(Lineseriesvector.count())
    {
        Valuepoint = Chart->mapToValue(point,Lineseriesvector.at(0));
    }
}

/*  record start point;*/

void SuperChartView::selectPoints(QPointF point)
{
    int linecount = Lineseriesvector.count();
    if(linecount > 0)
    {
        QVector<int> pointvector = {};
        QPointF endpoint = Chart->mapToValue(point,Lineseriesvector.at(0));
        QVector<QPointF> valuevector = {Valuepoint,endpoint};
        int indexmax = Core->getVectorMaxPointF(&valuevector,valuevector.count()).x() * Linedistance;
        int indexmin = Core->getVectorMinPointF(&valuevector,valuevector.count()).x() * Linedistance;
        for(int i = indexmin;i < indexmax;i++)
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

void SuperChartView::deselectAllPoint()
{
    int linecount = Lineseriesvector.count();
    for(int i = 0;i < linecount;i++)
    {
        Lineseriesvector.at(i)->deselectAllPoints();
    }
}

/*  deselect points function;*/

void SuperChartView::changeProgressLinePoint(double min,double max)
{
    int count = Progresslinevector.count();
    for(int i = 0;i < count;i++)
    {
        QVector<QPointF> pointvector = Progresslinevector.at(i)->points();
        pointvector[0].setY(min);
        pointvector[1].setY(max);
        Progresslinevector.at(i)->replace(pointvector);
    }
}

/*  change progress line point range;*/

int SuperChartView::addText(double posx,double posy,QString text)
{
    int index = Textvector.count();
    QPointF point(width() * posx,height() * posy);
    Textvector.append(new QGraphicsSimpleTextItem(Chart));
    Textvector.at(index)->setText(text);
    Textvector.at(index)->setPos(point);
    return index;
}

/*  add text;*/

void SuperChartView::setText(int index,double posx,double posy,QString text)
{
    int count = Textvector.count();
    QPointF point(width() * posx,height() * posy);
    if(index < count)
    {
        Textvector.at(index)->setText(text);
        Textvector.at(index)->setPos(point);
    }
}

/*  set text;*/

void SuperChartView::clearItems()
{
    for(int i = 0;i < Lineseriesvector.count();i++)
    {
        Lineseriesvector.at(i)->deleteLater();
    }
    for(int i = 0;i < Progresslinevector.count();i++)
    {
        Progresslinevector.at(i)->deleteLater();
    }
    for(int i = 0;i < Textvector.count();i++)
    {
        delete Textvector.at(i);
    }
    Lineseriesvector.clear();
    Progresslinevector.clear();
    Textvector.clear();
}

/*  set distance;*/

