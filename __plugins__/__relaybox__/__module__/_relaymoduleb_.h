#ifndef _RELAYMODULEB__H
#define _RELAYMODULEB__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class RelayModuleB;}
QT_END_NAMESPACE

class RelayModuleB : public QFrame
{
    Q_OBJECT

public:

    Ui::RelayModuleB *ui = nullptr;

public:

    RelayModuleB(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~RelayModuleB();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _RELAYMODULEB__H
