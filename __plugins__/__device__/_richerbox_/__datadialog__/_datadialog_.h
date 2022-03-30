#ifndef _DATADIALOG__H
#define _DATADIALOG__H

#include "_databox_.h"
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

class DataDialog : public SuperWindow
{
    Q_OBJECT

public:

    DataDialog(
            QString richerfile = "");

    ~DataDialog();

protected:

    void keyPressEvent(
            QKeyEvent *event);

private:

    DataBox *Plugin                 = nullptr;
    QString Richerfile              = "";
    QString Richerfilepath          = "";
    QString Richerfilename          = "";
    QTimer *Timer                   = nullptr;
    int Savevalue                   = 0;
    QStringList Fontformat          = {};
    QStringList Fontfamilies        = {};

private slots:

    void Init();

    void Objectinit();

    void Icoinit();

    void Textinit();

    void Timerinit();

    void Enableapply();

    void Apply();

    void Checkcharformat();

    void Checkfamilies(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void Setfamilies(
            QStringList fontfamilies);

    void Families();

    void Checksize(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void Size();

    void Checkbold(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void Bold();

    void Checkitalic(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void Italic();

    void Checkunderline(
            QTextCharFormat *editorformat,
            QStringList *fontformat);

    void Underline();

    void Checkcolor(
            QStringList *fontformat);

    void Opencolordialog();

    void Setcolor(
            QColor color);

    void Checkalign();

    void Textalignapi(
            bool boola,
            bool boolb,
            bool boolc,
            bool boold);

    void Textleftalign();

    void Textrightalign();

    void Textcenteralign();

    void Textjustifyalign();

    void Addprogressvalue();

    void Getformat();

    void Brushtext();

    void Selectimage();

    void Insertimage(
            QString file);

    void Printtopdf();

    void Openpath();

    void Openfinddialog();

};

#endif // _DATADIALOG__H
