#ifndef _CSVDATAMODULEA__H
#define _CSVDATAMODULEA__H

#include <QFrame>

/****************plugin*****************/
QT_BEGIN_NAMESPACE
namespace Ui { class CsvDataModuleA;}
QT_END_NAMESPACE

class CsvDataModuleA : public QFrame
{
    Q_OBJECT

public:

    Ui::CsvDataModuleA *ui = nullptr;

public:

    CsvDataModuleA(
        QWidget *parent = nullptr,
        QLayout *layout = nullptr);

    ~CsvDataModuleA();

private:

    QLayout *Layout = nullptr;

private slots:

    void init();

    void parameterInit();

};

#endif // _MODULEA__H
