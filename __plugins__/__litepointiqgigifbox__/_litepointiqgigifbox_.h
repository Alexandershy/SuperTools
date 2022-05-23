#ifndef _LITEPOINTIQGIGIFBOX__H
#define _LITEPOINTIQGIGIFBOX__H
#define _LITEPOINTIQGIGIFBOX__EXPORT Q_DECL_EXPORT

#include "__supertab__/_supertab_.h"
#include "__supercore__/_supercore_.h"
#include "__superlogger__/_superlogger_.h"
#include "__superchartview__/_superchartview_.h"
#include "__supernetwork__/_supernetwork_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "__pathlossdialog__/_pathlossdialog_.h"
#include "__routdialog__/_routdialog_.h"
#include "__module__/_litepointiqgigifmodulea_.h"
#include "__module__/_litepointiqgigifmoduleb_.h"
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

    SuperNetwork *Network               = nullptr;
    LitePointIQGigIfModuleA *Modulea    = nullptr;
    LitePointIQGigIfModuleB *Moduleb    = nullptr;
    QTcpSocket* Tcpsocket               = nullptr;
    QString Localtechnology             = "";
    int Currentconfig                   = 0;
    QStringList Clickconfiglist         = {"",""};
    SuperChartView* Chartview           = nullptr;
    Technology* Technologymenu          = nullptr;
    PathLossDataMenu* Pldatamenu        = nullptr;
    RoutDialog* Rout                    = nullptr;
    PathLossDialog* Pathloss            = nullptr;
    SuperTcpSocketThread* Threadta      = nullptr;
    SuperLogger *Logger                 = nullptr;

private slots:

    /* main function;*/
    void init();

    void objectInit();

    void enableConnectLitePoint();

    void connectTcpserver();

    void operatorConnectui();

    void disconnectTcpserver();

    void operatorDisconnectui();

    void litepointWriteApi(
            QString command);

    void litepointWaitApi(
            double timeout);

    QByteArray litepointReadApi();

    void openTechnologyMenu();

    void setTechnology();

    void openRoutConfig();

    void openPathLossEditor();

    void refreshPathLoss();

    void refreshPathLossConfig();

    void newPathLossConfig();

    void refreshPathLossData();

    void savePathLossData();

    void openPathLossDataMenu();

    void newPathLossDataRow();

    void deletePathLossDataRow();

    QString getLocalPathLossDataApi();

    QString getLocalPathLossFreqApi();

    void setLocalPathLossDataApi();

    void setHiddenApi(
            QGroupBox* groupbox);

    void displayVSASetting();

    void displayTriggleSetting();

    void displayImpairmentsSetting();

    QString litepointReadSlotApi();

    void litepointReadTimeoutSlot();

    void getActiveModuleSlot();

    void refreshConfigSlot();

    void refreshPathLossDataSlot();

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

    SuperCore *Core = nullptr;

private slots:

    void init();

    void objectInit();

    void actionInit();

};

#endif // _LITEPOINTIQGIGIFBOX__H
