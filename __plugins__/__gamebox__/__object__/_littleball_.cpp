#include "_littleball_.h"

LittleBall::LittleBall(QGraphicsScene *scene,QStringList *sceneinfolist,int colorindex,QTimer *timer)
{
    Scene = scene;
    Sceneinfolist = sceneinfolist;
    Colorindex[0] = colorindex;
    Timer = timer;
    init();
}

LittleBall::~LittleBall()
{

}

void LittleBall::init()
{
    colorInit();
    sceneInit();
    timerInit();
}

void LittleBall::colorInit()
{
    QColor orange(255,170,0);
    Colorlist.append(Qt::red);
    Colorlist.append(orange);
    Colorlist.append(Qt::yellow);
    Colorlist.append(Qt::green);
    Colorlist.append(Qt::cyan);
    Colorlist.append(Qt::blue);
    Colorlist.append(Qt::magenta);
}

/*  init little ball colorlist;*/

void LittleBall::sceneInit()
{
    Scenex = Scene->sceneRect().x();
    Sceney = Scene->sceneRect().y();
    Sceneheight = Scene->sceneRect().height();
    Scenewidth = Scene->sceneRect().width();
}

/*  init scene rect parameters;*/

void LittleBall::timerInit()
{
    connect(Timer,&QTimer::timeout,this,&LittleBall::timerxSlot);
    connect(Timer,&QTimer::timeout,this,&LittleBall::timerySlot);
}

/*  connect timer for little ball run in control speed;*/

QRectF LittleBall::boundingRect() const
{
    return Littleballrectf;
}

/*  reset LittleBall boundingrect;*/

QPainterPath LittleBall::shape() const
{
    QPainterPath path;
    path.addEllipse(Littleballrectf);
    return path;
}

/*  reset LittleBall shape;*/

void LittleBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *)
{
    painter->setPen(Colorlist.at(Colorindex.at(0)));
    painter->setBrush(Colorlist.at(Colorindex.at(0)));
    painter->drawEllipse(4,4,12,12);
}

/*  paint this in boundingrect;*/

void LittleBall::advance(int phase)
{
    if (!phase)
    {
        return;
    }
    speedLimit();
    moveBy(Speedx.at(0),Speedy.at(0));
    collisionCheck();
    boundingCheck();
}

/*  run advance when scene run advance;*/

void LittleBall::speedLimit()
{
    double speedx = Speedx.at(0);
    int pnnumber = speedx / abs(speedx);
    if(speedx > Speedlimitx || speedx < -Speedlimitx)
    {
        Speedx[0] = pnnumber * Speedlimitx;
    }
}

/*  set little ball speedx limit;*/

void LittleBall::collisionCheck()
{
    if(!Scene->collidingItems(this).isEmpty())
    {
        QGraphicsItem* Collitem = Scene->collidingItems(this).at(0);
        QPainterPath path = calRepeatCenter(Collitem);
        collidesItem(path,Collitem);
    }
}

/*  run little ball collision check;*/

QPainterPath LittleBall::calRepeatCenter(QGraphicsItem* collitem)
{
    QPainterPath path;
    QPainterPath temppath = collitem->shape();
    temppath.translate(collitem->pos());
    path.addEllipse(Littleballrectf);
    path.translate(pos());
    path &= temppath;
    path.translate(-this->pos().x(),-this->pos().y());
    return path;
}

/*  cal collision path center;*/

void LittleBall::collidesItem(QPainterPath path,QGraphicsItem* collitem)
{
    double width = collitem->boundingRect().width();
    if(width == 110)
    {
        collidesSkate(path);
        Resetbonus = 1;
        emit signalBb((Resetbonus + abs(Speedx.at(0)) + abs(Speedy.at(0))) * 5);
    }
    else if(width == 60)
    {
        collidesBrick(path);
        Resetbonus = Resetbonus + 1;
        emit signalBb((Resetbonus + abs(Speedx.at(0)) + abs(Speedy.at(0))) * 10);
    }
}

/*  run collides with items function;*/

void LittleBall::collidesSkate(QPainterPath path)
{
    double x = path.boundingRect().center().x();
    double y = path.boundingRect().center().y();
    if(x < 7)
    {
        Speedx[0] = abs(Speedx.at(0)) + Sceneinfolist->at(0).toDouble();
    }
    else if(x > 13)
    {
        Speedx[0] = -abs(Speedx.at(0)) + Sceneinfolist->at(0).toDouble();
    }
    if(y < 7 || y > 13)
    {
        Speedx[0] = Speedx.at(0) + Sceneinfolist->at(0).toDouble() / 4;
        Speedy[0] =  -Speedy.at(0);
        if(Resetbonus == 0)
        {
            firstCollides();
        }
    }
}

/*  run collides with skate function;*/

void LittleBall::firstCollides()
{
    double time = QDateTime::currentDateTime().toString("zzz").toDouble();
    Speedx[0] = sin(time);
}

/*  change speedx when first collides happened;*/

void LittleBall::collidesBrick(QPainterPath path)
{
    double x = path.boundingRect().center().x();
    double y = path.boundingRect().center().y();
    if(x < 7)
    {
        Speedx[0] = abs(Speedx.at(0));
    }
    else if(x > 13)
    {
        Speedx[0] = -abs(Speedx.at(0));
    }
    if(y < 7 || y > 13)
    {
        Speedy[0] =  -Speedy.at(0);
        if(Resetbonus == 0)
        {
            firstCollides();
        }
    }
}

/*  run collides with brick function;*/

void LittleBall::boundingCheck()
{
    double Xpos = pos().x();
    double Ypos = pos().y();
    double Xwidth = this->boundingRect().width();
    double Yheight = this->boundingRect().height();
    if(Xpos < Scenex)
    {
        Speedx[0] = abs(Speedx.at(0));
        changeSpeedy();
    }
    else if(Xpos + Xwidth > Scenewidth)
    {
       Speedx[0] = -abs(Speedx.at(0));
       changeSpeedy();
    }
    if(Ypos < Sceney)
    {
       Speedy[0] = abs(Speedy.at(0));
    }
    else if(Ypos + Yheight > Sceneheight)
    {
        emit signalBa();
        delete this;
    }
}

/*  change little ball speed or delete this when arrive scene bounding;*/

void LittleBall::changeSpeedy()
{
    if(Speedy.at(0) == 0)
    {
        Speedy[0] = -abs(Speedx.at(0));
    }
}

/*  if speedy is 0,change its speed when bounding check;*/

void LittleBall::moveToTarget(QPointF point)
{
    double speedtempx = point.x() - pos().x();
    double speedtempy = point.y() - pos().y();
    int pnnumberx = speedtempx / abs(speedtempx);
    int pnnumbery = speedtempy / abs(speedtempy);
    double speedxa = abs(speedtempx / speedtempy);
    double speedyb = abs(speedtempy / speedtempx);
    if(speedxa < 1)
    {
        Speedx[0] = speedxa * pnnumberx;
        Speedy[0] = pnnumbery;
    }
    else
    {
        Speedx[0] = pnnumberx;
        Speedy[0] = speedyb * pnnumbery;
    }
}

/*  cal point and pos distance,and change this speed;*/

void LittleBall::timerxSlot()
{
    double speedx = Speedx.at(0);
    if(speedx > 1)
    {
        Speedx[0] = Speedx.at(0) - 0.1;
    }
    else if(speedx < -1)
    {
        Speedx[0] = Speedx.at(0) + 0.1;
    }
}

/*  keep speedx at little than 1*/

void LittleBall::timerySlot()
{
    double speed = Speedy.at(0);
    if(speed > 0 && speed < Speedlimity)
    {
        Speedy[0] = Speedy.at(0) + 0.001;
    }
    else if(speed < 0 && speed > -Speedlimity)
    {
        Speedy[0] = Speedy.at(0) - 0.001;
    }
}

/*  keep speedy on bigger but not than 1;*/

