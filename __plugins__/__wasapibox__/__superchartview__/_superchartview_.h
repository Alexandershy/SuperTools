#ifndef _SUPERCHARTVIEW__H
#define _SUPERCHARTVIEW__H
#define _SUPERCHARTVIEW__EXPORT Q_DECL_EXPORT

#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QValueAxis>
#include <QChartView>
#include <QLineSeries>
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

    QChart *Chart                               = nullptr;
    QVector<QLineSeries*> Lineseriesvector      = {};
    QValueAxis *Xaxis                           = nullptr;
    QValueAxis *Yaxis                           = nullptr;
    double Initmin                              = 0;
    double Initmax                              = 1;
    QVector<QPointF> Minvector                  = {};
    QVector<QPointF> Maxvector                  = {};

public slots:

    void Addseries(
        int seriesnumber);

    void Setdata(
        int seriesindex,
        QVector<QPointF> point);

    void Rescaleaxes();

    void Setdragmode();

    void Setselectmode();

    void Enablewheel();

    void Disablewheel();

    void Setplotmode(
        bool boola);

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

    SuperCore *Core             = nullptr;
    int Plotmode                = 1;
    int Mousemode               = 1;
    int Wheelmode               = 1;
    bool Pressed                = false;
    QPointF Point               = {};
    QColor Backgroundcolor      = Qt::white;
    QColor Fontcolor            = Qt::black;
    QColor Concolor             = Qt::white;
    QString Strbackgroundcolor  = "";
    QString Strfontcolor        = "";
    QString Strconcolor         = "";
    QRubberBand *Rubberband     = nullptr;
    QPointF Valuepoint          = {};

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

    void Recordstartpoint(
        QPointF point);

    void Selectpoints(
        QPointF point);

    void Deselectallpoint();

signals:

    void Signalca(
        int plotmode);

};

#endif // _SUPERCHARTVIEW__H
