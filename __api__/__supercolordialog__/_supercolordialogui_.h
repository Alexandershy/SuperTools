#ifndef _SUPERCOLORDIALOGUI__H
#define _SUPERCOLORDIALOGUI__H

#include "_superpainter_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperColorDialogui; }
QT_END_NAMESPACE

class SuperColorDialogui : public QFrame
{
    Q_OBJECT

public:

    SuperPainter *Painter = nullptr;
    Ui::SuperColorDialogui *ui = nullptr;

public:

    SuperColorDialogui(
            QWidget *parent = nullptr);

    ~SuperColorDialogui();

private slots:

    void init();

    void objectInit();

};


#endif // _SUPERCOLORBOX__H
