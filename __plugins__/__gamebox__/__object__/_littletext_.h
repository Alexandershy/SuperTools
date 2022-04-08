#ifndef _LITTLETEXT__H
#define _LITTLETEXT__H

#include "__supercore__/_supercore_.h"
#include <QTimer>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

class LittleText : public QGraphicsTextItem
{
    Q_OBJECT

public:

    LittleText(
            QString text,
            QFont font,
            QPointF pos,
            bool colorstatus,
            QVector<int> pointpos,
            QGraphicsScene* scene,
            QTimer *timer);

    ~LittleText();

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;

    void advance(
            int phase) override;

    void Settext(
            QString text);

    QString Gettext();

    void Addvalue(
            QString name,
            int length,
            int value);

    int Getvalue();

    void Setbonus(
            bool boola);

protected:

    void mousePressEvent(
            QGraphicsSceneMouseEvent *event) override;

    void mouseDoubleClickEvent(
            QGraphicsSceneMouseEvent *event) override;

private:

    SuperCore *SuperC       = nullptr;
    QGraphicsScene *Scene   = nullptr;
    QRectF Littletextrectf  = QRectF(0,0,0,0);
    QTimer *Timer           = nullptr;
    QList<QColor> Colorlist = {};
    QList<int> Alphaindex   = {0};
    int Direction           = 1;
    QColor Rectcolor        = Qt::red;
    QFont Font              = {};
    QPointF Pos             = {0,0};
    QVector<int> Pointpos   = {0,0};
    int Distancex           = 0;
    int Distancey           = 0;
    bool Colorstatus        = false;
    bool Bonus              = false;
    QString Text            = "";
    int Value               = 0;

private slots:
    /*  mainfunction;*/
    void Init();

    void Objectinit();

    void Rectfinit();

    void Posinit();

    void Colorinit();

    void Timerinit();

    void Collisioncheck();

    void Alphacolortimerslot();

    void Statictimerslot();

signals:

    void Signalta(
            QString text);
};

#endif // _LITTLETEXT__H
