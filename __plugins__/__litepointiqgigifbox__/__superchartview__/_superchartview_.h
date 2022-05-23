#ifndef _SUPERCHARTVIEW__H
#define _SUPERCHARTVIEW__H
#define _SUPERCHARTVIEW__EXPORT Q_DECL_EXPORT

#include <QLabel>
#include <QBarSet>
#include <QWidget>
#include <QPainter>
#include <QValueAxis>
#include <QChartView>
#include <QBarSeries>
#include <QLineSeries>
#include <QScatterSeries>
#include <QGraphicsLayout>
#include "__supercore__/_supercore_.h"

class _SUPERCHARTVIEW__EXPORT SuperChartView : public QChartView
{
    Q_OBJECT

public:

    SuperChartView(
        QWidget *parent = nullptr);

    ~SuperChartView();

public:

    QChart *Chart                                   = nullptr;
    QVector<QLineSeries*> Lineseriesvector          = {};
    QVector<QBarSeries*> Barseriesvector            = {};
    QVector<QScatterSeries*> Scatterseriesvector    = {};
    QValueAxis *Xaxis                               = nullptr;
    QValueAxis *Yaxis                               = nullptr;
    double Initmin                                  = 0;
    double Initmax                                  = 1;
    QVector<QPointF> Minvector                      = {};
    QVector<QPointF> Maxvector                      = {};
    QVector<QLineSeries*> Progresslinevector        = {};

public slots:

    void setLine(
        int linenumber);//line function;

    void setLineData(
        int seriesindex,
        QVector<QPointF> point);

    void setLineData(
        int seriesindex,
        QVector<double> *xvector,
        QVector<double> *yvector);

    void setLineColor(
        QLineSeries* line,
        int index,
        Qt::PenStyle style);

    void addProgressLine(
        int colorindex);

    void setProgressLinePos(
        int index,
        double pos);

    void setLineDistance(
        double linedistance);

    void setBar(
        int barnumber);//bar function;

    void setBarData(
        int barindex,
        QVector<QPointF> point);

    void setBarData(
        int barindex,
        QVector<double> *xvector,
        QVector<double> *yvector);

    void setBarColor(
        QBarSeries* bar,
        int barindex);

    void setBarWidth(
        int barindex,
        double width);

    void setScatter(
        int scatternumber);//scatter function;

    void setScatterData(
        int scatterindex,
        QVector<QPointF> point);

    void setScatterData(
        int scatterindex,
        QVector<double> *xvector,
        QVector<double> *yvector);

    void setScatterColor(
        QScatterSeries* scatter,
        int index,
        Qt::PenStyle style);

    void setScatterDistance(
        double scatterdistance);

    void rescaleAxes();//general function;

    void setDragMode();

    void setSelectMode();

    void enableWheel();

    void disableWheel();

    void setPlotMode(
        bool boola);

    int addText(
        double posx,
        double posy,
        QString text);

    void setText(
        int index,
        double posx,
        double posy,
        QString text);

    void clearItems();

protected:

    void mouseDoubleClickEvent(
        QMouseEvent *event);

    void mousePressEvent(
        QMouseEvent *event);

    void mouseMoveEvent(
        QMouseEvent *event);

    void mouseReleaseEvent(
        QMouseEvent *event);

    void wheelEvent(
        QWheelEvent *event);

private:

    SuperCore *Core                                 = nullptr;
    int Plotmode                                    = 1;
    int Mousemode                                   = 1;
    int Wheelmode                                   = 1;
    bool Pressed                                    = false;
    QPointF Point                                   = {};
    QColor Backgroundcolor                          = Qt::white;
    QColor Fontcolor                                = Qt::black;
    QColor Concolor                                 = Qt::white;
    QString Strbackgroundcolor                      = "";
    QString Strfontcolor                            = "";
    QString Strconcolor                             = "";
    QRubberBand *Rubberband                         = nullptr;
    QPointF Valuepoint                              = {};
    double Linedistance                             = 1;
    double Scatterdistance                          = 1;
    QVector<QGraphicsSimpleTextItem*> Textvector    = {};
    int Chartmode                                   = 0;

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void recordStartPoint(
        QPointF point);

    void selectPoints(
        QPointF point);

    void deselectAllPoint();

    void changeProgressLinePoint(
        double min,double max);

signals:

    void signalCa(
        QPointF point);

    void signalCb();

};

#endif // _SUPERCHARTVIEW__H
