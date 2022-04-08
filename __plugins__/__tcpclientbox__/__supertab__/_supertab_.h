#ifndef _SUPERTAB__H
#define _SUPERTAB__H

#include "_supertab__ui_.h"
#include "__supercore__/_supercore_.h"
#include "__supergroupbox__/_supergroupbox_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperTab; }
QT_END_NAMESPACE

class SuperTab : public QGroupBox
{
    Q_OBJECT

public:

    SuperCore *SuperC                       = nullptr;
    QList<SuperGroupBox*> Leftgroupboxlist  = {};
    QList<SuperGroupBox*> Rightgroupboxlist = {};

public:

    SuperTab(
        QWidget *parent = nullptr);

    ~SuperTab();

public slots:

    void Init();

    void Objectinit();

    void Setgroupbox(
        int left,
        int right);

    void Setstretch(
        QList<int> leftstretch,
        QList<int> rightstretch);

    void Readme(
        QString objectname);

private:

    Ui::SuperTab *ui            = nullptr;
    QList<int> Groupboxcounts   = {};

};

#endif // _SUPERTAB__H
