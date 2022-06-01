#ifndef _SUPERSENDER__H
#define _SUPERSENDER__H
#define _SUPERSENDER__EXPORT Q_DECL_EXPORT

#include "__supernotedialog__/_supernotedialog_.h"
#include <QTimer>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperSenderui; }
QT_END_NAMESPACE

class _SUPERSENDER__EXPORT SuperSender : public QFrame
{
    Q_OBJECT

public:

    QLineEdit *Lineedit     = nullptr;

public:

    SuperSender(
            QWidget *parent = nullptr,
            QLayout *layout = nullptr);

    ~SuperSender();

public slots:

    void enable();

    void disable();

private:

    Ui::SuperSenderui *ui   = nullptr;
    QLayout *Layout         = nullptr;
    QWidget *Widget         = nullptr;
    QTimer *Timer           = nullptr;
    QString Spliter         = "<split>";
    int Index               = 0;

private slots:

    void init();

    void parameterInit();

    void objectInit();

    void enableSendButton(
            QString text);

    void sendText();

    void send();

    void enableSpinBox();

signals:

    void signalSa(
            QLineEdit *lineedit);

    void signalSb();
};

#endif // _SUPERSENDER__H
