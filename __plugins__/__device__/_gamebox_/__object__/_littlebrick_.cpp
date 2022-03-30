#include "_littlebrick_.h"

LittleBrick::LittleBrick(QGraphicsScene *scene,int colorindex,QTimer* timer)
{
    Scene = scene;
    Sourcecolorindex = colorindex;
    Colorindex[0] = colorindex;
    Timer = timer;
    Init();
}

LittleBrick::~LittleBrick()
{

}

void LittleBrick::Init()
{
    Colorinit();
    Timerinit();
}

void LittleBrick::Colorinit()
{
    Colorlist.append(Qt::red);
    Colorlist.append(Qt::red);
    Colorlist.append(Qt::yellow);
    Colorlist.append(Qt::green);
    Colorlist.append(Qt::cyan);
    Colorlist.append(Qt::blue);
    Colorlist.append(Qt::magenta);
    Colorlist.append(Qt::darkGray);
    Colorlist.append(Qt::black);
}

/*  color bricks init*/

void LittleBrick::Timerinit()
{
    connect(Timer,&QTimer::timeout,this,&LittleBrick::Timerslot);
}

/*  connect timer for update painter;*/

QRectF LittleBrick::boundingRect() const
{
    return Littlebrickrectf;
}

/*  reset LittleBrick boundingrect;*/

QPainterPath LittleBrick::shape() const
{
    QPainterPath path;
    path.addRect(Littlebrickrectf);
    return path;
}

/*  reset LittleBrick shape;*/

void LittleBrick::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *)
{
    painter->setPen(Colorlist.at(Colorindex.at(0)));
    painter->setBrush(Colorlist.at(Colorindex.at(0)));
    painter->drawRect(5,5,50,15);
}

/*  paint this in boundingrect;*/

void LittleBrick::advance(int phase)
{
    if(!phase)
    {
        return;
    }
    if(!Scene->collidingItems(this).isEmpty() && Colorindex.at(0) > 0)
    {
        QList<QGraphicsItem*> collitems = Scene->collidingItems(this);
        for(int i = 0;i < collitems.count();i++)
        {
            if(collitems.at(i)->boundingRect().width() == 20 && Colorindex.at(0) > 0)
            {
                Colorindex[0] = Colorindex.at(0) - 1;
                emit Signalbb(5);
            }
        }
    }
    else if(Colorindex.at(0) == 0)
    {
        emit Signalba(pos());
        emit Signalbb(10);
        delete this;
    }
}

/*  run advance when scene run advance;*/

void LittleBrick::Timerslot()
{
    if(Colorindex.at(0) < Sourcecolorindex)
    {
        this->update();
    }
}

/*  update this when timer out;*/
