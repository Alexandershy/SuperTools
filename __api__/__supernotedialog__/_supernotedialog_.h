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

    void Hidebutton();

    void Hideleftbutton();

    void Hiderightbutton();

    void Noteinit();

    void Messageinit();

private:

    QString Filestring  = "";

private slots:

    void Init();

    void Objectinit();

signals:

    void Signalna();

    void Signalnb();

};

#endif // _SUPERNOTEDIALOG__H
