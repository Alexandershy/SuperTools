#ifndef _CHANNEL34__H
#define _CHANNEL34__H

#include "__supernotedialog__/_supernotedialog_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superserial__/_superserial_.h"
#include "__supercore__/_supercore_.h"
#include "_channel34__ui_.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Channel34; }
QT_END_NAMESPACE

class Channel34 : public QFrame
{
    Q_OBJECT

public:

    Channel34(
            QWidget *parent = nullptr,
            QSerialPort *serial = nullptr,
            QCheckBox *checkbox = nullptr,
            QLineEdit *lineedit = nullptr);

    ~Channel34();

    void Setsetting(
            QString path);

    void Enablelineedit(
            bool boola);

    ScanSerialPort *Threadsa                = nullptr;
    QList<QWidget*> Connectwidgetet         = {};
    QList<QWidget*> Disconnectwidgetef      = {};
    QList<QProgressBar*> Progressbarlist    = {};
    QList<QCheckBox*> Checkboxlist          = {};
    QList<QLineEdit*> Lineeditlist          = {};
    QStringList Closecommand                = {"close001","close002","close003","close004","close005","close006","close007","close008","close009","close010",
                                               "close011","close012","close013","close014","close015","close016","close017","close018","close019","close020",
                                               "close021","close022","close023","close024","close025","close026","close027","close028","close029","close030",
                                               "close031","close032","close033","close034"};
    QStringList Closebackvalue              = {"close1 OK","close2 OK","close3 OK","close4 OK","close5 OK","close6 OK","close7 OK","close8 OK","close9 OK","close10 OK",
                                               "close11 OK","close12 OK","close13 OK","close14 OK","close15 OK","close16 OK","close17 OK","close18 OK","close19 OK","close20 OK",
                                               "close21 OK","close22 OK","close23 OK","close24 OK","close25 OK","close26 OK","close27 OK","close28 OK","close29 OK","close30 OK",
                                               "close31 OK","close32 OK","close33 OK","close34 OK"};
    QStringList Opencommand                 = {"open001","open002","open003","open004","open005","open006","open007","open008","open009","open010",
                                               "open011","open012","open013","open014","open015","open016","open017","open018","open019","open020",
                                               "open021","open022","open023","open024","open025","open026","open027","open028","open029","open030",
                                               "open031","open032","open033","open034"};
    QStringList Openbackvalue               = {"open1 OK","open2 OK","open3 OK","open4 OK","open5 OK","open6 OK","open7 OK","open8 OK","open9 OK","open10 OK",
                                               "open11 OK","open12 OK","open13 OK","open14 OK","open15 OK","open16 OK","open17 OK","open18 OK","open19 OK","open20 OK",
                                               "open21 OK","open22 OK","open23 OK","open24 OK","open25 OK","open26 OK","open27 OK","open28 OK","open29 OK","open30 OK",
                                               "open31 OK","open32 OK","open33 OK","open34 OK"};
    QString Settingpath                     = "";

private:

    SuperCore *SuperC                       = nullptr;
    Ui::Channel34 *ui                       = nullptr;
    QWidget *Widget                         = nullptr;
    QSerialPort *Serial                     = nullptr;
    QCheckBox *Checkbox                     = nullptr;
    QLineEdit *Lineedit                     = nullptr;
    QString Spliter                         = "<split>";

private slots:
    /*  main function*/
    void Init();

    void Objectinit();

    void Widgetlistinit();

    void Closechannel01();

    void Closechannel02();

    void Closechannel03();

    void Closechannel04();

    void Closechannel05();

    void Closechannel06();

    void Closechannel07();

    void Closechannel08();

    void Closechannel09();

    void Closechannel10();

    void Closechannel11();

    void Closechannel12();

    void Closechannel13();

    void Closechannel14();

    void Closechannel15();

    void Closechannel16();

    void Closechannel17();

    void Closechannel18();

    void Closechannel19();

    void Closechannel20();

    void Closechannel21();

    void Closechannel22();

    void Closechannel23();

    void Closechannel24();

    void Closechannel25();

    void Closechannel26();

    void Closechannel27();

    void Closechannel28();

    void Closechannel29();

    void Closechannel30();

    void Closechannel31();

    void Closechannel32();

    void Closechannel33();

    void Closechannel34();

    void Openchannel01();

    void Openchannel02();

    void Openchannel03();

    void Openchannel04();

    void Openchannel05();

    void Openchannel06();

    void Openchannel07();

    void Openchannel08();

    void Openchannel09();

    void Openchannel10();

    void Openchannel11();

    void Openchannel12();

    void Openchannel13();

    void Openchannel14();

    void Openchannel15();

    void Openchannel16();

    void Openchannel17();

    void Openchannel18();

    void Openchannel19();

    void Openchannel20();

    void Openchannel21();

    void Openchannel22();

    void Openchannel23();

    void Openchannel24();

    void Openchannel25();

    void Openchannel26();

    void Openchannel27();

    void Openchannel28();

    void Openchannel29();

    void Openchannel30();

    void Openchannel31();

    void Openchannel32();

    void Openchannel33();

    void Openchannel34();

    void Emitdisplaylog(
            QString direction,
            QString strtlog,
            QString strllog);

    void Emitsignalsbslot(
            QString strcommand);

    void Emitsignalscslot();

    void Emitenablerelaybutton();

    void Savecurrenttext();

    void Checklineedittext(
            QString text);

    void Loadsetting();

signals:

    void Signalca(
            QString direction,
            QString strtlog,
            QString strllog);

    void Signalcb(
            QString strcommand);

    void Signalcc();

    void Signalcd(
            QString strcommand);

    void Signalce();

};

#endif // _CHANNEL34__H
