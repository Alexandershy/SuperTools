#ifndef _LITEPOINTIQGIGIFBOX__H
#define _LITEPOINTIQGIGIFBOX__H

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superplot__/_superplot_.h"
#include "__superlogger__/_superlogger_.h"
#include "__supernetwork__/_supernetwork_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__pathlossdialog__/_pathlossdialog_.h"
#include "__routdialog__/_routdialog_.h"
#include "_litepointiqgigifbox__global.h"
#include "__module__/_modulea_.h"
#include "__module__/_moduleb_.h"
#include <QAction>
#include <QMenu>

class _LITEPOINTIQGIGIFBOX__EXPORT Interface
{
public:
    SuperTab* Loadplugin();                                /*  return class litepointiqgigifbox new instance pointer;*/
};

class Technology;

class LitePointIQGigIfBox : public SuperTab
{
    Q_OBJECT

public:

    LitePointIQGigIfBox(
            QWidget *parent = nullptr);

    ~LitePointIQGigIfBox();

private:

    SuperNetwork *SuperN            = nullptr;
    ModuleA *Modulea                = nullptr;
    ModuleB *Moduleb                = nullptr;
    QTcpSocket* Tcpsocket           = nullptr;
    QString Localtechnology         = "";
    int Currentconfig               = 0;
    QStringList Clickconfiglist     = {"",""};
    QCustomPlot* Canvas             = nullptr;
    Technology* Technologymenu      = nullptr;
    PathLossDataMenu* Pldatamenu    = nullptr;
    RoutDialog* Rout                = nullptr;
    PathLossDialog* Pathloss        = nullptr;
    Tcpsocketthread* Threadta       = nullptr;
    SuperLogger *Logger             = nullptr;

private slots:

    /* main function;*/

    void Init();

    void Objectinit();

    void Enableconnectlitepoint();

    void Connecttcpserver();

    void Operatorconnectui();

    void Disconnecttcpserver();

    void Operatordisconnectui();

    void Litepointwriteapi(
            QString command);

    void Litepointwaitapi(
            double timeout);

    QByteArray Litepointreadapi();

    void Opentechnologymenu();

    void Settechnology();

    void Openroutconfig();

    void Openpathlosseditor();

    void Refreshpathloss();

    void Refreshpathlossconfig();

    void Newpathlossconfig();

    void Refreshpathlossdata();

    void Savepathlossdata();

    void Openpathlossdatamenu();

    void Newpathlossdatarow();

    void Deletepathlossdatarow();

    QString Getlocalpathlossdataapi();

    QString Getlocalpathlossfreqapi();

    void Setlocalpathlossdataapi();

    void Sethiddenapi(
            QGroupBox* groupbox);

    void Displayvsasetting();

    void Displaytrigglesetting();

    void Displayimpairmentssetting();

    QString Litepointreadslotapi();

    void Litepointreadtimeoutslot();

    void Getactivemodulesolt();

    void Refreshconfigslot();

    void Refreshpathlossdataslot();

};

class Technology : public QMenu
{
    Q_OBJECT

public:

    /*  main function;*/

    Technology(
            QWidget *parent = nullptr);

    QAction *Gprf           = new QAction(this);
    QMenu   *Fivegmenu      = new QMenu(this);
    QAction *Fivegaction    = new QAction(this);
    QAction *Fivegsmallcell = new QAction(this);
    QAction *Wifigig        = new QAction(this);

private:

    SuperCore *SuperC = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Actioninit();

};

#endif // _LITEPOINTIQGIGIFBOX__H
