#ifndef _LITTLEBALL__H
#define _LITTLEBALL__H

#include <QPen>
#include <QBrush>
#include <QTimer>
#include <QThread>
#include <complex>
#include <QPainter>
#include <QDateTime>
#include <QGraphicsScene>
#include <QGraphicsItem>

class LittleBall : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    QList<double> Speedx        = {0};
    QList<double> Speedy        = {0};
    QRectF Littleballrectf      = QRectF(0,0,20,20);

public:

    LittleBall(
            QGraphicsScene *scene,
            QStringList *sceneinfolist,
            int colorindex,
            QTimer *timer);

    ~LittleBall();

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;

    void advance(
            int phase) override;

    void Movetotarget(
            QPointF point);

private:

    QGraphicsScene *Scene       = nullptr;
    double Scenex               = 0;
    double Sceney               = 0;
    double Sceneheight          = 0;
    double Scenewidth           = 0;
    QStringList *Sceneinfolist  = nullptr;
    QList<QColor> Colorlist     = {};
    QList<int> Colorindex       = {0};
    int Resetbonus              = 0;
    double Speedlimitx          = 1.5;
    double Speedlimity          = 1;
    QTimer *Timer               = nullptr;

private slots:
    /*  main function;*/

    void Init();

    void Colorinit();

    void Sceneinit();

    void Timerinit();

    void Speedlimit();

    void Boundingcheck();

    void Changespeedy();

    void Collisioncheck();

    QPainterPath Calrepeatcenter(
            QGraphicsItem *Collitem);

    void Collideswithitem(
            QPainterPath path,
            QGraphicsItem *Collitem);

    void Collidesskate(
            QPainterPath path);

    void Firstcollides();

    void Collidesbrick(
            QPainterPath path);

    void Timerxslot();

    void Timeryslot();

signals:

    void Signalba();

    void Signalbb(
            int score);
};

#endif // _LITTLEBALL__H
