#ifndef _INFOBOX__H
#define _INFOBOX__H

#include "_infobox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class InfoBox; }
QT_END_NAMESPACE

class InfoBox : public QFrame
{
    Q_OBJECT

public:

    Ui::InfoBox *ui = nullptr;

public:

    InfoBox(
            QWidget *parent = nullptr);

    ~InfoBox();

};

#endif // _INFOBOX__H
