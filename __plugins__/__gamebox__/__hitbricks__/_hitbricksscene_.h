#ifndef _HITBRICKSSCENE__H
#define _HITBRICKSSCENE__H

#include "__object__/_littlebrick_.h"
#include "__object__/_littleskate_.h"
#include "__object__/_littleball_.h"
#include "__object__/_littletext_.h"
#include "__supercore__/_supercore_.h"
#include <QGraphicsSimpleTextItem>
#include <QGuiApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QScreen>
#include <complex>
#include <QKeyEvent>
#include <QMessageBox>

class EnterGame;

class HitBricksScene : public QGraphicsScene
{
    Q_OBJECT

public:

    QVector<LittleSkate*> Skatevector;

public:

    HitBricksScene(
        QGraphicsScene *parent = nullptr,
        QGraphicsView *view = nullptr);

    ~HitBricksScene();

public slots:

    void startPlay();

    void stopPlayApi(
            QString texta,
            QString textb,
            QString textc);

protected:

    void keyPressEvent(
            QKeyEvent *event);

    void keyReleaseEvent(
            QKeyEvent *event);

private:

    QFont Font;
    int Started                             = 0;
    QGraphicsView *View                     = nullptr;
    SuperCore *Core                         = nullptr;
    QVector<LittleBrick*> Brickvector       = {};
    QVector<LittleText*> Textvector         = {};
    LittleText *Inittitle                   = nullptr;
    LittleText *Inittext                    = nullptr;
    LittleText *Scenemaxfps                 = nullptr;
    LittleText *Skatespeed                  = nullptr;
    LittleText *Health                      = nullptr;
    LittleText *Score                       = nullptr;
    LittleText *Endtext                     = nullptr;;
    LittleText *Yes                         = nullptr;
    LittleText *Quit                        = nullptr;
    LittleText *Continuepointer             = nullptr;
    LittleText *Countdown                   = nullptr;
    LittleText *Bulletpointer               = nullptr;
    QVector<LittleBall*> Balltempvector     = {};
    int Width = 800;
    int Height = 600;
    int Maxfps = 0;
    int Player = 1;
    int Runningball = 1;
    int Level = 0;
    int Brickwidthcenter                    = 25;
    int Brickitemnumber                     = 0;
    int Continuepointerpos                  = 0;
    int Scenespeed                          = 2;
    bool Endless                            = false;
    QStringList Sceneinfolist               = {"0"};
    QTimer *Refreshscene                    = nullptr;
    QTimer *Itemtimer                       = nullptr;
    QTimer *Onesecond                       = nullptr;

    /*  bonus*/
    QVector<QString> Bulletnamevector       = {"C","D","F","G","H","I","L","R","S"};
    QVector<LittleText*> Bulletvector       = {};
    int Bulletpointerpos                    = 0;
    int Bulletready                         = 10;

    /*  bulletsfunction*/

private slots:

    /*  main function;*/
    void init();

    void objectInit();

    QFont setFont(
            QString family,
            bool bold,
            bool overline,
            bool underline,
            bool italic,
            int pointsize);

    void initObjects();

    void initSkateVector();

    void initBallVector();

    LittleBall* addBallByHealth(
            int health);

    void initBrickVector();

    void initBulletVector();

    void initTimer();

    void addMaxFps();

    void resetFps();

    void refreshSkateSpeed(
            double speed);

    void addTime(
            int time);

    void reduceTime();

    void addScore(
            int score);

    void reduceHealth();

    void levelupAnimationa();

    void levelupAnimationb();

    void levelup();

    void addHealth(
            int health);

    void addBricks(
            QVector<QVector<int>> leveltemp);

    void checkHasBricks(
            QPointF point);

    void moveStopPointer(
            int step);

    void selectYesOrQuit();

    void resume();

    void addEndlessBricks();

    void addBullet(
            int value);

    void retry();

    /*  bonus*/
    LittleBall* generateBall(
            QPointF point,
            double speedx,
            double speedy);

    void generateBonus(
            QPointF point);

    void getBonus(
            QString text);

    void moveBulletPointer(
            int step);

    void fireBullets();

    void cBullets();

    void dBullets();

    void fBullets();

    void gBullets();

    void hBullets();

    void iBullets();

    void lBullets();

    void rBullets();

    void sBullets();

private:

    /*normal level bricks*/
    QVector<QVector<QVector<int>>> Levelbricks =
    {
        /*level01*/{{0,1,0},{1,0,1},{0,1,0}},
        /*level02*/{{1,1,1},{1,0,1},{1,1,1}},
        /*level03*/{{0,1,0},{1,1,1},{1,2,1},{1,1,1},{0,1,0}},
        /*level04*/{{1,1,1},{1,2,1},{2,3,2},{1,2,1},{1,1,1}},
        /*level05*/{{0,1,2,1,0},{1,2,3,2,1},{0,1,2,1,0}},
        /*level06*/{{1,2,3,2,1},{2,3,4,2,2},{1,2,3,2,1}},
        /*level07*/{{0,1,2,1,0},{1,2,3,2,1},{2,3,4,3,2},{1,2,3,2,1},{0,1,2,1,0}},
        /*level08*/{{1,2,3,2,1},{2,3,4,2,2},{3,4,5,4,3},{2,3,4,2,2},{1,2,3,2,1}},
        /*level09*/{{0,1,2,1,0},{1,2,3,2,1},{2,3,4,3,2},{3,4,5,4,3},{2,3,4,3,2},{1,2,3,2,1},{0,1,2,1,0}},
        /*level10*/{{1,2,3,2,1},{2,3,4,2,2},{3,4,5,4,3},{4,5,6,5,4},{3,4,5,4,3},{2,3,4,2,2},{1,2,3,2,1}},
        /*level11*/{{0,1,2,3,2,1,0},{1,2,3,4,3,2,1},{0,1,2,3,2,1,0}},
        /*level12*/{{1,2,3,4,3,2,1},{2,3,4,5,4,3,2},{1,2,3,4,3,2,1}},
        /*level13*/{{0,1,2,3,2,1,0},{1,2,3,4,3,2,1},{2,3,4,5,4,3,2},{1,2,3,4,3,2,1},{0,1,2,3,2,1,0}},
        /*level14*/{{1,2,3,4,3,2,1},{2,3,4,5,4,3,2},{3,4,5,6,5,4,3},{2,3,4,5,4,3,2},{1,2,3,4,3,2,1}},
        /*level15*/{{0,1,2,3,2,1,0},{1,2,3,4,3,2,1},{2,3,4,5,4,3,2},{3,4,5,6,5,4,3},{2,3,4,5,4,3,2},{1,2,3,4,3,2,1},{0,1,2,3,2,1,0}},
        /*level16*/{{1,2,3,4,3,2,1},{2,3,4,5,4,3,2},{3,4,5,6,5,4,3},{4,5,6,7,6,5,4},{3,4,5,6,5,4,3},{2,3,4,5,4,3,2},{1,2,3,4,3,2,1}},
        /*level17*/{{0,1,2,3,2,1,0},{1,2,3,4,3,2,1},{2,3,4,5,4,3,2},{3,4,5,6,5,4,3},{4,5,6,7,6,5,4},{3,4,5,6,5,4,3},{2,3,4,5,4,3,2},{1,2,3,4,3,2,1},{0,1,2,3,2,1,0}},
        /*level18*/{{1,2,3,4,3,2,1},{2,3,4,5,4,3,2},{3,4,5,6,5,4,3},{4,5,6,7,6,5,4},{5,6,7,8,7,6,5},{4,5,6,7,6,5,4},{3,4,5,6,5,4,3},{2,3,4,5,4,3,2},{1,2,3,4,3,2,1}},
        /*level19*/{{8},{7,7},{6,0,6},{5,0,0,5},{4,5,0,5,4},{3,4,0,0,4,3},{3,4,5,0,5,4,3},{2,3,4,0,0,4,3,2},{1,2,3,4,0,4,3,2,1}},
    };

signals:

    void signalSa();

};

#endif // _HITBRICKSSCENE__H
