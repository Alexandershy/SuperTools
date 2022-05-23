#ifndef _CSVDATAINFODIALOG__H
#define _CSVDATAINFODIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "_csvdatainfodialogui_.h"

class CsvDataInfoDialog : public SuperWindow
{
    Q_OBJECT

public:

    CsvDataInfoDialog(
            QWidget *parent = nullptr);

    ~CsvDataInfoDialog();

private:

    CsvDataInfoDialogui *Plugin = nullptr;

private slots:

    void init();

    void objectInit();

    void checkItemNumber();

    void checkUpperLimitNumber();

    void checkLowerLimitNumber();

    void checkDataNumber();

    void checkDutNumber();

    void checkTesterNumber();

    void checkAppraiserNumber();

signals:

    void signalIa(
            int itemindex);

    void signalIb(
            int upperindex);

    void signalIc(
            int lowerindex);

    void signalId(
            int dataindex);

    void signalIe(
            int dutindex);

    void signalIf(
            int testerindex);

    void signalIg(
            int appraiserindex);

};

#endif // _CSVDATAINFODIALOG__H
