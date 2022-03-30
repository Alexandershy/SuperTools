#include "_hitbricksscene_.h"

HitBricksScene::HitBricksScene(QGraphicsScene *parent,QGraphicsView* view)
    : QGraphicsScene(parent)
{
    View = view;
    setSceneRect(0,0,View->width() - 5,View->height() - 5);
    setItemIndexMethod(QGraphicsScene::NoIndex);
    Init();
}

HitBricksScene::~HitBricksScene()
{
    SuperC->Deleteobject(Refreshscene);
    SuperC->Deleteobject(Onesecond);
    SuperC->Deleteobject(Itemtimer);
    clear();
}

void HitBricksScene::keyPressEvent(QKeyEvent *event)
{
    if(Started == 0)
    {

    }
    else if(Started == 1)
    {
        switch (event->key())
        {
            case Qt::Key_W:
            {
                Movestoppointer(1);
                break;
            }
            case Qt::Key_S:
            {
                Movestoppointer(-1);
                break;
            }
            case Qt::Key_A:
            {
                Selectyesorquit();
                break;
            }
        }
    }
    else if(Started == 2)
    {
        switch (event->key())
        {
            case Qt::Key_L:
            {
                Skatevector.at(0)->Refreshdirection("Right");
                break;
            }
            case Qt::Key_J:
            {
                Skatevector.at(0)->Refreshdirection("Left");
                break;
            }
            case Qt::Key_S:
            {
                movebulletpointer(1);
                break;
            }
            case Qt::Key_W:
            {
                movebulletpointer(-1);
                break;
            }
            case Qt::Key_A:
            {
                Firebullets();
                break;
            }
        }
    }
}

/*  this scene key press function;*/

void HitBricksScene::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        int keyvalue = event->key();
        if(Started == 0)
        {
            Startplay();
        }
        else if(Started == 1)
        {
            switch (keyvalue)
            {
                case Qt::Key_Escape:
                {
                    Resume();
                    break;
                }
            }
        }
        else if(Started == 2)
        {
            switch (keyvalue)
            {
                case Qt::Key_L:
                {
                    Skatevector.at(0)->Refreshdirection("Stop");
                    break;
                }
                case Qt::Key_J:
                {
                    Skatevector.at(0)->Refreshdirection("Stop");
                    break;
                }
                case Qt::Key_Escape:
                {
                    Stopplayapi("Continues?","Yes","Quit");
                    break;
                }
            }
        }
    }
}

/*  this scene key release function;*/

void HitBricksScene::Init()
{
    Objectinit();
    Inittimer();
    Inittitle =         new LittleText("Hit Bricks V1.01",          Setfont("Microsoft Yahei",true,false,false,false,50),QPointF(sceneRect().width() / 2,sceneRect().height() * 0.3),           false,  {1,1},this,Itemtimer);
    Inittext =          new LittleText("Press Any Key Continue",    Setfont("Microsoft Yahei",true,false,false,false,15),QPointF(sceneRect().width() / 2,sceneRect().height() * 0.85),          true,   {1,1},this,Itemtimer);
    Scenemaxfps =       new LittleText("MAXFPS: 000",               Setfont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().x(),sceneRect().y()),                              false,  {0,0},this,Itemtimer);
    Health =            new LittleText("Health: 00",                Setfont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width(),sceneRect().y()),                          false,  {2,0},this,Itemtimer);
    Yes =               new LittleText("Yes",                       Setfont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 2,sceneRect().height() / 2 + 50),        false,  {1,1},this,Itemtimer);
    Quit =              new LittleText("Quit",                      Setfont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 2,sceneRect().height() / 2 + 100),       false,  {1,1},this,Itemtimer);
    Continuepointer =   new LittleText("👈",                        Setfont("Microsoft Yahei",true,false,false,false,15),QPointF(sceneRect().width() / 2 + 30,sceneRect().height() / 2 + 35),   false,  {0,0},this,Itemtimer);
    Skatespeed =        new LittleText("SPEED: 0000",               Setfont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() * 3 / 4,sceneRect().y()),                  false,  {1,0},this,Itemtimer);
    Score =             new LittleText("SCORE: 0000000000",         Setfont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 4,sceneRect().y()),                      false,  {1,0},this,Itemtimer);
    Countdown =         new LittleText("Level000: 00000",           Setfont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 2,sceneRect().y()),                      false,  {1,0},this,Itemtimer);
    Endtext =           new LittleText("text",                      Setfont("Microsoft Yahei",true,false,false,false,30),QPointF(sceneRect().width() / 2,sceneRect().height() / 2),             false,  {1,1},this,Itemtimer);
    addItem(Inittitle);
    addItem(Inittext);
    addItem(Scenemaxfps);
}

/*  creat init scene;*/

void HitBricksScene::Objectinit()
{
    SuperC = new SuperCore(this);
}

/*  object init;*/

void HitBricksScene::Inittimer()
{
    Refreshscene = new QTimer(this);
    Refreshscene->setInterval(2);
    Refreshscene->setTimerType(Qt::PreciseTimer);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::advance);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::Addmaxfps);
    Refreshscene->start();
    Onesecond = new QTimer(this);
    Onesecond->setInterval(1000);
    connect(Onesecond,&QTimer::timeout,this,&HitBricksScene::Resetfps);
    Onesecond->start();
    Itemtimer = new QTimer(this);
    Itemtimer->setInterval(100);
    Itemtimer->start();
}

/*  init scene timer;*/

QFont HitBricksScene::Setfont(QString family,bool bold,bool overline,bool underline,bool italic,int pointsize)
{
    Font.setFamily(family);
    Font.setBold(bold);
    Font.setOverline(overline);
    Font.setUnderline(underline);
    Font.setItalic(italic);
    Font.setPointSize(pointsize);
    return Font;
}

/*  set and return this font;*/

void HitBricksScene::Startplay()
{
    removeItem(Inittitle);
    removeItem(Inittext);
    Initobjects();
    Started = 2;
}

/*  set and return this font;*/

void HitBricksScene::Initobjects()
{
    Addtime(1000);
    connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Reducetime);
    addItem(Skatespeed);
    addItem(Score);
    addItem(Health);
    addItem(Countdown);
    Initskatevector();
    Initballvector();
    Initbrickvector();
    Initbulletvector();
}

/*  creat init object;*/

void HitBricksScene::Initskatevector()
{
    for(int i = 0;i < Player;i++)
    {
        Skatevector.append(new LittleSkate(this,i % 2,Itemtimer));
        addItem(Skatevector.at(i));
        Skatevector.at(i)->setPos(sceneRect().width() / 2,sceneRect().height() * 0.9);
        connect(Skatevector.at(i),&LittleSkate::Signalsa,this,&HitBricksScene::Refreshskatespeed);
        connect(Skatevector.at(i),&LittleSkate::Signalsb,this,&HitBricksScene::Generateball);
    }
}

/*  creat init skate;*/

void HitBricksScene::Initballvector()
{
    Addhealth(4);
    Reducehealth();
}

/*  creat init health and ball;*/

LittleBall* HitBricksScene::Addballbyhealth(int health)
{
    LittleBall *newball = new LittleBall(this,&Sceneinfolist,health % 7,Itemtimer);
    addItem(newball);
    newball->setPos(sceneRect().width() - 20,sceneRect().y() + 20);
    connect(newball,&LittleBall::Signalba,this,&HitBricksScene::Reducehealth);
    connect(newball,&LittleBall::Signalbb,this,&HitBricksScene::Addscore);
    return newball;
}

/*  creat ball;*/

void HitBricksScene::Initbrickvector()
{
    Addbricks(Levelbricks.at(Level));
}

/*  creat init level;*/

void HitBricksScene::Initbulletvector()
{
    Bulletpointer = new LittleText("👈",Setfont("Microsoft Yahei",true,false,false,false,8),QPointF(sceneRect().x() + 40,30 + sceneRect().y()),false,{0,0},this,Itemtimer);
    addItem(Bulletpointer);
    for(int i = 0;i < Bulletnamevector.count();i++)
    {
        Bulletvector.append(new LittleText(Bulletnamevector.at(i) + ": 00",Setfont("Microsoft Yahei",true,false,false,false,8),QPointF(sceneRect().x(),30 + sceneRect().y() + 15 * i),false,{0,0},this,Itemtimer));
        addItem(Bulletvector.at(i));
    }
}

/*  creat init bulletvector;*/

void HitBricksScene::Addbullet(int value)
{
    int bulletindex = Maxfps % Bulletvector.count();
    Bulletvector.at(bulletindex)->Addvalue(Bulletnamevector.at(bulletindex) + ": ",2,Maxfps % 5 + int(value / 5));
}

void HitBricksScene::Addmaxfps()
{
    Maxfps = Maxfps + 1;
}

/*  cal fps;*/

void HitBricksScene::Resetfps()
{
    Scenemaxfps->Settext("MAXFPS: " + QString("%1").arg(Maxfps,3, 10, QChar('0')));
    Maxfps = 0;
}

/*  reset fps value as 0;*/

void HitBricksScene::Refreshskatespeed(double speed)
{
    Skatespeed->Settext("SPEED: " + QString("%1").arg(int(abs(speed) * 1000),4, 10, QChar('0')));
    Sceneinfolist[0] = QString::number(speed);
}

/*  display skate speed;*/

void HitBricksScene::Addtime(int time)
{
    Countdown->Addvalue("Level" + QString("%1").arg(Level,3,10,QChar('0')) + ": ",5,time);
}

/*  init countdown time;*/

void HitBricksScene::Reducetime()
{
    Countdown->Addvalue("Level" + QString("%1").arg(Level,3,10,QChar('0')) + ": ",5,-1);
    if(Countdown->Getvalue() < 1)
    {
        Stopplayapi("Game Over","Retry","Quit");
    }
}

/*  countdown time by timer;*/

void HitBricksScene::Addscore(int score)
{
    Score->Addvalue("SCORE: ",10,score);
}

/*  add score;*/

void HitBricksScene::Reducehealth()
{
    Runningball = Runningball - 1;
    if(Runningball == 0)
    {
        Addhealth(-1);
        if(Health->Getvalue() > 0)
        {
            Addballbyhealth(Health->Getvalue())->Speedy[0] = 0.35;
            Runningball = Runningball + 1;
        }
        else
        {
            Stopplayapi("Game Over","Retry","Quit");
        }
    }
}

/*  if no running ball ,reduce health and new ball at righttop;*/

void HitBricksScene::Stopplayapi(QString texta,QString textb,QString textc)
{
    Endtext->Settext(texta);
    Yes->Settext(textb);
    Quit->Settext(textc);
    addItem(Endtext);
    addItem(Yes);
    addItem(Quit);
    addItem(Continuepointer);
    disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Reducetime);
    disconnect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::advance);
    disconnect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::Addmaxfps);
    disconnect(Onesecond,&QTimer::timeout,this,&HitBricksScene::Resetfps);
    Started = 1;
}

/*  stop play api;*/

void HitBricksScene::Resume()
{
    removeItem(Endtext);
    removeItem(Yes);
    removeItem(Quit);
    removeItem(Continuepointer);
    connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Reducetime);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::advance);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::Addmaxfps);
    connect(Onesecond,&QTimer::timeout,this,&HitBricksScene::Resetfps);
    Started = 2;
}

/*  resume play;*/

void HitBricksScene::Movestoppointer(int step)
{
    QPointF pointa(sceneRect().width() / 2 + 30,sceneRect().height() / 2 + 35);
    QPointF pointb(sceneRect().width() / 2 + 30,sceneRect().height() / 2 + 85);
    if(step > 0)
    {
        Continuepointer->setPos(pointa);
    }
    else
    {
        Continuepointer->setPos(pointb);
    }
}

/*  move stop pointer;*/

void HitBricksScene::Selectyesorquit()
{
    if(Continuepointer->pos().y() < sceneRect().height() / 2 + 60 && Endtext->Gettext() == "Continues?")
    {
        Resume();
    }
    else if(Continuepointer->pos().y() < sceneRect().height() / 2 + 60 && Endtext->Gettext() == "Endless level?")
    {
        Resume();
        Addhealth(1);
        Addendlessbricks();
        Addscore(1000);
        Addtime(1000);
        Endless = true;
    }
    else if(Continuepointer->pos().y() < sceneRect().height() / 2 + 60 && Endtext->Gettext() == "Game Over")
    {
        Resume();
        Retry();
    }
    else
    {
        emit Signalsa();
    }
}

/*  select yes or quit;*/

void HitBricksScene::Levelupanimationa()
{
    Scenespeed = Scenespeed + 1;
    if(Scenespeed == 3)
    {
        Endtext->Settext("Level" + QString::number(Level) + " Clear");
        addItem(Endtext);
        Level = Level + 1;
    }
    else if(Scenespeed < 10)
    {
        Refreshscene->setInterval(Scenespeed);
    }
    else if(Scenespeed >= 10)
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Levelupanimationa);
        connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Levelupanimationb);
    }
}

/*  enter next level animation step a;*/

void HitBricksScene::Levelupanimationb()
{
    if(Scenespeed > 2)
    {
        Scenespeed = Scenespeed - 1;
        Refreshscene->setInterval(Scenespeed);
    }
    else if(Scenespeed == 2)
    {
        Levelup();
    }
}

/*  enter next level animation step b;*/

void HitBricksScene::Levelup()
{
    disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Levelupanimationb);
    removeItem(Endtext);
    Addhealth(1);
    Addscore(1000);
    Addtime(1000);
    Addbullet(Level);
    if(Level + 1 <= Levelbricks.count())
    {
        Addbricks(Levelbricks.at(Level));
    }
    else
    {
        Addendlessbricks();
    }
}

/*  run level up function;*/

void HitBricksScene::Retry()
{
    if(Health->Getvalue() == 0)
    {
       Addhealth(4);
    }
    if(Countdown->Getvalue() == 0)
    {
        Addtime(1000);
    }
    Runningball = 1;
    Reducehealth();
}

/*  add game over reason little text value;*/

void HitBricksScene::Addhealth(int health)
{
    Health->Addvalue("Health: ",2,health);
}

/*  add health;*/

void HitBricksScene::Addbricks(QVector<QVector<int>> leveltemp)
{
    Brickvector.clear();
    Brickitemnumber = 0;
    int rows = leveltemp.count();
    int distancey = 25;
    int firstposy = 50;
    int boundingx = 200;
    for(int i = 0;i < rows;i++)
    {
        int group = leveltemp.at(i).count();
        int distancex = (sceneRect().width() - boundingx) / group;
        int firstposx = (boundingx + distancex) / 2 - Brickwidthcenter;
        for(int j = 0;j < leveltemp.at(i).count();j++)
        {
            int colorindex = leveltemp.at(i).at(j);
            if(leveltemp.at(i).at(j) > 0)
            {
                int count = Brickvector.count();
                Brickvector.append(new LittleBrick(this,colorindex,Itemtimer));
                addItem(Brickvector.at(count));
                connect(Brickvector.at(count),&LittleBrick::Signalba,this,&HitBricksScene::Checkhasbricks);
                connect(Brickvector.at(count),&LittleBrick::Signalbb,this,&HitBricksScene::Addscore);
                Brickvector.at(count)->setPos(firstposx + distancex * j,firstposy + distancey * i);
                Brickitemnumber = Brickitemnumber + 1;
            }
        }
    }
}

/*  add bricks;*/

void HitBricksScene::Checkhasbricks(QPointF point)
{
    Brickitemnumber = Brickitemnumber - 1;
    Generatebonus(point);
    if(Brickitemnumber == 0)
    {
        if(Endless == false)
        {
            if(Level + 1 >= Levelbricks.count())
            {
                Stopplayapi("Endless level?","Yes","Quit");
            }
            else
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Levelupanimationa);
            }
        }
        else
        {
            connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Levelupanimationa);
        }
    }
}

/*  check has bricks;*/

void HitBricksScene::Addendlessbricks()
{
    int time = QDateTime::currentDateTime().toString("zzz").toInt();
    QVector<int> rowtemp = {};
    QVector<QVector<int>> endlesstemp = {};
    if(time % 9 == 0)
    {
        time = time + 7;
    }
    for(int a = 0;a < time % 9;a++)
    {
        endlesstemp.append(rowtemp);
        for(int j = 0;j < time % 9;j++)
        {
            endlesstemp[a].append((time + a + j) % 9);
        }
    }
    Addbricks(endlesstemp);
}

/*  add endless bricks;*/

void HitBricksScene::Generatebonus(QPointF point)
{
    int time = QDateTime::currentDateTime().toString("zzz").toInt();
    if(time % 10 > 8)
    {
        LittleText *bonus = new LittleText(Bulletnamevector.at(time % Bulletnamevector.count()),Setfont("Microsoft Yahei",true,false,false,false,25),point,true,{0,0},this,Itemtimer);
        connect(bonus,&LittleText::Signalta,this,&HitBricksScene::Getbonus);
        bonus->Setbonus(true);
        addItem(bonus);
    }
}

/*  10% chance generate bonus when brick deleted;*/

void HitBricksScene::Getbonus(QString text)
{
    for(int i = 0;i < Bulletnamevector.count();i++)
    {
        if(text == Bulletnamevector.at(i))
        {
            Bulletvector.at(i)->Addvalue(text + ": ",2,1);
        }
    }
}

/*  get bonus;*/

LittleBall* HitBricksScene::Generateball(QPointF point,double speedx,double speedy)
{
    int x = point.x();
    LittleBall *gball = new LittleBall(this,&Sceneinfolist,x % 7,Itemtimer);
    addItem(gball);
    gball->setPos(point);
    gball->Speedx[0] = speedx;
    gball->Speedy[0] = speedy;
    Runningball = Runningball + 1;
    connect(gball,&LittleBall::Signalba,this,&HitBricksScene::Reducehealth);
    connect(gball,&LittleBall::Signalbb,this,&HitBricksScene::Addscore);
    return gball;
}

/*  generate little ball api;*/

void HitBricksScene::movebulletpointer(int step)
{
    Bulletpointerpos = (Bulletpointerpos + step) % Bulletnamevector.count();
    if(Bulletpointerpos < 0)
    {
        Bulletpointerpos = Bulletnamevector.count() - 1;
    }
    QPointF point = {Bulletpointer->pos().x(),Bulletvector.at(Bulletpointerpos)->pos().y() - 1};
    Bulletpointer->setPos(point);
}

/*  change bullet;*/

void HitBricksScene::Firebullets()
{
    if(Bulletvector.at(Bulletpointerpos)->Getvalue() > 0 && Bulletready == 10)
    {
        QString bulletname = Bulletnamevector.at(Bulletpointerpos);
        Bulletvector.at(Bulletpointerpos)->Addvalue(bulletname + ": ",2,-1);
        switch (Bulletpointerpos)
        {
            case 0:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Cbullets);
                Cbullets();
                break;
            }
            case 1:
            {
                Dbullets();
                break;
            }
            case 2:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Fbullets);
                Fbullets();
                break;
            }
            case 3:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Gbullets);
                Gbullets();
                break;
            }
            case 4:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Hbullets);
                Hbullets();
                break;
            }
            case 5:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Ibullets);
                Ibullets();
                break;
            }
            case 6:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Lbullets);
                Lbullets();
                break;
            }
            case 7:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Rbullets);
                Rbullets();
                break;
            }
            case 8:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Sbullets);
                Sbullets();
                break;
            }
        }
    }
}

/*  fire bullet;*/

void HitBricksScene::Cbullets()
{
    Bulletready = Bulletready - 1;
    int time = QDateTime::currentDateTime().toString("zzz").toInt();
    QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
    Balltempvector.append(Generateball(point,sin(time),-0.05));
    if(Bulletready == 0)
    {
        QPointF point(sceneRect().x() + sceneRect().width() / 2,sceneRect().y() + sceneRect().height() / 2);
        for(int i = 0;i < items().count();i++)
        {
            QGraphicsItem *item = items().at(i);
            if(item->boundingRect().width() == 60)
            {
                point.setX(item->pos().x() + 50);
                point.setY(item->pos().y() + 10);
                break;
            }
        }
        for(int j = 0;j < Balltempvector.count();j++)
        {
            Balltempvector.at(j)->Movetotarget(point);
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Cbullets);
        Balltempvector.clear();
        Bulletready = 10;
    }
}

/*  c class bullet;*/

void HitBricksScene::Dbullets()
{
    double distancex = sceneRect().width()  / Bulletready;
    for(int i = 0;i < Bulletready - 1;i++)
    {
        QPointF point(distancex + sceneRect().x() + distancex * i - 10,sceneRect().height() * 0.85);
        Generateball(point,0.8 - 0.2 * i,-1);
    }
}

/*  d class bullet;*/

void HitBricksScene::Fbullets()
{
    Bulletready = Bulletready - 1;
    double distancex = sceneRect().width()  / 10;
    QPointF point(sceneRect().x() + distancex * Bulletready - 10,sceneRect().height() * 0.85);
    Generateball(point,0,-1);
    if(Bulletready == 1)
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Fbullets);
        Bulletready = 10;
    }
}
/*  f class bullet;*/

void HitBricksScene::Gbullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
        Balltempvector.append(Generateball(point,0,-1));
    }
    else if(Bulletready == 0 && !Balltempvector.isEmpty())
    {
        Balltempvector.at(0)->Littleballrectf.adjust(0,0,20,20);
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 10;i++)
        {
            Generateball(Balltempvector.at(0)->pos(),sin(i + time),-abs(sin(i - time)));
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Gbullets);
        Bulletready = 10;
        Balltempvector.clear();
    }
}

/*  g class bullet;*/

void HitBricksScene::Hbullets()
{
    QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
    Generateball(point,0,-1);
    Bulletready = Bulletready - 1;
    if(Bulletready == 0)
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Hbullets);
        Bulletready = 10;
    }
}

/*  h class bullet;*/

void HitBricksScene::Ibullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        double temp = M_PI / 5;
        for(int i = 0;i < 5;i++)
        {
            QPoint pointa(Skatevector.at(0)->pos().x() + 20 * i,Skatevector.at(0)->pos().y() - 40 - 20 * (sin(temp * i)));
            QPoint pointb(Skatevector.at(0)->pos().x() + 20 * i,Skatevector.at(0)->pos().y() - 20 - 20 * (sin(temp * i)));
            Balltempvector.append(Generateball(pointa,-0.1 + 0.04 * i,-0.1));
            Balltempvector.append(Generateball(pointb,-0.1 + 0.04 * i,-0.1));
        }
        Balltempvector.append(Generateball({Skatevector.at(0)->pos().x() + 20 * 5,Skatevector.at(0)->pos().y() - 40 - 20 * (sin(temp * 5))},0.1,-0.1));
        Balltempvector.append(Generateball({Skatevector.at(0)->pos().x() + 20 * 5,Skatevector.at(0)->pos().y() - 20 - 20 * (sin(temp * 5))},0.1,-0.1));
    }
    else if(Bulletready == 0)
    {
        for(int i = 0;i < Balltempvector.count();i++)
        {
            Balltempvector.at(i)->Speedy[0] = -1;
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Ibullets);
        Balltempvector.clear();
        Bulletready = 10;
    }
}

/*  i class bullet;*/

void HitBricksScene::Lbullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
        Balltempvector.append(Generateball(point,0,-0.7));
    }
    else if(Bulletready < 9 && Bulletready > 0)
    {
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        Generateball(Balltempvector.at(0)->pos(),sin(time),-abs(sin(time)));
    }
    else
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Lbullets);
        Balltempvector.clear();
        Bulletready = 10;
    }
}

/*  l class bullet;*/

void HitBricksScene::Rbullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
        Balltempvector.append(Generateball(point,0.5,0));
        Balltempvector.append(Generateball(point,-0.5,0));
    }
    else if(Bulletready == 0 && !Balltempvector.isEmpty())
    {
        Balltempvector.at(0)->Speedy[0] = -1;
        Balltempvector.at(1)->Speedy[0] = -1;
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 6;i++)
        {
            Generateball(Balltempvector.at(0)->pos(),sin(i + time),-abs(sin(i - time)));
            Generateball(Balltempvector.at(1)->pos(),sin(i + time),-abs(sin(i - time)));
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Rbullets);
        Bulletready = 10;
        Balltempvector.clear();
    }
}

/*  r class bullet;*/

void HitBricksScene::Sbullets()
{
    Bulletready = Bulletready - 1;
    QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
    if(Bulletready == 9)
    {
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 5;i++)
        {
            Generateball(point,sin(i + time),-abs(sin(i - time)));
        }
    }
    else if(Bulletready == 7)
    {
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 3;i++)
        {
            Generateball(point,sin(i + time),-abs(sin(i - time)));
        }
    }
    else if(Bulletready == 5)
    {
        Generateball(point,0,-1);
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::Sbullets);
        Bulletready = 10;
    }
}

/*  s class bullet;*/



