#ifndef _INFODIALOG__H
#define _INFODIALOG__H

#include "__superwindow__/_superwindow_.h"
#include "__supernotedialog__/_supernotedialog_.h"
#include "_infobox_.h"

class InfoDialog : public SuperWindow
{
    Q_OBJECT

public:

    InfoDialog(
            QWidget *parent = nullptr);

    ~InfoDialog();

private:

    InfoBox *Plugin = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Checkitemnumber();

    void Checkupperlimitnumber();

    void Checklowerlimitnumber();

    void Checkdatanumber();

    void Checkdutnumber();

    void Checktesternumber();

    void Checkappraisernumber();

signals:

    void Signalia(
            int itemindex);

    void Signalib(
            int upperindex);

    void Signalic(
            int lowerindex);

    void Signalid(
            int dataindex);

    void Signalie(
            int dutindex);

    void Signalif(
            int testerindex);

    void Signalig(
            int appraiserindex);

};

#endif // _INFODIALOG__H
