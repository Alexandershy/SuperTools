#ifndef _LITTLEBRICK__H
#define _LITTLEBRICK__H

#include <QPen>
#include <QBrush>
#include <QTimer>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class LittleBrick : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    LittleBrick(
            QGraphicsScene *scene,
            int colorindex,
            QTimer *timer);

    ~LittleBrick();

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;

    void advance(
            int phase) override;

private:

    QRectF Littlebrickrectf = QRectF(0,0,60,25);
    QGraphicsScene *Scene   = nullptr;
    int Sourcecolorindex    = 0;
    QList<QColor> Colorlist = {};
    QList<int> Colorindex   = {0};
    int Vectorindex         = 0;
    QTimer *Timer           = nullptr;

private slots:

    /*  mainfunction;*/

    void Init();

    void Colorinit();

    void Timerinit();

    void Timerslot();

signals:

    void Signalba(
            QPointF point);

    void Signalbb(
            int score);
};

#endif // _LITTLEBRICK__H
