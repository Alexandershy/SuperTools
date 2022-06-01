#ifndef _CSVDATADIALOGUI__H
#define _CSVDATADIALOGUI__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class CsvDataDialogui; }
QT_END_NAMESPACE

class CsvDataDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::CsvDataDialogui *ui = nullptr;

public:

    CsvDataDialogui(
            QWidget *parent = nullptr);

    ~CsvDataDialogui();

};

#endif // _DATABOX__H
