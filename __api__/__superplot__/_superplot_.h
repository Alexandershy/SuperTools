#ifndef _SUPERPLOT__H
#define _SUPERPLOT__H

#include "qcustomplot.h"

class SuperPlot : public QCustomPlot
{
    Q_OBJECT

public:

    SuperPlot(
        QWidget *parent = nullptr);

    ~SuperPlot();

private slots:

    void Init();

    void Parameterinit();

};


#endif // _SUPERPLOT__H
