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

    SuperCore *Core             = nullptr;

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void actionInit();

    void addActionInfo(
            QAction *actiona,
            QString actionname,
            QString icopath);

    void openTaskManager();

    void openComputerManager();

    void openRegedit();

    void openNetwork();

    void trayClick(
            QSystemTrayIcon::ActivationReason reason);

    void close();

signals:

    void Signalta();

    void Signaltb();

};

#endif // _SYSTEMTRAY__H
