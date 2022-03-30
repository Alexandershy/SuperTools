#include "_littleskate_.h"

LittleSkate::LittleSkate(QGraphicsScene *scene,int colorindex,QTimer *timer)
{
    Scene = scene;
    Colorindex[0] = colorindex;
    Timer = timer;
    Init();

}

LittleSkate::~LittleSkate()
{

}

void LittleSkate::Init()
{
    Objectinit();
    Colorinit();
    Sceneinit();
    Timerinit();
}

void LittleSkate::Objectinit()
{
    SuperC = new SuperCore(this);
}

void LittleSkate::Colorinit()
{
    QStringList backgroundrgb = SuperC->Readonlyfile("./__depycache__/__cache__/__ini__/_backgroundcolor_.ini").split(",");
    Colorlist.append(QColor(backgroundrgb.at(0).toInt(),backgroundrgb.at(1).toInt(),backgroundrgb.at(2).toInt()));
    Colorlist.append(QColor(255 - backgroundrgb.at(0).toInt(),255 - backgroundrgb.at(1).toInt(),255 - backgroundrgb.at(2).toInt()));
}

/*  color bricks init*/

void LittleSkate::Sceneinit()
{
    Scenex = Scene->sceneRect().x();
    Sceney = Scene->sceneRect().y();
    Sceneheight = Scene->sceneRect().height();
    Scenewidth = Scene->sceneRect().width();
}

/*  init scene rect parameters;*/

void LittleSkate::Timerinit()
{
    connect(Timer,&QTimer::timeout,this,&LittleSkate::Timerslot);
    connect(Timer,&QTimer::timeout,this,&LittleSkate::Getbonus);
}

/*  start move thread;*/

QRectF LittleSkate::boundingRect() const
{
    return Littleskaterectf;
}

/*  reset littleball boundingrect;*/

QPainterPath LittleSkate::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

/*  reset littleball shape;*/

void LittleSkate::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *)
{
    painter->setPen(Colorlist.at(Colorindex.at(0)));
    painter->setBrush(Colorlist.at(Colorindex.at(0)));
    painter->drawRect(5,5,100,10);
}

/*  paint this in boundingrect;*/

void LittleSkate::advance(int phase)
{
    if (!phase)
    {
        return;
    }
    moveBy(Speed,0);
    Collisioncheck();
    Boundingcheck();
}

/*  run advance when scene run advance;*/

void LittleSkate::Speedlimit()
{
    if(Speed >= Speedlimitx)
    {
        Speed = Speedlimitx;
    }
    else if(Speed <= -Speedlimitx)
    {
        Speed = -Speedlimitx;
    }
    emit Signalsa(Speed);
}

/*  speed limit;*/

void LittleSkate::Collisioncheck()
{
    if(!Scene->collidingItems(this).isEmpty())
    {
        QGraphicsItem* collitem = Scene->collidingItems(this).at(0);
        Generateballbonus(collitem);
    }
}

/*  run collision check function;*/

void LittleSkate::Generateballbonus(QGraphicsItem* collitem)
{
    if(collitem->boundingRect().width() == 20 && Bonusball >= 50)
    {
        emit Signalsb(collitem->pos(),Speed,-0.35);
        Bonusball = 0;
    }
}

/*  generate ball every 10 seconds;*/

void LittleSkate::Boundingcheck()
{
    double Xpos = pos().x();
    double Xwidth = this->boundingRect().width();
    if(Xpos < Scenex)
    {
        Speed = 0;
        setPos(Scenex,y());
    }
    else if(Xpos + Xwidth > Scenewidth)
    {
        Speed = 0;
        setPos(Scenewidth - Xwidth,y());
    }
}

/*  generate ball every 10 seconds;*/

void LittleSkate::Timerslot()
{
    if(Direction == "Left")
    {
        Moveleft();
    }
    else if(Direction == "Right")
    {
        Moveright();
    }
    else if(Direction == "Stop")
    {
        Stop();
    }
    Speedlimit();
}

/*  improve or reduce speed;*/

void LittleSkate::Moveleft()
{
    if(Speed > 0)
    {
        Speed = Speed - 0.6;
    }
    else
    {
        Speed = Speed - 0.4;
    }
}

/*  move left;*/

void LittleSkate::Moveright()
{
    if(Speed < 0)
    {
        Speed = Speed + 0.6;
    }
    else
    {
        Speed = Speed + 0.4;
    }
}

/*  move right;*/

void LittleSkate::Stop()
{
    if(Speed > 0.6)
    {
        Speed = Speed - 0.6;
    }
    else if(Speed < -0.6)
    {
        Speed = Speed + 0.6;
    }
    else
    {
        Speed = 0;
    }
}

/*  stop move;*/

void LittleSkate::Refreshdirection(QByteArray direction)
{
    Direction = direction;
}

/*  run keyboard function;*/

void LittleSkate::Getbonus()
{
    if(Bonusball < 50)
    {
        Bonusball = Bonusball + 1;
    }
}

/*  reload bonus;*/
