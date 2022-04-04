#ifndef _SUPER__H
#define _SUPER__H

#include "__superwindow__/_superwindow_.h"
#include "__superinit__/_superinit_.h"
#include "__supermain__/_supermain_.h"
#include "__supertray__/_supertray_.h"
#include "_super__global.h"
#include <QTimer>

/**************interface****************/
class _SUPER__EXPORT Interface
{
public:
    SuperWindow* Loadplugin();                              /*  return class supertools new instance pointer;*/
};

class SuperTools : public SuperWindow
{
    Q_OBJECT

public:

    SuperTools();

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

#endif // _SUPER__EXPORT
