#ifndef _SUPERNOTEDIALOG__H
#define _SUPERNOTEDIALOG__H
#define _SUPERNOTEDIALOG__EXPORT Q_DECL_EXPORT

#include "_supernotedialogui_.h"
#include "__superwindow__/_superwindow_.h"

class _SUPERNOTEDIALOG__EXPORT SuperNoteDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperNoteDialogui *Plugin = nullptr;

public:

    SuperNoteDialog(
            QWidget *parent = nullptr,
            QString filestring = "");

    ~SuperNoteDialog();

public slots:

    void hideButton();

    void hideLeftButton();

    void hideRightButton();

    void noteInit();

    void messageInit();

private:

    QString Filestring  = "";

private slots:

    void init();

    void objectInit();

signals:

    void signalNa();

    void signalNb();

};

#endif // _SUPERNOTEDIALOG__H
