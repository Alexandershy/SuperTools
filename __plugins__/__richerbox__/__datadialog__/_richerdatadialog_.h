#ifndef _DATADIALOG__H
#define _DATADIALOG__H

#include "_richerdatadialogui_.h"
#include "__superwindow__/_superwindow_.h"
#include "__superfontdialog__/_superfontdialog_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "__superfinddialog__/_superfinddialog_.h"
#include "__superfiledialog__/_superfiledialog_.h"
#include "__supercolordialog__/_supercolordialog_.h"
#include <QtPrintSupport>
#include <QTextDocumentFragment>
#include <QImageReader>
#include <QPageSize>
#include <QTimer>

class RicherDataDialog : public SuperWindow
{
    Q_OBJECT

public:

    RicherDataDialog(
            QString richerfile = "");

    ~RicherDataDialog();

protected:

    void keyPressEvent(
            QKeyEvent *event);

private:

    RicherDataDialogui *Plugin      = nullptr;
    QString Richerfile              = "";
    QString Richerfilepath          = "";
    QString Richerfilename          = "";
    QTimer *Timer                   = nullptr;
    int Savevalue                   = 0;
    QStringList Fontformat          = {};
    QStringList Fontfamilies        = {};

private slots:

    void init();

    void objectInit();

    void iconInit();

    void textInit();

    void timerInit();

    void enableApply();

    void apply();

    void checkCharFormat();

    void checkFamilies(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void setFamilies(
            QStringList fontfamilies);

    void families();

    void checkSize(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void size();

    void checkBold(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void bold();

    void checkItalic(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void italic();

    void checkUnderLine(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void underLine();

    void checkColor(
            QStringList *fontformat);

    void openColorDialog();

    void setColor(
            QColor color);

    void checkAlign();

    void textAlignApi(
            bool boola,
            bool boolb,
            bool boolc,
            bool boold);

    void textLeftAlign();

    void textRightAlign();

    void textCenterAlign();

    void textJustifyAlign();

    void addProgressValue();

    void getFormat();

    void brushText();

    void selectImage();

    void insertImage(
            QString file);

    void printToPdf();

    void openPath();

    void openFindDialog();

};

#endif // _DATADIALOG__H
