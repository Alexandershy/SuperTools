#ifndef _SUPERSENDER__H
#define _SUPERSENDER__H

#include "__supernotedialog__/_supernotedialog_.h"
#include "_supersender__ui_.h"
#include <QTimer>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperSender; }
QT_END_NAMESPACE

class SuperSender : public QFrame
{
    Q_OBJECT

public:

    QLineEdit *Lineedit     = nullptr;

public:

    SuperSender(
            QWidget *parent = nullptr,
            QLayout *layout = nullptr);

    ~SuperSender();

    void Enable();

    void Disable();

private:

    Ui::SuperSender *ui     = nullptr;
    QLayout *Layout         = nullptr;
    QWidget *Widget         = nullptr;
    QTimer *Timer           = nullptr;
    QString Spliter         = "<split>";
    int Index               = 0;

private slots:

    void Init();

    void Parameterinit();

    void Objectinit();

    void Enablesendbutton(
            QString text);

    void Sendtext();

    void Send();

    void Enablespinbox();

signals:

    void Signalsa(
            QLineEdit *lineedit);

    void Signalsb();
};

#endif // _SUPERSENDER__H
