#ifndef _SUPERCOLORBOX__H
#define _SUPERCOLORBOX__H

#include "_superpainter_.h"
#include "_supercolorbox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperColorBox; }
QT_END_NAMESPACE

class SuperColorBox : public QFrame
{
    Q_OBJECT

public:

    SuperPainter *Painter = nullptr;
    Ui::SuperColorBox *ui = nullptr;

public:

    SuperColorBox(
            QWidget *parent = nullptr);

    ~SuperColorBox();

private slots:

    void Init();

    void Objectinit();

};


#endif // _SUPERCOLORBOX__H
