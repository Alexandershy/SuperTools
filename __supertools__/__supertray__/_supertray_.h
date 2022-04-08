#ifndef _SYSTEMTRAY__H
#define _SYSTEMTRAY__H

#include "__supernotedialog__/_supernotedialog_.h"
#include "__supercore__/_supercore_.h"
#include <QSystemTrayIcon>

/****************plugin*****************/
class SuperTray : public QSystemTrayIcon
{
    Q_OBJECT

public:

    QMenu   *Menu               = new QMenu();
    QAction *Regedit            = new QAction(Menu);
    QAction *Taskmanager        = new QAction(Menu);
    QAction *Computermanager    = new QAction(Menu);
    QAction *Network            = new QAction(Menu);
    QAction *Quit               = new QAction(Menu);

public:

    SuperTray(
            QWidget *parent = nullptr);

    ~SuperTray();

private:

    SuperCore *SuperC = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

    void Actioninit();

    void Addactioninfo(
            QAction *actiona,
            QString actionname,
            QString icopath);

    void Opentaskmanager();

    void Opencomputermanager();

    void Openregedit();

    void Opennetwork();

    void Trayclick(
            QSystemTrayIcon::ActivationReason reason);

    void Closeevent();

signals:

    void Signalta();

    void Signaltb();

};

#endif // _SYSTEMTRAY__H
