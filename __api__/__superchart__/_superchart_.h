#ifndef _SUPERCHART__H
#define _SUPERCHART__H
#define _SUPERCHART__EXPORT Q_DECL_EXPORT

#include <QWidget>
#include <QChart>

class _SUPERCHART__EXPORT SuperChart : public QWidget
{
    Q_OBJECT

public:

    SuperChart(
        QWidget *parent = nullptr);

    ~SuperChart();

public slots:

//    void Init();

private slots:

    void Init();

    void Objectinit();

    void Parameterinit();



};

#endif // _SUPERCHART__H
