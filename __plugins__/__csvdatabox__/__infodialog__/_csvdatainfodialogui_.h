#ifndef _CSVDATAINFODIALOGUI__H
#define _CSVDATAINFODIALOGUI__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class CsvDataInfoDialogui; }
QT_END_NAMESPACE

class CsvDataInfoDialogui : public QFrame
{
    Q_OBJECT

public:

    Ui::CsvDataInfoDialogui *ui = nullptr;

public:

    CsvDataInfoDialogui(
            QWidget *parent = nullptr);

    ~CsvDataInfoDialogui();

};

#endif // _CSVDATAINFODIALOGUI__H
