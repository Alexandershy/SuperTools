#include "_littleskate_.h"

LittleSkate::LittleSkate(QGraphicsScene *scene,int colorindex,QTimer *timer)
{
    Scene = scene;
    Colorindex[0] = colorindex;
    Timer = timer;
    init();

}

LittleSkate::~LittleSkate()
{

}

void LittleSkate::init()
{
    objectInit();
    colorInit();
    sceneInit();
    timerInit();
}

void LittleSkate::objectInit()
{
    SuperC = new SuperCore(this);
}

void LittleSkate::colorInit()
{
    QStringList backgroundrgb = SuperC->readOnlyFile("./__depycache__/__cache__/__ini__/_backgroundcolor_.ini").split(",");
    Colorlist.append(QColor(backgroundrgb.at(0).toInt(),backgroundrgb.at(1).toInt(),backgroundrgb.at(2).toInt()));
    Colorlist.append(QColor(255 - backgroundrgb.at(0).toInt(),255 - backgroundrgb.at(1).toInt(),255 - backgroundrgb.at(2).toInt()));
}

/*  color bricks init*/

void LittleSkate::sceneInit()
{
    Scenex = Scene->sceneRect().x();
    Sceney = Scene->sceneRect().y();
    Sceneheight = Scene->sceneRect().height();
    Scenewidth = Scene->sceneRect().width();
}

/*  init scene rect parameters;*/

void LittleSkate::timerInit()
{
    connect(Timer,&QTimer::timeout,this,&LittleSkate::timerSlot);
    connect(Timer,&QTimer::timeout,this,&LittleSkate::getBonus);
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
    collisionCheck();
    boundingCheck();
}

/*  run advance when scene run advance;*/

void LittleSkate::speedLimit()
{
    if(Speed >= Speedlimitx)
    {
        Speed = Speedlimitx;
    }
    else if(Speed <= -Speedlimitx)
    {
        Speed = -Speedlimitx;
    }
    emit signalSa(Speed);
}

/*  speed limit;*/

void LittleSkate::collisionCheck()
{
    if(!Scene->collidingItems(this).isEmpty())
    {
        QGraphicsItem* collitem = Scene->collidingItems(this).at(0);
        generateBallBonus(collitem);
    }
}

/*  run collision check function;*/

void LittleSkate::generateBallBonus(QGraphicsItem* collitem)
{
    if(collitem->boundingRect().width() == 20 && Bonusball >= 50)
    {
        emit signalSb(collitem->pos(),Speed,-0.35);
        Bonusball = 0;
    }
}

/*  generate ball every 10 seconds;*/

void LittleSkate::boundingCheck()
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

void LittleSkate::timerSlot()
{
    if(Direction == "Left")
    {
        moveLeft();
    }
    else if(Direction == "Right")
    {
        moveRight();
    }
    else if(Direction == "Stop")
    {
        stop();
    }
    speedLimit();
}

/*  improve or reduce speed;*/

void LittleSkate::moveLeft()
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

void LittleSkate::moveRight()
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

void LittleSkate::stop()
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

void LittleSkate::refreshDirection(QByteArray direction)
{
    Direction = direction;
}

/*  run keyboard function;*/

void LittleSkate::getBonus()
{
    if(Bonusball < 50)
    {
        Bonusball = Bonusball + 1;
    }
}

/*  reload bonus;*/
