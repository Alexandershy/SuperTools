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

public:

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;

    void advance(
            int phase) override;

    void moveToTarget(
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
    void init();

    void colorInit();

    void sceneInit();

    void timerInit();

    void speedLimit();

    void boundingCheck();

    void changeSpeedy();

    void collisionCheck();

    QPainterPath calRepeatCenter(
            QGraphicsItem *Collitem);

    void collidesItem(
            QPainterPath path,
            QGraphicsItem *Collitem);

    void collidesSkate(
            QPainterPath path);

    void firstCollides();

    void collidesBrick(
            QPainterPath path);

    void timerxSlot();

    void timerySlot();

signals:

    void signalBa();

    void signalBb(
            int score);
};

#endif // _LITTLEBALL__H
