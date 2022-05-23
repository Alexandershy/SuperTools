#ifndef _CHANNEL34__H
#define _CHANNEL34__H

#include "__supernotedialog__/_supernotedialog_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superserial__/_superserial_.h"
#include "__supercore__/_supercore_.h"
#include "ui__channel34_.h"

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

public slots:

    void setSetting(
            QString path);

    void enableLineEdit(
            bool boola);

public:

    SuperScanSerial *Threadsa                = nullptr;
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

    SuperCore *Core                         = nullptr;
    Ui::Channel34 *ui                       = nullptr;
    QWidget *Widget                         = nullptr;
    QSerialPort *Serial                     = nullptr;
    QCheckBox *Checkbox                     = nullptr;
    QLineEdit *Lineedit                     = nullptr;
    QString Spliter                         = "<split>";

private slots:
    /*  main function*/
    void init();

    void objectInit();

    void widgetListInit();

    void closeChannel01();

    void closeChannel02();

    void closeChannel03();

    void closeChannel04();

    void closeChannel05();

    void closeChannel06();

    void closeChannel07();

    void closeChannel08();

    void closeChannel09();

    void closeChannel10();

    void closeChannel11();

    void closeChannel12();

    void closeChannel13();

    void closeChannel14();

    void closeChannel15();

    void closeChannel16();

    void closeChannel17();

    void closeChannel18();

    void closeChannel19();

    void closeChannel20();

    void closeChannel21();

    void closeChannel22();

    void closeChannel23();

    void closeChannel24();

    void closeChannel25();

    void closeChannel26();

    void closeChannel27();

    void closeChannel28();

    void closeChannel29();

    void closeChannel30();

    void closeChannel31();

    void closeChannel32();

    void closeChannel33();

    void closeChannel34();

    void openChannel01();

    void openChannel02();

    void openChannel03();

    void openChannel04();

    void openChannel05();

    void openChannel06();

    void openChannel07();

    void openChannel08();

    void openChannel09();

    void openChannel10();

    void openChannel11();

    void openChannel12();

    void openChannel13();

    void openChannel14();

    void openChannel15();

    void openChannel16();

    void openChannel17();

    void openChannel18();

    void openChannel19();

    void openChannel20();

    void openChannel21();

    void openChannel22();

    void openChannel23();

    void openChannel24();

    void openChannel25();

    void openChannel26();

    void openChannel27();

    void openChannel28();

    void openChannel29();

    void openChannel30();

    void openChannel31();

    void openChannel32();

    void openChannel33();

    void openChannel34();

    void emitDisplayLog(
        QString direction,
        QString strtlog,
        QString strllog);

    void emitSignalSbSlot(
        QString strcommand);

    void emitSignalScSlot();

    void emitEnableRelayButton();

    void saveCurrentText();

    void checkLineEditText(
        QString text);

    void loadSetting();


signals:

    void signalCa(
        QString direction,
        QString strtlog,
        QString strllog);

    void signalCb(
        QString strcommand);

    void signalCc();

    void signalCd(
        QString strcommand);

    void signalCe();

};

#endif // _CHANNEL34__H
