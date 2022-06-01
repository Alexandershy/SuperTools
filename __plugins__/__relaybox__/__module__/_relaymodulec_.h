#ifndef _RELAYMODULEC__H
#define _RELAYMODULEC__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class RelayModuleC;}
QT_END_NAMESPACE

class RelayModuleC : public QFrame
{
    Q_OBJECT

public:

    Ui::RelayModuleC *ui = nullptr;

public:

    RelayModuleC(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~RelayModuleC();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

    void uiInit();
};

#endif // _RELAYMODULEC__H
