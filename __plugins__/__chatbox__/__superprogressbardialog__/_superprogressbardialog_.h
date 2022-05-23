#ifndef _SUPERPROGRESSBARDIALOG__H
#define _SUPERPROGRESSBARDIALOG__H
#define _SUPERPROGRESSBARDIALOG__EXPORT Q_DECL_EXPORT

#include "_superprogressbardialogui_.h"
#include "__superwindow__/_superwindow_.h"

class _SUPERPROGRESSBARDIALOG__EXPORT SuperProgressBarDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperProgressBarDialog(
            QWidget *parent = nullptr);

    ~SuperProgressBarDialog();

public slots:

    void setValueMessage(
        int value,
        QString message);

private:

    SuperProgressBarDialogui *Plugin    = nullptr;
    QAction *Stop                       = nullptr;

private slots:

    void init();

    void objectInit();

    void stopFunction();

signals:

    void signalPa();

    void signalPb();

};


#endif // _Superprogressbar__H
