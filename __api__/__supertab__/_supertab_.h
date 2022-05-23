#ifndef _SUPERTAB__H
#define _SUPERTAB__H
#define _SUPERTAB__EXPORT Q_DECL_EXPORT

#include "__supercore__/_supercore_.h"
#include "__supergroupbox__/_supergroupbox_.h"
#include "ui__supertabui_.h"

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class SuperTabui; }
QT_END_NAMESPACE

class _SUPERTAB__EXPORT SuperTab : public QGroupBox
{
    Q_OBJECT

public:

    SuperCore *Core                         = nullptr;
    QList<SuperGroupBox*> Leftgroupboxlist  = {};
    QList<SuperGroupBox*> Rightgroupboxlist = {};

public:

    SuperTab(
        QWidget *parent = nullptr);

    ~SuperTab();

public slots:

    void init();

    void objectInit();

    void setGroupBox(
        int left,
        int right);

    void setStretch(
        QList<int> leftstretch,
        QList<int> rightstretch);

    void readMe(
        QString objectname);

private:

    Ui::SuperTabui *ui          = nullptr;
    QList<int> Groupboxcounts   = {};

};

#endif // _SUPERTAB__H
