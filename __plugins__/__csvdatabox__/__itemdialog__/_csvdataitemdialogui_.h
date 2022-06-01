#ifndef _CSVDATAITEMDIALOGUI__H
#define _CSVDATAITEMDIALOGUI__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class CsvDataItemDialogui; }
QT_END_NAMESPACE

class CsvDataItemDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::CsvDataItemDialogui *ui = nullptr;

public:

    CsvDataItemDialogui(
            QWidget *parent = nullptr);

    ~CsvDataItemDialogui();

};

#endif // _CSVDATAITEMDIALOGUI__H
