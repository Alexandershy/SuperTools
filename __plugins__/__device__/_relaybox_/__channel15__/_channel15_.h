#ifndef _CHANNEL15__H
#define _CHANNEL15__H

#include "__supernotedialog__/_supernotedialog_.h"
#include "__superwindow__/_superwindow_.h"
#include "__supercore__/_supercore_.h"
#include "__superserial__/_superserial_.h"
#include "_channel15__ui_.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Channel15; }
QT_END_NAMESPACE

class Channel15 : public QFrame
{
    Q_OBJECT

public:

    Channel15(
            QWidget *parent = nullptr,
            QSerialPort *serial = nullptr,
            QCheckBox *checkbox = nullptr,
            QLineEdit *lineedit = nullptr);

    ~Channel15();

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
    QStringList Closecommand                = {"aa11","aa21","aa31","aa41","aa51","aa61","aa71","aa81","aa91","aaa1","aab1","aac1","aad1","aae1","aaf1"};
    QStringList Closebackvalue              = {"6611","6621","6631","6641","6651","6661","6671","6681","6691","66a1","66b1","66c1","66d1","66e1","66f1"};
    QStringList Opencommand                 = {"aa10","aa20","aa30","aa40","aa50","aa60","aa70","aa80","aa90","aaa0","aab0","aac0","aad0","aae0","aaf0"};
    QStringList Openbackvalue               = {"6610","6620","6630","6640","6650","6660","6670","6680","6690","66a0","66b0","66c0","66d0","66e0","66f0"};
    QString Settingpath                     = "";

private:

    Ui::Channel15 *ui                       = nullptr;
    SuperCore *SuperC                       = nullptr;
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

    void Closechannel1();

    void Closechannel2();

    void Closechannel3();

    void Closechannel4();

    void Closechannel5();

    void Closechannel6();

    void Closechannel7();

    void Closechannel8();

    void Closechannel9();

    void Closechannela();

    void Closechannelb();

    void Closechannelc();

    void Closechanneld();

    void Closechannele();

    void Closechannelf();

    void Openchannel1();

    void Openchannel2();

    void Openchannel3();

    void Openchannel4();

    void Openchannel5();

    void Openchannel6();

    void Openchannel7();

    void Openchannel8();

    void Openchannel9();

    void Openchannela();

    void Openchannelb();

    void Openchannelc();

    void Openchanneld();

    void Openchannele();

    void Openchannelf();

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

#endif // _CHANNEL15__H
