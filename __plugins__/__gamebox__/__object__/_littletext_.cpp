#include "_littletext_.h"

LittleText::LittleText(QString text,QFont font,QPointF pos,bool colorstatus,QVector<int> pointpos,QGraphicsScene * scene,QTimer *timer)
{
    Text = text;
    Font = font;
    Pos = pos;
    Colorstatus = colorstatus;
    Pointpos = pointpos;
    Scene = scene;
    Timer = timer;
    init();
}

LittleText::~LittleText()
{

}

void LittleText::init()
{
    objectInit();
    rectfInit();
    posInit();
    colorInit();
    timerInit();
}

void LittleText::objectInit()
{
    Core = new SuperCore(this);
}

void LittleText::rectfInit()
{
    Littletextrectf = QRectF(0,0,Font.pointSize() * Text.size() * 0.75,Font.pointSize() * 2);
    Distancex = Littletextrectf.width() / 2;
    Distancey = Littletextrectf.height() / 2;
}

/*  init little text rect;*/

void LittleText::posInit()
{
    setPos(Pos.x() - Pointpos.at(0) * Distancex,Pos.y() - Pointpos.at(1) * Distancey);
}

/*  init little text pos;*/

void LittleText::colorInit()
{
    QStringList backgroundrgb = Core->readOnlyFile("./__depycache__/__cache__/__ini__/_backgroundcolor_.ini").split(",");
    Colorlist.append(QColor(backgroundrgb[0].toInt(),backgroundrgb[1].toInt(),backgroundrgb[2].toInt()));
    Rectcolor.setRgb(255,255,255);
    Rectcolor.setAlpha(0);
}

/*  init little text color;*/

void LittleText::timerInit()
{
    if(Colorstatus == true)
    {
        connect(Timer,&QTimer::timeout,this,&LittleText::alphaColorTimerSlot);
    }
    connect(Timer,&QTimer::timeout,this,&LittleText::staticTimerSlot);
}

/*  init little text timer;*/

QRectF LittleText::boundingRect() const
{
    return Littletextrectf;
}

/*  reset LittleText boundingrect;*/

QPainterPath LittleText::shape() const
{
    QPainterPath path;
    path.addRect(Littletextrectf);
    return path;
}

/*  reset LittleText shape;*/

void LittleText::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *)
{
    painter->setPen(Rectcolor);
    painter->drawRect(Littletextrectf);
    painter->setPen(Colorlist.at(0));
    painter->setFont(Font);
    painter->drawText(Littletextrectf,Qt::AlignHCenter,Text,&Littletextrectf);
}

/*  paint this in boundingrect;*/

void LittleText::advance(int phase)
{
    if (!phase)
    {
        return;
    }
    if(Bonus == true)
    {
        moveBy(0,0.2);
        collisionCheck();
    }
}

/*  move delta;*/

void LittleText::collisionCheck()
{
    if(!Scene->collidingItems(this).isEmpty())
    {
        QList<QGraphicsItem*> collitems = Scene->collidingItems(this);
        for(int i = 0;i < collitems.count();i++)
        {
            if(collitems.at(i)->boundingRect().width() > 100)
            {
                emit signalTa(Text);
                delete this;
                break;
            }
        }
    }
    else if(pos().y() + boundingRect().height() > Scene->height())
    {
        delete this;
    }
}

/*  run little text collision check;*/

void LittleText::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

/*  ignore little text press event;*/

void LittleText::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

/*  ignore little text double click event;*/

void LittleText::setText(QString text)
{
    Text = text;
}

/*  set text function;*/

QString LittleText::getText()
{
    return Text;
}

void LittleText::addValue(QString name,int length,int value)
{
    Value = Value + value;
    if(Value < 0)
    {
        Value = 0;
    }
    Text = name + QString("%1").arg(Value,length, 10, QChar('0'));
}

/*  add score function;*/

int LittleText::getValue()
{
    return Value;
}

void LittleText::setBonus(bool boola)
{
    Bonus = boola;
}

void LittleText::alphaColorTimerSlot()
{
    Alphaindex[0] = Alphaindex.at(0) + 20;
    if(Alphaindex.at(0) >= 200)
    {
        Direction = -Direction;
        Alphaindex[0] = 0;
    }
    if(Direction == 1)
    {
        Colorlist[0].setAlpha(Alphaindex.at(0) % 200);
    }
    else
    {
        Colorlist[0].setAlpha(200 - Alphaindex.at(0) % 200);
    }
}

/*  display alpha text;*/

void LittleText::staticTimerSlot()
{
    update();
}

/*  update this;*/



