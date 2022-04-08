#ifndef _LITTLESKATE__H
#define _LITTLESKATE__H

#include "__supercore__/_supercore_.h"
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QTimer>
#include <QPainter>
#include <QDateTime>
#include <QGraphicsItem>
#include <QGraphicsScene>

class LittleSkate : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    LittleSkate(
            QGraphicsScene *scene,
            int colorindex,
            QTimer *timer);

    ~LittleSkate();

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;

    void advance(
            int phase) override;

    void Refreshdirection(
            QByteArray direction);

private:

    QPoint Point            = {0,0};
    double Speed            = 0;
    double Speedlimitx      = 1;
    QByteArray Direction    = "Stop";
    QGraphicsScene *Scene   = nullptr;
    SuperCore *SuperC       = nullptr;
    double Scenex           = 0;
    double Sceney           = 0;
    double Sceneheight      = 0;
    double Scenewidth       = 0;
    QRectF Littleskaterectf = QRectF(0,0,110,20);
    QList<QColor> Colorlist = {};
    QList<int> Colorindex   = {0};
    QTimer *Timer           = nullptr;

    /*  bonus*/
    int Bonusball           = 0;

private slots:
    /*  mainfunction;*/

    void Init();

    void Objectinit();

    void Colorinit();

    void Sceneinit();

    void Timerinit();

    void Boundingcheck();

    void Collisioncheck();

    void Speedlimit();

    void Moveleft();

    void Moveright();

    void Stop();

    void Timerslot();

    /*  bonus*/
    void Generateballbonus(
            QGraphicsItem* collitem);

    void Getbonus();

signals:
    void Signalsa(
            double speed);

    void Signalsb(
            QPointF point,
            double speedx,
            double speedy);

};

#endif // _LITTLESKATE__H
