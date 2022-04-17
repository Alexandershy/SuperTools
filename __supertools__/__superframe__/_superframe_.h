#ifndef _SUPERFRAME__H
#define _SUPERFRAME__H

#include "__superwindow__/_superwindow_.h"
#include "__superinit__/_superinit_.h"
#include "__supermain__/_supermain_.h"
#include "__supertray__/_supertray_.h"
#include <QApplication>
#include <QTimer>

class SuperFrame : public SuperWindow
{
    Q_OBJECT

public:

    SuperFrame(
        QWidget *parent = nullptr);

    ~SuperFrame();

private:

    SuperInit *Initbox      = nullptr;
    SuperMain *Mainbox      = nullptr;
    SuperTray *Tray         = nullptr;
    QTimer *Timer           = nullptr;
    QString Openstatuspath  = "./__depycache__/__cache__/__ini__/_openedstatus_.ini";

private slots:

    void Superinitwindow();

    void Supermainwindow(
            QString setting);

    void Supersystemtray();

    void Superselectcolor();

    void Supertimer();

    void Checkstatus();

    void Quit();

};

class SuperRepeat : public QObject
{
    Q_OBJECT

public:

    SuperRepeat(
        QObject *parent = nullptr);

    ~SuperRepeat();

public slots:

    void Init();

private:

    QString Openstatuspath      = "./__depycache__/__cache__/__ini__/_openedstatus_.ini";
    SuperCore* Core             = nullptr;
    QTimer *Timer               = nullptr;

private slots:

    void Writeinit();

    void Objectinit();

    void Timerinit();

};

#endif // _SUPER__EXPORT
