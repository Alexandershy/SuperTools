#ifndef _SUPERCHARTVIEW__H
#define _SUPERCHARTVIEW__H
#define _SUPERCHARTVIEW__EXPORT Q_DECL_EXPORT

#include <QWidget>
#include <QChartView>

class _SUPERCHARTVIEW__EXPORT SuperChartView : public QChartView
{
    Q_OBJECT

public:

    SuperChartView(
        QWidget *parent = nullptr);

    ~SuperChartView();

public:

    QChart *Chart = nullptr;

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();

};

#endif // _SUPERCHARTVIEW__H
