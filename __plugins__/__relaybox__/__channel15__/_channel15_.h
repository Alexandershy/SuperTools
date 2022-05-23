#ifndef _CHANNEL15__H
#define _CHANNEL15__H

#include "__supernotedialog__/_supernotedialog_.h"
#include "__superwindow__/_superwindow_.h"
#include "__supercore__/_supercore_.h"
#include "__superserial__/_superserial_.h"
#include "ui__channel15_.h"

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
    QStringList Closecommand                = {"aa11","aa21","aa31","aa41","aa51","aa61","aa71","aa81","aa91","aaa1","aab1","aac1","aad1","aae1","aaf1"};
    QStringList Closebackvalue              = {"6611","6621","6631","6641","6651","6661","6671","6681","6691","66a1","66b1","66c1","66d1","66e1","66f1"};
    QStringList Opencommand                 = {"aa10","aa20","aa30","aa40","aa50","aa60","aa70","aa80","aa90","aaa0","aab0","aac0","aad0","aae0","aaf0"};
    QStringList Openbackvalue               = {"6610","6620","6630","6640","6650","6660","6670","6680","6690","66a0","66b0","66c0","66d0","66e0","66f0"};
    QString Settingpath                     = "";

private:

    Ui::Channel15 *ui                       = nullptr;
    SuperCore *Core                         = nullptr;
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

    void closeChannel1();

    void closeChannel2();

    void closeChannel3();

    void closeChannel4();

    void closeChannel5();

    void closeChannel6();

    void closeChannel7();

    void closeChannel8();

    void closeChannel9();

    void closeChannela();

    void closeChannelb();

    void closeChannelc();

    void closeChanneld();

    void closeChannele();

    void closeChannelf();

    void openChannel1();

    void openChannel2();

    void openChannel3();

    void openChannel4();

    void openChannel5();

    void openChannel6();

    void openChannel7();

    void openChannel8();

    void openChannel9();

    void openChannela();

    void openChannelb();

    void openChannelc();

    void openChanneld();

    void openChannele();

    void openChannelf();

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

#endif // _CHANNEL15__H
