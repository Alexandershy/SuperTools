#ifndef _SUPERTITLE__H
#define _SUPERTITLE__H

#include "ui__supertitleui_.h"
#include "_supertitlebutton_.h"
#include <QMouseEvent>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui {class SuperTitleui;}
QT_END_NAMESPACE

class SuperTitle : public QFrame
{
    Q_OBJECT

public:

    Ui::SuperTitleui *ui                = nullptr;
    SuperTitleButton *Minisizebutton    = nullptr;
    SuperTitleButton *Maxisizebutton    = nullptr;
    SuperTitleButton *Closebutton       = nullptr;

public:

    SuperTitle(
            QWidget *parent = nullptr);

    ~SuperTitle();

public slots:

    void Setsourcecolor(
        QString rgbcolor);

protected:

    void mouseDoubleClickEvent(
            QMouseEvent *event);

    void enterEvent(
            QEnterEvent *);

    void leaveEvent(
            QEvent *);

private slots:

    void Init();

    void Objectinit();

signals:

    void Signalsa(
            bool mouseontitle);

    void Signalsb();

    void Signalsc(
        Qt::CursorShape shape);

};

#endif // _SUPERTITLE__H
