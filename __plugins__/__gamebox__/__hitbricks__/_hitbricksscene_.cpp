#include "_hitbricksscene_.h"

HitBricksScene::HitBricksScene(QGraphicsScene *parent,QGraphicsView* view)
    : QGraphicsScene(parent)
{
    View = view;
    setSceneRect(0,0,View->width() - 5,View->height() - 5);
    setItemIndexMethod(QGraphicsScene::NoIndex);
    init();
}

HitBricksScene::~HitBricksScene()
{
    Core->deleteObject(Refreshscene);
    Core->deleteObject(Onesecond);
    Core->deleteObject(Itemtimer);
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
                moveStopPointer(1);
                break;
            }
            case Qt::Key_S:
            {
                moveStopPointer(-1);
                break;
            }
            case Qt::Key_A:
            {
                selectYesOrQuit();
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
                Skatevector.at(0)->refreshDirection("Right");
                break;
            }
            case Qt::Key_J:
            {
                Skatevector.at(0)->refreshDirection("Left");
                break;
            }
            case Qt::Key_S:
            {
                moveBulletPointer(1);
                break;
            }
            case Qt::Key_W:
            {
                moveBulletPointer(-1);
                break;
            }
            case Qt::Key_A:
            {
                fireBullets();
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
            startPlay();
        }
        else if(Started == 1)
        {
            switch (keyvalue)
            {
                case Qt::Key_Escape:
                {
                    resume();
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
                    Skatevector.at(0)->refreshDirection("Stop");
                    break;
                }
                case Qt::Key_J:
                {
                    Skatevector.at(0)->refreshDirection("Stop");
                    break;
                }
                case Qt::Key_Escape:
                {
                    stopPlayApi("Continues?","Yes","Quit");
                    break;
                }
            }
        }
    }
}

/*  this scene key release function;*/

void HitBricksScene::init()
{
    objectInit();
    initTimer();
    Inittitle =         new LittleText("Hit Bricks V1.01",          setFont("Microsoft Yahei",true,false,false,false,50),QPointF(sceneRect().width() / 2,sceneRect().height() * 0.3),           false,  {1,1},this,Itemtimer);
    Inittext =          new LittleText("Press Any Key Continue",    setFont("Microsoft Yahei",true,false,false,false,15),QPointF(sceneRect().width() / 2,sceneRect().height() * 0.85),          true,   {1,1},this,Itemtimer);
    Scenemaxfps =       new LittleText("MAXFPS: 000",               setFont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().x(),sceneRect().y()),                              false,  {0,0},this,Itemtimer);
    Health =            new LittleText("Health: 00",                setFont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width(),sceneRect().y()),                          false,  {2,0},this,Itemtimer);
    Yes =               new LittleText("Yes",                       setFont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 2,sceneRect().height() / 2 + 50),        false,  {1,1},this,Itemtimer);
    Quit =              new LittleText("Quit",                      setFont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 2,sceneRect().height() / 2 + 100),       false,  {1,1},this,Itemtimer);
    Continuepointer =   new LittleText("👈",                        setFont("Microsoft Yahei",true,false,false,false,15),QPointF(sceneRect().width() / 2 + 30,sceneRect().height() / 2 + 35),   false,  {0,0},this,Itemtimer);
    Skatespeed =        new LittleText("SPEED: 0000",               setFont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() * 3 / 4,sceneRect().y()),                  false,  {1,0},this,Itemtimer);
    Score =             new LittleText("SCORE: 0000000000",         setFont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 4,sceneRect().y()),                      false,  {1,0},this,Itemtimer);
    Countdown =         new LittleText("Level000: 00000",           setFont("Microsoft Yahei",true,false,false,false,10),QPointF(sceneRect().width() / 2,sceneRect().y()),                      false,  {1,0},this,Itemtimer);
    Endtext =           new LittleText("text",                      setFont("Microsoft Yahei",true,false,false,false,30),QPointF(sceneRect().width() / 2,sceneRect().height() / 2),             false,  {1,1},this,Itemtimer);
    addItem(Inittitle);
    addItem(Inittext);
    addItem(Scenemaxfps);
}

/*  creat init scene;*/

void HitBricksScene::objectInit()
{
    Core = new SuperCore(this);
}

/*  object init;*/

void HitBricksScene::initTimer()
{
    Refreshscene = new QTimer(this);
    Refreshscene->setInterval(2);
    Refreshscene->setTimerType(Qt::PreciseTimer);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::advance);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::addMaxFps);
    Refreshscene->start();
    Onesecond = new QTimer(this);
    Onesecond->setInterval(1000);
    connect(Onesecond,&QTimer::timeout,this,&HitBricksScene::resetFps);
    Onesecond->start();
    Itemtimer = new QTimer(this);
    Itemtimer->setInterval(100);
    Itemtimer->start();
}

/*  init scene timer;*/

QFont HitBricksScene::setFont(QString family,bool bold,bool overline,bool underline,bool italic,int pointsize)
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

void HitBricksScene::startPlay()
{
    removeItem(Inittitle);
    removeItem(Inittext);
    initObjects();
    Started = 2;
}

/*  set and return this font;*/

void HitBricksScene::initObjects()
{
    addTime(1000);
    connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::reduceTime);
    addItem(Skatespeed);
    addItem(Score);
    addItem(Health);
    addItem(Countdown);
    initSkateVector();
    initBallVector();
    initBrickVector();
    initBulletVector();
}

/*  creat init object;*/

void HitBricksScene::initSkateVector()
{
    for(int i = 0;i < Player;i++)
    {
        Skatevector.append(new LittleSkate(this,i % 2,Itemtimer));
        addItem(Skatevector.at(i));
        Skatevector.at(i)->setPos(sceneRect().width() / 2,sceneRect().height() * 0.9);
        connect(Skatevector.at(i),&LittleSkate::signalSa,this,&HitBricksScene::refreshSkateSpeed);
        connect(Skatevector.at(i),&LittleSkate::signalSb,this,&HitBricksScene::generateBall);
    }
}

/*  creat init skate;*/

void HitBricksScene::initBallVector()
{
    addHealth(4);
    reduceHealth();
}

/*  creat init health and ball;*/

LittleBall* HitBricksScene::addBallByHealth(int health)
{
    LittleBall *newball = new LittleBall(this,&Sceneinfolist,health % 7,Itemtimer);
    addItem(newball);
    newball->setPos(sceneRect().width() - 20,sceneRect().y() + 20);
    connect(newball,&LittleBall::signalBa,this,&HitBricksScene::reduceHealth);
    connect(newball,&LittleBall::signalBb,this,&HitBricksScene::addScore);
    return newball;
}

/*  creat ball;*/

void HitBricksScene::initBrickVector()
{
    addBricks(Levelbricks.at(Level));
}

/*  creat init level;*/

void HitBricksScene::initBulletVector()
{
    Bulletpointer = new LittleText("👈",setFont("Microsoft Yahei",true,false,false,false,8),QPointF(sceneRect().x() + 40,30 + sceneRect().y()),false,{0,0},this,Itemtimer);
    addItem(Bulletpointer);
    for(int i = 0;i < Bulletnamevector.count();i++)
    {
        Bulletvector.append(new LittleText(Bulletnamevector.at(i) + ": 00",setFont("Microsoft Yahei",true,false,false,false,8),QPointF(sceneRect().x(),30 + sceneRect().y() + 15 * i),false,{0,0},this,Itemtimer));
        addItem(Bulletvector.at(i));
    }
}

/*  creat init bulletvector;*/

void HitBricksScene::addBullet(int value)
{
    int bulletindex = Maxfps % Bulletvector.count();
    Bulletvector.at(bulletindex)->addValue(Bulletnamevector.at(bulletindex) + ": ",2,Maxfps % 5 + int(value / 5));
}

void HitBricksScene::addMaxFps()
{
    Maxfps = Maxfps + 1;
}

/*  cal fps;*/

void HitBricksScene::resetFps()
{
    Scenemaxfps->setText("MAXFPS: " + QString("%1").arg(Maxfps,3, 10, QChar('0')));
    Maxfps = 0;
}

/*  reset fps value as 0;*/

void HitBricksScene::refreshSkateSpeed(double speed)
{
    Skatespeed->setText("SPEED: " + QString("%1").arg(int(abs(speed) * 1000),4, 10, QChar('0')));
    Sceneinfolist[0] = QString::number(speed);
}

/*  display skate speed;*/

void HitBricksScene::addTime(int time)
{
    Countdown->addValue("Level" + QString("%1").arg(Level,3,10,QChar('0')) + ": ",5,time);
}

/*  init countdown time;*/

void HitBricksScene::reduceTime()
{
    Countdown->addValue("Level" + QString("%1").arg(Level,3,10,QChar('0')) + ": ",5,-1);
    if(Countdown->getValue() < 1)
    {
        stopPlayApi("Game Over","Retry","Quit");
    }
}

/*  countdown time by timer;*/

void HitBricksScene::addScore(int score)
{
    Score->addValue("SCORE: ",10,score);
}

/*  add score;*/

void HitBricksScene::reduceHealth()
{
    Runningball = Runningball - 1;
    if(Runningball == 0)
    {
        addHealth(-1);
        if(Health->getValue() > 0)
        {
            addBallByHealth(Health->getValue())->Speedy[0] = 0.35;
            Runningball = Runningball + 1;
        }
        else
        {
            stopPlayApi("Game Over","Retry","Quit");
        }
    }
}

/*  if no running ball ,reduce health and new ball at righttop;*/

void HitBricksScene::stopPlayApi(QString texta,QString textb,QString textc)
{
    Endtext->setText(texta);
    Yes->setText(textb);
    Quit->setText(textc);
    addItem(Endtext);
    addItem(Yes);
    addItem(Quit);
    addItem(Continuepointer);
    disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::reduceTime);
    disconnect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::advance);
    disconnect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::addMaxFps);
    disconnect(Onesecond,&QTimer::timeout,this,&HitBricksScene::resetFps);
    Started = 1;
}

/*  stop play api;*/

void HitBricksScene::resume()
{
    removeItem(Endtext);
    removeItem(Yes);
    removeItem(Quit);
    removeItem(Continuepointer);
    connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::reduceTime);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::advance);
    connect(Refreshscene,&QTimer::timeout,this,&HitBricksScene::addMaxFps);
    connect(Onesecond,&QTimer::timeout,this,&HitBricksScene::resetFps);
    Started = 2;
}

/*  resume play;*/

void HitBricksScene::moveStopPointer(int step)
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

void HitBricksScene::selectYesOrQuit()
{
    if(Continuepointer->pos().y() < sceneRect().height() / 2 + 60 && Endtext->getText() == "Continues?")
    {
        resume();
    }
    else if(Continuepointer->pos().y() < sceneRect().height() / 2 + 60 && Endtext->getText() == "Endless level?")
    {
        resume();
        addHealth(1);
        addEndlessBricks();
        addScore(1000);
        addTime(1000);
        Endless = true;
    }
    else if(Continuepointer->pos().y() < sceneRect().height() / 2 + 60 && Endtext->getText() == "Game Over")
    {
        resume();
        retry();
    }
    else
    {
        emit signalSa();
    }
}

/*  select yes or quit;*/

void HitBricksScene::levelupAnimationa()
{
    Scenespeed = Scenespeed + 1;
    if(Scenespeed == 3)
    {
        Endtext->setText("Level" + QString::number(Level) + " Clear");
        addItem(Endtext);
        Level = Level + 1;
    }
    else if(Scenespeed < 10)
    {
        Refreshscene->setInterval(Scenespeed);
    }
    else if(Scenespeed >= 10)
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::levelupAnimationa);
        connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::levelupAnimationb);
    }
}

/*  enter next level animation step a;*/

void HitBricksScene::levelupAnimationb()
{
    if(Scenespeed > 2)
    {
        Scenespeed = Scenespeed - 1;
        Refreshscene->setInterval(Scenespeed);
    }
    else if(Scenespeed == 2)
    {
        levelup();
    }
}

/*  enter next level animation step b;*/

void HitBricksScene::levelup()
{
    disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::levelupAnimationb);
    removeItem(Endtext);
    addHealth(1);
    addScore(1000);
    addTime(1000);
    addBullet(Level);
    if(Level + 1 <= Levelbricks.count())
    {
        addBricks(Levelbricks.at(Level));
    }
    else
    {
        addEndlessBricks();
    }
}

/*  run level up function;*/

void HitBricksScene::retry()
{
    if(Health->getValue() == 0)
    {
       addHealth(4);
    }
    if(Countdown->getValue() == 0)
    {
        addTime(1000);
    }
    Runningball = 1;
    reduceHealth();
}

/*  add game over reason little text value;*/

void HitBricksScene::addHealth(int health)
{
    Health->addValue("Health: ",2,health);
}

/*  add health;*/

void HitBricksScene::addBricks(QVector<QVector<int>> leveltemp)
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
                connect(Brickvector.at(count),&LittleBrick::signalBa,this,&HitBricksScene::checkHasBricks);
                connect(Brickvector.at(count),&LittleBrick::signalBb,this,&HitBricksScene::addScore);
                Brickvector.at(count)->setPos(firstposx + distancex * j,firstposy + distancey * i);
                Brickitemnumber = Brickitemnumber + 1;
            }
        }
    }
}

/*  add bricks;*/

void HitBricksScene::checkHasBricks(QPointF point)
{
    Brickitemnumber = Brickitemnumber - 1;
    generateBonus(point);
    if(Brickitemnumber == 0)
    {
        if(Endless == false)
        {
            if(Level + 1 >= Levelbricks.count())
            {
                stopPlayApi("Endless level?","Yes","Quit");
            }
            else
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::levelupAnimationa);
            }
        }
        else
        {
            connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::levelupAnimationa);
        }
    }
}

/*  check has bricks;*/

void HitBricksScene::addEndlessBricks()
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
    addBricks(endlesstemp);
}

/*  add endless bricks;*/

void HitBricksScene::generateBonus(QPointF point)
{
    int time = QDateTime::currentDateTime().toString("zzz").toInt();
    if(time % 10 > 8)
    {
        LittleText *bonus = new LittleText(Bulletnamevector.at(time % Bulletnamevector.count()),setFont("Microsoft Yahei",true,false,false,false,25),point,true,{0,0},this,Itemtimer);
        connect(bonus,&LittleText::signalTa,this,&HitBricksScene::getBonus);
        bonus->setBonus(true);
        addItem(bonus);
    }
}

/*  10% chance generate bonus when brick deleted;*/

void HitBricksScene::getBonus(QString text)
{
    for(int i = 0;i < Bulletnamevector.count();i++)
    {
        if(text == Bulletnamevector.at(i))
        {
            Bulletvector.at(i)->addValue(text + ": ",2,1);
        }
    }
}

/*  get bonus;*/

LittleBall* HitBricksScene::generateBall(QPointF point,double speedx,double speedy)
{
    int x = point.x();
    LittleBall *gball = new LittleBall(this,&Sceneinfolist,x % 7,Itemtimer);
    addItem(gball);
    gball->setPos(point);
    gball->Speedx[0] = speedx;
    gball->Speedy[0] = speedy;
    Runningball = Runningball + 1;
    connect(gball,&LittleBall::signalBa,this,&HitBricksScene::reduceHealth);
    connect(gball,&LittleBall::signalBb,this,&HitBricksScene::addScore);
    return gball;
}

/*  generate little ball api;*/

void HitBricksScene::moveBulletPointer(int step)
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

void HitBricksScene::fireBullets()
{
    if(Bulletvector.at(Bulletpointerpos)->getValue() > 0 && Bulletready == 10)
    {
        QString bulletname = Bulletnamevector.at(Bulletpointerpos);
        Bulletvector.at(Bulletpointerpos)->addValue(bulletname + ": ",2,-1);
        switch (Bulletpointerpos)
        {
            case 0:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::cBullets);
                cBullets();
                break;
            }
            case 1:
            {
                dBullets();
                break;
            }
            case 2:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::fBullets);
                fBullets();
                break;
            }
            case 3:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::gBullets);
                gBullets();
                break;
            }
            case 4:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::hBullets);
                hBullets();
                break;
            }
            case 5:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::iBullets);
                iBullets();
                break;
            }
            case 6:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::lBullets);
                lBullets();
                break;
            }
            case 7:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::rBullets);
                rBullets();
                break;
            }
            case 8:
            {
                connect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::sBullets);
                sBullets();
                break;
            }
        }
    }
}

/*  fire bullet;*/

void HitBricksScene::cBullets()
{
    Bulletready = Bulletready - 1;
    int time = QDateTime::currentDateTime().toString("zzz").toInt();
    QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
    Balltempvector.append(generateBall(point,sin(time),-0.05));
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
            Balltempvector.at(j)->moveToTarget(point);
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::cBullets);
        Balltempvector.clear();
        Bulletready = 10;
    }
}

/*  c class bullet;*/

void HitBricksScene::dBullets()
{
    double distancex = sceneRect().width()  / Bulletready;
    for(int i = 0;i < Bulletready - 1;i++)
    {
        QPointF point(distancex + sceneRect().x() + distancex * i - 10,sceneRect().height() * 0.85);
        generateBall(point,0.8 - 0.2 * i,-1);
    }
}

/*  d class bullet;*/

void HitBricksScene::fBullets()
{
    Bulletready = Bulletready - 1;
    double distancex = sceneRect().width()  / 10;
    QPointF point(sceneRect().x() + distancex * Bulletready - 10,sceneRect().height() * 0.85);
    generateBall(point,0,-1);
    if(Bulletready == 1)
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::fBullets);
        Bulletready = 10;
    }
}
/*  f class bullet;*/

void HitBricksScene::gBullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
        Balltempvector.append(generateBall(point,0,-1));
    }
    else if(Bulletready == 0 && !Balltempvector.isEmpty())
    {
        Balltempvector.at(0)->Littleballrectf.adjust(0,0,20,20);
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 10;i++)
        {
            generateBall(Balltempvector.at(0)->pos(),sin(i + time),-abs(sin(i - time)));
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::gBullets);
        Bulletready = 10;
        Balltempvector.clear();
    }
}

/*  g class bullet;*/

void HitBricksScene::hBullets()
{
    QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
    generateBall(point,0,-1);
    Bulletready = Bulletready - 1;
    if(Bulletready == 0)
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::hBullets);
        Bulletready = 10;
    }
}

/*  h class bullet;*/

void HitBricksScene::iBullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        double temp = M_PI / 5;
        for(int i = 0;i < 5;i++)
        {
            QPoint pointa(Skatevector.at(0)->pos().x() + 20 * i,Skatevector.at(0)->pos().y() - 40 - 20 * (sin(temp * i)));
            QPoint pointb(Skatevector.at(0)->pos().x() + 20 * i,Skatevector.at(0)->pos().y() - 20 - 20 * (sin(temp * i)));
            Balltempvector.append(generateBall(pointa,-0.1 + 0.04 * i,-0.1));
            Balltempvector.append(generateBall(pointb,-0.1 + 0.04 * i,-0.1));
        }
        Balltempvector.append(generateBall({Skatevector.at(0)->pos().x() + 20 * 5,Skatevector.at(0)->pos().y() - 40 - 20 * (sin(temp * 5))},0.1,-0.1));
        Balltempvector.append(generateBall({Skatevector.at(0)->pos().x() + 20 * 5,Skatevector.at(0)->pos().y() - 20 - 20 * (sin(temp * 5))},0.1,-0.1));
    }
    else if(Bulletready == 0)
    {
        for(int i = 0;i < Balltempvector.count();i++)
        {
            Balltempvector.at(i)->Speedy[0] = -1;
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::iBullets);
        Balltempvector.clear();
        Bulletready = 10;
    }
}

/*  i class bullet;*/

void HitBricksScene::lBullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
        Balltempvector.append(generateBall(point,0,-0.7));
    }
    else if(Bulletready < 9 && Bulletready > 0)
    {
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        generateBall(Balltempvector.at(0)->pos(),sin(time),-abs(sin(time)));
    }
    else
    {
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::lBullets);
        Balltempvector.clear();
        Bulletready = 10;
    }
}

/*  l class bullet;*/

void HitBricksScene::rBullets()
{
    Bulletready = Bulletready - 1;
    if(Bulletready == 9)
    {
        QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
        Balltempvector.append(generateBall(point,0.5,0));
        Balltempvector.append(generateBall(point,-0.5,0));
    }
    else if(Bulletready == 0 && !Balltempvector.isEmpty())
    {
        Balltempvector.at(0)->Speedy[0] = -1;
        Balltempvector.at(1)->Speedy[0] = -1;
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 6;i++)
        {
            generateBall(Balltempvector.at(0)->pos(),sin(i + time),-abs(sin(i - time)));
            generateBall(Balltempvector.at(1)->pos(),sin(i + time),-abs(sin(i - time)));
        }
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::rBullets);
        Bulletready = 10;
        Balltempvector.clear();
    }
}

/*  r class bullet;*/

void HitBricksScene::sBullets()
{
    Bulletready = Bulletready - 1;
    QPoint point(Skatevector.at(0)->pos().x() + 45,Skatevector.at(0)->pos().y() - 20);
    if(Bulletready == 9)
    {
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 5;i++)
        {
            generateBall(point,sin(i + time),-abs(sin(i - time)));
        }
    }
    else if(Bulletready == 7)
    {
        int time = QDateTime::currentDateTime().toString("zzz").toInt();
        for(int i = 0;i < 3;i++)
        {
            generateBall(point,sin(i + time),-abs(sin(i - time)));
        }
    }
    else if(Bulletready == 5)
    {
        generateBall(point,0,-1);
        disconnect(Itemtimer,&QTimer::timeout,this,&HitBricksScene::sBullets);
        Bulletready = 10;
    }
}

/*  s class bullet;*/



