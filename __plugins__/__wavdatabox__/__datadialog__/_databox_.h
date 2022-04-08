#ifndef _DATABOX__H
#define _DATABOX__H

#include "ui__databox_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class DataBox; }
QT_END_NAMESPACE

class DataBox : public QFrame
{
    Q_OBJECT

public:

    Ui::DataBox *ui = nullptr;

public:

    DataBox(
            QWidget *parent = nullptr);

    ~DataBox();

};

#endif // _DATABOX__H
