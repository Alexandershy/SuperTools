#ifndef _SUPERFONTDIALOG__H
#define _SUPERFONTDIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "_superfontbox_.h"
#include <QFontDatabase>

class SuperFontDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperFontBox *Plugin = nullptr;

public:

    SuperFontDialog(
            QWidget *parent = nullptr,
            QStringList *fontfamilies = nullptr);

    ~SuperFontDialog();

private:

    QStringList *Fontfamilies = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

    void Fontlistinit();

    void Currentfontinit();

    void Searchfont();

    void Previewfont();

    void Sendfont();

signals:

    void Signalfa(
            QStringList fontfamilies);

};

#endif // _SUPERFONTDIALOG__H
