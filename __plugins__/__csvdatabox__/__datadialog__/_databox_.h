#ifndef _DATABOX__H
#define _DATABOX__H

#include "_databox__ui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class DataBox; }
QT_END_NAMESPACE

class DataBox : public QFrame
{
    Q_OBJECT

public:

    DataBox(
            QWidget *parent = nullptr);

    ~DataBox();

    Ui::DataBox *ui = nullptr;

};

#endif // _DATABOX__H
