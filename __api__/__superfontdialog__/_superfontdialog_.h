#ifndef _SUPERFONTDIALOG__H
#define _SUPERFONTDIALOG__H
#define _SUPERFONTDIALOG__EXPORT Q_DECL_EXPORT

#include "__superwindow__/_superwindow_.h"
#include "_superfontdialogui_.h"
#include <QFontDatabase>

class _SUPERFONTDIALOG__EXPORT SuperFontDialog : public SuperWindow
{
    Q_OBJECT

public:

    SuperFontDialogui *Plugin = nullptr;

public:

    SuperFontDialog(
            QWidget *parent = nullptr,
            QStringList *fontfamilies = nullptr);

    ~SuperFontDialog();

private:

    QStringList *Fontfamilies = nullptr;

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void fontListInit();

    void currentFontInit();

    void searchFont();

    void previewFont();

    void sendFont();

signals:

    void signalFa(
            QStringList fontfamilies);

};

#endif // _SUPERFONTDIALOG__H
