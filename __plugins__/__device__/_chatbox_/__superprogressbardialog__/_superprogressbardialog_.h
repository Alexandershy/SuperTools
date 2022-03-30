#ifndef _SUPERPROGRESSBARDIALOG__H
#define _SUPERPROGRESSBARDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_superprogressbarbox_.h"

class SuperProgressBarDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperProgressBarDialog(
            QWidget *parent = nullptr);

    ~SuperProgressBarDialog();

public slots:

    void Setvaluemessage(
        int value,
        QString message);

private:

    SuperProgressBarBox *Plugin = nullptr;
    QAction *Stop               = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Stopfunction();

signals:

    void Signalpa();

    void Signalpb();

};


#endif // _Superprogressbar__H
